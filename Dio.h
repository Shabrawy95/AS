 /********************************************************************************************************************************
 * Module: DIO
 *
 * File Name: DIO.h
 *
 * Description: Header file for DIO Module
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#ifndef DIO_H_
#define DIO_H_

/*ID for AUTOSAR partner or associate e.g 1000*/
#define DIO_VENDOR_ID                 (1000U)

/*DIO module ID*/
#define DIO_MODULE_ID				  (120U)

/*DIO instance ID*/
#define DIO_INSTANCE_ID				  (0U)

/*Module SW Version (1.0.0)*/

#define DIO_SW_MAJOR_VERSION				(1U)
#define DIO_SW_MINOR_VERSION				(0U)
#define DIO_SW_PATCH_VERSION				(0U)

/*Module AUTOSAR Version (4.0.3)*/

#define DIO_AR_RELEASE_MAJOR_VERSION				(4U)
#define DIO_AR_RELEASE_MINOR_VERSION				(0U)
#define DIO_AR_RELEASE_PATCH_VERSION				(3U)

/*Macros for DIO Status*/

#define DIO_INITIALIZED								(1U)
#define DIO_NOT_INITIALIZED							(0U)

/*Standard AUTOSAR Types*/
#include "Std_Types.h"

/*AUTOSAR Checking between Std_Types.h and DIO.h*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
		||(DIO_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
		||(DIO_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
#error "The AUTOSAR version of Std_Types.h doesn't match the expected version"
#endif

/*DIO Pre-Compile config header file*/
#include "DIO_Cfg.h"

/*AUTOSAR Checking between Dio_Cfg.h and DIO.h*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION != DIO_CFG_AR_RELEASE_MAJOR_VERSION)\
		||(DIO_AR_RELEASE_MINOR_VERSION != DIO_CFG_AR_RELEASE_MINOR_VERSION)\
		||(DIO_AR_RELEASE_PATCH_VERSION != DIO_CFG_AR_RELEASE_PATCH_VERSION))
#error "The AUTOSAR version of Dio_Cfg.h doesn't match the expected version"
#endif

/*SW Checking between Dio_Cfg.h and DIO.h*/
#if ((DIO_SW_MAJOR_VERSION != DIO_CFG_SW_MAJOR_VERSION)\
		||(DIO_SW_MINOR_VERSION != DIO_CFG_SW_MINOR_VERSION)\
		||(DIO_SW_PATCH_VERSION != DIO_CFG_SW_PATCH_VERSION))
#error "The Software version of Dio_Cfg.h doesn't match the expected version"
#endif



/*Not an AUTOSAR File therefore no version checking*/
#include "Common_Macros.h"

/*********************************************************************************************************************************
 *                    								  API Service IDs      						                                 *
 ********************************************************************************************************************************/

/*Service ID for DIO_ReadChannel*/
#define Dio_READ_CHANNEL_SID					(uint8)0x00

/*Service ID for Dio_WriteChannel*/
#define Dio_WRITE_CHANNEL_SID				(uint8)0x01

/*Service ID for Dio_ReadPort*/
#define Dio_READ_PORT_SID					(uint8)0x02

/*Service ID for Dio_WritePort*/
#define Dio_WRITE_PORT_SID					(uint8)0x03

/*Service ID for Dio_ReadChannelGroup*/
#define Dio_READ_CHANNEL_GROUP_SID			(uint8)0x04

/*Service ID for Dio_WriteChannelGroup*/
#define Dio_WRITE_CHANNEL_GROUP_SID			(uint8)0x05

/*Service ID for Dio_GetVersionInfo*/
#define Dio_GET_VERSION_INFO_SID				(uint8)0x12

/*Service ID for Dio_Init*/
#define DIO_INIT_SID						(uint8)0x10

/*Service ID for Dio_FlipChannel*/
#define DIO_FLIP_CHANNEL_SID					(uint8)0x11


/*********************************************************************************************************************************
 *                    								  DET Error Codes     						                                 *
 ********************************************************************************************************************************/
/*Error code to report Invalid Channel to DET Module*/
#define DIO_E_PARAM_INVALID_CHANNEL_ID		(uint8)0x0A

