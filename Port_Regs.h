 /********************************************************************************************************************************
 * Module: Port
 *
 * File Name: Port_Regs.h
 *
 * Description: header file for Port module Registers
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#ifndef PORT_REGS_H_
#define PORT_REGS_H_
#include "Std_Types.h"


/*PORTA registers defintions*/
#define PORTA_REG			(*(volatile uint8* const) 0x003B)
#define DDRA_REG			(*(volatile uint8* const) 0x003A)
#define PINA_REG			(*(const volatile uint8* const) 0x0039)

/*PORTB registers defintions*/
#define PORTB_REG			(*(volatile uint8* const) 0x0038)
#define DDRB_REG			(*(volatile uint8* const) 0x0037)
#define PINB_REG			(*(const volatile uint8* const) 0x0036)

/*PORTC registers defintions*/
#define PORTC_REG			(*(volatile uint8* const) 0x0035)
#define DDRC_REG			(*(volatile uint8* const) 0x0034)
#define PINC_REG			(*(const volatile uint8* const) 0x0033)

/*PORTD registers defintions*/
#define PORTD_REG			(*(volatile uint8* const) 0x0032)
#define DDRD_REG			(*(volatile uint8* const) 0x0031)
#define PIND_REG			(*(const volatile uint8* const) 0x0030)

#endif /* PORT_REGS_H_ */
