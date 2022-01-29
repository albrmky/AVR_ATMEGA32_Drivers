/*
 * TIMER1_interface.h
 *
 *  Created on: Jan 18, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_

typedef enum {
	TIMER1_OVERFLOW, TIMER1_COMPARE_B, TIMER1_COMPARE_A, TIMER1_INPUT_CAPTURE
} TIMER1_EVENT_TYPE;

typedef enum {
	TIMER1_DISABLE, TIMER1_ENABLE
} TIMER1_STATE;

void HSERVO(s16 angle);

void MTIMER1_voidInit(void);

void MTIMER1_voidControlInterrupt(TIMER1_EVENT_TYPE copy_u8Int, TIMER1_STATE copy_u8state);
void MTIMER1_voidAssignCallBack(TIMER1_EVENT_TYPE copy_u8event, void (*ptr)(void));


u16 MTIMER1_u16ReadTimerRegister(void);
u16 MTIMER1_u16ReadICRRegister(void);

void MTIMER1_voidWriteTimerRegister(u16 copy_u8Value);
void MTIMER1_voidWriteOCR_A_Register(u16 copy_u8Value);
void MTIMER1_voidWriteOCR_B_Register(u16 copy_u8Value);
void MTIMER1_voidWriteICRRegister(u16 copy_u8Value);

u8 MTIIMER1_u8ReadFlag(TIMER1_EVENT_TYPE copy_u8flag);
void MTIIMER1_voidClearFlag(TIMER1_EVENT_TYPE copy_u8flag);

void MTIMER1_voidForceCompare_A(void);
void MTIMER1_voidForceCompare_B(void);



#endif /* INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_ */
