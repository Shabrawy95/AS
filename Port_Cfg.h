 /********************************************************************************************************************************
 * Module: PORT
 *
 * File Name: PORT_Cfg.h
 *
 *
 * Description: Pre-Compile configuration header for PORT Driver
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_


/*Module SW Version (1.0.0)*/

#define PORT_CFG_SW_MAJOR_VERSION				(1U)
#define PORT_CFG_SW_MINOR_VERSION				(0U)
#define PORT_CFG_SW_PATCH_VERSION				(0U)

/*Module AUTOSAR Version (4.0.3)*/

#define PORT_CFG_AR_RELEASE_MAJOR_VERSION				(4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION				(0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION				(3U)


/*Pre-compile option for development error detection*/
#define PORT_DEV_ERROR_DETECT					(STD_ON)

/*Pre-compile option for Port_SetPinDirection API*/
#define PORT_SET_PIN_DIRECTION_API					(TRUE)

/*Pre-compile option for Port_SetPinMode API*/
#define PORT_SET_PIN_MODE_API						(TRUE)

/*Pre-compile option for Port Version Info API*/
#define PORT_VERSION_INFO_API					(STD_ON)

/*Number of Pins in the MCU*/
#define NUMBER_OF_PORT_PINS 					((Port_PinType)32U)


/*define each port's index*/
#define PORT_A_NUM								((uint8)0)
#define PORT_B_NUM								((uint8)1)
#define PORT_C_NUM								((uint8)2)
#define PORT_D_NUM								((uint8)3)


/*******************************************************************************************************************************
 * 												 Pre-compile Config					                    					   *
 * *****************************************************************************************************************************/
/*index of each pin config in array of Port_ConfigPin structs*/
#define PORT_A_PIN_0_INDEX				((uint8)0)
#define PORT_A_PIN_1_INDEX				((uint8)1)
#define PORT_A_PIN_2_INDEX				((uint8)2)
#define PORT_A_PIN_3_INDEX				((uint8)3)
#define PORT_A_PIN_4_INDEX				((uint8)4)
#define PORT_A_PIN_5_INDEX				((uint8)5)
#define PORT_A_PIN_6_INDEX				((uint8)6)
#define PORT_A_PIN_7_INDEX			    ((uint8)7)

#define PORT_B_PIN_0_INDEX				((uint8)8)
#define PORT_B_PIN_1_INDEX              ((uint8)9)
#define PORT_B_PIN_2_INDEX              ((uint8)10)
#define PORT_B_PIN_3_INDEX              ((uint8)11)
#define PORT_B_PIN_4_INDEX              ((uint8)12)
#define PORT_B_PIN_5_INDEX              ((uint8)13)
#define PORT_B_PIN_6_INDEX              ((uint8)14)
#define PORT_B_PIN_7_INDEX              ((uint8)15)

#define PORT_C_PIN_0_INDEX				((uint8)16)
#define PORT_C_PIN_1_INDEX              ((uint8)17)
#define PORT_C_PIN_2_INDEX              ((uint8)18)
#define PORT_C_PIN_3_INDEX              ((uint8)19)
#define PORT_C_PIN_4_INDEX              ((uint8)20)
#define PORT_C_PIN_5_INDEX              ((uint8)21)
#define PORT_C_PIN_6_INDEX              ((uint8)22)
#define PORT_C_PIN_7_INDEX              ((uint8)23)

#define PORT_D_PIN_0_INDEX				((uint8)24)
#define PORT_D_PIN_1_INDEX              ((uint8)25)
#define PORT_D_PIN_2_INDEX              ((uint8)26)
#define PORT_D_PIN_3_INDEX              ((uint8)27)
#define PORT_D_PIN_4_INDEX              ((uint8)28)
#define PORT_D_PIN_5_INDEX              ((uint8)29)
#define PORT_D_PIN_6_INDEX              ((uint8)30)
#define PORT_D_PIN_7_INDEX              ((uint8)31)
/*******************************************************************************************************************************/
/*Define Each Pin Direction, Default value is input*/

#define PORT_A_PIN_0_DIRECTION									PORT_PIN_IN
#define PORT_A_PIN_1_DIRECTION                                  PORT_PIN_IN
#define PORT_A_PIN_2_DIRECTION                                  PORT_PIN_IN
#define PORT_A_PIN_3_DIRECTION                                  PORT_PIN_IN
#define PORT_A_PIN_4_DIRECTION                                  PORT_PIN_IN
#define PORT_A_PIN_5_DIRECTION                                  PORT_PIN_IN
#define PORT_A_PIN_6_DIRECTION                                  PORT_PIN_IN
#define PORT_A_PIN_7_DIRECTION                                  PORT_PIN_IN

