        // LCD module connections
        sbit LCD_RS at RB2_bit;
        sbit LCD_EN at RB3_bit;
        sbit LCD_D4 at RB4_bit;
        sbit LCD_D5 at RB5_bit;
        sbit LCD_D6 at RB6_bit;
        sbit LCD_D7 at RB7_bit;
        // LCD module directions
        sbit LCD_RS_Direction at TRISB2_bit;
        sbit LCD_EN_Direction at TRISB3_bit;
        sbit LCD_D4_Direction at TRISB4_bit;
        sbit LCD_D5_Direction at TRISB5_bit;
        sbit LCD_D6_Direction at TRISB6_bit;
        sbit LCD_D7_Direction at TRISB7_bit;


        unsigned long u32_Mn, u32_Cn;


        /*******************************************************************************
        * Function Name      : void v_get_slope_intercept (uint16_t u16_adc)
        * Returns            : u32_Mn & u32_Cn as Global
        * Arguments          : u16_adc
        * Description        : Get Slope & Intercept value from Mapping
        *                      of Polo_10k3950 NTC sensor by Raihan Bin Mofidul
        * Modification Date  : 04-Jul-2019
        ******************************************************************************/
         void v_get_slope_intercept(unsigned long u16_adc) {
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
          /******************************************************************************/



        //get_adc_value
         unsigned long get_adc_value (unsigned short x)
         {
            unsigned long adc,i;
            adc = 0;
            for (i=0;i<1024;i++)
            {
             adc = adc + ADC_read(x);
             delay_ms(1);
            }
            adc = adc>>10;
            return(adc);
         }


         //get_res_value
         float get_res (float adc)
         {
           float vout,res;
           vout = (adc/1023)*5;          //for 10bit ADC, VCC=5
           res = (vout/(5-vout))*10000;  //to make Kohm
           return (res);
         }
         
         //get_temp_value
         int get_temp_RBM (unsigned long ADC)
         {
            unsigned long T;
            v_get_slope_intercept(ADC);
            T = (u32_Cn - ADC * u32_Mn) >> 10;
            return(T);
         }








        //get_temp user define function
        /*The Steinhart–Hart equation is a model of the resistance of a semiconductor at different temperatures. The equation is:
        1/T=A+Bln(R)+C(ln(R))^3
        where:
        T is the temperature (in kelvins)
        R is the resistance at TT (in ohms)
        A, B, and C are the Steinhart–Hart coefficients
        Target points at -40*c , 20*C , 80*C
        */
        float get_temp_SH (float res)
        {
           float t_SH,A,B,C;
           A = 0.000832869050329784;
           B = 0.000261881687376714;
           C = 1.40916067331594e-07;
           t_SH = (1/( A + B *log(res) + C * pow(log(res),3)) )-273;
           return(t_SH);
        }


        /*
          By Beta calculation
        */
        float get_temp_Beta (float res)
        {
           float t_Beta,To,Ro,B;
           To = 273+0;     //0 degree celcius
           Ro = 6350;      //at degree celcius
           B = 3823000;
           t_Beta = (1/((1/To)+(1/B)*log(res/Ro)))-273;
           return(t_Beta);
        }






   void main()
   {

       // variable
       char adc_print[3],res_print[7],temp_print[5];
       float t_get,res_get;
       int i, t_real, t_decimal;
       unsigned long adc_get;


        //*****I/O Configuration****//
       CMCON = 0b00000111;   // To turn off comparators
       ADCON1 = 0b00001110;  // To set AN0 as analog to digital converter
       trisa.f0 = 1;         //Set AN0 as input
       ADC_Init();


        //LCD initialization
        Lcd_Init();
        Lcd_cmd(_LCD_CLEAR);
        Lcd_cmd(_LCD_CURSOR_OFF);



        //Display Temperature
        while(1)
        {

          adc_get = get_adc_value(0);
          
          //adc_print
          WordToStr(adc_get, adc_print);
          Lcd_Out(1,1,"ADC ");
          Lcd_Out(1,4,adc_print);
          delay_ms(1);

          res_get = get_res (adc_get);
          FloatToStr_FixLen(res_get, res_print,10);
          Lcd_Out(2,1,"NTC ");
          Lcd_Out(2,5,res_print);
          delay_ms(1);
          
          t_get = get_temp_RBM(adc_get);
          FloatToStr_FixLen(t_get/10, temp_print,5);
          Lcd_Out(1,10,"T ");
          Lcd_Out(1,12,Temp_print);
          delay_ms(1);

         }
}