/*************************************************************
 * 
 * Filename: ULTRASONIC.c
 * Description: Source file of the ULTRASONIC driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "ULTRASONIC_Cfg.h"
#include "ULTRASONIC_Priv.h"
#include "ULTRASONIC_Types.h"
#include "ULTRASONIC.h"
#include "ICU.h"
#include "DIO.h"
#include "Std_Types.h"

static void (*callback)(u64) = NULL;

static ULTRASONIC_voidCallback(u64 Cpy_u64US) {
    callback((Cpy_u64US * 5) / 29);
}

void ULTRASONIC_voidInit(void (*fptr)(u64)) {
    ICU_voidInit(ULTRASONIC_voidCallback);
    callback = fptr;
}

void ULTRASONIC_voidTrigger(void) {
    u8 i = 0;
    DIO_enuSetPin(ULTRASONIC_TRIG_PIN);
    while (++i < ULTRASONIC_SPECIAL_VALUE);
    DIO_enuClearPin(ULTRASONIC_TRIG_PIN);
}