#define PORT_B_PIN_0_DIRECTION                                  PORT_PIN_IN
#define PORT_B_PIN_1_DIRECTION                                  PORT_PIN_IN
#define PORT_B_PIN_2_DIRECTION                                  PORT_PIN_IN
#define PORT_B_PIN_3_DIRECTION                                  PORT_PIN_IN
#define PORT_B_PIN_4_DIRECTION                                  PORT_PIN_IN
#define PORT_B_PIN_5_DIRECTION                                  PORT_PIN_IN
#define PORT_B_PIN_6_DIRECTION                                  PORT_PIN_IN
#define PORT_B_PIN_7_DIRECTION                                  PORT_PIN_IN

#define PORT_C_PIN_0_DIRECTION                                  PORT_PIN_IN
#define PORT_C_PIN_1_DIRECTION                                  PORT_PIN_IN
#define PORT_C_PIN_2_DIRECTION                                  PORT_PIN_IN
#define PORT_C_PIN_3_DIRECTION                                  PORT_PIN_IN
#define PORT_C_PIN_4_DIRECTION                                  PORT_PIN_IN
/*PC5 is output for LED*/
#define PORT_C_PIN_5_DIRECTION                                  PORT_PIN_OUT
#define PORT_C_PIN_6_DIRECTION                                  PORT_PIN_IN
#define PORT_C_PIN_7_DIRECTION                                  PORT_PIN_IN

#define PORT_D_PIN_0_DIRECTION                                  PORT_PIN_IN
#define PORT_D_PIN_1_DIRECTION                                  PORT_PIN_IN
/*PD2 input for button*/
#define PORT_D_PIN_2_DIRECTION                                  PORT_PIN_IN
#define PORT_D_PIN_3_DIRECTION                                  PORT_PIN_IN
#define PORT_D_PIN_4_DIRECTION                                  PORT_PIN_IN
#define PORT_D_PIN_5_DIRECTION                                  PORT_PIN_IN
#define PORT_D_PIN_6_DIRECTION                                  PORT_PIN_IN
#define PORT_D_PIN_7_DIRECTION                                  PORT_PIN_IN

/*******************************************************************************************************************************/
/*Pin direction is changeable -> True*/
#define PORT_A_PIN_0_DIRECTION_CHANGEABLE									TRUE
#define PORT_A_PIN_1_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_A_PIN_2_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_A_PIN_3_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_A_PIN_4_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_A_PIN_5_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_A_PIN_6_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_A_PIN_7_DIRECTION_CHANGEABLE                                   TRUE

#define PORT_B_PIN_0_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_B_PIN_1_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_B_PIN_2_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_B_PIN_3_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_B_PIN_4_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_B_PIN_5_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_B_PIN_6_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_B_PIN_7_DIRECTION_CHANGEABLE                                   TRUE

#define PORT_C_PIN_0_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_C_PIN_1_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_C_PIN_2_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_C_PIN_3_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_C_PIN_4_DIRECTION_CHANGEABLE                                   TRUE
/*False since it's output to drive led*/
#define PORT_C_PIN_5_DIRECTION_CHANGEABLE                                   FALSE
#define PORT_C_PIN_6_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_C_PIN_7_DIRECTION_CHANGEABLE                                   TRUE

#define PORT_D_PIN_0_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_D_PIN_1_DIRECTION_CHANGEABLE                                   TRUE
/*False since it's input to drive button*/
#define PORT_D_PIN_2_DIRECTION_CHANGEABLE                                   FALSE
#define PORT_D_PIN_3_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_D_PIN_4_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_D_PIN_5_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_D_PIN_6_DIRECTION_CHANGEABLE                                   TRUE
#define PORT_D_PIN_7_DIRECTION_CHANGEABLE                                   TRUE

/*******************************************************************************************************************************/
/*for initial mode sent to Port_init Api*/
#define PORT_A_PIN_0_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_1_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_2_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_3_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_4_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_5_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_6_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_7_INITIAL_MODE					PORT_PIN_MODE_UNUSED

#define PORT_B_PIN_0_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_1_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_2_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_3_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_4_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_5_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_6_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_7_INITIAL_MODE					PORT_PIN_MODE_UNUSED

#define PORT_C_PIN_0_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_1_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_2_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_3_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_4_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_5_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_6_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_7_INITIAL_MODE					PORT_PIN_MODE_UNUSED

#define PORT_D_PIN_0_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_1_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_2_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_3_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_4_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_5_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_6_INITIAL_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_7_INITIAL_MODE					PORT_PIN_MODE_UNUSED

/*******************************************************************************************************************************/

/*For mode change during runtime through Port_SetPinMode API*/
#define PORT_A_PIN_0_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_1_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_2_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_3_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_4_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_5_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_6_MODE					PORT_PIN_MODE_UNUSED
#define PORT_A_PIN_7_MODE					PORT_PIN_MODE_UNUSED

