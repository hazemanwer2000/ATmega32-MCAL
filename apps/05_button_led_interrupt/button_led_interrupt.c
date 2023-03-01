/*************************************************************
 * 
 * Filename: button_led_interrupt.c
 * Description: Application, increment and decrement the number
 *                  of LEDs on (interrupt-based).
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "Std_Types.h"

#include "DIO.h"
#include "LED.h"
#include "GLOBAL_INT.h"
#include "EXT_INT.h"

#include <avr/interrupt.h>


/*************************************************************
 * Description: Maximum number of LEDs.
 * 
 *************************************************************/
#define MAX_LEDS            8


s8 cnt = -1;


ISR (INT0_vect) {
    if (cnt < MAX_LEDS-1) {
        LED_enuLedOn(++cnt);
    }
}


ISR (INT1_vect) {
    if (cnt >= 0) {
        LED_enuLedOff(cnt--);
    }
}


/*************************************************************
 * Description: Entry point to the application.
 * Parameters:vb
 *      [X]
 * 
 *************************************************************/
void button_led_interrupt() {
    DIO_voidInit();
    LED_enuInit();
    EXT_INT_voidInit();
    GLOBAL_INT_voidInit();
    while (1) {}
}