/*******************************************************************************
 * Development Name: Frost Electronic Control System with Digital Display
 * Author          : Raihan Bin Mofidul 
 * Version         : 1.1
 * Date            : 03-Jul-2019
 *******************************************************************************/



/*******************************************************************************
 ***************************** Headers & Definition*****************************
 ******************************************************************************/
#include "mcc_generated_files/mcc.h"
#define ON                        1
#define OFF                       0
#define YES                       1
#define NO                        0
#define START                     1
#define STOP                      0
#define START_DELAY               2
#define STOP_DELAY                3
#define SET_LEVEL                 1
#define BOOST_COOLING             0
#define COOLING                   1
#define DEFROSTING                0
#define Save_Refrigeration_Mode   0
#define Save_Set_Level            1
#define Save_Lock_State           2
#define Save_Refrigeration_State  3
#define Save_BoostCooling_MinCD   4
#define Save_BoostCooling_HourC   5
#define FRIDGE_SENSOR             1
#define FREEZER_SENSOR            2



/*******************************************************************************
 ****************************Adjustable Parameters******************************
 ******************************************************************************/
#define DisplaySleep_CountDown_sec              30   //30  sec
#define BoostCooling_Duration_hour              8    //48  hours
#define CompressorStart_CountDown_sec           20   //180 sec = 3mins
#define CompressorStop_CountDown_sec            20   //180 sec = 3mins
#define Error_CompressorOFF_Duration_sec        300  //5mins
#define Error_CompressorON_Duration_sec         600  //10mins
#define FridgeSensorOffset_Temp_10Xc            0    //0.0 degree celcius
#define CompressorStart_Temp_10Xc               40   //4.0 degree celcius
#define SetLevel_1_CompressorStop_Temp_10Xc     -160 //-16.0 degree celcius
#define SetLevel_2_CompressorStop_Temp_10Xc     -180 //-18.0 degree celcius
#define SetLevel_3_CompressorStop_Temp_10Xc     -200 //-20.0 degree celcius
#define SetLevel_4_CompressorStop_Temp_10Xc     -220 //-22.0 degree celcius
#define SetLevel_5_CompressorStop_Temp_10Xc     -240 //-24.0 degree celcius



/*******************************************************************************
 *******************************Global Variables********************************
 ******************************************************************************/
uint8_t u8_Touch_Delay, u8_3sec_Count, u8_1min_CountDown;
uint8_t u8_Compressor_Status, u8_FridgeSensor_Error;
uint8_t EE_Refrigeration_Mode, EE_Set_Level, EE_Lock;
uint8_t EE_Refrigeration_State;
uint8_t EE_BoostCooling_Minute_CountDown, EE_BoostCooling_Hour_Count;
uint16_t u16_DisplaySleep_CountDown, u16_CompressorStart_CountDown, u16_CompressorStop_CountDown;
uint16_t u16_5min_CountDown, u16_ADCsample_Count;
uint16_t u16_Error_CompressorOFF_Duration,u16_Error_CompressorON_Duration;
uint32_t u32_Mn, u32_Cn;
int16_t i16_CompressorStop_Temp, i16_CompressorStart_Temp, i16_FridgeSensor_Temp;
int32_t i32_FridgeSensor_ADCsample;



/*******************************************************************************
 * Function Name      : void v_load_system_setting (void)
 * Get Values of      : EE_Refrigeration_Mode
 *                      EE_Set_Level
 *                      EE_Lock
 *                      EE_Refrigeration_State
 *                      EE_BoostCooling_Minute_CountDown
 *                      EE_BoostCooling_Hour_Count
 * When Call          : Set-up stage
 * Description        : Reload Previous Settings from EEPROM/MCU-Memory
 * Modification Date  : 03-Jul-2019
 ******************************************************************************/
