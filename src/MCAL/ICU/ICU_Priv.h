/*************************************************************
 * 
 * Filename: ICU_Priv.h
 * Description: Private header file of the ICU driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __ICU_PRIV_H__
#define __ICU_PRIV_H__

#include "Std_Types.h"


/*************************************************************
 * Description: Prescale setting of TIMER1 (e.g: 1).
 * 
 *************************************************************/
#define ICU_ClockPrescale_1                0b001


/*************************************************************
 * Description: Edge options.
 * 
 *************************************************************/
#define ICU_Edge_Rising                     1
#define ICU_Edge_Falling                    0


/*************************************************************
 * Description: ICU Clock (Mhz)
 * 
 *************************************************************/
#define ICU_CLK                             1


/*************************************************************
 * Description: Read ICR register (TIMER1).
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
static void ICU_voidReadICR(u16 *Add_u16Reg);


/*************************************************************
 * Description: Configure clock prescale (TIMER1).
 * Parameters:
 *      [1] Clock prescale option.
 * Return:
 *      None.
 *************************************************************/
static void ICU_voidConfigureClockPrescale(u8 Cpy_u8ClockPrescale);


/*************************************************************
 * Description: Select trigger edge.
 * Parameters:
 *      [1] Edge option.
 * Return:
 *      None.
 *************************************************************/
static void ICU_voidSelectEdge(u8 Cpy_u8Edge);


/*************************************************************
 * Description: Enable 'Overflow' (TIMER1) Interrupt.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
static void ICU_voidOverflowInterruptEnable(void);


/*************************************************************
 * Description: Enable 'InputCapture' (TIMER1) Interrupt.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
static void ICU_voidInputCaptureInterruptEnable(void);


#endif /* __ICU_PRIV_H__ */