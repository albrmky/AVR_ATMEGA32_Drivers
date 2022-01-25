/*
 * main.c
 *
 *  Created on: Jan 22, 2022
 *      Author: noureldeen albrmky
 */


#include "../Include/LIBRARY/standard_types.h"
#include "../Include/LIBRARY/bit_math.h"

#include "../Include/MCAL/DIO/DIO_interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_interface.h"
#include "../Include/MCAL/GLOBAL_INT/GLOBAL_INT_interface.h"
#include "../Include/HAL/KEYPAD/KEYPAD_interface.h"
#include "../Include/HAL/LCD/LCD_interface.h"

#include "../Include/App.h"

//#include "App.h"

s8 minutes = 0;
s8 seconds = 0;
u8 done_flag = 0;
u8 change_flag = 0;

void ISR_fun(void)
{
	static u16 count = 0;
	count++;
	if (count == 3907)
	{
		MDIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN1,
				!MDIO_u8GetPinValue(DIO_u8_PORTD, DIO_u8_PIN1)); // just as an indecation

		count = 0;
		MTIMER0_voidWriteTimerRegister(64); // start first overflow event from 64 to get one second
		//////////////////////////////////
		change_flag = 1;
		seconds--;

		if (seconds < 0 && minutes == 0)
		{
			done_flag = 1; // trigger function that ends the operation
		}
		else if (seconds < 0) // less than zero to display zero seconds
		{
			seconds = 59;
			minutes--;
		}

	}
}




int main(void)
{
	//KEY pad port
	MDIO_voidSetPortDir(DIO_u8_PORTC, 0x0F);  // low nibble o/p , high nibble i/p
	MDIO_voidSetPortValue(DIO_u8_PORTC, 0xFF);  // low nibble high, high nibble pullup

	// LCD
	MDIO_voidSetPortDir(DIO_u8_PORTA, 0xFF); // output for LCD data
	MDIO_voidSetPortDir(DIO_u8_PORTB, 0x0F); // lowest nibble high for LCD control

	MDIO_voidSetPinDir(DIO_u8_PORTD, DIO_u8_PIN1, DIO_u8_OUTPUT); // indicator led

	// initialize LCD
	HLCD_voidInit();

	// enable global interrupt
	MGINT_voidEnableGlobalINT();

	// set timer ISR and TIMER register start value
	MTIMER0_voidAssignOverflowISR(ISR_fun);
	MTIMER0_voidControlInterrupt(TIMER0_OVERFLOW, TIMER0_ENABLE);
	MTIMER0_voidWriteTimerRegister(64);


	/////////////////////////////////////////////////////////////////////////////
	//u8 key_press; // to hold the keypad pressed button value

	// welcoming message till any key is pressed
	HLCD_voidClearDisplay();
	HLCD_voidDisplayString((u8*) "Timer App");
	waitforkey();

	// take input of minutes
	HLCD_voidClearDisplay();
	HLCD_voidDisplayString((u8*) "Enter min: ");
	take_number(&minutes); // take minutes value by keypad


	// take input of seconds
	HLCD_voidClearDisplay();
	HLCD_voidDisplayString((u8*) "Enter sec: ");
	take_number(&seconds); // take seconds value by keypad


	// prepare counting display
	HLCD_voidClearDisplay();
	HLCD_voidDisplayString((u8*) "       :");


	// start timer
	MTIMER0_voidInit();
	while (1)
	{
		if (change_flag == 1) // triggered only every second to update display
		{

			// display minutes
			HLCD_voidGoToPos(LCD_u8_LINE1, 5);				// position the cursor
			if (minutes < 10) HLCD_voidSendData('0');		//display zero first if less than 10
			HLCD_voidDisplayNumber(minutes);				//display the number

			// display seconds
			HLCD_voidGoToPos(LCD_u8_LINE1, 8);				// position the cursor
			if (seconds < 10) HLCD_voidSendData('0');		// display zero if less than 10
			HLCD_voidDisplayNumber(seconds);				//display the number

			change_flag = 0;								// clear flag to avoid flickering
		}

		else if (done_flag == 1)
		{
			MTIMER0_voidStopTimer();					//stop timer
			HLCD_voidClearDisplay();					// clear display
			HLCD_voidDisplayString((u8*) "TimesOut");	//display time out
			done_flag = 0;								// clear flag to avoid flickering
			change_flag = 0;						// clear change flag to avoid flickering above
		}
	}




	return 0;
}
