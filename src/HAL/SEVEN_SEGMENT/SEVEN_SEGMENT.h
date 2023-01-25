/*************************************************************
 * 
 * Filename: SEVEN_SEGMENT.h
 * Description: Header (interface) file of the SEVEN_SEGMENT driver.
 *                  Note: This driver uses 'LED' driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __SEVEN_SEGMENT_H__
#define __SEVEN_SEGMENT_H__

#include "Std_Types.h"
#include "SEVEN_SEGMENT_Cfg.h"


/*************************************************************
 * Description: Number type, to display on the seven segment.
 * 
 *************************************************************/
typedef u8 SEVEN_SEGMENT_tuNumber;



/*************************************************************
 * Description: Number type, to display on the seven segment.
 * 
 *************************************************************/
typedef enum {
    SEVEN_SEGMENT_enuOk = 0,
    SEVEN_SEGMENT_enuNotOk,
    SEVEN_SEGMENT_enuInvalidNumber,
    SEVEN_SEGMENT_enuInvalidDisplay,
    SEVEN_SEGMENT_enuInvalidPinCfg
} SEVEN_SEGMENT_tenuErrorStatus;



/*************************************************************
 * Description: Initialize 7-segment display(s).
 * Parameters:
 *      [X]
 * Return:
 *          Error Status.
 *************************************************************/
SEVEN_SEGMENT_tenuErrorStatus SEVEN_SEGMENT_enuInit(void);



/*************************************************************
 * Description: Initialize 7-segment display(s).
 *                  Note: 'LED_init' must be called first.
 * Parameters:
 *      [X]
 * Return:
 *          Error Status.
 *************************************************************/
SEVEN_SEGMENT_tenuErrorStatus SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_tenuDisplayName Cpy_enuDisplayName,
            SEVEN_SEGMENT_tuNumber Cpy_uNumber);


#endif /* __SEVEN_SEGMENT_H__ */