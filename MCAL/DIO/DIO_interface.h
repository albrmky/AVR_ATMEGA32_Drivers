/*
 * DIO_interface.h
 *
 *  Created on: Jan 3, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INC_MCAL_DIO_DIO_INTERFACE_H_
#define INC_MCAL_DIO_DIO_INTERFACE_H_


#define DIO_u8_PORTA	0
#define DIO_u8_PORTB	1
#define DIO_u8_PORTC	2
#define DIO_u8_PORTD	3

#define DIO_u8_PIN0		0
#define DIO_u8_PIN1		1
#define DIO_u8_PIN2		2
#define DIO_u8_PIN3		3
#define DIO_u8_PIN4		4
#define DIO_u8_PIN5		5
#define DIO_u8_PIN6		6
#define DIO_u8_PIN7		7

#define DIO_u8_OUTPUT 	1
#define DIO_u8_INPUT	0

#define DIO_u8_HIGH		1
#define DIO_u8_LOW		0

/****************************************************/
/*		Functions prototype							*/
/****************************************************/

void MDIO_voidInit(void);



void MDIO_voidSetPinDir(u8 copy_u8PortID, u8 copy_u8Pin, u8 copy_u8Direction);
void MDIO_voidSetPinValue(u8 copy_u8PortID, u8 copy_u8Pin, u8 copy_u8Value);
u8 MDIO_u8GetPinValue(u8 copy_u8PortID, u8 copy_u8Pin);


void MDIO_voidSetPortDir(u8 copy_u8PortID, u8 copy_u8u8Direction);
void MDIO_voidSetPortValue(u8 copy_u8PortID, u8 copy_u8u8Direction);
u8	 MDIO_u8GetPortValue(u8 copy_u8PortID);



#endif /* INC_MCAL_DIO_DIO_INTERFACE_H_ */
