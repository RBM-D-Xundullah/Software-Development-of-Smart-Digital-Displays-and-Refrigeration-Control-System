//Date-04-Apr-2019

#include "mcc_generated_files/mcc.h"
#include <stdio.h>

#define ON     1
#define OFF    0
#define DELAY  2

static const uint8_t u8_seg[] = {
    0b11000000, //8bit binary value to display the number 0
    0b11111001, //8bit binary value to display the number 1
    0b10100100, //8bit binary value to display the number 2
    0b10110000, //8bit binary value to display the number 3
    0b10011001, //8bit binary value to display the number 4
    0b10010010, //8bit binary value to display the number 5
    0b10000010, //8bit binary value to display the number 6
    0b11111000, //8bit binary value to display the number 7
    0b10000000, //8bit binary value to display the number 8
    0b10010000, //8bit binary value to display the number 9
    0b00000000, //8bit binary value to display all  @serial 10
    0b11111111, //8bit binary value to display none @serial 11
    0b10111111, //8bit binary value to display the symbol '-' @serial 12 
    0b10000110, //8bit binary value to display the symbol 'E' @serial 13       
};

//constant value set by user
static const uint16_t u16_SLEEP_StartDelay_Sec        = 120;      //30   sec
static const uint16_t u16_COMP_StartDelay_Sec         = 20;     //180  sec
static const uint8_t  u8_SuperCool_Hr                 = 8;       //8    hour
static const int8_t   i8_FC_TemperatureOffset         = 0;       //0 degree 
static const int8_t   i8_PC_TemperatureOffset         = 0;       //0 degree
static const int8_t   i8_COMP_ON_Temperature          = 4;       //4 degree

//unsigned integer variables
uint8_t u8_DIG1, u8_DIG2, u8_DIG3, u8_IND_LEV_KEY, u8_DIS_Channel;
uint16_t u16_SLEEP_DelayCount, u16_COMP_DelayCount;
uint8_t u8_3sec_Count, u8_TouchDelay;
uint8_t u8_Timer_Countdown_Min, EE_COMP_RUN_CountDown_Min, EE_COMP_TOTAL_RUN_Count_Hr;
uint8_t u8_REF_SetLevel, u8_SuperCool_Status, u8_LOCK_Status, u8_COMP_Status, EE_COMP_Flag;

//integer variables
int8_t i8_COMP_OFF_Temperature;

//Uart Variables
uint8_t u8_Index, u8_Tx_Status, u8_Rx_DataBuff[10], u8_Tx_DataBuff[10];
uint8_t v_u8_RxData; 
uint8_t u8_COMP_Start;
uint8_t u8_ErrorCodes, u8_Door_Open;
int8_t i8_F_Temperature, i8_R_Temperature;



//EEPROM_LOADING_Functions 0xF000 to 0xF0FF
void Load_System_Setting (void){
    //u8_REF_SetLevel
    if (DATAEE_ReadByte(0xF000) == 255) {
        u8_REF_SetLevel = 3;
    }else{
        u8_REF_SetLevel = DATAEE_ReadByte(0xF000);
    }
    //u8_SuperCool_Status
    if (DATAEE_ReadByte(0xF001) == 255) {
        u8_SuperCool_Status = OFF;
    }else{
        u8_SuperCool_Status = DATAEE_ReadByte(0xF001);
    }
    //u8_LOCK_Status
    if (DATAEE_ReadByte(0xF002) == 255) {
        u8_LOCK_Status = OFF;
    }else{
        u8_LOCK_Status = DATAEE_ReadByte(0xF002);
    }
    //EE_COMP_PrevStart
    if (DATAEE_ReadByte(0xF003) == 255) {
        EE_COMP_Flag = OFF;
    }else{
        EE_COMP_Flag = DATAEE_ReadByte(0xF003);
    }
    //EE_COMP_RUN_CountDown_Min
    if (DATAEE_ReadByte(0xF004) == 255) {
        EE_COMP_RUN_CountDown_Min = 60;
    }else{
        EE_COMP_RUN_CountDown_Min = DATAEE_ReadByte(0xF004);
    }
    //EE_COMP_TOTAL_RUN_Count_Hr
    if (DATAEE_ReadByte(0xF005) == 255) {
        EE_COMP_TOTAL_RUN_Count_Hr = 0;
    }else{
        EE_COMP_TOTAL_RUN_Count_Hr = DATAEE_ReadByte(0xF005);
    }
}

