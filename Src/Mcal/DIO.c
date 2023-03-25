/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"
#include "Std_Types.h"
#include "Dio_Types.h"
#include "DIO.h"
#include "bitmath.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define GPIO_DATA_OFFSET                ((uint32) 0x000003FC)
#define REGISTER_CONCAT(REG1,REG2) (*((volatile uint32 *)( REG1 + REG2)))

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

extern Dio_LevelType Dio_ReadChannel(Dio_ChannelType Channel,

Dio_PortType Port){
    /*uint8 ChannelId = ((1 << Channel) & 0xffu) ;
    if(GPIO(Port)->GPIODATA[ChannelId] > 0)
        return Dio_HIGH;
    else
        return Dio_LOW;
        */
       
    if(GET_BIT(REGISTER_CONCAT(Port, GPIO_DATA_OFFSET),Channel) > 0)
        return Dio_HIGH;
    else
        return Dio_LOW;

}
extern void Dio_WriteChannel(Dio_ChannelType Channel, Dio_PortType Port,
                             Dio_LevelType Level){

    /** BIT MUSKING DON'T WORK ON KEIL */
    /*uint8 ChannelId = ((1 << Channel) & 0xffu) ;
    uint32 ptr = GPIO(Port)->GPIODATA[ChannelId];
    
    GPIO(Port)->GPIODATA[ChannelId] =  (uint8)0xFF; 
    */

   switch (Level) {
	case Dio_HIGH:
		SET_BIT(REGISTER_CONCAT(Port, GPIO_DATA_OFFSET),Channel);
		break;

	case Dio_LOW:
		CLEAR_BIT(REGISTER_CONCAT(Port, GPIO_DATA_OFFSET),Channel);
		break;

	default:
		break;
	}

}
extern Dio_PortLevelType Dio_ReadPort(Dio_PortType Port){
   return ((uint8)GPIO(Port)->GPIODATA[255]); 
}
extern void Dio_WritePort(Dio_PortType Port, Dio_PortLevelType Level){
    uint32 ptr = GPIO(Port)->GPIODATA[255];
    GPIO(Port)->GPIODATA[255] = Level; 
}
extern void Dio_FlipChannel(Dio_ChannelType Channel, Dio_PortType Port){
    TOGGLE_BIT(REGISTER_CONCAT(Port, GPIO_DATA_OFFSET),Channel);
}

/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/
