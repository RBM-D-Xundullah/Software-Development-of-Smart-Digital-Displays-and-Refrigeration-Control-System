
_v_get_slope_intercept:

;Test_01.c,28 :: 		void v_get_slope_intercept(unsigned long u16_adc) {
;Test_01.c,29 :: 		if (u16_adc) {
	MOVF       FARG_v_get_slope_intercept_u16_adc+0, 0
	IORWF      FARG_v_get_slope_intercept_u16_adc+1, 0
	IORWF      FARG_v_get_slope_intercept_u16_adc+2, 0
	IORWF      FARG_v_get_slope_intercept_u16_adc+3, 0
	BTFSC      STATUS+0, 2
	GOTO       L_v_get_slope_intercept0
;Test_01.c,30 :: 		if (u16_adc > 967) {        //-40 to -30
	MOVF       FARG_v_get_slope_intercept_u16_adc+3, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept30
	MOVF       FARG_v_get_slope_intercept_u16_adc+2, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept30
	MOVF       FARG_v_get_slope_intercept_u16_adc+1, 0
	SUBLW      3
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept30
	MOVF       FARG_v_get_slope_intercept_u16_adc+0, 0
	SUBLW      199
L__v_get_slope_intercept30:
	BTFSC      STATUS+0, 0
	GOTO       L_v_get_slope_intercept1
;Test_01.c,31 :: 		u32_Mn = 4064;
	MOVLW      224
	MOVWF      _u32_Mn+0
	MOVLW      15
	MOVWF      _u32_Mn+1
	CLRF       _u32_Mn+2
	CLRF       _u32_Mn+3
;Test_01.c,32 :: 		u32_Cn = 3634688;
	MOVLW      0
	MOVWF      _u32_Cn+0
	MOVLW      118
	MOVWF      _u32_Cn+1
	MOVLW      55
	MOVWF      _u32_Cn+2
	MOVLW      0
	MOVWF      _u32_Cn+3
;Test_01.c,33 :: 		} else if (u16_adc > 928) { //-30 to -20
	GOTO       L_v_get_slope_intercept2
L_v_get_slope_intercept1:
	MOVF       FARG_v_get_slope_intercept_u16_adc+3, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept31
	MOVF       FARG_v_get_slope_intercept_u16_adc+2, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept31
	MOVF       FARG_v_get_slope_intercept_u16_adc+1, 0
	SUBLW      3
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept31
	MOVF       FARG_v_get_slope_intercept_u16_adc+0, 0
	SUBLW      160
L__v_get_slope_intercept31:
	BTFSC      STATUS+0, 0
	GOTO       L_v_get_slope_intercept3
;Test_01.c,34 :: 		u32_Mn = 2503;
	MOVLW      199
	MOVWF      _u32_Mn+0
	MOVLW      9
	MOVWF      _u32_Mn+1
	CLRF       _u32_Mn+2
	CLRF       _u32_Mn+3
;Test_01.c,35 :: 		u32_Cn = 2121523;
	MOVLW      51
	MOVWF      _u32_Cn+0
	MOVLW      95
	MOVWF      _u32_Cn+1
	MOVLW      32
	MOVWF      _u32_Cn+2
	MOVLW      0
	MOVWF      _u32_Cn+3
;Test_01.c,36 :: 		} else if (u16_adc > 867) { //-20 to -10
	GOTO       L_v_get_slope_intercept4
L_v_get_slope_intercept3:
	MOVF       FARG_v_get_slope_intercept_u16_adc+3, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept32
	MOVF       FARG_v_get_slope_intercept_u16_adc+2, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept32
	MOVF       FARG_v_get_slope_intercept_u16_adc+1, 0
	SUBLW      3
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept32
	MOVF       FARG_v_get_slope_intercept_u16_adc+0, 0
	SUBLW      99
L__v_get_slope_intercept32:
	BTFSC      STATUS+0, 0
	GOTO       L_v_get_slope_intercept5
;Test_01.c,37 :: 		u32_Mn = 1672;
	MOVLW      136
	MOVWF      _u32_Mn+0
	MOVLW      6
	MOVWF      _u32_Mn+1
	CLRF       _u32_Mn+2
	CLRF       _u32_Mn+3
;Test_01.c,38 :: 		u32_Cn = 1350451;
	MOVLW      51
	MOVWF      _u32_Cn+0
	MOVLW      155
	MOVWF      _u32_Cn+1
	MOVLW      20
	MOVWF      _u32_Cn+2
	MOVLW      0
	MOVWF      _u32_Cn+3
;Test_01.c,39 :: 		} else if (u16_adc > 784) { //-10 to 0
	GOTO       L_v_get_slope_intercept6
L_v_get_slope_intercept5:
	MOVF       FARG_v_get_slope_intercept_u16_adc+3, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept33
	MOVF       FARG_v_get_slope_intercept_u16_adc+2, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept33
	MOVF       FARG_v_get_slope_intercept_u16_adc+1, 0
	SUBLW      3
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept33
	MOVF       FARG_v_get_slope_intercept_u16_adc+0, 0
	SUBLW      16
L__v_get_slope_intercept33:
	BTFSC      STATUS+0, 0
	GOTO       L_v_get_slope_intercept7
;Test_01.c,40 :: 		u32_Mn = 1227;
	MOVLW      203
	MOVWF      _u32_Mn+0
	MOVLW      4
	MOVWF      _u32_Mn+1
	CLRF       _u32_Mn+2
	CLRF       _u32_Mn+3
;Test_01.c,41 :: 		u32_Cn = 963461;
	MOVLW      133
	MOVWF      _u32_Cn+0
	MOVLW      179
	MOVWF      _u32_Cn+1
	MOVLW      14
	MOVWF      _u32_Cn+2
	MOVLW      0
	MOVWF      _u32_Cn+3
;Test_01.c,42 :: 		} else if (u16_adc > 681) { //0 to 10
	GOTO       L_v_get_slope_intercept8
L_v_get_slope_intercept7:
	MOVF       FARG_v_get_slope_intercept_u16_adc+3, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept34
	MOVF       FARG_v_get_slope_intercept_u16_adc+2, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept34
	MOVF       FARG_v_get_slope_intercept_u16_adc+1, 0
	SUBLW      2
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept34
	MOVF       FARG_v_get_slope_intercept_u16_adc+0, 0
	SUBLW      169
L__v_get_slope_intercept34:
	BTFSC      STATUS+0, 0
	GOTO       L_v_get_slope_intercept9
;Test_01.c,43 :: 		u32_Mn = 998;
	MOVLW      230
	MOVWF      _u32_Mn+0
	MOVLW      3
	MOVWF      _u32_Mn+1
	CLRF       _u32_Mn+2
	CLRF       _u32_Mn+3
;Test_01.c,44 :: 		u32_Cn = 783544;
	MOVLW      184
	MOVWF      _u32_Cn+0
	MOVLW      244
	MOVWF      _u32_Cn+1
	MOVLW      11
	MOVWF      _u32_Cn+2
	MOVLW      0
	MOVWF      _u32_Cn+3
;Test_01.c,45 :: 		} else if (u16_adc > 568) { //10 to 20
	GOTO       L_v_get_slope_intercept10
L_v_get_slope_intercept9:
	MOVF       FARG_v_get_slope_intercept_u16_adc+3, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept35
	MOVF       FARG_v_get_slope_intercept_u16_adc+2, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept35
	MOVF       FARG_v_get_slope_intercept_u16_adc+1, 0
	SUBLW      2
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept35
	MOVF       FARG_v_get_slope_intercept_u16_adc+0, 0
	SUBLW      56
L__v_get_slope_intercept35:
	BTFSC      STATUS+0, 0
	GOTO       L_v_get_slope_intercept11
;Test_01.c,46 :: 		u32_Mn = 905;
	MOVLW      137
	MOVWF      _u32_Mn+0
	MOVLW      3
	MOVWF      _u32_Mn+1
	CLRF       _u32_Mn+2
	CLRF       _u32_Mn+3
;Test_01.c,47 :: 		u32_Cn = 719657;
	MOVLW      41
	MOVWF      _u32_Cn+0
	MOVLW      251
	MOVWF      _u32_Cn+1
	MOVLW      10
	MOVWF      _u32_Cn+2
	MOVLW      0
	MOVWF      _u32_Cn+3
;Test_01.c,48 :: 		} else if (u16_adc > 456) { //20 to 30
	GOTO       L_v_get_slope_intercept12
L_v_get_slope_intercept11:
	MOVF       FARG_v_get_slope_intercept_u16_adc+3, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept36
	MOVF       FARG_v_get_slope_intercept_u16_adc+2, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept36
	MOVF       FARG_v_get_slope_intercept_u16_adc+1, 0
	SUBLW      1
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept36
	MOVF       FARG_v_get_slope_intercept_u16_adc+0, 0
	SUBLW      200
L__v_get_slope_intercept36:
	BTFSC      STATUS+0, 0
	GOTO       L_v_get_slope_intercept13
;Test_01.c,49 :: 		u32_Mn = 912;
	MOVLW      144
	MOVWF      _u32_Mn+0
	MOVLW      3
	MOVWF      _u32_Mn+1
	CLRF       _u32_Mn+2
	CLRF       _u32_Mn+3
;Test_01.c,50 :: 		u32_Cn = 723139;
	MOVLW      195
	MOVWF      _u32_Cn+0
	MOVLW      8
	MOVWF      _u32_Cn+1
	MOVLW      11
	MOVWF      _u32_Cn+2
	MOVLW      0
	MOVWF      _u32_Cn+3
;Test_01.c,51 :: 		} else if (u16_adc > 355) { //30 to 40
	GOTO       L_v_get_slope_intercept14
L_v_get_slope_intercept13:
	MOVF       FARG_v_get_slope_intercept_u16_adc+3, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept37
	MOVF       FARG_v_get_slope_intercept_u16_adc+2, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept37
	MOVF       FARG_v_get_slope_intercept_u16_adc+1, 0
	SUBLW      1
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept37
	MOVF       FARG_v_get_slope_intercept_u16_adc+0, 0
	SUBLW      99
L__v_get_slope_intercept37:
	BTFSC      STATUS+0, 0
	GOTO       L_v_get_slope_intercept15
;Test_01.c,52 :: 		u32_Mn = 1010;
	MOVLW      242
	MOVWF      _u32_Mn+0
	MOVLW      3
	MOVWF      _u32_Mn+1
	CLRF       _u32_Mn+2
	CLRF       _u32_Mn+3
;Test_01.c,53 :: 		u32_Cn = 767048;
	MOVLW      72
	MOVWF      _u32_Cn+0
	MOVLW      180
	MOVWF      _u32_Cn+1
	MOVLW      11
	MOVWF      _u32_Cn+2
	MOVLW      0
	MOVWF      _u32_Cn+3
;Test_01.c,54 :: 		} else if (u16_adc > 270) { //40 to 50
	GOTO       L_v_get_slope_intercept16
L_v_get_slope_intercept15:
	MOVF       FARG_v_get_slope_intercept_u16_adc+3, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept38
	MOVF       FARG_v_get_slope_intercept_u16_adc+2, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept38
	MOVF       FARG_v_get_slope_intercept_u16_adc+1, 0
	SUBLW      1
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept38
	MOVF       FARG_v_get_slope_intercept_u16_adc+0, 0
	SUBLW      14
L__v_get_slope_intercept38:
	BTFSC      STATUS+0, 0
	GOTO       L_v_get_slope_intercept17
;Test_01.c,55 :: 		u32_Mn = 1205;
	MOVLW      181
	MOVWF      _u32_Mn+0
	MOVLW      4
	MOVWF      _u32_Mn+1
	CLRF       _u32_Mn+2
	CLRF       _u32_Mn+3
;Test_01.c,56 :: 		u32_Cn = 835963;
	MOVLW      123
	MOVWF      _u32_Cn+0
	MOVLW      193
	MOVWF      _u32_Cn+1
	MOVLW      12
	MOVWF      _u32_Cn+2
	MOVLW      0
	MOVWF      _u32_Cn+3
;Test_01.c,57 :: 		} else if (u16_adc > 203) { //50 to 60
	GOTO       L_v_get_slope_intercept18
L_v_get_slope_intercept17:
	MOVF       FARG_v_get_slope_intercept_u16_adc+3, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept39
	MOVF       FARG_v_get_slope_intercept_u16_adc+2, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept39
	MOVF       FARG_v_get_slope_intercept_u16_adc+1, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__v_get_slope_intercept39
	MOVF       FARG_v_get_slope_intercept_u16_adc+0, 0
	SUBLW      203
L__v_get_slope_intercept39:
	BTFSC      STATUS+0, 0
	GOTO       L_v_get_slope_intercept19
;Test_01.c,58 :: 		u32_Mn = 1521;
	MOVLW      241
	MOVWF      _u32_Mn+0
	MOVLW      5
	MOVWF      _u32_Mn+1
	CLRF       _u32_Mn+2
	CLRF       _u32_Mn+3
;Test_01.c,59 :: 		u32_Cn = 920842;
	MOVLW      10
	MOVWF      _u32_Cn+0
	MOVLW      13
	MOVWF      _u32_Cn+1
	MOVLW      14
	MOVWF      _u32_Cn+2
	MOVLW      0
	MOVWF      _u32_Cn+3
;Test_01.c,60 :: 		}
L_v_get_slope_intercept19:
L_v_get_slope_intercept18:
L_v_get_slope_intercept16:
L_v_get_slope_intercept14:
L_v_get_slope_intercept12:
L_v_get_slope_intercept10:
L_v_get_slope_intercept8:
L_v_get_slope_intercept6:
L_v_get_slope_intercept4:
L_v_get_slope_intercept2:
;Test_01.c,61 :: 		}
L_v_get_slope_intercept0:
;Test_01.c,62 :: 		}
L_end_v_get_slope_intercept:
	RETURN
