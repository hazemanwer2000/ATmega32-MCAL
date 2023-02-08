/*************************************************************
 * 
 * Filename: KEYPAD_Cfg.c
 * Description: Configuration source file of the KEYPAD driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "KEYPAD_Cfg.h"


/*************************************************************
 * Description: Pins connected to each row, and column.
 *                  NOTE: Counting top-to-bottom, and left-to-right. 
 * 
 *************************************************************/
DIO_tuPinNumber KEYPAD_uRowPins[KEYPAD_ROW_COUNT] = {16, 17, 18, 19};
DIO_tuPinNumber KEYPAD_uColumnPins[KEYPAD_COLUMN_COUNT] = {20, 21, 22, 23};