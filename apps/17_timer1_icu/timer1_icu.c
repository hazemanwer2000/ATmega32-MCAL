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

void onNewReading(u64 val) {
    LCD_enuWriteCommand(LCD_CMD_CLEAR_DISPLAY); 
    LCD_enuWriteNumber(val/10);
    LCD_enuWriteString(" cm");
}

void entry_point() {
    GLOBAL_INT_voidInit();

    DIO_voidInit();
    LCD_enuInit();
    ULTRASONIC_voidInit(onNewReading);

    ULTRASONIC_voidTrigger();

    while (1);
}