//EEPROM_SAVING_Functions
void Save_System_Setting (void){
    DATAEE_WriteByte(0xF000, u8_REF_SetLevel);
    DATAEE_WriteByte(0xF001, u8_SuperCool_Status);
    DATAEE_WriteByte(0xF002, u8_LOCK_Status);
    DATAEE_WriteByte(0xF003, EE_COMP_Flag);
    DATAEE_WriteByte(0xF004, EE_COMP_RUN_CountDown_Min);
    DATAEE_WriteByte(0xF005, EE_COMP_TOTAL_RUN_Count_Hr);
}

//User Define ISR 1s Function
void v_service_routine(void) {
    
    if (!u8_Tx_Status && u8_SuperCool_Status) {
        u8_Tx_Status = ON;
    }
    
    //Touch Key Function
    if (u8_3sec_Count < 3 && MTOUCH_Button_isPressed(K3)) {
        u8_3sec_Count++;
    } else if (!MTOUCH_Button_isPressed(K3)) {
        u8_3sec_Count = 0;
    }
    
    //Sleep Delay Countdown Routine
    if (u16_SLEEP_DelayCount) {
        u16_SLEEP_DelayCount--;
    }
    
    //Compressor Start Delay Countdown Routine
    if (u16_COMP_DelayCount) {
        u16_COMP_DelayCount--;
    }
    
    //1min CountDown Only When Compressor is ON
    if (u8_Timer_Countdown_Min && u8_COMP_Status) {
        u8_Timer_Countdown_Min--;
    }
    
    //Compressor Status
    switch (u8_COMP_Status){
        case 0 :           
            IND_COMP_SetLow();
            u8_COMP_Start = 0;
            break;
        case 1:
            IND_COMP_SetHigh();
            u8_COMP_Start = 1;
            break;
        case 2:
            IND_COMP_Toggle();
            u8_COMP_Start = 0;
            break;
    }

}


//User Define ISR 1ms Function
void v_seg_display(void) {
    //Touch_once_delay Function
    if (u8_TouchDelay && !MTOUCH_Button_isPressed(K1) && !MTOUCH_Button_isPressed(K2) && !MTOUCH_Button_isPressed(K3)) {
        u8_TouchDelay--;
    } 
    
    //Countdown delay for Dim & Sleep
    if (u16_SLEEP_DelayCount) {
        //Re-initialize Display
        LATB = 0xff;
        DIG1_SetLow();
        DIG2_SetLow();
        DIG3_SetLow();
        IND_LEV_KEY_SetLow();

        //specified display
        switch (u8_DIS_Channel) {
            case 0:
                DIG1_SetHigh();
                LATB = u8_seg[u8_DIG1];
                break;
            case 3:
                DIG2_SetHigh();
                LATB = u8_seg[u8_DIG2];
                break;
            case 6:
                DIG3_SetHigh();
                LATB = u8_seg[u8_DIG3];
                break;
            case 9:
                IND_LEV_KEY_SetHigh();
                LATB = u8_IND_LEV_KEY;   //Modified
                break;
        }
       
        u8_DIS_Channel++;
        
        if (u8_DIS_Channel >= 12) {
            u8_DIS_Channel = 0;
        }

    } else {
        LATB = 0x00;
        DIG1_SetLow();
        DIG2_SetLow();
        DIG3_SetLow();
        IND_LEV_KEY_SetLow();
    }
}




void v_uart_receive_data(void) {
    if(!PIR3bits.RCIF){
        return;
    }
    v_u8_RxData = EUSART_Read();
    if (v_u8_RxData == 0xAA) {
        u8_Index = 0;
        u8_Rx_DataBuff [u8_Index] = v_u8_RxData;
        u8_Index++;
    } else {
        u8_Rx_DataBuff [u8_Index] = v_u8_RxData;
        u8_Index++;
        if (u8_Index >= 9) {
            u8_Index = 0;
            v_u8_RxData = 0;
            u8_Tx_Status = ON;
        }
    }
}

void v_uart_send_data(void) {
    //Update Received Data
    u8_ErrorCodes    = u8_Rx_DataBuff[1];
    i8_F_Temperature = (int8_t) u8_Rx_DataBuff[2];
    i8_R_Temperature = (int8_t) u8_Rx_DataBuff[3];
    u8_Door_Open     = u8_Rx_DataBuff[4];

    //Send Data
    u8_Tx_DataBuff[0] = 0xAA;
    u8_Tx_DataBuff[1] = u8_COMP_Start;//Prob
    u8_Tx_DataBuff[2] = 0x00;
    u8_Tx_DataBuff[3] = 0x00;
    u8_Tx_DataBuff[4] = 0x00;
    u8_Tx_DataBuff[5] = 0x00;
    u8_Tx_DataBuff[6] = 0x00;
    u8_Tx_DataBuff[7] = 0x00;
    u8_Tx_DataBuff[8] = 0x00;
    u8_Tx_DataBuff[9] = 0x00;
    
    for (u8_Index = 0; u8_Index <=9 ; u8_Index++) {
        EUSART_Write(u8_Tx_DataBuff[u8_Index]);
    }
}




