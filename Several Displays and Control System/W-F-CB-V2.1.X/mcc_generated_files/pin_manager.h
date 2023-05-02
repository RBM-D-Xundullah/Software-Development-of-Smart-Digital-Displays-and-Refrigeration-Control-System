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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC16F15344
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.00
        MPLAB 	          :  MPLAB X 5.10	
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

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

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

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set RD aliases
#define RD_TRIS                 TRISCbits.TRISC0
#define RD_LAT                  LATCbits.LATC0
#define RD_PORT                 PORTCbits.RC0
#define RD_WPU                  WPUCbits.WPUC0
#define RD_OD                   ODCONCbits.ODCC0
#define RD_ANS                  ANSELCbits.ANSC0
#define RD_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RD_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RD_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RD_GetValue()           PORTCbits.RC0
#define RD_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RD_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RD_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define RD_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define RD_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define RD_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define RD_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define RD_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

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

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set ION aliases
#define ION_TRIS                 TRISCbits.TRISC5
#define ION_LAT                  LATCbits.LATC5
#define ION_PORT                 PORTCbits.RC5
#define ION_WPU                  WPUCbits.WPUC5
#define ION_OD                   ODCONCbits.ODCC5
#define ION_ANS                  ANSELCbits.ANSC5
#define ION_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define ION_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define ION_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define ION_GetValue()           PORTCbits.RC5
#define ION_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define ION_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define ION_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define ION_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define ION_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define ION_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define ION_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define ION_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set COMP aliases
#define COMP_TRIS                 TRISCbits.TRISC7
#define COMP_LAT                  LATCbits.LATC7
#define COMP_PORT                 PORTCbits.RC7
#define COMP_WPU                  WPUCbits.WPUC7
#define COMP_OD                   ODCONCbits.ODCC7
#define COMP_ANS                  ANSELCbits.ANSC7
#define COMP_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define COMP_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define COMP_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define COMP_GetValue()           PORTCbits.RC7
#define COMP_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define COMP_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define COMP_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define COMP_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define COMP_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define COMP_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define COMP_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define COMP_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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