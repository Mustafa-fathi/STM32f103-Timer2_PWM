#ifndef GENERAL_PURPOSE_TIMER_H
#define GENERAL_PURPOSE_TIMER_H

typedef struct
{
	volatile u32 TIMx_CR1;
	volatile u32 TIMx_CR2;
	volatile u32 TIMx_SMCR;
	volatile u32 TIMx_DIER;
	volatile u32 TIMx_SR;
	volatile u32 TIMx_EGR;
	volatile u32 TIMx_CCMR1;
	volatile u32 TIMx_CCMR2;
	volatile u32 TIMx_CCER;
	volatile u32 TIMx_CNT;
	volatile u32 TIMx_PSC;
	volatile u32 TIMx_ARR;
    volatile u32 TIMx_reserved1;
	volatile u32 TIMx_CCR1;
	volatile u32 TIMx_CCR2;
	volatile u32 TIMx_CCR3;
	volatile u32 TIMx_CCR4;
	volatile u32 TIMx_reserved2;
	volatile u32 TIMx_DCR;
	volatile u32 TIMx_DMAR;

	
}GENERAL_PURPOSE_TIMER_type;

#define TIMER2  ((volatile GENERAL_PURPOSE_TIMER_type*) 0x40000000)
#define TIMER3  ((volatile GENERAL_PURPOSE_TIMER_type*) 0x40000400)
#define TIMER4  ((volatile GENERAL_PURPOSE_TIMER_type*) 0x40000800)
#define TIMER5  ((volatile GENERAL_PURPOSE_TIMER_type*) 0x40000C00)

#endif
