/*
 * TIMER1_program.c
 *
 *  Created on: Jan 18, 2022
 *      Author: noureldeen albrmky
 */


#include "../Include/LIBRARY/bit_math.h"
#include "../Include/LIBRARY/standard_types.h"

#include "../Include/MCAL/TIMER1/TIMER1_configuration.h"
#include "../Include/MCAL/TIMER1/TIMER1_interface.h"
#include "../Include/MCAL/TIMER1/TIMER1_private.h"


void (*overflow_ISR)(void) = NULL;
void (*compareB_ISR)(void) = NULL;
void (*compareA_ISR)(void) = NULL;
void (*inputcapture_ISR)(void) = NULL;




void MTIMER1_voidInit(void)
{
	// output compare mode pins
	INS_FIELD(TIMER1_TCCR1A_u8_REG, 0b11, 6, TIMER1_COMPARE_MATCH_MODE_A);
	INS_FIELD(TIMER1_TCCR1A_u8_REG, 0b11, 4, TIMER1_COMPARE_MATCH_MODE_B);

	// mode of operation
	INS_FIELD(TIMER1_TCCR1A_u8_REG, 0b11, 0, (TIMER1_OPERATION_MODE & 0b11));
	INS_FIELD(TIMER1_TCCR1B_u8_REG, 0b11, 3, (TIMER1_OPERATION_MODE >> 2));

	//enable timer with predefined pre-scaler
	INS_FIELD(TIMER1_TCCR1B_u8_REG, 0b111, 0, TIMER1_CLOCK_SOURCE);
}



void MTIMER1_voidControlInterrupt(TIMER1_EVENT_TYPE copy_u8Int, TIMER1_STATE copy_u8state)
{
	INS_BIT(TIMER1_TIMSK_u8_REG, (copy_u8Int + 2), copy_u8state);
}

void MTIMER1_voidWriteTimerRegister(u16 copy_u8Value)
{
	TIMER1_TCNT1_u16_REG = copy_u8Value;
}

u16 MTIMER1_u16ReadTimerRegister(void)
{
	return TIMER1_TCNT1_u16_REG;
}

void MTIMER1_voidWriteOCR_A_Register(u16 copy_u8Value)
{
	TIMER1_OCR1A_u16_REG = copy_u8Value;
}

void MTIMER1_voidWriteOCR_B_Register(u16 copy_u8Value)
{
	TIMER1_OCR1B_u16_REG = copy_u8Value;
}

void MTIMER1_voidWriteICRRegister(u16 copy_u8Value)
{
	TIMER1_ICR1_u16_REG = copy_u8Value;
}

u16 MTIMER1_u16ReadICRRegister(void)
{
	return TIMER1_ICR1_u16_REG;
}

u8 MTIIMER1_u8ReadFlag(TIMER1_EVENT_TYPE copy_u8flag)
{
	return GET_BIT(TIMER1_TIFR_u8_REG, (copy_u8flag + 2));
}

void MTIIMER1_voidClearFlag(TIMER1_EVENT_TYPE copy_u8flag)
{
	SET_BIT(TIMER1_TIFR_u8_REG, (copy_u8flag + 2) );
}

void MTIMER1_voidForceCompare_A(void)
{
	SET_BIT(TIMER1_TCCR1A_u8_REG, 3);    // FOC1A in TCCR1A
}

void MTIMER1_voidForceCompare_B(void)
{
	SET_BIT(TIMER1_TCCR1A_u8_REG, 2);	// FOC1B in TCCR1A
}


void MTIMER1_voidAssignCallBack(TIMER1_EVENT_TYPE copy_u8event, void (*ptr)(void))
{
	switch (copy_u8event)
	{
		case TIMER1_OVERFLOW:
			overflow_ISR = ptr;
			break;
		case TIMER1_COMPARE_A:
			compareA_ISR = ptr;
			break;
		case TIMER1_COMPARE_B:
			compareB_ISR = ptr;
			break;
		case TIMER1_INPUT_CAPTURE:
			inputcapture_ISR = ptr;
			break;
	}
}

void __vector_6(void) __attribute__((signal));

void __vector_6(void)
{
	if (inputcapture_ISR != NULL) inputcapture_ISR();
}

void __vector_7(void) __attribute__((signal));

void __vector_7(void)
{
	if (compareA_ISR != NULL) compareA_ISR();
}

void __vector_8(void) __attribute__((signal));

void __vector_8(void)
{
	if (compareB_ISR != NULL) compareB_ISR();
}

void __vector_9(void) __attribute__((signal));

void __vector_9(void)
{
	if (overflow_ISR != NULL) overflow_ISR();
}
