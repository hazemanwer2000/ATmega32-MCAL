/*************************************************************
 * 
 * Filename: DIO.c
 * Description: Source file of DIO module in ATmega32 uC.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include <avr/io.h>

#include "Std_Types.h"
#include "Bit_Utils.h"

#include "DIO.h"
#include "DIO_Cfg.h"
#include "DIO_Priv.h"


/*************************************************************
 * Description: Decode the bit number from the pin number. 
                    (e.g: 0-7 -> (0) 0-7, 8-15 -> (1) 0-7, etc)
 * Parameters:
 *      [1] Pin number (0-31).
        [2] Pointer, to return bit number (0-7) in.
 * Return:
 *      None.
 *************************************************************/
static void DIO_voidDecodeBitNumber(DIO_tuPinNumber Cpy_uPinNumber, u8 *Add_pu8BitNumber) {
    *Add_pu8BitNumber = Cpy_uPinNumber % 8;
}


/*************************************************************
 * Description: Decode the DDRx and PORTx from the pin number. 
                    (e.g: 0-7 -> DDRA, 8-15 -> DDRB, etc)
 * Parameters:
 *      [1] Pin number (0-31).
        [2] Pointer, to return the DDRx register in.
        [3] Pointer, to return the PORTx register in.
 * Return:
 *      None.
 *************************************************************/
static void DIO_voidDecodeRegisters(DIO_tuPinNumber Cpy_uPinNumber, volatile u8 **Add_ppu8RegDDR, 
                                        volatile u8 **Add_ppu8RegPORT, volatile u8 **Add_ppu8RegPIN) {
    switch (Cpy_uPinNumber / 8) {
        case 0:
            *Add_ppu8RegDDR = &DDRA;
            *Add_ppu8RegPORT = &PORTA;
            *Add_ppu8RegPIN = &PINA;
            break;
        case 1:
            *Add_ppu8RegDDR = &DDRB;
            *Add_ppu8RegPORT = &PORTB;
            *Add_ppu8RegPIN = &PINB;
            break;
        case 2:
            *Add_ppu8RegDDR = &DDRC;
            *Add_ppu8RegPORT = &PORTC;
            *Add_ppu8RegPIN = &PINC;
            break;
        case 3:
            *Add_ppu8RegDDR = &DDRD;
            *Add_ppu8RegPORT = &PORTD;
            *Add_ppu8RegPIN = &PIND;
            break;
    }
}


/*************************************************************
 * Description: Initialization of the DIO module, using associated 
 *                  configuration file.
 * Parameters:
 *      [X]
 * Return:
 *      Error status.
 *************************************************************/
DIO_tenuErrorStatus DIO_enuInit(void) {
    
        /* DDRX (Data Direction Register) */
    
    DDRA = MAKE_BYTE(
                        DIO_PIN7_DIR, 
                        DIO_PIN6_DIR, 
                        DIO_PIN5_DIR,
                        DIO_PIN4_DIR,
                        DIO_PIN3_DIR,
                        DIO_PIN2_DIR,
                        DIO_PIN1_DIR,
                        DIO_PIN0_DIR
    );
					
    DDRB = MAKE_BYTE(
                        DIO_PIN15_DIR, 
                        DIO_PIN14_DIR, 
                        DIO_PIN13_DIR,
                        DIO_PIN12_DIR,
                        DIO_PIN11_DIR,
                        DIO_PIN10_DIR,
                        DIO_PIN9_DIR,
                        DIO_PIN8_DIR
    );
                    
    DDRC = MAKE_BYTE(
                        DIO_PIN23_DIR, 
                        DIO_PIN22_DIR, 
                        DIO_PIN21_DIR,
                        DIO_PIN20_DIR,
                        DIO_PIN19_DIR,
                        DIO_PIN18_DIR,
                        DIO_PIN17_DIR,
                        DIO_PIN16_DIR
    );
                    
    DDRD = MAKE_BYTE(
                        DIO_PIN31_DIR, 
                        DIO_PIN30_DIR, 
                        DIO_PIN29_DIR,
                        DIO_PIN28_DIR,
                        DIO_PIN27_DIR,
                        DIO_PIN26_DIR,
                        DIO_PIN25_DIR,
                        DIO_PIN24_DIR
    );
                    
                    
        /* PORTX (Configuration Register) */

    PORTA = MAKE_BYTE(
                        DIO_PIN7_CFG, 
                        DIO_PIN6_CFG, 
                        DIO_PIN5_CFG,
                        DIO_PIN4_CFG,
                        DIO_PIN3_CFG,
                        DIO_PIN2_CFG,
                        DIO_PIN1_CFG,
                        DIO_PIN0_CFG
    );
					
    PORTB = MAKE_BYTE(
                        DIO_PIN15_CFG, 
                        DIO_PIN14_CFG, 
                        DIO_PIN13_CFG,
                        DIO_PIN12_CFG,
                        DIO_PIN11_CFG,
                        DIO_PIN10_CFG,
                        DIO_PIN9_CFG,
                        DIO_PIN8_CFG
    );
                    
    PORTC = MAKE_BYTE(
                        DIO_PIN23_CFG, 
                        DIO_PIN22_CFG, 
                        DIO_PIN21_CFG,
                        DIO_PIN20_CFG,
                        DIO_PIN19_CFG,
                        DIO_PIN18_CFG,
                        DIO_PIN17_CFG,
                        DIO_PIN16_CFG
    );
                    
    PORTD = MAKE_BYTE(
                        DIO_PIN31_CFG, 
                        DIO_PIN30_CFG, 
                        DIO_PIN29_CFG,
                        DIO_PIN28_CFG,
                        DIO_PIN27_CFG,
                        DIO_PIN26_CFG,
                        DIO_PIN25_CFG,
                        DIO_PIN24_CFG
    );
    
    return DIO_enuOk;
}


