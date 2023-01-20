APP/03_counting_segments/counting_segments.o: \
 APP/03_counting_segments/counting_segments.c MCAL/UTIL/Std_Types.h \
 UTIL/Bit_Utils/Bit_Utils.h MCAL/DIO/DIO.h HAL/LED/LED.h \
 MCAL/UTIL/Delay/Delay.h
	avr-gcc -c -I./APP/00_flickering_leds -I./APP/01_more_less_leds -I./APP/02_seven_segments -I./APP/03_counting_segments -I./HAL/BUTTON -I./HAL/LED -I./MCAL/DIO -I./MCAL/UTIL -I./MCAL/UTIL/Delay -I./UTIL/Bit_Utils -w -std=gnu99 -mmcu=atmega32 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums APP/03_counting_segments/counting_segments.c -o APP/03_counting_segments/counting_segments.o