/*************************************************************
 * 
 * Filename: LCD_Ping_Pong.c
 * Description: Application, LCD.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "Std_Types.h"
#include "DIO.h"
#include "LCD.h"
#include "ULTRASONIC.h"
#include "GLOBAL_INT.h"
#include "Delay.h"

u8 flag = 0;

void onNewReading(u64 val) {
    LCD_enuWriteCommand(LCD_CMD_CLEAR_DISPLAY); 
    LCD_enuWriteNumber(val/10);
    LCD_enuWriteString(" cm");

    flag = 1;
}

void entry_point() {
    GLOBAL_INT_voidInit();

    DIO_voidInit();
    LCD_enuInit();
    ULTRASONIC_voidInit(onNewReading);

    ULTRASONIC_voidTrigger();

    while (1) {
        if (flag == 1) {
            flag = 0;
            ULTRASONIC_voidTrigger();
        }
    };
}