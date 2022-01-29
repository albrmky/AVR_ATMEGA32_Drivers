/*
 * GLOBAL_INT_program.c
 *
 *  Created on: Jan 11, 2022
 *      Author: noureldeen albrmky
 */

#include "../Include/LIBRARY/bit_math.h"
#include "../Include/LIBRARY/standard_types.h"

#include "../Include/MCAL/GLOBAL_INT/GLOBAL_INT_interface.h"
#include "../Include/MCAL/GLOBAL_INT/GLOBAL_INT_private.h"
#include "../Include/MCAL/GLOBAL_INT/GLOBAL_INT_configuration.h"



void MGINT_voidInit(void)
{
	if(GLOBAL_INTERUPT_STATE == GINT_ENABLE)
	{
		SET_BIT(GINT_SREG,GINT_GLOBAL_INT_BIT);
	}

	else if (GLOBAL_INTERUPT_STATE == GINT_DISABLE)
	{
		CLR_BIT(GINT_SREG,GINT_GLOBAL_INT_BIT);
	}

}

void MGINT_voidEnableGlobalINT(void)
{
	SET_BIT(GINT_SREG,GINT_GLOBAL_INT_BIT);
}

void MGINT_voidDisableGlobalINT(void)
{
	CLR_BIT(GINT_SREG,GINT_GLOBAL_INT_BIT);
}