; end of _v_get_slope_intercept

_get_adc_value:

;Test_01.c,68 :: 		unsigned long get_adc_value (unsigned short x)
;Test_01.c,71 :: 		adc = 0;
	CLRF       get_adc_value_adc_L0+0
	CLRF       get_adc_value_adc_L0+1
	CLRF       get_adc_value_adc_L0+2
	CLRF       get_adc_value_adc_L0+3
;Test_01.c,72 :: 		for (i=0;i<1024;i++)
	CLRF       get_adc_value_i_L0+0
	CLRF       get_adc_value_i_L0+1
	CLRF       get_adc_value_i_L0+2
	CLRF       get_adc_value_i_L0+3
L_get_adc_value20:
	MOVLW      0
	SUBWF      get_adc_value_i_L0+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__get_adc_value41
	MOVLW      0
	SUBWF      get_adc_value_i_L0+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__get_adc_value41
	MOVLW      4
	SUBWF      get_adc_value_i_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__get_adc_value41
	MOVLW      0
	SUBWF      get_adc_value_i_L0+0, 0
L__get_adc_value41:
	BTFSC      STATUS+0, 0
	GOTO       L_get_adc_value21
;Test_01.c,74 :: 		adc = adc + ADC_read(x);
	MOVF       FARG_get_adc_value_x+0, 0
	MOVWF      FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	MOVLW      0
	MOVWF      R0+2
	MOVWF      R0+3
	MOVF       get_adc_value_adc_L0+0, 0
	ADDWF      R0+0, 1
	MOVF       get_adc_value_adc_L0+1, 0
	BTFSC      STATUS+0, 0
	INCFSZ     get_adc_value_adc_L0+1, 0
	ADDWF      R0+1, 1
	MOVF       get_adc_value_adc_L0+2, 0
	BTFSC      STATUS+0, 0
	INCFSZ     get_adc_value_adc_L0+2, 0
	ADDWF      R0+2, 1
	MOVF       get_adc_value_adc_L0+3, 0
	BTFSC      STATUS+0, 0
	INCFSZ     get_adc_value_adc_L0+3, 0
	ADDWF      R0+3, 1
	MOVF       R0+0, 0
	MOVWF      get_adc_value_adc_L0+0
	MOVF       R0+1, 0
	MOVWF      get_adc_value_adc_L0+1
	MOVF       R0+2, 0
	MOVWF      get_adc_value_adc_L0+2
	MOVF       R0+3, 0
	MOVWF      get_adc_value_adc_L0+3
