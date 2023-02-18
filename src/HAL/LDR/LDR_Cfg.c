/*************************************************************
 * 
 * Filename: LDR_Cfg.c
 * Description: Configuration source file of the LDR driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "LDR_Cfg.h"


/*************************************************************
 * Description: Sensor configuration.
 * 
 *************************************************************/
LDR_tstrucSensorCfg LDR_strucSensorCfgs[LDR_SENSOR_COUNT] = {
    {ADC_InputChannel_ADC0},
    {ADC_InputChannel_ADC1},
    {ADC_InputChannel_ADC2}
};
