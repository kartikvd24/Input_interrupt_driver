/*
 * systick.c
 *
 *  Created on: Aug 1, 2025
 *      Author: desai
 */
#include "stm32f4xx.h"
#define systick_enable (1U<<0)
#define CTRL_CLOCK (1U<<2)
#define CTRL_COUNT_FLAG (1U<<16)
#define systick_load_value 16000 //in a milli second





void systickdelayMS(int delay){
		SysTick->LOAD=systick_load_value;//configure the systick value with the load value in the systick timer(load the nuber of clocks per milli seconmd)
		//clear systick current value register
		SysTick->VAL=0;
		//enable systick and select internal clock source
		SysTick->CTRL=systick_enable | CTRL_CLOCK;


		for(int i=0;i<delay;i++){
			//wait until the count flag is set
			while((SysTick->CTRL &CTRL_COUNT_FLAG )==0){}


		}

		SysTick->CTRL=0;
}

