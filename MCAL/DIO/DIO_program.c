/*
 * DIO_program.c
 *
 *  Created on: Jan 3, 2022
 *      Author: noureldeen albrmky
 */

#include "../Include/LIBRARY/standard_types.h"
#include "../Include/LIBRARY/bit_math.h"

#include "../Include/MCAL/DIO/DIO_interface.h"
#include "../Include/MCAL/DIO/DIO_private.h"
#include "../Include/MCAL/DIO/DIO_configuration.h"


/****************************************************/
/*		USING LONG OR SHORT FUNCTIONS				*/
/****************************************************/
// SHORT_FUNCTION
// LONG_FUNCTION

#define SHORT_FUNCTION


/*************************************************************/
/* 	this function initialize both the pin direction
 * and its value according to the values specified in
 * the configuration file
 */
/*************************************************************/

void MDIO_voidInit(void)
{
	// initialize directions

	// portA
	DIO_u8_DDRA_REG = CONC_BIT(DIO_u8_PA7_INITIAL_DIRECTION,
			DIO_u8_PA6_INITIAL_DIRECTION, DIO_u8_PA5_INITIAL_DIRECTION,
			DIO_u8_PA4_INITIAL_DIRECTION, DIO_u8_PA3_INITIAL_DIRECTION,
			DIO_u8_PA2_INITIAL_DIRECTION, DIO_u8_PA1_INITIAL_DIRECTION,
			DIO_u8_PA0_INITIAL_DIRECTION);

	// PORTB
	DIO_u8_DDRB_REG = CONC_BIT(DIO_u8_PB7_INITIAL_DIRECTION,
			DIO_u8_PB6_INITIAL_DIRECTION, DIO_u8_PB5_INITIAL_DIRECTION,
			DIO_u8_PB4_INITIAL_DIRECTION, DIO_u8_PB3_INITIAL_DIRECTION,
			DIO_u8_PB2_INITIAL_DIRECTION, DIO_u8_PB1_INITIAL_DIRECTION,
			DIO_u8_PB0_INITIAL_DIRECTION);

	//PORTC
	DIO_u8_DDRC_REG = CONC_BIT(DIO_u8_PC7_INITIAL_DIRECTION,
			DIO_u8_PC6_INITIAL_DIRECTION, DIO_u8_PC5_INITIAL_DIRECTION,
			DIO_u8_PC4_INITIAL_DIRECTION, DIO_u8_PC3_INITIAL_DIRECTION,
			DIO_u8_PC2_INITIAL_DIRECTION, DIO_u8_PC1_INITIAL_DIRECTION,
			DIO_u8_PC0_INITIAL_DIRECTION);

	//PORTD
	DIO_u8_DDRD_REG = CONC_BIT(DIO_u8_PD7_INITIAL_DIRECTION,
			DIO_u8_PD6_INITIAL_DIRECTION, DIO_u8_PD5_INITIAL_DIRECTION,
			DIO_u8_PD4_INITIAL_DIRECTION, DIO_u8_PD3_INITIAL_DIRECTION,
			DIO_u8_PD2_INITIAL_DIRECTION, DIO_u8_PD1_INITIAL_DIRECTION,
			DIO_u8_PD0_INITIAL_DIRECTION);

	//initialize directions

	//PORTA
	DIO_u8_PORTA_REG = CONC_BIT(DIO_u8_PA7_INITIAL_VALUE,
			DIO_u8_PA6_INITIAL_VALUE, DIO_u8_PA5_INITIAL_VALUE,
			DIO_u8_PA4_INITIAL_VALUE, DIO_u8_PA3_INITIAL_VALUE,
			DIO_u8_PA2_INITIAL_VALUE, DIO_u8_PA1_INITIAL_VALUE,
			DIO_u8_PA0_INITIAL_VALUE);


	//PORTB
	DIO_u8_PORTB_REG = CONC_BIT(DIO_u8_PB7_INITIAL_VALUE,
			DIO_u8_PB6_INITIAL_VALUE, DIO_u8_PB5_INITIAL_VALUE,
			DIO_u8_PB4_INITIAL_VALUE, DIO_u8_PB3_INITIAL_VALUE,
			DIO_u8_PB2_INITIAL_VALUE, DIO_u8_PB1_INITIAL_VALUE,
			DIO_u8_PB0_INITIAL_VALUE);


	//PORTC
	DIO_u8_PORTC_REG = CONC_BIT(DIO_u8_PC7_INITIAL_VALUE,
			DIO_u8_PC6_INITIAL_VALUE, DIO_u8_PC5_INITIAL_VALUE,
			DIO_u8_PC4_INITIAL_VALUE, DIO_u8_PC3_INITIAL_VALUE,
			DIO_u8_PC2_INITIAL_VALUE, DIO_u8_PC1_INITIAL_VALUE,
			DIO_u8_PC0_INITIAL_VALUE);


	//PORTD
	DIO_u8_PORTD_REG = CONC_BIT(DIO_u8_PD7_INITIAL_VALUE,
			DIO_u8_PD6_INITIAL_VALUE, DIO_u8_PD5_INITIAL_VALUE,
			DIO_u8_PD4_INITIAL_VALUE, DIO_u8_PD3_INITIAL_VALUE,
			DIO_u8_PD2_INITIAL_VALUE, DIO_u8_PD1_INITIAL_VALUE,
			DIO_u8_PD0_INITIAL_VALUE);

}