#define PORT_B_PIN_0_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_1_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_2_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_3_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_4_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_5_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_6_MODE					PORT_PIN_MODE_UNUSED
#define PORT_B_PIN_7_MODE					PORT_PIN_MODE_UNUSED

#define PORT_C_PIN_0_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_1_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_2_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_3_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_4_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_5_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_6_MODE					PORT_PIN_MODE_UNUSED
#define PORT_C_PIN_7_MODE					PORT_PIN_MODE_UNUSED

#define PORT_D_PIN_0_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_1_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_2_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_3_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_4_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_5_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_6_MODE					PORT_PIN_MODE_UNUSED
#define PORT_D_PIN_7_MODE					PORT_PIN_MODE_UNUSED
/*******************************************************************************************************************************/

/*Pin MODE is not changeable since you don\t use mode in AVR */
#define PORT_A_PIN_0_MODE_CHANGEABLE								   FALSE
#define PORT_A_PIN_1_MODE_CHANGEABLE                                   FALSE
#define PORT_A_PIN_2_MODE_CHANGEABLE                                   FALSE
#define PORT_A_PIN_3_MODE_CHANGEABLE                                   FALSE
#define PORT_A_PIN_4_MODE_CHANGEABLE                                   FALSE
#define PORT_A_PIN_5_MODE_CHANGEABLE                                   FALSE
#define PORT_A_PIN_6_MODE_CHANGEABLE                                   FALSE
#define PORT_A_PIN_7_MODE_CHANGEABLE                                   FALSE

#define PORT_B_PIN_0_MODE_CHANGEABLE                                   FALSE
#define PORT_B_PIN_1_MODE_CHANGEABLE                                   FALSE
#define PORT_B_PIN_2_MODE_CHANGEABLE                                   FALSE
#define PORT_B_PIN_3_MODE_CHANGEABLE                                   FALSE
#define PORT_B_PIN_4_MODE_CHANGEABLE                                   FALSE
#define PORT_B_PIN_5_MODE_CHANGEABLE                                   FALSE
#define PORT_B_PIN_6_MODE_CHANGEABLE                                   FALSE
#define PORT_B_PIN_7_MODE_CHANGEABLE                                   FALSE

#define PORT_C_PIN_0_MODE_CHANGEABLE                                   FALSE
#define PORT_C_PIN_1_MODE_CHANGEABLE                                   FALSE
#define PORT_C_PIN_2_MODE_CHANGEABLE                                   FALSE
#define PORT_C_PIN_3_MODE_CHANGEABLE                                   FALSE
#define PORT_C_PIN_4_MODE_CHANGEABLE                                   FALSE
#define PORT_C_PIN_5_MODE_CHANGEABLE                                   FALSE
#define PORT_C_PIN_6_MODE_CHANGEABLE                                   FALSE
#define PORT_C_PIN_7_MODE_CHANGEABLE                                   FALSE

#define PORT_D_PIN_0_MODE_CHANGEABLE                                   FALSE
#define PORT_D_PIN_1_MODE_CHANGEABLE                                   FALSE
#define PORT_D_PIN_2_MODE_CHANGEABLE                                   FALSE
#define PORT_D_PIN_3_MODE_CHANGEABLE                                   FALSE
#define PORT_D_PIN_4_MODE_CHANGEABLE                                   FALSE
#define PORT_D_PIN_5_MODE_CHANGEABLE                                   FALSE
#define PORT_D_PIN_6_MODE_CHANGEABLE                                   FALSE
#define PORT_D_PIN_7_MODE_CHANGEABLE                                   FALSE

/*******************************************************************************************************************************/
/*Port pin level initial value*/
#define PORT_A_PIN_0_LEVEL_VALUE							PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_1_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_2_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_3_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_4_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_5_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_6_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_A_PIN_7_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW

#define PORT_B_PIN_0_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_1_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_2_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_3_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_4_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_5_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_6_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_B_PIN_7_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW

#define PORT_C_PIN_0_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_C_PIN_1_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_C_PIN_2_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_C_PIN_3_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_C_PIN_4_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_C_PIN_5_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_C_PIN_6_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_C_PIN_7_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW

#define PORT_D_PIN_0_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_1_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_2_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_3_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_4_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_5_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_6_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW
#define PORT_D_PIN_7_LEVEL_VALUE                            PORT_PIN_LEVEL_LOW



/*******************************************************************************************************************************/
/*Number of pins within the port registers*/
#define PORT_A_PIN_0					((Port_PinType)0)
#define PORT_A_PIN_1					((Port_PinType)1)
#define PORT_A_PIN_2					((Port_PinType)2)
#define PORT_A_PIN_3					((Port_PinType)3)
#define PORT_A_PIN_4					((Port_PinType)4)
#define PORT_A_PIN_5					((Port_PinType)5)
#define PORT_A_PIN_6					((Port_PinType)6)
#define PORT_A_PIN_7					((Port_PinType)7)

