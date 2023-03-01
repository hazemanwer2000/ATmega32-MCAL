/*************************************************************
 * 
 * Filename: segments_counter.c
 * Description: Application, displaying numbers on the seven segment display,
 *                  incrementing and decrementing using push-buttons.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "Std_Types.h"
#include "Bit_Utils.h"

#include "DIO.h"
#include "LED.h"
#include "Button.h"
#include "SEVEN_SEGMENT.h"
#include "SEVEN_SEGMENT_Cfg.h"

#include "Delay.h"


/*************************************************************
 * Description: Pin number of the incrementing / decrementing buttons.
 * 
 *************************************************************/
#define BUTTON_INC          16
#define BUTTON_DEC          17


/*************************************************************
 * Description: Maximum/Minimum number to display.
 * 
 *************************************************************/
#define MAX_NUMBER          99
#define MIN_NUMBER          0


/*************************************************************
 * Description: Set new number (2-digits).
 * Parameters:
 *      [X]
 * 
 *************************************************************/
void set(int i) {/*
    SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplayLeastSignificant, i % 10);
    SEVEN_SEGMENT_enuSetNumber(SEVEN_SEGMENT_enuDisplayMostSignificant, i / 10);
*/}


/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 * 
 *************************************************************/
void segments_counter() {/*
    s8 cnt = 0;
    BUTTON_tenuButtonState stateInc, stateDec;

    DIO_voidInit();
    LED_enuInit();
    SEVEN_SEGMENT_enuInit();

    while (1) {
        while (1)  {
            BUTTON_enuGetButtonState(BUTTON_INC, &stateInc);
            BUTTON_enuGetButtonState(BUTTON_DEC, &stateDec);
            if (stateInc == BUTTON_enuButtonReleased && stateDec == BUTTON_enuButtonReleased) {
                break;
            }
        }

        while (1)  {
            BUTTON_enuGetButtonState(BUTTON_INC, &stateInc);
            BUTTON_enuGetButtonState(BUTTON_DEC, &stateDec);
            if (stateInc == BUTTON_enuButtonPressed) {
                if (cnt < MAX_NUMBER) {
                    set(++cnt);
                }
                break;
            } else if (stateDec == BUTTON_enuButtonPressed) {
                if (cnt >= MIN_NUMBER) {
                    set(cnt--);
                }
                break;
            }
        }
    }
*/}