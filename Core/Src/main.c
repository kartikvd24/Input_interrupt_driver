#include "stm32f4xx.h"
#include<stdint.h>
#include<stdio.h>
#include "stm32f4xx.h"
#include "uart.h"
#include"ADC.h"
#include "TIM.h"
#include "systick.h"
#include "exti.h"


void EXTI15_10_IRQHandler(void);

int main(void){
	UART2_TX_INIT();
	pc13_exti_init();
	RCC->AHB1ENR|=(1U<<0);
		GPIOA->MODER|=(1U<<10);
		GPIOA->MODER&=~(1U<<11);
	while(1){


	}


}
static void exti_callback(void){
	printf("BTN pressed..\n\r");
GPIOA->ODR ^=(1U<<5);
}

void EXTI15_10_IRQHandler(void){
	if((EXTI->PR  & LINE13)!=0)
	{
		//Clear the pr flag
		EXTI->PR|=LINE13;
		// basic logic
		exti_callback();
	}
}



