/*
 * LCD_program.c
 *
 *  Created on: Jan 4, 2022
 *      Author: noureldeen albrmky
 */

#include "../Include/LIBRARY/standard_types.h"
#include "../Include/LIBRARY/bit_math.h"

#include "../Include/MCAL/DIO/DIO_interface.h"

#include "../Include/HAL/LCD/LCD_interface.h"
#include "../Include/HAL/LCD/LCD_private.h"
#include "../Include/HAL/LCD/LCD_configuration.h"

#include <util/delay.h>

/****************************************************************************
1 - All other functions depend on two functions SendCommand and SendData
2 - SH bit in entry mode command cause problems???????
*****************************************************************************/



/************************************************************************
initialize the LCD (this order specified in the data sheet
************************************************************************/
void HLCD_voidInit(void)
{

	_delay_ms(LCD_INITIALIZATION_DELAY);


	/* this extra nibble is needed in the initialization
	 according to the data sheet at 4-bit mode*/
#if LCD_INTERFACE_DATA_LENGTH ==  LCD_4_BITS_MODE
	HLCD_voidSendCommand(LCD_COMMAND_FUNCTION_SET>>4);
#endif

	// this sequence is according to data sheet
	HLCD_voidSendCommand(LCD_COMMAND_FUNCTION_SET);
	HLCD_voidSendCommand(LCD_COMMAND_DISPLAY_CONTROL);
	HLCD_voidSendCommand(LCD_COMMAND_CLEAR_DISPLAY);
	HLCD_voidSendCommand(LCD_COMMAND_ENTRY_SET);
}


/************************************************************************
send command to LCD
************************************************************************/
void HLCD_voidSendCommand(u8 copy_u8Command)
{
#if LCD_INTERFACE_DATA_LENGTH == LCD_8_BITS_MODE


#if LCD_WAITING_TYPE == LCD_WAIT_FLAG

	while(HLCD_u8GetFlag());

#elif LCD_WAITING_TYPE == LCD_DELAY_FUN

	_delay_ms(LCD_SLOW_COMMAND_DELAY);
#endif

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_LOW);//select instruction register
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);//write mode
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);// E rising edge

#if LCD_WAITING_TYPE == LCD_WAIT_FLAG
	// set port output again after being input for reading the flag
	MDIO_voidSetPortDir(LCD_Data_PORT,0xFF);
#endif

	MDIO_voidSetPortValue(LCD_Data_PORT,copy_u8Command);//send command
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);// E falling edge

#elif	LCD_INTERFACE_DATA_LENGTH == LCD_4_BITS_MODE

	/* first nibble */
	_delay_ms(LCD_SLOW_COMMAND_DELAY);

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_LOW);// select instruction register
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);// write mode
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);// Enable rising edge


	MDIO_voidSetPortValue(LCD_Data_PORT,copy_u8Command);// send command
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);// E falling edge

	/* second nibble */
	_delay_ms(LCD_SLOW_COMMAND_DELAY);

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_LOW);// select instruction register
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);// write mode
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);// Enable rising edge


	MDIO_voidSetPortValue(LCD_Data_PORT,copy_u8Command<<4);// send command
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);// E falling edge

#endif

}


/************************************************************************
send Data to LCD
************************************************************************/
void HLCD_voidSendData(u8 copy_u8Char)
{

#if LCD_INTERFACE_DATA_LENGTH == LCD_8_BITS_MODE


#if LCD_WAITING_TYPE == LCD_WAIT_FLAG
	while(HLCD_u8GetFlag());

#elif LCD_WAITING_TYPE == LCD_DELAY_FUN

	_delay_ms(LCD_SLOW_COMMAND_DELAY);
#endif

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_HIGH);//select data register
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);//	write mode
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);// E rising edge

#if LCD_WAITING_TYPE == LCD_WAIT_FLAG
	// set port output again after being input for reading the flag
	MDIO_voidSetPortDir(LCD_Data_PORT,0xFF);
#endif

	MDIO_voidSetPortValue(LCD_Data_PORT,copy_u8Char); // send data
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);// E falling edge

