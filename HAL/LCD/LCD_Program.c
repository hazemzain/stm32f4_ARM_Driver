/*========================================================================================
===========================   - Lcd_Program.c		     =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/

/*============= INCLUDE LIB ==============*/
	 #include  "STD_TYPES.h"
	 #include  "BIT_MATH.h"

/*========================================*/
/*===========  INCLUDE MCAL  ===========*/
	#include "GPIO_Interface.h"
	#include "LCD_Privet.h"
	#include "LCD_Interface.h"
	#include "LCD_Cfg.h"
	#include "Delay_interface.h"
/*======================================*/


void H_Lcd_Init(void)
{
	#if    LCD_MODE       ==     _8_BIT_MODE
	
		for ( u8 Counter = LCD_DATA_START_PIN ;Counter<LCD_DATA_START_PIN +LCD_DATA_TOTAL_PIN ; Counter ++)
		{
			MGPIO_vSetPinMode(LCD_DATA_PORT,Counter,MODE_OUTPUT);
			MGPIO_vSetPinOutPutType(LCD_DATA_PORT,Counter,_OUTPUT_TYPE_PUSH_PUL);
			MGPIO_vSetPinOutSpeed(LCD_DATA_PORT,Counter,_OUTPUT_SPEED_MEDUIM);
			MGPIO_vSetPullType(LCD_DATA_PORT,Counter,_PULL_OFF);
		}
		for ( u8 Counter = LCD_CONTROL_START_PIN ;Counter < LCD_CONTROL_START_PIN +LCD_CONTROL_TOTAL_PIN ; Counter ++)
				{
					MGPIO_vSetPinMode(LCD_CONTROL_PORT,Counter,MODE_OUTPUT);
					MGPIO_vSetPinOutPutType(LCD_CONTROL_PORT,Counter,_OUTPUT_TYPE_PUSH_PUL);
					MGPIO_vSetPinOutSpeed(LCD_CONTROL_PORT,Counter,_OUTPUT_SPEED_MEDUIM);
					MGPIO_vSetPullType(LCD_CONTROL_PORT,Counter,_PULL_OFF);
				}

			Delay_vMsIn16MHz(1000);
			
			H_Lcd_WriteCommand(_8_BIT_MODE_COMMAND);
			H_Lcd_WriteCommand(LCD_DIS_ON_CUR_OFF);
			H_Lcd_WriteCommand(LCD_CLR);
			H_Lcd_WriteCommand(LCD_RETURN_HOME);
	
	#elif  LCD_MODE       ==     _4_BIT_MODE
	
	for ( u8 Counter = LCD_DATA_START_PIN ;Counter < LCD_DATA_START_PIN +LCD_DATA_TOTAL_PIN ; Counter ++)
		{
			MGPIO_vSetPinMode(LCD_DATA_PORT,Counter,MODE_OUTPUT);
			MGPIO_vSetPinOutPutType(LCD_DATA_PORT,Counter,_OUTPUT_TYPE_PUSH_PUL);
			MGPIO_vSetPinOutSpeed(LCD_DATA_PORT,Counter,_OUTPUT_SPEED_MEDUIM);
			MGPIO_vSetPullType(LCD_DATA_PORT,Counter,_PULL_OFF);
		}

	for ( u8 Counter = LCD_CONTROL_START_PIN ;Counter<LCD_CONTROL_START_PIN +LCD_CONTROL_TOTAL_PIN ; Counter ++)
		{
			MGPIO_vSetPinMode(LCD_CONTROL_PORT,Counter,MODE_OUTPUT);
			MGPIO_vSetPinOutPutType(LCD_CONTROL_PORT,Counter,_OUTPUT_TYPE_PUSH_PUL);
			MGPIO_vSetPinOutSpeed(LCD_CONTROL_PORT,Counter,_OUTPUT_SPEED_MEDUIM);
			MGPIO_vSetPullType(LCD_CONTROL_PORT,Counter,_PULL_OFF);
		}


	Delay_vMsIn16MHz(1000);
	H_Lcd_WriteCommand(0x33);
	H_Lcd_WriteCommand(0x32);
	H_Lcd_WriteCommand(0x28);
	H_Lcd_WriteCommand(LCD_DIS_ON_CUR_OFF);
	H_Lcd_WriteCommand(LCD_CLR);
	H_Lcd_WriteCommand(LCD_RETURN_HOME);	
	#endif
}
void H_Lcd_WriteCharacter(u8 Local_u8_Character)
{
	#if  LCD_MODE       ==      _8_BIT_MODE
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_RW_PIN,_LOW);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_RS_PIN,_HIGH);  // LOW
	MGPIO_vPortOutputOneByte (LCD_DATA_PORT,Local_u8_Character,LCD_DATA_START_PIN);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_EN_PIN,_HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_EN_PIN,_LOW);
	Delay_vMsIn16MHz(5);
	
	#elif  LCD_MODE       ==     _4_BIT_MODE  
	u8 L_u8Data;
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_RW_PIN,_LOW);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_RS_PIN,_HIGH);
	L_u8Data = MGPIO_vPortReadOneByte(LCD_DATA_PORT,LCD_DATA_START_PIN);
	L_u8Data &= (0xF0);
	MGPIO_vPortOutputOneByte (LCD_DATA_PORT,((Local_u8_Character >>4)|L_u8Data),LCD_DATA_START_PIN);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_EN_PIN,_HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_EN_PIN,_LOW);
	Delay_vMsIn16MHz(3);
	L_u8Data = MGPIO_vPortReadOneByte(LCD_DATA_PORT,LCD_DATA_START_PIN);
	L_u8Data &=0xF0 ;
	MGPIO_vPortOutputOneByte (LCD_DATA_PORT,((Local_u8_Character & 0x0F)|L_u8Data) ,LCD_DATA_START_PIN);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_EN_PIN,_HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_EN_PIN,_LOW);
	Delay_vMsIn16MHz(3);
	#endif
}
void H_Lcd_WriteCommand(u8 Local_u8_Command)
{
	#if  LCD_MODE       ==     _8_BIT_MODE
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_RW_PIN,_LOW);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_RS_PIN,_LOW);                  // 0,1
	MGPIO_vPortOutputOneByte (LCD_DATA_PORT,Local_u8_Command,LCD_DATA_START_PIN);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_EN_PIN,_HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_EN_PIN,_LOW);
	Delay_vMsIn16MHz(5);
	#elif  LCD_MODE       ==     _4_BIT_MODE
	u8 L_u8Data;
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_RW_PIN,_LOW);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_RS_PIN,_LOW);

	L_u8Data = MGPIO_vPortReadOneByte(LCD_DATA_PORT,LCD_DATA_START_PIN);
	L_u8Data &=0xF0 ;
	MGPIO_vPortOutputOneByte (LCD_DATA_PORT, ((Local_u8_Command >>4)|L_u8Data),LCD_DATA_START_PIN);


	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_EN_PIN,_HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_EN_PIN,_LOW);
	Delay_vMsIn16MHz(3);

	L_u8Data = MGPIO_vPortReadOneByte(LCD_DATA_PORT,LCD_DATA_START_PIN);
	L_u8Data &=0xF0;
	MGPIO_vPortOutputOneByte (LCD_DATA_PORT, ((Local_u8_Command & 0x0F)|L_u8Data),LCD_DATA_START_PIN);

	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_EN_PIN,_HIGH);
	Delay_vMsIn16MHz(1);
	MGPIO_vWriteData(LCD_CONTROL_PORT,LCD_EN_PIN,_LOW);
	Delay_vMsIn16MHz(3);
	#endif
}
void H_Lcd_WriteString(u8*Local_u8_Ptr)
{
	u8 Local_u8_Counter = 0;
	while(Local_u8_Ptr[Local_u8_Counter] != NULL_)
	{
		//New add
		if(Local_u8_Counter == 16)
			H_Lcd_GoTo(1,0);
			
		//
		H_Lcd_WriteCharacter(Local_u8_Ptr[Local_u8_Counter]);
		Local_u8_Counter++;
	}	
}

