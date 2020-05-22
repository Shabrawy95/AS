 /********************************************************************************************************************************
 * Module: DIO
 *
 * File Name: DIO.C
 *
 * Description: Source file for DIO Module
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/
#include "Dio.h"
#include "Dio_Regs.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)
#include"Det.h"
/*AUTOSAR Version check between Det.h and Dio Module*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)\
		||(DIO_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION)\
		||(DIO_AR_RELEASE_PATCH_VERSION != DET_AR_RELEASE_PATCH_VERSION))
#error "The AUTOSAR version of Det.h doesn't match the expected version"
#endif
#endif

STATIC Dio_ConfigChannel* Dio_PortChannels= NULL_PTR;

STATIC Dio_ChannelGroupType*  Dio_ChannelGroups= NULL_PTR;

STATIC Dio_PortType* Dio_Ports= NULL_PTR;

STATIC uint8 Dio_Status = DIO_NOT_INITIALIZED;

/*********************************************************************************************************************************
* Service Name: Dio_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Dio module.
*********************************************************************************************************************************/
void Dio_Init(
 const Dio_ConfigType* ConfigPtr
){
	#if (DIO_DEV_ERROR_DETECT == STD_ON)
		/*Check if input configuration pointer is not null pointer*/
		if(NULL_PTR == ConfigPtr){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID, DIO_E_PARAM_CONFIG);
		}else
	#endif
		{
			/*Set module state to initialized*/
			Dio_Status = DIO_INITIALIZED;

			/*Below pointers are global variables to be used in other functions*/
			/*point to first element of the array of Dio_ConfigChannel(&channels[0]) structs */
			Dio_PortChannels = ConfigPtr->channels;

			/*point to first element of the array of Dio_ChannelGroupType(&channelGroup[0]) structs */
			Dio_ChannelGroups = ConfigPtr->channelGroup;

			/*point to first element of the array of Dio_PortType(&ports[0]) */
			Dio_Ports = ConfigPtr->ports;
		}
}


/*********************************************************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType-> STD_HIGH The physical level of the corresponding Pin is
				STD_HIGH
				STD_LOW The physical level of the corresponding Pin is
				STD_LOW
* Description: Returns the value of the specified DIO channel.
*********************************************************************************************************************************/
Dio_LevelType Dio_ReadChannel(
 Dio_ChannelType ChannelId
){
	boolean error = FALSE;
	Dio_PortLevelType* Pin_Ptr = NULL_PTR;
	Dio_LevelType Output = STD_LOW;
	#if (DIO_DEV_ERROR_DETECT == STD_ON)
		/*Check if driver is initialized before using this API*/
		if(DIO_NOT_INITIALIZED == Dio_Status){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_READ_CHANNEL_SID, DIO_E_UNINIT);
			error = TRUE;
		}else{
			/*No action required*/
		}
		/*check if channel ID is withing valid channel range*/
		if(DIO_CONFIGURED_CHANNELS <= ChannelId){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_READ_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
			error = TRUE;
		}else{
			/*No Action Required*/
		}
	#endif
		/*in case there are no erros*/
		/*point to correct port and pin registers according to pord id stored in port_num member*/
		if(FALSE == error){
			switch(Dio_PortChannels[ChannelId].Port_Num){
				case 0: Pin_Ptr = (Dio_PortLevelType*)&PINA_REG;
						break;
				case 1: Pin_Ptr = (Dio_PortLevelType*)&PINB_REG;
						break;
				case 2: Pin_Ptr = (Dio_PortLevelType*)&PINC_REG;
						break;
				case 3: Pin_Ptr = (Dio_PortLevelType*)&PIND_REG;
						break;

			}
			/*read required channel*/
			if(BIT_IS_SET(*Pin_Ptr, Dio_PortChannels[ChannelId].Ch_Num)){
				Output = STD_HIGH;
			}else{
				Output = STD_LOW;
			}
			return Output;

		}else{
			/*No Action Required*/
		}
}

