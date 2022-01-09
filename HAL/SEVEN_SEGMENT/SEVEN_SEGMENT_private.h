/*
 * SEVEN_SEGMENT_private.h
 *
 *  Created on: Jan 4, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INC_HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_PRIVATE_H_
#define INC_HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_PRIVATE_H_

//#define SEVSEG_u8_PORTA 		0
//#define SEVSEG_u8_PORTB 		1
//#define SEVSEG_u8_PORTC 		2
//#define SEVSEG_u8_PORTD 		3


/***********************************************************
options for:
 	 	 SEVSEG_u8_TYPE macro
at the configuration file
************************************************************/
#define SEVSEG_COMMON_CATHOD	0
#define SEVSEG_COMMON_ANODE		1


/***********************************************************
options for:
		SEVSEG_u8_CONNECTION_TYPE macro
at the configuration file
************************************************************/
#define SEVSEG_A_ON_PIN0			1
#define SEVSEG_A_ON_PIN7			0




#endif /* INC_HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_PRIVATE_H_ */
