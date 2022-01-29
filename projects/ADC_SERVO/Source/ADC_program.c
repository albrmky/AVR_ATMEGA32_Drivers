/*
 * ADC_program.c
 *
 *  Created on: Jan 17, 2022
 *      Author: noureldeen albrmky
 */
#include "../Include/LIBRARY/bit_math.h"
#include "../Include/LIBRARY/standard_types.h"


#include "../Include/MCAL/ADC/ADC_interface.h"
#include "../Include/MCAL/ADC/ADC_private.h"
#include "../Include/MCAL/ADC/ADC_configuration.h"

#include "../Include/MCAL/DIO/DIO_interface.h"// just for testing

void (*ADC_ISR_PTR)(void) = NULL;



/****************************************************
 1- choose the Vref
 2- type of adjustment
 3- auto trigger state
 4- interrupt state
 5- prescaler
 6- enable the ADC
 */

void MADC_voidInit(void)
{

	//ADMUX
	INS_FIELD(ADC_u8_ADMUX_REG, 3, 6, ADC_VOLTAGE_REFERENCE); //reference
	INS_BIT(ADC_u8_ADMUX_REG, 5, ADC_ADJUSTMENT_TYPE); //adjustment

	/*ADCSRA*/

	// auto trigger state
	INS_BIT(ADC_u8_ADCSRA_REG, ADC_BIT_AUTO_TRIGGER, ADC_AUTO_TRIGGER);

	//interrupt state
	INS_BIT(ADC_u8_ADCSRA_REG, ADC_BIT_INTERRUPT_FLAG, ADC_INTERRUPT_STATE);

	//choose prescaler
	INS_FIELD(ADC_u8_ADCSRA_REG, 7, 0, ADC_PRESCALER);

	// ADC enabled
	INS_BIT(ADC_u8_ADCSRA_REG, ADC_BIT_ENABLE, ADC_ENABLE_STATE);

	// ADC_int source
	INS_FIELD(ADC_u8_SFIOR_REG, 0b111, 5, ADC_TRIGGRE_SOURCE);

}

/*******************************************
 1- select the channel
 2- start conversion
 3- clear interrupt flag if INT is disabled

 ********************************************/

u8 MADC_u8DigitalRead(ADC_INPUT copy_u8InputChannel)
{
	u8 local_u8ReadingValue;
	if (copy_u8InputChannel < 32)
	{
		INS_FIELD(ADC_u8_ADMUX_REG, 0b11111, 0, copy_u8InputChannel); //channel and gain
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_BIT_INTERRUPT_FLAG); // clear it
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_BIT_START_CONVERSION);

		while (GET_BIT(ADC_u8_ADCSRA_REG,ADC_BIT_INTERRUPT_FLAG) == 0)
			;

		SET_BIT(ADC_u8_ADCSRA_REG, ADC_BIT_INTERRUPT_FLAG); // clear it
		local_u8ReadingValue = ADC_u8_ADCH_REG;


	}

	return local_u8ReadingValue;
}


u16 MADC_u16DigitalRead(ADC_INPUT copy_u8InputChannel)
{
	u16 local_u8ReadingValue;
	if (copy_u8InputChannel < 32)
	{
		INS_FIELD(ADC_u8_ADMUX_REG, 0b11111, 0, copy_u8InputChannel); //channel and gain
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_BIT_INTERRUPT_FLAG); // clear it
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_BIT_START_CONVERSION);

		while (GET_BIT(ADC_u8_ADCSRA_REG,ADC_BIT_INTERRUPT_FLAG) == 0)
			;

		SET_BIT(ADC_u8_ADCSRA_REG, ADC_BIT_INTERRUPT_FLAG); // clear it
		local_u8ReadingValue = ADC_u16_ADC_REG;

	}

	return local_u8ReadingValue;
}




u8 MADC_u8Read()
{
	return ADC_u8_ADCH_REG;
}

void MADC_voidInterruptEnable(void (*isr_function_ptr)(void),
		ADC_INPUT copy_u8InputChannel)
{
	if (copy_u8InputChannel < 32)
	{
		INS_FIELD(ADC_u8_ADMUX_REG, 0b11111, 0, copy_u8InputChannel); //channel and gain
		ADC_ISR_PTR = isr_function_ptr;

		SET_BIT(ADC_u8_ADCSRA_REG, ADC_BIT_INTERRUPT_ENABLE);

		SET_BIT(ADC_u8_ADCSRA_REG, ADC_BIT_START_CONVERSION);
	}
}


void __vector_16(void) __attribute__((signal));

void __vector_16(void)
{
	if (ADC_ISR_PTR != NULL)
		ADC_ISR_PTR();
}
