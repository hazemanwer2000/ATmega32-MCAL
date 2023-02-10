/*************************************************************
 * 
 * Filename: LCD_Cfg.c
 * Description: Configuration source file of the LCD driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "LCD_Cfg.h"


/*************************************************************
 * Description: LCD configuration.
 * 
 *************************************************************/
LCD_tstrucLCDCfg LCD_strucLCDCfg = {
    .PinD = {24, 25, 26, 27, 28, 29, 30, 31},
    .PinRS = 8,
    .PinRW = 9,
    .PinE = 10
};