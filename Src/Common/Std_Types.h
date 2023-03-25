/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Std_Types.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  Provision of Standard Types
 *
 *********************************************************************************************************************/



#ifndef STD_TYPES_H
#define STD_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "Platform_Types.h"
# include "Compiler.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define STD_HIGH     1u /* Physical state 5V or 3.3V */
# define STD_LOW      0u /* Physical state 0V */

# define STD_ACTIVE   1u /* Logical state active */
# define STD_IDLE     0u /* Logical state idle */

# define STD_ON       1u
# define STD_OFF      0u

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*--------------------------signed integers------------------------*/
typedef char sint8;
typedef short sint16;
typedef int sint32;
typedef long long sint64;
/*------------------------unsigned integers------------------------*/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
/*-------------------volatile signed integers----------------------*/
typedef volatile char vint8;
typedef volatile short vint16;
typedef volatile long vint32;
typedef volatile long long vint64;
/*-------------------volatile unsigned integers--------------------*/
typedef volatile unsigned char vuint8;
typedef volatile unsigned short vuint16;
typedef volatile unsigned long vuint32;
typedef volatile unsigned long long vuint64;
/*-----------------------------boolean-----------------------------*/
typedef unsigned long boolean;
typedef volatile unsigned long vboolean;



typedef uint8 Std_ReturnType;
#define E_OK          0u
#define E_NOT_OK      1u

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* STD_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
