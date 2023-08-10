/*========================================================================================
===========================   - GPIO_Private.h    =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/



#ifndef _GPIO_PRIVET_H_
#define _GPIO_PRIVET_H_

typedef struct

{
volatile u32 GPIO_MODER		   ;														
volatile u32 GPIO_OTYPER       ;
volatile u32 GPIO_OSPEEDR      ;
volatile u32 GPIO_PUPDR        ;
volatile u32 GPIO_IDR          ;
volatile u32 GPIO_ODR          ;
volatile u32 GPIO_BSRR         ;
volatile u32 GPIO_LCKR         ;
volatile u32 GPIO_AFR[2]       ;
}GPIO_Reg_t;


#define GPIOA_BASS_ADD	0x40020000 
#define GPIOB_BASS_ADD	0x40020400 
#define GPIOC_BASS_ADD	0x40020800 
#define GPIOD_BASS_ADD	0x40020C00 
#define GPIOE_BASS_ADD	0x40021000 
#define GPIOH_BASS_ADD	0x40021C00 

#define _LUCKED_PIN		16U


#define MGPIOA       ((GPIO_Reg_t*) GPIOA_BASS_ADD )
#define MGPIOB       ((GPIO_Reg_t*) GPIOB_BASS_ADD )
#define MGPIOC       ((GPIO_Reg_t*) GPIOC_BASS_ADD )
#define MGPIOD       ((GPIO_Reg_t*) GPIOD_BASS_ADD )
#define MGPIOE       ((GPIO_Reg_t*) GPIOE_BASS_ADD )
#define MGPIOH       ((GPIO_Reg_t*) GPIOH_BASS_ADD )



#endif
