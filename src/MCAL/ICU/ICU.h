/*************************************************************
 * 
 * Filename: ICU.h
 * Description: Header (interface) file of the ICU driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __ICU_H__
#define __ICU_H__

#include "ICU_Cfg.h"
#include "ICU_Types.h"


/*************************************************************
 * Description: Initialize ICU (Timer1).
 * Parameters:
 *      [1] Callback function.
 * Return:
 *      None.
 *************************************************************/
void ICU_voidInit(void (*fptr)(u64));


#endif /* __ICU_H__ */