/*********************************************************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel
* 				   Level -  Value to be written
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Service to set a level of a channel.
*********************************************************************************************************************************/
void Dio_WriteChannel(
 Dio_ChannelType ChannelId,
 Dio_LevelType Level
){
	boolean error = FALSE;
	Dio_PortLevelType* Port_Ptr = NULL_PTR;
	#if (DIO_DEV_ERROR_DETECT == STD_ON)
		/*Check if driver is initialized before using this API*/
		if(DIO_NOT_INITIALIZED == Dio_Status){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_WRITE_CHANNEL_SID, DIO_E_UNINIT);
			error = TRUE;
		}else{
			/*No action required*/
		}
		/*check if channel ID is withing valid channel range*/
		if(DIO_CONFIGURED_CHANNELS <= ChannelId){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
			error = TRUE;
		}else{
			/*No Action Required*/
		}
	#endif
		/*If there are no erros*/
		if(FALSE == error){
			/*Point to correct port register according to port_num member*/
			switch (Dio_PortChannels[ChannelId].Port_Num){
					case 0: Port_Ptr = (Dio_PortLevelType*)&PORTA_REG;
						break;
					case 1: Port_Ptr = (Dio_PortLevelType*)&PORTB_REG;
						break;
					case 2: Port_Ptr = (Dio_PortLevelType*)&PORTC_REG;
						break;
					case 3: Port_Ptr = (Dio_PortLevelType*)&PORTD_REG;
						break;
			}

			if(Level == STD_HIGH){
				/*write logic high*/
				SET_BIT(*Port_Ptr, Dio_PortChannels[ChannelId].Ch_Num);

			}else if(Level == STD_LOW){

				/*write logic low*/
				CLEAR_BIT(*Port_Ptr, Dio_PortChannels[ChannelId].Ch_Num);

			}

		}else{
			/*No action required*/
		}
}

/*********************************************************************************************************************************
* Service Name: Dio_ReadPort
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO Port
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType - Level of all channels of that port
* Description: Returns the level of all channels of that port.
*********************************************************************************************************************************/
Dio_PortLevelType Dio_ReadPort(
 Dio_PortType PortId
){
	boolean error = FALSE;
	Dio_PortLevelType* Pin_Ptr = NULL_PTR;
	Dio_PortLevelType Output = STD_LOW; /*0x00*/
		#if (DIO_DEV_ERROR_DETECT == STD_ON)
		/*Check if driver is initialized before using this API*/
		if(DIO_NOT_INITIALIZED == Dio_Status){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_READ_PORT_SID, DIO_E_UNINIT);
			error = TRUE;
		}else{
			/*No action required*/
		}
		/*check if channel ID is withing valid channel range*/
		if(DIO_CONFIGURED_PORTS <= PortId){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_READ_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
			error = TRUE;
		}else{
			/*No Action Required*/
		}
	#endif
		/*If there are no errors*/
		if(FALSE == error){
			switch(Dio_Ports[PortId]){
				case 0: Pin_Ptr = (Dio_PortLevelType*)&PINA_REG;
						break;
				case 1: Pin_Ptr = (Dio_PortLevelType*)&PINB_REG;
						break;
				case 2: Pin_Ptr = (Dio_PortLevelType*)&PINC_REG;
						break;
				case 3: Pin_Ptr = (Dio_PortLevelType*)&PIND_REG;
						break;
			}
			Output = GET_REG(*Pin_Ptr);
			return Output;
		}else{
			/*No action required*/
		}
}

/*********************************************************************************************************************************
* Service Name: Dio_WritePort
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): PortId - ID of DIO Port
 	 	 	 	 Level - Value to be written
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Service to set the Value of a Port.
*********************************************************************************************************************************/
void Dio_WritePort(
 Dio_PortType PortId,
 Dio_PortLevelType Level
){
	boolean error = FALSE;
		Dio_PortLevelType* Port_Ptr = NULL_PTR;

	#if (DIO_DEV_ERROR_DETECT == STD_ON)
		/*Check if driver is initialized before using this API*/
		if(DIO_NOT_INITIALIZED == Dio_Status){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_WRITE_PORT_SID, DIO_E_UNINIT);
			error = TRUE;
		}else{
			/*No action required*/
		}
		/*check if channel ID is withing valid channel range*/
		if(DIO_CONFIGURED_PORTS <= PortId){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
			error = TRUE;
		}else{
			/*No Action Required*/
		}
	#endif
		/*If there are no errors*/
		if(FALSE == error){
			switch(Dio_Ports[PortId]){
				case 0: Port_Ptr = (Dio_PortLevelType*)&PORTA_REG;
						break;
				case 1: Port_Ptr = (Dio_PortLevelType*)&PORTB_REG;
						break;
				case 2: Port_Ptr = (Dio_PortLevelType*)&PORTC_REG;
						break;
				case 3: Port_Ptr = (Dio_PortLevelType*)&PORTD_REG;
						break;
			}
			SET_REG_VAL(*Port_Ptr, Level);
		}else{
			/*No action required*/
		}
}