#elif	LCD_INTERFACE_DATA_LENGTH == LCD_4_BITS_MODE

	/* first nibble */
	_delay_ms(LCD_SLOW_COMMAND_DELAY);

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_HIGH);// select data register
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);//write mode
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);// E rising edge

	MDIO_voidSetPortValue(LCD_Data_PORT,copy_u8Char);// send data first nibble
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);//E falling edge

	/* second nibble */
	_delay_ms(LCD_SLOW_COMMAND_DELAY);

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_HIGH);// select data register
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_LOW);//write mode
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);// E rising edge

	MDIO_voidSetPortValue(LCD_Data_PORT,copy_u8Char<<4);// send data second nibble
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);//E falling edge

#endif
}




/************************************************************************
display string
************************************************************************/
void HLCD_voidDisplayString(u8* copy_pu8String)
{
	while( *copy_pu8String !='\0')
	{
		HLCD_voidSendData(*copy_pu8String++);
	}
}



/************************************************************************
display number
************************************************************************/
void HLCD_voidDisplayNumber(s32 copy_s32Number)
{
	s32 temp = 5;
	//check if the number is negative
	if(copy_s32Number<0)
	{
		HLCD_voidSendData('-');
		copy_s32Number *= -1;
	}
	//cascade numbers in reverse order
	if (copy_s32Number == 0)
	{
		HLCD_voidSendData('0');
		return;
	}
	while(copy_s32Number != 0)
	{
		temp = temp*10 + copy_s32Number%10;
		copy_s32Number /=10;
	}
	//display them one by one
	while(temp != 5)
	{
		HLCD_voidSendData(temp%10 + '0');
		temp /= 10;
	}

}



/************************************************************************
send clear screen command
************************************************************************/
void HLCD_voidClearDisplay(void)
{
	HLCD_voidSendCommand(LCD_COMMAND_CLEAR_DISPLAY);
}



/************************************************************************
specify the address for the position at DDRAM
************************************************************************/
void HLCD_voidGoToPos(u8 copy_u8RowNum, u8 copy_u8ColNum)
{
	u8 value = 0x40 * copy_u8RowNum + copy_u8ColNum + 0b10000000 ;
	HLCD_voidSendCommand(value);
}



/************************************************************************
send the custom pattern to n location from the 8 locations at CGRAM
then display it
************************************************************************/
void HLCD_voidSendSpecialCharacter(	u8* copy_pu8charArr, u8 copy_u8patternNum,
									u8 copy_u8LineNum, u8 copy_ColNum)
{
	/* set address of first byte of the pattern at pattern number n*/
	HLCD_voidSendCommand(0x40+8*copy_u8patternNum);
	//_delay_ms(1);

	/* send the pattern  data bytes one by one */
	for(u8 i = 0; i<8; i++)
	{
		HLCD_voidSendData(*copy_pu8charArr++);
		//_delay_us(50);
	}

	/* set the address in the DDRAM instead of GCRAM */
	HLCD_voidGoToPos(copy_u8LineNum,copy_ColNum);
	//_delay_ms(1);

	HLCD_voidSendData(copy_u8patternNum);

}



/************************************************************************
sent pattern n at n block at CGRAM only, not displaying it
if we want to display the character we send the block number with
HLCD_voidSendData() command
************************************************************************/
void HLCD_voidSetSpecialCharacterPattern(u8* copy_pu8charArr, u8 copy_u8patternNum)
{
	/* set address of first byte in the pattern of pattern number n*/
	HLCD_voidSendCommand(0x40+8*copy_u8patternNum);
	//_delay_ms(1);

	/* send the pattern  data bytes one by one */
	for(u8 i = 0; i<8; i++)
	{
		HLCD_voidSendData(*copy_pu8charArr++);
		//_delay_ms(1);
	}
}

/*****************************************************************************
 Read the busy flag before start a new command

 steps
 1- make the port as input first
 (LCD already input from previous command so there is no risk of short circuit)
 2- make the reading sequence by R/S and RW pins
 3- E rising edge
 4- according to data sheet the data will be valid to read after 120ns as a maximum
 (we work with 8MHz oscillator so one assembly instruction time will be more than enough)
 5- read data and extract the flag
 6- E falling edge
*****************************************************************************/


u8 HLCD_u8GetFlag(void)
{

	u8 value;

	MDIO_voidSetPortDir(LCD_Data_PORT,0x00); //make port input to read data

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_u8_LOW);//select instruction reg
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_u8_HIGH);//read mode
	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_HIGH);//E rising edge

	value = MDIO_u8GetPortValue(LCD_Data_PORT) >>7;// read data and extract the flag(bit 7)

	MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_u8_LOW);//E falling edge

	return value;

}
