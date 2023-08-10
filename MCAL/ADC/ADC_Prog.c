/*========================================================================================
===========================   - ADC_program.c		     =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/


/*===========   INCLUDE LIB   ===========*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "ADC_Cfg.h"
#define _NULL   (void *)0
/*======================================*/

static ADC_Control_t  ADC_Control;

static void (* (SG_Arr_AdcMode [7]))(void);


void M_AdcInit(AdcModeOperatin_t Copy_eAdcModeOperation )
{
	ADC_Control.ADC_Mode = _ADC_DISABLE_MODE ;
	#if ADC_ENABLE_MODE  == ADC_ENABLE

		ADC_CCR &= 0xFF3FFFFF;
		ADC_CCR |= (ADC_PRESCALER<<16);

		ADC_Control.SG_u8RegularSequenerIndex  =0 ;
		ADC_Control.SG_u8InjectedSequenerIndex =0 ;
		MADC1 -> CR1_.CR1.RES =  ADC_RESOLUTION ;     // ADC xbit reseloution
		MADC1 -> CR2_.CR2.ALIGN= ADC_DATA_ALIGMENT  ; // ADC_ alignment
		SG_Arr_AdcMode [0] = MAdc_vAdcInitMode;
		SG_Arr_AdcMode [1] = MAdc_vSingleRegulerMode;
		SG_Arr_AdcMode [2] = MAdc_vSingleRegulerContinuousMode;
		SG_Arr_AdcMode [3] = MAdc_vScanRegulerOnceMode;
		SG_Arr_AdcMode [4] = MAdc_v_ScanRegulerContinuousMode;
		SG_Arr_AdcMode [5] = MAdc_vScanInjectedOnce;
		SG_Arr_AdcMode [0]();
		ADC_Control.ADC_Mode = (u8)Copy_eAdcModeOperation;
		SG_Arr_AdcMode [0]();
		if ( Copy_eAdcModeOperation != 0)
		{
			SG_Arr_AdcMode [Copy_eAdcModeOperation]();
		}
		else
		{
			/*error*/
		}
		
		MADC1 -> CR2_.CR2.ADON = (1U);
		
	#endif
	
}

void MADC_vChangeModeOperation(AdcModeOperatin_t Copy_eAdcModeOperation)// review if i shoud wait
{
	if(ADC_Control.ADC_Mode != _ADC_DISABLE_MODE )
	{
		SG_Arr_AdcMode [0]();
		if ( Copy_eAdcModeOperation != 0)
		{
			SG_Arr_AdcMode [Copy_eAdcModeOperation]();
		}
		
	}
	
	else
	{
		/*error*/
	}
}


void M_AdcEnable(void)
{

	MADC1 ->  CR2_.CR2.ADON =(1U);
}

void M_AdcDisable(void)
{
		MADC1 ->  CR2_.CR2.ADON =(0U);
}
/*Interrupt*/
void M_AdcStartConv(AdcMode_t u8_CopyAdcMode)
{
	switch(u8_CopyAdcMode){
		
		case ADC_MODE_REGULAR  : MADC1 -> CR2_.CR2.SWSTART   =  (1U) ; break;
		case ADC_MODE_INJECTED : MADC1 -> CR2_.CR2. JSWSTART =  (1U) ; break;
		default :													   break;
				
	}
}
/**********/

/*****************/
void M_Adc1StopConv(Channel_t Copy_u8ChannelType)
{
	MADC1 -> CR2_.CR2. ADON =  (0U) ;
}
/***************/
 /* work on two case reguler scan ||cont Scan  active mode  */
RegularSequence_t  M_AdcRegular_Sequance(Channel_t Copy_eChannelType , RegularSequence_t Copy_eSequenceNum)
{  

	// if -> check the mode :

		   u8  L_u8_Index1, L_u8_Index2, L_u8SeqReturn =0xFF;
		   
	if ( (Copy_eSequenceNum <= ADC_Control.SG_u8RegularSequenerIndex)&&(Copy_eSequenceNum >=0)&&(Copy_eSequenceNum <16))
	{
		L_u8_Index1 = 2 -( Copy_eSequenceNum /6) ;
		L_u8_Index2 =  Copy_eSequenceNum %6 ;
		MADC1 -> SQR[L_u8_Index1] &=  (~(((u32 )0x0000001F)<<(5* L_u8_Index2)));
		MADC1 -> SQR[L_u8_Index1] |= Copy_eChannelType << (5* L_u8_Index2);
		
		if  (Copy_eSequenceNum == ADC_Control.SG_u8RegularSequenerIndex)
		{
			ADC_Control.SG_u8RegularSequenerIndex ++;
			MADC1 -> SQR[0] &=  (~((u32 )0x00F00000));
			MADC1 -> SQR[0] |=  ((u32) Copy_eSequenceNum )<< 20 ;
		}
		L_u8SeqReturn = Copy_eSequenceNum; // if add or adjust is happen return the request ID
	}
	else{
		
		/*error */
		
	}
	// end the check of the mode
	return L_u8SeqReturn ;
}

