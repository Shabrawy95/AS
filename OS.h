 /********************************************************************************************************************************
 * Module: OS
 *
 * File Name: OS.h
 *
 *
 * Description: header file for OS scheduler
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#ifndef OS_H_
#define OS_H_

#include "Std_Types.h"

/*timer couting time is 20ms*/
#define OS_BASE_TIME 20

/*********************************************************************************************************************************
 *                    								  Function prototypes      						                                 *
 ********************************************************************************************************************************/

/*Description: Function reponsible for 1- Initialize OS
 * 									   2- Execute init task
 * 									   3- Start scheduler to run tasks*/
void OS_Start(void);

/*Description: Used to switch between different tasks*/
void OS_scheduler(void);

/*Desciption: called by timer Module using callback pointer*/
void OS_newTimerTick(void);
#endif /* OS_H_ */