/*************************************************************
 * Description: Set an output pin in the DIO module.
 * Parameters:
 *      [1] Pin number (0-31). 
 * Return:
 *      Error status.
 *************************************************************/
DIO_tenuErrorStatus DIO_enuSetPin(DIO_tuPinNumber Cpy_uPinNumber) {
    u8 Loc_u8BitNumber;
    volatile u8 *Loc_pu8RegDDR, *Loc_pu8RegPORT, *Loc_pu8RegPIN;
    
    DIO_voidDecodeBitNumber(Cpy_uPinNumber, &Loc_u8BitNumber);
    DIO_voidDecodeRegisters(Cpy_uPinNumber, &Loc_pu8RegDDR, &Loc_pu8RegPORT, &Loc_pu8RegPIN);
    
    if (GET_BIT(*Loc_pu8RegDDR, Loc_u8BitNumber) == DIO_DIR_OUTPUT) {
        *Loc_pu8RegPORT = SET_BIT(*Loc_pu8RegPORT, Loc_u8BitNumber);
        return DIO_enuOk;
    } else {
        return DIO_enuNotOk;
    }
}


/*************************************************************
 * Description: Clear an output pin in the DIO module.
 * Parameters:
 *      [1] Pin number (0-31). 
 * Return:
 *      Error status.
 *************************************************************/
DIO_tenuErrorStatus DIO_enuClearPin(DIO_tuPinNumber Cpy_uPinNumber) {
    u8 Loc_u8BitNumber;
    volatile u8 *Loc_pu8RegDDR, *Loc_pu8RegPORT, *Loc_pu8RegPIN;
    
    DIO_voidDecodeBitNumber(Cpy_uPinNumber, &Loc_u8BitNumber);
    DIO_voidDecodeRegisters(Cpy_uPinNumber, &Loc_pu8RegDDR, &Loc_pu8RegPORT, &Loc_pu8RegPIN);
    
    if (GET_BIT(*Loc_pu8RegDDR, Loc_u8BitNumber) == DIO_DIR_OUTPUT) {
        *Loc_pu8RegPORT = CLR_BIT(*Loc_pu8RegPORT, Loc_u8BitNumber);
        return DIO_enuOk;
    } else {
        return DIO_enuNotOk;
    }
}


/*************************************************************
 * Description: Get the state of an input pin in the DIO module.
 * Parameters:
 *      [1] Pin number (0-31).
 *      [2] Pointer, to return the state of the input pin in.
 * Return:
 *      Error status.
 *************************************************************/
DIO_tenuErrorStatus DIO_enuGetPin(DIO_tuPinNumber Cpy_uPinNumber, DIO_tenuPinState *Add_enuPinState) {
    u8 Loc_u8BitNumber;
    volatile u8 *Loc_pu8RegDDR, *Loc_pu8RegPORT, *Loc_pu8RegPIN;
    
    DIO_voidDecodeBitNumber(Cpy_uPinNumber, &Loc_u8BitNumber);
    DIO_voidDecodeRegisters(Cpy_uPinNumber, &Loc_pu8RegDDR, &Loc_pu8RegPORT, &Loc_pu8RegPIN);
    
    if (GET_BIT(*Loc_pu8RegDDR, Loc_u8BitNumber) == DIO_DIR_INPUT) {
        *Add_enuPinState = GET_BIT(*Loc_pu8RegPIN, Loc_u8BitNumber);
        return DIO_enuOk;
    } else {
        return DIO_enuNotOk;
    }
}
