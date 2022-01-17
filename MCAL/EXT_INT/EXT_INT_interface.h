/*
 * EXT_INT_interface.h
 *
 *  Created on: Jan 11, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_EXT_INT_EXT_INT_INTERFACE_H_
#define INCLUDE_MCAL_EXT_INT_EXT_INT_INTERFACE_H_

typedef enum {
	EXTINT2_FLAG=5,
	EXTINT0_FLAG=6,
	EXTINT1_FLAG=7
}EXTERNAL_INTERRUPT_FLAG;


typedef enum{
	EXTINT_SENSE_LOW_LEVEL,
	EXTINT_SENSE_LOGIC_CHANGE,
	EXTINT_SENSE_FALLING_EDGE,
	EXTINT_SENSE_RISING_EDGE
}EXTINT_SENSE_CONRTROL;

typedef enum{
	EXTINT2_SENSE_FALLING_EDGE, EXTINT2_SENSE_RISING_EDGE
} EXTINT2_SENSE_CONTROL;

typedef enum {
	EXTINT_EXTINT0_INTERRUPT,
	EXTINT_EXTINT1_INTERRUPT,
	EXTINT_EXTINT2_INTERRUPT
}EXTINT_fun_INTERRUPT;


/*********************************************
 pay great attention when using the macro type

 notes:

 use  assign function then init function
 or

 assign function then enable function

 or

 read then clear by polling methods

 *********************************************/
void MEXTINT_voidInit(void);
u8 MEXTINT_u8ReadFlag(EXTERNAL_INTERRUPT_FLAG flag);
void MEXTINT_voidClearFlag(EXTERNAL_INTERRUPT_FLAG flag);
void MEXTINT_voidEnable(EXTERNAL_INTERRUPT_FLAG copy_u8InterruptNumber, EXTINT_SENSE_CONRTROL copy_u8SenseControl);
void MEXTINT_voidAssignIntFun(EXTINT_fun_INTERRUPT copy_enumNumber, void(*copy_fptr)(void) );
void MEXTINT_voidDisable(EXTERNAL_INTERRUPT_FLAG copy_u8InterruptNumber);



#endif /* INCLUDE_MCAL_EXT_INT_EXT_INT_INTERFACE_H_ */
