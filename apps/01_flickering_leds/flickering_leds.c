/*************************************************************
 * 
 * Filename: flickering_leds.c
 * Description: Application, simple and sequential LED animation.
 *                  Uses 8 LEDs.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "Delay.h"
#include "Std_Types.h"
#include "DIO.h"
#include "LED.h"


/*************************************************************
 * Description: The transition's delay, in milliseconds.
 * 
 *************************************************************/
#define DELAY_MS            500


/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 * 
 *************************************************************/
void flickering_leds() {
    s8 i = 0;
    DIO_voidInit();
    LED_enuInit();

    while (1) {
        for (i = 1; i < 8; i++) {
            delay_ms(DELAY_MS);
            LED_enuLedOff(i-1);
            LED_enuLedOn(i);
        }

        for (i = 6; i >= 0; i--) {
            delay_ms(DELAY_MS);
            LED_enuLedOff(i+1);
            LED_enuLedOn(i);
        }
    }
}