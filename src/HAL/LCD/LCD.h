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
 * Description: LCD type-definitions.
 * 
 *************************************************************/
typedef u8 


/*************************************************************
 * Description: LCD error status.
 * 
 *************************************************************/
typedef enum {
    LCD_enuOk,
    LCD_enuInvalidPinCfg
} LCD_tenuErrorStatus;


/*************************************************************
 * Description: LCD commands.
 * 
 *************************************************************/
#define LCD_CMD_CLEAR_DISPLAY                   0b00000001
#define LCD_CMD_RETURN_HOME                     0b00000010
#define LCD_CMD_ENTRY_MODE_SET                  0b00000111

#define LCD_CMD_CURSOR_ON_BLINK_ON              0b00001111
#define LCD_CMD_CURSOR_ON_BLINK_OFF             0b00001110
#define LCD_CMD_CURSOR_OFF                      0b00001100

#define LCD_CMD_SHIFT_DISPLAY_RIGHT             0b00011100
#define LCD_CMD_SHIFT_DISPLAY_LEFT              0b00011000

#define LCD_CMD_SHIFT_CURSOR_RIGHT              0b00010100
#define LCD_CMD_SHIFT_CURSOR_LEFT               0b00010000


#endif /* __LCD_H__ */