/*
 * TIMER1_private.h
 *
 *  Created on: Jan 18, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_



#define TIMER1_TIMSK_u8_REG 	*((volatile u8*)(0x59))
#define TIMER1_TIFR_u8_REG 		*((volatile u8*)(0x58))

#define TIMER1_TCCR1A_u8_REG  	*((volatile u8*)(0x4F))
#define TIMER1_TCCR1B_u8_REG  	*((volatile u8*)(0x4E))


#define TIMER1_TCNT1_u16_REG 	*((volatile u16*)(0x4C))
#define TIMER1_OCR1A_u16_REG 	*((volatile u16*)(0x4A))
#define TIMER1_OCR1B_u16_REG 	*((volatile u16*)(0x48))
#define TIMER1_ICR1_u16_REG 	*((volatile u16*)(0x46))

/* options for clock source */
#define TIMER1_NO_CLOCK					0
#define TIMER1_CLKIO					1
#define TIMER1_CLK_8					2
#define TIMER1_CLK_64					3
#define TIMER1_CLK_256					4
#define TIMER1_CLK_1024					5
#define TIMER1_EXTERNAL_FALLING_EDGE	6
#define TIMER1_EXTERNAL_RISING_EDGE		7

/* options for mode of operation */
#define TIMER1_NORMAL_MODE					0
#define TIMER1_PWM_PHASE_CORRECT_8_BIT		1
#define TIMER1_PWM_PHASE_CORRECT_9_BIT		2
#define TIMER1_PWM_PHASE_CORRECT_10_BIT		3
#define TIMER1_CTC_OCR1A					4
#define TIMER1_FAST_PWM_8_BIT				5
#define TIMER1_FAST_PWM_9_BIT				6
#define TIMER1_FAST_PWM_10_BIT				7
#define TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1	8
#define TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A	9
#define TIMER1_PWM_PHASE_CORRECT_ICR1		10
#define TIMER1_PWM_PHASE_CORRECT_OCR1A		11
#define TIMER1_CTC_ICR1						12
#define TIMER1_FAST_PWM_ICR1				14
#define TIMER1_FAST_PWM_OCR1A				15


/* options of output on compare*/
#define TIMER1_OC1n_DISCONNECTED			0

#define TIMER1_OC1n_TOGGLE					1
#define TIMER1_OC1n_CLEAR_ON_MATCH			2
#define TIMER1_OC1n_SET_ON_MATCH			3

#define TIMER1_OC1A_TOGGLE					1
#define TIMER1_NON_INVERTING				2
#define TIMER1_INVERTING					3



#define TIMER1_BIT_OVERFLOW					2
#define TIMER1_BIT_OC1B						3
#define TIMER1_BIT_OC1A						4
#define TIMER1_BIT_IC						5

#endif /* INCLUDE_MCAL_TIMER1_TIMER1_PRIVATE_H_ */
