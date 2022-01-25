/*
 * TIMER0_program.c
 *
 *  Created on: Jan 18, 2022
 *      Author: noureldeen albrmky
 */


#include "../Include/LIBRARY/bit_math.h"
#include "../Include/LIBRARY/standard_types.h"

#include "../Include/MCAL/TIMER0/TIMER0_interface.h"
#include "../Include/MCAL/TIMER0/TIMER0_configuration.h"
#include "../Include/MCAL/TIMER0/TIMER0_private.h"
//#include <util/delay.h>


void (*OverflowISR)(void) = NULL;
void (*compareISR)(void) = NULL;

void MTIMER0_voidInit(void)
{


	// operating mode
	// parenthesis is necessary to avoid any risks
	INS_BIT(TIMER0_TCCR0_REG, TIMER0_BIT_WGM00, (TIMER0_OPERATING_MODE & 1)); // WGM00
	INS_BIT(TIMER0_TCCR0_REG, TIMER0_BIT_WGM01, (TIMER0_OPERATING_MODE >>1)); // WGM01

	// compare match pin mode (toggle , inverting . non inverting)
	INS_FIELD(TIMER0_TCCR0_REG, 0b11, 4, TIMER0_COMPARE_MATCH_MODE); // COM0 0:2 bits

	// for future compatiplity according to the data sheet
	CLR_BIT(TIMER0_TCCR0_REG, 7);

	// clock source
	INS_FIELD(TIMER0_TCCR0_REG, 0b111, 0, TIMER0_CLOCK_SOURCE); // CS0 0:2 bits

	//_delay_ms(500);


}

void MTIMER_voidForceOutputCompareBit()
{
	SET_BIT(TIMER0_TCCR0_REG, 7);
}


void MTIMER0_voidWriteTimerRegister(u8 copy_u8Value)
{
	TIMER0_TCNT0_REG = copy_u8Value;
}

void MTIMER0_voidWriteOCRegister(u8 copy_u8Value)
{
	TIMER0_OCR0_REG = copy_u8Value;
}

u8 MTIMER0_u8ReadFlag(TIMER0_EVENT_TYPE copy_u8flag)
{
	u8 temp = 255;

	if (copy_u8flag == TIMER0_OVERFLOW)
		temp = GET_BIT(TIMER0_TIFR_REG, TIMER0_BIT_OVERFLOW_FLAG);
	else if (copy_u8flag == TIMER0_COMPARE)
		temp = GET_BIT(TIMER0_TIFR_REG, TIMER0_BIT_COMPARE_FLAG);

	return temp;

}

void MTIMER0_voidControlInterrupt(TIMER0_EVENT_TYPE copy_u8Int,
		TIMER0_STATE copy_u8state)
{
	if (copy_u8Int == TIMER0_OVERFLOW)
		INS_BIT(TIMER0_TIMSK_REG, TIMER0_BIT_OVERFLOW_ENABLE, copy_u8state);
	else if (copy_u8Int == TIMER0_COMPARE)
		INS_BIT(TIMER0_TIMSK_REG, TIMER0_BIT_COMPARE_ENABLE, copy_u8state);
}

void MTIMER0_voidAssignOverflowISR(void (*ISRptr)(void))
{
	OverflowISR = ISRptr;
}

void MTIMER0_voidAssignCompareISR(void (*ISRptr)(void))
{
	compareISR = ISRptr;
}

void __vector_10(void) __attribute__((signal));

void __vector_10(void)
{
	if (compareISR != NULL)
	compareISR();
}



void __vector_11(void) __attribute__((signal));

void __vector_11(void)
{
	if (OverflowISR != NULL)
	OverflowISR();
}
