HAL/LED/LED.o: HAL/LED/LED.c MCAL/DIO/DIO.h MCAL/UTIL/Std_Types.h \
 HAL/LED/LED.h HAL/LED/LED_Cfg.h HAL/LED/LED_Priv.h
	avr-gcc -c -I./APP/01_flickering_leds -I./APP/02_more_less_leds -I./APP/03_segments_timer -I./APP/04_segments_counter -I./APP/05_button_led_interrupt -I./APP/06_keypad_testing -I./APP/07_ADC_potentiometer -I./APP/08_ADC_LM35 -I./APP/09_LCD_Testing -I./HAL/BUTTON -I./HAL/KEYPAD -I./HAL/LCD -I./HAL/LED -I./HAL/LM35 -I./HAL/SEVEN_SEGMENT -I./MCAL/ADC -I./MCAL/DIO -I./MCAL/EXT_INT -I./MCAL/GLOBAL_INT -I./MCAL/UTIL -I./MCAL/UTIL/Delay -I./UTIL -I./UTIL/Bit_Utils -w -std=gnu99 -mmcu=atmega32 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums HAL/LED/LED.c -o HAL/LED/LED.o