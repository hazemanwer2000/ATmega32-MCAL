/*************************************************************
 * 
 * Filename: LED.c
 * Description: Source file of the LED driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "DIO.h"
#include "LED.h"
#include "LED_Cfg.h"
#include "LED_Priv.h"


/*************************************************************
 * Description: Initialization of the LED module, using associated 
 *                  configuration file(s).
 * Parameters:
 *      [X]
 * Return:
 *      Error status.
 *************************************************************/
LED_tenuErrorStatus LED_enuInit(void) {
    LED_tuPinNumber Loc_uPinNumberIterator = 0;
    LED_tenuErrorStatus Loc_enuErrorStatus = LED_enuOk;

    while (Loc_uPinNumberIterator < LED_NUM_OF_LEDS) {
        if (LED_strucLedCfgs[Loc_uPinNumberIterator].Mem_enuInitLedState == LED_enuLedStateOn) {
            Loc_enuErrorStatus = LED_enuLedOn(LED_strucLedCfgs[Loc_uPinNumberIterator].Mem_uPinNumber);
        } else {
            Loc_enuErrorStatus = LED_enuLedOff(LED_strucLedCfgs[Loc_uPinNumberIterator].Mem_uPinNumber);
        }

        if (Loc_enuErrorStatus != LED_enuOk) {
            break;
        }

        Loc_uPinNumberIterator++;
    }

    return Loc_enuErrorStatus;
}


/*************************************************************
 * Description: (static) Set an LED with a state, using its associated pin number.
 * Parameters:
 *      [1] Pin number.
 * Return:
 *      Error status.
 *************************************************************/
static LED_tenuErrorStatus LED_enuSetLedState(LED_tuPinNumber Cpy_uPinNumber, LED_tenuLedState Cpy_enuLedState) {
    LED_tenuErrorStatus Loc_enuErrorStatus = LED_enuOk;
    DIO_tenuErrorStatus Loc_enuDIOErrorStatus = DIO_enuOk;
    
    if (LED_strucLedCfgs[Cpy_uPinNumber].Mem_enuActiveCfg == LED_enuActiveHigh) {
        if (Cpy_enuLedState == LED_enuLedStateOn) {
            Loc_enuDIOErrorStatus = DIO_enuSetPin(Cpy_uPinNumber);
        } else {
            Loc_enuDIOErrorStatus =  DIO_enuClearPin(Cpy_uPinNumber);
        }
    } else {
        if (Cpy_enuLedState == LED_enuLedStateOn) {
            Loc_enuDIOErrorStatus = DIO_enuClearPin(Cpy_uPinNumber);
        } else {
            Loc_enuDIOErrorStatus =  DIO_enuOnPin(Cpy_uPinNumber);
        }
    }

    if (Loc_enuDIOErrorStatus == DIO_enuInvalidPinNumber) {
        Loc_enuErrorStatus = LED_enuInvalidPinNumber;
    } else if (Loc_enuDIOErrorStatus == DIO_enuNotOutputPin) {
        Loc_enuErrorStatus = LED_enuInvalidPinCfg;
    }

    return Loc_enuErrorStatus;
}


/*************************************************************
 * Description: Set an LED on, using its associated pin number.
 * Parameters:
 *      [1] Pin number.
 * Return:
 *      Error status.
 *************************************************************/
LED_tenuErrorStatus LED_enuLedOn(LED_tuPinNumber Cpy_uPinNumber) {
    return LED_enuSetLedState(Cpy_uPinNumber, LED_enuLedStateOn);
}


/*************************************************************
 * Description: Set an LED off, using its associated pin number.
 * Parameters:
 *      1] Pin number.
 * Return:
 *      Error status.
 *************************************************************/
LED_tenuErrorStatus LED_enuLedOff(LED_tuPinNumber Cpy_uPinNumber) {
    return LED_enuSetLedState(Cpy_uPinNumber, LED_enuLedStateOff);
}