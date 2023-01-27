/*************************************************************
 * 
 * Filename: GLOBAL_INT.h
 * Description: Header (interface) file of the GLOBAL_INT driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __GLOBAL_INT_H__
#define __GLOBAL_INT_H__



/*************************************************************
 * Description: Initialization of the Global Interrupt Enable bit.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void GLOBAL_INT_voidInit();



/*************************************************************
 * Description: Enable interrupts globally, setting 'GIE' to '1'.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void GLOBAL_INT_voidEnable();



/*************************************************************
 * Description: Disable interrupts globally, setting 'GIE' to '0'.
 * Parameters:
 *      [X]
 * Return:
 *      None.
 *************************************************************/
void GLOBAL_INT_voidDisable();



#endif /* __GLOBAL_INT_H__ */