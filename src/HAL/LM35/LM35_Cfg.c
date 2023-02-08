/*************************************************************
 * 
 * Filename: LM35_Cfg.c
 * Description: Configuration source file of the LM35 driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "LM35_Cfg.h"


/*************************************************************
 * Description: Sensor configuration.
 * 
 *************************************************************/
LM35_tstrucSensorCfg LM35_strucSensorCfgs[LM35_SENSOR_COUNT] = {
    {ADC_InputChannel_ADC7}
};
