 /********************************************************************************************************************************
 * Module: PORT
 *
 * File Name: PORT.h
 *
 * Description: Header file for PORT Driver
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#ifndef PORT_H_
#define PORT_H_

/*ID for AUTOSAR partner or associate e.g 1000*/
#define PORT_VENDOR_ID                 (1000U)

/*PORT module ID*/
#define PORT_MODULE_ID				  (124U)

/*PORT instance ID*/
#define PORT_INSTANCE_ID				  (0U)

/*Module SW Version (1.0.0)*/

#define PORT_SW_MAJOR_VERSION				(1U)
#define PORT_SW_MINOR_VERSION				(0U)
#define PORT_SW_PATCH_VERSION				(0U)

/*Module AUTOSAR Version (4.0.3)*/

#define PORT_AR_RELEASE_MAJOR_VERSION				(4U)
#define PORT_AR_RELEASE_MINOR_VERSION				(0U)
#define PORT_AR_RELEASE_PATCH_VERSION				(3U)

/*Macros for PORT Status*/

#define PORT_INITIALIZED								(1U)
#define PORT_NOT_INITIALIZED							(0U)

/*Since in AVR mode is enabled by default when enabling module*/
#define PORT_PIN_MODE_UNUSED							((Port_PinModeType)STD_OFF)

/*Standard AUTOSAR Types*/
#include "Std_Types.h"

/*AUTOSAR Checking between Std_Types.h and PORT.h*/
#if ((PORT_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
		||(PORT_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
		||(PORT_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
#error "The AUTOSAR version of Std_Types.h doesn't match the expected version"
#endif

/*PORT Pre-Compile config header file*/
#include "Port_Cfg.h"

/*AUTOSAR Checking between Port_Cfg.h and Port.h*/
#if ((PORT_AR_RELEASE_MAJOR_VERSION != PORT_CFG_AR_RELEASE_MAJOR_VERSION)\
		||(PORT_AR_RELEASE_MINOR_VERSION != PORT_CFG_AR_RELEASE_MINOR_VERSION)\
		||(PORT_AR_RELEASE_PATCH_VERSION != PORT_CFG_AR_RELEASE_PATCH_VERSION))
#error "The AUTOSAR version of Port_Cfg.h doesn't match the expected version"
#endif

/*SW Checking between v.h and Port.h*/
#if ((PORT_SW_MAJOR_VERSION != PORT_CFG_SW_MAJOR_VERSION)\
		||(PORT_SW_MINOR_VERSION != PORT_CFG_SW_MINOR_VERSION)\
		||(PORT_SW_PATCH_VERSION != PORT_CFG_SW_PATCH_VERSION))
#error "The Software version of Port_Cfg.h doesn't match the expected version"
#endif



/*Not an AUTOSAR File therefore no version checking*/
#include "Common_Macros.h"

/*********************************************************************************************************************************
 *                    								  API Service IDs      						                                 *
 ********************************************************************************************************************************/

/*Service ID for Port_Init*/
#define PORT_INIT_SID								(uint8)0x00

/*Service ID for Port_SetPinDirection*/
#define PORT_SET_PIN_DIRECTION_SID					(uint8)0x01

/*Service ID for Port_RefreshPortDirection*/
#define Port_REFRESH_PORT_DIRECTION_SID				(uint8)0x02

/*Service ID for Port_GetVersionInfo*/
#define PORT_GET_VERSION_INFO_SID					(uint8)0x03

/*Service ID for Port_SetPinMode*/
#define PORT_SET_PIN_MODE_SID						(uint8)0x04


/*********************************************************************************************************************************
 *                    								  DET Error Codes     						                                 *
 ********************************************************************************************************************************/
/*Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN						((uint8)0x0A)

/*Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE			((uint8)0x0B)

/*API Port_Init service called with wrong parameter (e.g NULL PTR) */
#define PORT_E_PARAM_CONFIG						((uint8)0x0C)

