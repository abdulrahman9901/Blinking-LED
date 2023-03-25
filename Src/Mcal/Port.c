/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Port_Types.h"
#include "Port_Cfg.h"
#include "Port.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Port_Init()
{
	uint8 i =0;

    /*Enable GPIO F */
    	// get the required RCGC register for this peripheral
		vuint32 regOffset = 0x08u;
		vuint32 bitOffset = 0x5;
		// assign the sequired RCGC and PR registers
		vuint32 *RCGCGPIO = (vuint32 *)((SysCtrl_BASE) + (RCGC_OFFSET) + (regOffset));
		vuint32 *PRGPIO = (vuint32 *)((SysCtrl_BASE) + (PR_OFFSET) + (regOffset));
        
        *RCGCGPIO |= 1u << (uint32)bitOffset;

    for(i=0; i<NUM_OF_PINS ;++i){
        Dio_PortType port = Port_Config[i].port;
        Dio_ChannelType pin = Port_Config[i].pin;
        
        if(Port_Config[i].direction){
            GPIO(port)->GPIODIR |= (1u << pin);
        }
        else{
            GPIO(port)->GPIODIR &= ~(1u << pin);
        }

        if(Digital == Port_Config[i].mode){
            GPIO(port)->GPIOAFSEL &= ~(1u << pin);
            GPIO(port)->GPIODEN |= 1u << pin;
        }

        switch (Port_Config[i].internalAttach)
        {
        case OpenDrain:
            GPIO(port)->GPIOODR |= (1u << pin);
            break;
        case PullUp:
            GPIO(port)->GPIOPUR |= (1u << pin);
            break;
        case PullDown:
            GPIO(port)->GPIOPDR |= (1u << pin);
            break;
        default:
            break;
        }

        switch (Port_Config[i].outputcurrent)
        {
        case Port_2ma:
            GPIO(port)->GPIODR2R |= (1u << pin);
            break;

        case Port_4ma:
            GPIO(port)->GPIODR4R |= (1u << pin);
            break;

        case Port_8ma:
            GPIO(port)->GPIODR8R |= (1u << pin);
            break;
        default:
            break;
        }
    }
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
