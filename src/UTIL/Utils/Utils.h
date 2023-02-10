/*************************************************************
 * 
 * Filename: Utils.h
 * Description: Macros and function prototypes, performing various operations.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#ifndef __UTILS_H__
#define __UTILS_H__


/*************************************************************
 * Description: Maximum/minimum macro-functions.
 * 
 *************************************************************/
#define MAX(A, B)               ((A) > (B) ? (A) : (B))
#define MIN(A, B)               ((A) < (B) ? (A) : (B))


/*************************************************************
 * Description: Maximum/minimum functions.
 * 
 *************************************************************/
u8 max_u8(u8 A, u8 B);
u8 min_u8(u8 A, u8 B);


#endif /* __UTILS_H__ */