;Test_01.c,75 :: 		delay_ms(1);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_get_adc_value23:
	DECFSZ     R13+0, 1
	GOTO       L_get_adc_value23
	DECFSZ     R12+0, 1
	GOTO       L_get_adc_value23
;Test_01.c,72 :: 		for (i=0;i<1024;i++)
	MOVF       get_adc_value_i_L0+0, 0
	MOVWF      R0+0
	MOVF       get_adc_value_i_L0+1, 0
	MOVWF      R0+1
	MOVF       get_adc_value_i_L0+2, 0
	MOVWF      R0+2
	MOVF       get_adc_value_i_L0+3, 0
	MOVWF      R0+3
	INCF       R0+0, 1
	BTFSC      STATUS+0, 2
	INCF       R0+1, 1
	BTFSC      STATUS+0, 2
	INCF       R0+2, 1
	BTFSC      STATUS+0, 2
	INCF       R0+3, 1
	MOVF       R0+0, 0
	MOVWF      get_adc_value_i_L0+0
	MOVF       R0+1, 0
	MOVWF      get_adc_value_i_L0+1
	MOVF       R0+2, 0
	MOVWF      get_adc_value_i_L0+2
	MOVF       R0+3, 0
	MOVWF      get_adc_value_i_L0+3
;Test_01.c,76 :: 		}
	GOTO       L_get_adc_value20