void H_Lcd_WriteNum(s32 Local_S32_Num)
{
	u8 Local_u8_Unit=0;
	u8 Local_u8_arr[20]={0};
	s8 Local_S8_Counter=0;
	if(Local_S32_Num==0)
	{
		H_Lcd_WriteCharacter('0');
	}
	else 
	{
		if(Local_S32_Num<0)
		{
			H_Lcd_WriteCharacter('_');
			Local_S32_Num=Local_S32_Num * -1;
		}
		
	}
	while(Local_S32_Num!=0)
	{
		Local_u8_Unit=Local_S32_Num % 10;
		Local_u8_arr[Local_S8_Counter]=Local_u8_Unit;
		Local_S8_Counter++;
		Local_S32_Num=Local_S32_Num/10;
	}
	Local_S8_Counter--;
	while(Local_S8_Counter>=0)
	{
		H_Lcd_WriteCharacter(Local_u8_arr[Local_S8_Counter]+48);
		Local_S8_Counter--;
	}
}

void H_Lcd_Clr(void)
{
	H_Lcd_WriteCommand(LCD_CLR);
}

void H_Lcd_GoTo(u8 Local_u8_Row,u8 Local_u8_Col)
{
	u8 Local_u8_arr [2] = {0x80,0xC0};
	H_Lcd_WriteCommand(Local_u8_arr[Local_u8_Row] + Local_u8_Col);
}
/*
void H_Lcd_ClockDisplay(u8,u8,u8)
{
	
}
*/
