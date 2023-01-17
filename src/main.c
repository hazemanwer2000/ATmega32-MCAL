
#define F_CPU		1000000UL

#include "DIO.h"
#include <util/delay.h>

int main(void) {
	
	DIO_enuInit();
	
	DIO_tenuPinState state;
	
    while (1) {
		
			// Input-2-Output
			
		DIO_enuGetPin(16, &state);
		if (state == DIO_enuHigh) {
			DIO_enuSetPin(11);
		} else {
			DIO_enuClearPin(11);
		}
		
			// On-Off Fun'
		
		DIO_enuSetPin(0);
		DIO_enuClearPin(5);
		
		_delay_ms(1000);
		
		DIO_enuSetPin(5);
		DIO_enuClearPin(0);
		
		_delay_ms(1000);
	};
}