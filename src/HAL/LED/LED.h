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
 * Description: Maximum number of LEDs that can be connected to the hardware.
 *
 *************************************************************/
#define LED_MAX_NUM_OF_LEDS          DIO_PIN_COUNT


/*************************************************************
 * Description: Error status, return by various functions.
 *      (Ok):                   Successful.
 *      (NotOk):                Failed.
 *      (InvalidPinNumber):     Failed, no LED is connected to this pin, or within 
 *                                  'init' function, larger than maximum number of LEDs.
 * 
 *************************************************************/
typedef enum {
    LED_enuOk = 0,
    LED_enuNotOk,
    LED_enuInvalidPinNumber           
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