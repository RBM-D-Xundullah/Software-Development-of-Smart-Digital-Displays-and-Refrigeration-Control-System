/*******************************************************************************
 * Development Name: FROST DUAL TEMPERATURE DISPLAY
 * Target Model    : FROST REFRIGERATORS
 * Selected MCU    : PIC16F15344
 * Author          : Raihan Bin Mofidul 
 * Version         : 01
 * CRC32           : 0x196C4439
 * Date            : 12-NOV-2019
 *******************************************************************************/


/*******************************************************************************
 ****************************Adjustable Parameters******************************
 ******************************************************************************/
//SENSOR_PARAMETER
#define F_SENSOR_TEMPERATURE_OFFSET_10xDEG       0   //00.0 DEG FOR 238L
#define R_SENSOR_TEMPERATURE_OFFSET_10xDEG      -30  //-3.0 DEG FOR 238L
//DISPLAY_PARAMETER
#define DIMMING_START_COUNTDOWN_SEC              10  //10 SEC   FOR ALL
#define SLEEPING_START_COUNTDOWN_SEC             60  //60 SEC   FOR ALL
/******************************************************************************/


/*******************************************************************************
 ***************************** Headers & Definition*****************************
 ******************************************************************************/
#include "mcc_generated_files/mcc.h"
/******************************************************************************/


/*******************************************************************************
 *********************COMMON ANODE SEVEN SEGMENT BIT PARRERNS*******************
 ******************************************************************************/
static const uint8_t u8_PATTERN[] = {
    0b11000000, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "0" @ARRAY 0
    0b11111001, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "1" @ARRAY 1
    0b10100100, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "2" @ARRAY 2
    0b10110000, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "3" @ARRAY 3
    0b10011001, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "4" @ARRAY 4
    0b10010010, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "5" @ARRAY 5
    0b10000010, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "6" @ARRAY 6
    0b11111000, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "7" @ARRAY 7
    0b10000000, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "8" @ARRAY 8
    0b10010000, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "9" @ARRAY 9
    0b00000000, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY ALL @ARRAY 10
    0b11111111, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY NONE@ARRAY 11
    0b10000110, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "E" @ARRAY 12
    0b11000111, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "L" @ARRAY 13
    0b10001001, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "H" @ARRAY 14       
    0b10111111, //SEVEN SEGMENT 8-BIT VALUE TO DISPLAY "-" @ARRAY 15  
};
/******************************************************************************/


/*******************************************************************************
 *******************************Global Variables********************************
 ******************************************************************************/
//LED RELATED VARIABLES
uint8_t u8_DIG_CHANNEL, u8_DIG11, u8_DIG12, u8_DIG13, u8_DIG21, u8_DIG22;
uint8_t u8_DIMMING_START_COUNTDOWN_SEC, u8_SLEEPING_START_COUNTDOWN_SEC;

//TOUCH RELATED VARIABLES
uint8_t u8_TOUCH_DELAY_COUNTDOWN;

//SENSOR RELATED VARIABLES
uint16_t u16_ADCsample_COUNT;
uint32_t u32_Mn, u32_Cn;
int16_t i16_F_SENSOR_TEMPERATURE_10xDEG, i16_R_SENSOR_TEMPERATURE_10xDEG;
int32_t i32_F_SENSOR_ADCsample, i32_R_SENSOR_ADCsample;
/******************************************************************************/

/*******************************************************************************
 * Function Name      : void v_1s_service_routine (void)
 * Returns            : None
 * Arguments          : None
 * Description        : 1 second Interrupt Service Routine using timer1
 * Modification Date  : 07-NOV-2019
 ******************************************************************************/
void v_1s_service_routine(void) {
    //u8_DIMMING_START_COUNTDOWN_SEC
    if (u8_DIMMING_START_COUNTDOWN_SEC) {
        u8_DIMMING_START_COUNTDOWN_SEC--;
    }
    //u8_SLEEPING_START_COUNTDOWN_SEC
    if (u8_SLEEPING_START_COUNTDOWN_SEC) {
        u8_SLEEPING_START_COUNTDOWN_SEC--; /*DISPLAY CENTER*/
    }
}

