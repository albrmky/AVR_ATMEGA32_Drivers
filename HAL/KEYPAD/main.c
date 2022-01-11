/*
 * main.c
 *
 *  Created on: Jan 9, 2022
 *      Author: noureldeen albrmky
 */

#include "../include/LIBRARY/standard_types.h"
#include "../include/LIBRARY/bit_math.h"

#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_interface.h"

#include <util/delay.h>


int main(void)
{

	//LCD
	MDIO_voidSetPortDir(DIO_u8_PORTA,0xFF);
	MDIO_voidSetPortDir(DIO_u8_PORTB,0xFF);

	//KEYPAD
	MDIO_voidSetPortDir(DIO_u8_PORTC,0x0F);  // low nibble o/p , high nibble i/p
	MDIO_voidSetPortValue(DIO_u8_PORTC,0xFF);// low nibble high, high nibble pullup

	//LCD
	HLCD_voidInit();

	u8 value;
	while(1)
	{
		value = HKEYPAD_voidGetKey();
		if(value != KEYPAD_NO_KEY )
		{
			HLCD_voidSendData(value);
		}
	}

	return 0;
}
