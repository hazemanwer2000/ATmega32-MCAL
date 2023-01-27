/*************************************************************
 * 
 * Filename: BUTTON_Cfg.c
 * Description: Configuration source file of the BUTTON driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "BUTTON_Cfg.h"


/*************************************************************
 * Description: (definition) Array of configurations, for each button connected. 
 * 
 *************************************************************/
const BUTTON_tstrucButtonCfg BUTTON_strucButtonCfgs[BUTTON_NUM_OF_BUTTONS] = {
    {26, BUTTON_enuActiveHigh},
    {27, BUTTON_enuActiveHigh}
};