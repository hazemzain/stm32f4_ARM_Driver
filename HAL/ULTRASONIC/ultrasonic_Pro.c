 /*========================================================================================
===========================   - Ultra Sonic_Prog.c		     =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
	#define ARM_MATH_CM4

	#include "STD_TYPES.h"
	#include"BIT_MATH.h"
	#include "Delay_interface.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
	#include "RCC_Interface.h"
	#include "GPIO_Interface.h"
 	#include "TIMER2_Private.h"
	#include "LCD_Interface.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/
	#include "Ultrasomic_Interface.h"
	#include "Ultrasonic_Private.h"
	#include "Ultrasonic_Cfg.h"

/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/



static void TIM2_us_Delay(u32 delay){
	MRCC->APB1ENR |=1; //Start the clock for the timer peripheral
	TIM2->ARR = (int)(delay/0.0625); // Total period of the timer
	TIM2->CNT = 0;
	TIM2->CR1 |= 1; //Start the Timer
	while(!(TIM2->SR & TIM_SR_UIF)){} //Polling the update interrupt flag
	TIM2->SR &= ~(0x0001); //Reset the update interrupt flag
}

void H_VUltrasonicInit(){
	//Configuring PA5 for generating pulse sent to trig pin
	MGPIO_vSetPinMode(TRIGER_PORT ,TRIGER_PIN, MODE_OUTPUT); //Set the PA5 pin to output mode->    P8->16
	//Configuring output from echo pin to be sent to the board (PA6 pin)
	MGPIO_vSetPinMode(ECHO_PORT ,ECHO_PIN ,MODE_INPUT); //Set PA6 to input mode
	
}

u32  H_u16USRead(void)
{
	u32 data =0 ,dist;
	f64 time;

	  MGPIO_vWriteDataDIR(TRIGER_PORT ,TRIGER_PIN,_LOW); // Make PA5 low again
	  TIM2_us_Delay(10);
	  MGPIO_vWriteDataDIR(TRIGER_PORT ,TRIGER_PIN,_HIGH);//PA5 set to High
	  TIM2_us_Delay(10);// wait for 10us
	  MGPIO_vWriteDataDIR(TRIGER_PORT ,TRIGER_PIN,_LOW);

 //2. Measure the pulse width of the pulse sent from the echo pin by polling IDR for port A
	  
	while(!MGPIO_u8ReadData(ECHO_PORT,ECHO_PIN));
	while(MGPIO_u8ReadData(ECHO_PORT,ECHO_PIN))
	 
	  {
		data = data+1;
	  }

	//3.Converting the gathered data into distance in cm
	 if (data>0)
	 {
		 time = (data*(0.0625*0.000001));
		 dist = (((time*340000.0)/2)* 1.75);

	 }

    return dist;
}