L_get_adc_value21:
;Test_01.c,77 :: 		adc = adc>>10;
	MOVLW      10
	MOVWF      R4+0
	MOVF       get_adc_value_adc_L0+0, 0
	MOVWF      R0+0
	MOVF       get_adc_value_adc_L0+1, 0
	MOVWF      R0+1
	MOVF       get_adc_value_adc_L0+2, 0
	MOVWF      R0+2
	MOVF       get_adc_value_adc_L0+3, 0
	MOVWF      R0+3
	MOVF       R4+0, 0
L__get_adc_value42:
	BTFSC      STATUS+0, 2
	GOTO       L__get_adc_value43
	RRF        R0+3, 1
	RRF        R0+2, 1
	RRF        R0+1, 1
	RRF        R0+0, 1
	BCF        R0+3, 7
	ADDLW      255
	GOTO       L__get_adc_value42
L__get_adc_value43:
	MOVF       R0+0, 0
	MOVWF      get_adc_value_adc_L0+0
	MOVF       R0+1, 0
	MOVWF      get_adc_value_adc_L0+1
	MOVF       R0+2, 0
	MOVWF      get_adc_value_adc_L0+2
	MOVF       R0+3, 0
	MOVWF      get_adc_value_adc_L0+3
;Test_01.c,78 :: 		return(adc);
;Test_01.c,79 :: 		}
L_end_get_adc_value:
	RETURN
; end of _get_adc_value

_get_res:

;Test_01.c,83 :: 		float get_res (float adc)
;Test_01.c,86 :: 		vout = (adc/1023)*5;          //for 10bit ADC, VCC=5
	MOVLW      0
	MOVWF      R4+0
	MOVLW      192
	MOVWF      R4+1
	MOVLW      127
	MOVWF      R4+2
	MOVLW      136
	MOVWF      R4+3
	MOVF       FARG_get_res_adc+0, 0
	MOVWF      R0+0
	MOVF       FARG_get_res_adc+1, 0
	MOVWF      R0+1
	MOVF       FARG_get_res_adc+2, 0
	MOVWF      R0+2
	MOVF       FARG_get_res_adc+3, 0
	MOVWF      R0+3
	CALL       _Div_32x32_FP+0
	MOVLW      0
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVLW      32
	MOVWF      R4+2
	MOVLW      129
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
	MOVF       R0+0, 0
	MOVWF      FLOC__get_res+0
	MOVF       R0+1, 0
	MOVWF      FLOC__get_res+1
	MOVF       R0+2, 0
	MOVWF      FLOC__get_res+2
	MOVF       R0+3, 0
	MOVWF      FLOC__get_res+3
	MOVF       FLOC__get_res+0, 0
	MOVWF      R4+0
	MOVF       FLOC__get_res+1, 0
	MOVWF      R4+1
	MOVF       FLOC__get_res+2, 0
	MOVWF      R4+2
	MOVF       FLOC__get_res+3, 0
	MOVWF      R4+3
	MOVLW      0
	MOVWF      R0+0
	MOVLW      0
	MOVWF      R0+1
	MOVLW      32
	MOVWF      R0+2
	MOVLW      129
	MOVWF      R0+3
	CALL       _Sub_32x32_FP+0
