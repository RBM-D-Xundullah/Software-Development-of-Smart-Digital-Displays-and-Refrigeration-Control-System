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
        Device            :  PIC16F18856
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

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA3 procedures
#define RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()             do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()           do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set power aliases
#define power_TRIS                 TRISAbits.TRISA6
#define power_LAT                  LATAbits.LATA6
#define power_PORT                 PORTAbits.RA6
#define power_WPU                  WPUAbits.WPUA6
#define power_OD                   ODCONAbits.ODCA6
#define power_ANS                  ANSELAbits.ANSA6
#define power_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define power_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define power_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define power_GetValue()           PORTAbits.RA6
#define power_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define power_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define power_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define power_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define power_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define power_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define power_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define power_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set IO_RB0 aliases
#define IO_RB0_TRIS                 TRISBbits.TRISB0
#define IO_RB0_LAT                  LATBbits.LATB0
#define IO_RB0_PORT                 PORTBbits.RB0
#define IO_RB0_WPU                  WPUBbits.WPUB0
#define IO_RB0_OD                   ODCONBbits.ODCB0
#define IO_RB0_ANS                  ANSELBbits.ANSB0
#define IO_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_RB0_GetValue()           PORTBbits.RB0
#define IO_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IO_RB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define IO_RB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define IO_RB0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define IO_RB0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define IO_RB0_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define IO_RB0_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set IO_RB1 aliases
#define IO_RB1_TRIS                 TRISBbits.TRISB1
#define IO_RB1_LAT                  LATBbits.LATB1
#define IO_RB1_PORT                 PORTBbits.RB1
#define IO_RB1_WPU                  WPUBbits.WPUB1
#define IO_RB1_OD                   ODCONBbits.ODCB1
#define IO_RB1_ANS                  ANSELBbits.ANSB1
#define IO_RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_RB1_GetValue()           PORTBbits.RB1
#define IO_RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define IO_RB1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define IO_RB1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define IO_RB1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define IO_RB1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define IO_RB1_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define IO_RB1_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set IO_RB2 aliases
#define IO_RB2_TRIS                 TRISBbits.TRISB2
#define IO_RB2_LAT                  LATBbits.LATB2
#define IO_RB2_PORT                 PORTBbits.RB2
#define IO_RB2_WPU                  WPUBbits.WPUB2
#define IO_RB2_OD                   ODCONBbits.ODCB2
#define IO_RB2_ANS                  ANSELBbits.ANSB2
#define IO_RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_RB2_GetValue()           PORTBbits.RB2
#define IO_RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IO_RB2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IO_RB2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IO_RB2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define IO_RB2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define IO_RB2_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define IO_RB2_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set IO_RB3 aliases
#define IO_RB3_TRIS                 TRISBbits.TRISB3
#define IO_RB3_LAT                  LATBbits.LATB3
#define IO_RB3_PORT                 PORTBbits.RB3
#define IO_RB3_WPU                  WPUBbits.WPUB3
#define IO_RB3_OD                   ODCONBbits.ODCB3
#define IO_RB3_ANS                  ANSELBbits.ANSB3
#define IO_RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IO_RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IO_RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IO_RB3_GetValue()           PORTBbits.RB3
#define IO_RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define IO_RB3_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define IO_RB3_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define IO_RB3_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define IO_RB3_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define IO_RB3_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define IO_RB3_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set IO_RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set IO_RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_RB6 aliases
#define IO_RB6_TRIS                 TRISBbits.TRISB6
#define IO_RB6_LAT                  LATBbits.LATB6
#define IO_RB6_PORT                 PORTBbits.RB6
#define IO_RB6_WPU                  WPUBbits.WPUB6
#define IO_RB6_OD                   ODCONBbits.ODCB6
#define IO_RB6_ANS                  ANSELBbits.ANSB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RB6_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define IO_RB6_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define IO_RB6_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define IO_RB6_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_OD                   ODCONBbits.ODCB7
#define IO_RB7_ANS                  ANSELBbits.ANSB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define IO_RB7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define IO_RB7_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set IND_DOOR aliases
#define IND_DOOR_TRIS                 TRISCbits.TRISC0
#define IND_DOOR_LAT                  LATCbits.LATC0
#define IND_DOOR_PORT                 PORTCbits.RC0
#define IND_DOOR_WPU                  WPUCbits.WPUC0
#define IND_DOOR_OD                   ODCONCbits.ODCC0
#define IND_DOOR_ANS                  ANSELCbits.ANSC0
#define IND_DOOR_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IND_DOOR_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IND_DOOR_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IND_DOOR_GetValue()           PORTCbits.RC0
#define IND_DOOR_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IND_DOOR_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IND_DOOR_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IND_DOOR_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IND_DOOR_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IND_DOOR_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define IND_DOOR_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define IND_DOOR_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set IND_COMP aliases
#define IND_COMP_TRIS                 TRISCbits.TRISC1
#define IND_COMP_LAT                  LATCbits.LATC1
#define IND_COMP_PORT                 PORTCbits.RC1
#define IND_COMP_WPU                  WPUCbits.WPUC1
#define IND_COMP_OD                   ODCONCbits.ODCC1
#define IND_COMP_ANS                  ANSELCbits.ANSC1
#define IND_COMP_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IND_COMP_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IND_COMP_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IND_COMP_GetValue()           PORTCbits.RC1
#define IND_COMP_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IND_COMP_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IND_COMP_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define IND_COMP_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define IND_COMP_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define IND_COMP_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define IND_COMP_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define IND_COMP_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set IND_LEV_KEY aliases
#define IND_LEV_KEY_TRIS                 TRISCbits.TRISC2
#define IND_LEV_KEY_LAT                  LATCbits.LATC2
#define IND_LEV_KEY_PORT                 PORTCbits.RC2
#define IND_LEV_KEY_WPU                  WPUCbits.WPUC2
#define IND_LEV_KEY_OD                   ODCONCbits.ODCC2
#define IND_LEV_KEY_ANS                  ANSELCbits.ANSC2
#define IND_LEV_KEY_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IND_LEV_KEY_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IND_LEV_KEY_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IND_LEV_KEY_GetValue()           PORTCbits.RC2
#define IND_LEV_KEY_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IND_LEV_KEY_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IND_LEV_KEY_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IND_LEV_KEY_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IND_LEV_KEY_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define IND_LEV_KEY_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define IND_LEV_KEY_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define IND_LEV_KEY_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set DIG3 aliases
#define DIG3_TRIS                 TRISCbits.TRISC3
#define DIG3_LAT                  LATCbits.LATC3
#define DIG3_PORT                 PORTCbits.RC3
#define DIG3_WPU                  WPUCbits.WPUC3
#define DIG3_OD                   ODCONCbits.ODCC3
#define DIG3_ANS                  ANSELCbits.ANSC3
#define DIG3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define DIG3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define DIG3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define DIG3_GetValue()           PORTCbits.RC3
#define DIG3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define DIG3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define DIG3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define DIG3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define DIG3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define DIG3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define DIG3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define DIG3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set DIG2 aliases
#define DIG2_TRIS                 TRISCbits.TRISC4
#define DIG2_LAT                  LATCbits.LATC4
#define DIG2_PORT                 PORTCbits.RC4
#define DIG2_WPU                  WPUCbits.WPUC4
#define DIG2_OD                   ODCONCbits.ODCC4
#define DIG2_ANS                  ANSELCbits.ANSC4
#define DIG2_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define DIG2_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define DIG2_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define DIG2_GetValue()           PORTCbits.RC4
#define DIG2_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define DIG2_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define DIG2_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define DIG2_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define DIG2_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define DIG2_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define DIG2_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define DIG2_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set DIG1 aliases
#define DIG1_TRIS                 TRISCbits.TRISC5
#define DIG1_LAT                  LATCbits.LATC5
#define DIG1_PORT                 PORTCbits.RC5
#define DIG1_WPU                  WPUCbits.WPUC5
#define DIG1_OD                   ODCONCbits.ODCC5
#define DIG1_ANS                  ANSELCbits.ANSC5
#define DIG1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define DIG1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define DIG1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define DIG1_GetValue()           PORTCbits.RC5
#define DIG1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define DIG1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define DIG1_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define DIG1_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define DIG1_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define DIG1_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define DIG1_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define DIG1_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

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