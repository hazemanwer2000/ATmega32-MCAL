/*************************************************************
 * 
 * Filename: EXT_INT.c
 * Description: Source file of the EXT_INT driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "EXT_INT_Cfg.h"
#include "EXT_INT_Priv.h"
#include "EXT_INT.h"


/*************************************************************
 * Description: Initialization of each external interrupt module.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void EXT_INT_voidInit(void) {
    MCUCR = REPLACE_FIELD(MCUCR, ISC11, ISC00, BIN_CONCAT(EXT_INT_INT1_CFG, EXT_INT_INT0_CFG));
    MCUCSR = REPLACE_BIT(MCUCSR, ISC2, (1 & EXT_INT_INT2_CFG));
    GICR = REPLACE_FIELD(GICR, INT2, INT0, MAKE_NIBBLE(0, EXT_INT_INT1_STATE, EXT_INT_INT0_STATE, EXT_INT_INT2_STATE));
}