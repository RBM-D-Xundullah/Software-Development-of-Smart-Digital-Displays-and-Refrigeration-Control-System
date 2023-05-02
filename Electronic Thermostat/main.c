/*******************************************************************************
 * Development Name: Electronic Thermostat with POT
 * Target Model    : Beverage Cooler
 * Selected MCU    : PIC16F15344
 * Author          : Raihan Bin Mofidul 
 * Version         : 101
 * Date            : 16-Oct-2019
 *******************************************************************************/



/*******************************************************************************
 ***************************** Headers & Definition*****************************
 ******************************************************************************/
#include "mcc_generated_files/mcc.h"
#define UNKNOWN                                   0

#define OFF                                       0
#define ON                                        1

#define NO                                        0
#define YES                                       1

#define STOP                                      0
#define START                                     1
#define START_DELAY                               2
#define STOP_DELAY                                3

#define COOLING                                   1
#define DEFROSTING                                0

#define CABINET_SENSOR                            1
#define KNOB_RESISTANCE                           2

#define COMPRESSOR_FORCED_STOP                    0
#define COMPRESSOR_FORCED_START                   1
#define COMPRESSOR_RUN_NORMAL                     2
#define COMPRESSOR_RUN_ABNORMAL                   3




/*******************************************************************************
 ****************************Adjustable Parameters******************************
 ******************************************************************************/
//SENSOR_PARAMETER
#define CABINET_SENSOR_TEMPERATURE_OFFSET_10xDEG  0  //00.0 DEG
//COMPRESSOR_PARAMETER
#define COMPRESSOR_START_COUNTDOWN_SEC           20  //180S = 180/60MIN = 3MIN
#define COMPRESSOR_STOP_COUNTDOWN_SEC            20  //180S = 180/60MIN = 3MIN
//SET_1_PARAMETER
#define SET_1_COMPRESSOR_OFF_TEMP_10xDEG         25  //2.5 DEG
#define SET_1_COMPRESSOR_ON_TEMP_10xDEG          60  //6.0 DEG
//SET_2_PARAMETER
#define SET_2_COMPRESSOR_OFF_TEMP_10xDEG         20  //2.0 DEG
#define SET_2_COMPRESSOR_ON_TEMP_10xDEG          56  //5.6 DEG
//SET_3_PARAMETER
#define SET_3_COMPRESSOR_OFF_TEMP_10xDEG         12  //1.2 DEG
#define SET_3_COMPRESSOR_ON_TEMP_10xDEG          48  //4.8 DEG
//SET_4_PARAMETER
#define SET_4_COMPRESSOR_OFF_TEMP_10xDEG          0  //0.0 DEG
#define SET_4_COMPRESSOR_ON_TEMP_10xDEG          37  //3.7 DEG
//SET_5_PARAMETER
#define SET_5_COMPRESSOR_OFF_TEMP_10xDEG         -6  //-0.6 DEG
#define SET_5_COMPRESSOR_ON_TEMP_10xDEG          32  //3.2 DEG
//SET_6_PARAMETER
#define SET_6_COMPRESSOR_OFF_TEMP_10xDEG        -15  //-1.5 DEG
#define SET_6_COMPRESSOR_ON_TEMP_10xDEG          24  //2.4 DEG
//SET_7_PARAMETER
#define SET_7_COMPRESSOR_OFF_TEMP_10xDEG        -25  //-2.5 DEG
#define SET_7_COMPRESSOR_ON_TEMP_10xDEG          15  //1.5 DEG
//ABNORMAL_PARAMETER
#define ERROR_COMPRESSOR_OFF_SEC                 10  //10 SEC
#define ERROR_COMPRESSOR_ON_SEC                  10  //10 SEC





/*******************************************************************************
 *******************************Global Variables********************************
 ******************************************************************************/
