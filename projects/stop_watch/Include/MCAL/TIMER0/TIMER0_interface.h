/*
 * TIMER0_interface.h
 *
 *  Created on: Jan 18, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_
#define INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_


typedef enum {
	TIMER0_OVERFLOW, TIMER0_COMPARE
} TIMER0_EVENT_TYPE;

typedef enum {
	TIMER0_DISABLE, TIMER0_ENABLE
} TIMER0_STATE;


// set the mode of the time to operate
// start the timer clock to any source from those
//specified in the configuration file
void MTIMER0_voidInit(void);

// used with non-pwm modes
// its usage still a mystery
void MTIMER_voidForceOutputCompareBit();

//write value to the timer register
void MTIMER0_voidWriteTimerRegister(u8 copy_u8Value);

// write any value to output capture register
void MTIMER0_voidWriteOCRegister(u8 copy_u8Value);

// read any of the two flags
// usually used in polling conditions
u8 MTIMER0_u8ReadFlag(TIMER0_EVENT_TYPE copy_u8flag);

// enable or disable  interrupt for any of the two available timer events
void MTIMER0_voidControlInterrupt(TIMER0_EVENT_TYPE copy_u8Int, TIMER0_STATE copy_u8state);

// pass the pointer to be used in over flow event
void MTIMER0_voidAssignOverflowISR(void (*ISRptr)(void));

// pass the pointer to the function to be used for compare match event
void MTIMER0_voidAssignCompareISR(void (*ISRptr)(void));

// stop timer
void MTIMER0_voidStopTimer(void);


#endif /* INCLUDE_MCAL_TIMER0_TIMER0_INTERFACE_H_ */
