/*************************************************************
 * 
 * Filename: EXT_INT_Cfg.h
 * Description: Configuration header file of the EXT_INT driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __EXT_INT_CFG_H__
#define __EXT_INT_CFG_H__


/*************************************************************
 * Description: (Do not change) The possible configurations for each interrupt.
 * 
 *************************************************************/
#define EXT_INT_ON_LOW                 00
#define EXT_INT_ON_CHANGE              01
#define EXT_INT_ON_FALLING             10
#define EXT_INT_ON_RISING              11


/*************************************************************
 * Description: The different configurations for each interrupt.
 *                  Note: 'INT3' accepts 'FALLING` and `RISING` only.
 * 
 *************************************************************/
#define EXT_INT_INT0_CFG                EXT_INT_ON_RISING
#define EXT_INT_INT1_CFG                EXT_INT_ON_RISING
#define EXT_INT_INT2_CFG                EXT_INT_ON_RISING


/*************************************************************
 * Description: (Do not change) The possible states of each interrupt module.
 *
 *************************************************************/
#define EXT_INT_STATE_ENABLED                1
#define EXT_INT_STATE_DISABLED               0


/*************************************************************
 * Description: The different states of each interrupt.
 * 
 *************************************************************/
#define EXT_INT_INT0_STATE                  EXT_INT_STATE_ENABLED
#define EXT_INT_INT1_STATE                  EXT_INT_STATE_ENABLED
#define EXT_INT_INT2_STATE                  EXT_INT_STATE_DISABLED


#endif /* __EXT_INT_CFG_H__ */