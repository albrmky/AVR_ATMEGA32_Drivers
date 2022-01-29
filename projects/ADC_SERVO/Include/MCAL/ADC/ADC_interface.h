/*
 * ADC_interface.h
 *
 *  Created on: Jan 17, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_ADC_ADC_INTERFACE_H_
#define INCLUDE_MCAL_ADC_ADC_INTERFACE_H_

typedef enum {

	ADC_INPUT_ADC0,
	ADC_INPUT_ADC1,
	ADC_INPUT_ADC2,
	ADC_INPUT_ADC3,
	ADC_INPUT_ADC4,
	ADC_INPUT_ADC5,
	ADC_INPUT_ADC6,
	ADC_INPUT_ADC7
} ADC_INPUT;

/*************************************************************
 useage
 method1
 1- init
 2- digital read

 method2
 1- init
 2- interrupt enable
 3- read from inside ISR
 **************************************************************/


/* according to the configuration file */
void MADC_voidInit(void);

/* read with polling and nointerrupt*/
u8 MADC_u8DigitalRead(ADC_INPUT copy_u8InputChannel);

/* only read register */
u8 MADC_u8Read();

/* assign isr function and enable the interrupt */
void MADC_voidInterruptEnable(void (*isr_function_ptr)(void),
		ADC_INPUT copy_u8InputChannel);

u16 MADC_u16DigitalRead(ADC_INPUT copy_u8InputChannel);


#endif /* INCLUDE_MCAL_ADC_ADC_INTERFACE_H_ */
