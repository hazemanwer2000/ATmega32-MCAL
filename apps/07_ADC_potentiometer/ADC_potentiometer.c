/*************************************************************
 * 
 * Filename: ADC_potentiometer.c
 * Description: Application, ADC and potentiometer.
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

#include "Delay.h"


/*************************************************************
 * Description: The transition's delay, in milliseconds.
 * 
 *************************************************************/
#define DELAY_MS            1000


/*************************************************************
 * Description: Maximum/Minimum number to display.
 * 
 *************************************************************/
#define MAX_NUMBER          9
#define MIN_NUMBER          0


u8 flag = 0;


/*************************************************************
 * Description: Maximum/Minimum number to display.
 * 
 *************************************************************/
void APP_07_callback(void)
{
/*
    u16 value = (u16) ((ADC_u16GetValue() / 1023.0)*100.0);

    if (value > 99) {
        value = 99;
    }

    SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplayLow, value % 10);
    value /= 10;
    SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplayHigh, value % 10);
*/
    flag = 1;
    // ADC_voidStartConversion();
}


/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 *  
 *************************************************************/
void ADC_potentiometer()
{
    ADC_tenuErrorStatus status;
    u16 value;

    GLOBAL_INT_voidInit();
    DIO_voidInit();
    LED_enuInit();
    SEVEN_SEGMENT_enuInit();
    ADC_voidInit();

    ADC_voidConfigureInputChannel(ADC_InputChannel_ADC7);

    ADC_voidConfigureAutoTriggerSource(ADC_AutoTriggerSource_FreeRunningMode);
    ADC_voidEnableAutoTrigger();
    
    ADC_voidSetCallback(&APP_07_callback);
    ADC_voidEnableInterrupt();
    
    ADC_voidStartConversion();

    while(1) {
        if (flag == 1) {
            flag = 0;
            value = (u16) ((ADC_u16GetValue() / 1023.0)*100.0);

            if (value > 99) {
                value = 99;
            }

            SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplayLow, value % 10);
            value /= 10;
            SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplayHigh, value % 10);
        }
    }
/*
    ADC_voidConfigureInputChannel(ADC_InputChannel_ADC7);
    ADC_voidEnableInterrupt();
    ADC_voidSetCallback(&APP_07_callback);

    while (1) {
        if (flag == 1) {
            flag = 0;
            ADC_voidStartConversion();
        }
    }
*/
/*
    while (1) {
        status = ADC_enuStartConversionAndWait(&value);
        
        if (status == ADC_enuOk) {
            value /= 10.25;
            SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplay, value / 10.25);
        }
    }
*/
}