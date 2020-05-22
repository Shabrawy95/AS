/*********************************************************************************************************************************
 *  Filename: OS_config.c
 *
 *  Description: source file for OS timer 0  configurations required
 *
 *  Created on: MAR 03, 2020
 *
 *  Author: Shabrawy
 ********************************************************************************************************************************/
#include "Gpt.h"
#include "OS.h"

TIMER0_ConfigType OS_configuration = {T0_CTC, T0_OFF, T0_F_CPU_1024, T0_COMP_ENABLE, 0, OS_BASE_TIME };
