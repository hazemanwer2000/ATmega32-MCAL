
#include "TIMER0.h"
#include "DIO.h"
#include "BUTTON.h"

#define BUTTON_LESS                 24
#define BUTTON_MORE                 25

#define STEP_VAL                     25
#define MAX_VAL                     250

u8 compareValue = 0;

void update(void) {
    TIMER0_voidSetCompareMatchRegister(compareValue);
}

void more(void) {
    if (compareValue < MAX_VAL) {
        compareValue += STEP_VAL;
        update(); 
    }
}

void less(void) {
    if (compareValue > 0) { 
        compareValue -= STEP_VAL; 
        update(); 
    }
}

void entry_point(void) {
    BUTTON_tenuButtonState 
        curr_less = BUTTON_enuButtonReleased,
        curr_more = BUTTON_enuButtonReleased,
        prev_less = BUTTON_enuButtonReleased,
        prev_more = BUTTON_enuButtonReleased;

    DIO_voidInit();

    TIMER0_voidConfigureWaveformGenerationMode(TIMER0_WaveformGenerationMode_FastPWM);
    TIMER0_voidConfigureCompareMatchOutputMode(TIMER0_CompareMatchOutputMode_Clear);
    TIMER0_voidSetCompareMatchRegister(0);
    TIMER0_voidConfigureClock(TIMER0_Clock_Prescale_1);

    while (1) {
        BUTTON_enuGetButtonState(BUTTON_LESS, &curr_less);
        BUTTON_enuGetButtonState(BUTTON_MORE, &curr_more);

        if (curr_less == BUTTON_enuButtonPressed && prev_less == BUTTON_enuButtonReleased) {
            less();
            // DIO_enuClearPin(11);
        }

        if (curr_more == BUTTON_enuButtonPressed && prev_more == BUTTON_enuButtonReleased) {
            more();
            // DIO_enuSetPin(11);
        }

        prev_less = curr_less;
        prev_more = curr_more;
    }
}