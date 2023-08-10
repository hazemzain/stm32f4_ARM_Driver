/*========================================================================================
===========================   - GPIO_Program.c		     =============================
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
	#include "GPIO_Private.h"
	#include "GPIO_Interface.h"
	#include "GPIO_Config.h"
/*======================================*/




/*===============   1-Function Set The Mode Of Pin	 ===============*/
void MGPIO_vSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u32 Copy_u32Mode  )
{
	switch (Copy_u8PortName)
	{
		
		case _GPIOA_PORT :   
		
			MGPIOA-> GPIO_MODER &=  ~((u32) 0b11<< (Copy_u8PinNum*2));
			MGPIOA-> GPIO_MODER |=  (Copy_u32Mode << (Copy_u8PinNum*2));
		break ;
		
		case _GPIOB_PORT :
		
			MGPIOB-> GPIO_MODER &=  ~((u32) 0b11<< (Copy_u8PinNum*2));
			MGPIOB-> GPIO_MODER |=  (Copy_u32Mode << (Copy_u8PinNum*2));

		break ;
		case _GPIOC_PORT :
		
			MGPIOC-> GPIO_MODER &=  ~((u32) 0b11<< (Copy_u8PinNum*2));
			MGPIOC-> GPIO_MODER |=  (Copy_u32Mode << (Copy_u8PinNum*2));


		break ;
		case _GPIOD_PORT : 
			MGPIOD-> GPIO_MODER &=  ~((u32)0b11<< (Copy_u8PinNum*2));
            MGPIOD-> GPIO_MODER |=  (Copy_u32Mode << (Copy_u8PinNum*2));
		break ;
		case _GPIOE_PORT :
			
			MGPIOE-> GPIO_MODER &=  ~((u32)0b11<< (Copy_u8PinNum*2));
            MGPIOE-> GPIO_MODER |=  (Copy_u32Mode << (Copy_u8PinNum*2));

		break ;
		case _GPIOH_PORT : 
			MGPIOH-> GPIO_MODER &=  ~((u32)0b11<< (Copy_u8PinNum*2));
            MGPIOH-> GPIO_MODER |=  (Copy_u32Mode << (Copy_u8PinNum*2));

		break ;
		
		default : break;
	}	
 }

/*===============   2-Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1)  ===============*/
void MGPIO_vSetPinOutPutType(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u16 Copy_u16OutPutType  )
{
	switch (Copy_u8PortName){
		
		case _GPIOA_PORT :   
		
			MGPIOA-> GPIO_OTYPER &=  ~((u16)1<< Copy_u8PinNum);
			MGPIOA-> GPIO_OTYPER |=  (Copy_u16OutPutType << Copy_u8PinNum);
		break ;
		
		case _GPIOB_PORT :
		
			MGPIOB-> GPIO_OTYPER &=  ~((u16)1<< Copy_u8PinNum);
			MGPIOB-> GPIO_OTYPER |=  (Copy_u16OutPutType << Copy_u8PinNum);

		break ;
		case _GPIOC_PORT :
		
			MGPIOC-> GPIO_OTYPER &=  ~((u16)1<< Copy_u8PinNum);
			MGPIOC-> GPIO_OTYPER |=  (Copy_u16OutPutType << Copy_u8PinNum);


		break ;
		case _GPIOD_PORT : 
			MGPIOD-> GPIO_OTYPER &=  ~((u16)1<< Copy_u8PinNum);
            MGPIOD-> GPIO_OTYPER |=  (Copy_u16OutPutType << Copy_u8PinNum);
		break ;
		case _GPIOE_PORT :
			
			MGPIOE-> GPIO_OTYPER &=  ~((u16)1<< Copy_u8PinNum);
            MGPIOE-> GPIO_OTYPER |=  (Copy_u16OutPutType << Copy_u8PinNum);

		break ;
		case _GPIOH_PORT : 
			MGPIOH-> GPIO_OTYPER &=  ~((u16)1<< Copy_u8PinNum);
            MGPIOH-> GPIO_OTYPER |=  (Copy_u16OutPutType << Copy_u8PinNum);

		break ;
		
		default : break;
		
		
	}
	
}
/*===============	3-Function Set The Speed Of output pin  (LOW , Meduim , High ,VeryHaigh	===============*/
void MGPIO_vSetPinOutSpeed(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u32 Copy_u32OutSpeed )
{
	switch (Copy_u8PortName)
	{
		
		case _GPIOA_PORT :   
		
			MGPIOA-> GPIO_OSPEEDR &=  ~((u32)0b11<< (Copy_u8PinNum*2));
			MGPIOA-> GPIO_OSPEEDR |=  (Copy_u32OutSpeed << (Copy_u8PinNum*2));
		break ;
		
		case _GPIOB_PORT :
		
			MGPIOB-> GPIO_OSPEEDR &=  ~((u32)0b11<< (Copy_u8PinNum*2));
			MGPIOB-> GPIO_OSPEEDR |=  (Copy_u32OutSpeed << (Copy_u8PinNum*2));

		break ;
		case _GPIOC_PORT :
		
			MGPIOC-> GPIO_OSPEEDR &=  ~((u32)0b11<< (Copy_u8PinNum*2));
			MGPIOC-> GPIO_OSPEEDR |=  (Copy_u32OutSpeed << (Copy_u8PinNum*2));


		break ;
		case _GPIOD_PORT : 
			MGPIOD-> GPIO_OSPEEDR &=  ~((u32)0b11<< (Copy_u8PinNum*2));
            MGPIOD-> GPIO_OSPEEDR |=  (Copy_u32OutSpeed << (Copy_u8PinNum*2));
		break ;
		case _GPIOE_PORT :
			
			MGPIOE-> GPIO_OSPEEDR &=  ~((u32)0b11<< (Copy_u8PinNum*2));
            MGPIOE-> GPIO_OSPEEDR |=  (Copy_u32OutSpeed << (Copy_u8PinNum*2));

		break ;
		case _GPIOH_PORT : 
			MGPIOH-> GPIO_OSPEEDR &=  ~((u32)0b11<< (Copy_u8PinNum*2));
            MGPIOH-> GPIO_OSPEEDR |=  (Copy_u32OutSpeed << (Copy_u8PinNum*2));

		break ;
		
		default : break;
	}	
	
}

