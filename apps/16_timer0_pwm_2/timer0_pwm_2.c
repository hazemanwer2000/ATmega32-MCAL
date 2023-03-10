
#include "TIMER0.h"
#include "DIO.h"
#include "LED.h"
#include "ADC.h"
#include "SERVO.h"

void entry_point(void) {
    u16 value = 0;

    DIO_voidInit();
    LED_enuInit();
    ADC_voidInit();
    SERVO_voidInit();
    
    while (1) {
        ADC_enuStartConversionAndWait(&value);
        
        if (value > 512) {
            LED_enuLedOn(24);
        } else {
            LED_enuLedOff(24);
        }

        SERVO_enuSetAngle((u8) ((value / 1023.0) * 180));
    }
}