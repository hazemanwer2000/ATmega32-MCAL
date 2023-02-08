/*************************************************************
 * 
 * Filename: LM35_Cfg.h
 * Description: Configuration header file of the LM35 driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __LM35_CFG_H__
#define __LM35_CFG_H__

#include "ADC.h"


/*************************************************************
 * Description: Sensor maximum count.
 * 
 *************************************************************/
#define LM35_SENSOR_COUNT           1


/*************************************************************
 * Description: Sensor aliases.
 * 
 *************************************************************/
typedef enum {
    LM35_enuSensor
} LM35_tenuSensor;


/*************************************************************
 * Description: (Do not alter) Sensor configuration structure.
 * 
 *************************************************************/
typedef struct {
    ADC_tuInputChannel inputChannel;
} LM35_tstrucSensorCfg;


/*************************************************************
 * Description: (Declaration) Sensor configuration.
 * 
 *************************************************************/
extern LM35_tstrucSensorCfg LM35_strucSensorCfgs[LM35_SENSOR_COUNT];


#endif /* __LM35_CFG_H__ */