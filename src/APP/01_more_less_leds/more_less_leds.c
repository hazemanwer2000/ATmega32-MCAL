
#define F_CPU		1000000UL

#include "Std_Types.h"

#include "DIO.h"
#include "LED.h"
#include "BUTTON.h"

#define BUTTON_INC          16
#define BUTTON_DEC          17

#define MAX_LEDS            8

void more_less_leds() {
    s8 cnt = -1;
    BUTTON_tenuButtonState stateInc, stateDec;

    DIO_enuInit();
    LED_enuInit();

    while (1) {
        while (1)  {
            BUTTON_enuGetButtonState(BUTTON_INC, &stateInc);
            BUTTON_enuGetButtonState(BUTTON_DEC, &stateDec);
            if (stateInc == BUTTON_enuButtonReleased && stateDec == BUTTON_enuButtonReleased) {
                break;
            }
        }

        while (1)  {
            BUTTON_enuGetButtonState(BUTTON_INC, &stateInc);
            BUTTON_enuGetButtonState(BUTTON_DEC, &stateDec);
            if (stateInc == BUTTON_enuButtonPressed) {
                if (cnt < MAX_LEDS-1) {
                    LED_enuLedOn(++cnt);
                }
                break;
            } else if (stateDec == BUTTON_enuButtonPressed) {
                if (cnt >= 0) {
                    LED_enuLedOff(cnt--);
                }
                break;
            }
        }
    }
}