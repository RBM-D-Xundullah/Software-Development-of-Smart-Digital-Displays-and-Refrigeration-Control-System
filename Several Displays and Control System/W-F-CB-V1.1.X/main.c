#include "mcc_generated_files/mcc.h"

#define ON      1
#define OFF     0
#define DELAY   2


//Uart Variables
uint8_t u8_Index, u8_Tx_Status;
volatile uint8_t  u8_RxData, u8_Rx_DataBuff[10], u8_Tx_DataBuff[10];
uint8_t u8_Compressor_PIN;
uint8_t u8_ErrorCodes, u8_Door_Open;
int8_t i8_F_Temperature, i8_R_Temperature;



void v_uart_receive (void) {
    if(PIR3bits.RC1IF == 0){
        return;
    }
    u8_RxData = EUSART1_Read();
    if (u8_RxData == 0xAA) {
        u8_Index = 0;
        u8_Rx_DataBuff [u8_Index] = u8_RxData;
        u8_Index++;
    } else {
        u8_Rx_DataBuff [u8_Index] = u8_RxData;
        u8_Index++;
        if (u8_Index >= 9) {
            //Update Received Data
            u8_Compressor_PIN    = u8_Rx_DataBuff[1];
            
            //Re-Initialize
            u8_Index = 0;
            u8_RxData = 0;
            u8_Tx_Status = ON;
        }
    }
}

void v_uart_send(void) {
    //Send Data
    u8_Tx_DataBuff[0] = 0xAA;
    u8_Tx_DataBuff[1] = u8_ErrorCodes;
    u8_Tx_DataBuff[2] = (uint8_t)i8_F_Temperature;
    u8_Tx_DataBuff[3] = (uint8_t)i8_R_Temperature;
    u8_Tx_DataBuff[4] = u8_Door_Open;
    u8_Tx_DataBuff[5] = 0x00;
    u8_Tx_DataBuff[6] = 0x00;
    u8_Tx_DataBuff[7] = 0x00;
    u8_Tx_DataBuff[8] = 0x00;
    u8_Tx_DataBuff[9] = 0x00;
    
    //Sending by loop
    for (u8_Index = 0; u8_Index <= 9; u8_Index++) {
        EUSART1_Write(u8_Tx_DataBuff[u8_Index]);
    }
}



void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();


    u8_Tx_Status = ON;
    
    u8_ErrorCodes = 0x00;
    i8_F_Temperature = -25;
    i8_R_Temperature = 0;
    u8_Door_Open = ON;


    while (1) {
        //Uart_Data_Exchange
        if (u8_Tx_Status) {
            v_uart_send();
            u8_Tx_Status = OFF;
        } else {
            v_uart_receive();
        }

        if (u8_Compressor_PIN) {
            COMP_SetHigh();
        } else {
            COMP_SetLow();
        }
        
    }
}
