/*************************************************************
 * 
 * Filename: LCD.c
 * Description: Source file of the LCD driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "LCD_Cfg.h"
#include "LCD_Priv.h"
#include "LCD.h"

#include "DIO.h"
#include "Delay.h"
#include "Utils.h"
#include "Bit_Utils.h"


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
        DIO_tenuPinState Cpy_enuPinStateRW, u8 Cpy_u8Data) {  
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOk;
    u8 Loc_u8Iterator = 0;

    if (DIO_enuSetPinState(LCD_strucLCDCfg.PinRS, Cpy_enuPinStateRS) != DIO_enuOk) {
        Loc_enuErrorStatus = LCD_enuInvalidPinCfg;
    } else if (DIO_enuSetPinState(LCD_strucLCDCfg.PinRW, Cpy_enuPinStateRW) != DIO_enuOk) {
        Loc_enuErrorStatus = LCD_enuInvalidPinCfg;
    } else {
        for (Loc_u8Iterator = 0; Loc_u8Iterator < 8; Loc_u8Iterator++) {
            if (DIO_enuSetPinState(LCD_strucLCDCfg.PinD[Loc_u8Iterator], GET_BIT(Cpy_u8Data, Loc_u8Iterator)) != DIO_enuOk) {
                Loc_enuErrorStatus = LCD_enuInvalidPinCfg;
                break;
            }
        }
    }

    return Loc_enuErrorStatus;
}


/*************************************************************
 * Description: Set EN pin state.
 * Parameters:
 *      [1] Pin state.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
static LCD_tenuErrorStatus LCD_enuCfgPinEN(DIO_tenuPinState Cpy_enuPinState) {
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOk;
    
    if (DIO_enuSetPinState(LCD_strucLCDCfg.PinE, Cpy_enuPinState) != DIO_enuOk) {
        Loc_enuErrorStatus = LCD_enuInvalidPinCfg;
    }

    return Loc_enuErrorStatus;
}


/*************************************************************
 * Description: Write command to LCD.
 * Parameters:
 *      [1] Command.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
static LCD_tenuErrorStatus LCD_enuWriteCommandCustom(u8 Cpy_u8Command, u16 Loc_u16Delay) {
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOk;

    if (LCD_enuCfgPins(LCD_RS_STATE_CMD, LCD_RW_STATE_WRITE, Cpy_u8Command) != LCD_enuOk) {
        Loc_enuErrorStatus = LCD_enuInvalidPinCfg;
    } else if (LCD_enuCfgPinEN(DIO_enuHigh) != LCD_enuOk) {
        Loc_enuErrorStatus = LCD_enuInvalidPinCfg;
    } else {
        delay_ms(LCD_DELAY_MS_BETWEEN);
        Loc_enuErrorStatus = LCD_enuCfgPinEN(DIO_enuLow);
    }

    return Loc_enuErrorStatus;
}


/*************************************************************
 * Description: Write command to LCD.
 * Parameters:
 *      [1] Command.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuWriteCommand(u8 Cpy_u8Command) {
    return LCD_enuWriteCommandCustom(Cpy_u8Command, LCD_DELAY_MS_BETWEEN);
}


/*************************************************************
 * Description: Initialize LCD.
 * Parameters:
 *      [X]
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuInit() {
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOk;

    delay_ms(LCD_DELAY_MS_INITIAL);
    
    Loc_enuErrorStatus = MAX(Loc_enuErrorStatus, LCD_enuWriteCommandCustom(LCD_CMD_FUNCTION_SET, LCD_DELAY_MS_INITIAL_STAGE_1));
    Loc_enuErrorStatus = MAX(Loc_enuErrorStatus, LCD_enuWriteCommandCustom(LCD_CMD_FUNCTION_SET, LCD_DELAY_MS_INITIAL_STAGE_2));

    Loc_enuErrorStatus = MAX(Loc_enuErrorStatus, LCD_enuWriteCommand(LCD_CMD_FUNCTION_SET));
    Loc_enuErrorStatus = MAX(Loc_enuErrorStatus, LCD_enuWriteCommand(LCD_CMD_FUNCTION_SET));

    Loc_enuErrorStatus = MAX(Loc_enuErrorStatus, LCD_enuWriteCommand(LCD_CMD_DISPLAY_OFF));
    Loc_enuErrorStatus = MAX(Loc_enuErrorStatus, LCD_enuWriteCommand(LCD_CMD_CLEAR_DISPLAY));
    Loc_enuErrorStatus = MAX(Loc_enuErrorStatus, LCD_enuWriteCommand(LCD_CMD_ENTRY_MODE_SET));

    Loc_enuErrorStatus = MAX(Loc_enuErrorStatus, LCD_enuWriteCommand(LCD_CMD_CURSOR_ON_BLINK_ON));

    return Loc_enuErrorStatus;
}