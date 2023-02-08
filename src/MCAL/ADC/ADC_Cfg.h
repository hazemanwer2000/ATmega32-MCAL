/*************************************************************
 * 
 * Filename: ADC_Cfg.h
 * Description: Configuration header file of the ADC driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __ADC_CFG_H__
#define __ADC_CFG_H__

#include "ADC.h"


/*************************************************************
 * Description: Initialization of clock prescaler, and voltage reference.
 * 
 *************************************************************/
#define ADC_CFG_CLOCK_PRESCALER                 ADC_ClockPrescale_128
#define ADC_CFG_VOLTAGE_REFERENCE               ADC_VoltageReference_AVCC


#endif /* __ADC_CFG_H__ */