/*************************************************************
 * 
 * Filename: KEYPAD.h
 * Description: Header (interface) file of the KEYPAD driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include "KEYPAD_Cfg.h"


/*************************************************************
 * Description: Error status.
 * 
 *************************************************************/
typedef enum {
    KEYPAD_enuOk,
    KEYPAD_enuNotOk,
    KEYPAD_enuInvalidPinCfg
} KEYPAD_tenuErrorStatus;


/*************************************************************
 * Description: Get key currently pressed on keypad.
 * Parameters:
 *      [X]
 * Return:
 *          Error Status.
 *************************************************************/
KEYPAD_tenuErrorStatus KEYPAD_enuGetKey(KEYPAD_tenuKey *Add_enuKey);


#endif /* __KEYPAD_H__ */