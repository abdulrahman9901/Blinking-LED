
#include "Std_Types.h"
#include "DIO_Types.h"
#include "IntCtrl.h"
#include "Port.h"
#include "DIO.h"
#include "Systick.h"
#include "led_blink.h"

uint8 LED_ON = 0;   // 1 => ON / 0 => OFF
 /* Selecting port and pins to work with */
static Dio_ChannelType Confirm = Pin4;  // THIS BUTTON USED AS RESET BUTTON IF WHILE LED IS	
										// AND AS CONFIRM BUTTON WHEN TAKING USER INPUT
static Dio_ChannelType Inc = Pin0;

static Dio_ChannelType LED = Pin2;

static Dio_PortType Port = PORT_F;

static uint32 resetCount = 0 ;
vuint8 x ;
void check_reset(Dio_PortType Port , Dio_ChannelType reset){
	if(Dio_ReadChannel(reset,Port)== 0){
		resetCount++;
	}else {
		resetCount = 0;
	}
	if(resetCount > 500){   // BUTTON SHOULD BE PRESSED AT LEAST FOR 0.5 SEC TO RESET 
		LED_ON = 0;
	}
}
void handle__Systick_isr(void){
	check_reset(Port,Confirm);
}

void system_setup(){
	IntCrtl_Init();
	Port_Init();
	Systick_init();
	Led_init(LED,Confirm,Inc,Port);
	register_Systick_CB(handle__Systick_isr);
}
int main(void){

system_setup();

while (1){
	/*User need to press Confirm button at the begining
	to start accepting his/her input */
	LED_ON = get_user_input();
	resetCount = 0;
	while(LED_ON){
		light_led(&x);	
		}
	}
}