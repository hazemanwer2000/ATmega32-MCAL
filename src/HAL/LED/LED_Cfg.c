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
    {0, LED_enuActiveHigh, LED_enuLedStateOff},
    {1, LED_enuActiveHigh, LED_enuLedStateOff},
    {2, LED_enuActiveHigh, LED_enuLedStateOff},
    {3, LED_enuActiveHigh, LED_enuLedStateOff},
    {4, LED_enuActiveHigh, LED_enuLedStateOff},
    {5, LED_enuActiveHigh, LED_enuLedStateOff},
    {6, LED_enuActiveHigh, LED_enuLedStateOff},

    {24, LED_enuActiveHigh, LED_enuLedStateOff},
    {25, LED_enuActiveHigh, LED_enuLedStateOff},
    {26, LED_enuActiveHigh, LED_enuLedStateOff},
    {27, LED_enuActiveHigh, LED_enuLedStateOff},
    {28, LED_enuActiveHigh, LED_enuLedStateOff},
    {29, LED_enuActiveHigh, LED_enuLedStateOff},
    {30, LED_enuActiveHigh, LED_enuLedStateOff}
};