/*===============   4-Function Set The PULL ( Almost Input ) ( OFF , UP , DOWN )  ===============*/
void MGPIO_vSetPullType(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u32 Copy_u32PullType )
{
	
	   switch (Copy_u8PortName)
	   {
	   	
	   	case _GPIOA_PORT :   
	   	
	   		MGPIOA-> GPIO_PUPDR &=  ~((u32)0b11<< (Copy_u8PinNum*2));
	   		MGPIOA-> GPIO_PUPDR |=  (Copy_u32PullType << (Copy_u8PinNum*2));
	   	break ;
	   	
	   	case _GPIOB_PORT :
	   	
	   		MGPIOB-> GPIO_PUPDR &=  ~((u32)0b11<< (Copy_u8PinNum*2));
	   		MGPIOB-> GPIO_PUPDR |=  (Copy_u32PullType << (Copy_u8PinNum*2));
	   
	   	break ;
	   	case _GPIOC_PORT :
	   	
	   		MGPIOC-> GPIO_PUPDR &=  ~((u32)0b11<< (Copy_u8PinNum*2));
	   		MGPIOC-> GPIO_PUPDR |=  (Copy_u32PullType << (Copy_u8PinNum*2));
	   
	   
	   	break ;
	   	case _GPIOD_PORT : 
			   MGPIOD-> GPIO_PUPDR &=  ~((u32)0b11<< (Copy_u8PinNum*2));
	           MGPIOD-> GPIO_PUPDR |=  (Copy_u32PullType << (Copy_u8PinNum*2));
	   	break ;
	   	case _GPIOE_PORT :
	   		
			   MGPIOE-> GPIO_PUPDR &=  ~((u32)0b11<< (Copy_u8PinNum*2));
	           MGPIOE-> GPIO_PUPDR |=  (Copy_u32PullType << (Copy_u8PinNum*2));
	   
	   	break ;
	   	case _GPIOH_PORT : 
	   		   MGPIOH-> GPIO_PUPDR &=  ~((u32)0b11<< (Copy_u8PinNum*2));
	           MGPIOH-> GPIO_PUPDR |=  (Copy_u32PullType << (Copy_u8PinNum*2));
	   
	   	break ;
	   	
	   	default : break;
	   }	
	
}
/*===============   5-Function To Read Data From IDR  ===============*/
u8 MGPIO_u8ReadData(u8 copy_u8PORT ,u8 copy_u8PIN)
{
	u8 Local_u8Data =0;
	
		switch (copy_u8PORT){
		
		case _GPIOA_PORT :  Local_u8Data = GET_BIT( MGPIOA -> GPIO_IDR , copy_u8PIN);	break ;	
			
		case _GPIOB_PORT :  Local_u8Data = GET_BIT( MGPIOB -> GPIO_IDR , copy_u8PIN);   break ;

		case _GPIOC_PORT :  Local_u8Data = GET_BIT( MGPIOC -> GPIO_IDR , copy_u8PIN);   break ;
		
		case _GPIOD_PORT :  Local_u8Data = GET_BIT( MGPIOD -> GPIO_IDR , copy_u8PIN);   break ;
		
		case _GPIOE_PORT :  Local_u8Data = GET_BIT( MGPIOE -> GPIO_IDR , copy_u8PIN);   break ;

		case _GPIOH_PORT :  Local_u8Data = GET_BIT( MGPIOH -> GPIO_IDR , copy_u8PIN);   break ;

		default : 																		break;	
	}	
	
	return Local_u8Data;
	
}
/*===============   6-Function To Write Data At ODR	Value = HIGH , LOW  ===============*/
void MGPIO_vWriteData(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State)
{
	switch(Copy_u8State)
	{
		case  _LOW  :
			switch (Copy_u8PortName)
			{
		
				case _GPIOA_PORT :  CLR_BIT(MGPIOA -> GPIO_ODR,Copy_u8PinNum);	break ;
				case _GPIOB_PORT :  CLR_BIT(MGPIOB -> GPIO_ODR,Copy_u8PinNum);	break ;
				case _GPIOC_PORT :  CLR_BIT(MGPIOC -> GPIO_ODR,Copy_u8PinNum);	break ;
				case _GPIOD_PORT :  CLR_BIT(MGPIOD -> GPIO_ODR,Copy_u8PinNum);	break ;
				case _GPIOE_PORT :  CLR_BIT(MGPIOE -> GPIO_ODR,Copy_u8PinNum);	break ;
				case _GPIOH_PORT :  CLR_BIT(MGPIOH -> GPIO_ODR,Copy_u8PinNum);	break ;
				default : 														break;
			}	
		break;
		
		case _HIGH  :
			switch (Copy_u8PortName)
			{
				case _GPIOA_PORT :  SET_BIT(MGPIOA -> GPIO_ODR,Copy_u8PinNum);	break ;
				case _GPIOB_PORT :  SET_BIT(MGPIOB -> GPIO_ODR,Copy_u8PinNum);	break ;
				case _GPIOC_PORT :  SET_BIT(MGPIOC -> GPIO_ODR,Copy_u8PinNum);	break ;
				case _GPIOD_PORT :  SET_BIT(MGPIOD -> GPIO_ODR,Copy_u8PinNum);	break ;
				case _GPIOE_PORT :  SET_BIT(MGPIOE -> GPIO_ODR,Copy_u8PinNum);	break ;
				case _GPIOH_PORT :  SET_BIT(MGPIOH -> GPIO_ODR,Copy_u8PinNum);	break ;
				default : 														break;
			}
		break;
		
		default : break;

	}
	
}
/*===============   7-Function To Locked   ===============*/
void MGPIO_vPinLock(u8 Copy_u8PortNum ,u8 Copy_u8PinNum )
{
			switch (Copy_u8PortNum)
			{
		
				case _GPIOA_PORT : 
					SET_BIT(MGPIOA -> GPIO_LCKR,Copy_u8PinNum);
					SET_BIT(MGPIOA -> GPIO_LCKR,_LUCKED_PIN);
					while ( GET_BIT(MGPIOA -> GPIO_LCKR,_LUCKED_PIN) ==0);	
				break ;
				
				case _GPIOB_PORT :
					SET_BIT(MGPIOB -> GPIO_LCKR,Copy_u8PinNum);
					SET_BIT(MGPIOB -> GPIO_LCKR,_LUCKED_PIN);
					while ( GET_BIT(MGPIOB -> GPIO_LCKR,_LUCKED_PIN) ==0);	
				break ;
				
				case _GPIOC_PORT :
					SET_BIT(MGPIOC -> GPIO_LCKR,Copy_u8PinNum);
					SET_BIT(MGPIOC -> GPIO_LCKR,_LUCKED_PIN);
					while ( GET_BIT(MGPIOC -> GPIO_LCKR,_LUCKED_PIN) ==0);	
				break ;
					
				case _GPIOD_PORT :
					SET_BIT(MGPIOD -> GPIO_LCKR,Copy_u8PinNum);
					SET_BIT(MGPIOD -> GPIO_LCKR,_LUCKED_PIN);
					while ( GET_BIT(MGPIOD -> GPIO_LCKR,_LUCKED_PIN) ==0);	
				break ;
				
				case _GPIOE_PORT :  
					SET_BIT(MGPIOE -> GPIO_LCKR,Copy_u8PinNum);
					SET_BIT(MGPIOE -> GPIO_LCKR,_LUCKED_PIN);
					while ( GET_BIT(MGPIOE -> GPIO_LCKR,_LUCKED_PIN) ==0);	
				break ;
				case _GPIOH_PORT : 
					SET_BIT(MGPIOH -> GPIO_LCKR,Copy_u8PinNum);
					SET_BIT(MGPIOH -> GPIO_LCKR,_LUCKED_PIN);
					while ( GET_BIT(MGPIOH -> GPIO_LCKR,_LUCKED_PIN) ==0);	
				break ;
				default : 														break;
			}	
}

