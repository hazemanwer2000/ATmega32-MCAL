/*************************************************************
 * 
 * Filename: SERVO_Priv.h
 * Description: Private header file of the SERVO driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __SERVO_PRIV_H__
#define __SERVO_PRIV_H__


/*************************************************************
 * Description: Compare-match TIMER0 Register values.
 * 
 *************************************************************/
#define SERVO_CMP_MIN             12
#define SERVO_CMP_MAX             31
#define SERVO_CMP_RANGE           (SERVO_CMP_MAX - SERVO_CMP_MIN)


#endif /* __SERVO_PRIV_H__ */