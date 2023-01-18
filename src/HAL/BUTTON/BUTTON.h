/*************************************************************
 * 
 * Filename: BUTTON.h
 * Description: Header (interface) file of the BUTTON driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "DIO.h"


/*************************************************************
 * Description: State of a button, pressed or released.
 * 
 *************************************************************/
typedef enum {
    BUTTON_enuButtonReleased = 0,
    BUTTON_enuButtonPressed = 1
} BUTTON_tenuButtonState;


/*************************************************************
 * Description: Error status, return by various functions.
 *      (Ok):                   Successful.
 *      (NotOk):                Failed.
 *      (InvalidPinNumber):     Failed, no BUTTON is connected to this pin.
 *      (InvalidPinCfg):        Failed, pin configured as output, not input.
 * 
 *************************************************************/
typedef enum {
    BUTTON_enuOk = 0,
    BUTTON_enuNotOk,
    BUTTON_enuInvalidPinNumber,
    BUTTON_enuInvalidPinCfg,
    BUTTON_enuNullPtr
} BUTTON_tenuErrorStatus;


/*************************************************************
 * Description: Type of integer to hold pin number.
 * 
 *************************************************************/
typedef DIO_tuPinNumber BUTTON_tuPinNumber;


/*************************************************************
 * Description: Get the status of a button, connected to a pin.
 * Parameters:
 *      [1] Pin number.
 *      [2] Pointer, to store state in.
 * Return:
 *      Error status.
 *************************************************************/
BUTTON_tenuErrorStatus BUTTON_enuGetButtonState(BUTTON_tuPinNumber Cpy_uPinNumber, 
                            BUTTON_tenuButtonState *Add_enuButtonState);


#endif /* __BUTTON_H__ */