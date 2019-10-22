#include "LSTD_TYPES.h"
#include "GENERAL_PURPOSE_TIMER_private.h"
#include "GENERAL_PURPOSE_TIMER_interface.h"

void (*TIMER2_CallBack)(void);

void MTIMER2_Initialize(void)
{ 


	TIMER2 ->TIMx_PSC=0;
	TIMER2 ->TIMx_ARR=1000;    //periodic time
	//TIMER2 ->TIMx_CCR1=1000; //duty cycle
	//these three bits for PWM mode 1
	TIMER2 ->TIMx_CCMR1 &=~(1<<4);
	TIMER2 ->TIMx_CCMR1 |=(1<<5);
	TIMER2 ->TIMx_CCMR1 |=(1<<6);
	//TIMER2 ->TIMx_CCMR1 &=~(1<<4)|(1<<5)|(1<<6);

	TIMER2 ->TIMx_CCMR1 |=(1<<3);  //enable preload
	TIMER2 ->TIMx_CR1 |=(1<<7);
	TIMER2 ->TIMx_CCER |=0x1;  //enable capture compare for channel 1
	TIMER2 ->TIMx_CCER &=~(1<<1) ; //polarity is active high
	//TIMER2 ->TIMx_BDTR |=(1<<15);

	TIMER2-> TIMx_CR1 |=1;  //enable counter
	TIMER2 ->TIMx_EGR |=1;
	
}

void increase()
{
	 u32 i=0;
	while(i<1000)
	{
	TIMER2 ->TIMx_CCR1=i; //duty cycle
	i+=1;
	}
}

void decrease()
{
	 u32 i=1000;
		while(i>0)
		{
		TIMER2 ->TIMx_CCR1=i; //duty cycle
		i-=1;
		}
}


void setCallBack(void(*ptr)(void))
{
	TIMER2_CallBack=ptr;

}

void TIM2_IRQHandler(void)
{ //id --> 28   of interrupt
   TIMER2->TIMx_SR |=0;//clear interrupt flag
   
	TIMER2_CallBack();
}
