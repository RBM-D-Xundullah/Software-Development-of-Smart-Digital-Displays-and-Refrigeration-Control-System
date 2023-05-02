/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F15344
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set FD aliases
#define FD_TRIS                 TRISAbits.TRISA0
#define FD_LAT                  LATAbits.LATA0
#define FD_PORT                 PORTAbits.RA0
#define FD_WPU                  WPUAbits.WPUA0
#define FD_OD                   ODCONAbits.ODCA0
#define FD_ANS                  ANSELAbits.ANSA0
#define FD_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define FD_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define FD_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define FD_GetValue()           PORTAbits.RA0
#define FD_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define FD_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define FD_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define FD_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define FD_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define FD_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define FD_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define FD_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RD aliases
#define RD_TRIS                 TRISAbits.TRISA1
#define RD_LAT                  LATAbits.LATA1
#define RD_PORT                 PORTAbits.RA1
#define RD_WPU                  WPUAbits.WPUA1
#define RD_OD                   ODCONAbits.ODCA1
#define RD_ANS                  ANSELAbits.ANSA1
#define RD_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RD_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RD_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RD_GetValue()           PORTAbits.RA1
#define RD_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RD_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RD_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define RD_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define RD_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define RD_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define RD_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define RD_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set DS aliases
#define DS_TRIS                 TRISAbits.TRISA2
#define DS_LAT                  LATAbits.LATA2
#define DS_PORT                 PORTAbits.RA2
#define DS_WPU                  WPUAbits.WPUA2
#define DS_OD                   ODCONAbits.ODCA2
#define DS_ANS                  ANSELAbits.ANSA2
#define DS_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define DS_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define DS_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define DS_GetValue()           PORTAbits.RA2
#define DS_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define DS_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define DS_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define DS_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define DS_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define DS_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define DS_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define DS_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RS aliases
#define RS_TRIS                 TRISAbits.TRISA4
#define RS_LAT                  LATAbits.LATA4
#define RS_PORT                 PORTAbits.RA4
#define RS_WPU                  WPUAbits.WPUA4
#define RS_OD                   ODCONAbits.ODCA4
#define RS_ANS                  ANSELAbits.ANSA4
#define RS_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RS_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RS_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RS_GetValue()           PORTAbits.RA4
#define RS_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RS_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define RS_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define RS_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define RS_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define RS_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define RS_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set FS aliases
#define FS_TRIS                 TRISAbits.TRISA5
#define FS_LAT                  LATAbits.LATA5
#define FS_PORT                 PORTAbits.RA5
#define FS_WPU                  WPUAbits.WPUA5
#define FS_OD                   ODCONAbits.ODCA5
#define FS_ANS                  ANSELAbits.ANSA5
#define FS_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define FS_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define FS_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define FS_GetValue()           PORTAbits.RA5
#define FS_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define FS_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define FS_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define FS_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define FS_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define FS_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define FS_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define FS_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set ION aliases
#define ION_TRIS                 TRISBbits.TRISB4
#define ION_LAT                  LATBbits.LATB4
#define ION_PORT                 PORTBbits.RB4
#define ION_WPU                  WPUBbits.WPUB4
#define ION_OD                   ODCONBbits.ODCB4
#define ION_ANS                  ANSELBbits.ANSB4
#define ION_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define ION_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define ION_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define ION_GetValue()           PORTBbits.RB4
#define ION_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define ION_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define ION_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define ION_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define ION_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define ION_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define ION_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define ION_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set COMP aliases
#define COMP_TRIS                 TRISBbits.TRISB7
#define COMP_LAT                  LATBbits.LATB7
#define COMP_PORT                 PORTBbits.RB7
#define COMP_WPU                  WPUBbits.WPUB7
#define COMP_OD                   ODCONBbits.ODCB7
#define COMP_ANS                  ANSELBbits.ANSB7
#define COMP_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define COMP_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define COMP_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define COMP_GetValue()           PORTBbits.RB7
#define COMP_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define COMP_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define COMP_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define COMP_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define COMP_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define COMP_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define COMP_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define COMP_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set FL aliases
#define FL_TRIS                 TRISCbits.TRISC0
#define FL_LAT                  LATCbits.LATC0
#define FL_PORT                 PORTCbits.RC0
#define FL_WPU                  WPUCbits.WPUC0
#define FL_OD                   ODCONCbits.ODCC0
#define FL_ANS                  ANSELCbits.ANSC0
#define FL_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define FL_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define FL_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define FL_GetValue()           PORTCbits.RC0
#define FL_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define FL_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define FL_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define FL_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define FL_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define FL_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define FL_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define FL_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RL aliases
#define RL_TRIS                 TRISCbits.TRISC1
#define RL_LAT                  LATCbits.LATC1
#define RL_PORT                 PORTCbits.RC1
#define RL_WPU                  WPUCbits.WPUC1
#define RL_OD                   ODCONCbits.ODCC1
#define RL_ANS                  ANSELCbits.ANSC1
#define RL_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RL_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RL_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RL_GetValue()           PORTCbits.RC1
#define RL_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RL_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RL_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define RL_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define RL_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define RL_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define RL_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define RL_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set UV aliases
#define UV_TRIS                 TRISCbits.TRISC2
#define UV_LAT                  LATCbits.LATC2
#define UV_PORT                 PORTCbits.RC2
#define UV_WPU                  WPUCbits.WPUC2
#define UV_OD                   ODCONCbits.ODCC2
#define UV_ANS                  ANSELCbits.ANSC2
#define UV_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define UV_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define UV_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define UV_GetValue()           PORTCbits.RC2
#define UV_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define UV_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define UV_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define UV_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define UV_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define UV_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define UV_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define UV_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set Eva_Fan aliases
#define Eva_Fan_TRIS                 TRISCbits.TRISC6
#define Eva_Fan_LAT                  LATCbits.LATC6
#define Eva_Fan_PORT                 PORTCbits.RC6
#define Eva_Fan_WPU                  WPUCbits.WPUC6
#define Eva_Fan_OD                   ODCONCbits.ODCC6
#define Eva_Fan_ANS                  ANSELCbits.ANSC6
#define Eva_Fan_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define Eva_Fan_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define Eva_Fan_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define Eva_Fan_GetValue()           PORTCbits.RC6
#define Eva_Fan_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define Eva_Fan_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define Eva_Fan_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define Eva_Fan_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define Eva_Fan_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define Eva_Fan_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define Eva_Fan_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define Eva_Fan_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set Heater aliases
#define Heater_TRIS                 TRISCbits.TRISC7
#define Heater_LAT                  LATCbits.LATC7
#define Heater_PORT                 PORTCbits.RC7
#define Heater_WPU                  WPUCbits.WPUC7
#define Heater_OD                   ODCONCbits.ODCC7
#define Heater_ANS                  ANSELCbits.ANSC7
#define Heater_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define Heater_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define Heater_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define Heater_GetValue()           PORTCbits.RC7
#define Heater_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define Heater_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define Heater_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define Heater_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define Heater_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define Heater_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define Heater_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define Heater_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/