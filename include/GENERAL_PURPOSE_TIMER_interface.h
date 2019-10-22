#ifndef GENERAL_PURPOSE_TIMER_H
#define GENERAL_PURPOSE_TIMER_H



void MTIMER2_Initialize(void);
void increase(void);
void decrease( void);
void setCallBack(void(*ptr)(void));


#endif
