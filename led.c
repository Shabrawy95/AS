 /********************************************************************************************************************************
 * Module: Led
 *
 * File Name: led.c
 *
 *
 * Description: source file for led module
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/
#include "app.h"
#include "Dio.h"
#include "led.h"
/*********************************************************************************************************************************
 *                    								  Function definitions      						                                 *
 ********************************************************************************************************************************/
/*Turn led on*/
void LED_setOn(void){
	Dio_WriteChannel(DIOConf_LED_CHANNEL_ID_INDEX, LED_ON);
}

/*Turn led off*/
void LED_setOff(void){
	Dio_WriteChannel(DIOConf_LED_CHANNEL_ID_INDEX, LED_OFF);
}

/*Toggle led state*/
void LED_toggle(void){
	Dio_LevelType state = Dio_FlipChannel(DIOConf_LED_CHANNEL_ID_INDEX);
}

/*Refresh led state*/
void LED_refreshOutput(void){
	Dio_LevelType state = Dio_ReadChannel(DIOConf_LED_CHANNEL_ID_INDEX); /*read value of led*/

	 Dio_WriteChannel(DIOConf_LED_CHANNEL_ID_INDEX, state); /*rewrite the same value*/

}