#define PORT_B_PIN_0					((Port_PinType)0)
#define PORT_B_PIN_1                    ((Port_PinType)1)
#define PORT_B_PIN_2                    ((Port_PinType)2)
#define PORT_B_PIN_3                    ((Port_PinType)3)
#define PORT_B_PIN_4                    ((Port_PinType)4)
#define PORT_B_PIN_5                    ((Port_PinType)5)
#define PORT_B_PIN_6                    ((Port_PinType)6)
#define PORT_B_PIN_7                    ((Port_PinType)7)

#define PORT_C_PIN_0					((Port_PinType)0)
#define PORT_C_PIN_1                    ((Port_PinType)1)
#define PORT_C_PIN_2                    ((Port_PinType)2)
#define PORT_C_PIN_3                    ((Port_PinType)3)
#define PORT_C_PIN_4                    ((Port_PinType)4)
#define PORT_C_PIN_5                    ((Port_PinType)5)
#define PORT_C_PIN_6                    ((Port_PinType)6)
#define PORT_C_PIN_7                    ((Port_PinType)7)

#define PORT_D_PIN_0					((Port_PinType)0)
#define PORT_D_PIN_1                    ((Port_PinType)1)
#define PORT_D_PIN_2                    ((Port_PinType)2)
#define PORT_D_PIN_3                    ((Port_PinType)3)
#define PORT_D_PIN_4                    ((Port_PinType)4)
#define PORT_D_PIN_5                    ((Port_PinType)5)
#define PORT_D_PIN_6                    ((Port_PinType)6)
#define PORT_D_PIN_7                    ((Port_PinType)7)
/*******************************************************************************************************************************/
/*Input pins resistor mode, all disabled in this case*/
#define PORT_A_PIN_0_RESISTOR_MODE							RES_DISABLED
#define PORT_A_PIN_1_RESISTOR_MODE							RES_DISABLED
#define PORT_A_PIN_2_RESISTOR_MODE							RES_DISABLED
#define PORT_A_PIN_3_RESISTOR_MODE							RES_DISABLED
#define PORT_A_PIN_4_RESISTOR_MODE							RES_DISABLED
#define PORT_A_PIN_5_RESISTOR_MODE							RES_DISABLED
#define PORT_A_PIN_6_RESISTOR_MODE							RES_DISABLED
#define PORT_A_PIN_7_RESISTOR_MODE							RES_DISABLED

#define PORT_B_PIN_0_RESISTOR_MODE							RES_DISABLED
#define PORT_B_PIN_1_RESISTOR_MODE							RES_DISABLED
#define PORT_B_PIN_2_RESISTOR_MODE							RES_DISABLED
#define PORT_B_PIN_3_RESISTOR_MODE							RES_DISABLED
#define PORT_B_PIN_4_RESISTOR_MODE							RES_DISABLED
#define PORT_B_PIN_5_RESISTOR_MODE							RES_DISABLED
#define PORT_B_PIN_6_RESISTOR_MODE							RES_DISABLED
#define PORT_B_PIN_7_RESISTOR_MODE							RES_DISABLED

#define PORT_C_PIN_0_RESISTOR_MODE							RES_DISABLED
#define PORT_C_PIN_1_RESISTOR_MODE							RES_DISABLED
#define PORT_C_PIN_2_RESISTOR_MODE							RES_DISABLED
#define PORT_C_PIN_3_RESISTOR_MODE							RES_DISABLED
#define PORT_C_PIN_4_RESISTOR_MODE							RES_DISABLED
#define PORT_C_PIN_5_RESISTOR_MODE							RES_DISABLED
#define PORT_C_PIN_6_RESISTOR_MODE							RES_DISABLED
#define PORT_C_PIN_7_RESISTOR_MODE							RES_DISABLED

#define PORT_D_PIN_0_RESISTOR_MODE							RES_DISABLED
#define PORT_D_PIN_1_RESISTOR_MODE							RES_DISABLED
#define PORT_D_PIN_2_RESISTOR_MODE							RES_DISABLED
#define PORT_D_PIN_3_RESISTOR_MODE							RES_DISABLED
#define PORT_D_PIN_4_RESISTOR_MODE							RES_DISABLED
#define PORT_D_PIN_5_RESISTOR_MODE							RES_DISABLED
#define PORT_D_PIN_6_RESISTOR_MODE							RES_DISABLED
#define PORT_D_PIN_7_RESISTOR_MODE							RES_DISABLED
/*******************************************************************************************************************************/

#endif /* PORT_CFG_H_ */
