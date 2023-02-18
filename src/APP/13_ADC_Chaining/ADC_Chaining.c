/*************************************************************
 * 
 * Filename: ADC_Chaining.c
 * Description: Application, ADC and Chaining LDR.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "Std_Types.h"
#include "Bit_Utils.h"

#include "DIO.h"
#include "LED.h"
#include "SEVEN_SEGMENT.h"
#include "SEVEN_SEGMENT_Cfg.h"
#include "GLOBAL_INT.h"
#include "ADC.h"
#include "LDR.h"
#include "delay.h"


#define ADC_CHANNEL_MAX             3
#define ADC_DELAY                   500


u8 ADC_update = 0;
u8 ADC_channel = 0;


void ADC_callback(void) {
    u16 value;

    value = (1 - (ADC_u16GetValue() / 1023.0)) * 99;

    SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplayLow, value % 10);
    value /= 10;
    SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplayHigh, value % 10);

    if (++ADC_channel == ADC_CHANNEL_MAX) { ADC_channel = 0; }

    ADC_voidConfigureInputChannel(ADC_channel);

    delay_ms(ADC_DELAY);

    ADC_voidStartConversion();
}


/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 *  
 *************************************************************/
void ADC_Chaining()
{
    GLOBAL_INT_voidInit();
    DIO_voidInit();
    LED_enuInit();
    SEVEN_SEGMENT_enuInit();
    ADC_voidInit();

    ADC_voidEnableInterrupt();

    ADC_voidSetCallback(&ADC_callback);
    ADC_voidStartConversion();

    while (1) {}
}