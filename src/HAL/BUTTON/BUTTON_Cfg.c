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
    {16, BUTTON_enuActiveLow},
    {17, BUTTON_enuActiveLow},
    {18, BUTTON_enuActiveLow},
    {19, BUTTON_enuActiveLow}
};