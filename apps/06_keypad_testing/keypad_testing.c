/*************************************************************
 * 
 * Filename: keypad_testing.h
 * Description: Application, testing of keypad.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "Std_Types.h"

#include "DIO.h"
#include "LED.h"
#include "KEYPAD.h"
#include "KEYPAD_Cfg.h"

#include "Delay.h"


/*************************************************************
 * Description: Maximum number of LEDs.
 * 
 *************************************************************/
#define LED_COUNT           9


/*************************************************************
 * Description: Map enum keys to values (non-numeric yield '0')
 * 
 *************************************************************/
u8 keypad_testing_map(KEYPAD_tenuKey key) {
    u8 num = 0;

    switch (key) 
    {
        case KEYPAD_enuKey1: num = 1; break;
        case KEYPAD_enuKey2: num = 2; break;
        case KEYPAD_enuKey3: num = 3; break;
        case KEYPAD_enuKey4: num = 4; break;
        case KEYPAD_enuKey5: num = 5; break;
        case KEYPAD_enuKey6: num = 6; break;
        case KEYPAD_enuKey7: num = 7; break;
        case KEYPAD_enuKey8: num = 8; break;
        case KEYPAD_enuKey9: num = 9; break;
    }

    return num;
}


/*************************************************************
 * Description: Turn on/off LEDs, based on count.
 * 
 *************************************************************/
void keypad_testing_led(u8 count)
{
    u8 i = 0;

    for (; i < count; i++)
    {
        LED_enuLedOn(i);
    }

    for (; i < LED_COUNT; i++)
    {
        LED_enuLedOff(i);
    }
}


/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 * 
 *************************************************************/
void keypad_testing() {
    KEYPAD_tenuKey key;

    DIO_voidInit();
    LED_enuInit();

    while (1) {
        KEYPAD_enuGetKey(&key);
        keypad_testing_led(keypad_testing_map(key));
    }
}