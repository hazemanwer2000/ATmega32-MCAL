/*************************************************************
 * 
 * Filename: LCD.h
 * Description: Header (interface) file of the LCD driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __LCD_H__
#define __LCD_H__

#include "Std_Types.h"


/*************************************************************
 * Description: LCD special characters.
 * 
 *************************************************************/
#define LCD_SPECIAL_CHAR_0                  0
#define LCD_SPECIAL_CHAR_1                  1
#define LCD_SPECIAL_CHAR_2                  2
#define LCD_SPECIAL_CHAR_3                  3
#define LCD_SPECIAL_CHAR_4                  4
#define LCD_SPECIAL_CHAR_5                  5
#define LCD_SPECIAL_CHAR_6                  6
#define LCD_SPECIAL_CHAR_7                  7


/*************************************************************
 * Description: LCD commands.
 * 
 *************************************************************/
#define LCD_CMD_CLEAR_DISPLAY                   0b00000001
#define LCD_CMD_RETURN_HOME                     0b00000010
#define LCD_CMD_ENTRY_MODE_SET                  0b00000110

#define LCD_CMD_CURSOR_ON_BLINK_ON              0b00001111
#define LCD_CMD_CURSOR_ON_BLINK_OFF             0b00001110
#define LCD_CMD_CURSOR_OFF                      0b00001100

#define LCD_CMD_SHIFT_DISPLAY_RIGHT             0b00011100
#define LCD_CMD_SHIFT_DISPLAY_LEFT              0b00011000

#define LCD_CMD_SHIFT_CURSOR_RIGHT              0b00010100
#define LCD_CMD_SHIFT_CURSOR_LEFT               0b00010000


/*************************************************************
 * Description: LCD error status.
 * 
 *************************************************************/
typedef enum {
    LCD_enuOk,
    LCD_enuInvalidPinCfg,
    LCD_enuInvalidLocation
} LCD_tenuErrorStatus;


/*************************************************************
 * Description: Write command to LCD.
 * Parameters:
 *      [1] Command.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuWriteCommand(u8 Cpy_u8Command);


/*************************************************************
 * Description: Initialize LCD.
 * Parameters:
 *      [X]
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuInit();


/*************************************************************
 * Description: Write data to LCD.
 * Parameters:
 *      [1] Byte.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuWriteData(u8 Loc_u8Data);


/*************************************************************
 * Description: Write string to LCD.
 * Parameters:
 *      [1] String.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuWriteString(u8 *Add_u8Data);


/*************************************************************
 * Description: Write number to LCD.
 * Parameters:
 *      [1] Number.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuWriteNumber(u16 Cpy_u16Data);


/*************************************************************
 * Description: Write special character to LCD.
 *                  Note: Must call 'GoToXY' thereafter.
 * Parameters:
 *      [1] Special character name.
 *      [2] Array of 5 bits by 8 bytes.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuStoreSpecialCharacter(u8 Cpy_u8SpecialCharacter, u8 *Cpy_u8Bits);


/*************************************************************
 * Description: Go to (x, y).
 * Parameters:
 *      [1] X.
 *      [2] Y.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuGoToXY(u8 Cpy_u8X, u8 Cpy_u8Y);


#endif /* __LCD_H__ */