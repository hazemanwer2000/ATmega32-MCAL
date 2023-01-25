/*************************************************************
 * 
 * Filename: SEVEN_SEGMENT.c
 * Description: Source file of the SEVEN_SEGMENT driver.
 *                  Note: This driver uses 'LED' driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "SEVEN_SEGMENT_Cfg.h"
#include "SEVEN_SEGMENT_Priv.h"
#include "SEVEN_SEGMENT.h"

#include "LED.h"

#include "Bit_Utils.h"



/*************************************************************
 * Description: Mapping of numbers (indexes) to states of LEDs (gfedcba).
 * 
 *************************************************************/
u8 SEVEN_SEGMENTS_u8Mapping[] = {
/*  ___gfedcba (0) */
    0b00111111,

/*  ___gfedcba (1) */
    0b00000110,

/*  ___gfedcba (2) */
    0b01011011,

/*  ___gfedcba (3) */
    0b01001111,

/*  ___gfedcba (4) */
    0b01100110,

/*  ___gfedcba (5) */
    0b01101101,

/*  ___gfedcba (6) */
    0b01111101,

/*  ___gfedcba (7) */
    0b00000111,

/*  ___gfedcba (8) */
    0b01111111,

/*  ___gfedcba (9) */
    0b01101111
};



/*************************************************************
 * Description: Initialize 7-segment display(s).
 * Parameters:
 *      [X]
 * Return:
 *          Error Status.
 *************************************************************/
SEVEN_SEGMENT_tenuErrorStatus SEVEN_SEGMENT_enuInit(void) {
    SEVEN_SEGMENT_tenuErrorStatus Loc_enuErrorStatus = SEVEN_SEGMENT_enuOk;
    u8 Loc_u8DisplayIterator = 0;

    for (Loc_u8DisplayIterator = 0; Loc_u8DisplayIterator < SEVEN_SEGMENT_DISPLAY_COUNT; Loc_u8DisplayIterator++) {
        Loc_enuErrorStatus = SEVEN_SEGMENT_enuSetNumber(Loc_u8DisplayIterator, 
                                SEVEN_SEGMENT_strucDisplayCfgs[Loc_u8DisplayIterator].SEVEN_SEGMENT_uInitNumber);
        
        if (Loc_enuErrorStatus != SEVEN_SEGMENT_enuOk) {
            break;
        }
    }

    return Loc_enuErrorStatus;
}



/*************************************************************
 * Description: Initialize 7-segment display(s).
 *                  Note: 'LED_init' must be called first.
 * Parameters:
 *      [X]
 * Return:
 *          Error Status.
 *************************************************************/
SEVEN_SEGMENT_tenuErrorStatus SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_tenuDisplayName Cpy_enuDisplayName,
            SEVEN_SEGMENT_tuNumber Cpy_uNumber) {
    SEVEN_SEGMENT_tenuErrorStatus Loc_enuErrorStatus = SEVEN_SEGMENT_enuOk;
    LED_tenuErrorStatus Loc_enuLEDErrorStatus = LED_enuOk;
    DIO_tuPinNumber Loc_uPinIterator = 0;

    if (Cpy_enuDisplayName < 0 || Cpy_enuDisplayName >= SEVEN_SEGMENT_DISPLAY_COUNT) {
        Loc_enuErrorStatus = SEVEN_SEGMENT_enuInvalidDisplay;
    } else if (Cpy_uNumber < SEVEN_SEGMENT_MIN_NUMBER || Cpy_uNumber > SEVEN_SEGMENT_MAX_NUMBER) {
        Loc_enuErrorStatus = SEVEN_SEGMENT_enuInvalidNumber;
    } else {
        for (Loc_uPinIterator = 0; Loc_uPinIterator < SEVEN_SEGMENT_LED_COUNT; Loc_uPinIterator++) {
            if (GET_BIT(SEVEN_SEGMENTS_u8Mapping[Cpy_uNumber], Loc_uPinIterator)) {
                Loc_enuLEDErrorStatus = LED_enuLedOn(SEVEN_SEGMENT_strucDisplayCfgs[Cpy_enuDisplayName]
                    .SEVEN_SEGMENT_uPins[Loc_uPinIterator]);
            } else {
                Loc_enuLEDErrorStatus = LED_enuLedOff(SEVEN_SEGMENT_strucDisplayCfgs[Cpy_enuDisplayName]
                    .SEVEN_SEGMENT_uPins[Loc_uPinIterator]);
            }

            if (Loc_enuLEDErrorStatus != LED_enuOk) {
                Loc_enuErrorStatus = SEVEN_SEGMENT_enuInvalidPinCfg;
                break;
            }
        }
    }

    return Loc_enuErrorStatus;
}