void v_load_system_setting(void) {
    if (DATAEE_ReadByte(0xF000) == 255) {
        EE_Refrigeration_Mode = SET_LEVEL; //default
    } else {
        EE_Refrigeration_Mode = DATAEE_ReadByte(0xF000);
    }
    if (DATAEE_ReadByte(0xF001) == 255) {
        EE_Set_Level = 3; //default
    } else {
        EE_Set_Level = DATAEE_ReadByte(0xF001);
    }
    if (DATAEE_ReadByte(0xF002) == 255) {
        EE_Lock = OFF; //default
    } else {
        EE_Lock = DATAEE_ReadByte(0xF002);
    }
    if (DATAEE_ReadByte(0xF003) == 255) {
        EE_Refrigeration_State = COOLING; //default
    } else {
        EE_Refrigeration_State = DATAEE_ReadByte(0xF003);
    }
    if (DATAEE_ReadByte(0xF004) == 255) {
        EE_BoostCooling_Minute_CountDown = 60; //default
    } else {
        EE_BoostCooling_Minute_CountDown = DATAEE_ReadByte(0xF004);
    }
    if (DATAEE_ReadByte(0xF005) == 255) {
        EE_BoostCooling_Hour_Count = 0; //default
    } else {
        EE_BoostCooling_Hour_Count = DATAEE_ReadByte(0xF005);
    }
}




/*******************************************************************************
 * Function Name      : void v_save_system_setting (uint8_t u8_Memory_Index)
 * Returns            : None
 * Arguments          : u8_Memory_Index
 * Description        : Save Current Setting to EEPROM/MCU-Memory
 * Modification Date  : 04-Jul-2019
 ******************************************************************************/
void v_save_system_setting(uint8_t u8_Memory_Index) {
    switch (u8_Memory_Index) {
        case Save_Refrigeration_Mode:
            DATAEE_WriteByte(0xF000, EE_Refrigeration_Mode);
            break;
        case Save_Set_Level:
            DATAEE_WriteByte(0xF001, EE_Set_Level);
            break;
        case Save_Lock_State:
            DATAEE_WriteByte(0xF002, EE_Lock);
            break;
        case Save_Refrigeration_State:
            DATAEE_WriteByte(0xF003, EE_Refrigeration_State);
            break;
        case Save_BoostCooling_MinCD:
            DATAEE_WriteByte(0xF004, EE_BoostCooling_Minute_CountDown);
            break;
        case Save_BoostCooling_HourC:
            DATAEE_WriteByte(0xF005, EE_BoostCooling_Hour_Count);
            break;
    }
}




/*******************************************************************************
 * Function Name      : void v_1s_service_routine (void)
 * Returns            : None
 * Arguments          : None
 * Description        : 1 second Interrupt Service Routine
 * Modification Date  : 04-Jul-2019
 ******************************************************************************/
void v_1s_service_routine(void) {
    //Touch 3sec for ChildLock Button
    if (u8_3sec_Count < 3 && MTOUCH_Button_isPressed(B_SYSTEM_LOCK)) {
        u8_3sec_Count++;
    } 
    //Touch 3sec is reset
    if (!MTOUCH_Button_isPressed(B_SYSTEM_LOCK)){
        u8_3sec_Count = 0;
    }
    //Sleep Delay CountDown
    if (u16_DisplaySleep_CountDown) {
        u16_DisplaySleep_CountDown--;
    }
    //One Minute Routine
    if (u8_1min_CountDown) {
        u8_1min_CountDown--;
    }
    //Five Minute Routine
    if (u16_5min_CountDown){
        u16_5min_CountDown--;
    }
    //Compressor_RUN_time_countdown_during_sensor_error
    if (u16_Error_CompressorON_Duration && u8_Compressor_Status == START) {
        u16_Error_CompressorON_Duration--;
    }
    //Compressor_REST_time_countdown_during_sensor_error
    if (u16_Error_CompressorOFF_Duration && u8_Compressor_Status == STOP) {
        u16_Error_CompressorOFF_Duration--;
    }
    //Compressor Start Delay CountDown
    if (u16_CompressorStart_CountDown && u8_Compressor_Status == START_DELAY) {
        u16_CompressorStart_CountDown--;
        IND_COMP_Toggle();
    }
    //Compressor Stop Delay CountDown
    if (u16_CompressorStop_CountDown && u8_Compressor_Status == STOP_DELAY) {
        u16_CompressorStop_CountDown--;
        IND_COMP_Toggle();
    } 
}




