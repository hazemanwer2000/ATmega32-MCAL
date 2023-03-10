/*************************************************************
 * 
 * Filename: LED_Cfg.c
 * Description: Configuration (source) file of the LED driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "LED_Cfg.h"


/*************************************************************
 * Description: (definition) Array of configurations, for each LED connected. 
 * 
 *************************************************************/
const LED_tstrucLedCfg LED_strucLedCfgs[LED_NUM_OF_LEDS] = {
    {24, LED_enuActiveHigh, LED_enuLedStateOff}
};