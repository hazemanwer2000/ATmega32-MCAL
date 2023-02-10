/*************************************************************
 * 
 * Filename: LCD_Cfg.h
 * Description: Configuration header file of the LCD driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __LCD_CFG_H__
#define __LCD_CFG_H__

#include "DIO.h"


/*************************************************************
 * Description: (Do not change) Structural representation of the LCD configuration.
 * 
 *************************************************************/
typedef struct {
    DIO_tuPinNumber PinD[8], PinRS, PinRW, PinE;
} LCD_tstrucLCDCfg;


/*************************************************************
 * Description: LCD configuration.
 * 
 *************************************************************/
extern LCD_tstrucLCDCfg LCD_strucLCDCfg;


#endif /* __LCD_CFG_H__ */