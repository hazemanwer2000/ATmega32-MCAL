/*************************************************************
 * 
 * Filename: Delay.c
 * Description: Source file of the delay utilities, MCAL-dependent.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "Std_Types.h"
#include "Delay.h"


/*************************************************************
 * Description: Magic constant, to increment an accumulator by,
 *                  until it reaches the required milliseconds.
 *
 *************************************************************/
#define DELAY_EPSILON               (0.275 / CLK_SPEED)


/*************************************************************
 * Description: Delay uProcessor execution by milli-seconds.
 * Parameters:
 *      [1] Milli-seconds.
 * Return:
 *      None.
 *************************************************************/
void delay_ms(double ms) {
    volatile double accum = 0;
    while (accum < ms) { accum += DELAY_EPSILON; }
}