/*************************************************************
 * 
 * Filename: seven_segments.c
 * Description: Application, displaying numbers on the seven segment display.
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
 * Description: Pin map (a-g -> 0-6)
 * 
 *************************************************************/
u8 map[LED_COUNT] = {0, 1, 2, 3, 4, 5, 6};


/*************************************************************
 * Description: Pin map (a-g -> 0-6)
 * 
 *************************************************************/
void display_number(u8 encoded) {
    u8 i = 0;

    for (i = 0; i < LED_COUNT; i++) {
        if (GET_BIT(encoded, i) != FALSE) {
            LED_enuLedOn(map[i]);
        } else {
            LED_enuLedOff(map[i]);
        }
    }
}


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
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 * 
 *************************************************************/
void seven_segments() {
    u8 i = 0;

    DIO_enuInit();
    LED_enuInit();

    while (1) {
        for (i = 0; i <= 9; i++) {
            display_number(patterns[i]);
            delay_ms(600);
        }
    }
}