/**********************************************************/
/* set DDR register which decide the direction of the pin
 * 1 OUTPUT      0 INPUT
 * the above is implemented in bit wise
 */
/**********************************************************/

void MDIO_voidSetPinDir(u8 copy_u8PortID, u8 copy_u8Pin, u8 copy_u8Direction)
{

#ifdef SHORT_FUNCTION
if ( 	(copy_u8Pin < DIO_u8_PIN0)	|| (copy_u8PortID < DIO_u8_PORTA) 	||
		(copy_u8Pin > DIO_u8_PIN7) 	|| (copy_u8PortID > DIO_u8_PORTD)			)
{}

else
{
	volatile u8* reg = (volatile u8*) (0x31 + (3 - copy_u8PortID) * 3 );
	INS_BIT(*reg,copy_u8Pin,copy_u8Direction);
}


#endif



#ifdef LONG_FUNCTION
	if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA)
			|| (copy_u8Pin > DIO_u8_PIN7) || (copy_u8Pin < DIO_u8_PIN0))
	{

	}

	else
	{
		switch (copy_u8PortID)
		{
			case DIO_u8_PORTA:
				switch (copy_u8Direction)
				{
					case DIO_u8_OUTPUT:
						SET_BIT(DIO_u8_DDRA_REG, copy_u8Pin);
						break;
					case DIO_u8_INPUT:
						CLR_BIT(DIO_u8_DDRA_REG, copy_u8Pin);
						break;
				}
				break;

			case DIO_u8_PORTB:
				switch (copy_u8Direction)
				{
					case DIO_u8_OUTPUT:
						SET_BIT(DIO_u8_DDRB_REG, copy_u8Pin);
						break;
					case DIO_u8_INPUT:
						CLR_BIT(DIO_u8_DDRB_REG, copy_u8Pin);
						break;
				}
				break;

			case DIO_u8_PORTC:
				switch (copy_u8Direction)
				{
					case DIO_u8_OUTPUT:
						SET_BIT(DIO_u8_DDRC_REG, copy_u8Pin);
						break;
					case DIO_u8_INPUT:
						CLR_BIT(DIO_u8_DDRC_REG, copy_u8Pin);
						break;
				}
				break;

			case DIO_u8_PORTD:
				switch (copy_u8Direction)
				{
					case DIO_u8_OUTPUT:
						SET_BIT(DIO_u8_DDRD_REG, copy_u8Pin);
						break;
					case DIO_u8_INPUT:
						CLR_BIT(DIO_u8_DDRD_REG, copy_u8Pin);
						break;
				}
				break;

		} // switch
	} // else

