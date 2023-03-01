/*************************************************************
 * 
 * Filename: TIMER0_Priv.h
 * Description: Private header file of the TIMER0 driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __TIMER0_PRIV_H__
#define __TIMER0_PRIV_H__

#include "IO_Map.h"
#include "Bit_Utils.h"


/*************************************************************
 * Description: Different masks.
 * 
 *************************************************************/
#define TIMER0_WaveformGenerationMode_MASK                  (MSK_BIT(WGM01) | MSK_BIT(WGM00))
#define TIMER0_CompareOutputMatchMode_MASK                  (0b11 << COM00)
#define TIMER0_Clock_MASK                                   (0b111 << CS00)


#endif /* __TIMER0_PRIV_H__ */