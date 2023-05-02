////////////////Frost_Electronic_Control_System//////////////////
/////////////////////Display_Board_Program///////////////////////
////////////////Programmed by Raihan Bin Mofidul/////////////////
///////////////////Modified Date: 19-May-2019////////////////////

#include "mcc_generated_files/mcc.h"

#define OFF 0
#define ON  1

//Refrigeration Parameters
#define SuperCool    0
#define SetLevel     1

//Compressor Parameters
#define Stop    0
#define Start   1
#define Delay   2


//Parameters which can be Adjusted by User
static const uint16_t u16_Sleep_StartDelay_Sec         = 30; //30sec
static const uint16_t u16_Comp_StartDleay_Sec          = 20; //180sec
static const uint8_t  u8_SuperCool_Hr                  = 8;  //48hr
static const int8_t   i8_Offset_F_Temp                 = 0;  //0
static const int8_t   i8_Offset_R_Temp                 = 0;  //0
static const int8_t   i8_Comp_ON_Temp                  = 4;  //4



//Seven Segment Display Array
static const uint8_t u8_Seg[20] = {
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


//Global Variables Used in this program
//For Seven Segment
uint8_t  u8_DIS_Ch, u8_DIG1, u8_DIG2, u8_DIG3, u8_IND_LEV_KEY;
//For CountDown & Delay
uint8_t  u8_TouchDelay, u8_3secCount, u8_1minCountDown;
uint16_t u16_500msCountDown, u16_Sleep_StartDelay_CountDown,u16_Comp_StartDleay_CountDown;
uint16_t u16_5minCountDown;
//Integer Variable
int8_t i8_Comp_OFF_Temp;
//Unsigned variable
uint8_t u8_Compressor_Status;

//EEPROM Variables
uint8_t  u8_MemoryIndex, EE_Refrigeration_Mode, EE_SetLevel, EE_Lock_Status;
uint8_t  EE_Compressor_Status, EE_SuperCool_Min_CountDown, EE_SuperCool_Hr_Count;

//Uart Variables
uint8_t u8_Index, u8_Tx_Status;
volatile uint8_t u8_RxData, u8_Rx_DataBuff[10], u8_Tx_DataBuff[10];
//Uart Data-Exchange Variable
uint8_t u8_Compressor_PIN, u8_ErrorCodes, u8_DoorStatus;
int8_t i8_F_Temp, i8_R_Temp;


//EEPROM_LOAD_Function 0xF000 TO 0xF0FF
void v_load_system_setting (void){
    //EE_Refrigeration_Mode        @0xF000
    if (DATAEE_ReadByte(0xF000) == 255) {
        EE_Refrigeration_Mode      = SetLevel;
    } else {
        EE_Refrigeration_Mode      = DATAEE_ReadByte(0xF000);
    }
    //EE_SetLevel                  @0xF001
    if (DATAEE_ReadByte(0xF001) == 255) {
        EE_SetLevel                = 3;
    } else {
        EE_SetLevel                = DATAEE_ReadByte(0xF001);
    }
    //EE_Lock_Status               @0xF002
    if (DATAEE_ReadByte(0xF002) == 255) {
        EE_Lock_Status             = OFF;
    } else {
        EE_Lock_Status             = DATAEE_ReadByte(0xF002);
    }
    //EE_Compressor_Status         @0xF003
    if (DATAEE_ReadByte(0xF003) == 255) {
        EE_Compressor_Status       = OFF;
    } else {
        EE_Compressor_Status       = DATAEE_ReadByte(0xF003);
    }
    //EE_SuperCool_Min_CountDown   @0xF004
    if (DATAEE_ReadByte(0xF004) == 255) {
        EE_SuperCool_Min_CountDown = 60;
    } else {
        EE_SuperCool_Min_CountDown = DATAEE_ReadByte(0xF004);
    }
    //EE_SuperCool_Hr_Count        @0xF005
    if (DATAEE_ReadByte(0xF005) == 255) {
        EE_SuperCool_Hr_Count      = 0;
    } else {
        EE_SuperCool_Hr_Count      = DATAEE_ReadByte(0xF005);
    }
}

void v_save_system_setting(void) {
    switch (u8_MemoryIndex) {
        case 0:
            DATAEE_WriteByte(0xF000, EE_Refrigeration_Mode);
            break;
        case 1:
            DATAEE_WriteByte(0xF001, EE_SetLevel);
            break;
        case 2:
            DATAEE_WriteByte(0xF002, EE_Lock_Status);
            break;
        case 3:
            DATAEE_WriteByte(0xF003, EE_Compressor_Status);
            break;
        case 4:
            DATAEE_WriteByte(0xF004, EE_SuperCool_Min_CountDown);
            break;
        case 5:
            DATAEE_WriteByte(0xF005, EE_SuperCool_Hr_Count);
            break;
    }
}


void v_1s_service_routine(void) {
    //Touch 3sec for ChildLock Button
    if (u8_3secCount < 3 && MTOUCH_Button_isPressed(B_CHILD_LOCK)) {
        u8_3secCount++;
    } 
    //Touch 3sec is reset
    if (!MTOUCH_Button_isPressed(B_CHILD_LOCK)){
        u8_3secCount = 0;
    }
    //Sleep Delay CountDown
    if (u16_Sleep_StartDelay_CountDown) {
        u16_Sleep_StartDelay_CountDown--;
    }
    //One Minute Routine
    if (u8_1minCountDown) {
        u8_1minCountDown--;
    }
    //Five Minute Routine
    if (u16_5minCountDown){
        u16_5minCountDown--;
    }
    //Compressor Start Delay CountDown only when u8_Compressor_Status = Delay
    if (u16_Comp_StartDleay_CountDown && u8_Compressor_Status == Delay) {
        u16_Comp_StartDleay_CountDown--;
        IND_COMP_Toggle();
    } 
}


void v_1ms_service_routine(void) {
    //Touch Once //If no buttons is touched then delay will be zero
    if (u8_TouchDelay && !MTOUCH_Button_isPressed(B_SET_LEV) && !MTOUCH_Button_isPressed(B_SUPER_COOL) && !MTOUCH_Button_isPressed(B_CHILD_LOCK)) {
        u8_TouchDelay -- ;
    }
    //Memory Write One by One at 100ms interval
    if (u16_500msCountDown){
       u16_500msCountDown--;
    }
    //CountDown for activating Display Dim & Sleep Feature
    if (u16_Sleep_StartDelay_CountDown) {
        //Re-initialize Display
        LATB = 0xff;
        DIG1_SetLow();
        DIG2_SetLow();
        DIG3_SetLow();
        IND_LEV_KEY_SetLow();
        //Switch DIG one by one
        switch (u8_DIS_Ch) {
            case 0:
                DIG1_SetHigh();
                LATB = u8_Seg[u8_DIG1];
                break;
            case 3:
                DIG2_SetHigh();
                LATB = u8_Seg[u8_DIG2];
                break;
            case 6:
                DIG3_SetHigh();
                LATB = u8_Seg[u8_DIG3];
                break;
            case 9:
                IND_LEV_KEY_SetHigh();
                LATB = u8_IND_LEV_KEY;
                break;
        }
        u8_DIS_Ch++;
        if (u8_DIS_Ch >= 12) {
            u8_DIS_Ch = 0;
        }
    } else {
        //OFF All Display
        LATB = 0x00;
        DIG1_SetLow();
        DIG2_SetLow();
        DIG3_SetLow();
        IND_LEV_KEY_SetLow();
    }
}


void v_uart_receive(void) {
    if (PIR3bits.RCIF == 0) {
        return;
    }
    u8_RxData = EUSART_Read();
    if (u8_RxData == 0xAA) {
        u8_Index = 0;
        u8_Rx_DataBuff[u8_Index] = u8_RxData;
        u8_Index++;
    } else {
        u8_Rx_DataBuff[u8_Index] = u8_RxData;
        u8_Index++;
        if (u8_Index >= 9) {
            //Update Receive Data
            u8_ErrorCodes     = u8_Rx_DataBuff[1];
            i8_F_Temp         = (int8_t) u8_Rx_DataBuff[2];
            i8_R_Temp         = (int8_t) u8_Rx_DataBuff[3];
            u8_DoorStatus     = u8_Rx_DataBuff[4];
            //Re-initialize
            u8_Index = 0;
            u8_RxData = 0;
            u8_Tx_Status = ON;
        }
    }
}

void v_uart_send (void) {
    //Send Data
    u8_Tx_DataBuff[0] = 0xAA;
    u8_Tx_DataBuff[1] = u8_Compressor_PIN;
    u8_Tx_DataBuff[2] = 0x00;
    u8_Tx_DataBuff[3] = 0x00;
    u8_Tx_DataBuff[4] = 0x00;
    u8_Tx_DataBuff[5] = 0x00;
    u8_Tx_DataBuff[6] = 0x00;
    u8_Tx_DataBuff[7] = 0x00;
    u8_Tx_DataBuff[8] = 0x00;
    u8_Tx_DataBuff[9] = 0x00;
    
    //Sending by Loop
    for (u8_Index = 0; u8_Index <= 9; u8_Index++) {
        EUSART_Write(u8_Tx_DataBuff[u8_Index]);
    }
}


void main(void)
{
    SYSTEM_Initialize();                                  // initialize the device except Euart
    INTERRUPT_GlobalInterruptEnable();                    // Enable the Global Interrupts 
    INTERRUPT_PeripheralInterruptEnable();                // Enable the Peripheral Interrupts
    TMR1_SetInterruptHandler(v_1ms_service_routine);      // 1milli second ISR
    TMR0_SetInterruptHandler(v_1s_service_routine);       // 1second ISR
    
    //Load EEROM Parameters
    v_load_system_setting();
   
    //Parameters Initialize
    u8_MemoryIndex       = 0;
    u8_DIS_Ch            = 0;                             // Start From Channel 0
    u8_DIG1              = 10;                            // Display All
    u8_DIG2              = 10;                            // Display All
    u8_DIG3              = 10;                            // Display All
    u8_IND_LEV_KEY       = 0b000000000;                   // Display All
    u8_Tx_Status         = ON;
//    u8_Index             = 0;
//    u8_RxData            = 0;
//    u8_Rx_DataBuff[10]   = {0,0,0,0,0,0,0,0,0,0,};
//    u8_Tx_DataBuff[10]   = {0,0,0,0,0,0,0,0,0,0,};
    u8_Compressor_Status = Stop;
    u8_Compressor_PIN    = OFF;
    u8_ErrorCodes        = 0;
    u8_DoorStatus        = 0;
    i8_Comp_OFF_Temp     = 0;
    i8_F_Temp            = 0;
    i8_R_Temp            = 0;
    u8_TouchDelay        = 0;
    u8_3secCount         = 0;
    u16_500msCountDown   = 500;
    u8_1minCountDown     = 60;
    u16_5minCountDown    = 300;//Run at start
    u16_Sleep_StartDelay_CountDown = u16_Sleep_StartDelay_Sec;
    u16_Comp_StartDleay_CountDown  = u16_Comp_StartDleay_Sec;
    
    
    //2sec Delay For UART
    for (int16_t i = 0; i < 2000; i++) {
        __delay_ms(1);
    }


    while (1) {
        //UART_DATA_EXCHANGE////////////////////////////////////////////////////////////////////
        if (u8_Tx_Status) {
            v_uart_send();
            u8_Tx_Status = OFF;
        } else {
            v_uart_receive();
        }
        //UART_DATA_EXCHANGE////////////////////////////////////////////////////////////////////
        
        //EE_ROM_Schedule_Update////////////////////////////////////////////////////////////////
        if (!u16_500msCountDown) {
            v_save_system_setting();
            if (u8_MemoryIndex<=5){
               u8_MemoryIndex++;
            }
            
            printf("\n\ru8_MemoryIndex = %d", u8_MemoryIndex);
            
            //Re-initialize 500x1msec= 500msec
            u16_500msCountDown = 500;
        }
        
        
        if (!u16_5minCountDown) {
            
            //Re-initialize 300x1s= 300s; 300/60 min = 5min
            u16_5minCountDown = 300;
        }
        //EE_ROM_Schedule_Update////////////////////////////////////////////////////////////////
        
        //Touch Function////////////////////////////////////////////////////////////////////////
        if (MTOUCH_Service_Mainloop()) {
            //IF Set_Level Button is Touched Once
            if (MTOUCH_Button_isPressed(B_SET_LEV) && !u8_TouchDelay) {
                u8_TouchDelay = 3;
                if (!u16_Sleep_StartDelay_CountDown) {
                    //If Device was in Sleep, Just wake UP
                    u16_Sleep_StartDelay_CountDown = u16_Sleep_StartDelay_Sec;
                } else if (EE_Refrigeration_Mode==SetLevel && !EE_Lock_Status) {
                    u16_Sleep_StartDelay_CountDown = u16_Sleep_StartDelay_Sec;
                    EE_SetLevel++;
                    if (EE_SetLevel > 5) {
                        EE_SetLevel = 1;
                    }
                    u8_MemoryIndex = 0;                 //Save all Settings to Memory
                } else if (EE_Refrigeration_Mode==SuperCool && !EE_Lock_Status) {
                    u16_Sleep_StartDelay_CountDown = u16_Sleep_StartDelay_Sec;
                    EE_Refrigeration_Mode = SetLevel;
                    EE_SuperCool_Min_CountDown = 60;
                    EE_SuperCool_Hr_Count = 0;
                    u8_MemoryIndex = 0;                 //Save all Settings to Memory
                }
            }
            //IF Super_Cool Button is Touched Once
            if (MTOUCH_Button_isPressed(B_SUPER_COOL) && !u8_TouchDelay) {
                u8_TouchDelay = 3;
                if (!u16_Sleep_StartDelay_CountDown) {
                    //If Device was in Sleep, Just wake UP
                    u16_Sleep_StartDelay_CountDown = u16_Sleep_StartDelay_Sec;
                } else if (EE_Refrigeration_Mode==SetLevel && !EE_Lock_Status) {
                    u16_Sleep_StartDelay_CountDown = u16_Sleep_StartDelay_Sec;
                    EE_Refrigeration_Mode = SuperCool;
                    EE_SuperCool_Min_CountDown = 60;
                    EE_SuperCool_Hr_Count = 0;
                    u8_MemoryIndex = 0;                 //Save all Settings to Memory
                } else if (EE_Refrigeration_Mode==SuperCool && !EE_Lock_Status) {
                    u16_Sleep_StartDelay_CountDown = u16_Sleep_StartDelay_Sec;
                    EE_Refrigeration_Mode = SetLevel;
                    EE_SuperCool_Min_CountDown = 60;
                    EE_SuperCool_Hr_Count = 0;
                    u8_MemoryIndex = 0;                 //Save all Settings to Memory
                }
            }
            //IF ChildLock Button is Touched Once
            if (MTOUCH_Button_isPressed(B_CHILD_LOCK) && !u8_TouchDelay) {
                u8_TouchDelay = 3;
                u16_Sleep_StartDelay_CountDown = u16_Sleep_StartDelay_Sec;
                //IF ChildLock Button is Touched for 3sec
                if (u8_3secCount == 3) {
                    u8_3secCount = 0;
                    if (EE_Lock_Status==OFF) {
                        EE_Lock_Status = ON;
                        DATAEE_WriteByte(0xF002, EE_Lock_Status);
                    } else {
                        EE_Lock_Status = OFF;
                        DATAEE_WriteByte(0xF002, EE_Lock_Status);
                    }
                }
            }
        }
        //Touch Function////////////////////////////////////////////////////////////////////////


        //INDICATIONS & Set Comp OFF Temp///////////////////////////////////////////////////////
        switch (EE_Refrigeration_Mode) {
            case SuperCool:
                if (EE_Lock_Status) u8_IND_LEV_KEY = 0b00000110;
                else u8_IND_LEV_KEY = 0b00000101;
                //Main_Function
                if (!u8_1minCountDown) {
                    EE_SuperCool_Min_CountDown--;
                    DATAEE_WriteByte(0xF004, EE_SuperCool_Min_CountDown);//Save to Memory after 1min                
                    //Re-initialize 60x1s= 60s
                    u8_1minCountDown = 60;
                }
                if (!EE_SuperCool_Min_CountDown) {
                    EE_SuperCool_Hr_Count++;
                    DATAEE_WriteByte(0xF005, EE_SuperCool_Hr_Count);     //Save to Memory after 1hr
                    //Re-initialize 60x1min= 1hr
                    EE_SuperCool_Min_CountDown = 60;
                }
                if (EE_SuperCool_Hr_Count < u8_SuperCool_Hr) {
                    EE_Compressor_Status = ON;
                }
                if (EE_SuperCool_Hr_Count >= u8_SuperCool_Hr) {
                    EE_Compressor_Status = OFF;
                    EE_Refrigeration_Mode = SetLevel;
                    EE_SuperCool_Min_CountDown = 60;
                    EE_SuperCool_Hr_Count = 0;
                    u8_MemoryIndex = 0;                                 //Save all Settings to Memory
                }
                break;
            case SetLevel:
                switch (EE_SetLevel) {
                    case 1:
                        i8_Comp_OFF_Temp = -16;
                        if (EE_Lock_Status) u8_IND_LEV_KEY = 0b11110110;
                        else u8_IND_LEV_KEY = 0b11110011;
                        break;
                    case 2:
                        i8_Comp_OFF_Temp = -18;
                        if (EE_Lock_Status) u8_IND_LEV_KEY = 0b11101110;
                        else u8_IND_LEV_KEY = 0b11101011;
                        break;
                    case 3:
                        i8_Comp_OFF_Temp = -20;
                        if (EE_Lock_Status) u8_IND_LEV_KEY = 0b11011110;
                        else u8_IND_LEV_KEY = 0b11011011;
                        break;
                    case 4:
                        i8_Comp_OFF_Temp = -22;
                        if (EE_Lock_Status) u8_IND_LEV_KEY = 0b10111110;
                        else u8_IND_LEV_KEY = 0b10111011;
                        break;
                    case 5:
                        i8_Comp_OFF_Temp = -24;
                        if (EE_Lock_Status) u8_IND_LEV_KEY = 0b01111110;
                        else u8_IND_LEV_KEY = 0b01111011;
                        break;
                }
                //Main_Function
                //if Cabinet Temp >=4 or EE_Com was ON
                if (i8_R_Temp >= i8_Comp_ON_Temp || EE_Compressor_Status == ON) {
                    EE_Compressor_Status = ON;
                } 
                //if Cabinet Temp <=-18
                if (i8_R_Temp <= i8_Comp_OFF_Temp) {
                    EE_Compressor_Status = OFF;
                }
                break;
        }
        //INDICATIONS & Set Comp OFF Temp///////////////////////////////////////////////////////

        //Compressor ON/OFF Function Details///////////////////////////////////////////////////
        switch (EE_Compressor_Status) {
            case ON:
                //Delay Enable after power up or change setting
                if (u8_Compressor_Status == Stop){
                    u8_Compressor_Status = Delay;
                    u16_Comp_StartDleay_CountDown = u16_Comp_StartDleay_Sec;
                    DATAEE_WriteByte(0xF003, EE_Compressor_Status);//Save in Memory
                }
                //Compressor is started after delay
                if (u8_Compressor_PIN == OFF && u16_Comp_StartDleay_CountDown == 0) {
                    u8_Compressor_Status = Start;
                    u8_Compressor_PIN = ON;
                    IND_COMP_SetHigh();
                }
                break;
            case OFF:
                if (u8_Compressor_Status){
                    u8_Compressor_Status = Stop;
                    u8_Compressor_PIN    = OFF;
                    IND_COMP_SetLow();
                    DATAEE_WriteByte(0xF003, EE_Compressor_Status);//Save in Memory after Compressor is Turned OFF
                }
                break; 
        }
        //Compressor ON/OFF Function Details///////////////////////////////////////////////////
        
    }
}