/*API Port_SetPinMode service called when mode is unchangeable.*/
#define PORT_E_PARAM_INVALID_MODE  				((uint8)0x0D)

/*API Port_SetPinMode service called when mode is unchangeable.*/
#define PORT_E_MODE_UNCHANGEABLE				((uint8)0x0E)

/*API service called without module initialization*/
#define PORT_E_UNINIT 							((uint8)0x0F)

/*APIs called with a Null Pointer*/
#define PORT_E_PARAM_POINTER					((uint8)0x10)



/*********************************************************************************************************************************
 *                    								  Module DataTypes     						                                 *
 ********************************************************************************************************************************/



/*type definition of Port_PinType used by Port APIS*/
typedef uint8 Port_PinType;

/*type definition of Port_PinModeType used by Port APIS*/
typedef uint8 Port_PinModeType;

/*type definition of Port_PinDirectionType used by Port APIS*/
typedef enum{
	/*Sets port pin as input. */
	PORT_PIN_IN,
	/*Sets port pin as output. */
	PORT_PIN_OUT
}Port_PinDirectionType;

/*type definition of Port_PinLevel used by Port APIS*/
typedef enum{
		/*STD_HIGH*/
	 PORT_PIN_LEVEL_LOW = STD_LOW,
	   /*STD_LOW*/
	 PORT_PIN_LEVEL_HIGH = STD_HIGH
}Port_PinLevel;


/*this type s before the Port_ConfigType struct are not in Port Autosar SWS*/


typedef enum{ /*IN_PULLDOWN since no pull down in AVR*/
	RES_DISABLED = 0 , RES_PULLDOWN = 0, RES_PULLUP = 1
}Port_PinResistorMode;

typedef struct{
	/*Set pin direction input or output*/
	Port_PinDirectionType Pin_Direction;
	/*Enable or disable pullup/down resistors*/
	Port_PinResistorMode Pin_ResistorMode;
	/*Set pin initial level STD_LOW or STD_HIGH*/
	Port_PinLevel Pin_InitialLevel;
	/*Number of pin to configure*/
	Port_PinType Pin_Num;
	/*Number of port containing the required pin*/
	uint8 Port_Num;
	/*set pin Mode GPIO, ADC, UART etc*/
	Port_PinModeType Pin_Mode;
	/*Configuration for direction changeability, STD_ON or STD_OFF*/
	uint8 Pin_Direction_Changeable;
	/*Configuration for Mode changeability, STD_ON or STD_OFF*/
	uint8 Pin_Mode_Changeable;

}Port_ConfigPin;


/*Structure for initialing Port Driver*/
typedef struct{
	/*array of 32 structures of type Port_ConfigPin to initialize each pin*/
	Port_ConfigPin Pin_Config[NUMBER_OF_PORT_PINS];
}Port_ConfigType;



/*********************************************************************************************************************************
 *                    								  Function Prototypes     						                                 *
 ********************************************************************************************************************************/
/*Function for Port_Init API*/
void Port_Init(
 const Port_ConfigType* ConfigPtr
);

#if (PORT_SET_PIN_DIRECTION_API == TRUE)
/*Function for Port_SetPinDirection API*/
void Port_SetPinDirection(
 Port_PinType Pin,
 Port_PinDirectionType Direction
);
#endif

/*Function for Port_RefreshPortDirection API*/
void Port_RefreshPortDirection(
 void
);


/*Function for Port_GetVersionInfo API*/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(
 Std_VersionInfoType* versioninfo
);
#endif

/*Function for Port_SetPinMode API*/
#if (PORT_SET_PIN_MODE_API == TRUE)
void Port_SetPinMode(
 Port_PinType Pin,
 Port_PinModeType Mode
);
#endif



/*********************************************************************************************************************************
*            								           External Variables                						                 *
 ********************************************************************************************************************************/
/*Port Post-build config header file*/
#include "Port_PBcfg.h"


#endif /* PORT_H_ */
