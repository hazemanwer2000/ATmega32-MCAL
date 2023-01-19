/*************************************************************
 * 
 * Filename: BUTTON.c
 * Description: Source file of the BUTTON driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "Delay.h"

#include "BUTTON.h"
#include "BUTTON_Cfg.h"
#include "BUTTON_Priv.h"
#include "DIO.h"


/*************************************************************
 * Description: Get the status of a button, connected to a pin.
 * Parameters:
 *      [1] Pin number.
 *      [2] Pointer, to store state in.
 * Return:
 *      Error status (BUTTON_enuOk, BUTTON_enuNullPtr, BUTTON_enuInvalidPinNumber, BUTTON_enuInvalidPinCfg)
 *************************************************************/
BUTTON_tenuErrorStatus BUTTON_enuGetButtonState(BUTTON_tuPinNumber Cpy_uPinNumber, 
                            BUTTON_tenuButtonState *Add_enuButtonState) {
    DIO_tenuErrorStatus Loc_enuDIOErrorStatus = DIO_enuOk;
    BUTTON_tenuErrorStatus Loc_enuErrorStatus = BUTTON_enuOk;
    DIO_tenuPinState Loc_enuDIOPinState = DIO_enuHigh;
    BUTTON_tenuButtonState Loc_enuPrevButtonState = BUTTON_enuButtonPressed, 
                            Loc_enuButtonState = BUTTON_enuButtonPressed;
    BUTTON_tuPinNumber Loc_uPinNumberIterator = 0;
    u8 Loc_u8DebouncingCounter = 0;

    for (Loc_uPinNumberIterator = 0; Loc_uPinNumberIterator < BUTTON_NUM_OF_BUTTONS; Loc_uPinNumberIterator++) {
        if (BUTTON_strucButtonCfgs[Loc_uPinNumberIterator].Mem_uPinNumber == Cpy_uPinNumber) {
            Loc_enuDIOErrorStatus = DIO_enuGetPin(Cpy_uPinNumber, &Loc_enuDIOPinState);

            switch (Loc_enuDIOErrorStatus) {
                case DIO_enuNullPtr:
                    Loc_enuErrorStatus = BUTTON_enuNullPtr;
                    break;
                case DIO_enuInvalidPinNumber:
                    Loc_enuErrorStatus = BUTTON_enuInvalidPinNumber;
                    break;
                case DIO_enuNotInputPin:
                    Loc_enuErrorStatus = BUTTON_enuInvalidPinCfg;
                    break;
                case DIO_enuOk:
                    Loc_enuPrevButtonState = Loc_enuDIOPinState ^ BUTTON_strucButtonCfgs[Loc_uPinNumberIterator].Mem_enuActiveCfg;
                    while (Loc_u8DebouncingCounter < BUTTON_DEBOUNCE_COUNT) {
                        delay_ms(BUTTON_DEBOUNCE_DELAY_MS);
                        DIO_enuGetPin(Cpy_uPinNumber, &Loc_enuButtonState);
                        if (Loc_enuButtonState == Loc_enuPrevButtonState) {
                            Loc_u8DebouncingCounter++;
                        } else {
                            Loc_u8DebouncingCounter = 0;
                        }
                        Loc_enuPrevButtonState = Loc_enuButtonState;
                    }
                    *Add_enuButtonState = Loc_enuButtonState;
                    break;
            }
            break;
        }
    }

    if (Loc_uPinNumberIterator == BUTTON_NUM_OF_BUTTONS) {
        Loc_enuErrorStatus = BUTTON_enuInvalidPinNumber;
    }

    return Loc_enuErrorStatus;
}