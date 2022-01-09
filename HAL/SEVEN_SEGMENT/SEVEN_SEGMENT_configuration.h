/*
 * SEVEN_SEGMENT_configuration.h
 *
 *  Created on: Jan 4, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INC_HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_CONFIGURATION_H_
#define INC_HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_CONFIGURATION_H_






/*********************************************************************
		specify which DIO port we connect the 7 segment on
 options:

		DIO_u8_PORTA	DIO_u8_PORTB	DIO_u8_PORTC	DIO_u8_PORTD
**********************************************************************/
#define SEVSEG_u8_PORT 	DIO_u8_PORTB



/*******************************************************************
						type of seven segment
options:

 	SEVSEG_COMMON_CATHOD				SEVSEG_COMMON_ANODE
********************************************************************/
#define SEVSEG_u8_TYPE	SEVSEG_COMMON_ANODE



/********************************************************************
				how the segment is connected on port
options:

	SEVSEG_A_ON_PIN0					SEVSEG_A_ON_PIN7

Usage:

	specify the number pattern according to the connection
*********************************************************************/
#define SEVSEG_u8_CONNECTION_TYPE	SEVSEG_A_ON_PIN7


/********************************************************************
 displayed number pattern according to the type of the connection
*********************************************************************/
#if SEVSEG_u8_CONNECTION_TYPE == SEVSEG_A_ON_PIN7

		#define SEVSEG_u8_NUMBER_ZERO  0b11111100
		#define SEVSEG_u8_NUMBER_ONE   0b01100000
		#define SEVSEG_u8_NUMBER_TWO   0b11011010
		#define SEVSEG_u8_NUMBER_THREE 0b11110010
		#define SEVSEG_u8_NUMBER_FOUR  0b01100110
		#define SEVSEG_u8_NUMBER_FIVE  0b10110110
		#define SEVSEG_u8_NUMBER_SIX   0b00111110
		#define SEVSEG_u8_NUMBER_SEVEN 0b11100000
		#define SEVSEG_u8_NUMBER_EIGHT 0b11111110
		#define SEVSEG_u8_NUMBER_NINE  0b11100110


#elif SEVSEG_u8_CONNECTION_TYPE == SEVSEG_A_ON_PIN0

		#define SEVSEG_u8_NUMBER_ZERO  0b00111111
		#define SEVSEG_u8_NUMBER_ONE   0b00000110
		#define SEVSEG_u8_NUMBER_TWO   0b01011011
		#define SEVSEG_u8_NUMBER_THREE 0b01001111
		#define SEVSEG_u8_NUMBER_FOUR  0b01100110
		#define SEVSEG_u8_NUMBER_FIVE  0b01101101
		#define SEVSEG_u8_NUMBER_SIX   0b01111100
		#define SEVSEG_u8_NUMBER_SEVEN 0b00000111
		#define SEVSEG_u8_NUMBER_EIGHT 0b01111111
		#define SEVSEG_u8_NUMBER_NINE  0b01100111

#endif


#endif /* INC_HAL_SEVEN_SEGMENT_SEVEN_SEGMENT_CONFIGURATION_H_ */
