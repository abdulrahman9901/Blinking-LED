/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"
#include "IntCtrl_Cfg.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void)
{

    vuint8 i=0;
	vuint8 intVIndex=0;
	vuint8 PRI_X_Offset=0;
	vuint8 EN_Offset=0;
	vuint8 PRI_X =0;
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    APINT = 0xFA05|(PRIORITY_GROUPING << 8);
    /* Loop through all given interrupts*/
    for(i=0; i < INT_NUM_TO_ACTIVATE ;++i){
        intVIndex = NVIC_Config[i].interruptName;
        PRI_X = (intVIndex / 4);
        PRI_X_Offset = ((intVIndex % 4) * 8) + 5;
        EN_Offset = (intVIndex % 32) ;

        /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/      
        #if (PRIORITY_GROUPING == xxx)
        NVIC->PRI[PRI_X] |= (NVIC_Config[i].groupPriority << (uint32)PRI_X_Offset);
        #elif (PRIORITY_GROUPING == xxy)
        NVIC->PRI[PRI_X] |= (NVIC_Config[i].groupPriority << (uint32)(PRI_X_Offset + 1));
        NVIC->PRI[PRI_X] |= (NVIC_Config[i].subGroupPriority <<(uint32)PRI_X_Offset);
        #elif (PRIORITY_GROUPING == xyy)
        NVIC->PRI[PRI_X] |= (NVIC_Config[i].groupPriority << (uint32)(PRI_X_Offset + 2));
        NVIC->PRI[PRI_X] |= (NVIC_Config[i].subGroupPriority << (uint32)PRI_X_Offset);
        #elif (PRIORITY_GROUPING == yyy)
        NVIC->PRI[PRI_X] |= (NVIC_Config[i].subGroupPriority << (uint32)PRI_X_Offset);
        #endif
    }	

        
        /*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
        for(i=0; i < INT_NUM_TO_ACTIVATE ;++i){
            intVIndex = NVIC_Config[i].interruptName;
            EN_Offset = (intVIndex % 32) ;
            NVIC->EN[intVIndex/32] |= ((1u) << (uint32)EN_Offset);
        }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
