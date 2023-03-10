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
 * Description: Write to LCD (with custom delay, and RS/RW).
 * Parameters:
 *      [1] Data.
 *      [2] Delay (in ms).
 *      [3] RS Pin State.
 *      [4] RW Pin State.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
static LCD_tenuErrorStatus LCD_enuWriteCustom(u8 Cpy_u8Data, u16 Loc_u16Delay,
        DIO_tenuPinState Cpy_enuPinStateRS, DIO_tenuPinState Cpy_enuPinStateRW) {
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOk;

    if (LCD_enuCfgPins(Cpy_enuPinStateRS, Cpy_enuPinStateRW, Cpy_u8Data) != LCD_enuOk) {
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
 * Description: Write command to LCD (with custom delay).
 * Parameters:
 *      [1] Command.
 *      [2] Delay (in ms).
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
static LCD_tenuErrorStatus LCD_enuWriteCommandCustom(u8 Cpy_u8Command, u16 Loc_u16Delay) {
    return LCD_enuWriteCustom(Cpy_u8Command, Loc_u16Delay, LCD_RS_STATE_CMD, LCD_RW_STATE_WRITE);
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
    
    Loc_enuErrorStatus = max_u8(Loc_enuErrorStatus, LCD_enuWriteCommandCustom(LCD_CMD_FUNCTION_SET, LCD_DELAY_MS_INITIAL_STAGE_1));
    //Loc_enuErrorStatus = max_u8(Loc_enuErrorStatus, LCD_enuWriteCommandCustom(LCD_CMD_FUNCTION_SET, LCD_DELAY_MS_INITIAL_STAGE_2));

    //Loc_enuErrorStatus = max_u8(Loc_enuErrorStatus, LCD_enuWriteCommand(LCD_CMD_FUNCTION_SET));
    //Loc_enuErrorStatus = max_u8(Loc_enuErrorStatus, LCD_enuWriteCommand(LCD_CMD_FUNCTION_SET));

    Loc_enuErrorStatus = max_u8(Loc_enuErrorStatus, LCD_enuWriteCommand(LCD_CMD_CURSOR_ON_BLINK_ON));
    Loc_enuErrorStatus = max_u8(Loc_enuErrorStatus, LCD_enuWriteCommand(LCD_CMD_CLEAR_DISPLAY));
    Loc_enuErrorStatus = max_u8(Loc_enuErrorStatus, LCD_enuWriteCommand(LCD_CMD_ENTRY_MODE_SET));
    Loc_enuErrorStatus = max_u8(Loc_enuErrorStatus, LCD_enuWriteCommand(LCD_CMD_CURSOR_ON_BLINK_ON));

    return Loc_enuErrorStatus;
}


/*************************************************************
 * Description: Write data to LCD.
 * Parameters:
 *      [1] Byte.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuWriteData(u8 Cpy_u8Data) {
    return LCD_enuWriteCustom(Cpy_u8Data, LCD_DELAY_MS_BETWEEN, LCD_RS_STATE_DATA, LCD_RW_STATE_WRITE);
}


/*************************************************************
 * Description: Write string to LCD.
 * Parameters:
 *      [1] String.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuWriteString(u8 *Add_u8Data) {
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOk;
    u8 Loc_u8Iterator = 0;

    while (Add_u8Data[Loc_u8Iterator] != '\0') {
        Loc_enuErrorStatus = max_u8(Loc_enuErrorStatus, LCD_enuWriteData(Add_u8Data[Loc_u8Iterator]));
        Loc_u8Iterator++;
    }

    return Loc_enuErrorStatus;
}


/*************************************************************
 * Description: Write number to LCD.
 * Parameters:
 *      [1] Number.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuWriteNumber(u16 Cpy_u16Data) {
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOk;
    u16 Loc_u16Data = Cpy_u16Data;
    u16 Loc_u16Order = 1;
    u8 Loc_u8DigitCount = 0;

    if (Cpy_u16Data == 0) {
        LCD_enuWriteData('0');
    } else {
        
        while (Loc_u16Data != 0) {
            Loc_u16Data /= 10;
            Loc_u16Order *= 10;
            Loc_u8DigitCount++;
        }

        while (Cpy_u16Data != 0) {
            Loc_u16Order /= 10;
            Loc_u16Data += (Cpy_u16Data % 10) * Loc_u16Order;
            Cpy_u16Data /= 10;
        }

        do {
            Loc_enuErrorStatus = max_u8(Loc_enuErrorStatus, LCD_enuWriteData((Loc_u16Data % 10) + '0'));
            Loc_u16Data /= 10;
        } while (--Loc_u8DigitCount > 0);
    }

    return Loc_enuErrorStatus;
}


/*************************************************************
 * Description: Write special character to LCD.
 *                  Note: Must call 'GoToXY' thereafter.
 * Parameters:
 *      [1] Special character name.
 *      [2] Array of 5 bits by 8 bytes.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuStoreSpecialCharacter(u8 Cpy_u8SpecialCharacter, u8 *Cpy_u8Bits) {
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOk;
    u8 Loc_u8Iterator = 0;
    
    for (Loc_u8Iterator = 0; Loc_u8Iterator < LCD_SP_CHAR_BIT_ROW_COUNT; Loc_u8Iterator++) {
        Loc_enuErrorStatus = max_u8(Loc_enuErrorStatus, LCD_enuWriteCommand(LCD_CMD_SET_ADDRESS_CGRAM | (LCD_BASE_ADDRESS_CGRAM * Cpy_u8SpecialCharacter) | Loc_u8Iterator));
        Loc_enuErrorStatus = max_u8(Loc_enuErrorStatus, LCD_enuWriteData(Cpy_u8Bits[Loc_u8Iterator]));
    }

    return Loc_enuErrorStatus;
}


/*************************************************************
 * Description: Go to (x, y).
 * Parameters:
 *      [1] X.
 *      [2] Y.
 * Return:
 *      Error status (LCD_enuOk, LCD_enuInvalidPinCfg)
 *************************************************************/
LCD_tenuErrorStatus LCD_enuGoToXY(u8 Cpy_u8X, u8 Cpy_u8Y) {
    LCD_tenuErrorStatus Loc_enuErrorStatus = LCD_enuOk;

    if (Cpy_u8X >= LCD_COLUMNS_TOTAL || Cpy_u8Y >= LCD_ROWS_TOTAL) {
        Loc_enuErrorStatus = LCD_enuInvalidLocation;
    } else {
        Loc_enuErrorStatus = LCD_enuWriteCommand(LCD_CMD_SET_ADDRESS_DDRAM | 
            (Cpy_u8Y * LCD_ROW_OFFSET + Cpy_u8X * LCD_COLUMN_OFFSET));
    }

    return Loc_enuErrorStatus;
}