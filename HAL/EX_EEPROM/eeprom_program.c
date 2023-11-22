/*
 * eeprom_program.c
 *
 *  Created on: Nov 9, 2023
 *      Author: Lenovo
 */

#include<util/delay.h>
#include"../../Bit_Math.h"
#include"../../Std_Types.h"
#include"eeprom_interface.h"
#include"eeprom_private.h"
#include"../../MCAL/TWI/TWI_interface.h"


void EEPROM_voidInit(void)
{
	TWI_InitMaster(255);
}


void EEPROM_voidWriteByte(u16 copy_u16WordAddress, uint8_t copy_u8Data)
{
	uint8_t local_u8Address = (copy_u16WordAddress>>8) | EEPROM_FIXED_ADDRESS;

	// Send start condition
	TWI_send_start_condition();

	// Send slave address with write operation
	TWI_send_slave_addressWithWrite(local_u8Address);

	// Send word address
	TWI_WriteMasterDataByte((uint8_t)copy_u16WordAddress);

	// Send byte data
	TWI_WriteMasterDataByte(copy_u8Data);

	// Send stop condition
	TWI_stop_condition();

    // Self-timed Write Cycle delay
	_delay_ms(5);
}


void EEPROM_voidReadByte(u16 copy_u16WordAddress, uint8_t* copy_pu8RxData)
{
	if(copy_pu8RxData != NULL)
	{
		uint8_t local_u8Address = (copy_u16WordAddress>>8) | EEPROM_FIXED_ADDRESS;

	    // Send start condition
		TWI_send_start_condition();

	    // Send slave address with write operation
		TWI_send_slave_addressWithWrite(local_u8Address);

	    // Send word address
		TWI_WriteMasterDataByte((uint8_t)copy_u16WordAddress);

	    // Send Repeated start condition
		TWI_send_repeated_start_condition();

		// Send slave address with read operation
		TWI_send_slave_addressWithRead(local_u8Address);

		// Read byte data
		TWI_ReadMasterDataByte(copy_pu8RxData);

		// Send stop condition
		TWI_stop_condition();

        // Self-timed Write Cycle delay
	    _delay_ms(5);
	}
}
void EEPROM_writePage(u16 eeprom_address,uint8_t* ptr_data)
{
	uint8_t counter=0;
	for(counter=0;counter<20;counter++)
	{
		EEPROM_voidWriteByte(eeprom_address+counter, ptr_data+counter);
	}
}
void EEPROM_readPage(u16 eeprom_address,uint8_t* ptr_data)
{
	uint8_t counter=0;
	for(counter=0;counter<20;counter++)
	{
		EEPROM_voidReadByte(eeprom_address+counter, ptr_data+counter);
	}
}

