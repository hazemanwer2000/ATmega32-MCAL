/*************************************************************
 * 
 * Filename: DIO_Cfg.h
 * Description: Configuration file of DIO module in ATmega32 uC.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __DIO_CFG_H__
#define __DIO_CFG_H__

#include "DIO.h"


/*************************************************************
 * Description: (Do not change) Macro constants, used to define pin direction
 *                  in following configurations.
 * 
 *************************************************************/
#define DIO_DIR_INPUT                   0
#define DIO_DIR_OUTPUT                  1


/*************************************************************
 * Description: (Do not change) Macro constants, used to define the
 *                  configuration of an input pin.
 * 
 *************************************************************/
#define DIO_CFG_HI_Z                    0
#define DIO_CFG_PULL_UP                 1


/*************************************************************
 * Description: (Do not change) Macro constants, used to define the
 *                  configuration (default state) of an output pin.
 * 
 *************************************************************/
#define DIO_CFG_LOW                     0
#define DIO_CFG_HIGH                    1


/*************************************************************
 * Description: Configuration of pin direction (0-32).
 * 
 *************************************************************/
#define DIO_PIN0_DIR                DIO_DIR_OUTPUT
#define DIO_PIN1_DIR                DIO_DIR_OUTPUT
#define DIO_PIN2_DIR                DIO_DIR_OUTPUT
#define DIO_PIN3_DIR                DIO_DIR_OUTPUT
#define DIO_PIN4_DIR                DIO_DIR_OUTPUT
#define DIO_PIN5_DIR                DIO_DIR_OUTPUT
#define DIO_PIN6_DIR                DIO_DIR_OUTPUT
#define DIO_PIN7_DIR                DIO_DIR_OUTPUT

#define DIO_PIN8_DIR                DIO_DIR_INPUT
#define DIO_PIN9_DIR                DIO_DIR_INPUT
#define DIO_PIN10_DIR               DIO_DIR_INPUT
#define DIO_PIN11_DIR               DIO_DIR_INPUT
#define DIO_PIN12_DIR               DIO_DIR_INPUT
#define DIO_PIN13_DIR               DIO_DIR_INPUT
#define DIO_PIN14_DIR               DIO_DIR_INPUT
#define DIO_PIN15_DIR               DIO_DIR_INPUT

#define DIO_PIN16_DIR               DIO_DIR_INPUT
#define DIO_PIN17_DIR               DIO_DIR_INPUT
#define DIO_PIN18_DIR               DIO_DIR_INPUT
#define DIO_PIN19_DIR               DIO_DIR_INPUT
#define DIO_PIN20_DIR               DIO_DIR_INPUT
#define DIO_PIN21_DIR               DIO_DIR_INPUT
#define DIO_PIN22_DIR               DIO_DIR_INPUT
#define DIO_PIN23_DIR               DIO_DIR_INPUT

#define DIO_PIN24_DIR               DIO_DIR_INPUT
#define DIO_PIN25_DIR               DIO_DIR_INPUT
#define DIO_PIN26_DIR               DIO_DIR_INPUT
#define DIO_PIN27_DIR               DIO_DIR_INPUT
#define DIO_PIN28_DIR               DIO_DIR_INPUT
#define DIO_PIN29_DIR               DIO_DIR_INPUT
#define DIO_PIN30_DIR               DIO_DIR_INPUT
#define DIO_PIN31_DIR               DIO_DIR_INPUT


/*************************************************************
 * Description: Configuration of pins (0-32).
 * 
 *************************************************************/
#define DIO_PIN0_CFG                  DIO_CFG_LOW
#define DIO_PIN1_CFG                  DIO_CFG_LOW
#define DIO_PIN2_CFG                  DIO_CFG_LOW
#define DIO_PIN3_CFG                  DIO_CFG_LOW
#define DIO_PIN4_CFG                  DIO_CFG_LOW
#define DIO_PIN5_CFG                  DIO_CFG_LOW
#define DIO_PIN6_CFG                  DIO_CFG_LOW
#define DIO_PIN7_CFG                  DIO_CFG_LOW

#define DIO_PIN8_CFG                  DIO_CFG_HI_Z
#define DIO_PIN9_CFG                  DIO_CFG_HI_Z
#define DIO_PIN10_CFG                 DIO_CFG_HI_Z
#define DIO_PIN11_CFG                 DIO_CFG_HI_Z
#define DIO_PIN12_CFG                 DIO_CFG_HI_Z
#define DIO_PIN13_CFG                 DIO_CFG_HI_Z
#define DIO_PIN14_CFG                 DIO_CFG_HI_Z
#define DIO_PIN15_CFG                 DIO_CFG_HI_Z

#define DIO_PIN16_CFG                 DIO_CFG_HI_Z
#define DIO_PIN17_CFG                 DIO_CFG_HI_Z
#define DIO_PIN18_CFG                 DIO_CFG_HI_Z
#define DIO_PIN19_CFG                 DIO_CFG_HI_Z
#define DIO_PIN20_CFG                 DIO_CFG_HI_Z
#define DIO_PIN21_CFG                 DIO_CFG_HI_Z
#define DIO_PIN22_CFG                 DIO_CFG_HI_Z
#define DIO_PIN23_CFG                 DIO_CFG_HI_Z

#define DIO_PIN24_CFG                 DIO_CFG_HI_Z
#define DIO_PIN25_CFG                 DIO_CFG_HI_Z
#define DIO_PIN26_CFG                 DIO_CFG_HI_Z
#define DIO_PIN27_CFG                 DIO_CFG_HI_Z
#define DIO_PIN28_CFG                 DIO_CFG_HI_Z
#define DIO_PIN29_CFG                 DIO_CFG_HI_Z
#define DIO_PIN30_CFG                 DIO_CFG_HI_Z
#define DIO_PIN31_CFG                 DIO_CFG_HI_Z


#endif /* __DIO_CFG_H__ */