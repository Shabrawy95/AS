 /********************************************************************************************************************************
 * Module: Led
 *
 * File Name: led.h
 *
 *
 * Description: header file for led module
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#include "Std_Types.h"


#ifndef LED_H_
#define LED_H_

/*Set led on or off according to its connection (+ve or -ve logic)*/
#define LED_ON STD_HIGH
#define LED_OFF STD_LOW

/*********************************************************************************************************************************
 *                    								  Function Prototypes      						                                 *
 ********************************************************************************************************************************/
/*Turn led on*/
void LED_setOn(void);

/*Turn led off*/
void LED_setOff(void);

/*Toggle led state*/
void LED_toggle(void);

/*Refresh led state*/
void LED_refreshOutput(void);

#endif /* LED_H_ */
