/*
 * TIMER1_configuration.h
 *
 *  Created on: Jan 18, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_CONFIGURATION_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_CONFIGURATION_H_


/***********************************************
 deciding the clock source for time_1

 options:
 TIMER1_NO_CLOCK
 TIMER1_CLKIO
 TIMER1_CLK_8
 TIMER1_CLK_64
 TIMER1_CLK_256
 TIMER1_CLK_1024
 TIMER1_EXTERNAL_FALLING_EDGE	// on T1 [PB1]
 TIMER1_EXTERNAL_RISING_EDGE		// on T1 [PB1]
 ***********************************************/
#define TIMER1_CLOCK_SOURCE				TIMER1_CLKIO



/*****************************************************
 Mode of operation of the timer
 options:

 TIMER1_NORMAL_MODE 						// free running mode from 0-> 0xFF

 TIMER1_CTC_OCR1A							// Clear timer on compare with OCR1A
 TIMER1_CTC_ICR1							// Clear timer on compare with ICR1

 TIMER1_PWM_PHASE_CORRECT_8_BIT				// count from  0 -> 0xFF
 TIMER1_PWM_PHASE_CORRECT_9_BIT				// count from  0 -> 0x1FF
 TIMER1_PWM_PHASE_CORRECT_10_BIT			// count from  0 -> 0x3FF
 TIMER1_PWM_PHASE_CORRECT_ICR1				// count from  0 -> ICR1
 TIMER1_PWM_PHASE_CORRECT_OCR1A				// count from  0 -> OCR1A

 TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1		  	// count from  0 -> ICR1
 TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A      	// count from  0 -> OCR1A

 TIMER1_FAST_PWM_8_BIT        				// count from  0 -> 0xFF
 TIMER1_FAST_PWM_9_BIT       			 	// count from  0 -> 0x1FF
 TIMER1_FAST_PWM_10_BIT      			 	// count from  0 -> 0x3FF
 TIMER1_FAST_PWM_ICR1        			 	// count from  0 -> ICR1
 TIMER1_FAST_PWM_OCR1A        				// count from  0 -> OCR1A
 *****************************************************/
#define TIMER1_OPERATION_MODE		TIMER1_FAST_PWM_ICR1


/*********************************************************
 mode of OCx pin on different modes		>>>>>>>>>>>>>> OC1A [PD5]  OC1B  [PD4]  ICP1  [PD6] <<<<<<<<<<

 >>>	TIMER1_OC1n_DISCONNECTED	<<<

 options: // for non PWM mode (CTC and normal)

 >>>	TIMER1_OC1n_TOGGLE			<<<
 >>>	TIMER1_OC1n_CLEAR_ON_MATCH	<<<
 >>>	TIMER1_OC1n_SET_ON_MATCH	<<<

 options: // for PWM modes (Fast / phase / phase and frequency)

 >>>	TIMER1_OC1A_PWM_TOGGLE		<<<		//work with PWM modes when OCR1A is the top otherwise not connected OC1A only
 >>>	TIMER1_NON_INVERTING		<<< 	// clear on compare or clear on compare when counting up
 >>>	TIMER1_INVERTING			<<< 	// set   on compare or set   on compare when counting down
 *********************************************************/
#define TIMER1_COMPARE_MATCH_MODE_A	TIMER1_NON_INVERTING
#define TIMER1_COMPARE_MATCH_MODE_B	TIMER1_OC1n_DISCONNECTED


#endif /* INCLUDE_MCAL_TIMER1_TIMER1_CONFIGURATION_H_ */
