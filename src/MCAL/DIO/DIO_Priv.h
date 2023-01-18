/*************************************************************
 * 
 * Filename: DIO_Priv.h
 * Description: Private header (interface) file of DIO module in ATmega32 uC,
 *                  to be included within the module only.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __DIO_PRIV_H__
#define __DIO_PRIV_H__

#include "DIO.h"


/*************************************************************
 * Description: Maximum number of pins in the ATmega32 uController.
 *
 *************************************************************/
#define DIO_PIN_COUNT           32


/*************************************************************
 * Description: Number of bits in a port in the ATmega32 uController.
 *
 *************************************************************/
#define DIO_PORT_SIZE           8


/*************************************************************
 * Description: Decode the bit number from the pin number. 
                    (e.g: 0-7 -> (0) 0-7, 8-15 -> (1) 0-7, etc)
 * Parameters:
 *      [1] Pin number (0-31).
        [2] Pointer, to return bit number (0-7) in.
 * Return:
 *      None.
 *************************************************************/
static void DIO_voidDecodeBitNumber(DIO_tuPinNumber Cpy_uPinNumber, u8 *Add_pu8BitNumber);


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
                                        volatile u8 **Add_ppu8RegPORT, volatile u8 **Add_ppu8RegPIN);


#endif /* __DIO_PRIV_H__ */