//Compressor_Related_Variables
uint8_t u8_CompressorStatus;
uint16_t u16_CompressorStart_CountDown, u16_CompressorStop_CountDown;
uint16_t u16_Error_CompressorON_Duration, u16_Error_CompressorOFF_Duration;
int16_t i16_CompressorStart_Temp, i16_CompressorStop_Temp;
//Sensor_Related_Variables
uint8_t u8_CabinetSensor_Error;
uint16_t u16_Knob_Res, u16_ADCsample_Count;
uint32_t u32_Mn, u32_Cn, u32_KnobPOT_ADCsample;
int32_t i32_CabinetSensor_ADCsample;
int16_t i16_CabinetSensor_Temp;
//Others
uint8_t u8_Refrigeration_Mode, u8_Refrigeration_State, u8_SetLevel;

/*******************************************************************************
 * Function Name      : void v_1s_service_routine (void)
 * Returns            : None
 * Arguments          : None
 * Description        : 1 second Interrupt Service Routine
 * Modification Date  : 04-Jul-2019
 ******************************************************************************/
void v_1s_service_routine(void) {
    //Compressor Start Delay CountDown
    if (u16_CompressorStart_CountDown && u8_CompressorStatus == START_DELAY) {
        u16_CompressorStart_CountDown--;
        O_IND_Toggle();
    }
    //Compressor Stop Delay CountDown
    if (u16_CompressorStop_CountDown && u8_CompressorStatus == STOP_DELAY) {
        u16_CompressorStop_CountDown--;
        //_IND_Toggle();
    }
    //Compressor_RUN_time_countdown_during_sensor_error
    if (u16_Error_CompressorON_Duration) {
        u16_Error_CompressorON_Duration--;
    }
    //Compressor_REST_time_countdown_during_sensor_error
    if (u16_Error_CompressorOFF_Duration) {
        u16_Error_CompressorOFF_Duration--;
    }
}

/*******************************************************************************
 * Function Name      : uint16_t u16_get_adc_value (uint8_t u8_ADC_channel)
 * Returns            : u16_ADC_sample
 * Arguments          : u8_ADC_channel
 * Description        : Get ADC values
 * Modification Date  : 04-Jul-2019
 ******************************************************************************/
