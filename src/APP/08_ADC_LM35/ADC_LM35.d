APP/08_ADC_LM35/ADC_LM35.o: APP/08_ADC_LM35/ADC_LM35.c \
 MCAL/UTIL/Std_Types.h UTIL/Bit_Utils/Bit_Utils.h MCAL/DIO/DIO.h \
 HAL/LED/LED.h HAL/SEVEN_SEGMENT/SEVEN_SEGMENT.h \
 HAL/SEVEN_SEGMENT/SEVEN_SEGMENT_Cfg.h \
 HAL/SEVEN_SEGMENT/SEVEN_SEGMENT_Priv.h \
 HAL/SEVEN_SEGMENT/SEVEN_SEGMENT_Cfg.h MCAL/GLOBAL_INT/GLOBAL_INT.h \
 MCAL/ADC/ADC.h MCAL/UTIL/IO_Map.h MCAL/UTIL/Std_Types.h HAL/LM35/LM35.h \
 HAL/LM35/LM35_Cfg.h
	avr-gcc -c -I./APP/01_flickering_leds -I./APP/02_more_less_leds -I./APP/03_segments_timer -I./APP/04_segments_counter -I./APP/05_button_led_interrupt -I./APP/06_keypad_testing -I./APP/07_ADC_potentiometer -I./APP/08_ADC_LM35 -I./APP/09_LCD_Testing -I./HAL/BUTTON -I./HAL/KEYPAD -I./HAL/LCD -I./HAL/LED -I./HAL/LM35 -I./HAL/SEVEN_SEGMENT -I./MCAL/ADC -I./MCAL/DIO -I./MCAL/EXT_INT -I./MCAL/GLOBAL_INT -I./MCAL/UTIL -I./MCAL/UTIL/Delay -I./UTIL -I./UTIL/Bit_Utils -w -std=gnu99 -mmcu=atmega32 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums APP/08_ADC_LM35/ADC_LM35.c -o APP/08_ADC_LM35/ADC_LM35.o