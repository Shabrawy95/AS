 /********************************************************************************************************************************
 * Module: button
 *
 * File Name: button.c
 *
 *
 * Description: source file for button module
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#include "Dio.h"
#include "button.h"

/*********************************************************************************************************************************
 *                    								  Global variables      						                                 *
 ********************************************************************************************************************************/
/*Get count of button presses, increments if button is pressed for 20ms*/
static uint8 g_Pressed_Count = 0;

/*Get count of button releases, increments if button is released for 20ms*/
static uint8 g_Released_Count = 0;

static uint8 g_Button_State = BUTTON_RELEASED;

/*********************************************************************************************************************************
 *                    								  Function definitions      						                                 *
 ********************************************************************************************************************************/

/*Description: get button state (pressed or released)*/
uint8 BUTTON_getState(void){
	return g_Button_State;
}


/*Description: Function called by schedule very 20ms, it's used to update button state.
 * if button is pressed continually for 60 ms then it's state is pressed.
 * if button is released continually for 60ms then it's state is released*/
void BUTTON_refreshState(void){
	uint8 state = Dio_ReadChannel(DIOConf_BUTTON_CHANNEL_ID_INDEX);
	if(state == BUTTON_PRESSED){
		g_Pressed_Count++;
		g_Released_Count = 0;
	}else{
		g_Released_Count++;
		g_Pressed_Count = 0;
	}

	if(g_Pressed_Count == 3){
		g_Button_State = BUTTON_PRESSED;
		g_Pressed_Count = 0;
		g_Released_Count = 0;
	}
	else if(g_Released_Count == 3)
	{
		g_Button_State = BUTTON_RELEASED;
		g_Released_Count = 0;
		g_Pressed_Count = 0;
	}


}
