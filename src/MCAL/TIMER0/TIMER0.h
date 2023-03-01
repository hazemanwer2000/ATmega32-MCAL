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

#define TIMER0_WaveformGenerationMode_Normal                        (BIT(0, WGM01) | BIT(0, WGM00))
#define TIMER0_WaveformGenerationMode_PWMPhaseCorrect               (BIT(0, WGM01) | BIT(1, WGM00))
#define TIMER0_WaveformGenerationMode_CTC                           (BIT(1, WGM01) | BIT(0, WGM00))
#define TIMER0_WaveformGenerationMode_FastPWM                       (BIT(1, WGM01) | BIT(1, WGM00))

#define TIMER0_CompareMatchOutputMode_Disconnected                  (0 << COM00)
#define TIMER0_CompareMatchOutputMode_Toggle                        (1 << COM00)
#define TIMER0_CompareMatchOutputMode_Clear                         (2 << COM00)
#define TIMER0_CompareMatchOutputMode_Set                           (3 << COM00)

#define TIMER0_Clock_Disconnected                                   (0 << CS00)
#define TIMER0_Clock_Prescale_1                                     (1 << CS00)
#define TIMER0_Clock_Prescale_8                                     (2 << CS00)
#define TIMER0_Clock_Prescale_64                                    (3 << CS00)
#define TIMER0_Clock_Prescale_256                                   (4 << CS00)
#define TIMER0_Clock_Prescale_1024                                  (5 << CS00)
#define TIMER0_Clock_External_Falling                               (6 << CS00)
#define TIMER0_Clock_External_Rising                                (7 << CS00)

#define TIMER0_TimerRegister_Max                                    255

void TIMER0_voidForceOutputCompare(void);

void TIMER0_voidConfigureWaveformGenerationMode(TIMER0_tuCfg Cpy_uWaveformGenerationMode);

void TIMER0_voidConfigureCompareMatchOutputMode(TIMER0_tuCfg Cpy_uCompareMatchOutputMode);

void TIMER0_voidConfigureClock(TIMER0_tuCfg Cpy_uClock);

void TIMER0_voidSetTimerRegister(u8 Cpy_u8Value);
u8 TIMER0_u8GetTimerRegister(void);

void TIMER0_voidSetCompareMatchRegister(u8 Cpy_u8Value);

void TIMER0_voidEnableOverflowInterrupt(void);
void TIMER0_voidDisableOverflowInterrupt(void);

void TIMER0_voidEnableOutputCompareMatchInterrupt(void);
void TIMER0_voidDisableOutputCompareMatchInterrupt(void);

void TIMER0_voidSetOverflowCallback(void (*Cpy_fCallback)(void));
void TIMER0_voidSetOutputCompareMatchCallback(void (*Cpy_fCallback)(void));

void TIMER0_voidInit(void);

#endif /* __TIMER0_H__ */