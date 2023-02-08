/*************************************************************
 * 
 * Filename: ADC.h
 * Description: Header (interface) file of the ADC driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * Notes: 
 *      [1]: The ADC unit in ATmega32 uC has 10-bit resolution.
 * 
 *************************************************************/

#ifndef __ADC_H__
#define __ADC_H__

#include "Std_Types.h"
#include "IO_Map.h"


/*************************************************************
 * Description: Voltage reference options. 
 *      [1] AREF: External, 'AREF' pin.
 *      [2] AVCC: 'AVCC' (with external capacitor on 'AREF' pin).
 *      [3] Internal: Internal 2.56V voltage (with external capacitor on 'AREF' pin).
 *************************************************************/
#define ADC_VoltageReference_AREF                   (0 << REFS0)
#define ADC_VoltageReference_AVCC                   (1 << REFS0)
#define ADC_VoltageReference_Internal               (3 << REFS0)


/*************************************************************
 * Description: Input channel options.
 *      [1] AREF: External, 'AREF' pin.
 *      [2] AVCC: 'AVCC' (with external capacitor on 'AREF' pin).
 *      [3] Internal: Internal 2.56V voltage (with external capacitor on 'AREF' pin).
 *************************************************************/
#define ADC_InputChannel_ADC0                       (0 << MUX0)
#define ADC_InputChannel_ADC1                       (1 << MUX0)
#define ADC_InputChannel_ADC2                       (2 << MUX0)
#define ADC_InputChannel_ADC3                       (3 << MUX0)
#define ADC_InputChannel_ADC4                       (4 << MUX0)
#define ADC_InputChannel_ADC5                       (5 << MUX0)
#define ADC_InputChannel_ADC6                       (6 << MUX0)
#define ADC_InputChannel_ADC7                       (7 << MUX0)


/*************************************************************
 * Description: Auto-Trigger Source options.
 *      [1] FreeRunningMode: Automatically triggered upon conversion completion.
 *              Note: In this mode, conversion should be started at least once,
 *                      to kickstart the automatic triggering sequence.
 *      [2-7]: Different trigger sources, from different interrupts.
 *              Note: Interrupt sources need not be enabled. 
 *************************************************************/
#define ADC_AutoTriggerSource_FreeRunningMode               (0 << ADTS0)
#define ADC_AutoTriggerSource_AnalogComparator              (1 << ADTS0)
#define ADC_AutoTriggerSource_ExternalInterrupt0            (2 << ADTS0)
#define ADC_AutoTriggerSource_Timer0CompareMatch            (3 << ADTS0)
#define ADC_AutoTriggerSource_Timer0Overflow                (4 << ADTS0)
#define ADC_AutoTriggerSource_Timer1CompareMatch            (5 << ADTS0)
#define ADC_AutoTriggerSource_Timer1Overflow                (6 << ADTS0)
#define ADC_AutoTriggerSource_Timer1CaptureEvent            (7 << ADTS0)


/*************************************************************
 * Description: aDC Clock Prescale options.
 * 
 *************************************************************/
#define ADC_ClockPrescale_2                 (1 << ADPS0)
#define ADC_ClockPrescale_4                 (2 << ADPS0)
#define ADC_ClockPrescale_8                 (3 << ADPS0)
#define ADC_ClockPrescale_16                (4 << ADPS0)
#define ADC_ClockPrescale_32                (5 << ADPS0)
#define ADC_ClockPrescale_64                (6 << ADPS0)
#define ADC_ClockPrescale_128               (7 << ADPS0)


/*************************************************************
 * Description: Type-definitions.
 * 
 *************************************************************/
typedef u8 ADC_tuVoltageReference;
typedef u8 ADC_tuInputChannel;
typedef u8 ADC_tuAutoTriggerSource;
typedef u8 ADC_tuClockPrescale;


/*************************************************************
 * Description: Error status, return by various functions.
 *      (Ok):                   Successful.
 * 
 *************************************************************/
typedef enum {
    ADC_enuOk = 0,
    ADC_enuNullPointer,
    ADC_enuTimeout
} ADC_tenuErrorStatus;


/*************************************************************
 * Description: Configure voltage reference.
 *                  Note: If configured during a converion,
 *                      change will go into effect after conversion completion.
 * Parameters:
 *      [1] Voltage reference option.
 * Return:
 *      None.
 *************************************************************/
void ADC_voidConfigureVoltageReference(ADC_tuVoltageReference);


/*************************************************************
 * Description: Configure voltage reference.
 *                  Note: If configured during a converion,
 *                      change will go into effect after conversion completion.
 * Parameters:
 *      [1] Voltage reference option.
 * Return:
 *      None.
 *************************************************************/
void ADC_voidConfigureInputChannel(ADC_tuInputChannel);


/*************************************************************
 * Description: Configure ADC clock prescale value.
 * Parameters:
 *      [1] Clock prescale option.
 * Return:
 *      None.
 *************************************************************/
void ADC_voidConfigureClockPrescale(ADC_tuClockPrescale);


/*************************************************************
 * Description: Enable ADC unit.
 * Parameters:
 *      [X] 
 * Return:
 *      None.
 *************************************************************/
void ADC_voidEnableADC(void);


/*************************************************************
 * Description: Disable ADC unit.
 *                  Note: If ADC is disabled during a conversion,
 *                          the conversion is terminated.
 * Parameters:
 *      [X] 
 * Return:
 *      None.
 *************************************************************/
void ADC_voidDisableADC(void);


/*************************************************************
 * Description: Start a conversion (asynchronous).
 * Parameters:
 *      [X]
 * Return:
 *      None
 *************************************************************/
void ADC_voidStartConversion(void);


/*************************************************************
 * Description: Get value of conversion.
 *                  Note: To be used inside callback function.
 * Parameters:
 *      [X]
 * Return:
 *      Value.
 *************************************************************/
u16 ADC_u16GetValue(void);


/*************************************************************
 * Description: Set callback function.
 * Parameters:
 *      [1] Address, to return result into.
 * Return:
 *      None
 *************************************************************/
void ADC_voidSetCallback(void (*)(void));


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
ADC_tenuErrorStatus ADC_enuStartConversionAndWait(u16 *);


/*************************************************************
 * Description: Enable interrupt.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void ADC_voidEnableInterrupt(void);


/*************************************************************
 * Description: Disable interrupt.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void ADC_voidDisableInterrupt(void);


/*************************************************************
 * Description: Enable Auto-Trigger.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void ADC_voidEnableAutoTrigger(void);


/*************************************************************
 * Description: Disable Auto-Trigger.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void ADC_voidDisableAutoTrigger(void);


/*************************************************************
 * Description: Configure Auto-Trigger Source
 * Parameters:
 *      [1] Auto-Trigger Source option.
 * Return:
 *      None.
 *************************************************************/
void ADC_voidConfigureAutoTriggerSource(ADC_tuAutoTriggerSource);


/******************** Short-Cut API(s) *********************/


/*************************************************************
 * Description: Initialization of ADC module.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void ADC_voidInit(void);


#endif /* __ADC_H__ */