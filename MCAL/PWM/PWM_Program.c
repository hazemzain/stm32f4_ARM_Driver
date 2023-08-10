 /*========================================================================================
===========================   - Project_Prog.c		     =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		#include "STD_TYPES.h"
		#include"BIT_MATH.h"
		#include "Delay_interface.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "PWM_Interface.h"
/*======================================*/

u32 G_u32OnTime;
u32 G_u32OffTime;
u8  G_u8PinNum;



void Generate_PWM(u8 Copy_u16DutyCyclePercent, u32 Copy_u32PeriodInMilli, u8 Copy_ChoosePin)
{
	G_u32OnTime = ((Copy_u16DutyCyclePercent * 10) * Copy_u32PeriodInMilli); //Percentage of duty times 10 to handle the floating numbers
	G_u32OffTime = (Copy_u32PeriodInMilli*1000) - G_u32OnTime;
	G_u8PinNum = Copy_ChoosePin;
	MSTK_vSetIntervalPeriodic(G_u32OffTime , ON_PWM);
}

void ON_PWM(void)
{
	MGPIO_vWriteData(_GPIOB_PORT, G_u8PinNum, _HIGH);
	MSTK_vSetIntervalPeriodic(G_u32OffTime, OFF_PWM);
}

void OFF_PWM(void)
{
	MGPIO_vWriteData(_GPIOB_PORT, G_u8PinNum, _LOW);
	MSTK_vSetIntervalPeriodic(G_u32OnTime , ON_PWM);
}

void Stop_PWM(void)
{
	MSTK_voidStopInterval();
}



