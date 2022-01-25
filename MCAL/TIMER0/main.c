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
#include "../Include/MCAL/TIMER0/TIMER0_interface.h"

void ISR(void)
{

	MDIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1, !MDIO_u8GetPinValue(DIO_u8_PORTB, DIO_u8_PIN1));

//	static u16 count = 0;
//	count++;
//	if (count == 3907)
//	{
//		MDIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN1,
//				!MDIO_u8GetPinValue(DIO_u8_PORTB, DIO_u8_PIN1));
//
//		count = 0;
//		MTIMER0_voidWriteTimerRegister(64);
//	}

}


int main(void)
{

	// make OC0 pin output
	MDIO_voidSetPortDir(DIO_u8_PORTB, 0b00001010); //PB1 & PB3(OC0) output
	MDIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN0, DIO_u8_HIGH); // external clock pin pull up PB0


	// enable global interrupt
	MGINT_voidEnableGlobalINT();

	/*
	 * 1- assign the call back function for the required event
	 * 2- write OCR value if needed (usually not needed in normal mode only)
	 * 3- enable the type of the interrupt
	 * 4- call the initialize function
	 */

	//MTIMER0_voidAssignOverflowISR(ISR);
	MTIMER0_voidAssignCompareISR(ISR);
	MTIMER0_voidWriteOCRegister(5); //

	//MTIMER0_voidWriteTimerRegister(64);
	MTIMER0_voidControlInterrupt(TIMER0_COMPARE, TIMER0_ENABLE);
	//MTIMER0_voidControlInterrupt(TIMER0_OVERFLOW, TIMER0_ENABLE);

	MTIMER0_voidInit();


	while (1)
	{

	}
}

