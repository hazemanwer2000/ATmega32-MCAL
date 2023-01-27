/*************************************************************
 * 
 * Filename: GLOBAL_INT.c
 * Description: Source file of the GLOBAL_INT driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "GLOBAL_INT_Cfg.h"
#include "GLOBAL_INT_Priv.h"
#include "GLOBAL_INT.h"

#include "Bit_Utils.h"
#include "IO_Map.h"



/*************************************************************
 * Description: Initialization of the Global Interrupt Enable bit.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void GLOBAL_INT_voidInit()
{
    #if GLOBAL_INT_INIT_STATE == GLOBAL_INT_STATE_ENABLED
        GLOBAL_INT_voidEnable();
    #else
        GLOBAL_INT_voidDisable();
    #endif
}



/*************************************************************
 * Description: Enable interrupts globally, setting 'GIE' to '1'.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void GLOBAL_INT_voidEnable() 
{
    SREG = SET_BIT(SREG, GIE);
}



/*************************************************************
 * Description: Disable interrupts globally, setting 'GIE' to '0'.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void GLOBAL_INT_voidDisable()
{
    SREG = CLR_BIT(SREG, GIE);
}
