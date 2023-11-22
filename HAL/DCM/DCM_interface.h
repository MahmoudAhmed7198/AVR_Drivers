/*
 * DCM_interface.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Lenovo
 */

#ifndef HAL_DCM_DCM_INTERFACE_H_
#define HAL_DCM_DCM_INTERFACE_H_

#define DCM_CLOCK_WISE                   1
#define DCM_COUNTER_CLOCK_WISE           2

void DCM_Init();
void DCM_voidOn          (uint8_t Copy_u8Direction);
void DCM_voidControlSpeed(uint8_t Copy_u8Speed);
void DCM_voidOff         (void);


#endif /* HAL_DCM_DCM_INTERFACE_H_ */
