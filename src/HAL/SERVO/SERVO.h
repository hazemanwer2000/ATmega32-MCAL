/*************************************************************
 * 
 * Filename: SERVO.h
 * Description: Header (interface) file of the SERVO driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __SERVO_H__
#define __SERVO_H__

#include "SERVO_Cfg.h"
#include "SERVO_Types.h"
#include "Std_Types.h"


/*************************************************************
 * Description: Maximum angle.
 * 
 *************************************************************/
#define SERVO_ANGLE_MAX             180


/*************************************************************
 * Description: Error status.
 * 
 *************************************************************/
typedef enum {
    SERVO_enuOk,
    SERVO_enuOutOfRange
} SERVO_tenuErrorStatus;


/*************************************************************
 * Description: Initialize servo-motor (Timer0-based).
 * Parameters:
 *      [X] None.
 * Return:
 *      None.
 *************************************************************/
void SERVO_voidInit(void);


/*************************************************************
 * Description: Set angle.
 * Parameters:
 *      [1] Angle
 * Return:
 *      None.
 *************************************************************/
SERVO_tenuErrorStatus SERVO_enuSetAngle(u8 Cpy_u8Angle);


#endif /* __SERVO_H__ */