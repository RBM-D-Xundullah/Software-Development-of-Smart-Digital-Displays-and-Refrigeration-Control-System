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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F15344
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
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

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set O_ECO aliases
#define O_ECO_TRIS                 TRISAbits.TRISA0
#define O_ECO_LAT                  LATAbits.LATA0
#define O_ECO_PORT                 PORTAbits.RA0
#define O_ECO_WPU                  WPUAbits.WPUA0
#define O_ECO_OD                   ODCONAbits.ODCA0
#define O_ECO_ANS                  ANSELAbits.ANSA0
#define O_ECO_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define O_ECO_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define O_ECO_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define O_ECO_GetValue()           PORTAbits.RA0
#define O_ECO_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define O_ECO_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define O_ECO_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define O_ECO_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define O_ECO_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define O_ECO_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define O_ECO_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define O_ECO_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set O_DIG22 aliases
#define O_DIG22_TRIS                 TRISAbits.TRISA1
#define O_DIG22_LAT                  LATAbits.LATA1
#define O_DIG22_PORT                 PORTAbits.RA1
#define O_DIG22_WPU                  WPUAbits.WPUA1
#define O_DIG22_OD                   ODCONAbits.ODCA1
#define O_DIG22_ANS                  ANSELAbits.ANSA1
#define O_DIG22_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define O_DIG22_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define O_DIG22_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define O_DIG22_GetValue()           PORTAbits.RA1
#define O_DIG22_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define O_DIG22_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define O_DIG22_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define O_DIG22_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define O_DIG22_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define O_DIG22_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define O_DIG22_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define O_DIG22_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set A_RS aliases
#define A_RS_TRIS                 TRISAbits.TRISA2
#define A_RS_LAT                  LATAbits.LATA2
#define A_RS_PORT                 PORTAbits.RA2
#define A_RS_WPU                  WPUAbits.WPUA2
#define A_RS_OD                   ODCONAbits.ODCA2
#define A_RS_ANS                  ANSELAbits.ANSA2
#define A_RS_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define A_RS_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define A_RS_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define A_RS_GetValue()           PORTAbits.RA2
#define A_RS_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define A_RS_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define A_RS_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define A_RS_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define A_RS_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define A_RS_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define A_RS_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define A_RS_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set A_FS aliases
#define A_FS_TRIS                 TRISAbits.TRISA4
#define A_FS_LAT                  LATAbits.LATA4
#define A_FS_PORT                 PORTAbits.RA4
#define A_FS_WPU                  WPUAbits.WPUA4
#define A_FS_OD                   ODCONAbits.ODCA4
#define A_FS_ANS                  ANSELAbits.ANSA4
#define A_FS_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define A_FS_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define A_FS_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define A_FS_GetValue()           PORTAbits.RA4
#define A_FS_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define A_FS_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define A_FS_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define A_FS_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define A_FS_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define A_FS_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define A_FS_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define A_FS_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set O_DIG21 aliases
#define O_DIG21_TRIS                 TRISBbits.TRISB4
#define O_DIG21_LAT                  LATBbits.LATB4
#define O_DIG21_PORT                 PORTBbits.RB4
#define O_DIG21_WPU                  WPUBbits.WPUB4
#define O_DIG21_OD                   ODCONBbits.ODCB4
#define O_DIG21_ANS                  ANSELBbits.ANSB4
#define O_DIG21_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define O_DIG21_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define O_DIG21_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define O_DIG21_GetValue()           PORTBbits.RB4
#define O_DIG21_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define O_DIG21_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define O_DIG21_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define O_DIG21_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define O_DIG21_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define O_DIG21_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define O_DIG21_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define O_DIG21_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set O_DIG13 aliases
#define O_DIG13_TRIS                 TRISBbits.TRISB5
#define O_DIG13_LAT                  LATBbits.LATB5
#define O_DIG13_PORT                 PORTBbits.RB5
#define O_DIG13_WPU                  WPUBbits.WPUB5
#define O_DIG13_OD                   ODCONBbits.ODCB5
#define O_DIG13_ANS                  ANSELBbits.ANSB5
#define O_DIG13_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define O_DIG13_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define O_DIG13_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define O_DIG13_GetValue()           PORTBbits.RB5
#define O_DIG13_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define O_DIG13_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define O_DIG13_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define O_DIG13_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define O_DIG13_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define O_DIG13_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define O_DIG13_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define O_DIG13_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set O_DIG12 aliases
#define O_DIG12_TRIS                 TRISBbits.TRISB6
#define O_DIG12_LAT                  LATBbits.LATB6
#define O_DIG12_PORT                 PORTBbits.RB6
#define O_DIG12_WPU                  WPUBbits.WPUB6
#define O_DIG12_OD                   ODCONBbits.ODCB6
#define O_DIG12_ANS                  ANSELBbits.ANSB6
#define O_DIG12_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define O_DIG12_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define O_DIG12_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define O_DIG12_GetValue()           PORTBbits.RB6
#define O_DIG12_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define O_DIG12_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define O_DIG12_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define O_DIG12_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define O_DIG12_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define O_DIG12_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define O_DIG12_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define O_DIG12_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set O_DIG11 aliases
#define O_DIG11_TRIS                 TRISBbits.TRISB7
#define O_DIG11_LAT                  LATBbits.LATB7
#define O_DIG11_PORT                 PORTBbits.RB7
#define O_DIG11_WPU                  WPUBbits.WPUB7
#define O_DIG11_OD                   ODCONBbits.ODCB7
#define O_DIG11_ANS                  ANSELBbits.ANSB7
#define O_DIG11_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define O_DIG11_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define O_DIG11_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define O_DIG11_GetValue()           PORTBbits.RB7
#define O_DIG11_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define O_DIG11_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define O_DIG11_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define O_DIG11_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define O_DIG11_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define O_DIG11_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define O_DIG11_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define O_DIG11_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set O_A aliases
#define O_A_TRIS                 TRISCbits.TRISC0
#define O_A_LAT                  LATCbits.LATC0
#define O_A_PORT                 PORTCbits.RC0
#define O_A_WPU                  WPUCbits.WPUC0
#define O_A_OD                   ODCONCbits.ODCC0
#define O_A_ANS                  ANSELCbits.ANSC0
#define O_A_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define O_A_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define O_A_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define O_A_GetValue()           PORTCbits.RC0
#define O_A_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define O_A_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define O_A_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define O_A_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define O_A_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define O_A_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define O_A_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define O_A_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set O_B aliases
#define O_B_TRIS                 TRISCbits.TRISC1
#define O_B_LAT                  LATCbits.LATC1
#define O_B_PORT                 PORTCbits.RC1
#define O_B_WPU                  WPUCbits.WPUC1
#define O_B_OD                   ODCONCbits.ODCC1
#define O_B_ANS                  ANSELCbits.ANSC1
#define O_B_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define O_B_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define O_B_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define O_B_GetValue()           PORTCbits.RC1
#define O_B_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define O_B_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define O_B_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define O_B_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define O_B_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define O_B_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define O_B_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define O_B_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set O_C aliases
#define O_C_TRIS                 TRISCbits.TRISC2
#define O_C_LAT                  LATCbits.LATC2
#define O_C_PORT                 PORTCbits.RC2
#define O_C_WPU                  WPUCbits.WPUC2
#define O_C_OD                   ODCONCbits.ODCC2
#define O_C_ANS                  ANSELCbits.ANSC2
#define O_C_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define O_C_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define O_C_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define O_C_GetValue()           PORTCbits.RC2
#define O_C_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define O_C_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define O_C_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define O_C_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define O_C_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define O_C_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define O_C_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define O_C_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set O_D aliases
#define O_D_TRIS                 TRISCbits.TRISC3
#define O_D_LAT                  LATCbits.LATC3
#define O_D_PORT                 PORTCbits.RC3
#define O_D_WPU                  WPUCbits.WPUC3
#define O_D_OD                   ODCONCbits.ODCC3
#define O_D_ANS                  ANSELCbits.ANSC3
#define O_D_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define O_D_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define O_D_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define O_D_GetValue()           PORTCbits.RC3
#define O_D_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define O_D_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define O_D_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define O_D_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define O_D_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define O_D_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define O_D_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define O_D_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set O_E aliases
#define O_E_TRIS                 TRISCbits.TRISC4
#define O_E_LAT                  LATCbits.LATC4
#define O_E_PORT                 PORTCbits.RC4
#define O_E_WPU                  WPUCbits.WPUC4
#define O_E_OD                   ODCONCbits.ODCC4
#define O_E_ANS                  ANSELCbits.ANSC4
#define O_E_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define O_E_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define O_E_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define O_E_GetValue()           PORTCbits.RC4
#define O_E_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define O_E_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define O_E_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define O_E_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define O_E_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define O_E_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define O_E_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define O_E_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set O_F aliases
#define O_F_TRIS                 TRISCbits.TRISC5
#define O_F_LAT                  LATCbits.LATC5
#define O_F_PORT                 PORTCbits.RC5
#define O_F_WPU                  WPUCbits.WPUC5
#define O_F_OD                   ODCONCbits.ODCC5
#define O_F_ANS                  ANSELCbits.ANSC5
#define O_F_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define O_F_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define O_F_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define O_F_GetValue()           PORTCbits.RC5
#define O_F_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define O_F_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define O_F_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define O_F_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define O_F_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define O_F_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define O_F_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define O_F_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set O_G aliases
#define O_G_TRIS                 TRISCbits.TRISC6
#define O_G_LAT                  LATCbits.LATC6
#define O_G_PORT                 PORTCbits.RC6
#define O_G_WPU                  WPUCbits.WPUC6
#define O_G_OD                   ODCONCbits.ODCC6
#define O_G_ANS                  ANSELCbits.ANSC6
#define O_G_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define O_G_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define O_G_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define O_G_GetValue()           PORTCbits.RC6
#define O_G_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define O_G_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define O_G_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define O_G_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define O_G_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define O_G_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define O_G_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define O_G_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set O_DP aliases
#define O_DP_TRIS                 TRISCbits.TRISC7
#define O_DP_LAT                  LATCbits.LATC7
#define O_DP_PORT                 PORTCbits.RC7
#define O_DP_WPU                  WPUCbits.WPUC7
#define O_DP_OD                   ODCONCbits.ODCC7
#define O_DP_ANS                  ANSELCbits.ANSC7
#define O_DP_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define O_DP_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define O_DP_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define O_DP_GetValue()           PORTCbits.RC7
#define O_DP_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define O_DP_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define O_DP_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define O_DP_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define O_DP_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define O_DP_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define O_DP_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define O_DP_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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