 /********************************************************************************************************************************
 * Module: button
 *
 * File Name: button.h
 *
 *
 * Description: header file for button module
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#ifndef BUTTON_H_
#define BUTTON_H_

#include "Std_Types.h"

/*button released or pressed according to connection (pullup or pulldown)
 * in this case it's pull down*/
#define BUTTON_PRESSED 		STD_HIGH
#define BUTTON_RELEASED 	STD_LOW

/*********************************************************************************************************************************
 *                    								  Function Prototypes      						                                 *
 ********************************************************************************************************************************/

/*Description: get button state (pressed or released)*/
uint8 BUTTON_getState(void);


/*Description: Function called by schedule very 20ms, it's used to update button state.
 * if button is pressed continually for 60 ms then it's state is pressed.
 * if button is released continually for 60ms then it's state is released*/
void BUTTON_refreshState(void);

#endif /* BUTTON_H_ */
