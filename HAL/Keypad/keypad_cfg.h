/*
 * keypad_cfg.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Lenovo
 */

#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_

/* Keypad configurations for number of rows and columns */
#define N_col 4
#define N_row 4

/* Keypad Port Configurations */
#define KEYPAD_PORT_OUT PORTC
#define KEYPAD_PORT_IN  PINC
#define KEYPAD_PORT_DIR DDRC

#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
