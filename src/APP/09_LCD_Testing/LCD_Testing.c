/*************************************************************
 * 
 * Filename: LCD_Testing.c
 * Description: Application, LCD.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "DIO.h"
#include "LCD.h"

#include "Delay.h"

u8 LCD_heart[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000
};

u8 LCD_smile[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b10001,
    0b01110,
    0b00000,
    0b00000
};



/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 *  
 *************************************************************/
void LCD_Testing() {
    u8 i, j;

    DIO_voidInit();
    LCD_enuInit();

    LCD_enuStoreSpecialCharacter(LCD_SPECIAL_CHAR_0, LCD_smile);
    LCD_enuStoreSpecialCharacter(LCD_SPECIAL_CHAR_1, LCD_heart);
    LCD_enuGoToXY(0, 0);
    
    for (j = 0; j < 2; j++) {
        LCD_enuGoToXY(0, j);
        for (i = 0; i < 16; i++) {
            LCD_enuWriteData(j);    
            j = !j;
        }
    }

    while (1) {}
}