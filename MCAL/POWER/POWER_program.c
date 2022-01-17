/*
 * POWER.c
 *
 *  Created on: Jan 16, 2022
 *      Author: noureldeen albrmky
 */

#include "../Include/LIBRARY/standard_types.h"
#include "../Include/LIBRARY/bit_math.h"

#include "../Include/MCAL/POWER/POWER.interface.h"
#include "../Include/MCAL/POWER/POWER.private.h"
#include "../Include/MCAL/POWER/POWER.configuration.h"


void MPOWER_voidInitSleepMode()
{
	// clear the sleep enable bit
	CLR_BIT(POWER_MCUCR_REG, POWER_SLEEP_ENABLE_BIT);

	INS_FIELD(POWER_MCUCR_REG, BIT_FIELD_MASK, BIT_FIELD_SHIFT,
			POWER_SLEEP_MODE_CONFIGURATION);
}

void MPOWER_voidSetSleepMode(MPOWER_SLEEPMODE copy_u8_sleepMode)
{
	INS_FIELD(POWER_MCUCR_REG, BIT_FIELD_MASK, BIT_FIELD_SHIFT,
			copy_u8_sleepMode);
}

void MPOWER_voidStartSleep()
{
	// enable the sleep mode
	SET_BIT(POWER_MCUCR_REG, POWER_SLEEP_ENABLE_BIT);

	// enter the sleep mode
	asm volatile("SLEEP");

	// disable the sleep mode
	CLR_BIT(POWER_MCUCR_REG, POWER_SLEEP_ENABLE_BIT);
}
