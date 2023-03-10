
#include "TIMER0.h"
#include "GLOBAL_INT.h"
#include "DIO.h"
#include "LED.h"

#define CLK_MHZ                 1
#define CLK_Prescale            8

#define LED_ACK                 24

u8 LEDState = 0;
u64 counter = 0;

u64 counterMax = 0;
u8 preload = 0;

void overflowEvent() {
    counter++;
    
    if (counter == counterMax) {
        TIMER0_voidSetTimerRegister(preload);
        counter = 0;

        LEDState = !LEDState;
        if (LEDState == 0) { 
            LED_enuLedOn(LED_ACK);
        } else {
            LED_enuLedOff(LED_ACK);
        }
    }
}

void delay_in_ms(u64 ms) {
    u64 count = ms * ((1000 / CLK_Prescale) * CLK_MHZ);
    preload = 256 - count % 256;
    counterMax = count / 256;

    TIMER0_voidSetTimerRegister(preload);
    counter = 0;
}

void entry_point(void) {
    GLOBAL_INT_voidEnable();

    DIO_voidInit();
    LED_enuInit();

    TIMER0_voidSetOverflowCallback(&overflowEvent);
    TIMER0_voidEnableOverflowInterrupt();

    TIMER0_voidConfigureWaveformGenerationMode(TIMER0_WaveformGenerationMode_Normal);
    TIMER0_voidConfigureCompareMatchOutputMode(TIMER0_CompareMatchOutputMode_Disconnected);

    TIMER0_voidConfigureClock(TIMER0_Clock_Prescale_8);

    delay_in_ms(1000);

    while (1);
}