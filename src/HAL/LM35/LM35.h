/*************************************************************
 * 
 * Filename: LM35.h
 * Description: Header (interface) file of the LM35 driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __LM35_H__
#define __LM35_H__

#include "Std_Types.h"
#include "LM35_Cfg.h"


/*************************************************************
 * Description: Error status, return by various functions.
 *      (Ok):                   Successful.
 *      (DoesNotExist):         Sensor index/alias does not exist.
 * 
 *************************************************************/
typedef enum {
    LM35_enuOk = 0,
    LM35_enuDoesNotExist,
    LM35_enuFailedToRead,
    LM35_enuNullPointer
} LM35_tenuErrorStatus;


/*************************************************************
 * Description: Get value (0-500 degrees celsius).
 * Parameters:
 *      [1] Sensor index/alias.
 *      [2] Address to data, to read into.
 * Return:
 *      value.
 *************************************************************/
LM35_tenuErrorStatus LM35_enuGetValue(LM35_tenuSensor Cpy_enuSensor, double *Add_doubleReading);


#endif /* __LM35_H__ */