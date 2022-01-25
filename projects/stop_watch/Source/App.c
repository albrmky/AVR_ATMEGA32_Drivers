/*
 * App.c
 *
 *  Created on: Jan 25, 2022
 *      Author: noureldeen albrmky
 */

#include "../Include/LIBRARY/standard_types.h"
#include "../Include/LIBRARY/bit_math.h"

#include "../Include/App.h"
#include "../Include/HAL/KEYPAD/KEYPAD_interface.h"


u8 waitforkey(void)
{
	u8 key_value;
	u8 return_key;
	u8 startflag = 0;
	while (1)
	{
		key_value = HKEYPAD_voidGetKey();
		if (key_value != KEYPAD_NO_KEY && startflag == 0) // wait the key to be pressed
		{
			startflag = 1;
			return_key = key_value;
		}
		if (key_value == KEYPAD_NO_KEY && startflag == 1) // wait the key to be released
		return return_key;
	}
}

void take_number(s8* number)
{
	u8 key_press;
	while (1)
	{
		key_press = waitforkey();
		if (key_press <= '9' && key_press >= '0')
		{
			HLCD_voidSendData(key_press);
			*number = *number * 10 + (key_press - '0');
		}
		else
			break;
	}
}
