/*
 * LCD_interface.h
 *
 *  Created on: Jan 4, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INC_HAL_LCD_LCD_INTERFACE_H_
#define INC_HAL_LCD_LCD_INTERFACE_H_

void HLCD_voidInit(void);

void HLCD_voidSendCommand(u8 copy_u8Command);
void HLCD_voidSendData(u8 copy_u8Char);
void HLCD_voidClearDisplay(void);
void HLCD_voidGoToPos(u8 copy_u8RowNum, u8 copy_u8ColNum);
void HLCD_voidSendSpecialCharacter(u8* copy_pu8charArr, u8 copy_u8patternNum,
									u8 copy_u8LineNum, u8 copy_ColNum);

void HLCD_voidSetSpecialCharacterPattern(u8* copy_pu8charArr, u8 copy_u8patternNum);


void HLCD_voidDisplayNumber(s32 copy_s32Number);
void HLCD_voidDisplayString(u8* copy_pu8String);



#define LCD_u8_LINE1	0
#define LCD_u8_LINE2	1


#define LCD_COMMAND_CLEAR_DISPLAY			0b00000001
#define LCD_COMMAND_RETURN_HOME 			0b00000010

#define LCD_COMMAND_SHIFT_DISPLAY_LEFT		0b00011000
#define LCD_COMMAND_SHIFT_DISPLAY_RIGHT		0b00011100

#define LCD_COMMAND_SHIFT_CURSOR_LEFT		0b00010000
#define LCD_COMMAND_SHIFT_CURSOR_RIGHT		0b00010100





#endif /* INC_HAL_LCD_LCD_INTERFACE_H_ */