;Test_01.c,87 :: 		res = (vout/(5-vout))*10000;  //to make Kohm
	MOVF       R0+0, 0
	MOVWF      R4+0
	MOVF       R0+1, 0
	MOVWF      R4+1
	MOVF       R0+2, 0
	MOVWF      R4+2
	MOVF       R0+3, 0
	MOVWF      R4+3
	MOVF       FLOC__get_res+0, 0
	MOVWF      R0+0
	MOVF       FLOC__get_res+1, 0
	MOVWF      R0+1
	MOVF       FLOC__get_res+2, 0
	MOVWF      R0+2
	MOVF       FLOC__get_res+3, 0
	MOVWF      R0+3
	CALL       _Div_32x32_FP+0
	MOVLW      0
	MOVWF      R4+0
	MOVLW      64
	MOVWF      R4+1
	MOVLW      28
	MOVWF      R4+2
	MOVLW      140
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
;Test_01.c,88 :: 		return (res);
;Test_01.c,89 :: 		}
L_end_get_res:
	RETURN
; end of _get_res

_get_temp_RBM:

;Test_01.c,92 :: 		int get_temp_RBM (unsigned long ADC)
;Test_01.c,95 :: 		v_get_slope_intercept(ADC);
	MOVF       FARG_get_temp_RBM_ADC+0, 0
	MOVWF      FARG_v_get_slope_intercept_u16_adc+0
	MOVF       FARG_get_temp_RBM_ADC+1, 0
	MOVWF      FARG_v_get_slope_intercept_u16_adc+1
	MOVF       FARG_get_temp_RBM_ADC+2, 0
	MOVWF      FARG_v_get_slope_intercept_u16_adc+2
	MOVF       FARG_get_temp_RBM_ADC+3, 0
	MOVWF      FARG_v_get_slope_intercept_u16_adc+3
	CALL       _v_get_slope_intercept+0
;Test_01.c,96 :: 		T = (u32_Cn - ADC * u32_Mn) >> 10;
	MOVF       FARG_get_temp_RBM_ADC+0, 0
	MOVWF      R0+0
	MOVF       FARG_get_temp_RBM_ADC+1, 0
	MOVWF      R0+1
	MOVF       FARG_get_temp_RBM_ADC+2, 0
	MOVWF      R0+2
	MOVF       FARG_get_temp_RBM_ADC+3, 0
	MOVWF      R0+3
	MOVF       _u32_Mn+0, 0
	MOVWF      R4+0
	MOVF       _u32_Mn+1, 0
	MOVWF      R4+1
	MOVF       _u32_Mn+2, 0
	MOVWF      R4+2
	MOVF       _u32_Mn+3, 0
	MOVWF      R4+3
	CALL       _Mul_32x32_U+0
	MOVF       _u32_Cn+0, 0
	MOVWF      R5+0
	MOVF       _u32_Cn+1, 0
	MOVWF      R5+1
	MOVF       _u32_Cn+2, 0
	MOVWF      R5+2
	MOVF       _u32_Cn+3, 0
	MOVWF      R5+3
	MOVF       R0+0, 0
	SUBWF      R5+0, 1
	MOVF       R0+1, 0
	BTFSS      STATUS+0, 0
	INCFSZ     R0+1, 0
	SUBWF      R5+1, 1
	MOVF       R0+2, 0
	BTFSS      STATUS+0, 0
	INCFSZ     R0+2, 0
	SUBWF      R5+2, 1
	MOVF       R0+3, 0
	BTFSS      STATUS+0, 0
	INCFSZ     R0+3, 0
	SUBWF      R5+3, 1
	MOVLW      10
	MOVWF      R4+0
	MOVF       R5+0, 0
	MOVWF      R0+0
	MOVF       R5+1, 0
	MOVWF      R0+1
	MOVF       R5+2, 0
	MOVWF      R0+2
	MOVF       R5+3, 0
	MOVWF      R0+3
	MOVF       R4+0, 0
L__get_temp_RBM46:
	BTFSC      STATUS+0, 2
	GOTO       L__get_temp_RBM47
	RRF        R0+3, 1
	RRF        R0+2, 1
	RRF        R0+1, 1
	RRF        R0+0, 1
	BCF        R0+3, 7
	ADDLW      255
	GOTO       L__get_temp_RBM46
L__get_temp_RBM47:
;Test_01.c,97 :: 		return(T);
;Test_01.c,98 :: 		}
L_end_get_temp_RBM:
	RETURN
; end of _get_temp_RBM

_get_temp_SH:

