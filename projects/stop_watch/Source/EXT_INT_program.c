/*
 * EXT_INT_program.c
 *
 *  Created on: Jan 11, 2022
 *      Author: noureldeen albrmky
 */


#include "../Include/LIBRARY/standard_types.h"
#include "../Include/LIBRARY/bit_math.h"

#include "../Include/MCAL/EXT_INT/EXT_INT_interface.h"
#include "../Include/MCAL/EXT_INT/EXT_INT_private.h"
#include "../Include/MCAL/EXT_INT/EXT_INT_configuration.h"


#define NULL (void*)0

void (*fp[3])(void) = {NULL, NULL, NULL};


void MEXTINT_voidInit(void)
{
	INS_BIT(EXTINT_GICR_REG,EXTINT_INT0_BIT,EXTINT0_STATE);
	INS_BIT(EXTINT_GICR_REG,EXTINT_INT1_BIT,EXTINT1_STATE);
	INS_BIT(EXTINT_GICR_REG,EXTINT_INT2_BIT,EXTINT2_STATE);

	INS_FIELD(EXTINT_MCUCR_REG,0b0011,0,EXTINT0_SENSE_TYPE);
	INS_FIELD(EXTINT_MCUCR_REG,0b1100,0,EXTINT1_SENSE_TYPE);
	INS_BIT(EXTINT_MCUCSR_REG,EXTINT2_CONTROL_SENSE_BIT,EXTINT2_SENSE_TYPE);

}


void MEXTINT_voidEnable(EXTERNAL_INTERRUPT_FLAG copy_u8InterruptNumber, EXTINT_SENSE_CONRTROL copy_u8SenseControl)
{
	if(copy_u8InterruptNumber==EXTINT0_FLAG)
	{
		INS_FIELD(EXTINT_MCUCR_REG,3,0,copy_u8SenseControl);
		SET_BIT(EXTINT_GICR_REG,copy_u8InterruptNumber);
	}
	else if(copy_u8InterruptNumber==EXTINT1_FLAG)
	{
		INS_FIELD(EXTINT_MCUCR_REG, 3, 2, copy_u8SenseControl);
		SET_BIT(EXTINT_GICR_REG,copy_u8InterruptNumber);
	}
	else if(copy_u8InterruptNumber==EXTINT2_FLAG)
	{
		INS_BIT(EXTINT_MCUCSR_REG,6,copy_u8SenseControl);
		SET_BIT(EXTINT_GICR_REG,copy_u8InterruptNumber);
	}
}

void MEXTINT_voidDisable(EXTERNAL_INTERRUPT_FLAG copy_u8InterruptNumber)
{
	if(copy_u8InterruptNumber==EXTINT0_FLAG)
	{
		CLR_BIT(EXTINT_GICR_REG,copy_u8InterruptNumber);
	}
	else if(copy_u8InterruptNumber==EXTINT1_FLAG)
	{
		CLR_BIT(EXTINT_GICR_REG,copy_u8InterruptNumber);
	}
	else if(copy_u8InterruptNumber==EXTINT2_FLAG)
	{
		CLR_BIT(EXTINT_GICR_REG,copy_u8InterruptNumber);
	}
}


void MEXTINT_voidAssignIntFun(EXTINT_fun_INTERRUPT copy_enumNumber, void(*copy_fptr)(void) )
{
	fp[copy_enumNumber] = copy_fptr;
}


u8 MEXTINT_u8ReadFlag(EXTERNAL_INTERRUPT_FLAG flag)
{
	return GET_BIT(EXTINT_GIFR_REG,flag);
}

void MEXTINT_voidClearFlag(EXTERNAL_INTERRUPT_FLAG flag)
{
	 CLR_BIT(EXTINT_GIFR_REG,flag);
}


void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
	if(fp[0] != NULL) fp[0]();
}

void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
	if(fp[1] != NULL) fp[1]();
}

void __vector_3(void) __attribute__((signal));

void __vector_3(void)
{
	if(fp[2] != NULL) fp[2]();
}

