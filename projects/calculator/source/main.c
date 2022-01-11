/*
 * main.c
 *
 *  Created on: Jan 9, 2022
 *      Author: noureldeen albrmky
 */

#include "../include/LIBRARY/standard_types.h"
#include "../include/LIBRARY/bit_math.h"

#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/HAL/LCD/LCD_interface.h"
#include "../include/HAL/KEYPAD/KEYPAD_interface.h"

#include <util/delay.h>


int main(void)
{

	//LCD
	MDIO_voidSetPortDir(DIO_u8_PORTA,0xFF);
	MDIO_voidSetPortDir(DIO_u8_PORTB,0xFF);

	//KEYPAD
	MDIO_voidSetPortDir(DIO_u8_PORTC,0x0F);  // low nibble o/p , high nibble i/p
	MDIO_voidSetPortValue(DIO_u8_PORTC,0xFF);// low nibble high, high nibble pullup

	//LCD
	HLCD_voidInit();

	u8 key; // get the keypad button

	s32 var1 = 0;
	s32 var2 = 0;
	s32 result = 0;
	//u8 signflag = 0;
	u8 operator  = 0;

	u8 initflag = 0;
	u8 varflag = 0;


	while(1)
	{
		key = HKEYPAD_voidGetKey();
		if(key != KEYPAD_NO_KEY )
		{
			if( (key>'9' || key <'0' ) && initflag == 0 )
			{
				HLCD_voidDisplayString((u8*)"Enter an operand");
				_delay_ms(200);
				HLCD_voidClearDisplay();
			}//if
			else
			{
				initflag = 1;
				if (key == 'C')
				{
					var1 = 0;
					var2 = 0;
					operator = 0;
					varflag = 0;
					initflag = 0;
					HLCD_voidClearDisplay();
				} //if
				else if ( (key<='9' && key >='0' ) )
				{
					if(varflag == 0)
					{
						HLCD_voidSendData(key);
						var1 *= 10;
						var1 += key - '0';
					}
					else if(varflag == 1)
					{
						HLCD_voidSendData(key);
						var2 *= 10;
						var2 += key - '0';
					}
				}//else if
				else if((key == '+') || (key == '*') || (key == '/') || (key == '-'))
				{
					HLCD_voidSendData(key);
					operator = key;
					varflag = !varflag;
				}//else if
				else if(key == '=')
				{
					HLCD_voidClearDisplay();
					HLCD_voidSendData(key);

					switch (operator)
					{
						case '*':
							result = var1 * var2;
							break;

						case '/':
							result = var1 / var2;
							break;

						case '+':
							result = var1 + var2;
							break;

						case '-':
							result = var1 - var2;
							break;
					}//switch


					HLCD_voidDisplayNumber(result);
					var1 = result;
					var2 = 0;
					varflag = ! varflag;

				}//else if


			}//else

		}//if
	}//while

	return 0;
}
