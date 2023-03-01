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
#include "BUTTON.h"

#include "Delay.h"



#define LCD_BUTTON_LEFT         16
#define LCD_BUTTON_RIGHT        17

#define LCD_SIZE_X              16

#define LCD_GAME_DELAY          200

#define LCD_SCORE_LX            2
#define LCD_SCORE_RX            (LCD_SIZE_X - LCD_SCORE_LX - 1)

#define LCD_SCORE_Y             0

#define LCD_STICK_C             '|'
#define LCD_BALL_C              'o'

#define LCD_BALL_RESET_X        8
#define LCD_BALL_RESET_Y        1

#define LCD_WINNING_SCORE       3



void LCD_writeQuick(u8 i, u8 j, u8 data);
void LCD_refresh();
void LCD_logic();



u8 score_l = 0;
u8 score_r = 0;

u8 ball_i = LCD_BALL_RESET_X;
u8 ball_j = LCD_BALL_RESET_Y;

s8 ball_dir = -1;

s8 stick_l = 0;
s8 stick_r = 0;

const char *gameResult = NULL;



void LCD_writeQuick(u8 i, u8 j, u8 data) {
    LCD_enuGoToXY(i, j);
    LCD_enuWriteData(data);
}

void LCD_refresh() {
    // LCD_enuWriteCommand(LCD_CMD_CLEAR_DISPLAY);
    LCD_writeQuick(LCD_SCORE_LX, LCD_SCORE_Y, score_l + '0');
    LCD_writeQuick(LCD_SCORE_RX, LCD_SCORE_Y, score_r + '0');
    LCD_writeQuick(ball_i, ball_j, LCD_BALL_C);
    LCD_writeQuick(0, stick_l, LCD_STICK_C);
    LCD_writeQuick(LCD_SIZE_X - 1, stick_r, LCD_STICK_C);
}

void LCD_clear() {
    LCD_writeQuick(ball_i, ball_j, ' ');
    LCD_writeQuick(0, stick_l, ' ');
    LCD_writeQuick(LCD_SIZE_X - 1, stick_r, ' ');
}

void LCD_logic() {
    BUTTON_tenuButtonState state;

    BUTTON_enuGetButtonState(LCD_BUTTON_LEFT, &state);
    stick_l = (state == BUTTON_enuButtonPressed ? 1 : 0);

    BUTTON_enuGetButtonState(LCD_BUTTON_RIGHT, &state);
    stick_r = (state == BUTTON_enuButtonPressed ? 1 : 0);

    ball_j = !ball_j;
    ball_i += ball_dir;

    if (ball_i == 0) {
        ball_dir = 1;
        if (ball_j != stick_l) {
            ball_i += 2;
        } else {
            ball_i = LCD_BALL_RESET_X;
            score_r++;
        }
    } else if (ball_i == (LCD_SIZE_X - 1)) {
        ball_dir = -1;
        if (ball_j != stick_r) {
            ball_i -= 2;
        } else {
            ball_i = LCD_BALL_RESET_X;
            score_l++;
        }
    }
}



/*************************************************************
 * Description: Entry point to the application.
 * Parameters:
 *      [X]
 *  
 *************************************************************/
void LCD_Ping_Pong() {
    DIO_voidInit();
    LCD_enuInit();

    LCD_enuWriteCommand(LCD_CMD_CURSOR_OFF);

        // Game Loop
    while (1) {
        LCD_refresh();
        delay_ms(LCD_GAME_DELAY);
        LCD_clear();

        LCD_logic();

        if (score_l == LCD_WINNING_SCORE) {
            gameResult = "Left-side won!";
            break;
        } else if (score_r == LCD_WINNING_SCORE) {
            gameResult = "Right-side won!";
            break;
        }
    }

    LCD_enuGoToXY(0, 0);
    LCD_enuWriteString(gameResult);

    while (1) {}
}