;Test_01.c,116 :: 		float get_temp_SH (float res)
;Test_01.c,119 :: 		A = 0.000832869050329784;
	MOVLW      229
	MOVWF      get_temp_SH_A_L0+0
	MOVLW      84
	MOVWF      get_temp_SH_A_L0+1
	MOVLW      90
	MOVWF      get_temp_SH_A_L0+2
	MOVLW      116
	MOVWF      get_temp_SH_A_L0+3
;Test_01.c,120 :: 		B = 0.000261881687376714;
	MOVLW      42
	MOVWF      get_temp_SH_B_L0+0
	MOVLW      77
	MOVWF      get_temp_SH_B_L0+1
	MOVLW      9
	MOVWF      get_temp_SH_B_L0+2
	MOVLW      115
	MOVWF      get_temp_SH_B_L0+3
;Test_01.c,121 :: 		C = 1.40916067331594e-07;
	MOVLW      183
	MOVWF      get_temp_SH_C_L0+0
	MOVLW      78
	MOVWF      get_temp_SH_C_L0+1
	MOVLW      23
	MOVWF      get_temp_SH_C_L0+2
	MOVLW      104
	MOVWF      get_temp_SH_C_L0+3
;Test_01.c,122 :: 		t_SH = (1/( A + B *log(res) + C * pow(log(res),3)) )-273;
	MOVF       FARG_get_temp_SH_res+0, 0
	MOVWF      FARG_log_x+0
	MOVF       FARG_get_temp_SH_res+1, 0
	MOVWF      FARG_log_x+1
	MOVF       FARG_get_temp_SH_res+2, 0
	MOVWF      FARG_log_x+2
	MOVF       FARG_get_temp_SH_res+3, 0
	MOVWF      FARG_log_x+3
	CALL       _log+0
	MOVF       get_temp_SH_B_L0+0, 0
	MOVWF      R4+0
	MOVF       get_temp_SH_B_L0+1, 0
	MOVWF      R4+1
	MOVF       get_temp_SH_B_L0+2, 0
	MOVWF      R4+2
	MOVF       get_temp_SH_B_L0+3, 0
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
	MOVF       get_temp_SH_A_L0+0, 0
	MOVWF      R4+0
	MOVF       get_temp_SH_A_L0+1, 0
	MOVWF      R4+1
	MOVF       get_temp_SH_A_L0+2, 0
	MOVWF      R4+2
	MOVF       get_temp_SH_A_L0+3, 0
	MOVWF      R4+3
	CALL       _Add_32x32_FP+0
	MOVF       R0+0, 0
	MOVWF      FLOC__get_temp_SH+0
	MOVF       R0+1, 0
	MOVWF      FLOC__get_temp_SH+1
	MOVF       R0+2, 0
	MOVWF      FLOC__get_temp_SH+2
	MOVF       R0+3, 0
	MOVWF      FLOC__get_temp_SH+3
	MOVF       FARG_get_temp_SH_res+0, 0
	MOVWF      FARG_log_x+0
	MOVF       FARG_get_temp_SH_res+1, 0
	MOVWF      FARG_log_x+1
	MOVF       FARG_get_temp_SH_res+2, 0
	MOVWF      FARG_log_x+2
	MOVF       FARG_get_temp_SH_res+3, 0
	MOVWF      FARG_log_x+3
	CALL       _log+0
	MOVF       R0+0, 0
	MOVWF      FARG_pow_x+0
	MOVF       R0+1, 0
	MOVWF      FARG_pow_x+1
	MOVF       R0+2, 0
	MOVWF      FARG_pow_x+2
	MOVF       R0+3, 0
	MOVWF      FARG_pow_x+3
	MOVLW      0
	MOVWF      FARG_pow_y+0
	MOVLW      0
	MOVWF      FARG_pow_y+1
	MOVLW      64
	MOVWF      FARG_pow_y+2
	MOVLW      128
	MOVWF      FARG_pow_y+3
	CALL       _pow+0
	MOVF       get_temp_SH_C_L0+0, 0
	MOVWF      R4+0
	MOVF       get_temp_SH_C_L0+1, 0
	MOVWF      R4+1
	MOVF       get_temp_SH_C_L0+2, 0
	MOVWF      R4+2
	MOVF       get_temp_SH_C_L0+3, 0
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
	MOVF       FLOC__get_temp_SH+0, 0
	MOVWF      R4+0
	MOVF       FLOC__get_temp_SH+1, 0
	MOVWF      R4+1
	MOVF       FLOC__get_temp_SH+2, 0
	MOVWF      R4+2
	MOVF       FLOC__get_temp_SH+3, 0
	MOVWF      R4+3
	CALL       _Add_32x32_FP+0
	MOVF       R0+0, 0
	MOVWF      R4+0
	MOVF       R0+1, 0
	MOVWF      R4+1
	MOVF       R0+2, 0
	MOVWF      R4+2
	MOVF       R0+3, 0
	MOVWF      R4+3
	MOVLW      0
	MOVWF      R0+0
	MOVLW      0
	MOVWF      R0+1
	MOVLW      0
	MOVWF      R0+2
	MOVLW      127
	MOVWF      R0+3
	CALL       _Div_32x32_FP+0
	MOVLW      0
	MOVWF      R4+0
	MOVLW      128
	MOVWF      R4+1
	MOVLW      8
	MOVWF      R4+2
	MOVLW      135
	MOVWF      R4+3
	CALL       _Sub_32x32_FP+0
