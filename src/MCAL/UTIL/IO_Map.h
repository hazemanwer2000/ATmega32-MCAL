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
 * Description: Interrupt service routine macro-function.
 *
 *************************************************************/
#define ISRx__(ISR_NO) \
void __vector_##ISR_NO(void) __attribute__((signal)); \
void __vector_##ISR_NO(void)

#define ISRx(ISR_NO)                ISRx__(ISR_NO)


/*************************************************************
 * Description: Interrupt options.
 *
 *************************************************************/
#define VECT_RESET                    0
#define VECT_INT0                     1
#define VECT_INT1                     2
#define VECT_INT2                     3
#define VECT_TIMER2_COMP              4
#define VECT_TIMER2_OVF               5
#define VECT_TIMER1_CAPT              6
#define VECT_TIMER1_COMPA             7
#define VECT_TIMER1_COMPB             8
#define VECT_TIMER1_OVF               9
#define VECT_TIMER0_COMP              10
#define VECT_TIMER0_OVF               11
#define VECT_SPI_STC                  12
#define VECT_USART_RXC                13
#define VECT_USART_UDRE               14
#define VECT_USART_TXC                15
#define VECT_ADC                      16
#define VECT_EE_RDY                   17
#define VECT_ANA_COMP                 18
#define VECT_TWI                      19
#define VECT_SPM_RDY                  20


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



/*************************************************************
 * Description: The ADC registers, and associated bits.
 *
 *************************************************************/
#define ADMUX               (*(volatile u8 *) 0x27)
#define REFS1               7
#define REFS0               6
#define ADLAR               5
#define MUX4                4
#define MUX3                3
#define MUX2                2
#define MUX1                1
#define MUX0                0

#define ADCSRA              (*(volatile u8 *) 0x26)
#define ADEN                7
#define ADSC                6
#define ADATE               5
#define ADIF                4
#define ADIE                3
#define ADPS2               2
#define ADPS1               1
#define ADPS0               0

#define ADCH                (*(volatile u8 *) 0x25)

#define ADCL                (*(volatile u8 *) 0x24)


/*************************************************************
 * Description: Special function I/O register, and associated bits.
 *
 *************************************************************/
#define SFIOR               (*(volatile u8 *) 0x50)
#define ADTS2               7
#define ADTS1               6
#define ADTS0               5