/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Lenovo
 */
#include<util/delay.h>
#include"Bit_Math.h"
#include"Std_Types.h"
#include"MCAL/Dio/Dio.h"
#include"MCAL/GI/GI_interface.h"
#include"MCAL/EXTI/EXTI_interface.h"
#include"MCAL/Timer_0/Timer0_interface.h"
#include"MCAL/Timer2/Timer2_interface.h"
#include"HAL/DCM/DCM_interface.h"
#include"HAL/Keypad/keypad.h"
#include"HAL/LCD2/lcd.h"
#include"MCAL/ADC/adc.h"
#include"MCAL/UART/uart.h"
#include"MCAL/Timer1/timer1_interface.h"
#include"MCAL/SPI/spi_interface.h"
#include"HAL/Servo/SRVM_interface.h"
#include"HAL/EX_EEPROM/eeprom_interface.h"
#include"MCAL/WDT/WDT_interface.h"

#include"HAL/HC_05/HC_05.h"
#include"Service_layer/OS_Scheduler/RTOS_Interface.h"

void toggle_led1(void);
void toggle_led2(void);

int main()
{
	Dio_SetChannel_Dir(PA_0, OUTPUT);
	Dio_SetChannel_Dir(PA_1, OUTPUT);
	enable_global_int();
	RTOS_CreateTask(toggle_led1, 100, 0,1);//(ptf,periodicity,periority,first delay)
	RTOS_CreateTask(toggle_led2, 200, 1,2);
	RTOS_voidStartOS();



	while(1)
	{

	}

	return 0;
}

void toggle_led1(void)
{
	Dio_FlipChannel(PA_0);
}
void toggle_led2(void)
{
	Dio_FlipChannel(PA_1);
}
