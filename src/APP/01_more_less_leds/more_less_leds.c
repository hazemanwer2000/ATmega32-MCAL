
#define F_CPU		1000000UL

#include "Std_Types.h"

#include "DIO.h"
#include "LED.h"
#include "BUTTON.h"

#define BUTTON_INC          16
#define BUTTON_DEC          17

void flickering_leds() {
    u8 cnt = 0;
    BUTTON_tenuButtonState buttonState;

    DIO_enuInit();
    LED_enuInit();

    while (1) {
        BUTTON_enuGetButtonState(BUTTON_INC, &buttonState);
        if (buttonState == BUTTON_enuButtonPressed) {
            LED_enuLedOn(0);
        } else if (buttonState == BUTTON_enuButtonReleased) {
            LED_enuLedOff(0);
        }
    }
}