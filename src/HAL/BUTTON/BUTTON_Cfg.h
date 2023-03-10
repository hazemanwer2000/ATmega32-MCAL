/*************************************************************
 * 
 * Filename: BUTTON_Cfg.h
 * Description: Configuration header file of the BUTTON driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __BUTTON_CFG_H__
#define __BUTTON_CFG_H__

#include "BUTTON.h"


/*************************************************************
 * Description: Debounce configuration, count and delay in ms.
 * 
 *************************************************************/
#define BUTTON_DEBOUNCE_COUNT               5
#define BUTTON_DEBOUNCE_DELAY_MS            5


/*************************************************************
 * Description: Number of LEDs connected to the hardware.
 * 
 *************************************************************/
#define BUTTON_NUM_OF_BUTTONS      2


/*************************************************************
 * Description: Configuration of BUTTON, whether active low or high.
 * 
 *************************************************************/
typedef enum {
    BUTTON_enuActiveHigh = 0,
    BUTTON_enuActiveLow = 1
} BUTTON_tenuActiveCfg;


/*************************************************************
 * Description: Structural representation of the configuration of a Button.
 * 
 *************************************************************/
typedef struct {
    BUTTON_tuPinNumber Mem_uPinNumber;
    BUTTON_tenuActiveCfg Mem_enuActiveCfg;
} BUTTON_tstrucButtonCfg;


/*************************************************************
 * Description: Array of configurations, for each Button connected. 
 * 
 *************************************************************/
extern const BUTTON_tstrucButtonCfg BUTTON_strucButtonCfgs[BUTTON_NUM_OF_BUTTONS];


#endif /* __BUTTON_CFG_H__ */