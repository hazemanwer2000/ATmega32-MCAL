/*************************************************************
 * 
 * Filename: TIMER0.c
 * Description: Source file of the TIMER0 driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "TIMER0_Cfg.h"
#include "TIMER0_Priv.h"
#include "TIMER0_Types.h"
#include "TIMER0.h"
#include "IO_Map.h"
#include "Bit_Utils.h"

static void(*TIMER0_fOverflowCallback)(void) = NULL;
static void(*TIMER0_fOutputCompareMatchCallback)(void) = NULL;

void TIMER0_voidForceOutputCompare(void)
{
    TCCR0 |= (1 << FOC0);
}

void TIMER0_voidConfigureWaveformGenerationMode(TIMER0_tuCfg Cpy_uWaveformGenerationMode)
{
    TCCR0 = (TCCR0 & ~TIMER0_WaveformGenerationMode_MASK) | Cpy_uWaveformGenerationMode;
}

void TIMER0_voidConfigureCompareMatchOutputMode(TIMER0_tuCfg Cpy_uCompareMatchOutputMode) {
    TCCR0 = (TCCR0 & ~TIMER0_CompareOutputMatchMode_MASK) | Cpy_uCompareMatchOutputMode;
}

void TIMER0_voidConfigureClock(TIMER0_tuCfg Cpy_uClock)
{
    TCCR0 = (TCCR0 & ~TIMER0_Clock_MASK) | Cpy_uClock;
}

void TIMER0_voidSetTimerRegister(u8 Cpy_u8Value)
{
    TCNT0 = Cpy_u8Value;
}

u8 TIMER0_u8GetTimerRegister(void)
{
    return TCNT0;
}

void TIMER0_voidSetCompareMatchRegister(u8 Cpy_u8Value)
{
    OCR0 = Cpy_u8Value;
}

void TIMER0_voidEnableOverflowInterrupt(void)
{
    TIMSK |= (1 << TOIE0);
}

void TIMER0_voidDisableOverflowInterrupt(void)
{
    TIMSK &= ~(1 << TOIE0);
}

void TIMER0_voidEnableOutputCompareMatchInterrupt(void)
{
    TIMSK |= (1 << OCIE0);
}

void TIMER0_voidDisableOutputCompareMatchInterrupt(void)
{
    TIMSK &= ~(1 << OCIE0);
}

void TIMER0_voidSetOverflowCallback(void (*Cpy_fCallback)(void))
{
    TIMER0_fOverflowCallback = Cpy_fCallback;
}

void TIMER0_voidSetOutputCompareMatchCallback(void (*Cpy_fCallback)(void))
{
    TIMER0_fOutputCompareMatchCallback = Cpy_fCallback;
}

ISRx(VECT_TIMER0_OVF)
{
    if (TIMER0_fOverflowCallback != NULL) {
        TIMER0_fOverflowCallback();
    }
}

ISRx(VECT_TIMER0_COMP)
{
    if (TIMER0_fOutputCompareMatchCallback != NULL) {
        TIMER0_fOutputCompareMatchCallback();
    }
}

void TIMER0_voidInit(void) {
    TIMER0_voidConfigureWaveformGenerationMode(TIMER0_WaveformGenerationMode_Cfg);
    TIMER0_voidConfigureCompareMatchOutputMode(TIMER0_CompareMatchOutputMode_Cfg);
}