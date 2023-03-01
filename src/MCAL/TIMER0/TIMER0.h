/*************************************************************
 * 
 * Filename: TIMER0.h
 * Description: Header (interface) file of the TIMER0 driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __TIMER0_H__
#define __TIMER0_H__

#include "TIMER0_Cfg.h"
#include "TIMER0_Types.h"
#include "Std_Types.h"
#include "IO_Map.h"
#include "Bit_Utils.h"


/*************************************************************
 * Description: Waverform Generation Mode options.
 * 
 *************************************************************/
#define TIMER0_WaveformGenerationMode_Normal                        (BIT(0, WGM01) | BIT(0, WGM00))
#define TIMER0_WaveformGenerationMode_PWMPhaseCorrect               (BIT(0, WGM01) | BIT(1, WGM00))
#define TIMER0_WaveformGenerationMode_CTC                           (BIT(1, WGM01) | BIT(0, WGM00))
#define TIMER0_WaveformGenerationMode_FastPWM                       (BIT(1, WGM01) | BIT(1, WGM00))


/*************************************************************
 * Description: Compare Match Output Mode options.
 * 
 *************************************************************/
#define TIMER0_CompareMatchOutputMode_Disconnected                  (0 << COM00)
#define TIMER0_CompareMatchOutputMode_Toggle                        (1 << COM00)
#define TIMER0_CompareMatchOutputMode_Clear                         (2 << COM00)
#define TIMER0_CompareMatchOutputMode_Set                           (3 << COM00)


/*************************************************************
 * Description: Clock options.
 * 
 *************************************************************/
#define TIMER0_Clock_Disconnected                                   (0 << CS00)
#define TIMER0_Clock_Prescale_1                                     (1 << CS00)
#define TIMER0_Clock_Prescale_8                                     (2 << CS00)
#define TIMER0_Clock_Prescale_64                                    (3 << CS00)
#define TIMER0_Clock_Prescale_256                                   (4 << CS00)
#define TIMER0_Clock_Prescale_1024                                  (5 << CS00)
#define TIMER0_Clock_External_Falling                               (6 << CS00)
#define TIMER0_Clock_External_Rising                                (7 << CS00)


/*************************************************************
 * Description: (Constant) Maximum value timer register can withstand.
 * 
 *************************************************************/
#define TIMER0_TimerRegister_Max                                    255


/*************************************************************
 * Description: Force output compare (OC0 pin), based on Compare-Match-Output Mode.
 *                  Note: Valid only in CTC mode.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void TIMER0_voidForceOutputCompare(void);


/*************************************************************
 * Description: Configure waverform generation mode.
 * Parameters:
 *      [1] Waveform generation mode option.
 * Return:
 *      None.
 *************************************************************/
void TIMER0_voidConfigureWaveformGenerationMode(TIMER0_tuCfg Cpy_uWaveformGenerationMode);


/*************************************************************
 * Description: Configure compare match output mode.
 * Parameters:
 *      [1] Compare match output mode option.
 * Return:
 *      None.
 *************************************************************/
void TIMER0_voidConfigureCompareMatchOutputMode(TIMER0_tuCfg Cpy_uCompareMatchOutputMode);


/*************************************************************
 * Description: Configure timer clock.
 * Parameters:
 *      [1] Clock option.
 * Return:
 *      None.
 *************************************************************/
void TIMER0_voidConfigureClock(TIMER0_tuCfg Cpy_uClock);


/*************************************************************
 * Description: Set value of timer register.
 * Parameters:
 *      [1] Value.
 * Return:
 *      None.
 *************************************************************/
void TIMER0_voidSetTimerRegister(u8 Cpy_u8Value);


/*************************************************************
 * Description: Get value of timer register.
 * Parameters:
 *      [X]
 * Return:
 *      Value.
 *************************************************************/
u8 TIMER0_u8GetTimerRegister(void);


/*************************************************************
 * Description: Set compare match register.
 * Parameters:
 *      [1] Value.
 * Return:
 *      None.
 *************************************************************/
void TIMER0_voidSetCompareMatchRegister(u8 Cpy_u8Value);


/*************************************************************
 * Description: Enable/Disable overflow interrupt.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void TIMER0_voidEnableOverflowInterrupt(void);
void TIMER0_voidDisableOverflowInterrupt(void);


/*************************************************************
 * Description: Enable/Disable compare match interrupt.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void TIMER0_voidEnableOutputCompareMatchInterrupt(void);
void TIMER0_voidDisableOutputCompareMatchInterrupt(void);


/*************************************************************
 * Description: Set overflow/compare-match callback function.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void TIMER0_voidSetOverflowCallback(void (*Cpy_fCallback)(void));
void TIMER0_voidSetOutputCompareMatchCallback(void (*Cpy_fCallback)(void));


/*************************************************************
 * Description: Initialize timer based on configuration.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void TIMER0_voidInit(void);


#endif /* __TIMER0_H__ */