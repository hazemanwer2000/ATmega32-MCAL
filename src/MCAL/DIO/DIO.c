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


/*************************************************************
 * Description: Initialization of the DIO module, using associated 
 *                  configuration file.
 * Parameters:
 *      [X]
 * Return:
 *      Error status.
 *************************************************************/
DIO_tenuErrorStatus DIO_enuInit(void) {
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
    
    return DIO_enuOK;
}