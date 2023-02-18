/*************************************************************
 * 
 * Filename: LDR_Cfg.h
 * Description: Configuration header file of the LDR driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __LDR_CFG_H__
#define __LDR_CFG_H__

#include "ADC.h"


/*************************************************************
 * Description: Sensor maximum count.
 * 
 *************************************************************/
#define LDR_SENSOR_COUNT           3


/*************************************************************
 * Description: Sensor aliases.
 * 
 *************************************************************/
typedef enum {
    LDR_enuSensor
} LDR_tenuSensor;


/*************************************************************
 * Description: (Do not alter) Sensor configuration structure.
 * 
 *************************************************************/
typedef struct {
    ADC_tuInputChannel inputChannel;
} LDR_tstrucSensorCfg;


/*************************************************************
 * Description: (Declaration) Sensor configuration.
 * 
 *************************************************************/
extern LDR_tstrucSensorCfg LDR_strucSensorCfgs[LDR_SENSOR_COUNT];


#endif /* __LDR_CFG_H__ */