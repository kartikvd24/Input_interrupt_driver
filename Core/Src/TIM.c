#include <stm32f4xx.h>

#define tim2en  (1U<<0)
#define gpioen (1U<<0)
#define CR1_CEN	 (1U<<0)
#define OUTPUT_CMP ((1U<<4)|(1U<<5))
#define CCER_CC1 (1u<<0)
#define AFR5_TIM (1U<<20)



#define AFR6_TIM (1U<<25)
#define TIM3_EN (1U<<1)
#define CCMR1_CC1S (1U<<0)
#define CCER1_EN (1U<<0)

void tim2_1hz_init(void){


	//enable clock access at clock 2
	RCC->APB1ENR |=tim2en;
	//set the prescalar value
	TIM2->PSC=1600-1;//16 000 000/1600=10 000
	//auto reload value
	TIM2->ARR=10000-1;//10000/10000=1HZ
	//clear the tim/counter
	TIM2->CNT =0;
	//enable the timer
	TIM2->CR1|=CR1_CEN;
}


void tim2_PA5_outputCompare(void){

	//configure PA5

	//enable clock access to pa5
RCC->AHB1ENR|=gpioen;
	//set the pa5 mode to alternate function mode
GPIOA->MODER&=~(1U<<10);
GPIOA->MODER|=(1U<<11);
	//set pa5 alternate function type to tim2 ch1
GPIOA->AFR[0] |=AFR5_TIM;


	//enable clock access at clock 2
	RCC->APB1ENR |=tim2en;
	//set the prescalar value
	TIM2->PSC=1600-1;//16 000 000/1600=10 000
	//auto reload value
	TIM2->ARR=10000-1;//10000/10000=1HZ
	//set output compare toggle mode
	//enable timer2 ch1 in compare mode
	TIM2->CCMR1=OUTPUT_CMP;
	//enable the capture/compare mode enable in channel 1 using ccer register i.e capture compare enable register
	TIM2->CCER=CCER_CC1;


	//clear the tim/counter
	TIM2->CNT =0;
	//enable the timer
	TIM2->CR1|=CR1_CEN;


}



void tim3_PA6_INPUTCAPTURE(void){
	//enable clock access at gpioa

	RCC->AHB1ENR|=gpioen;
	//set pa6 alternate function time to tim3 ch1
	GPIOA->MODER&=~(1U<<12);
	GPIOA->MODER|=(1U<<13);
	GPIOA->AFR[0]|=AFR6_TIM;

	//Enable clock access to tim3
	RCC->APB1ENR|=TIM3_EN;
	//set prescalar
	TIM3->PSC=1600-1;

	//set ch1 to capture at every edge(ie set ch1 to input capture mode)
	TIM3->CCMR1|=CCMR1_CC1S;
	//enable ch1 to capture rising edge
	TIM3->CCER|=CCER1_EN;
	//enable tim3
	TIM3->CR1|=CR1_CEN;

}
