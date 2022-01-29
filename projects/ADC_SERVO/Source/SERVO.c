/*
 * SERVO.c
 *
 *  Created on: Jan 29, 2022
 *      Author: noureldeen albrmky
 */

#include "../Include/LIBRARY/bit_math.h"
#include "../Include/LIBRARY/standard_types.h"


#include "../Include/MCAL/TIMER1/TIMER1_interface.h"

#include "../Include/HAL/SERVO/SERVO_interface.h"

void HSERVO(s16 angle)
{
	u16 value = (((angle + 90) * 100 * 1.0) / 18) + 1000;
	MTIMER1_voidWriteOCR_A_Register(value);
}
