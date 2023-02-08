/*************************************************************
 * 
 * Filename: ADC.c
 * Description: Source file of the ADC driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "ADC.h"
#include "ADC_Priv.h"
#include "ADC_Cfg.h"
#include "Std_Types.h"
#include "IO_Map.h"
#include "Bit_Utils.h"


/*************************************************************
 * Description: ADC callback function variable.
 * 
 *************************************************************/
static void(*ADC_fCallback)(void) = NULL;


/*************************************************************
 * Description: Configure voltage reference.
 *                  Note: If configured during a converion,
 *                      change will go into effect after conversion completion.
 * Parameters:
 *      [1] Voltage reference option.
 * Return:
 *      None.
 *************************************************************/
void ADC_voidConfigureVoltageReference(ADC_tuVoltageReference Cpy_uVoltageReference)
{
    ADMUX = (~MSK_I2J(REFS0, REFS1) & ADMUX) | Cpy_uVoltageReference;
}


/*************************************************************
 * Description: Configure voltage reference.
 *                  Note: If configured during a converion,
 *                      change will go into effect after conversion completion.
 * Parameters:
 *      [1] Voltage reference option.
 * Return:
 *      None.
 *************************************************************/
void ADC_voidConfigureInputChannel(ADC_tuInputChannel Cpy_uInputChannel)
{
    ADMUX = (~MSK_I2J(MUX0, MUX4) & ADMUX) | Cpy_uInputChannel;
}


/*************************************************************
 * Description: Configure ADC clock prescale value.
 * Parameters:
 *      [1] Clock prescale option.
 * Return:
 *      None.
 *************************************************************/
void ADC_voidConfigureClockPrescale(ADC_tuClockPrescale Cpy_uClockPrescale)
{
    ADCSRA = (~MSK_I2J(ADPS0, ADPS2) & ADCSRA) | Cpy_uClockPrescale;
}


/*************************************************************
 * Description: Enable ADC unit.
 * Parameters:
 *      [X] 
 * Return:
 *      None.
 *************************************************************/
void ADC_voidEnableADC(void)
{
    ADCSRA |= 1 << ADEN;
}


/*************************************************************
 * Description: Disable ADC unit.
 *                  Note: If ADC is disabled during a conversion,
 *                          the conversion is terminated.
 * Parameters:
 *      [X] 
 * Return:
 *      None.
 *************************************************************/
void ADC_voidDisableADC(void)
{
    ADCSRA &= ~(1 << ADEN);
}


/*************************************************************
 * Description: Start a conversion (asynchronous).
 * Parameters:
 *      [X]
 * Return:
 *      None
 *************************************************************/
void ADC_voidStartConversion(void)
{
    ADCSRA |= 1 << ADSC;
}


/*************************************************************
 * Description: Get value of conversion.
 *                  Note: To be used inside callback function.
 * Parameters:
 *      [X]
 * Return:
 *      Value.
 *************************************************************/
u16 ADC_u16GetValue(void)
{
    u16 Loc_u16Value = (u16) ADCL;
    Loc_u16Value |= ((u16) ADCH) << 8;
    return Loc_u16Value;
}


/*************************************************************
 * Description: Set callback function.
 * Parameters:
 *      [1] Address, to return result into.
 * Return:
 *      None
 *************************************************************/
void ADC_voidSetCallback(void (*Cpy_fCallback)(void))
{
    ADC_fCallback = Cpy_fCallback;
}


/*************************************************************
 * Description: Start conversion and wait for value (synchronous).
 * Parameters:
 *      [1] Address, to return result into. 
 * Return:
 *      Error status:
 *          [Ok]: Successfull.
 *          [ConversionInProgress]: Failed due to ongoing conversion.
 *          [Timeout]: Failed, timed out.
 *************************************************************/
ADC_tenuErrorStatus ADC_enuStartConversionAndWait(u16 *Add_u16Data)
{
    ADC_tenuErrorStatus Loc_enuErrorStatus = ADC_enuOk;
    u8 Loc_u8Timeout = ADC_CONVERSION_TIME;

    if (Add_u16Data == NULL) {
        Loc_enuErrorStatus = ADC_enuNullPointer;
    } else {
        ADCSRA |= 1 << ADSC;

        while ((ADCSRA & (1 << ADIF)) == 0 && --Loc_u8Timeout > 0);

        if (Loc_u8Timeout == 0) {
            Loc_enuErrorStatus = ADC_enuTimeout;
        } else {
            *Add_u16Data = (u16) ADCL;
            *Add_u16Data |= ((u16) ADCH) << 8;

            ADCSRA |= 1 << ADIF;
        }
    }

    return Loc_enuErrorStatus;
}


/*************************************************************
 * Description: Enable interrupt.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void ADC_voidEnableInterrupt(void)
{
    ADCSRA |= 1 << ADIE;
}


/*************************************************************
 * Description: Disable interrupt.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void ADC_voidDisableInterrupt(void)
{
    ADCSRA &= ~(1 << ADIE);
}


/*************************************************************
 * Description: Enable Auto-Trigger.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void ADC_voidEnableAutoTrigger(void)
{
    ADCSRA |= 1 << ADATE;
}


/*************************************************************
 * Description: Disable Auto-Trigger.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void ADC_voidDisableAutoTrigger(void)
{
    ADCSRA |= ~(1 << ADATE);
}


/*************************************************************
 * Description: Configure Auto-Trigger Source
 * Parameters:
 *      [1] Auto-Trigger Source option.
 * Return:
 *      None.
 *************************************************************/
void ADC_voidConfigureAutoTriggerSource(ADC_tuAutoTriggerSource Cpy_uAutoTriggerSource)
{
    SFIOR = (~MSK_I2J(ADTS0, ADTS2) & SFIOR) | Cpy_uAutoTriggerSource;
}


/*************************************************************
 * Description: ADC ISR (Upon conversion completion).
 * 
 *************************************************************/
ISRx(VECT_ADC)
{
    if (ADC_fCallback != NULL) {
        ADC_fCallback();
    }
}


/******************** Short-Cut API(s) *********************/


/*************************************************************
 * Description: Initialization of ADC module.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void ADC_voidInit(void)
{
    ADC_voidEnableADC();
    ADC_voidConfigureClockPrescale(ADC_CFG_CLOCK_PRESCALER);
    ADC_voidConfigureVoltageReference(ADC_CFG_VOLTAGE_REFERENCE);
}