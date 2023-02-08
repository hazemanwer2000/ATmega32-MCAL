/*************************************************************
 * 
 * Filename: KEYPAD_Cfg.h
 * Description: Configuration header file of the KEYPAD driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __KEYPAD_CFG_H__
#define __KEYPAD_CFG_H__

#include "DIO.h"


/*************************************************************
 * Description: Number of rows and columns in the keypad. 
 * 
 *************************************************************/
#define KEYPAD_ROW_COUNT            4
#define KEYPAD_COLUMN_COUNT         4


/*************************************************************
 * Description: Enum of key names in keypad, sized 'ROW X COLUMN + 1'.
 *                  NOTE: Starting from top-left corner, move onto each key in the first row, 
 *                          then drop to the next row, etc.
 *                  NOTE: Leave 'KEYPAD_enuKeyNone' unchanged. 
 * 
 *************************************************************/
typedef enum {
    KEYPAD_enuKey7 = 0,
    KEYPAD_enuKey8,
    KEYPAD_enuKey9,
    KEYPAD_enuKeyDivide,
    
    KEYPAD_enuKey4,
    KEYPAD_enuKey5,
    KEYPAD_enuKey6,
    KEYPAD_enuKeyMultiply,

    KEYPAD_enuKey1,
    KEYPAD_enuKey2,
    KEYPAD_enuKey3,
    KEYPAD_enuKeyMinus,

    KEYPAD_enuKeyOn,
    KEYPAD_enuKey0,
    KEYPAD_enuKeyEqual,
    KEYPAD_enuKeyPlus,

    KEYPAD_enuKeyNone
} KEYPAD_tenuKey;


/*************************************************************
 * Description: Pins connected to each row, and column.
 *                  NOTE: Counting top-to-bottom, and left-to-right. 
 * 
 *************************************************************/
extern DIO_tuPinNumber KEYPAD_uRowPins[KEYPAD_ROW_COUNT];
extern DIO_tuPinNumber KEYPAD_uColumnPins[KEYPAD_COLUMN_COUNT];


#endif /* __KEYPAD_CFG_H__ */