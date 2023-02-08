/*************************************************************
 * 
 * Filename: SEVEN_SEGMENT_Cfg.c
 * Description: Configuration source file of the SEVEN_SEGMENT driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "SEVEN_SEGMENT_Cfg.h"
#include "DIO.h"


/*************************************************************
 * Description: Confguration of each 7-segment.
 *                  Note: Pins are ordered 'gfedcba', starting with 'a'.
 * 
 *************************************************************/
SEVEN_SEGMENT_tstrucDisplayCfg SEVEN_SEGMENT_strucDisplayCfgs[SEVEN_SEGMENT_DISPLAY_COUNT] = {
    {
        .SEVEN_SEGMENT_uPins = {0, 1, 2, 3, 4, 5, 6},
        .SEVEN_SEGMENT_uInitNumber = 0
    }
};