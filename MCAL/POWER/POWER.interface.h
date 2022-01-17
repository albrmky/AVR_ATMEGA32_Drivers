/*
 * POWER.interface.h
 *
 *  Created on: Jan 16, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_POWER_POWER_INTERFACE_H_
#define INCLUDE_MCAL_POWER_POWER_INTERFACE_H_

/*********************************************************
 we use set mode function first
 to prepare the proper option for the required sleep mode
 which is already specified in the configuration mode


 then we use strt sleep whenever we want to start the sleep

 NOTE:
 when the microcontroller back from sleep it execute the
 ISR function first then continue from the instruction following
 the sleep instruction
 **********************************************************/
void MPOWER_voidSetSleepMode();
void MPOWER_voidStartSleep();

#endif /* INCLUDE_MCAL_POWER_POWER_INTERFACE_H_ */
