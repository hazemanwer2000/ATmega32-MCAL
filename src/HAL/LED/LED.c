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
        if (LED_strucLedCfgs[Loc_uPinNumberIterator].Mem_uPinNumber > LED_MAX_NUM_OF_LEDS - 1) {
            Loc_enuErrorStatus = LED_enuInvalidPinNumber;
            break;
        } else {
            if (LED_strucLedCfgs[Loc_uPinNumberIterator].Mem_enuInitLedState == LED_enuLedOn) {
                LED_enuLedOn(LED_strucLedCfgs[Loc_uPinNumberIterator].Mem_uPinNumber);
            } else {
                LED_enuLedOff(LED_strucLedCfgs[Loc_uPinNumberIterator].Mem_uPinNumber);
            }
        }

        Loc_uPinNumberIterator++;
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
    LED_tenuErrorStatus Loc_enuErrorStatus = LED_enuOk;
    
    if (Cpy_uPinNumber > DIO_) {

    }
}


/*************************************************************
 * Description: Set an LED off, using its associated pin number.
 * Parameters:
 *      1] Pin number.
 * Return:
 *      Error status.
 *************************************************************/
LED_tenuErrorStatus LED_enuLedOff(LED_tuPinNumber Cpy_uPinNumber) {

}