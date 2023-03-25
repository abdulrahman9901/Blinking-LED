/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
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
#include "led_blink.h"
#include "Port_Types.h"
#include "DIO_Types.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
Dio_ChannelType LED;
Dio_ChannelType Confirm;
Dio_ChannelType Inc;
Dio_PortType Port;
uint32 OnTime = 0,OffTime = 0;
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


void Led_init(Dio_ChannelType inLED, Dio_ChannelType inConfirm, Dio_ChannelType inInc,
              Dio_PortType inPort){
                LED = inLED;
                Confirm = inConfirm;
                Inc = inInc;
                Port = inPort;
    }

uint8 get_user_input()
{
    inputState currentState = WAITING;
    OnTime = 0;
    OffTime = 0;
    while (currentState != DONE)
    {
      if(Dio_ReadChannel(Confirm,Port) == 0){  //start taking input from user

        while (Dio_ReadChannel(Confirm,Port) == 0);
        currentState+=1;
        
      }
    if(Dio_ReadChannel(Inc,Port) == 0){  //start taking input from user
        while (Dio_ReadChannel(Inc,Port) == 0);
        switch (currentState)
        {
        case GETTING_ON_TIME:
            OnTime+=1000;
            break;
        case GETTING_OFF_TIME:
            OffTime+=1000;
            break;
        default:
            break;
        }
        
      }
    }
    return 1;
}
void light_led(vuint8 *x){
    Dio_WriteChannel(LED,Port,Dio_HIGH);
		*x = Dio_ReadChannel(LED,Port);
    delay_ms(OnTime);		
    Dio_WriteChannel(LED,Port,Dio_LOW);
		*x = Dio_ReadChannel(LED,Port);
    delay_ms(OffTime);		
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/