/*===============   8-Function To Set ALTF   ===============*/
void MGPIO_vSetPinAltFn( u8 Copy_u8PortNum ,u8 Copy_u8PinNum, u8 Copy_u8ALF )
{
	u8 L_u8ALT_Index = Copy_u8PinNum /8;
	u8 L_u8ALT_Addjust = Copy_u8PinNum %8;
	switch (Copy_u8PortNum)
	{
		case _GPIOA_PORT :  
			MGPIOA -> GPIO_AFR[L_u8ALT_Index] &= ~(((u32) 0x0000000F)  << (L_u8ALT_Addjust *4));
			MGPIOA -> GPIO_AFR[L_u8ALT_Index] |= ((u32) Copy_u8ALF)  << (L_u8ALT_Addjust *4);
		break ;
		case _GPIOB_PORT :  
			MGPIOB -> GPIO_AFR[L_u8ALT_Index] &= ~(((u32) 0x0000000F)  << (L_u8ALT_Addjust *4));
			MGPIOB -> GPIO_AFR[L_u8ALT_Index] |= (((u32) Copy_u8ALF)  << (L_u8ALT_Addjust *4));
		break ;
		case _GPIOC_PORT :  
			MGPIOC -> GPIO_AFR[L_u8ALT_Index] &= ~(((u32) 0x0000000F)  << (L_u8ALT_Addjust *4));
			MGPIOC -> GPIO_AFR[L_u8ALT_Index] |= (((u32) Copy_u8ALF)  << (L_u8ALT_Addjust *4));
		break ;
		case _GPIOD_PORT : 
			MGPIOC -> GPIO_AFR[L_u8ALT_Index] &= ~(((u32) 0x0000000F)  << (L_u8ALT_Addjust *4));
			MGPIOC -> GPIO_AFR[L_u8ALT_Index] |= (((u32) Copy_u8ALF)  << (L_u8ALT_Addjust *4));
		break ;
		case _GPIOE_PORT :  
			MGPIOE -> GPIO_AFR[L_u8ALT_Index] &= ~(((u32) 0x0000000F)  << (L_u8ALT_Addjust *4));
			MGPIOE -> GPIO_AFR[L_u8ALT_Index] |= (((u32) Copy_u8ALF)  << (L_u8ALT_Addjust *4));
		break ;
		case _GPIOH_PORT :  
			MGPIOH -> GPIO_AFR[L_u8ALT_Index] &= ~(((u32) 0x0000000F)  << (L_u8ALT_Addjust *4));
			MGPIOH -> GPIO_AFR[L_u8ALT_Index] |= (((u32) Copy_u8ALF)  << (L_u8ALT_Addjust *4));
		break ;
		default : 														break;
	}	
}
/*===============   9-Function To Send One Byte  ===============*/
void MGPIO_vPortOutputOneByte(u8 Copy_u8Port, u8 Copy_u8Data, u8 Copy_u8StartBit)
{
			switch (Copy_u8Port)
			{
		
				case _GPIOA_PORT :  
					MGPIOA -> GPIO_ODR =   ( MGPIOA -> GPIO_ODR & (~ (((u16)0xFF) << Copy_u8StartBit))) | Copy_u8Data << Copy_u8StartBit ; 
				break ;
				case _GPIOB_PORT :  
					MGPIOB -> GPIO_ODR =   ( MGPIOB -> GPIO_ODR & (~ (((u16)0xFF) << Copy_u8StartBit))) | Copy_u8Data << Copy_u8StartBit ; 
				break ;
				case _GPIOC_PORT :  
					MGPIOC -> GPIO_ODR =   ( MGPIOC -> GPIO_ODR & (~ (((u16)0xFF) << Copy_u8StartBit))) | Copy_u8Data << Copy_u8StartBit ; 
				break ;
				case _GPIOD_PORT :  
					MGPIOD -> GPIO_ODR =   ( MGPIOD -> GPIO_ODR & (~ (((u16)0xFF) << Copy_u8StartBit))) | Copy_u8Data << Copy_u8StartBit ; 
				break ;
				case _GPIOE_PORT :  
					MGPIOE -> GPIO_ODR =   ( MGPIOE -> GPIO_ODR & (~ (((u16)0xFF) << Copy_u8StartBit))) | Copy_u8Data << Copy_u8StartBit ; 
				break ;
				case _GPIOH_PORT : 
					MGPIOH -> GPIO_ODR =   ( MGPIOH -> GPIO_ODR & (~ (((u16)0xFF) << Copy_u8StartBit))) | Copy_u8Data << Copy_u8StartBit ; 
				break ;
				default : 														
				
				break;
			}	

}

