/*
 * SRVM_program.c
 *
 * Created: 9/20/2023 12:00:31 PM
 *  Author: Kareem Hussein
 */ 



/* UTILES_LIB */

#include"../../Std_Types.h"
#include"../../Bit_Math.h"
#include"SRVM_interface.h"
#include"../../MCAL/Timer1/timer1_interface.h"
#include"../../MCAL/Dio/Dio.h"

void SRVM_voidOn(uint8_t Copy_u8Angle)
{
	Dio_SetChannel_Dir(PD_5, OUTPUT);
	/* TMR1 init at pwm mode 14 */
	Timer1_init();

	/* Set pwm fre. = 50 */
	set_frequency(50);//ICR=4999

	/* Set pwm duty cycle between 5 : 10
	 depend on desired angle[0 : 180] */
	u16 OCR1_value=(u16)(((Copy_u8Angle-MiniAngle)*((float)(MaxCount-MiniCount)/(MaxAngle-MiniAngle)))+MiniCount-1);
	f32_t duty=((OCR1_value+1)*100)/5000;//5000=ICR+1
	set_duty(duty);
	/* TMR1 start */
	Timer1_start();
}


void SRVM_voidOff(void)
{
	/* TMR1 stop */
	Timer1_stop();
}

