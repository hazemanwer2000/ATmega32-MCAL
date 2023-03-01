/*************************************************************
 * 
 * Filename: LCD_Arabic.c
 * Description: Application, LCD.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "DIO.h"
#include "LCD.h"
#include "BUTTON.h"

#include "Delay.h"

#define LCD_WORD_LENGTH         4
#define LCD_MOVE_DELAY          50

#define LCD_LIMIT_X             (16 - LCD_WORD_LENGTH - 1)
#define LCD_LIMIT_Y             1

void LCD_update();

void LCD_moveUp(void);
void LCD_moveDown(void);
void LCD_moveLeft(void);
void LCD_moveRight(void);

u8 LCD_Arabic_H[8] = {
    0B00000,
    0B00000,
    0B00000,
    0B01100,
    0B10010,
    0B00001,
    0B11111,
    0B00000
};

u8 LCD_Arabic_A[8] = {
    0B00000,
    0B10000,
    0B10000,
    0B10000,
    0B10000,
    0B10000,
    0B01111,
    0B00000
};

u8 LCD_Arabic_Z[8] = {
    0B00000,
    0B00000,
    0B00010,
    0B00000,
    0B00010,
    0B00010,
    0B00100,
    0B11000
};

u8 LCD_Arabic_M[8] = {
    0B00000,
    0B00000,
    0B00000,
    0B00111,
    0B00101,
    0B11111,
    0B10000,
    0B10000
};

int LCD_i = 0;
int LCD_j = 0;

int pins[] = {16, 17, 18, 19};
void (*fcns[])() = {&LCD_moveUp, &LCD_moveDown, &LCD_moveLeft, &LCD_moveRight};

void LCD_update() {
    int i;

    LCD_enuGoToXY(LCD_i, LCD_j);
    
    for (i = 0; i < 4; i++) {
        LCD_enuWriteData(i);
    }
}

void LCD_moveUp(void) {
    if (LCD_j > 0) { LCD_j--; }
}

void LCD_moveDown(void) {
    if (LCD_j < LCD_LIMIT_Y) { LCD_j++; }
}

void LCD_moveLeft(void) {
    if (LCD_i > 0) { LCD_i--; }
}

void LCD_moveRight(void) {
    if (LCD_i < LCD_LIMIT_X) { LCD_i++; }
}

/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 *  
 *************************************************************/
void LCD_Arabic() {
    BUTTON_tenuButtonState state;
    int i;

    DIO_voidInit();
    LCD_enuInit();

    LCD_enuWriteCommand(LCD_CMD_CURSOR_OFF);

    LCD_enuStoreSpecialCharacter(LCD_SPECIAL_CHAR_0, LCD_Arabic_M);
    LCD_enuStoreSpecialCharacter(LCD_SPECIAL_CHAR_1, LCD_Arabic_Z);
    LCD_enuStoreSpecialCharacter(LCD_SPECIAL_CHAR_2, LCD_Arabic_A);
    LCD_enuStoreSpecialCharacter(LCD_SPECIAL_CHAR_3, LCD_Arabic_H);

    LCD_update();

    while (1) {
        for (i = 0; i < LCD_WORD_LENGTH; i++) {
            BUTTON_enuGetButtonState(pins[i], &state);
            if (state == BUTTON_enuButtonPressed) {
                fcns[i]();
                break;
            }
        }

        LCD_enuWriteCommand(LCD_CMD_CLEAR_DISPLAY);
        LCD_update();
        delay_ms(LCD_MOVE_DELAY);
    }
}