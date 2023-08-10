#include "TIMER2_Interface.h"
void MTIMER_void_TIMERInit(void)
{
	/*
	 * Bits 15:0 PSC[15:0]: Prescaler value
	The counter clock frequency CK_CNT is equal to fCK_PSC / (PSC[15:0] + 1).
	PSC contains the value to be loaded in the active prescaler register at each update event
	(including when the counter is cleared through UG bit of TIMx_EGR register or through
	trigger controller when configured in “reset mode”)
	 */
	TIM2->PSC=15999;
	/*TIMx auto-reload register (TIMx_ARR)*/
	TIM2->ARR=500;
	/*: Direction*/
	CLR_BIT(TIM2->CR1,4);
	/* Auto-reload preload enable*/
	SET_BIT(TIM2->CR1,7);
	/*UIE: Update interrupt enable
	0: Update interrupt disabled
	1: Update interrupt enabled
	 */
	SET_BIT(TIM2->DIER,0);
	/* CEN: Counter enable*/
	SET_BIT(TIM2->CR1,0);
}
