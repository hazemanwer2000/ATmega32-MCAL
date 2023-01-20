/*************************************************************
 * 
 * Filename: counting_segments.c
 * Description: Application, displaying numbers on the seven segment display,
 *                  delayed increase and decrease.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "Std_Types.h"
#include "Bit_Utils.h"

#include "DIO.h"
#include "LED.h"

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
extern u8 patterns[];


/*************************************************************
 * Description: Pin map (a-g -> 0-6)
 * 
 *************************************************************/
extern u8 mapLeast[LED_COUNT];
extern u8 mapMost[LED_COUNT];


/*************************************************************
 * Description: Pin map (a-g -> 0-6)
 * 
 *************************************************************/
void display_number(u8 num, u8 *map);


/*************************************************************
 * Description: Milliseconds to delay between increment, or decrement.
 * 
 *************************************************************/
#define DELAY_MS            500


/*************************************************************
 * Description: Minimum and maximum numbers to swing between.
 * 
 *************************************************************/
#define DISPLAY_NUM_MIN     14
#define DISPLAY_NUM_MAX     36


/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 * 
 *************************************************************/
void counting_segments() {
    s8 i = 0;

    DIO_enuInit();
    LED_enuInit();

    while (1) {
        for (i = DISPLAY_NUM_MIN; i < DISPLAY_NUM_MAX; i++) {
            display_number(i % 10, mapLeast);
            display_number(i / 10, mapMost);
            delay_ms(DELAY_MS);
        }

        for (i = DISPLAY_NUM_MAX; i > DISPLAY_NUM_MIN; i--) {
            display_number(i % 10, mapLeast);
            display_number(i / 10, mapMost);
            delay_ms(DELAY_MS);
        }
    }
}