/**************************************************************************************/


InjectedSequence_t  M_AdcInjected_Sequance(Channel_t Copy_eChannelType , InjectedSequence_t Copy_eSequenceNum)
{  

	// if -> check the mode :
	
	
	u8  L_u8SeqReturn=0xFF;

	if ( (Copy_eSequenceNum <= ADC_Control.SG_u8InjectedSequenerIndex)&&(Copy_eSequenceNum >=0)&&(Copy_eSequenceNum <4))
	{
		
		MADC1 -> JSQR  &=  (~(((u32 )0x0000001F)<< (5 * (3-Copy_eSequenceNum))));
		MADC1 -> JSQR  |=  Copy_eChannelType    << (5 *(3- Copy_eSequenceNum));
		

		if  (Copy_eSequenceNum == ADC_Control.SG_u8InjectedSequenerIndex)
		{
			ADC_Control.SG_u8InjectedSequenerIndex ++;
			MADC1 -> JSQR &=  (((u32 )0xFFCFFFFF));
			MADC1 -> JSQR |=  ((u32) Copy_eSequenceNum )<< 20 ;

		}
		L_u8SeqReturn = Copy_eSequenceNum; // if add or adjust is happened return the request ID

	}
	else{
		
		/*error */
		
	}
	// end the check of the mode
	return L_u8SeqReturn ;
}

void MADC_InjectedRead(u16 * Copy_u16Ptr)
{
	#if (1)
	/*reguler single -DisCont by software*/
	//	MADC1 -> CR1_.CR1.JAUTO =  (0U) ;

		MADC1 -> CR2_.CR2.JSWSTART =  (1U) ;

		while (MADC1 ->SR_ .SR.JEOC == 0)
		{


		}
	//	MGPIO_vWriteData(0,0,1);


		*Copy_u16Ptr = MADC1 -> JDR[0];
	/*************************/
	#endif
	
	/**************************************************/
	
	#if(0)
	/*reguler single -Cont by software by interrupt*/
	/*in reguler call function //*/
	MADC1 -> CR2_.CR2.SWSTART =  (1U) ;
	
	/*after each conversion is end the interrupt accure and shoud serve  preffered to be an array that take data*/
	*Copy_u16Ptr = MADC1 -> DR;
	/*****************************************/
	#endif
	
	/*****************************************/
	
}


void MADC_RegulerRead(u16 * Copy_u16Ptr)
{
	#if (1)
	/*reguler single -DisCont by software*/
		MADC1 -> CR2_.CR2.SWSTART =  (1U);
		while (MADC1 ->SR_ .SR.EOC ==0);
		*Copy_u16Ptr = MADC1 -> DR;
	/*************************/
	#endif
	
	/**************************************************/
	
	#if(0)
	/*reguler single -Cont by software by interrupt*/
	/*in reguler call function //*/
	MADC1 -> CR2_.CR2.SWSTART =  (1U) ;
	
	/*after each conversion is end the interrupt accure and shoud serve  preffered to be an array that take data*/
	*Copy_u16Ptr = MADC1 -> DR;
	/*****************************************/
	#endif
	
	/*****************************************/
	
}
void MADC_RegulerScan(u16 * Copy_u16Ptr , u8* Copy_u8TotalConversion_nu)
{
	#if (1)
	u8 L_u8Size=0;
	if ( ADC_Control.SG_u8RegularSequenerIndex > 0 &&  ADC_Control.SG_u8RegularSequenerIndex < 16 )
	{
		// once  scan
		
		if( ADC_Control.SG_u8RegularSequenerIndex >= *Copy_u8TotalConversion_nu )
		{
			MADC1 -> SQR[0] &=  (~((u32 )0x00F00000));
			MADC1 -> SQR[0] |=  ((u32) (*Copy_u8TotalConversion_nu-1 ))<< 20 ;

		}
		else
		{
			MADC1 -> SQR[0] &=  (~((u32 )0x00F00000));
			MADC1 -> SQR[0] |=  ((u32) (ADC_Control.SG_u8RegularSequenerIndex))<< 20 ;
			*Copy_u8TotalConversion_nu = ADC_Control.SG_u8RegularSequenerIndex;
			
		}
		MADC1 -> CR2_.CR2.SWSTART =  (1U) ;
		
		for (; L_u8Size < *Copy_u8TotalConversion_nu  ; L_u8Size ++)
		{
			while (MADC1 ->SR_ .SR.EOC ==0);
			Copy_u16Ptr [ L_u8Size]= MADC1 -> DR;
		}
	
	}
	
	else 
	{
		/* error -> empty */
	}
	#endif
	#if (0)
	//reguler scan cont-
		//-in function call */ // Need some control Parmeter
		if ( SG_u8RegularSequenerIndex > 0 &&  SG_u8RegularSequenerIndex < 16 )
	{
		
		if( SG_u8RegularSequenerIndex <= Copy_u8TotalConversion_nu )
		{
			MADC1 -> SQR[0] &=  (~((u32 )0x00F00000));
			MADC1 -> SQR[0] |=  ((u32) (Copy_u8TotalConversion_nu-1 ))<< 20 ;
			
		}
		MADC1 -> CR2_.CR2.SWSTART =  (1U) ;
		}
	
		else 
		{
			/* error -> empty */
		}
	
		
		/************* in INT *///
		
		// globle var static take add of array (shoud buffer twice and address of size */
			// clear register 
		GS_arr[GS_ContScanSize] = MADC1 -> DR;
		 GS_ContScanSize ++;
		/*********************************************/	
		#endif 
			

}

