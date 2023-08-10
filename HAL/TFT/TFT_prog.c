 /*========================================================================================
===========================   - TFT_Prog.c		     =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/

/*=======================================================================================
============================   The Foundation Of Function   ============================= 
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		#include  "STD_TYPES.h"
	 	 #include  "BIT_MATH.h"
		 #include "Delay_interface.h"

/*======================================*/	 
/*===========  INCLUDE MCAL  ===========*/
		#include"RCC_interface.h"
		#include"GPIO_Interface.h"
		#include"SPI_interface.h"
		#include"STK_interface.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
		#include"TFT_interface.h"
		#include"TFT_config.h"
		#include"TFT_private.h"
/*======================================*/	
/*===========  INCLUDEAPP   ===========*/

		#include "Picture.h"
		#include "welcome.h"
 /*=====================================*/




/*====================================================   Start_FUNCTION   ====================================================*/
 void HTFT_voidInit(void)
 {
	   /*set Pin configuration for spi and tft */
	 	MGPIO_vSetPinMode(TFT_A0_PIN,MODE_OUTPUT); /*A0*/
	 	MGPIO_vSetPinOutPutType(TFT_A0_PIN,_OUTPUT_TYPE_PUSH_PUL);
	 	MGPIO_vSetPinOutSpeed(TFT_A0_PIN,_OUTPUT_SPEED_LOW);

	 	MGPIO_vSetPinMode(TFT_RST_PIN,MODE_OUTPUT);//RES
	 	MGPIO_vSetPinOutPutType(TFT_RST_PIN,_OUTPUT_TYPE_PUSH_PUL);
	 	MGPIO_vSetPinOutSpeed(TFT_RST_PIN,_OUTPUT_SPEED_LOW);

		MGPIO_vSetPinMode(SCK_PIN,MODE_ALTF);/*SPI CLK*/
		MGPIO_vSetPinAltFn(SCK_PIN,ALTF_5);
		MGPIO_vSetPinOutPutType(SCK_PIN,_OUTPUT_TYPE_PUSH_PUL);
		MGPIO_vSetPinOutSpeed(SCK_PIN,_OUTPUT_SPEED_VERY_HIGH);

		MGPIO_vSetPinMode(MOSI_PIN,MODE_ALTF);/*MOSI*/
		MGPIO_vSetPinAltFn(MOSI_PIN,ALTF_5);
		MGPIO_vSetPinOutPutType(MOSI_PIN,_OUTPUT_TYPE_PUSH_PUL);
		MGPIO_vSetPinOutSpeed(MOSI_PIN,_OUTPUT_SPEED_VERY_HIGH);

		/*init Systic for delay*/
		//MSTK_vInit();
		/*init Spi*/
		//SPI_vInit();

		/*RESET PULSE*/
		  MGPIO_vWriteData(TFT_RST_PIN,_HIGH);
		  MSTK_vBusyWait(100);
		  MGPIO_vWriteData(TFT_RST_PIN,_LOW);
		  MSTK_vBusyWait(1);
		  MGPIO_vWriteData(TFT_RST_PIN,_HIGH);
		  MSTK_vBusyWait(100);
		  MGPIO_vWriteData(TFT_RST_PIN,_LOW);
		  MSTK_vBusyWait(100);
		  MGPIO_vWriteData(TFT_RST_PIN,_HIGH);
		  MSTK_vBusyWait(120000);

		  /*Sleep Out Command */
		  voidWriteCommand(sleep_out_command);

		  /*Wait 150 ms*/
		  MSTK_vBusyWait(150000);

		  /*Color Mode Command*/
		  voidWriteCommand(color_Mode_Command);
		  /*RGB 565*/
		  VoidWriteData(0x05);

		  /*Display On Command*/
		  voidWriteCommand(0x29);

 }
