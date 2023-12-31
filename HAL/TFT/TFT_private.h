/*========================================================================================
===========================   - TFT_private.h    =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/

/*=====================================================================================
===================    guard of file will call on time in .c	    ===================
=======================================================================================*/ 

#ifndef _PRIVATE_H
#define _PRIVATE_H

static void voidWriteCommand(u8 Copy_u8Command);
static void VoidWriteData(u16 Copy_u8Data);
static void HTFT_vDisplay_Image(const u16* Copy_Image);
static void TFT_vDrawPic(u8 x1,u8 x2,u16 y1,u16 y2,const u16* Copy_Image);

#endif 
