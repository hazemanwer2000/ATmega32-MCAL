/*************************************************************
 * 
 * Filename: LED.h
 * Description: Header (interface) file of the LED driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __LED_H__
#define __LED_H__

#include "DIO.h"


/*************************************************************
 * Description: Error status, return by various functions.
 *      (Ok):                   Successful.
 *      (NotOk):                Failed.
 *      (InvalidPinNumber):     Failed, no LED is connected to this pin.
 *      (InvalidPinCfg):        Failed, pin configured as input, not output.
 * 
 *************************************************************/
typedef enum {
    LED_enuOk = 0,
    LED_enuNotOk,
    LED_enuInvalidPinNumber,
    LED_enuInvalidPinCfg    
} LED_tenuErrorStatus;


/*************************************************************
 * Description: Type of integer to hold pin number.
 * 
 *************************************************************/
typedef DIO_tuPinNumber LED_tuPinNumber;


/*************************************************************
 * Description: Initialization of the LED module, using associated 
 *                  configuration file(s).
 * Parameters:
 *      [X]
 * Return:
 *      Error status.
 *************************************************************/
LED_tenuErrorStatus LED_enuInit(void);


/*************************************************************
 * Description: Set an LED on, using its associated pin number.
 * Parameters:
 *      [1] Pin number.
 * Return:
 *      Error status.
 *************************************************************/
LED_tenuErrorStatus LED_enuLedOn(LED_tuPinNumber Cpy_uPinNumber);


/*************************************************************
 * Description: Set an LED off, using its associated pin number.
 * Parameters:
 *      1] Pin number.
 * Return:
 *      Error status.
 *************************************************************/
LED_tenuErrorStatus LED_enuLedOff(LED_tuPinNumber Cpy_uPinNumber);


#endif /* __LED_H__ */