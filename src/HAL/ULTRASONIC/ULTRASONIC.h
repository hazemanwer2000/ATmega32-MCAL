/*************************************************************
 * 
 * Filename: ULTRASONIC.h
 * Description: Header (interface) file of the ULTRASONIC driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __ULTRASONIC_H__
#define __ULTRASONIC_H__

#include "ULTRASONIC_Cfg.h"
#include "ULTRASONIC_Types.h"

void ULTRASONIC_voidInit(void (*fptr)(u64));

void ULTRASONIC_voidTrigger(void);

#endif /* __ULTRASONIC_H__ */