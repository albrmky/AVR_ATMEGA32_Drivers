/*
 * main.c
 *
 *  Created on: Jan 17, 2022
 *      Author: noureldeen albrmky
 */


#include "../Include/LIBRARY/bit_math.h"
#include "../Include/LIBRARY/standard_types.h"

#include "../Include/MCAL/GLOBAL_INT/GLOBAL_INT_interface.h"
#include "../Include/MCAL/DIO/DIO_interface.h"
#include "../Include/MCAL/TIMER1/TIMER1_interface.h"
#include "../Include/MCAL/ADC/ADC_interface.h"

#include "../Include/HAL/SERVO/SERVO_interface.h"


u8 flag = 0;

void ISR(void)
{
	flag = 1;

}


int main(void)
{
	/*
	 * 0- set values in configuration file
	 * 1- set port direction for OC1x pins >>>>>>>>>>>>>> OC1A [PD5]  OC1B  [PD4]  ICP1  [PD6] <<<<<<<<<<
	 * 2- enable global interrupt
	 * 3- assign call back function
	 * 4- enable interrupt
	 * 5- write the proper values in the used registers
	 * 6- call initialization function
	 */

	MDIO_voidSetPortDir(DIO_u8_PORTD, 0xFF);
	MDIO_voidSetPinDir(DIO_u8_PORTA, DIO_u8_PIN0, DIO_u8_INPUT);    // adc

	MGINT_voidEnableGlobalINT();

//	MTIMER1_voidAssignCallBack(TIMER1_OVERFLOW, ISR);
//	MTIMER1_voidControlInterrupt(TIMER1_OVERFLOW, TIMER1_ENABLE);

	MTIMER1_voidAssignCallBack(TIMER1_COMPARE_A, ISR);
	MTIMER1_voidControlInterrupt(TIMER1_COMPARE_A, TIMER1_ENABLE);

	MTIMER1_voidWriteICRRegister(20000);
	MTIMER1_voidWriteOCR_A_Register(2000);

	MTIMER1_voidInit();

	MADC_voidInit();

	s16 reading;
	s16 dumb;

	while (1)
	{
		if (flag == 1)
		{
			reading = MADC_u8DigitalRead(ADC_INPUT_ADC0);
			dumb = ((reading * 18 * 1.0) / 255) * 10 - 90;
			HSERVO(dumb);
			flag = 0;
		}
	}
}

