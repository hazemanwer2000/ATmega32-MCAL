/*************************************************************
 * 
 * Filename: LCD_Priv.h
 * Description: Private header file of the LCD driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __LCD_PRIV_H__
#define __LCD_PRIV_H__

#include "LCD.h"
#include "Std_Types.h"


/*************************************************************
 * Description: LCD commands.
 * 
 *************************************************************/
#define LCD_CMD_FUNCTION_SET                    0b00111000

#define LCD_CMD_SET_ADDRESS_CGRAM               0b01000000
#define LCD_CMD_SET_ADDRESS_DDRAM               0b10000000


/*************************************************************
 * Description: Set RS, RW and D[0-7] pin states.
 * Parameters:
 *      [1] Pin RS state.
 *      [2] Pin RW state.
 *      [3] Byte to set on D0 to D7.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
static LCD_tenuErrorStatus LCD_enuWriteToPins(DIO_tenuPinState Cpy_enuPinStateRS,
        DIO_tenuPinState Cpy_enuPinStateRW, u8 Cpy_u8Data);


#endif /* __LCD_PRIV_H__ */