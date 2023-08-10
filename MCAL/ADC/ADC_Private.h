/*========================================================================================
===========================   - ADC_Private.h     =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/

#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

#define _ADC_BASE_ADD 0x40012000

#define ADC_DISABLE 	(0U)
#define ADC_ENABLE 		(1U)

#define ADC_INTERRUPT_ENABLE       (0U)
#define ADC_INTERRUPT_DISABLE      (1U)

typedef union {
	struct 
	{
		volatile u32 AWD	: 1;
		volatile u32 EOC    : 1;
		volatile u32 JEOC   : 1;
		volatile u32 JSTRT  : 1;
		volatile u32 STRT   : 1;
		volatile u32 OVR    : 1;
		//volatile u32 RESERVED[26];
	} SR; 
	volatile u32 SR_Reg;
	
} SR_Reg_t;

typedef union {
	struct 
	{
		volatile u32 AWDCH 		:5    ;
		volatile u32 EOCIE      :1    ;
		volatile u32 AWDIE	    :1    ;
		volatile u32 JEOCIE	    :1    ;
		volatile u32 SCAN 	    :1    ;
		volatile u32 AWDSGL     :1    ;
		volatile u32 JAUTO      :1    ;
		volatile u32 DISCEN     :1    ;
		volatile u32 JDISCEN	:1    ;
		volatile u32 DISCNUM 	:3    ;
		volatile u32 Reserved0 	:6    ;
		volatile u32 JAWDEN		:1    ;
		volatile u32 AWDEN 		:1    ;
		volatile u32 RES 		:2    ;
		volatile u32 OVRIE 		:1    ;
		volatile u32 Reserved 	:5    ;
		
	} CR1; 
	volatile u32 CR1_Reg;
	
} CR1_Reg_t;

typedef union {
	struct 
	{
		volatile u32 ADON 		:1    ;
		volatile u32 CONT	    :1    ;
		volatile u32 Reserved0 	:6    ;
		volatile u32 DMA   		:1    ;
		volatile u32 DDS	    :1    ;
		volatile u32 EOCS	    :1    ;
		volatile u32 ALIGN 	    :1    ;
		volatile u32 Reserved1 	:4    ;
		volatile u32 JEXTSEL    :4    ;
		volatile u32 JEXTEN     :2    ;
		volatile u32 JSWSTART   :1    ;
		volatile u32 Reserved2  :1	  ;
		volatile u32 EXTSEL		:4    ;
		volatile u32 EXTEN 		:2    ;
		volatile u32 SWSTART 	:1    ;
		volatile u32 Reserved3  :1	  ;	
		
	} CR2; 
	volatile u32 CR2_Reg;
	
} CR2_Reg_t;

typedef union {
	struct 
	{
		volatile u32 SQ13		:5    ;
		volatile u32 SQ14	    :5    ;
		volatile u32 SQ15 		:5    ;
		volatile u32 SQ16   	:5    ;
		volatile u32 L	   		:4    ;
		volatile u32 Reserved0  :8	  ;
		
	} SQR1; 
	volatile u32 SQR1_Reg;
	
} SQR1_Reg_t;

typedef union 
{
	struct 
	{
		volatile u32 SQ7		:5    ;
		volatile u32 SQ8	    :5    ;
		volatile u32 SQ9 		:5    ;
		volatile u32 SQ10   	:5    ;
		volatile u32 SQ11   	:5    ;
		volatile u32 SQ12   	:5    ;
		volatile u32 Reserved0  :2	  ;
		
	} SQR2; 
	volatile u32 SQR2_Reg;
	
} SQR2_Reg_t;

typedef union {
	struct 
	{
		volatile u32 SQ1		:5    ;
		volatile u32 SQ2	    :5    ;
		volatile u32 SQ3 		:5    ;
		volatile u32 SQ4	  	:5    ;
		volatile u32 SQ5    	:5    ;
		volatile u32 SQ6 	  	:5    ;
		volatile u32 Reserved0  :2	  ;
		
	} SQR3; 
	volatile u32 SQR3_Reg;
	
} SQR3_Reg_t;

typedef union {
	struct 
	{
		volatile u32 JSQ1		:5    ;
		volatile u32 JSQ2	    :5    ;
		volatile u32 JSQ3 		:5    ;
		volatile u32 JSQ4	  	:5    ;
		volatile u32 JL	    	:2    ;
		volatile u32 Reserved0  :10	  ;
		
	} JSQR; 
	volatile u32 JSQR_Reg;
	
} JSQR_Reg_t;

typedef struct
{
	SR_Reg_t SR_    	   ;
	CR1_Reg_t CR1_   	   ;
	CR2_Reg_t CR2_  	   ;
	volatile u32 SMPR1 	   ;
	volatile u32 SMPR2 	   ;
	volatile u32 JOFR1 	   ;
	volatile u32 JOFR2 	   ;
	volatile u32 JOFR3 	   ;
	volatile u32 JOFR4 	   ;
	volatile u32 HTR   	   ;
	volatile u32 LTR   	   ;
	volatile u32 SQR[3]    ;
	volatile u32 JSQR  	   ;
	volatile u32 JDR[4]    ;
	volatile u32 DR    	   ;

} ADC_t;


#define  MADC1   ((ADC_t		 *) (_ADC_BASE_ADD))

#define  ADC_CCR (*(volatile u32*) (_ADC_BASE_ADD + 0x304)) // common for all ADC

/**/

typedef struct 
{
	u8 SG_u8RegularSequenerIndex  ;
	u8 SG_u8InjectedSequenerIndex ;
	u8 ADC_Mode					  ;
	
    void (*(ADC_SetCallBackArr[2]))(void);
	
	
}ADC_Control_t;

/*************** static fun*///////
static void MAdc_vAdcInitMode(void);

static void MAdc_vSingleRegulerMode(void);
static void MAdc_vSingleRegulerContinuousMode(void);

static void MAdc_vScanRegulerOnceMode(void);
static void MAdc_v_ScanRegulerContinuousMode(void);

static void MAdc_vScanInjectedOnce (void);






#endif