/*******************************************************************************
 * Function Name      : void v_1ms_service_routine (void)
 * Returns            : None
 * Arguments          : None
 * Description        : 1 milli second Interrupt Service Routine using timer0
 * Modification Date  : 12-NOV-2019
 ******************************************************************************/
void v_1ms_service_routine(void) {
    /*Touch Once: If no buttons is touched then delay will be zero*************/
    if (u8_TOUCH_DELAY_COUNTDOWN && !MTOUCH_Button_isPressed(I_K1)) {
        u8_TOUCH_DELAY_COUNTDOWN--;
    }
    /*DISPLAY SERVICE ROUTINE*/
    if (u8_SLEEPING_START_COUNTDOWN_SEC) {
        /*FIXED@ 1-APR-2019: DISCHARGE SEGMENT PINS*/
        LATC = 0xFF;
        /*TURN OFF ALL DIG PORTS*/
        O_DIG11_SetLow();
        O_DIG12_SetLow();
        O_DIG13_SetLow();
        O_DIG21_SetLow();
        O_DIG22_SetLow();
        O_ECO_SetLow();
        /*DISPLAY CHANNEL ACTIVITY*/
        switch (u8_DIG_CHANNEL) {
            case 0:
                O_ECO_SetHigh();
                O_DIG11_SetHigh();
                LATC = u8_PATTERN[u8_DIG11];
                break;
            case 3:
                O_DIG12_SetHigh();
                LATC = u8_PATTERN[u8_DIG12];
                break;
            case 6:
                O_DIG13_SetHigh();
                LATC = u8_PATTERN[u8_DIG13];
                break;
            case 9:
                O_DIG21_SetHigh();
                LATC = u8_PATTERN[u8_DIG21];
                break;
            case 12:
                O_DIG22_SetHigh();
                LATC = u8_PATTERN[u8_DIG22];
                break;
        }

        /*DISPLAY DIMMING SERVICE*/
        if (u8_DIMMING_START_COUNTDOWN_SEC) {
            //FULL INTENSITY
            u8_DIG_CHANNEL += 3;
        } else {
            //LOW INTESITY, WHEN DIMMING COUNTDOWN IS COMPLETED
            u8_DIG_CHANNEL++;
        }

        /*FIXED@ 12-NOV-2019: logic must be called after incremental value*/
        /*Re-initialize*/
        if (u8_DIG_CHANNEL >= 15) {
            u8_DIG_CHANNEL = 0;
        }
    } else {
        /*FIXED@ 1-APR-2019: OFFLINE SEGMENT PINS*/
        LATC = 0x00;
        /*TURN OFF ALL DIG PORTS*/
        O_DIG11_SetLow();
        O_DIG12_SetLow();
        O_DIG13_SetLow();
        O_DIG21_SetLow();
        O_DIG22_SetLow();
        O_ECO_SetLow();
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
 * Description        : Main Function (FIXED @12-NOV-2019 SYSTEM CLOCK 16MHz)
 * Modification Date  : 12-NOV-2019
 ******************************************************************************/
void main(void) {
    // initialize the device
    SYSTEM_Initialize();
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    //ISR @1millisec
    TMR0_SetInterruptHandler(v_1ms_service_routine);
    //ISR @1sec
    TMR1_SetInterruptHandler(v_1s_service_routine);

    //Initialize Parameters
    u8_DIG_CHANNEL = 0;
    u8_DIG11 = 10; //DISPLAY ALL @ARRAY 10
    u8_DIG12 = 10; //DISPLAY ALL @ARRAY 10
    u8_DIG13 = 10; //DISPLAY ALL @ARRAY 10
    u8_DIG21 = 10; //DISPLAY ALL @ARRAY 10
    u8_DIG22 = 10; //DISPLAY ALL @ARRAY 10
    u8_DIMMING_START_COUNTDOWN_SEC = DIMMING_START_COUNTDOWN_SEC;
    u8_SLEEPING_START_COUNTDOWN_SEC = SLEEPING_START_COUNTDOWN_SEC;
    u8_TOUCH_DELAY_COUNTDOWN = 5; //FIXED@ 12-NOV-2019
    u16_ADCsample_COUNT = 0;
    u32_Mn = 0;
    u32_Cn = 0;
    i16_F_SENSOR_TEMPERATURE_10xDEG = 0;
    i16_R_SENSOR_TEMPERATURE_10xDEG = 0;
    i32_F_SENSOR_ADCsample = 0;
    i32_R_SENSOR_ADCsample = 0;



    while (1) {
        /***********************************************************************
         *******************Sensors Temperature Calculation*********************
         **********************************************************************/
        /*Get A SUMMATION OF 256 ADC Values one by one********/
        i32_F_SENSOR_ADCsample += (int32_t) ADC_GetConversion(A_FS);
        i32_R_SENSOR_ADCsample += (int32_t) ADC_GetConversion(A_RS);
        u16_ADCsample_COUNT++;


        /*FIXED @12-NOV-2019: AFTER 2^8 DATA COUNTDOWN*************************/
        if (u16_ADCsample_COUNT == 256) {
            /***********************Freezer Sensor*****************************/
            /*AVERAGE VALUE OF ADCsample***********************/
            i32_F_SENSOR_ADCsample = i32_F_SENSOR_ADCsample >> 8;
            /*FINDING SENSOR ERROR*****************************/
            if (i32_F_SENSOR_ADCsample <= 203) {
                /*Short Circuit or High Temperature Error*/
                u8_DIG11 = 11; //DISPLAY NONE@ARRAY 11
                u8_DIG12 = 1; //DISPLAY "1" @ARRAY 1
                u8_DIG13 = 14; //DISPLAY "H" @ARRAY 14
            } else if (i32_F_SENSOR_ADCsample >= 994) {
                /*Open Circuit or Low Temperature Error*/
                u8_DIG11 = 11; //DISPLAY NONE@ARRAY 11
                u8_DIG12 = 1; //DISPLAY "1" @ARRAY 1
                u8_DIG13 = 13; //DISPLAY "L" @ARRAY 13
            }                
            /*No Sensor Error; Therefore, Temperature Calculation Begins*******/
            else {
                v_get_slope_intercept((uint16_t) i32_F_SENSOR_ADCsample);
                i32_F_SENSOR_ADCsample = i32_F_SENSOR_ADCsample * u32_Mn;
                i32_F_SENSOR_ADCsample = (u32_Cn - i32_F_SENSOR_ADCsample) >> 10;
                i16_F_SENSOR_TEMPERATURE_10xDEG = (int16_t) i32_F_SENSOR_ADCsample;
                /*ADDING TEMPERATURE OFFSET*/
                i16_F_SENSOR_TEMPERATURE_10xDEG += F_SENSOR_TEMPERATURE_OFFSET_10xDEG;
                /*DECIMAL CORRECTION FOR (+VE) VALUE*/
                if (i16_F_SENSOR_TEMPERATURE_10xDEG >= 0 && (i16_F_SENSOR_TEMPERATURE_10xDEG % 10) >= 5) {
                    i16_F_SENSOR_TEMPERATURE_10xDEG = i16_F_SENSOR_TEMPERATURE_10xDEG + 5;
                }                    /*DECIMAL CORRECTION FOR (-VE) VALUE*/
                else if (i16_F_SENSOR_TEMPERATURE_10xDEG < 0 && ((i16_F_SENSOR_TEMPERATURE_10xDEG*-1) % 10) >= 5) {
                    i16_F_SENSOR_TEMPERATURE_10xDEG = i16_F_SENSOR_TEMPERATURE_10xDEG - 5;
                }
                /**************************************************************/
                /*DISPLAY TEMPERATURE**************************/
                /*WHEN, SENSOR TEMPERATURE <= -1.0 DEG*/
                if (i16_F_SENSOR_TEMPERATURE_10xDEG <= -10) {
                    /*WHEN SENSOR TEMPERATURE IS BEYOND MIN LIMIT*/
                    if (i16_F_SENSOR_TEMPERATURE_10xDEG < -400) {
                        i16_F_SENSOR_TEMPERATURE_10xDEG = -400;
                    }
                    /*WHEN, -10.0 DEG < SENSOR TEMPERATURE <= -1.0 DEG */
                    if ((i16_F_SENSOR_TEMPERATURE_10xDEG > -100) && (i16_F_SENSOR_TEMPERATURE_10xDEG <= -10)) {
                        u8_DIG11 = 11; //DISPLAY NONE@ARRAY 11
                        u8_DIG12 = 15; //DISPLAY "-" @ARRAY 15
                        u8_DIG13 = ((i16_F_SENSOR_TEMPERATURE_10xDEG*-1) / 10) % 10;
                    }                        /*WHEN, -40.0 DEG <= SENSOR TEMPERATURE <= -10.0 DEG */
                    else {
                        u8_DIG11 = 15; //DISPLAY "-" @ARRAY 15
                        u8_DIG12 = (i16_F_SENSOR_TEMPERATURE_10xDEG*-1) / 100;
                        u8_DIG13 = ((i16_F_SENSOR_TEMPERATURE_10xDEG*-1) / 10) % 10;
                    }
                }                    /*WHEN, SENSOR TEMPERATURE >= 0 DEG*/
                else {
                    /*SET 0.0 DEG, WHEN -1.0 DEG < SENSOR TEMPERATURE <= 0.0 DEG */
                    if ((i16_F_SENSOR_TEMPERATURE_10xDEG > -10)&&(i16_F_SENSOR_TEMPERATURE_10xDEG <= 0)) {
                        i16_F_SENSOR_TEMPERATURE_10xDEG = 0;
                    }
                    /*WHEN SENSOR TEMPERATURE IS BEYOND MAX LIMIT*/
                    if (i16_F_SENSOR_TEMPERATURE_10xDEG > 600) {
                        i16_F_SENSOR_TEMPERATURE_10xDEG = 600;
                    }
                    /*WHEN, 0.0 DEG <= SENSOR TEMPERATURE < 10.0 DEG */
                    if ((i16_F_SENSOR_TEMPERATURE_10xDEG >= 0) && (i16_F_SENSOR_TEMPERATURE_10xDEG < 100)) {
                        u8_DIG11 = 11; //DISPLAY NONE@ARRAY 11
                        u8_DIG12 = 11; //DISPLAY NONE@ARRAY 11
                        u8_DIG13 = (i16_F_SENSOR_TEMPERATURE_10xDEG / 10) % 10;
                    }/*WHEN, 10.0 DEG <= SENSOR TEMPERATURE <= 60.0 DEG */
                    else {
                        u8_DIG11 = 11; //DISPLAY NONE@ARRAY 11
                        u8_DIG12 = i16_F_SENSOR_TEMPERATURE_10xDEG / 100;
                        u8_DIG13 = (i16_F_SENSOR_TEMPERATURE_10xDEG / 10) % 10;
                    }
                }
            }
            /***********************Freezer Sensor*****************************/


            /******************* *Refrigerator Sensor**************************/
            /*AVERAGE VALUE OF ADCsample***********************/
            i32_R_SENSOR_ADCsample = i32_R_SENSOR_ADCsample >> 8;
            /*FINDING SENSOR ERROR*****************************/
            if (i32_R_SENSOR_ADCsample <= 203) {
                /*Short Circuit or High Temperature Error*/
                u8_DIG21 = 2; //DISPLAY "2" @ARRAY 2
                u8_DIG22 = 14; //DISPLAY "H" @ARRAY 14
            } else if (i32_R_SENSOR_ADCsample >= 994) {
                /*Open Circuit or Low Temperature Error*/
                u8_DIG21 = 2; //DISPLAY "2" @ARRAY 2
                u8_DIG22 = 13; //DISPLAY "L" @ARRAY 13
            }                
            /*No Sensor Error; Therefore, Temperature Calculation Begins*******/
            else {
                v_get_slope_intercept((uint16_t) i32_R_SENSOR_ADCsample);
                i32_R_SENSOR_ADCsample = i32_R_SENSOR_ADCsample * u32_Mn;
                i32_R_SENSOR_ADCsample = (u32_Cn - i32_R_SENSOR_ADCsample) >> 10;
                i16_R_SENSOR_TEMPERATURE_10xDEG = (int16_t) i32_R_SENSOR_ADCsample;
                /*ADDING TEMPERATURE OFFSET*/
                i16_R_SENSOR_TEMPERATURE_10xDEG += R_SENSOR_TEMPERATURE_OFFSET_10xDEG;
                /*DECIMAL CORRECTION FOR (+VE) VALUE*/
                if (i16_R_SENSOR_TEMPERATURE_10xDEG >= 0 && (i16_R_SENSOR_TEMPERATURE_10xDEG % 10) >= 5) {
                    i16_R_SENSOR_TEMPERATURE_10xDEG = i16_R_SENSOR_TEMPERATURE_10xDEG + 5;
                }
                /*NO NEED: DECIMAL CORRECTION FOR (-VE) VALUE*/
                /**************************************************************/
                /*DISPLAY TEMPERATURE**************************/
                /*NO NEED: WHEN, SENSOR TEMPERATURE <= -1.0 DEG*/
                /*WHEN, SENSOR TEMPERATURE >= 0 DEG*/
                if (i16_R_SENSOR_TEMPERATURE_10xDEG <= 10) {
                    /*SET 1.0 DEG, WHEN SENSOR TEMPERATURE <= 1.0 DEG */
                    i16_R_SENSOR_TEMPERATURE_10xDEG = 10;
                }
                /*WHEN SENSOR TEMPERATURE IS BEYOND MAX LIMIT*/
                if (i16_R_SENSOR_TEMPERATURE_10xDEG > 600) {
                    i16_R_SENSOR_TEMPERATURE_10xDEG = 600;
                }
                /*WHEN, 1.0 DEG <= SENSOR TEMPERATURE < 10.0 DEG */
                if ((i16_R_SENSOR_TEMPERATURE_10xDEG >= 10) && (i16_R_SENSOR_TEMPERATURE_10xDEG < 100)) {
                    u8_DIG21 = 11; //DISPLAY NONE@ARRAY 11
                    u8_DIG22 = (i16_R_SENSOR_TEMPERATURE_10xDEG / 10) % 10;
                }                    /*WHEN, 10.0 DEG <= SENSOR TEMPERATURE <= 60.0 DEG */
                else {
                    u8_DIG21 = i16_R_SENSOR_TEMPERATURE_10xDEG / 100;
                    u8_DIG22 = (i16_R_SENSOR_TEMPERATURE_10xDEG / 10) % 10;
                }
            }
            /******************* *Refrigerator Sensor**************************/


            /*Re-initialize*/
            u16_ADCsample_COUNT = 0;
            i32_F_SENSOR_ADCsample = 0;
            i32_R_SENSOR_ADCsample = 0;
        }


        /***********************************************************************
         ***********************I/O: CAP TOUCH (I_K1)***************************
         **********************************************************************/
        if (MTOUCH_Service_Mainloop()) {
            if (MTOUCH_Button_isPressed(I_K1) && !u8_TOUCH_DELAY_COUNTDOWN) {
                u8_TOUCH_DELAY_COUNTDOWN = 5;
                if (!u8_SLEEPING_START_COUNTDOWN_SEC) {
                    u8_SLEEPING_START_COUNTDOWN_SEC = SLEEPING_START_COUNTDOWN_SEC;
                    u8_DIMMING_START_COUNTDOWN_SEC = DIMMING_START_COUNTDOWN_SEC;
                } else {
                    u8_SLEEPING_START_COUNTDOWN_SEC = 0;
                    u8_DIMMING_START_COUNTDOWN_SEC = 0;
                }
            }
        }


    }
}
/******************************************************************************
 *********************************End of File**********************************
 ******************************************************************************/