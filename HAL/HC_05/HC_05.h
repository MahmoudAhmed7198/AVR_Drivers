/*
 * HC_05.h
 *
 *  Created on: Nov 15, 2023
 *      Author: Lenovo
 */

#ifndef HAL_HC_05_HC_05_H_
#define HAL_HC_05_HC_05_H_

void sendATCommand(const uint8_t* command);
void receiveResponse();

#endif /* HAL_HC_05_HC_05_H_ */
