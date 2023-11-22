/*
 * RTOS_Interface.h
 *
 *  Created on: Nov 17, 2023
 *      Author: Lenovo
 */

#ifndef SERVICE_LAYER_OS_SCHEDULER_RTOS_INTERFACE_H_
#define SERVICE_LAYER_OS_SCHEDULER_RTOS_INTERFACE_H_

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void RTOS_CreateTask(void (*PTF)(void),uint8_t periodicity,uint8_t priority,uint8_t first_delay);
void scheduler(void);
void RTOS_voidStartOS(void);
void RTOS_DeleteTask(uint8_t priority);
void RTOS_SuspendTask(uint8_t priority);

#endif /* SERVICE_LAYER_OS_SCHEDULER_RTOS_INTERFACE_H_ */
