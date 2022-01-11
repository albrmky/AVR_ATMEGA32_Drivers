/*
 * main.c
 *
 *  Created on: Jan 4, 2022
 *      Author: noureldeen albrmky
 */

#include "../Inc/LIBRARY/standard_types.h"
#include "../Inc/LIBRARY/bit_math.h"

#include "../Inc/MCAL/DIO/DIO_interface.h"
#include "../Inc/HAL/LCD/LCD_interface.h"

#include <util/delay.h>


u8 Heart[] = {
  0b00011011,
  0b00011111,
  0b00011111,
  0b00001110,
  0b00000100,
  0b00000000,
  0b00000000,
  0b00000000
};


int main(void)
{

	//initialize the pins for LCD
	MDIO_voidSetPortDir(DIO_u8_PORTA,0xFF);//data
	MDIO_voidSetPortDir(DIO_u8_PORTB,0x07);//control


	HLCD_voidInit();


	HLCD_voidSendData('A');
	HLCD_voidDisplayString((u8*)" NOUR ");
	HLCD_voidDisplayNumber(-125925);
	HLCD_voidSendSpecialCharacter(Heart,0,LCD_u8_LINE2,1);

// test the shift
//	HLCD_voidSendCommand(LCD_COMMAND_SHIFT_CURSOR_LEFT);
//	_delay_ms(100);
//	HLCD_voidSendCommand(LCD_COMMAND_SHIFT_CURSOR_LEFT);
//	_delay_ms(100);
//	HLCD_voidSendCommand(LCD_COMMAND_SHIFT_CURSOR_LEFT);
//	_delay_ms(100);
//
//
//	HLCD_voidSendCommand(LCD_COMMAND_SHIFT_CURSOR_RIGHT);
//	_delay_ms(100);
//	HLCD_voidSendCommand(LCD_COMMAND_SHIFT_CURSOR_RIGHT);
//	_delay_ms(100);
//	HLCD_voidSendCommand(LCD_COMMAND_SHIFT_CURSOR_RIGHT);
//	_delay_ms(100);


	while (1)
	{

	}

	return 0;
}
