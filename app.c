 /********************************************************************************************************************************
 * Module: Application
 *
 * File Name: app.c
 *
 *
 * Description: source file for application tasks
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/
#include "app.h"
#include "button.h"
#include "led.h"
#include "Dio.h"
#include "Port.h"
#include "micro_config.h"
/*********************************************************************************************************************************
 *                    								  Function definitions      						                                 *
 ********************************************************************************************************************************/

/*Description: Task called once to initialize all modules*/
void Init_Task(void){
	/*Enable interrupts*/
	SREG |= (1<<7);

	/*initialize port driver*/
	Port_Init(&Port_Configuration);

	/*initialize dio driver*/
	Dio_Init(&Dio_Configuration);


}

/*Description: Task called every 20ms to refresh button state*/
void Button_Task(void){
	BUTTON_refreshState();
}

/*Description: Task called every 40ms to refresh led state*/
void Led_Task(void){
	LED_refreshOutput();
}

/*Description: Task called every 60ms to get button state and toggle the led*/
void App_Task(void){
	static uint8 button_current_state = BUTTON_RELEASED;
	static uint8 button_previous_state = BUTTON_RELEASED;

	/*read current state of the button*/
	button_current_state = BUTTON_getState();

	/*only toggle led if previous state was released and the button's current state is pressed*/
	if((button_current_state == BUTTON_PRESSED)&&(button_previous_state == BUTTON_RELEASED)){
		LED_toggle();
	}else{
		/*No action required*/
	}
	button_previous_state = button_current_state;
}
