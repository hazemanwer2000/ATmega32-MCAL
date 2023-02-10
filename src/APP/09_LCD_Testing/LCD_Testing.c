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


/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 *  
 *************************************************************/
void LCD_Testing() {
    DIO_voidInit();
    LCD_enuInit();
    
    while (1) {}
}