/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
 void HTFT_vSetCursorPosition(u16 X_Start, u16 Y_Start, u16 X_End,u16 Y_End)
 {
	 /*Set X Address*/
 	voidWriteCommand(x_aderess);
 	/*Start Bit X coordinates*/
 	VoidWriteData(X_Start >>8);      		/* higher byte*/
 	VoidWriteData(X_Start & 0x00ff);		/* lower Byte */
 	/*End Bit X coordinates*/
 	VoidWriteData(X_End >>8);          /*send higher byte*/
 	VoidWriteData(X_End & 0x00ff);    /*send lower Byte */

 	/*Set Y Address*/
 	voidWriteCommand(y_aderess);
 	/*Start Bit Y coordinates*/
 	VoidWriteData(Y_Start >>8);      		/*send higher byte*/
 	VoidWriteData(Y_Start & 0x00ff);		/*send lower Byte */
 	/*End Bit Y coordinates*/
 	VoidWriteData(Y_End>>8);          /*send higher byte*/
 	VoidWriteData(Y_End & 0x00ff);    /*send lower Byte */
 }

 void HTFT_voidDisplayImage(const u16* Copy_Image)
 {
 	u32 counter = 0;
 	/*Set X Address*/
 	voidWriteCommand(x_aderess);
 	VoidWriteData(0);  //start byte 0 0
 	VoidWriteData(0);
 	VoidWriteData(0);  //END BYTE 0 127
 	VoidWriteData(239);

 	/*set Y aderess*/

 	voidWriteCommand(y_aderess);
 	VoidWriteData(0);  //start byte
 	VoidWriteData(0);
 	VoidWriteData(0);
 	VoidWriteData(319);

 	/*RAM WRITE  */
 	voidWriteCommand(0x2C);
 	for(counter =0; counter <76800 ;counter++)
 	{
 		/*write the high byte / pixel*/
 		VoidWriteData(Copy_Image[counter ]>>8);
 		/*write the low byte / pixel*/
 		VoidWriteData(Copy_Image[counter ]&0x00ff);
 	}
 }

/*====================================================   END_ FUNCTION   ====================================================*/
static void voidWriteCommand(u8 Copy_u8Command)
{

	/* set data pin to low A0*/
	MGPIO_vWriteData(TFT_A0_PIN,_LOW);
	/*send command over spi*/
	MSPI1_u16TrasRes(Copy_u8Command);
}

static void VoidWriteData(u16 Copy_u8Data)
{
	/* set data pin to high A0*/
	MGPIO_vWriteData(TFT_A0_PIN,_HIGH);
	/*send data over spi*/
	MSPI1_u16TrasRes(Copy_u8Data);
	
}
/*************************************_Drawing_Pictures_***************************************************************************/
static void TFT_vDrawPic(u8 x1,u8 x2,u16 y1,u16 y2,const u16* Copy_Image)
{
	u32 Counter ;
	u32 Local_u32Size =( x2 - x1 ) * ( y2 - y1 ) ; /*calculate image element numbers*/
	HTFT_vSetCursorPosition(x1, y1, x2, y2);		  /*set addresses of x and y */

	/* RAM Write Command Every thing is coming After This Command Display on TFT*/
	voidWriteCommand(0x2C);
	for(Counter = 0 ; Counter < Local_u32Size-5 ; Counter ++)	/*5 for protus*/
	{
		/* Write For One Pixel The High Byte Then Low Byte For Each Pixel */
		/* Write The High Byte */
		VoidWriteData(Copy_Image[Counter] >> 8);
		/* Write The LOW Byte */
		VoidWriteData(Copy_Image[Counter] & 0x00ff);
	}
}

static void HTFT_vDisplay_Image(const u16* Copy_Image)
{
	u32 Counter =0;
	u32 Local_u32Size = (240) * (320); 	/*calculate image element numbers*/
	HTFT_vSetCursorPosition(0, 0, 240, 320);    /*set addresses of x and y */

	/*Write on the Ram */
	/* RAM Write Command Every thing is comming After This Command Display on TFT*/
	voidWriteCommand(0x2C);

	for(Counter = 0 ; Counter < Local_u32Size+5; Counter ++)	/*5 for protus*/
	{
		/* Write For One Pixel The High Byte Then Low Byte For Each Pixel */
		/*write the high byte */
		VoidWriteData(Copy_Image[Counter] >> 8);
		/*write low byte*/
		VoidWriteData(Copy_Image[Counter] & 0x00ff);
	}
}

/**********************************************_Functions_*****************************************/

void HTFT_vWelcome(void)
{
	HTFT_vDisplay_Image(Welcome);
	Delay_vMsIn16MHz(1000);
}

void HTFT_vDoor_Close(void)
{
	HTFT_vDisplay_Image(Blank);
	TFT_vDrawPic(0,120,0,100, Door_Close);
}

void HTFT_vDoor_Open(void)
{
	TFT_vDrawPic(0,120,0,100, Door_Open);
}

void HTFT_vAirConditioner_close(void)
{
	TFT_vDrawPic(140,240,0,100,AirConditionar_close);
}

void HTFT_vAirConditioner_open(void)
{
	TFT_vDrawPic(140,240,0,100,AirConditionar_open);
}

void HTFT_Go_Car(void)
{
	TFT_vDrawPic(0,240,160,320,Avoiding_Sys_On);
}

void HTFT_Stop_Car(void)
{
	TFT_vDrawPic(0,240,160,320,force_ToStop);
}

