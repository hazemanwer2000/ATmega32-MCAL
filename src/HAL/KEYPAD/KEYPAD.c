/*************************************************************
 * 
 * Filename: KEYPAD.c
 * Description: Source file of the KEYPAD driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "KEYPAD_Cfg.h"
#include "KEYPAD_Priv.h"
#include "KEYPAD.h"

#include "DIO.h"

#include "Std_Types.h"


/*************************************************************
 * Description: Get key currently pressed on keypad.
 * Parameters:
 *      [X]
 * Return:
 *          Error Status.
 *************************************************************/
KEYPAD_tenuErrorStatus KEYPAD_enuGetKey(KEYPAD_tenuKey *Add_enuKey)
{
    KEYPAD_tenuErrorStatus Loc_enuErrorStatus = KEYPAD_enuOk;
    DIO_tenuErrorStatus Loc_enuDIOErrorStatus = DIO_enuOk;
    u8 Loc_u8Row = 0, Loc_u8Column = 0, Loc_u8ErrorFlag = 0;
    DIO_tenuPinState Loc_enuPinState = DIO_enuLow;

    *Add_enuKey = KEYPAD_enuKeyNone;

    for (Loc_u8Row = 0; Loc_u8Row < KEYPAD_ROW_COUNT && Loc_u8ErrorFlag == 0; Loc_u8Row++)
    {
        Loc_enuDIOErrorStatus = DIO_enuClearPin(KEYPAD_uRowPins[Loc_u8Row]);
        if (Loc_enuDIOErrorStatus != DIO_enuOk) 
        {
            Loc_u8ErrorFlag = 1;
        }

        for (Loc_u8Column = 0; Loc_u8Column < KEYPAD_COLUMN_COUNT; Loc_u8Column++)
        {
            Loc_enuDIOErrorStatus = DIO_enuGetPin(KEYPAD_uColumnPins[Loc_u8Column], &Loc_enuPinState);
            if (Loc_enuDIOErrorStatus != DIO_enuOk)
            {
                Loc_u8ErrorFlag = 1;
            }

            if (Loc_enuPinState == DIO_enuLow)
            {
                *Add_enuKey = Loc_u8Row * KEYPAD_COLUMN_COUNT + Loc_u8Column;
            }
        }

        Loc_enuDIOErrorStatus = DIO_enuSetPin(KEYPAD_uRowPins[Loc_u8Row]);
        if (Loc_enuDIOErrorStatus != DIO_enuOk) 
        {
            Loc_u8ErrorFlag = 1;
        }
    }

    if (Loc_u8ErrorFlag)
    {
        Loc_enuErrorStatus = KEYPAD_enuInvalidPinCfg;
    }

    return Loc_enuErrorStatus;
}