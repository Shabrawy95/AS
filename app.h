 /********************************************************************************************************************************
 * Module: Application
 *
 * File Name: app.h
 *
 *
 * Description: header file for application tasks
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#ifndef APP_H_
#define APP_H_

#include "Std_Types.h"


/*********************************************************************************************************************************
 *                    								  Function prototypes      						                                 *
 ********************************************************************************************************************************/
/*Description: Task called once to initialize all modules*/
void Init_Task(void);

/*Description: Task called every 20ms to refresh button state*/
void Button_Task(void);

/*Description: Task called every 40ms to refresh led state*/
void Led_Task(void);

/*Description: Task called every 60ms to get button state and toggle the led*/
void App_Task(void);
#endif /* APP_H_ */
