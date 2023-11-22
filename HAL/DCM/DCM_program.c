/*
 * DCM_program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Lenovo
 */
#include"../../Bit_Math.h"
#include"../../Std_Types.h"
#include"DCM_interface.h"
#include"../../MCAL/Timer_0/Timer0_interface.h"
#include"../../MCAL/Dio/Dio.h"


void DCM_Init()
{
	Dio_SetChannel_Dir(PC_0, OUTPUT);
	Dio_SetChannel_Dir(PC_1, OUTPUT);
	Dio_SetChannel_Dir(PB_3, OUTPUT);
}

void DCM_voidOn(uint8_t Copy_u8Direction)
{
	/* Turn DC motor on using H-Bridge
	 By Setting PWM, Dir and Enable pins with high
	 or Dir Low depend on Copy_u8Direction*/


	if(Copy_u8Direction==DCM_CLOCK_WISE)
	{
		Dio_WriteChannel(PC_0, STD_HIGH);
		Dio_WriteChannel(PC_1, STD_LOW);
	}
	else if(Copy_u8Direction==DCM_COUNTER_CLOCK_WISE)
	{
		Dio_WriteChannel(PC_0, STD_LOW);
		Dio_WriteChannel(PC_1, STD_HIGH);
	}
}


void DCM_voidControlSpeed(uint8_t Copy_u8Speed)
{
	/* Controlling DC motor speed using PWM
	mode from TMR0 by setting Duty Cycle*/
	Timer0_set_duty_cyclePhaseCorrect(Copy_u8Speed);
}


void DCM_voidOff(void)
{
	/* Turn DC motor off using H-Bridge
	   By Setting Enable pin with low */
	Dio_WriteChannel(PC_0, STD_LOW);
	Dio_WriteChannel(PC_1, STD_LOW);
	Dio_WriteChannel(PB_3, STD_LOW);
}