/*******************************************************************************
 * Function Name      : void v_1ms_service_routine (void)
 * Returns            : None
 * Arguments          : None
 * Description        : 1 milli second Interrupt Service Routine
 * Modification Date  : 04-Jul-2019
 ******************************************************************************/
void v_1ms_service_routine(void) {
    //Touch Once //If no buttons is touched then delay will be zero
    if (u8_Touch_Delay && !MTOUCH_Button_isPressed(B_SET_LEVEL) && !MTOUCH_Button_isPressed(B_BOOST_COOLING) && !MTOUCH_Button_isPressed(B_SYSTEM_LOCK)) {
        u8_Touch_Delay -- ;
    }

    //CountDown for activating Display Dim & Sleep Feature
    if (!u16_DisplaySleep_CountDown) {
        LATC = 0b00000000;
    }
}




/*******************************************************************************
 * Function Name      : void v_get_slope_intercept (uint16_t u16_adc)
 * Returns            : u32_Mn & u32_Cn as Global
 * Arguments          : u16_adc
 * Description        : Get Slope & Intercept value from Mapping
 *                      of Polo_10k3950 NTC sensor
 * Modification Date  : 04-Jul-2019
 ******************************************************************************/
void v_get_slope_intercept(uint16_t u16_adc) {
    if (u16_adc) {
        if (u16_adc > 967) {        //-40 to -30
            u32_Mn = 4064;
            u32_Cn = 3634688;
        } else if (u16_adc > 928) { //-30 to -20
            u32_Mn = 2503;
            u32_Cn = 2121523;
        } else if (u16_adc > 867) { //-20 to -10
            u32_Mn = 1672;
            u32_Cn = 1350451;
        } else if (u16_adc > 784) { //-10 to 0
            u32_Mn = 1227;
            u32_Cn = 963461;
        } else if (u16_adc > 681) { //0 to 10
            u32_Mn = 998;
            u32_Cn = 783544;
        } else if (u16_adc > 568) { //10 to 20
            u32_Mn = 905;
            u32_Cn = 719657;
        } else if (u16_adc > 456) { //20 to 30
            u32_Mn = 912;
            u32_Cn = 723139;
        } else if (u16_adc > 355) { //30 to 40
            u32_Mn = 1010;
            u32_Cn = 767048;
        } else if (u16_adc > 270) { //40 to 50
            u32_Mn = 1205;
            u32_Cn = 835963;
        } else if (u16_adc > 203) { //50 to 60
            u32_Mn = 1521;
            u32_Cn = 920842;
        }
    }
}




/*******************************************************************************
 * Function Name      : uint16_t u16_get_adc_value (uint8_t u8_ADC_channel)
 * Returns            : u16_ADC_sample
 * Arguments          : u8_ADC_channel
 * Description        : Get ADC values
 * Modification Date  : 04-Jul-2019
 ******************************************************************************/
uint16_t u16_get_adc_value (uint8_t u8_ADC_channel) {
    uint16_t u16_ADC_sample;
    switch (u8_ADC_channel) {
        case FRIDGE_SENSOR:
            u16_ADC_sample = ADC_GetConversion(RS);
            break;
        case FREEZER_SENSOR:
            //u16_ADC_sample = ADC_GetConversion(FS);
            break;
    }
    return (u16_ADC_sample);
}




/*******************************************************************************
 * Function Name      : void main (void)
 * Returns            : None
 * Arguments          : None
 * Description        : Main Function
 * Modification Date  : 04-Jul-2019
 ******************************************************************************/
