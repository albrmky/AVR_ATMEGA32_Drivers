/*
 * EXT_INT_configuration.h
 *
 *  Created on: Jan 11, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_EXT_INT_EXT_INT_CONFIGURATION_H_
#define INCLUDE_MCAL_EXT_INT_EXT_INT_CONFIGURATION_H_



/*********************************************************
Enabling the External interrupt

options:

EXTINT_ENABLE			EXTINT_DISABLE
**********************************************************/
#define EXTINT0_STATE	EXTINT_DISABLE
#define EXTINT1_STATE	EXTINT_DISABLE
#define EXTINT2_STATE	EXTINT_DISABLE



/********************************************************
			setting Control sense for INT0 and INT1

options:
EXTINT_LOW_LEVEL_SENSE
EXTINT_LOGIC_CHANGE
EXTINT_FALLING_EDGE
EXTINT_RISING_EDGE
*********************************************************/
#define EXTINT0_SENSE_TYPE	EXTINT_FALLING_EDGE
#define EXTINT1_SENSE_TYPE	EXTINT_FALLING_EDGE



/********************************************************
			setting Control sense for INT2

options:
EXTINT2_FALLING_EDGE			EXTINT2_RISING_EDGE
*********************************************************/
#define EXTINT2_SENSE_TYPE	EXTINT2_FALLING_EDGE



#endif /* INCLUDE_MCAL_EXT_INT_EXT_INT_CONFIGURATION_H_ */