/*********************************************************************************************************************************
* Service Name: Dio_ReadChannelGroup
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelGroupIdPtr - Pointer to ChannelGroup
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_PortLevelType Level of a subset of the adjoining bits of a port
* Description: This Service reads a subset of the adjoining bits of a port.
*********************************************************************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup(
 const Dio_ChannelGroupType* ChannelGroupIdPtr
){
	boolean error = FALSE;
	Dio_PortLevelType* Pin_Ptr = NULL_PTR;
	Dio_PortLevelType Output = STD_LOW; /*0x00*/
		#if (DIO_DEV_ERROR_DETECT == STD_ON)

		/*check if passed pointer is null*/
		if(NULL_PTR == ChannelGroupIdPtr){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_POINTER);
			error = TRUE;
		}else{
			/*No action required*/
		}
		/*Check if driver is initialized before using this API*/
		if(DIO_NOT_INITIALIZED == Dio_Status){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_READ_CHANNEL_GROUP_SID, DIO_E_UNINIT);
			error = TRUE;
		}else{
			/*No action required*/
		}
		/*check if channel group struct is within valid range for array of channel group structs in config*/
		if(&Dio_ChannelGroups[DIO_CONFIGURED_GROUPS] <= ChannelGroupIdPtr){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP);
			error = TRUE;
		}else{
			/*No Action Required*/
		}
	#endif
		/*If there are no errors*/
		if(FALSE == error){
			/*get port num of channel group, index is difference between sent pointer and name of array which is the
			 * first element*/
			switch(ChannelGroupIdPtr->port){
				case 0: Pin_Ptr = (Dio_PortLevelType*)&PINA_REG;
						break;
				case 1: Pin_Ptr = (Dio_PortLevelType*)&PINB_REG;
						break;
				case 2: Pin_Ptr = (Dio_PortLevelType*)&PINC_REG;
						break;
				case 3: Pin_Ptr = (Dio_PortLevelType*)&PIND_REG;
						break;
			}
			/*set channel group to the level parameter sent to function*/
			Output = GET_CH_GROUP(*Pin_Ptr, ChannelGroupIdPtr->mask, ChannelGroupIdPtr->offset);
			return Output;
		}else{
			/*No action required*/
		}
}


/*********************************************************************************************************************************
* Service Name: Dio_WriteChannelGroup
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelGroupIdPtr - Pointer to ChannelGroup
				   Level - Value to be written
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Service to set a subset of the adjoining bits of a port to a specified level.
*********************************************************************************************************************************/
void Dio_WriteChannelGroup(
 const Dio_ChannelGroupType* ChannelGroupIdPtr,
 Dio_PortLevelType Level
){
	boolean error = FALSE;
	Dio_PortLevelType* Port_Ptr = NULL_PTR;
		#if (DIO_DEV_ERROR_DETECT == STD_ON)

		/*Check if driver is initialized before using this API*/
		if(DIO_NOT_INITIALIZED == Dio_Status){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_WRITE_CHANNEL_GROUP_SID, DIO_E_UNINIT);
			error = TRUE;
		}else{
			/*No action required*/
		}
		/*check if passed pointer is null*/
		if(NULL_PTR == ChannelGroupIdPtr){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_POINTER);
			error = TRUE;
		}else{
			/*No action required*/
		}

		/*check if channel group struct is within valid range for array of channel group structs in config*/
		if(&Dio_ChannelGroups[DIO_CONFIGURED_GROUPS] <= ChannelGroupIdPtr){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_INVALID_GROUP);
			error = TRUE;
		}else{
			/*No Action Required*/
		}
	#endif
		/*If there are no errors*/
		if(FALSE == error){
			/*get port num of channel group, index is difference between sent pointer and name of array which is the
			 * first element*/
			switch(ChannelGroupIdPtr->port){
				case 0: Port_Ptr = (Dio_PortLevelType*)&PORTA_REG;
						break;
				case 1: Port_Ptr = (Dio_PortLevelType*)&PORTB_REG;
						break;
				case 2: Port_Ptr = (Dio_PortLevelType*)&PORTC_REG;
						break;
				case 3: Port_Ptr = (Dio_PortLevelType*)&PORTD_REG;
						break;
			}
			SET_CH_GROUP(*Port_Ptr, ChannelGroupIdPtr->mask, ChannelGroupIdPtr->offset, Level);

		}else{
			/*No action required*/
		}
}