u8 MGPIO_vPortReadOneByte(u8 Copy_u8Port, u8 Copy_u8StartBit)
{

			u8 Copy_u8Data =0 ;

			switch (Copy_u8Port)
			{

				case _GPIOA_PORT :
					Copy_u8Data =   ((( MGPIOA -> GPIO_ODR) &  (((u16)(0xFF)) << Copy_u8StartBit)) >>  Copy_u8StartBit) ;
				break ;
				case _GPIOB_PORT :
					Copy_u8Data =   ((( MGPIOB -> GPIO_ODR) &  (((u16)(0xFF)) << Copy_u8StartBit)) >>  Copy_u8StartBit );
				break ;
				case _GPIOC_PORT :
					Copy_u8Data = ( (( MGPIOC -> GPIO_ODR) &  (((u16)(0xFF)) << Copy_u8StartBit)) >>  Copy_u8StartBit );
				break ;
				case _GPIOD_PORT :
					Copy_u8Data =  ((( MGPIOD -> GPIO_ODR) &  (((u16)(0xFF)) << Copy_u8StartBit)) >>  Copy_u8StartBit) ;
				break ;
				case _GPIOE_PORT :
					Copy_u8Data =   ((( MGPIOE -> GPIO_ODR) &  (((u16)(0xFF)) << Copy_u8StartBit)) >>  Copy_u8StartBit) ;
				break ;
				case _GPIOH_PORT :
					Copy_u8Data =   ((( MGPIOH -> GPIO_ODR) &  (((u16)(0xFF)) << Copy_u8StartBit)) >>  Copy_u8StartBit) ;
				break ;
				default :

				break;
			}
			return Copy_u8Data;

}






