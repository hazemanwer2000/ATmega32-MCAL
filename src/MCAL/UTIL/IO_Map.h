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


/*************************************************************
 * Description: The Timer registers, and associated bits.
 *
 *************************************************************/
#define TCCR0               (*(volatile u8 *) 0x53)
#define FOC0                7
#define WGM00               6
#define COM01               5
#define COM00               4
#define WGM01               3
#define CS02                2
#define CS01                1
#define CS00                0

#define TCNT0               (*(volatile u8 *) 0x52)

#define OCR0                (*(volatile u8 *) 0x5C)

#define TIMSK               (*(volatile u8 *) 0x59)
#define OCIE0               1
#define TOIE0               0

#define TIFR                (*(volatile u8 *) 0x58)
#define OCF0                1
#define TOV0                0


/*************************************************************
 * Description: ICU (Timer1) registers, and associated bits.
 *
 *************************************************************/
#define TCCR1A              (*(volatile u8 *) 0x4F)
#define COM1A1              7
#define COM1A0              6
#define COM1B1              5
#define COM1B0              4
#define FOC1A               3
#define FOC1B               2
#define WGM11               1
#define WGM10               0

#define TCCR1B              (*(volatile u8 *) 0x4E)
#define ICNC1               7
#define ICES1               6
#define WGM13               4
#define WGM12               3
#define CS12                2
#define CS11                1
#define CS10                0

#define TCNT1H              (*(volatile u8 *) 0x4D)
#define TCNT1L              (*(volatile u8 *) 0x4C)

#define OCR1AH              (*(volatile u8 *) 0x4B)
#define OCR1AL              (*(volatile u8 *) 0x4A)

#define OCR1BL              (*(volatile u8 *) 0x49)
#define OCR1BL              (*(volatile u8 *) 0x48)

#define ICR1H               (*(volatile u8 *) 0x47)
#define ICR1L               (*(volatile u8 *) 0x46)

// TIMSK
#define TICIE1              5
#define OCIE1A              4
#define OCIE1B              3
#define TOIE1               2

// TIFR
#define ICIF1               5
#define OCF1A               4
#define OCF1B               3
#define TOV1                2