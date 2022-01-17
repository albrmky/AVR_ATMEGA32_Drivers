/*
 * POWER.private.h
 *
 *  Created on: Jan 16, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_POWER_POWER_PRIVATE_H_
#define INCLUDE_MCAL_POWER_POWER_PRIVATE_H_

/********************************************************
 register address
 &
 bit field options
 &
 bit numbers
 *********************************************************/
#define POWER_MCUCR_REG *( (volatile u8*)(0x55) )

#define POWER_SLEEP_MODE_IDLE 				0
#define POWER_SLEEP_MODE_ADC				1
#define POWER_SLEEP_MODE_POWER_DOWN			2
#define POWER_SLEEP_MODE_POWER_SAVE			3
#define POWER_SLEEP_MODE_STANDBY			6
#define POWER_SLEEP_MODE_EXTENDED_STANDBY	7

#define POWER_SLEEP_ENABLE_BIT				7

#define BIT_FIELD_MASK						7
#define BIT_FIELD_SHIFT						4

#endif /* INCLUDE_MCAL_POWER_POWER_PRIVATE_H_ */