/*********************************************************************************************************************************
* Service Name: Dio_GetVersionInfo
* Service ID[hex]: 0x12
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Nonea
* Parameters (inout): None
* Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: VersionInfo Pointer to where to store the version information of this module.
*********************************************************************************************************************************/
#if  (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(
 Std_VersionInfoType* VersionInfo
){
	#if (DIO_DEV_ERROR_DETECT == STD_ON)
		if( NULL_PTR == VersionInfo){
			Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, Dio_GET_VERSION_INFO_SID, DIO_E_PARAM_POINTER);
		}else
	#endif
		{
			/*Copy Vendor ID*/
			VersionInfo->VendorID = (uint16)DIO_VENDOR_ID;
			/*Copy Module ID*/
			VersionInfo->moduleID = (uint16)DIO_MODULE_ID;
			/*Copy SW Major Version*/
			VersionInfo->sw_major_version = (uint8)DIO_SW_MAJOR_VERSION;
			/*Copy SW Minor Version*/
			VersionInfo->sw_minor_version = (uint8)DIO_SW_MINOR_VERSION;
			/*Copy Software Patch*/
			VersionInfo->sw_patch_version = (uint8)DIO_SW_PATCH_VERSION;

		}
}
#endif

/*********************************************************************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x11
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType - STD_HIGH: The physical level of the corresponding Pin is
							   STD_HIGH.
							   STD_LOW: The physical level of the corresponding Pin is
							   STD_LOW.
* Description: Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return
the level of the channel after flip.
*********************************************************************************************************************************/
#if (DIO_FLIP_CHANNEL_API == STD_ON)
Dio_LevelType Dio_FlipChannel(
 Dio_ChannelType ChannelId
){
	boolean error = FALSE;
	Dio_PortLevelType* Port_Ptr = NULL_PTR;
	Dio_PortLevelType* Pin_Ptr = NULL_PTR;
	Dio_LevelType Output = STD_LOW;
	#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/*Check if driver is initialized before using this API*/
	if(DIO_NOT_INITIALIZED == Dio_Status){
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_FLIP_CHANNEL_SID, DIO_E_UNINIT);
		error = TRUE;
	}else{
		/*No action required*/
	}
	/*check if channel ID is withing valid channel range*/
	if(DIO_CONFIGURED_CHANNELS <= ChannelId){
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_FLIP_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
		error = TRUE;
	}else{
		/*No Action Required*/
	}
	#endif
	/*If there are no errors*/
	if(FALSE == error){
		/*Point to correct pin and port registers according to port_num member*/
		switch (Dio_PortChannels[ChannelId].Port_Num){
				case 0:
						Pin_Ptr = (Dio_PortLevelType*)&PINA_REG;
						Port_Ptr = (Dio_PortLevelType*)&PORTA_REG;
						break;
				case 1:
						Pin_Ptr = (Dio_PortLevelType*)&PINB_REG;
						Port_Ptr = (Dio_PortLevelType*)&PORTB_REG;
						break;
				case 2:
						Pin_Ptr = (Dio_PortLevelType*)&PINC_REG;
						Port_Ptr = (Dio_PortLevelType*)&PORTC_REG;
						break;
				case 3:
						Pin_Ptr = (Dio_PortLevelType*)&PIND_REG;
						Port_Ptr = (Dio_PortLevelType*)&PORTD_REG;
						break;
		}
		/*read required channel then flip the level and return output after flipping*/
		if(BIT_IS_SET(*Pin_Ptr, Dio_PortChannels[ChannelId].Ch_Num)){
			CLEAR_BIT(*Port_Ptr, Dio_PortChannels[ChannelId].Ch_Num);
			Output = STD_LOW;
		}else{
			SET_BIT(*Port_Ptr, Dio_PortChannels[ChannelId].Ch_Num);
			Output = STD_HIGH;
		}
		return Output;

	}else{
		/*No action required*/
	}
}
#endif
