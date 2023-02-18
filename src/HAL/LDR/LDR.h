/*************************************************************
 * 
 * Filename: LDR.h
 * Description: Header (interface) file of the LDR driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __LDR_H__
#define __LDR_H__

#include "Std_Types.h"
#include "LDR_Cfg.h"


/*************************************************************
 * Description: Error status, return by various functions.
 *      (Ok):                   Successful.
 *      (DoesNotExist):         Sensor index/alias does not exist.
 * 
 *************************************************************/
typedef enum {
    LDR_enuOk = 0,
    LDR_enuDoesNotExist,
    LDR_enuFailedToRead,
    LDR_enuNullPointer
} LDR_tenuErrorStatus;


/*************************************************************
 * Description: Get value (0-500 degrees celsius).
 * Parameters:
 *      [1] Sensor index/alias.
 *      [2] Address to data, to read into.
 * Return:
 *      value.
 *************************************************************/
LDR_tenuErrorStatus LDR_enuGetValue(LDR_tenuSensor Cpy_enuSensor, double *Add_doubleReading);


#endif /* __LDR_H__ */