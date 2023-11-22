/*
 * keypad.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Lenovo
 */

#ifndef HAL_KEYPAD_H_
#define HAL_KEYPAD_H_

#include"../../Std_Types.h"
#include"../../Bit_Math.h"
#include"keypad_cfg.h"
#include<avr/io.h>


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function responsible for getting the pressed keypad key
 */
uint8_t KeyPad_getPressedKey(void);

//void set_threshold(uint8_t threshold);



#endif /* HAL_KEYPAD_H_ */
