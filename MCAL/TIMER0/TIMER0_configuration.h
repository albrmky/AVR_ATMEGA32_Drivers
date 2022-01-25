/*
 * TIMER0_configuration.h
 *
 *  Created on: Jan 18, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_CONFIGURATION_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_CONFIGURATION_H_

/*************************************
 the clock source for the timer

 options:

 TIMER0_NO_CLOCK
 TIMER0_CLKIO
 TIMER0_CLK_8
 TIMER0_CLK_64
 TIMER0_CLK_256
 TIMER0_CLK_1024
 TIMER0_EXTERNAL_FALLING_EDGE  		// [T0] pin PB0
 TIMER0_EXTERNAL_RISING_EDGE		// [T0] pin PB0
 *************************************/
#define TIMER0_CLOCK_SOURCE	TIMER0_EXTERNAL_FALLING_EDGE


/************************************
 choose the mode of operation
 options:

 TIMER0_NORMAL_MODE
 TIMER0_PHASE_CORRECT_PWM
 TIMER0_CLEAR_TIMER_ON_COMPARE // with toggle and no prescaler largest frequency is Fclk/2
 TIMER0_FAST_PWM
 ************************************/
#define TIMER0_OPERATING_MODE	TIMER0_CLEAR_TIMER_ON_COMPARE

/**************************************
 the mode of OC0 pin with respect to the operating mode [ PB3 ]

 options: in non-PWM modes:

 TIMER0_OC0_DISCONNECTED
 TIMER0_OC0_TOGGLE
 TIMER0_OC0_CLEAR
 TIMER0_OC0_SET

 options: in PWM mode
 // clear on compare , set on bottom  in FAST PWM
 // PHASE correction PWM
 // clear on compare while counting down
 // set on compare while counting up

 TIMER0_OC0_DICONNECTED
 TIMER0_OC0_NON_INVERTING
 TIMER0_OC0_INVERTING 		// in fast PWM set on compare , clear on bottom

 **************************************/
#define TIMER0_COMPARE_MATCH_MODE	 TIMER0_OC0_TOGGLE


#endif /* INCLUDE_MCAL_TIMER0_TIMER0_CONFIGURATION_H_ */