void MGPIO_vWriteDataDIR(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State)
{
		switch(Copy_u8State)
	{
		case  _LOW  :
			switch (Copy_u8PortName)
			{
		
				case _GPIOA_PORT :  MGPIOA -> GPIO_BSRR = 1U <<(Copy_u8PinNum+16U);	break ;
				case _GPIOB_PORT :  MGPIOB -> GPIO_BSRR = 1U <<(Copy_u8PinNum+16U);	break ;
				case _GPIOC_PORT :  MGPIOC -> GPIO_BSRR = 1U <<(Copy_u8PinNum+16U);	break ;
				case _GPIOD_PORT :  MGPIOD -> GPIO_BSRR = 1U <<(Copy_u8PinNum+16U);	break ;
				case _GPIOE_PORT :  MGPIOE -> GPIO_BSRR = 1U <<(Copy_u8PinNum+16U);	break ;
				case _GPIOH_PORT :  MGPIOH -> GPIO_BSRR = 1U <<(Copy_u8PinNum+16U);	break ;
				default : 																break;
			}	
		break;
		
		case _HIGH  :
			switch (Copy_u8PortName)
			{
				case _GPIOA_PORT :  MGPIOA -> GPIO_BSRR = 1U <<	Copy_u8PinNum         ;	break ;
				case _GPIOB_PORT :  MGPIOB -> GPIO_BSRR = 1U <<	Copy_u8PinNum         ;	break ;
				case _GPIOC_PORT :  MGPIOC -> GPIO_BSRR = 1U <<	Copy_u8PinNum         ;	break ;
				case _GPIOD_PORT :  MGPIOD -> GPIO_BSRR = 1U <<	Copy_u8PinNum         ;	break ;
				case _GPIOE_PORT :  MGPIOE -> GPIO_BSRR = 1U <<	Copy_u8PinNum         ;	break ;
				case _GPIOH_PORT :  MGPIOH -> GPIO_BSRR = 1U <<	Copy_u8PinNum         ;	break ;
				default : 														        break;
			}
		break;
		
		default : break;

	}
	
}
	
	

