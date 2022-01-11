/*
 * KEYPAD_configuration.h
 *
 *  Created on: Jan 9, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_
#define INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_

/***************************************************************************
specify the port where keypad is connected
options:
	DIO_u8_PORTA	DIO_u8_PORTA	DIO_u8_PORTA	DIO_u8_PORTA
***************************************************************************/
#define KEYPAD_PORT		DIO_u8_PORTC


/***************************************************************************
specify where each pin of the keypad is connected which port pin
options:
	DIO_u8_PIN0 : DIO_u8_PIN7
***************************************************************************/
#define KEYPAD_R1_PIN	DIO_u8_PIN0
#define KEYPAD_R2_PIN	DIO_u8_PIN1
#define KEYPAD_R3_PIN	DIO_u8_PIN2
#define KEYPAD_R4_PIN	DIO_u8_PIN3

#define KEYPAD_C1_PIN	DIO_u8_PIN4
#define KEYPAD_C2_PIN	DIO_u8_PIN5
#define KEYPAD_C3_PIN	DIO_u8_PIN6
#define KEYPAD_C4_PIN	DIO_u8_PIN7



/**************************************************************************
specify the  characteristics of the keypad
e.g. 1- rows and columns sizes
	 2- character at each position
***************************************************************************/
#define KEYPAD_ROW_NUM	4
#define KEYPAD_COL_NUM	4
#define KEYPAD_Au8BUTTONS {	{'7','8','9','/'}, \
							{'4','5','6','*'}, \
							{'1','2','3','-'}, \
							{'C','0','=','+'}  }


/***********************************************************************
Debounce time for the buttons in milliseconds
***********************************************************************/
#define KEYPAD_DEBOUNCE		20



/*************************************************************************
collect the keypad pin in one array to access them more easily
**************************************************************************/
#define KEYPAD_Au8ROWS {KEYPAD_R1_PIN,\
						KEYPAD_R2_PIN,\
						KEYPAD_R3_PIN,\
						KEYPAD_R4_PIN	}


#define KEYPAD_Au8COLS {KEYPAD_C1_PIN,\
						KEYPAD_C2_PIN,\
						KEYPAD_C3_PIN,\
						KEYPAD_C4_PIN	}


#endif /* INCLUDE_HAL_KEYPAD_KEYPAD_CONFIGURATION_H_ */
