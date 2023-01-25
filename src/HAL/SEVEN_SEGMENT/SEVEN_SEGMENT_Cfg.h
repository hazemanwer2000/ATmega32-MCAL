/*************************************************************
 * 
 * Filename: SEVEN_SEGMENT_Cfg.h
 * Description: Configuration header file of the SEVEN_SEGMENT driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __SEVEN_SEGMENT_CFG_H__
#define __SEVEN_SEGMENT_CFG_H__

#include "DIO.h"
#include "SEVEN_SEGMENT_Priv.h"


/*************************************************************
 * Description: Number type, to display on the seven segment.
 * 
 *************************************************************/
typedef u8 SEVEN_SEGMENT_tuNumber;


/*************************************************************
 * Description: Number of 7-segment displays in the hardware.
 * 
 *************************************************************/
#define SEVEN_SEGMENT_DISPLAY_COUNT      2


/*************************************************************
 * Description: Labels for each 7-segment display in the hardware.
 * 
 *************************************************************/
typedef enum {
    SEVEN_SEGMENT_enuDisplayLeastSignificant = 0,
    SEVEN_SEGMENT_enuDisplayMostSignificant = 1
} SEVEN_SEGMENT_tenuDisplayName;


/*************************************************************
 * Description: Structure of confguration of each 7-segment.
 *                  Note: Pins are ordered 'gfedcba', starting with 'a'.
 * 
 *************************************************************/
typedef struct {
    DIO_tuPinNumber SEVEN_SEGMENT_uPins[SEVEN_SEGMENT_LED_COUNT];
    SEVEN_SEGMENT_tuNumber SEVEN_SEGMENT_uInitNumber;
} SEVEN_SEGMENT_tstrucDisplayCfg;


/*************************************************************
 * Description: Confguration of each 7-segment.
 *                  Note: Pins are ordered 'gfedcba', starting with 'a'.
 * 
 *************************************************************/
extern SEVEN_SEGMENT_tstrucDisplayCfg SEVEN_SEGMENT_strucDisplayCfgs[SEVEN_SEGMENT_DISPLAY_COUNT];


#endif /* __SEVEN_SEGMENT_CFG_H__ */