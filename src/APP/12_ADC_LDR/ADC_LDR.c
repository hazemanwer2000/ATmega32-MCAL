/*************************************************************
 * 
 * Filename: ADC_LDR.c
 * Description: Application, ADC and LDR.
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


/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 *  
 *************************************************************/
void ADC_LDR()
{
    LDR_tenuErrorStatus status;
    double reading;
    u16 value;

    GLOBAL_INT_voidInit();
    DIO_voidInit();
    LED_enuInit();
    SEVEN_SEGMENT_enuInit();
    ADC_voidInit();

/*
    ADC_voidConfigureInputChannel(ADC_InputChannel_ADC7);

    while (1) {
        status = ADC_enuStartConversionAndWait(&value);
        
        if (status == ADC_enuOk) {
            SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplay, value / 103);
        }
    }
*/

    while (1) {
        status = LDR_enuGetValue(0, &reading);
        
        if (status == LDR_enuOk) {
            value = (u16) reading;
            SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplayLow, value % 10);
            value /= 10;
            SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplayHigh, value % 10);
        }
    }
}