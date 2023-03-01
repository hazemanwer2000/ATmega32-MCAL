
#include "TIMER0.h"
#include "GLOBAL_INT.h"
#include "DIO.h"
#include "LED.h"

#define LED_ACK                 24

u8 counter = 0;
u8 LEDState = 0;

void overflowEvent() {
    counter++;
    
    if (counter == 4) {
        counter = 0;

        LEDState = !LEDState;

        if (LEDState == 0) { 
            LED_enuLedOn(LED_ACK);
        } else {
            LED_enuLedOff(LED_ACK);
        }
    }
}

void entry_point(void) {
    GLOBAL_INT_voidEnable();

    DIO_voidInit();
    LED_enuInit();

    TIMER0_voidSetOverflowCallback(&overflowEvent);
    TIMER0_voidEnableOverflowInterrupt();

    TIMER0_voidConfigureWaveformGenerationMode(TIMER0_WaveformGenerationMode_CTC);
    TIMER0_voidSetCompareMatchRegister(TIMER0_TimerRegister_Max/2);
    TIMER0_voidConfigureCompareMatchOutputMode(TIMER0_CompareMatchOutputMode_Disconnected);
    TIMER0_voidConfigureClock(TIMER0_Clock_Prescale_1024);

    while (1) {}
}