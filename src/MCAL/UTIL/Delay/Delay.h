/*************************************************************
 * 
 * Filename: Delay.h
 * Description: Header file of the delay utilities, MCAL-dependent.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __DELAY_H__
#define __DELAY_H__

#include "Std_Types.h"


/*************************************************************
 * Description: The speed of the uController, in MHz.
 * 
 *************************************************************/
#define CLK_SPEED               1.0


/*************************************************************
 * Description: Delay uProcessor execution by milli-seconds.
 * Parameters:
 *      [1] Milli-seconds.
 * Return:
 *      None.
 *************************************************************/
void delay_ms(double ms);


#endif /* __BIT_UTILS_H__ */