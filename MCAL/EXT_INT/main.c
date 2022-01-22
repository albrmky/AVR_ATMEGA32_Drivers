/*
 * main.c
 *
 *  Created on: Jan 11, 2022
 *      Author: noureldeen albrmky
 */


#include "../Include/LIBRARY/standard_types.h"
#include "../Include/LIBRARY/bit_math.h"
#include <util/delay.h>

#include "../Include/MCAL/POWER/POWER.interface.h"

#include "../Include/MCAL/EXT_INT/EXT_INT_interface.h"
#include "../Include/MCAL/DIO/DIO_interface.h"
#include "../Include/MCAL/GLOBAL_INT/GLOBAL_INT_interface.h"

void int_fun(void)
{
	// first thing to be executed when coming from sleep
	MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,!MDIO_u8GetPinValue(DIO_u8_PORTA,DIO_u8_PIN0));
}



int main(void)
{

	MDIO_voidSetPortDir(DIO_u8_PORTD, 0x00); // port contains INT0 and INT1
	MDIO_voidSetPortDir(DIO_u8_PORTB, 0x00); // port contains INT2
	MDIO_voidSetPortDir(DIO_u8_PORTA, 0xFF); // port for the led

	MDIO_voidSetPortValue(DIO_u8_PORTD, 0xFF); // pull up for PORTD
	MDIO_voidSetPortValue(DIO_u8_PORTB, 0xFF); // pull up for PORTB

	// define sense control for the int and enable it
	MEXTINT_voidEnable(EXTINT0_FLAG, EXTINT_SENSE_LOW_LEVEL);
	MEXTINT_voidAssignIntFun(EXTINT_EXTINT0_INTERRUPT, int_fun);

	// enable the global int
	MGINT_voidEnableGlobalINT();


	// prepare and enter sleep mode
	MPOWER_voidInitSleepMode();


	// led will toggle one time after coming back from sleep

	while (1)
	{
		MPOWER_voidStartSleep();
		MDIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN1, DIO_u8_HIGH);
		_delay_ms(2000);
		MDIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN1, DIO_u8_LOW);
	}
	return 0;

}
