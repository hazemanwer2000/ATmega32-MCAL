/*************************************************************
 * 
 * Filename: ADC_LM35.c
 * Description: Application, ADC and LM35.
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


u8 flag = 1;


/*************************************************************
 * Description: Maximum/Minimum number to display.
 * 
 *************************************************************/
void APP_08_callback(void)
{
    SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplay, ADC_u16GetValue() / 103);
    flag = 1;
}


/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 *  
 *************************************************************/
void ADC_LM35()
{
    ADC_tenuErrorStatus status;
    u16 value;

    GLOBAL_INT_voidInit();
    DIO_voidInit();
    LED_enuInit();
    SEVEN_SEGMENT_enuInit();
    ADC_voidInit();

    ADC_voidConfigureInputChannel(ADC_InputChannel_ADC7);
    ADC_voidEnableInterrupt();
    ADC_voidSetCallback(&APP_07_callback);

    while (1) {
        if (flag == 1) {
            flag = 0;
            ADC_voidStartConversion();
        }
    }
/*
    while (1) {
        status = ADC_enuStartConversionAndWait(&value);
        
        if (status == ADC_enuOk) {
            SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplay, value / 103);
        }
    }
*/
}