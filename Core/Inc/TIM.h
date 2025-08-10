/*
 * TIM.h
 *
 *  Created on: Aug 6, 2025
 *      Author: desai
 */

#ifndef INC_TIM_H_
#define INC_TIM_H_

void tim2_1hz_init(void);
void tim2_PA5_outputCompare(void);
void tim3_PA6_INPUTCAPTURE(void);
#define Status_reg (1U<<1)
#endif /* INC_TIM_H_ */
