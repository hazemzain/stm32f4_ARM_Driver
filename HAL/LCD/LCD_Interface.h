/*========================================================================================
===========================   -LCD_interface.h    =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/

#ifndef LCD_H_
#define LCD_H_


/*******************************************_MACROS_********************************************/
#define _8_BIT_MODE                1
#define _4_BIT_MODE                2
#define NULL_                    '\0'

/*****************************************_PROTOTYPES_******************************************/
void H_Lcd_Init(void);
void H_Lcd_WriteCharacter(u8);
void H_Lcd_WriteCommand(u8);
void H_Lcd_WriteString(u8*);
void H_Lcd_WriteNum(s32);
void H_Lcd_Clr(void);
void H_Lcd_GoTo(u8,u8);
void H_Lcd_ClockDisplay(u8,u8,u8);
#endif /* LCD_H_ */
