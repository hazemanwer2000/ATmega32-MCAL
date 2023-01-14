/*************************************************************
 * 
 * Filename: DIO.h
 * Description: Header (interface) file of DIO module in ATmega32 uC.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __DIO_H__
#define __DIO_H__

#include "Std_Types.h"


/*************************************************************
 * Description: Error status, return by various functions.
 * 
 *************************************************************/
typedef enum {
    DIO_enuOk = 0,
    DIO_enuNotOk,
    DIO_enuNullPtr
} DIO_tenuErrorStatus;


/*************************************************************
 * Description: State of input and output pins.
 * 
 *************************************************************/
typedef enum {
    DIO_enuLow = 0,
    DIO_enuHigh = 1
} DIO_tenuPinState;


/*************************************************************
 * Description: Type of integer to hold pin number.
 * 
 *************************************************************/
typedef u8 DIO_tuPinNumber;


/*************************************************************
 * Description: Initialization of the DIO module, using associated 
 *                  configuration file.
 * Parameters:
 *      [X]
 * Return:
 *      Error status.
 *************************************************************/
DIO_tenuErrorStatus DIO_enuInit(void);


/*************************************************************
 * Description: Set the state of the output pin in the DIO module.
 * Parameters:
 *      [1] Pin number (0-31). 
 * Return:
 *      Error status.
 *************************************************************/
DIO_tenuErrorStatus DIO_enuSetPin(DIO_tuPinNumber Cpy_uPinNumber);


/*************************************************************
 * Description: Get the state of an input pin in the DIO module.
 * Parameters:
 *      [1] Pin number (0-31).
 *      [2] Pointer, to return the state of the input pin in.
 * Return:
 *      Error status.
 *************************************************************/
DIO_tenuErrorStatus DIO_enuGetPin(DIO_tuPinNumber Cpy_uPinNumber, DIO_tenuPinState *Add_enuPinState);


#endif /* __DIO_H__ */