void MADCInjectedScan(u16 * Copy_u16Ptr, u8 Copy_u8TotalConversion_nu)
{
	#if (1)
	u8 L_u8Size=0;
	if ( ADC_Control.SG_u8InjectedSequenerIndex > 0 &&  ADC_Control.SG_u8InjectedSequenerIndex< 4 )
	{
		// once  scan
		
		if( ADC_Control.SG_u8InjectedSequenerIndex <= Copy_u8TotalConversion_nu )
		{
			MADC1 -> JSQR &=  (~((u32 )0x00300000));
			MADC1 -> JSQR |=  ((u32) (Copy_u8TotalConversion_nu-1 ))<< 20 ;
			
		}
		MADC1 -> CR2_.CR2.JSWSTART =  (1U) ;
		for (; L_u8Size < Copy_u8TotalConversion_nu  ; L_u8Size ++)
		{
			
			while (MADC1 ->SR_ .SR.JEOC == 0);

			Copy_u16Ptr [ L_u8Size]= MADC1 -> JDR[L_u8Size];

		}
			
	}
	
	else 
	{
		/* error -> empty */
	}
	#endif
	
			

}


void M_Adc1SetCallBack(void (* ptr)(void) , AdcIntId_t Copy_u8eSetCall)
{
	
	if(ptr != _NULL)
	{
		ADC_Control.ADC_SetCallBackArr[Copy_u8eSetCall] = ptr;
	}
	else 
	{
	}
}


/***************** static fn************/
void MAdc_vAdcInitMode(void)
{
	MADC1 -> CR1_.CR1.SCAN   = (0U); 
	MADC1 -> CR2_.CR2.EOCS   = (0U) ;
	MADC1 ->  CR2_.CR2.EXTEN = (0U);
	MADC1 -> CR2_.CR2.CONT	 = (0U);
	MADC1 -> CR1_.CR1.DISCEN = (0U); 
}
static void MAdc_vSingleRegulerMode(void)
{

	MADC1 -> CR2_.CR2.EOCS   = (1U) ; 	 // GET FLAG at each channel conversion 
	//MADC1 -> CR1_.CR1.SCAN   = (0U);    // disable scan mode 
	//MADC1 ->  CR2_.CR2.EXTEN = (0U);	// disable external trigger
	//MADC1 -> CR2_.CR2.CONT	 = (0U);	//Continuous conversion Disable 
	//MADC1 -> CR1_.CR1.DISCEN = (0U);    //Disable Discontinuous mode // important 
	
}

static void MAdc_vSingleRegulerContinuousMode(void)
{
	
	MADC1 -> CR2_.CR2.EOCS   = (1U) ;      // GET FLAG at each channel conversion 
	MADC1 -> CR2_.CR2.CONT	 = (1U);     //Continuous conversion Enable 
	//MADC1 -> CR1_.CR1.SCAN   = (0U);        // disable scan mode 
	//MADC1 -> CR2_.CR2.EXTEN  = (0U);	  // DISable external trigger
	//MADC1 -> CR1_.CR1.DISCEN = (0U);     // Disable Discontinuous mode // important 
	
}

static void MAdc_vScanRegulerOnceMode(void)
{			
	MADC1 -> CR1_.CR1.SCAN   =(1U);       // enable scan mode 
	MADC1 -> CR2_.CR2.EOCS   =(1U) ;     // GET FLAG at each channel conversion  
	//MADC1 -> CR2_.CR2.CONT	 =(0U);		//Continuous conversion Disable 
	//MADC1 -> CR2_.CR2.EXTEN = (0U);	   // DISable external trigger
	//MADC1 -> CR1_.CR1.DISCEN =(0U);   // Disable Discontinuous mode // important 
}
static void MAdc_v_ScanRegulerContinuousMode(void)		
{		
			MADC1 -> CR1_.CR1.SCAN   =(1U);	// enable scan mode 
			MADC1 -> CR2_.CR2.EOCS   =(1U) ;  // GET FLAG at each channel conversion 
			MADC1 -> CR2_.CR2.CONT	 =(1U); // Enable Continuous conversion  
			//MADC1 -> CR2_.CR2.EXTEN  =(0U);	  // Disable external trigger
			//MADC1 -> CR1_.CR1.DISCEN =(0U); // Disable Discontinuous mode // important 
}

static void MAdc_vScanInjectedOnce (void)
{
	MADC1 -> CR1_.CR1.SCAN   =(1U); 			// enable scan mode 
}
