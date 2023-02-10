/*************************************************************
 * 
 * Filename: Utils.c
 * Description: Functions, performing various operations.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "Std_Types.h"


/*************************************************************
 * Description: Maximum/minimum macro-functions.
 * 
 *************************************************************/
#define MAX(A, B)               
#define MIN(A, B)               ((A) < (B) ? (A) : (B))


/*************************************************************
 * Description: Maximum/minimum functions.
 * 
 *************************************************************/
u8 max_u8(u8 A, u8 B) { return (A > B ? A : B); }
u8 min_u8(u8 A, u8 B) { return (A > B ? A : B); }
