/*
 * main.c
 *
 *  Created on: Jan 3, 2022
 *      Author: noureldeen albrmky
 */

// TEST_PINS_OUTPUT_WRITE
// TEST_PORT_OUTPUT_WRITE
// TEST_READ_PINS
// TEST_READ_PORTS
// NO_TEST

#define TEST_READ_PINS


#include "../Inc/LIBRARY/standard_types.h"
#include "../Inc/LIBRARY/bit_math.h"
#include "../Inc/MCAL/DIO/DIO_interface.h"

#include <util/delay.h> // for testing

/*****************************************************************/
#ifdef NO_TEST

int main(void)
{
	MDIO_voidInit();
	return 0;
}

#endif


/****************************************************/
// test code block 4
// READING PORTS
#ifdef TEST_READ_PORTS

int main(void)
{
	for (u8 i = 0; i < 4; i++)
	{
		MDIO_voidSetPortDir(i, 0xFF);
	}

	while (1)
	{
		for (u8 i = 0; i < 4; i++)
		{
			MDIO_voidSetPortValue(i, ~MDIO_u8GetPortValue(i));
			_delay_ms(200);
		}

	} //while
	return 0;
}

#endif

/*****************************************************************/

// test code block 3
// READING INPUT PINS INDIVIDUALLY
#ifdef TEST_READ_PINS
int main(void)
{

	for(u8 i=0; i<4; i++)
	{
		for(u8 j=0; j< 8; j++)
		{
			MDIO_voidSetPinDir(i,j,DIO_u8_OUTPUT);
		}
	}

	while (1)
	{
		for(u8 i=0; i<4; i++)
		{
			for(u8 j=0; j< 8; j++)
			{
				MDIO_voidSetPinValue(i,j,!MDIO_u8GetPinValue(i,j));
				_delay_ms(100);
			}
		}


	} // while

	return 0;
}//main
#endif
/***************************************************************/

// test code block 2
// WRITING THE WHOLE OUTPUT PORT
#ifdef TEST_PORT_OUTPUT_WRITE
int main(void)
{
	for (u8 i = 0; i < 4; i++)
	{
		MDIO_voidSetPortDir(i, 0xFF);
	}

	while (1)
	{

		for (u8 i = 0; i < 4; i++)
		{
			MDIO_voidSetPortValue(i, 0xFF);
			_delay_ms(200);
		}

		for (u8 i = 0; i < 4; i++)
		{
			MDIO_voidSetPortValue(i, 0x00);
			_delay_ms(200);
		}

	} //while
}//main
#endif

/****************************************************************/
// test code block 1
// writing the individual output pins
#ifdef TEST_PINS_OUTPUT_WRITE
int main(void)
{
	for(u8 i=0; i<4; i++)
	{
		for(u8 j=0; j< 8; j++)
		{
			MDIO_voidSetPinDir(i,j,DIO_u8_OUTPUT);

		}
	}

	while (1)
	{

		for(u8 i=0; i<4; i++)
		{
			for(u8 j=0; j< 8; j++)
			{
				MDIO_voidSetPinValue(i,j,DIO_u8_HIGH);
				_delay_ms(50);
			}
		}

		for(u8 i=0; i<4; i++)
		{
			for(u8 j=0; j< 8; j++)
			{
				MDIO_voidSetPinValue(i,j,DIO_u8_LOW);
				_delay_ms(50);
			}
		}

	} // while
}//main
#endif
