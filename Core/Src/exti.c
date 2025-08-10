/*
 * exti.c
 *
 *  Created on: Aug 9, 2025
 *      Author: desai
 */
#include<stm32f4xx.h>
#include<exti.h>
#define gpioc_en (1U<<2)
#define syscfg_en (1U<<14)
#define EXTICR3 (1U<<5)
void pc13_exti_init(void){
	__disable_irq();	//diabale global interrupt bedore init the interrupt
	//enable clock access to gpioc
RCC->AHB1ENR|=gpioc_en;

//SET THE PC13 AS input
GPIOC->MODER&=~(1U<<26);
GPIOC->MODER&=~(1U<<27);


	//enable clock access to access "syscfg"
RCC->APB2ENR|=syscfg_en;
	//select portc for exti13
SYSCFG->EXTICR[3]|=EXTICR3;//Based on the configuration register if cr1 is nedded use 0 and same for next registers
	//unmask exti13
EXTI->IMR|=(1U<<13);

	//select falling edge trigger
EXTI->FTSR|=(1U<<13);
	//enable exti line in the nvic
NVIC_EnableIRQ(EXTI15_10_IRQn);
	//enable global interrupt bedore init the interrupt
	__enable_irq();

}
