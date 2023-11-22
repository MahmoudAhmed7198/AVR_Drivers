/*
 * eeprom_interface.h
 *
 *  Created on: Nov 9, 2023
 *      Author: Lenovo
 */

#ifndef HAL_EX_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EX_EEPROM_EEPROM_INTERFACE_H_


void EEPROM_voidInit     (void);
void EEPROM_voidWriteByte(u16 copy_u16WordAddress, uint8_t copy_u8Data);
void EEPROM_voidReadByte (u16 copy_u16WordAddress, uint8_t* copy_pu8RxData);
void EEPROM_writePage(u16 eeprom_address,uint8_t* ptr_data);
void EEPROM_readPage(u16 eeprom_address,uint8_t* ptr_data);


#endif /* HAL_EX_EEPROM_EEPROM_INTERFACE_H_ */