#endif
} //func()


/************************************************************/
/* set PORT Register to decide
 * output state high or low in case the direction is output
 * input state floating or pull up in case the direction is input
 * the above is implemented in bit wise
 */
/************************************************************/

void MDIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8Pin, u8 copy_u8Value)
{


#ifdef SHORT_FUNCTION
if ( 	(copy_u8Pin < DIO_u8_PIN0)	|| (copy_u8PortID < DIO_u8_PORTA) 	||
		(copy_u8Pin > DIO_u8_PIN7) 	|| (copy_u8PortID > DIO_u8_PORTD)			)
{}
else
{
	volatile u8* reg = (volatile u8*) (0x32 + (3 - copy_u8PortID) * 3 );
	INS_BIT(*reg,copy_u8Pin,copy_u8Value);
}

#endif


#ifdef LONG_FUNCTION

	if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA)
			|| (copy_u8Pin > DIO_u8_PIN7) || (copy_u8Pin < DIO_u8_PIN0))
	{

	}

	else
	{
		switch (copy_u8PortID)
		{
			case DIO_u8_PORTA:
				switch (copy_u8Value)
				{
					case DIO_u8_OUTPUT:
						SET_BIT(DIO_u8_PORTA_REG, copy_u8Pin);
						break;
					case DIO_u8_INPUT:
						CLR_BIT(DIO_u8_PORTA_REG, copy_u8Pin);
						break;
				}
				break;

			case DIO_u8_PORTB:
				switch (copy_u8Value)
				{
					case DIO_u8_OUTPUT:
						SET_BIT(DIO_u8_PORTB_REG, copy_u8Pin);
						break;
					case DIO_u8_INPUT:
						CLR_BIT(DIO_u8_PORTB_REG, copy_u8Pin);
						break;
				}
				break;

			case DIO_u8_PORTC:
				switch (copy_u8Value)
				{
					case DIO_u8_OUTPUT:
						SET_BIT(DIO_u8_PORTC_REG, copy_u8Pin);
						break;
					case DIO_u8_INPUT:
						CLR_BIT(DIO_u8_PORTC_REG, copy_u8Pin);
						break;
				}
				break;

			case DIO_u8_PORTD:
				switch (copy_u8Value)
				{
					case DIO_u8_OUTPUT:
						SET_BIT(DIO_u8_PORTD_REG, copy_u8Pin);
						break;
					case DIO_u8_INPUT:
						CLR_BIT(DIO_u8_PORTD_REG, copy_u8Pin);
						break;
				}
				break;

		} // switch
	} // else

#endif
}

/******************************************************/
/* read PIN register to get the input value of the pin
 * in case the pin is output PIN register will contain
 * same value as PORT register
 * the above is implemented in bit wise
 */
/******************************************************/

u8 MDIO_u8GetPinValue(u8 copy_u8PortID, u8 copy_u8Pin)
{

u8 value = 255;

#ifdef SHORT_FUNCTION

if ( 	(copy_u8Pin < DIO_u8_PIN0)	|| (copy_u8PortID < DIO_u8_PORTA) 	||
		(copy_u8Pin > DIO_u8_PIN7) 	|| (copy_u8PortID > DIO_u8_PORTD)			)
{}
else
{
	volatile u8* reg = (volatile u8*) (0x30 + (3 - copy_u8PortID) * 3 );
	value = GET_BIT(*reg,copy_u8Pin);
}

#endif


#ifdef LONG_FUNCTION

if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA)
		|| (copy_u8Pin > DIO_u8_PIN7) || (copy_u8Pin < DIO_u8_PIN0))
{}

