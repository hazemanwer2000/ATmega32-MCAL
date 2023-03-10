/*************************************************************
 * 
 * Filename: SERVO.c
 * Description: Source file of the SERVO driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "SERVO_Cfg.h"
#include "SERVO_Priv.h"
#include "SERVO_Types.h"
#include "SERVO.h"
#include "TIMER0.h"


/*************************************************************
 * Description: Initialize servo-motor (Timer0-based).
 * Parameters:
 *      [X] None.
 * Return:
 *      None.
 *************************************************************/
void SERVO_voidInit(void) {
    TIMER0_voidConfigureWaveformGenerationMode(TIMER0_WaveformGenerationMode_FastPWM);
    TIMER0_voidConfigureCompareMatchOutputMode(TIMER0_CompareMatchOutputMode_Clear);
    TIMER0_voidSetCompareMatchRegister(SERVO_CMP_MIN);
    TIMER0_voidConfigureClock(TIMER0_Clock_Prescale_64);
}


/*************************************************************
 * Description: Set angle.
 * Parameters:
 *      [1] Angle (-90 to 90)
 * Return:
 *      None.
 *************************************************************/
SERVO_tenuErrorStatus SERVO_enuSetAngle(u8 Cpy_u8Angle) {
    SERVO_tenuErrorStatus Loc_enuErrorStatus = SERVO_enuOk;

    if (Cpy_u8Angle > SERVO_ANGLE_MAX) {
        Loc_enuErrorStatus = SERVO_enuOutOfRange;
    } else {
        TIMER0_voidSetCompareMatchRegister((u8) (
            ((double) Cpy_u8Angle / SERVO_ANGLE_MAX) * SERVO_CMP_RANGE + SERVO_CMP_MIN
        ));
    }

    return Loc_enuErrorStatus;
}