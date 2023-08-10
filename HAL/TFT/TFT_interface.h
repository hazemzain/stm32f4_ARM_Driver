/*========================================================================================
===========================   - TFT_Interface.h    =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/
/*=====================================================================================
		* What i sell To Customer
		*  The Archictect Give The API	
						- The Name Of Function 
						- What is The Input 
						- What Is The Output
						- Macro 
						 
======================================================================================*/ 

/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/


#ifndef _INTERFACE_H
#define _INTERFACE_H

/*===========   INCLUDE LIB   ===========*/
		 #include  "STD_TYPES.h"
	 	 #include  "BIT_MATH.h"
		 #include "Delay_interface.h"

/*======================================*/
/*===========  INCLUDE MCAL  ===========*/

#define sleep_out_command 0x11
#define color_Mode_Command 0x3A
#define x_aderess   0x2A
#define y_aderess   0x2B





void HTFT_voidInit(void);
void HTFT_vSetCursorPosition(u16 X_Start, u16 Y_Start, u16 X_End, u16 Y_End);
void HTFT_voidDisplayImage(const u16* Copy_Image);

/***************************_picture_*******************************/
void HTFT_vWelcome(void);
void HTFT_vDoor_Close(void);
void HTFT_vDoor_Open(void);
void HTFT_vAirConditioner_close(void);
void HTFT_vAirConditioner_open(void);
void HTFT_Go_Car(void);
void HTFT_Stop_Car(void);




#endif //RCC_INTERFACE_H