else
{
	switch (copy_u8PortID)
	{
		case DIO_u8_PORTA:
			value = GET_BIT(DIO_u8_PINA_REG, copy_u8Pin);
			break;

		case DIO_u8_PORTB:
			value = GET_BIT(DIO_u8_PINB_REG, copy_u8Pin);
			break;

		case DIO_u8_PORTC:
			value = GET_BIT(DIO_u8_PINC_REG, copy_u8Pin);
			break;

		case DIO_u8_PORTD:
			value = GET_BIT(DIO_u8_PIND_REG, copy_u8Pin);
			break;

	} // switch
} // else

#endif

	return value;

}

/**********************************************************/
/* set DDR register which decide the direction of the pin
 * 1 OUTPUT      0 INPUT
 * the above is implemented in port wise
 */
/**********************************************************/

void MDIO_voidSetPortDir(u8 copy_u8PortID, u8 copy_u8Direction)
{
#ifdef SHORT_FUNCTION

if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA))
{}
else
{
	volatile u8* reg = (volatile u8*) (0x31 + (3 - copy_u8PortID) * 3 );
	*reg = copy_u8Direction;
}
#endif

#ifdef LONG_FUNCTION
	if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA))
	{

	}

	else
	{
		switch (copy_u8PortID)
		{
			case DIO_u8_PORTA:
				SET_BYTE(DIO_u8_DDRA_REG, copy_u8Direction);
				break;
			case DIO_u8_PORTB:
				SET_BYTE(DIO_u8_DDRB_REG, copy_u8Direction);
				break;

			case DIO_u8_PORTC:
				SET_BYTE(DIO_u8_DDRC_REG, copy_u8Direction);
				break;
			case DIO_u8_PORTD:
				SET_BYTE(DIO_u8_DDRD_REG, copy_u8Direction);

		} //switch
	} //else
#endif
}


/************************************************************/
/* set PORT Register to decide
 * output state high or low in case the direction is output
 * input state floating or pull up in case the direction is input
 * the above is implemented in port wise
 */
/************************************************************/


void MDIO_voidSetPortValue(u8 copy_u8PortID, u8 copy_u8Value)
{
#ifdef SHORT_FUNCTION

if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA))
{}
else
{
	volatile u8* reg = (volatile u8*) (0x32 + (3 - copy_u8PortID) * 3 );
	*reg = copy_u8Value;
}
#endif

#ifdef LONG_FUNCTION
	if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA))
	{

	}

	else
	{
		switch (copy_u8PortID)
		{
			case DIO_u8_PORTA:
				SET_BYTE(DIO_u8_PORTA_REG, copy_u8Value);
				break;
			case DIO_u8_PORTB:
				SET_BYTE(DIO_u8_PORTB_REG, copy_u8Value);
				break;

			case DIO_u8_PORTC:
				SET_BYTE(DIO_u8_PORTC_REG, copy_u8Value);
				break;
			case DIO_u8_PORTD:
				SET_BYTE(DIO_u8_PORTD_REG, copy_u8Value);

		} //switch
	} //else
#endif
}


/******************************************************/
/* read PIN register to get the input value of the pin
 * in case the pin is output PIN register will contain
 * same value as PORT register
 * the above is implemented in port wise
 */
/******************************************************/

u8 MDIO_u8GetPortValue(u8 copy_u8PortID)
{
	u8 value = 255;

#ifdef SHORT_FUNCTION
if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA))
{}
else
{
	volatile u8* reg = (volatile u8*) (0x30 + (3 - copy_u8PortID) * 3 );
	value = *reg;
}
#endif

#ifdef LONG_FUNCTION
	if ((copy_u8PortID > DIO_u8_PORTD) || (copy_u8PortID < DIO_u8_PORTA))
	{

	}

	else
	{
		switch (copy_u8PortID)
		{
			case DIO_u8_PORTA:
				value = DIO_u8_PINA_REG;
				break;
			case DIO_u8_PORTB:
				value = DIO_u8_PINB_REG;
				break;
			case DIO_u8_PORTC:
				value = DIO_u8_PINC_REG;
				break;
			case DIO_u8_PORTD:
				value = DIO_u8_PIND_REG;
				break;

		} //switch
	} //else

#endif

	return value;

}
