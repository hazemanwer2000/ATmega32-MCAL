/*************************************************************
 * 
 * Filename: seven_segments.c
 * Description: Application, displaying numbers on the seven segment display,
 *                  incrementing and decrementing using push-buttons.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "Std_Types.h"
#include "Bit_Utils.h"

#include "DIO.h"
#include "LED.h"
#include "BUTTON.h"

#include "Delay.h"


/*************************************************************
 * Description: Number of LEDs in a seven-segment display
 * 
 *************************************************************/
#define LED_COUNT               7


/*************************************************************
 * Description: Patterns of numbers (index -> N) to loop around, 
 *                  encoded in bits (0 -> 6 : a -> g).
 * 
 *************************************************************/
u8 patterns[] = {
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
 * Description: Pin map (a-g -> 0-6)
 * 
 *************************************************************/
u8 mapLeast[LED_COUNT] = {0, 1, 2, 3, 4, 5, 6};
u8 mapMost[LED_COUNT] = {24, 25, 26, 27, 28, 29, 30};


/*************************************************************
 * Description: Pin map (a-g -> 0-6)
 * 
 *************************************************************/
void display_number(u8 num, u8 *map) {
    u8 i = 0;
    u8 encoded = 0;

    encoded = patterns[num];

    for (i = 0; i < LED_COUNT; i++) {
        if (GET_BIT(encoded, i) != FALSE) {
            LED_enuLedOn(map[i]);
        } else {
            LED_enuLedOff(map[i]);
        }
    }
}


/*************************************************************
 * Description: Pins connected to the on-off buttons.
 * 
 *************************************************************/
#define PIN_BUTTON_DEC          17
#define PIN_BUTTON_INC          16


/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 * 
 *************************************************************/
void seven_segments() {
    u8 i = 0;
    BUTTON_tenuButtonState stateInc, stateDec;
    u8 breakFlag = 0;

    DIO_enuInit();
    LED_enuInit();

    display_number(0, mapLeast);
    display_number(0, mapMost);

    while (1) {
        while (1)  {
            BUTTON_enuGetButtonState(PIN_BUTTON_INC, &stateInc);
            BUTTON_enuGetButtonState(PIN_BUTTON_DEC, &stateDec);
            if (stateInc == BUTTON_enuButtonReleased && stateDec == BUTTON_enuButtonReleased) {
                break;
            }
        }

        while (1)  {
            BUTTON_enuGetButtonState(PIN_BUTTON_INC, &stateInc);
            BUTTON_enuGetButtonState(PIN_BUTTON_DEC, &stateDec);
            if (stateInc == BUTTON_enuButtonPressed) {
                if (i < 99) { i++; breakFlag = TRUE; }
            } else if (stateDec == BUTTON_enuButtonPressed) {
                if (i > 0) { i--; breakFlag = TRUE; }
            }

            if (breakFlag != FALSE) {
                display_number(i % 10, mapLeast);
                display_number(i / 10, mapMost);
                breakFlag = FALSE;
                break;
            }
        }
    }
}