;Test_01.c,123 :: 		return(t_SH);
;Test_01.c,124 :: 		}
L_end_get_temp_SH:
	RETURN
; end of _get_temp_SH

_get_temp_Beta:

;Test_01.c,130 :: 		float get_temp_Beta (float res)
;Test_01.c,136 :: 		t_Beta = (1/((1/To)+(1/B)*log(res/Ro)))-273;
	MOVLW      1
	MOVWF      FLOC__get_temp_Beta+4
	MOVLW      15
	MOVWF      FLOC__get_temp_Beta+5
	MOVLW      112
	MOVWF      FLOC__get_temp_Beta+6
	MOVLW      118
	MOVWF      FLOC__get_temp_Beta+7
	MOVLW      141
	MOVWF      FLOC__get_temp_Beta+0
	MOVLW      110
	MOVWF      FLOC__get_temp_Beta+1
	MOVLW      12
	MOVWF      FLOC__get_temp_Beta+2
	MOVLW      105
	MOVWF      FLOC__get_temp_Beta+3
	MOVLW      0
	MOVWF      R4+0
	MOVLW      112
	MOVWF      R4+1
	MOVLW      70
	MOVWF      R4+2
	MOVLW      139
	MOVWF      R4+3
	MOVF       FARG_get_temp_Beta_res+0, 0
	MOVWF      R0+0
	MOVF       FARG_get_temp_Beta_res+1, 0
	MOVWF      R0+1
	MOVF       FARG_get_temp_Beta_res+2, 0
	MOVWF      R0+2
	MOVF       FARG_get_temp_Beta_res+3, 0
	MOVWF      R0+3
	CALL       _Div_32x32_FP+0
	MOVF       R0+0, 0
	MOVWF      FARG_log_x+0
	MOVF       R0+1, 0
	MOVWF      FARG_log_x+1
	MOVF       R0+2, 0
	MOVWF      FARG_log_x+2
	MOVF       R0+3, 0
	MOVWF      FARG_log_x+3
	CALL       _log+0
	MOVF       FLOC__get_temp_Beta+0, 0
	MOVWF      R4+0
	MOVF       FLOC__get_temp_Beta+1, 0
	MOVWF      R4+1
	MOVF       FLOC__get_temp_Beta+2, 0
	MOVWF      R4+2
	MOVF       FLOC__get_temp_Beta+3, 0
	MOVWF      R4+3
	CALL       _Mul_32x32_FP+0
	MOVF       FLOC__get_temp_Beta+4, 0
	MOVWF      R4+0
	MOVF       FLOC__get_temp_Beta+5, 0
	MOVWF      R4+1
	MOVF       FLOC__get_temp_Beta+6, 0
	MOVWF      R4+2
	MOVF       FLOC__get_temp_Beta+7, 0
	MOVWF      R4+3
	CALL       _Add_32x32_FP+0
	MOVF       R0+0, 0
	MOVWF      R4+0
	MOVF       R0+1, 0
	MOVWF      R4+1
	MOVF       R0+2, 0
	MOVWF      R4+2
	MOVF       R0+3, 0
	MOVWF      R4+3
	MOVLW      0
	MOVWF      R0+0
	MOVLW      0
	MOVWF      R0+1
	MOVLW      0
	MOVWF      R0+2
	MOVLW      127
	MOVWF      R0+3
	CALL       _Div_32x32_FP+0
	MOVLW      0
	MOVWF      R4+0
	MOVLW      128
	MOVWF      R4+1
	MOVLW      8
	MOVWF      R4+2
	MOVLW      135
	MOVWF      R4+3
	CALL       _Sub_32x32_FP+0
;Test_01.c,137 :: 		return(t_Beta);
;Test_01.c,138 :: 		}
L_end_get_temp_Beta:
	RETURN
; end of _get_temp_Beta

_main:

;Test_01.c,145 :: 		void main()
;Test_01.c,156 :: 		CMCON = 0b00000111;   // To turn off comparators
	MOVLW      7
	MOVWF      CMCON+0
;Test_01.c,157 :: 		ADCON1 = 0b00001110;  // To set AN0 as analog to digital converter
	MOVLW      14
	MOVWF      ADCON1+0
;Test_01.c,158 :: 		trisa.f0 = 1;         //Set AN0 as input
	BSF        TRISA+0, 0
;Test_01.c,159 :: 		ADC_Init();
	CALL       _ADC_Init+0
;Test_01.c,163 :: 		Lcd_Init();
	CALL       _Lcd_Init+0
;Test_01.c,164 :: 		Lcd_cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Test_01.c,165 :: 		Lcd_cmd(_LCD_CURSOR_OFF);
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Test_01.c,170 :: 		while(1)
L_main24:
;Test_01.c,173 :: 		adc_get = get_adc_value(0);
	CLRF       FARG_get_adc_value_x+0
	CALL       _get_adc_value+0
	MOVF       R0+0, 0
	MOVWF      main_adc_get_L0+0
	MOVF       R0+1, 0
	MOVWF      main_adc_get_L0+1
	MOVF       R0+2, 0
	MOVWF      main_adc_get_L0+2
	MOVF       R0+3, 0
	MOVWF      main_adc_get_L0+3
