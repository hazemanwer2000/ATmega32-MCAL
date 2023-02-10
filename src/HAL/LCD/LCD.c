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


LCD_tenuErrorStatus LCD_enuWriteCommand() {
    
}