/*Error code to report Null pointer call to DIO_Init to DET Module*/
#define DIO_E_PARAM_CONFIG					(uint8)0x10

/*Error code to report Invalid Port to DET Module*/
#define DIO_E_PARAM_INVALID_PORT_ID			(uint8)0x14

/*Error code to report Invalid Channel Group to DET Module*/
#define DIO_E_PARAM_INVALID_GROUP			(uint8)0x1F

/*API service shall return immediately after reporting this error*/
#define DIO_E_PARAM_POINTER					(uint8)0x20

/*API service used without module initialization is reported using this ERROR
 * not in AUTOSAR 4.0.3 SWS*/
#define DIO_E_UNINIT						(uint8)0xF0

/*********************************************************************************************************************************
 *                    								  Module DataTypes     						                                 *
 ********************************************************************************************************************************/

/*type definition of Dio_ChannelType used by DIO APIS*/
typedef uint8 Dio_ChannelType;

/*type definition of Dio_PortType used by DIO APIS*/
typedef uint8 Dio_PortType;

/*type definition of Dio_LevelType used by DIO APIS*/
typedef uint8 Dio_LevelType;

/*type definition of Dio_PortLevelType used by DIO APIS*/
typedef uint8 Dio_PortLevelType;

/*Structure for Dio_ChannelGroup*/
typedef struct{
	/*Mask which defines the position of the channel group*/
	uint8 mask;

	/*the position of the channel group form LSB*/
	uint8 offset;

	/*Port ID where the channel group is defined*/
	Dio_PortType port;
}Dio_ChannelGroupType;


typedef struct{
	/*Member contains the ID of Port where the channel belongs*/
	Dio_PortType Port_Num;

	/*ID of the channel within the port*/
	Dio_ChannelType Ch_Num;
}Dio_ConfigChannel;


/*Data Structure for Initializing the DIO Driver*/
typedef struct{
	/*Array of structs of type DIO_ConfigChannel, the array size is the number of Configured Channels in the app*/
	Dio_ConfigChannel channels[DIO_CONFIGURED_CHANNELS];

	/*Array of structs of type Dio_ChannelGroupType, the array size is the number of Configured ChannelGroups in the app*/
	Dio_ChannelGroupType channelGroup[DIO_CONFIGURED_GROUPS];

	/*Array of structs of type Dio_PortType, the array size is the number of Configured Ports in the app*/
	Dio_PortType ports[DIO_CONFIGURED_PORTS];


}Dio_ConfigType;



/*********************************************************************************************************************************
 *                    								  Function Prototypes     						                                 *
 ********************************************************************************************************************************/
/*Function for Dio_Init API*/
void Dio_Init(
 const Dio_ConfigType* ConfigPtr
);

/*Function for Dio_ReadChannel API*/
Dio_LevelType Dio_ReadChannel(
 Dio_ChannelType ChannelId
);

/*Function for Dio_WriteChannel API*/
void Dio_WriteChannel(
 Dio_ChannelType ChannelId,
 Dio_LevelType Level
);

/*Function for Dio_ReadPort API*/
Dio_PortLevelType Dio_ReadPort(
 Dio_PortType PortId
);

/*Function for Dio_WritePort API*/
void Dio_WritePort(
 Dio_PortType PortId,
 Dio_PortLevelType Level
);

/*Function for Dio_ReadChannelGroup API*/
Dio_PortLevelType Dio_ReadChannelGroup(
 const Dio_ChannelGroupType* ChannelGroupIdPtr
);


/*Function for Dio_WriteChannelGroup API*/
void Dio_WriteChannelGroup(
 const Dio_ChannelGroupType* ChannelGroupIdPtr,
 Dio_PortLevelType Level
);


#if  (DIO_VERSION_INFO_API == STD_ON)
/*Function for Dio_GetVersionInfo API*/
void Dio_GetVersionInfo(
 Std_VersionInfoType* VersionInfo
);
#endif

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/*Function for DIO_FlipChannel API*/
Dio_LevelType Dio_FlipChannel(
 Dio_ChannelType ChannelId
);
#endif

/*********************************************************************************************************************************
*            								           External Variables                						                 *
 ********************************************************************************************************************************/
/*DIO Post-build config header file*/
#include "Dio_PBcfg.h"


#endif /* DIO_H_ */
