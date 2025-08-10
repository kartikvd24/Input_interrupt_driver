/*
 * exti.h
 *
 *  Created on: Aug 9, 2025
 *      Author: desai
 */

#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#include<stm32f4xx.h>
void pc13_exti_init(void);
#define LINE13 (1U<<13)

#endif /* INC_EXTI_H_ */
