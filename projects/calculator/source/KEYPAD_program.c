/*
 * KEYPAD_program.c
 *
 *  Created on: Jan 9, 2022
 *      Author: noureldeen albrmky
 */

#include "../include/LIBRARY/standard_types.h"
#include "../include/LIBRARY/bit_math.h"

#include "../include/MCAL/DIO/DIO_interface.h"

#include "../include/HAL/KEYPAD/KEYPAD_interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_private.h"
#include "../include/HAL/KEYPAD/KEYPAD_configuration.h"

#include <util/delay.h>


// pin 0:3 rows from R1:R4
// pin 4:7 rows from C1:C4

/*******************************************************************************
the following three arrays are initialized
by macros in the configuration file
********************************************************************************/
u8 keypad_Au8buttonsvalue[KEYPAD_ROW_NUM][KEYPAD_COL_NUM] = KEYPAD_Au8BUTTONS;
u8 KEYPAD_Au8Rowspins[KEYPAD_ROW_NUM] = KEYPAD_Au8ROWS;
u8 KEYPAD_Au8ColsPins[KEYPAD_COL_NUM] = KEYPAD_Au8COLS;


/*********************************************************************************

*********************************************************************************/
u8 HKEYPAD_voidGetKey()
{

	u8 local_u8RowCounter;		//counter for the rows for loops
	u8 local_u8ColCounter;		//counter for the colunms for loops
	u8 local_u8PinValue;		// store the reading of the current column pin
	u8 local_u8KeyValue = KEYPAD_NO_KEY;	// value of key pressed (return of the function)
	u8 local_u8Flag = KEYPAD_FLAG_DOWN;		// flag to break the bigger for loop when the button pressed is found



	for(local_u8RowCounter=0; local_u8RowCounter< KEYPAD_ROW_NUM;local_u8RowCounter++ )
	{
		// set the current row to 0
		MDIO_voidSetPinValue(KEYPAD_PORT, KEYPAD_Au8Rowspins[local_u8RowCounter], DIO_u8_LOW);


		// check cols one by one
		for(local_u8ColCounter = 0; local_u8ColCounter < KEYPAD_COL_NUM; local_u8ColCounter++)
		{
			//read current  column pin
			local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_Au8ColsPins[local_u8ColCounter]);


			if(local_u8PinValue == DIO_u8_LOW)// if found
			{
				_delay_ms(KEYPAD_DEBOUNCE); // wait for noisy part of the signal

				//read again
				local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_Au8ColsPins[local_u8ColCounter]);

				while(local_u8PinValue==DIO_u8_LOW)// wait to release the button
				{
					local_u8PinValue = MDIO_u8GetPinValue(KEYPAD_PORT, KEYPAD_Au8ColsPins[local_u8ColCounter]);
				}

				// get the button value
				local_u8KeyValue = keypad_Au8buttonsvalue[local_u8RowCounter][local_u8ColCounter];

				// raise the flag
				local_u8Flag = KEYPAD_FLAG_UP;
				break;

			}//if
		}//for

		// don't forget to set the row pin again for the next reading
		MDIO_voidSetPinValue(KEYPAD_PORT, KEYPAD_Au8Rowspins[local_u8RowCounter], DIO_u8_HIGH);
		if(local_u8Flag == KEYPAD_FLAG_UP)
		{
			break;
		}//if
	}//for

	return local_u8KeyValue;
}//function
