/*
 * ADC_private.h
 *
 *  Created on: Jan 17, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_ADC_ADC_PRIVATE_H_
#define INCLUDE_MCAL_ADC_ADC_PRIVATE_H_



#define ADC_u8_SFIOR_REG	*((volatile u8*)(0x50))
#define ADC_u8_ADCL_REG		*((volatile u8*)(0x24))
#define ADC_u8_ADCH_REG		*((volatile u8*)(0x25))
#define ADC_u8_ADCSRA_REG	*((volatile u8*)(0x26))
#define ADC_u8_ADMUX_REG	*((volatile u8*)(0x27))

#define ADC_u16_ADC_REG		*((volatile u16*)(0x24))




/*ADC_VOLTAGE_REFERENCE*/
#define ADC_VREF_AREF			0
#define ADC_VREF_AVCC			1
#define ADC_VREF_INTERNAL		3


#define ADC_LEFT_ADJUSTMENT		1
#define ADC_RIGHT_ADJUSTMENT	0


#define ADC_SINGLE_ADC0			0
#define ADC_SINGLE_ADC1			1
#define ADC_SINGLE_ADC2			2
#define ADC_SINGLE_ADC3			3
#define ADC_SINGLE_ADC4			4
#define ADC_SINGLE_ADC5			5
#define ADC_SINGLE_ADC6			6
#define ADC_SINGLE_ADC7			7
#define ADC_DIFF_P0_N0_G10		8
#define ADC_DIFF_P1_N0_G10		9
#define ADC_DIFF_P0_N0_G200		10
#define ADC_DIFF_P1_N0_G200		11
#define ADC_DIFF_P2_N2_G10		12
#define ADC_DIFF_P3_N2_G10		13
#define ADC_DIFF_P2_N2_G200		14
#define ADC_DIFF_P3_N2_G200		15
#define ADC_DIFF_P0_N1			16
#define ADC_DIFF_P1_N1			17
#define ADC_DIFF_P2_N1			18
#define ADC_DIFF_P3_N1			19
#define ADC_DIFF_P4_N1			20
#define ADC_DIFF_P5_N1			21
#define ADC_DIFF_P6_N1			22
#define ADC_DIFF_P7_N1			23
#define ADC_DIFF_P0_N2			24
#define ADC_DIFF_P1_N2			25
#define ADC_DIFF_P2_N2			26
#define ADC_DIFF_P3_N2			27
#define ADC_DIFF_P4_N2			28
#define ADC_DIFF_P5_N2			29
#define ADC_SINGLE_V_BAND_GAB	30
#define ADC_SINGLE_GND			31

/* to be continued*/


#define ADC_ENABLE				1
#define ADC_DISABLE				0


//ADCSRA bits
#define ADC_BIT_ENABLE				7
#define ADC_BIT_START_CONVERSION	6
#define ADC_BIT_AUTO_TRIGGER		5
#define ADC_BIT_INTERRUPT_FLAG		4
#define ADC_BIT_INTERRUPT_ENABLE	3



/*ADC_PRESCALER*/
#define ADC_DIVIDE_2		1
#define ADC_DIVIDE_4		2
#define ADC_DIVIDE_8		3
#define ADC_DIVIDE_16		4
#define ADC_DIVIDE_32		5
#define ADC_DIVIDE_64		6
#define ADC_DIVIDE_128		7


/* trigger sources*/
#define ADC_TSOURCE_FREE_RUNNING	0
#define ADC_ANALOG_COMPARATOR       1
#define ADC_EXTINT0                 2
#define ADC_TIMER0_COMPARE_MATCH    3
#define ADC_TIMER0_OVERFLOW         4
#define ADC_TIMER1_COMPARE_MATCHB   5
#define ADC_TIMER1_OVERFLOW         6
#define ADC_TIMER1_CAPTURE_EVENT    7


#endif /* INCLUDE_MCAL_ADC_ADC_PRIVATE_H_ */
