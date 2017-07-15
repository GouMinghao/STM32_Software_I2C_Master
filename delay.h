#ifndef _DELAY_H_
#define _DELAY_H_

#include "stm32f10x.h"
//there two function is only function with a crystal oscillation frequency of 72MHz
extern uint16_t TIM6_cnt;
extern uint16_t TIM7_cnt;

/*
Use TIM1 and TIM8 of STM32F103 to generate accurate time delay.
*/
void DelayInit(void);
//We use timer to achieve the function
void Delay_us(uint16_t us);
void Delay_ms(uint16_t ms);

#endif
