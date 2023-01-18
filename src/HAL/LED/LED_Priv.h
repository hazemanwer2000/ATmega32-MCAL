/*************************************************************
 * 
 * Filename: LED_Priv.h
 * Description: Configuration header file of the LED driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __LED_PRIV_H__
#define __LED_PRIV_H__

#include "LED.h"


/*************************************************************
 * Description: (static) Set an LED with a state, using its associated pin number.
 * Parameters:
 *      [1] Pin number.
 * Return:
 *      Error status.
 *************************************************************/
static LED_tenuErrorStatus LED_enuSetLedState(LED_tuPinNumber Cpy_uPinNumber, LED_tenuLedState Cpy_enuLedState);


#endif /* __LED_PRIV_H__ */