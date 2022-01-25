/*
 * TIMER0_private.h
 *
 *  Created on: Jan 18, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_TIMER0_PRIVATE_H_
#define INCLUDE_MCAL_TIMER0_PRIVATE_H_



#define TIMER0_TIMSK_REG 	*((volatile u8*)(0x59))
#define TIMER0_TIFR_REG 	*((volatile u8*)(0x58))

#define TIMER0_OCR0_REG  	*((volatile u8*)(0x5c))

#define TIMER0_TCCR0_REG 	*((volatile u8*)(0x53))

#define TIMER0_TCNT0_REG 	*((volatile u8*)(0x52))


/* options for the timer clock source*/
#define TIMER0_NO_CLOCK					0
#define TIMER0_CLKIO					1
#define TIMER0_CLK_8					2
#define TIMER0_CLK_64					3
#define TIMER0_CLK_256					4
#define TIMER0_CLK_1024					5
#define TIMER0_EXTERNAL_FALLING_EDGE	6
#define TIMER0_EXTERNAL_RISING_EDGE		7

/* options for timer operation mode*/

#define TIMER0_NORMAL_MODE				0
#define TIMER0_PHASE_CORRECT_PWM		1
#define TIMER0_CLEAR_TIMER_ON_COMPARE	2
#define TIMER0_FAST_PWM					3

#define TIMER0_OC0_DISCONNECTED		0

//#if (TIMER0_OPERATING_MODE == TIMER0_NORMAL_MODE) || (TIMER0_OPERATING_MODE == TIMER0_CLEAR_TIMER_ON_COMPARE)


#define TIMER0_OC0_TOGGLE			1
#define TIMER0_OC0_CLEAR			2
#define TIMER0_OC0_SET				3

//#elif	(TIMER0_OPERATING_MODE == TIMER0_FAST_PWM) || (TIMER0_OPERATING_MODE == TIMER0_PHASE_CORRECT_PWM)

#define TIMER0_OC0_NON_INVERTING	2
#define TIMER0_OC0_INVERTING		3

//#endif


#define TIMER0_BIT_OVERFLOW_FLAG	0
#define TIMER0_BIT_COMPARE_FLAG		1

#define TIMER0_BIT_OVERFLOW_ENABLE	0
#define TIMER0_BIT_COMPARE_ENABLE	1


#define TIMER0_BIT_WGM01	3
#define TIMER0_BIT_WGM00	6

#define TIMER0_FIELD_CLOCK	0
#define TIMER0_FIELD_COM_MODE	4

#endif /* INCLUDE_MCAL_TIMER0_PRIVATE_H_ */
