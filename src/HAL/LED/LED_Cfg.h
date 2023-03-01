/*************************************************************
 * 
 * Filename: LED_Cfg.h
 * Description: Configuration (header) file of the LED driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __LED_CFG_H__
#define __LED_CFG_H__

#include "LED.h"


/*************************************************************
 * Description: Number of LEDs connected to the hardware.
 * 
 *************************************************************/
#define LED_NUM_OF_LEDS         1


/*************************************************************
 * Description: Configuration of LED, whether active low or high.
 * 
 *************************************************************/
typedef enum {
    LED_enuActiveHigh = 0,
    LED_enuActiveLow = 1
} LED_tenuActiveCfg;


/*************************************************************
 * Description: Representation of state of LED, whether on or off.
 * 
 *************************************************************/
typedef enum {
    LED_enuLedStateOff = 0,
    LED_enuLedStateOn = 1
} LED_tenuLedState;


/*************************************************************
 * Description: Structural representation of the configuration of an LED.
 * 
 *************************************************************/
typedef struct {
    LED_tuPinNumber Mem_uPinNumber;
    LED_tenuActiveCfg Mem_enuActiveCfg;
    LED_tenuLedState Mem_enuInitLedState;
} LED_tstrucLedCfg;


/*************************************************************
 * Description: Array of configurations, for each LED connected. 
 * 
 *************************************************************/
extern const LED_tstrucLedCfg LED_strucLedCfgs[LED_NUM_OF_LEDS];


#endif /* __LED_CFG_H__ */