void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    TMR0_SetInterruptHandler(v_service_routine); //Timer0 as 1sec Interrupt Service Routine
    TMR1_SetInterruptHandler(v_seg_display);     //Timer1 as 1msec Interrupt Service Routine

    u8_DIS_Channel = 0;                          //Start From Display Channel 0
    u8_DIG1 = 10;                                //Display all @serial 10
    u8_DIG2 = 10;                                //Display all @serial 10
    u8_DIG3 = 10;                                //Display all @serial 10
    u8_IND_LEV_KEY = 0b00000000;                 //Display all
    
    
    u8_COMP_Status = OFF;
    u16_COMP_DelayCount = u16_COMP_StartDelay_Sec;
    
    u8_Timer_Countdown_Min = 0;
    u8_3sec_Count = 0;
    u8_TouchDelay = 0;
    i8_F_Temperature = 0;
    i8_R_Temperature = 0;
    
    Load_System_Setting();
    
    IND_COMP_SetLow();
    IND_DOOR_SetLow(); 
    u16_SLEEP_DelayCount = u16_SLEEP_StartDelay_Sec;
    
    for (int i = 0; i < 2000; i++) {
        __delay_ms(1);
    }
    EUSART_Initialize();
    u8_Tx_Status = ON;

    
    

    while (1) {

        //Uart_Data_Exchange
        if (u8_Tx_Status) {
            v_uart_send_data();
            u8_Tx_Status = OFF;
        } else {
            v_uart_receive_data();
        }

        //1min_Routine_Only When Compressor is ON
        if (!u8_Timer_Countdown_Min) {

            //For SuperCool Functions Only 
            if (u8_SuperCool_Status) {
                EE_COMP_RUN_CountDown_Min--;
                DATAEE_WriteByte(0xF004, EE_COMP_RUN_CountDown_Min); //Save in Memory

                //1Hr_Routine_During SuperCool Only
                if (!EE_COMP_RUN_CountDown_Min) {
                    EE_COMP_TOTAL_RUN_Count_Hr++;
                    DATAEE_WriteByte(0xF005, EE_COMP_TOTAL_RUN_Count_Hr); //Save in Memory

                    //Re-initialize for 60min = 1hr
                    EE_COMP_RUN_CountDown_Min = 60;
                }
            }

            //Re-initialize for 60s = 1min
            u8_Timer_Countdown_Min = 60;
        }

        
        
        //Compressor ON/OFF Function
        if (u8_SuperCool_Status) {
            //Compressor_Going_To_Start
            if (!u8_COMP_Status) {
                u8_COMP_Status = DELAY;
                u16_COMP_DelayCount = u16_COMP_StartDelay_Sec;
            }
            
            //Compressor_Starts
            else if (u8_COMP_Status==2 && !u16_COMP_DelayCount) {
                u8_COMP_Status = ON;
            }
            
            //Compressor_Stops_&_Exit from Super_Cool
            else if (EE_COMP_TOTAL_RUN_Count_Hr > u8_SuperCool_Hr) {
                u8_COMP_Status = OFF;

                //Re-Initialise Status
                u8_SuperCool_Status = OFF;
                EE_COMP_RUN_CountDown_Min = 60;
                EE_COMP_TOTAL_RUN_Count_Hr = 0;

                //Save to Memory
                Save_System_Setting();
            }
        } else {
            //Compressor_Going_To_Start
            if (i8_R_Temperature >= i8_COMP_ON_Temperature && !u8_COMP_Status) {
                u8_COMP_Status = DELAY;
                u16_COMP_DelayCount = u16_COMP_StartDelay_Sec;
            }
            
            //Compressor_Starts-----------
            else if (u8_COMP_Status==2 && !u16_COMP_DelayCount) {
                u8_COMP_Status = ON;
            }

            //Compressor_Stops
            else if (i8_R_Temperature <= i8_COMP_OFF_Temperature) {
                u8_COMP_Status = OFF;
            }

        }
        
        
        
        //Touch Functions 
        if (MTOUCH_Service_Mainloop()) {
            if (MTOUCH_Button_isPressed(K1) && !u8_TouchDelay) {
                u8_TouchDelay = 3;
                if (!u16_SLEEP_DelayCount) {
                    u16_SLEEP_DelayCount = u16_SLEEP_StartDelay_Sec;
                } else if (!u8_SuperCool_Status && !u8_LOCK_Status) {
                    u8_REF_SetLevel++;
                    if (u8_REF_SetLevel > 5) {
                        u8_REF_SetLevel = 1;
                    }
                } else if (u8_SuperCool_Status && !u8_LOCK_Status) {
                    //Super_Cool_Exit
                    u8_SuperCool_Status = OFF;
                    EE_COMP_RUN_CountDown_Min = 60;
                    EE_COMP_TOTAL_RUN_Count_Hr = 0;
                }
                Save_System_Setting();
            }
            if (MTOUCH_Button_isPressed(K2) && !u8_TouchDelay) {
                u8_TouchDelay = 3;
                if (!u16_SLEEP_DelayCount) {
                    u16_SLEEP_DelayCount = u16_SLEEP_StartDelay_Sec;
                } else if (!u8_LOCK_Status) {
                    //Super_Cool_Reset_&_Start
                    u8_SuperCool_Status = ON;
                    EE_COMP_RUN_CountDown_Min = 60;
                    EE_COMP_TOTAL_RUN_Count_Hr = 0;
                }
                Save_System_Setting();
            }
            if (MTOUCH_Button_isPressed(K3) && !u8_TouchDelay) {
                if (!u16_SLEEP_DelayCount) {
                    u16_SLEEP_DelayCount = u16_SLEEP_StartDelay_Sec;
                } 
            }
            if (MTOUCH_Button_isPressed(K3) && u8_3sec_Count == 3 && !u8_TouchDelay) {
                u8_3sec_Count = 0;
                u8_TouchDelay = 3;
                if (!u8_LOCK_Status) {
                    u8_LOCK_Status = ON;
                    Save_System_Setting();
                } else {
                    u8_LOCK_Status = OFF;
                    Save_System_Setting();
                }
            }
        }


       //Indicator & ICONs
        if (u8_SuperCool_Status) {
            //i8_COMP_OFF_Temperature = -28;
            if(u8_LOCK_Status){
               u8_IND_LEV_KEY = 0b00000110;  
            }else {
               u8_IND_LEV_KEY = 0b00000101;
            } 
        } else {
            if (u8_REF_SetLevel == 1) {
                i8_COMP_OFF_Temperature = -16;
                if (u8_LOCK_Status) {
                    u8_IND_LEV_KEY = 0b11110110;
                } else {
                    u8_IND_LEV_KEY = 0b11110011;
                } 
            } else if (u8_REF_SetLevel == 2) {
                i8_COMP_OFF_Temperature = -18;
                if (u8_LOCK_Status) {
                    u8_IND_LEV_KEY = 0b11101110;
                } else {
                    u8_IND_LEV_KEY = 0b11101011;
                }
            } else if (u8_REF_SetLevel == 3) {
                i8_COMP_OFF_Temperature = -20;
                if (u8_LOCK_Status) {
                    u8_IND_LEV_KEY = 0b11011110;
                } else {
                    u8_IND_LEV_KEY = 0b11011011;
                }
            } else if (u8_REF_SetLevel == 4) {
                i8_COMP_OFF_Temperature = -22;
                if (u8_LOCK_Status) {
                    u8_IND_LEV_KEY = 0b10111110;
                } else {
                    u8_IND_LEV_KEY = 0b10111011;
                }
            } else if (u8_REF_SetLevel == 5) {
                i8_COMP_OFF_Temperature = -24;
                if (u8_LOCK_Status) {
                    u8_IND_LEV_KEY = 0b01111110;
                } else {
                    u8_IND_LEV_KEY = 0b01111011;
                }
            }
        }






        

        
        

        //UART_Print
        //        if (!u8_Timer_Countdown_Min) {
        //            printf("\nu8_REF_SetLevel                = %d", u8_REF_SetLevel);
        //            printf("\nu8_SuperCool_Status            = %d", u8_SuperCool_Status);
        //            printf("\nu8_LOCK_Status                 = %d", u8_LOCK_Status);
        //            printf("\nu8_EE_COMP_RUN_CountDown_Min   = %d", u8_EE_COMP_RUN_CountDown_Min);
        //            printf("\nu8_EE_COMP_TOTAL_RUN_Count_Hr  = %d", u8_EE_COMP_TOTAL_RUN_Count_Hr);
        //            printf("\nGPIO u8_COMP_Status            = %d", u8_COMP_Status);
        //            printf("\nGPIO u8_IND_LEV_KEY            = %d", u8_IND_LEV_KEY);
        //        }

        
       
    }        
}
/**
 End of File
*/