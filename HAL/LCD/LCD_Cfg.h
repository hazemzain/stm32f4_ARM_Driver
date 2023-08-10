/*========================================================================================
===========================   - LCD_Cfg.h    =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/

#ifndef LCDCFG_H_
#define LCDCFG_H_
/***************************************_SELECT_LCD_MODE_****************************************/
// option 1 -> [ _4_BIT_MODE ]
// option 2 -> [ _8_BIT_MODE ]
#define LCD_MODE         _4_BIT_MODE
/***************************************_SELECT_MC_PINS_****************************************/

/* Port option :
			 [1] ->PORT_A
			 [2] ->PORT_B
			 [3] ->PORT_C
			 [4] ->PORT_D
			 [5] ->PORT_E
			 [6] ->PORT_H
*/
/****************************PIN Option ************************/
/*
	pin option :
			[0]PIN_0
			[1]PIN_1
			[2]PIN_2
			[3]PIN_3
			[4]PIN_4
			[5]PIN_5
			[6]PIN_6
			[7]PIN_7
			[8]PIN_8
			[9]PIN_9
			[10]PIN_10
			[11]PIN_11
			[12]PIN_12
			[13]PIN_13
			[14]PIN_14
            [15]PIN_15
*/
#define LCD_DATA_PORT     	    PORT_D
#define LCD_DATA_START_PIN		PIN_4
#define LCD_DATA_TOTAL_PIN		4

#define LCD_CONTROL_PORT     	 PORT_D
#define LCD_CONTROL_START_PIN	 PIN_13
#define LCD_CONTROL_TOTAL_PIN	  3


#define LCD_EN_PIN           PIN_15
#define LCD_RS_PIN           PIN_13
#define LCD_RW_PIN           PIN_14

#endif /* LCDCFG_H_ */