;Test_01.c,176 :: 		WordToStr(adc_get, adc_print);
	MOVF       R0+0, 0
	MOVWF      FARG_WordToStr_input+0
	MOVF       R0+1, 0
	MOVWF      FARG_WordToStr_input+1
	MOVLW      main_adc_print_L0+0
	MOVWF      FARG_WordToStr_output+0
	CALL       _WordToStr+0
;Test_01.c,177 :: 		Lcd_Out(1,1,"ADC ");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr1_Test_01+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Test_01.c,178 :: 		Lcd_Out(1,4,adc_print);
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      4
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      main_adc_print_L0+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Test_01.c,179 :: 		delay_ms(1);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main26:
	DECFSZ     R13+0, 1
	GOTO       L_main26
	DECFSZ     R12+0, 1
	GOTO       L_main26
;Test_01.c,181 :: 		res_get = get_res (adc_get);
	MOVF       main_adc_get_L0+0, 0
	MOVWF      R0+0
	MOVF       main_adc_get_L0+1, 0
	MOVWF      R0+1
	MOVF       main_adc_get_L0+2, 0
	MOVWF      R0+2
	MOVF       main_adc_get_L0+3, 0
	MOVWF      R0+3
	CALL       _longword2double+0
	MOVF       R0+0, 0
	MOVWF      FARG_get_res_adc+0
	MOVF       R0+1, 0
	MOVWF      FARG_get_res_adc+1
	MOVF       R0+2, 0
	MOVWF      FARG_get_res_adc+2
	MOVF       R0+3, 0
	MOVWF      FARG_get_res_adc+3
	CALL       _get_res+0
;Test_01.c,182 :: 		FloatToStr_FixLen(res_get, res_print,10);
	MOVF       R0+0, 0
	MOVWF      FARG_FloatToStr_FixLen_fnum+0
	MOVF       R0+1, 0
	MOVWF      FARG_FloatToStr_FixLen_fnum+1
	MOVF       R0+2, 0
	MOVWF      FARG_FloatToStr_FixLen_fnum+2
	MOVF       R0+3, 0
	MOVWF      FARG_FloatToStr_FixLen_fnum+3
	MOVLW      main_res_print_L0+0
	MOVWF      FARG_FloatToStr_FixLen_str+0
	MOVLW      10
	MOVWF      FARG_FloatToStr_FixLen_len+0
	CALL       _FloatToStr_FixLen+0
;Test_01.c,183 :: 		Lcd_Out(2,1,"NTC ");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr2_Test_01+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Test_01.c,184 :: 		Lcd_Out(2,5,res_print);
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      5
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      main_res_print_L0+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Test_01.c,185 :: 		delay_ms(1);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main27:
	DECFSZ     R13+0, 1
	GOTO       L_main27
	DECFSZ     R12+0, 1
	GOTO       L_main27
;Test_01.c,187 :: 		t_get = get_temp_RBM(adc_get);
	MOVF       main_adc_get_L0+0, 0
	MOVWF      FARG_get_temp_RBM_ADC+0
	MOVF       main_adc_get_L0+1, 0
	MOVWF      FARG_get_temp_RBM_ADC+1
	MOVF       main_adc_get_L0+2, 0
	MOVWF      FARG_get_temp_RBM_ADC+2
	MOVF       main_adc_get_L0+3, 0
	MOVWF      FARG_get_temp_RBM_ADC+3
	CALL       _get_temp_RBM+0
	CALL       _int2double+0
;Test_01.c,188 :: 		FloatToStr_FixLen(t_get/10, temp_print,5);
	MOVLW      0
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVLW      32
	MOVWF      R4+2
	MOVLW      130
	MOVWF      R4+3
	CALL       _Div_32x32_FP+0
	MOVF       R0+0, 0
	MOVWF      FARG_FloatToStr_FixLen_fnum+0
	MOVF       R0+1, 0
	MOVWF      FARG_FloatToStr_FixLen_fnum+1
	MOVF       R0+2, 0
	MOVWF      FARG_FloatToStr_FixLen_fnum+2
	MOVF       R0+3, 0
	MOVWF      FARG_FloatToStr_FixLen_fnum+3
	MOVLW      main_temp_print_L0+0
	MOVWF      FARG_FloatToStr_FixLen_str+0
	MOVLW      5
	MOVWF      FARG_FloatToStr_FixLen_len+0
	CALL       _FloatToStr_FixLen+0
;Test_01.c,189 :: 		Lcd_Out(1,10,"T ");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      10
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr3_Test_01+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Test_01.c,190 :: 		Lcd_Out(1,12,Temp_print);
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      12
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      main_temp_print_L0+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Test_01.c,191 :: 		delay_ms(1);
	MOVLW      7
	MOVWF      R12+0
	MOVLW      125
	MOVWF      R13+0
L_main28:
	DECFSZ     R13+0, 1
	GOTO       L_main28
	DECFSZ     R12+0, 1
	GOTO       L_main28
;Test_01.c,193 :: 		}
	GOTO       L_main24
;Test_01.c,194 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
