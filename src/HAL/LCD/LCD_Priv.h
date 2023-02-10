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

#include "DIO.h"
#include "LCD.h"
#include "Std_Types.h"


/*************************************************************
 * Description: LCD constants.
 * 
 *************************************************************/
#define LCD_DELAY_MS_BETWEEN                    2

#define LCD_DELAY_MS_INITIAL                    41
#define LCD_DELAY_MS_INITIAL_STAGE_1            5
#define LCD_DELAY_MS_INITIAL_STAGE_2            1

#define LCD_RS_STATE_CMD                        DIO_enuLow
#define LCD_RS_STATE_DATA                       DIO_enuHigh

#define LCD_RW_STATE_WRITE                      DIO_enuLow
#define LCD_RW_STATE_READ                       DIO_enuHigh


/*************************************************************
 * Description: LCD commands.
 * 
 *************************************************************/
#define LCD_CMD_DISPLAY_OFF                      0b00001000

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
static LCD_tenuErrorStatus LCD_enuCfgPins(DIO_tenuPinState Cpy_enuPinStateRS,
        DIO_tenuPinState Cpy_enuPinStateRW, u8 Cpy_u8Data);


/*************************************************************
 * Description: Set EN pin state.
 * Parameters:
 *      [1] Pin state.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
static LCD_tenuErrorStatus LCD_enuCfgPinEN(DIO_tenuPinState Cpy_enuPinState);


/*************************************************************
 * Description: Write command to LCD.
 * Parameters:
 *      [1] Command.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
static LCD_tenuErrorStatus LCD_enuWriteCommandCustom(u8 Cpy_u8Command, u16 Loc_u16Delay);


#endif /* __LCD_PRIV_H__ */