/*
 * EXT_INT_private.h
 *
 *  Created on: Jan 11, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_EXT_INT_EXT_INT_PRIVATE_H_
#define INCLUDE_MCAL_EXT_INT_EXT_INT_PRIVATE_H_

/***********************************************************
 registers addresses
 ***********************************************************/
#define EXTINT_MCUCR_REG	*((volatile u8*)0x55)
#define EXTINT_MCUCSR_REG	*((volatile u8*)0x54)

#define EXTINT_GICR_REG		*((volatile u8*)0x5B)
#define EXTINT_GIFR_REG		*((volatile u8*)0x5A)

/*******************************************************
 MCUCR bits number to be used in the configuration file
 ********************************************************/
#define EXTINT_INT0_BIT		6
#define EXTINT_INT1_BIT		7
#define EXTINT_INT2_BIT		5

/*******************************************************
 MCUCSR bits number to be used in the configuration file
 ********************************************************/
#define EXTINT2_CONTROL_SENSE_BIT	6

/********************************************************
 Configuration options
 *********************************************************/
#define EXTINT_LOW_LEVEL_SENSE		00
#define EXTINT_LOGIC_CHANGE			01
#define EXTINT_FALLING_EDGE			10
#define EXTINT_RISING_EDGE			11

#define EXTINT2_FALLING_EDGE	0
#define EXTINT2_RISING_EDGE		1


#define EXTINT_ENABLE	1
#define EXTINT_DISABLE	0

#endif /* INCLUDE_MCAL_EXT_INT_EXT_INT_PRIVATE_H_ */
