/*************************************************************
 * 
 * Filename: segments_timer.c
 * Description: Application, displaying numbers on the seven segment display,
 *                              delaying and incrementing/decrementing.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "Std_Types.h"
#include "Bit_Utils.h"

#include "DIO.h"
#include "LED.h"
#include "SEVEN_SEGMENT.h"
#include "SEVEN_SEGMENT_Cfg.h"

#include "Delay.h"


/*************************************************************
 * Description: The transition's delay, in milliseconds.
 * 
 *************************************************************/
#define DELAY_MS            1000


/*************************************************************
 * Description: Maximum/Minimum number to display.
 * 
 *************************************************************/
#define MAX_NUMBER          99
#define MIN_NUMBER          0


/*************************************************************
 * Description: Hold for some delay, and then set new number (2-digits).
 * Parameters:
 *      [X]
 * 
 *************************************************************/
void hold_set(int i) {
    delay_ms(DELAY_MS);
    SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplayLeastSignificant, i % 10);
    SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplayMostSignificant, i / 10);
}


/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 * 
 *************************************************************/
void segments_timer() {
    s8 i = 0;

    DIO_voidInit();
    LED_enuInit();
    SEVEN_SEGMENT_enuInit();

    while (1) {
        for (i = MIN_NUMBER + 1; i <= MAX_NUMBER; i++)
            hold_set(i);
        
        for (i = MAX_NUMBER - 1; i >= MIN_NUMBER; i--)
            hold_set(i);
    }
}