uint16_t u16_get_adc_value(uint8_t u8_ADC_channel) {
    uint16_t u16_ADC_sample;
    switch (u8_ADC_channel) {
        case CABINET_SENSOR:
            u16_ADC_sample = ADC_GetConversion(A_FS);
            break;
        case KNOB_RESISTANCE:
            u16_ADC_sample = ADC_GetConversion(A_KNOB);
            break;
    }
    return (u16_ADC_sample);
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
        if (u16_adc > 967) { //-40 to -30
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

    //ISR @1s
    TMR1_SetInterruptHandler(v_1s_service_routine);

    //Initialize Parameters
    //Compressor_Related_Variables
    u8_CompressorStatus = STOP;
    u16_CompressorStart_CountDown = 0;
    u16_CompressorStop_CountDown = 0;
    u16_Error_CompressorON_Duration = 0;
    u16_Error_CompressorOFF_Duration = 0;
    i16_CompressorStart_Temp = UNKNOWN;
    i16_CompressorStop_Temp = UNKNOWN;
    //Sensor_Related_Variables
    u8_CabinetSensor_Error = NO;
    u16_Knob_Res = UNKNOWN;
    u16_ADCsample_Count = UNKNOWN;
    u32_Mn = UNKNOWN;
    u32_Cn = UNKNOWN;
    i32_CabinetSensor_ADCsample = UNKNOWN;
    u32_KnobPOT_ADCsample = UNKNOWN;
    i16_CabinetSensor_Temp = UNKNOWN;
    //Others
    u8_Refrigeration_Mode = UNKNOWN;
    u8_Refrigeration_State = COOLING;



    while (1) {
        /***********************************************************************
         ****************Cabinet Sensor Temperature Calculation*****************
         *********************Knob Resistance Calculation***********************
         **********************************************************************/
        //Get 1024 ADC Values one by one
        i32_CabinetSensor_ADCsample += (int32_t) u16_get_adc_value(CABINET_SENSOR);
        u32_KnobPOT_ADCsample += (uint32_t) u16_get_adc_value(KNOB_RESISTANCE);
        u16_ADCsample_Count++;


        //Calculation Starts
        if (u16_ADCsample_Count == 1024) {


            /***********************Cabinet Sensor*****************************/
            //Average Samples Value
            i32_CabinetSensor_ADCsample = i32_CabinetSensor_ADCsample >> 10;
            //Finding Error
            if (i32_CabinetSensor_ADCsample <= 203) {
                //short circuit error
                u8_CabinetSensor_Error = YES;
            } else if (i32_CabinetSensor_ADCsample >= 994) {
                //open circuit error
                u8_CabinetSensor_Error = YES;
            } else {
                //No Error, Therefore start Temperature Calculation
                u8_CabinetSensor_Error = NO;
                v_get_slope_intercept((uint16_t) i32_CabinetSensor_ADCsample);
                i32_CabinetSensor_ADCsample = i32_CabinetSensor_ADCsample * u32_Mn;
                i32_CabinetSensor_ADCsample = (u32_Cn - i32_CabinetSensor_ADCsample) >> 10;
                i16_CabinetSensor_Temp = (int16_t) i32_CabinetSensor_ADCsample + CABINET_SENSOR_TEMPERATURE_OFFSET_10xDEG;
            }
            /******************************************************************/


            /***********************Knob Resistance****************************/
            //Average Samples Value
            u32_KnobPOT_ADCsample = u32_KnobPOT_ADCsample >> 10;
            u16_Knob_Res = (uint16_t) u32_KnobPOT_ADCsample;
            /******************************************************************/


            //Re-initialize
            u16_ADCsample_Count = 0;
            i32_CabinetSensor_ADCsample = 0;
            u32_KnobPOT_ADCsample = 0;
        }



        /***********************************************************************
         ****************************I/O: Knob *********************************
         **********************************************************************/
        if (u16_Knob_Res > 994) { //set 0
            u8_Refrigeration_Mode = COMPRESSOR_FORCED_STOP;
        } else if (u16_Knob_Res > 897) { //set 1
            if (u8_CabinetSensor_Error == NO) {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_NORMAL;
                i16_CompressorStop_Temp = SET_1_COMPRESSOR_OFF_TEMP_10xDEG;
                i16_CompressorStart_Temp = SET_1_COMPRESSOR_ON_TEMP_10xDEG;
            } else {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_ABNORMAL;
            }
        } else if (u16_Knob_Res > 762) { //set 2
            if (u8_CabinetSensor_Error == NO) {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_NORMAL;
                i16_CompressorStop_Temp = SET_2_COMPRESSOR_OFF_TEMP_10xDEG;
                i16_CompressorStart_Temp = SET_2_COMPRESSOR_ON_TEMP_10xDEG;
            } else {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_ABNORMAL;
            }
        } else if (u16_Knob_Res > 614) { //set 3
            if (u8_CabinetSensor_Error == NO) {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_NORMAL;
                i16_CompressorStop_Temp = SET_3_COMPRESSOR_OFF_TEMP_10xDEG;
                i16_CompressorStart_Temp = SET_3_COMPRESSOR_ON_TEMP_10xDEG;
            } else {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_ABNORMAL;
            }
        } else if (u16_Knob_Res > 457) { //set 4
            if (u8_CabinetSensor_Error == NO) {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_NORMAL;
                i16_CompressorStop_Temp = SET_4_COMPRESSOR_OFF_TEMP_10xDEG;
                i16_CompressorStart_Temp = SET_4_COMPRESSOR_ON_TEMP_10xDEG;
            } else {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_ABNORMAL;
            }
        } else if (u16_Knob_Res > 303) { //set 5
            if (u8_CabinetSensor_Error == NO) {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_NORMAL;
                i16_CompressorStop_Temp = SET_5_COMPRESSOR_OFF_TEMP_10xDEG;
                i16_CompressorStart_Temp = SET_5_COMPRESSOR_ON_TEMP_10xDEG;
            } else {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_ABNORMAL;
            }
        } else if (u16_Knob_Res > 155) { //set 6
            if (u8_CabinetSensor_Error == NO) {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_NORMAL;
                i16_CompressorStop_Temp = SET_6_COMPRESSOR_OFF_TEMP_10xDEG;
                i16_CompressorStart_Temp = SET_6_COMPRESSOR_ON_TEMP_10xDEG;
            } else {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_ABNORMAL;
            }
        } else if (u16_Knob_Res > 43) { //set 7
            if (u8_CabinetSensor_Error == NO) {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_NORMAL;
                i16_CompressorStop_Temp = SET_7_COMPRESSOR_OFF_TEMP_10xDEG;
                i16_CompressorStart_Temp = SET_7_COMPRESSOR_ON_TEMP_10xDEG;
            } else {
                u8_Refrigeration_Mode = COMPRESSOR_RUN_ABNORMAL;
            }
        } else if (u16_Knob_Res >= 0) { //set 8
            u8_Refrigeration_Mode = COMPRESSOR_FORCED_START;
        }
        
        
        

        /***********************************************************************
         ****************************Refrigeration******************************
         **********************************************************************/
        
        switch (u8_Refrigeration_Mode) {
            case COMPRESSOR_FORCED_STOP:
                //Defrosting State
                if (u8_CompressorStatus == START) {
                    u8_CompressorStatus = STOP_DELAY;
                    u16_CompressorStop_CountDown = COMPRESSOR_STOP_COUNTDOWN_SEC;
                }
                if (u8_CompressorStatus == STOP_DELAY && !u16_CompressorStop_CountDown) {
                    u8_CompressorStatus = STOP;
                }
                break;
            case COMPRESSOR_FORCED_START:
                //Cooling State
                if (u8_CompressorStatus == STOP) {
                    u8_CompressorStatus = START_DELAY;
                    u16_CompressorStart_CountDown = COMPRESSOR_START_COUNTDOWN_SEC;
                }
                if (u8_CompressorStatus == START_DELAY && !u16_CompressorStart_CountDown) {
                    u8_CompressorStatus = START;
                }
                break;
            case COMPRESSOR_RUN_NORMAL:
                //Cooling State
                if (u8_CompressorStatus == STOP && i16_CabinetSensor_Temp >= i16_CompressorStart_Temp) {
                    u8_CompressorStatus = START_DELAY;
                    u16_CompressorStart_CountDown = COMPRESSOR_START_COUNTDOWN_SEC;
                }
                if (u8_CompressorStatus == START_DELAY && !u16_CompressorStart_CountDown) {
                    u8_CompressorStatus = START;
                }
                //Defrosting State
                if (u8_CompressorStatus == START && i16_CabinetSensor_Temp <= i16_CompressorStop_Temp) {
                    u8_CompressorStatus = STOP_DELAY;
                    u16_CompressorStop_CountDown = COMPRESSOR_STOP_COUNTDOWN_SEC;
                }
                if (u8_CompressorStatus == STOP_DELAY && !u16_CompressorStop_CountDown) {
                    u8_CompressorStatus = STOP;
                }
                break;
            case COMPRESSOR_RUN_ABNORMAL:
                switch (u8_CompressorStatus) {
                    case START:
                        if (!u16_Error_CompressorON_Duration) {
                            u8_CompressorStatus = STOP;
                            u16_Error_CompressorOFF_Duration = ERROR_COMPRESSOR_OFF_SEC;
                        }
                        break;
                    case STOP:
                        if (!u16_Error_CompressorOFF_Duration) {
                            u8_CompressorStatus = START;
                            u16_Error_CompressorON_Duration = ERROR_COMPRESSOR_ON_SEC;
                        }
                        break;
                    default:
                        u8_CompressorStatus = START;
                        break;
                }
                break;
        }



        /***********************************************************************
         ****************************O/P: Compressor*****************************
         ***********************************************************************/
        switch (u8_CompressorStatus) {
            case STOP:
                O_MOTOR_SetLow();
                O_IND_SetLow();
                break;
            case START:
                O_MOTOR_SetHigh();
                O_IND_SetHigh();
                break;
        }




    }
}
/******************************************************************************
 *********************************End of File**********************************
 ******************************************************************************/