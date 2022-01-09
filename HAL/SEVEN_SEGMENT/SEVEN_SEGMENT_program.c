/*
 * SEVEN_SEGMENT_program.c
 *
 *  Created on: Jan 4, 2022
 *      Author: noureldeen albrmky
 */

#include "../Inc/LIBRARY/standard_types.h"
#include "../Inc/LIBRARY/bit_math.h"

#include "../Inc/MCAL/DIO/DIO_interface.h"

#include "../Inc/HAL/SEVEN_SEGMENT/SEVEN_SEGMENT_interface.h"
#include "../Inc/HAL/SEVEN_SEGMENT/SEVEN_SEGMENT_private.h"
#include "../Inc/HAL/SEVEN_SEGMENT/SEVEN_SEGMENT_configuration.h"

u8 local_u8NumbersArray[10] = {
SEVSEG_u8_NUMBER_ZERO,
SEVSEG_u8_NUMBER_ONE,
SEVSEG_u8_NUMBER_TWO,
SEVSEG_u8_NUMBER_THREE,
SEVSEG_u8_NUMBER_FOUR,
SEVSEG_u8_NUMBER_FIVE,
SEVSEG_u8_NUMBER_SIX,
SEVSEG_u8_NUMBER_SEVEN,
SEVSEG_u8_NUMBER_EIGHT,
SEVSEG_u8_NUMBER_NINE };

/***************************************************
make the port direction of the 7seg output
****************************************************/
void H7SEG_voidInit(void)
{
	MDIO_voidSetPortDir(SEVSEG_u8_PORT, 0xFF);
}


/***************************************************
display the number according to the pattern
specified in the configuration file
****************************************************/
void H7SEG_voidDisplayNumber(u8 copy_u8Number)
{
#if SEVSEG_u8_TYPE == SEVSEG_COMMON_CATHOD
if (copy_u8Number > 9 || copy_u8Number < 0)	{}
else
{
	MDIO_voidSetPortValue(SEVSEG_u8_PORT,local_u8NumbersArray[copy_u8Number]);
}
#elif  SEVSEG_u8_TYPE == SEVSEG_COMMON_ANODE
if (copy_u8Number > 9 || copy_u8Number < 0)	{}
else
{
	MDIO_voidSetPortValue(SEVSEG_u8_PORT,~local_u8NumbersArray[copy_u8Number]);
}

#endif

}
