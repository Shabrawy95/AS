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
#include "OS.h"
#include "Gpt.h"
#include "app.h"

/*********************************************************************************************************************************
 *                    								  Global Variables     						                                 *
 ********************************************************************************************************************************/
/*Timer 0 config struct used for os scheduler*/
extern const TIMER0_ConfigType OS_configuration;

/*Global Variable used to store OS time*/
static uint8 g_Time_Tick_Count = 0;

/*Global Variable used to indicate that timer finished counting 20ms
 * and os has new tick to process*/
static uint8 g_New_Time_Tick_Flag = 0;
/*********************************************************************************************************************************
 *                    								  Function defintions      						                                 *
 ********************************************************************************************************************************/


/*Description: Function reponsible for 1- Initialize OS
 * 									   2- Execute init task
 * 									   3- Start scheduler to run tasks*/
void OS_Start(void){

	/*Set callback function from timer module to OS_newTimerTick,
	 * so that this function is called every Compare val interrupt(20ms)*/
	TIMER0_setCallBack(OS_newTimerTick);


	/*initialize Timer in CTC MODE
	 * Prescaler: F_CPU/2014
	 * Comapre Value: 20ms to generate interrupt every 20ms*/
	TIMER0_Start(&OS_configuration);

	/*initialize DIO and PORT drivers*/
	Init_Task();

	/*Start the OS Scheduler*/
	OS_scheduler();
}


/*Desciption: called by timer Module using callback pointer*/
void OS_newTimerTick(void){

	/*Increment OS Time be 20ms (Base Time)*/
	g_Time_Tick_Count += OS_BASE_TIME;

	/*Set flag to indicate a new timer tick*/
	g_New_Time_Tick_Flag = 1;

}
/*
void Button_Task(void);

void Led_Task(void);

void App_Task(void);*/

/*Description: Used to switch between different tasks*/
void OS_scheduler(void){
	while(1){
		if(g_New_Time_Tick_Flag == 1){
			switch(g_Time_Tick_Count){
			case 20:
			case 100:Button_Task();
					 g_New_Time_Tick_Flag = 0; /*For new tick*/
					 break;


			case 40:
			case 80: Button_Task();
					 Led_Task();
					 g_New_Time_Tick_Flag = 0; /*For new tick*/
					 break;

			case 60: Button_Task();
					 App_Task();/*toggle led if button is pressed*/
					 g_New_Time_Tick_Flag = 0;
					 break;

			case 120: Button_Task();
					  Led_Task();
					  App_Task();
					  g_New_Time_Tick_Flag = 0;
					  g_Time_Tick_Count = 0;
					  break;

			}
		}
	}
}

