
#define F_CPU		1000000UL

#include <util/delay.h>
#include "Std_Types.h"

#include "DIO.h"
#include "LED.h"

#define DELAY_MS            500

void flickering_leds() {
    s8 i = 0;

    DIO_enuInit();
    LED_enuInit();

    while (1) {
        for (i = 1; i < 8; i++) {
            _delay_ms(DELAY_MS);
            LED_enuLedOff(i-1);
            LED_enuLedOn(i);
        }

        for (i = 6; i >= 0; i--) {
            _delay_ms(DELAY_MS);
            LED_enuLedOff(i+1);
            LED_enuLedOn(i);
        }
    }
}