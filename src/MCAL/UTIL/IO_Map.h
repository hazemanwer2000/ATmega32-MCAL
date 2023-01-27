/*************************************************************
 * 
 * Filename: IO_Map.h
 * Description: Macro definitions of the relevant I/O registers, in the
 *                  ATmega32 memory map.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "Std_Types.h"



/*************************************************************
 * Description: Macro-definitions of register addresses, in the DIO module.
 * 
 *************************************************************/
#define PORTA               (*(volatile u8 *) 0x3B)
#define DDRA                (*(&PORTA - 1))
#define PINA                (*(&PORTA - 2))

#define PORTB               (*(&PORTA - 3))
#define DDRB                (*(&DDRA - 3))
#define PINB                (*(&PINA - 3))

#define PORTC               (*(&PORTA - 6))
#define DDRC                (*(&DDRA - 6))
#define PINC                (*(&PINA - 6))

#define PORTD               (*(&PORTA - 9))
#define DDRD                (*(&DDRA - 9))
#define PIND                (*(&PINA - 9))



/*************************************************************
 * Description: The status register, and associated bits.
 *
 *************************************************************/
#define SREG                (*(volatile u8 *) 0x5F)
#define GIE                 7



/*************************************************************
 * Description: The uC control registers, and associated bits.
 *
 *************************************************************/
#define MCUCR               (*(volatile u8 *) 0x55)
#define ISC00               0
#define ISC01               1
#define ISC10               2
#define ISC11               3

#define MCUCSR              (*(volatile u8 *) 0x54)
#define ISC2                6

#define GICR                (*(volatile u8 *) 0x5B)
#define INT2                5
#define INT0                6
#define INT1                7