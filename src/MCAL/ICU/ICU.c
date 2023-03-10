/*************************************************************
 * 
 * Filename: ICU.c
 * Description: Source file of the ICU driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "ICU_Cfg.h"
#include "ICU_Priv.h"
#include "ICU_Types.h"
#include "ICU.h"
#include "IO_Map.h"
#include "Bit_Utils.h"
#include "Std_Types.h"


/*************************************************************
 * Description: Several run-time variables.
 * 
 *************************************************************/
static u64 overflowCount = 0;
static u16 startValue = 0, endValue = 0;
static u8 isMeasuring = 0;
static void (*callback)(u64) = NULL;


/*************************************************************
 * Description: TIMER1 Overflow Interrupt Vector.
 * 
 *************************************************************/
ISRx(VECT_TIMER1_OVF) {
    overflowCount++;
}


/*************************************************************
 * Description: TIMER1 Input Capture Interrupt Vector.
 * 
 *************************************************************/
ISRx(VECT_TIMER1_CAPT) {
    if (isMeasuring == 0) {
        overflowCount = 0;
        
        ICU_voidReadICR(&startValue);
        isMeasuring = 1;
        ICU_voidSelectEdge(ICU_Edge_Falling);
    } else {
        ICU_voidReadICR(&endValue);
        isMeasuring = 0;
        ICU_voidSelectEdge(ICU_Edge_Rising);

        callback(((overflowCount * 65536 + endValue) - startValue));
    }
}


/*************************************************************
 * Description: Read ICR register (TIMER1).
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
static void ICU_voidReadICR(u16 *Add_u16Reg) {
    *Add_u16Reg = ICR1L;
    *Add_u16Reg |= ICR1H << 8; 
}


/*************************************************************
 * Description: Configure clock prescale (TIMER1).
 * Parameters:
 *      [1] Clock prescale option.
 * Return:
 *      None.
 *************************************************************/
static void ICU_voidConfigureClockPrescale(u8 Cpy_u8ClockPrescale) {
    TCCR1B = REPLACE_FIELD(TCCR1B, CS10, CS12, Cpy_u8ClockPrescale);
}


/*************************************************************
 * Description: Select trigger edge.
 * Parameters:
 *      [1] Edge option.
 * Return:
 *      None.
 *************************************************************/
static void ICU_voidSelectEdge(u8 Cpy_u8Edge) {
    TCCR1B = REPLACE_BIT(TCCR1B, ICES1, Cpy_u8Edge);
}


/*************************************************************
 * Description: Enable 'Overflow' (TIMER1) Interrupt.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
static void ICU_voidOverflowInterruptEnable(void) {
    TIMSK |= (1 << TOIE1);
}


/*************************************************************
 * Description: Enable 'InputCapture' (TIMER1) Interrupt.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
static void ICU_voidInputCaptureInterruptEnable(void) {
    TIMSK |= (1 << TICIE1);
}


/*************************************************************
 * Description: Initialize ICU (Timer1).
 * Parameters:
 *      [1] Callback function.
 * Return:
 *      None.
 *************************************************************/
void ICU_voidInit(void (*fptr)(u64)) {
    ICU_voidOverflowInterruptEnable();
    ICU_voidInputCaptureInterruptEnable();
    ICU_voidSelectEdge(ICU_Edge_Rising);
    ICU_voidConfigureClockPrescale(ICU_ClockPrescale_1);
    callback = fptr;
}