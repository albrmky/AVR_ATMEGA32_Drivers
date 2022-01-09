/*
 * main.c
 *
 *  Created on: Jan 3, 2022
 *      Author: noureldeen albrmky
 */

#include "../Inc/LIBRARY/standard_types.h"
#include "../Inc/LIBRARY/bit_math.h"

#include "../Inc/MCAL/DIO/DIO_interface.h"
#include "../Inc/HAL/SEVEN_SEGMENT/SEVEN_SEGMENT_interface.h"

#include <util/delay.h> // for testing

//NO_TEST
//COM_CATH_A_P0
//COM_CATH_A_P7
//COM_ANOD_A_P0
//COM_ANOD_A_P7
#define COM_ANOD_A_P7

/*****************************************************************/
// test code 4
// common anode segment with a segment connected on P7
// according to simulation make sure the segment port on port B
// and the connection type is SEVSEG_A_ON_PIN7
#ifdef COM_ANOD_A_P7

int main(void)
{
	MDIO_voidInit();
	H7SEG_voidInit();

	while (1)
	{
		for (u8 i = 0; i < 10; i++)
		{
			H7SEG_voidDisplayNumber(i);
			_delay_ms(100);
		}
	}
	return 0;
}

#endif

/*****************************************************************/
// test code 3
// common anode segment with a segment connected on P0
// according to simulation make sure the segment port on port A
// and the connection type is SEVSEG_A_ON_PIN0
#ifdef COM_ANOD_A_P0

int main(void)
{
	MDIO_voidInit();
	H7SEG_voidInit();

	while (1)
	{
		for (u8 i = 0; i < 10; i++)
		{
			H7SEG_voidDisplayNumber(i);
			_delay_ms(100);
		}
	}
	return 0;
}

#endif

/*****************************************************************/
// test code 2
// common cathode segment with a segment connected on P7
// according to simulation make sure the segment port on port D
// and the connection type is SEVSEG_A_ON_PIN7
#ifdef COM_CATH_A_P7

int main(void)
{
	MDIO_voidInit();
	H7SEG_voidInit();

	while (1)
	{
		for (u8 i = 0; i < 10; i++)
		{
			H7SEG_voidDisplayNumber(i);
			_delay_ms(100);
		}
	}
	return 0;
}

#endif

/*****************************************************************/
// test code 1
// common cathode segment with a segment connected on P0
// according to simulation make sure the segment port on port C
// and the connection type is SEVSEG_A_ON_PIN0
#ifdef COM_CATH_A_P0

int main(void)
{
	MDIO_voidInit();
	H7SEG_voidInit();

	while (1)
	{
		for (u8 i = 0; i < 10; i++)
		{
			H7SEG_voidDisplayNumber(i);
			_delay_ms(100);
		}
	}
	return 0;
}

#endif


/**************************************************************************/
#ifdef NO_TEST

int main(void)
{
	MDIO_voidInit();
	H7SEG_voidInit();

	while (1)
	{
		for (u8 i = 0; i < 10; i++)
		{
			H7SEG_voidDisplayNumber(i);
			_delay_ms(100);
		}
	}
	return 0;
}

#endif