void main(void) {
    // initialize the device
    SYSTEM_Initialize();
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    //ISR @1ms
    TMR0_SetInterruptHandler(v_1ms_service_routine);
    //ISR @1s
    TMR1_SetInterruptHandler(v_1s_service_routine);
    
    //Load EEROM Parameters
    v_load_system_setting();
    //Initialize Parameters
    u8_Touch_Delay                   = 0;
    u8_3sec_Count                    = 0;
    u8_1min_CountDown                = 60;
    u16_5min_CountDown               = 300;
    u8_Compressor_Status             = STOP;
    u8_FridgeSensor_Error            = NO;    
    u16_DisplaySleep_CountDown       = DisplaySleep_CountDown_sec;
    u16_CompressorStart_CountDown    = CompressorStart_CountDown_sec;
    u16_CompressorStop_CountDown     = CompressorStop_CountDown_sec;
    u16_ADCsample_Count              = 0;
    u16_Error_CompressorOFF_Duration = 0;
    u16_Error_CompressorON_Duration  = 0;
    i16_CompressorStart_Temp         = CompressorStart_Temp_10Xc;
    i16_CompressorStop_Temp          = 0;
    i16_FridgeSensor_Temp            = 0;
    i32_FridgeSensor_ADCsample       = 0;
    
    

    while (1) {
        /***********************************************************************
         *****************Fridge Sensor Temperature Calculation*****************
         **********************************************************************/
        //Get 1024 ADC Values one by one
        i32_FridgeSensor_ADCsample += (int32_t) u16_get_adc_value(FRIDGE_SENSOR);
        u16_ADCsample_Count++;
        //Temperature Calculation Starts
        if (u16_ADCsample_Count == 1024) {
            //Average Samples Value
            i32_FridgeSensor_ADCsample = i32_FridgeSensor_ADCsample >> 10;
            //Finding Error
            if (i32_FridgeSensor_ADCsample <= 203) {
                //short circuit error
                u8_FridgeSensor_Error = YES;
            } else if (i32_FridgeSensor_ADCsample >= 994) {
                //open circuit error
                u8_FridgeSensor_Error = YES;
            } else {
                //No Error, Therefore start Temperature Calculation
                u8_FridgeSensor_Error = NO;
                v_get_slope_intercept((uint16_t) i32_FridgeSensor_ADCsample);
                i32_FridgeSensor_ADCsample = i32_FridgeSensor_ADCsample * u32_Mn;
                i32_FridgeSensor_ADCsample = (u32_Cn - i32_FridgeSensor_ADCsample) >> 10;
                i16_FridgeSensor_Temp = (int16_t) i32_FridgeSensor_ADCsample + FridgeSensorOffset_Temp_10Xc;
            }
            //Re-initialize
            i32_FridgeSensor_ADCsample = 0;
            u16_ADCsample_Count = 0;
        }

        
        
        
        /***********************************************************************
         ****************Refrigeration During FridgeSensor Error****************
         **********************************************************************/
        if (u8_FridgeSensor_Error == YES) {
            //Compressor ON cycle during Fridge Sensor Error
            if (!u16_Error_CompressorOFF_Duration) {
                u8_Compressor_Status = START;
                u16_Error_CompressorON_Duration = Error_CompressorON_Duration_sec;
            }
            //Compressor OFF cycle during Fridge Sensor Error
            if (!u16_Error_CompressorON_Duration){
                u8_Compressor_Status = STOP;
                u16_Error_CompressorOFF_Duration = Error_CompressorOFF_Duration_sec;
            }
        }
        
        


        /***********************************************************************
         ****************************Refrigeration******************************
         **********************************************************************/
        if (u8_FridgeSensor_Error == NO) {
            switch (EE_Refrigeration_Mode) {
                case BOOST_COOLING:
                    //Main_Function
                    if (!u8_1min_CountDown) {
                        EE_BoostCooling_Minute_CountDown--;
                        //Save Setting to Memory
                        v_save_system_setting(Save_BoostCooling_MinCD);
                        //Re-initialize 60x1s= 60s
                        u8_1min_CountDown = 60;
                    }
                    if (!EE_BoostCooling_Minute_CountDown) {
                        EE_BoostCooling_Hour_Count++;
                        //Save Setting to Memory
                        v_save_system_setting(Save_BoostCooling_HourC);
                        //Re-initialize 60x1min= 1hr
                        EE_BoostCooling_Minute_CountDown = 60;
                    }
                    //Compressor Continuous Running 
                    if (EE_BoostCooling_Hour_Count < BoostCooling_Duration_hour) {
                        u8_Compressor_Status = START;
                    }
                    //Exit From BoostCooling & Return to Previous SET_LEVEL
                    if (EE_BoostCooling_Hour_Count >= BoostCooling_Duration_hour) {
                        u8_Compressor_Status = STOP;
                        EE_Refrigeration_Mode = SET_LEVEL;
                        EE_BoostCooling_Minute_CountDown = 60;
                        EE_BoostCooling_Hour_Count = 0;
                        //Save Setting to Memory
                        v_save_system_setting(Save_Refrigeration_Mode);
                        v_save_system_setting(Save_BoostCooling_MinCD);
                        v_save_system_setting(Save_BoostCooling_HourC);
                    }
                    break;
                case SET_LEVEL:
                    switch (EE_Set_Level) {
                            i16_CompressorStart_Temp = CompressorStart_Temp_10Xc;
                        case 1:
                            i16_CompressorStop_Temp = SetLevel_1_CompressorStop_Temp_10Xc;
                            break;
                        case 2:
                            i16_CompressorStop_Temp = SetLevel_2_CompressorStop_Temp_10Xc;
                            break;
                        case 3:
                            i16_CompressorStop_Temp = SetLevel_3_CompressorStop_Temp_10Xc;
                            break;
                        case 4:
                            i16_CompressorStop_Temp = SetLevel_4_CompressorStop_Temp_10Xc;
                            break;
                        case 5:
                            i16_CompressorStop_Temp = SetLevel_5_CompressorStop_Temp_10Xc;
                            break;
                    }
                    //Cooling State
                    if (u8_Compressor_Status == STOP && (i16_FridgeSensor_Temp >= i16_CompressorStart_Temp || EE_Refrigeration_State == COOLING)) {
                        u8_Compressor_Status = START_DELAY;
                        u16_CompressorStart_CountDown = CompressorStart_CountDown_sec;
                    }
                    if (u8_Compressor_Status == START_DELAY && !u16_CompressorStart_CountDown) {
                        u8_Compressor_Status = START;
                        EE_Refrigeration_State = COOLING;
                        //Save Setting to Memory
                        v_save_system_setting(Save_Refrigeration_State);
                    }
                    //Defrosting State
                    if (u8_Compressor_Status == START && i16_FridgeSensor_Temp <= i16_CompressorStop_Temp) {
                        u8_Compressor_Status = STOP_DELAY;
                        u16_CompressorStop_CountDown = CompressorStop_CountDown_sec;
                        EE_Refrigeration_State = DEFROSTING;
                        //Save Setting to Memory
                        v_save_system_setting(Save_Refrigeration_State);
                    }
                    if (u8_Compressor_Status == STOP_DELAY && !u16_CompressorStop_CountDown) {
                        u8_Compressor_Status = STOP;
                    }
                    break;
            }
        }

        
        
        
        
        /***********************************************************************
         ***************************O/P: Compressor*****************************
         **********************************************************************/
        switch (u8_Compressor_Status){
            case STOP:
                COMP_SetLow();
                IND_COMP_SetLow();
                break;
            case START:
                COMP_SetHigh();
                IND_COMP_SetHigh();
                break;
        }
        
        
        
        
        
        
        
        /***********************************************************************
         ***************************I/P: Touch Button***************************
         **********************************************************************/
        if (MTOUCH_Service_Mainloop()) {
            //IF B_SET_LEVEL Button is Touched Once
            if (MTOUCH_Button_isPressed(B_SET_LEVEL) && !u8_Touch_Delay) {
                u8_Touch_Delay = 3;
                if (!u16_DisplaySleep_CountDown) {
                    //If Device was in Sleep, Just wake UP
                    u16_DisplaySleep_CountDown = DisplaySleep_CountDown_sec;
                } else if (EE_Refrigeration_Mode == SET_LEVEL && !EE_Lock) {
                    u16_DisplaySleep_CountDown = DisplaySleep_CountDown_sec;
                    EE_Set_Level++;
                    if (EE_Set_Level > 5) {
                        EE_Set_Level = 1;
                    }
                    //Save Setting to Memory
                    v_save_system_setting(Save_Set_Level);
                } else if (EE_Refrigeration_Mode == BOOST_COOLING && !EE_Lock) {
                    u16_DisplaySleep_CountDown = DisplaySleep_CountDown_sec;
                    EE_Refrigeration_Mode = SET_LEVEL;
                    EE_BoostCooling_Minute_CountDown = 60;
                    EE_BoostCooling_Hour_Count = 0;
                    //Save Setting to Memory
                    v_save_system_setting(Save_Refrigeration_Mode);
                    v_save_system_setting(Save_BoostCooling_MinCD);
                    v_save_system_setting(Save_BoostCooling_HourC);
                }
            }
            //IF Super_Cool Button is Touched Once
            if (MTOUCH_Button_isPressed(B_BOOST_COOLING) && !u8_Touch_Delay) {
                u8_Touch_Delay = 3;
                if (!u16_DisplaySleep_CountDown) {
                    //If Device was in Sleep, Just wake UP
                    u16_DisplaySleep_CountDown = DisplaySleep_CountDown_sec;
                } else if (EE_Refrigeration_Mode == SET_LEVEL && !EE_Lock) {
                    u16_DisplaySleep_CountDown = DisplaySleep_CountDown_sec;
                    EE_Refrigeration_Mode = BOOST_COOLING;
                    EE_BoostCooling_Minute_CountDown = 60;
                    EE_BoostCooling_Hour_Count = 0;
                    //Save Setting to Memory
                    v_save_system_setting(Save_Refrigeration_Mode);
                    v_save_system_setting(Save_BoostCooling_MinCD);
                    v_save_system_setting(Save_BoostCooling_HourC);
                } else if (EE_Refrigeration_Mode == BOOST_COOLING && !EE_Lock) {
                    u16_DisplaySleep_CountDown = DisplaySleep_CountDown_sec;
                    EE_Refrigeration_Mode = SET_LEVEL;
                    EE_BoostCooling_Minute_CountDown = 60;
                    EE_BoostCooling_Hour_Count = 0;
                    //Save Setting to Memory
                    v_save_system_setting(Save_Refrigeration_Mode);
                    v_save_system_setting(Save_BoostCooling_MinCD);
                    v_save_system_setting(Save_BoostCooling_HourC);
                }
            }
            //IF ChildLock Button is Touched Once
            if (MTOUCH_Button_isPressed(B_SYSTEM_LOCK) && !u8_Touch_Delay) {
                u8_Touch_Delay = 3;
                u16_DisplaySleep_CountDown = DisplaySleep_CountDown_sec;
                //IF ChildLock Button is Touched for 3sec
                if (u8_3sec_Count == 3) {
                    u8_3sec_Count = 0;
                    if (EE_Lock == OFF) {
                        EE_Lock = ON;
                        v_save_system_setting(Save_Lock_State);
                    } else {
                        EE_Lock = OFF;
                        v_save_system_setting(Save_Lock_State);
                    }
                }
            }
        }
        
    
      
        
    }
}
/******************************************************************************
 *********************************End of File**********************************
 ******************************************************************************/