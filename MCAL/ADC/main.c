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
#include "../Include/MCAL/ADC/ADC_interface.h"
#include "../Include/HAL/LCD/LCD_interface.h"

s16 reading;
u8 flag = 0;

void ADC_ISR_FUN(void)
{
	reading = MADC_u8Read();
	//MDIO_voidSetPortValue(DIO_u8_PORTB, reading);
}

/*
 * 1- set configuration file
 * 2- set pin direction
 * 3- enable global interrupt if used
 * 4- enable adc interrupt if used
 * 5- assign callback function if used
 * 6- otherwise call any of disgital read functions
 */

int main(void)
{

	MDIO_voidSetPortDir(DIO_u8_PORTA, 0x00); //analog input
	MDIO_voidSetPortDir(DIO_u8_PORTC, 0xFF); //LCD data
	MDIO_voidSetPortDir(DIO_u8_PORTD, 0xFF); //LCD control


	HLCD_voidInit();

	MGINT_voidEnableGlobalINT();

	MADC_voidInit();
	//MADC_voidInterruptEnable(ADC_ISR_FUN, ADC_INPUT_ADC0);

	while (1)
	{
		reading = MADC_u8DigitalRead(ADC_INPUT_ADC0);

		HLCD_voidClearDisplay();
		HLCD_voidDisplayNumber(reading);

	}
}

