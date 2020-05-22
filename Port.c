 /********************************************************************************************************************************
 * Module: Port
 *
 * File Name: Port.C
 *
 * Description: Source file for Port Driver
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/
#include "Port.h"
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)
#include"Det.h"
/*AUTOSAR Version check between Det.h and Port Driver*/
#if ((PORT_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)\
		||(PORT_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION)\
		||(PORT_AR_RELEASE_PATCH_VERSION != DET_AR_RELEASE_PATCH_VERSION))
#error "The AUTOSAR version of Det.h doesn't match the expected version"
#endif
#endif

/*to point to each struct in array of Port_ConfigPin structs*/
STATIC Port_ConfigPin* Port_Pin= NULL_PTR;

STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

/*********************************************************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port module.
*********************************************************************************************************************************/
void Port_Init(
 const Port_ConfigType* ConfigPtr
) {
	Port_PinType i = 0;
	uint8 *Port_Ptr = NULL_PTR;
	uint8 *DDR_Ptr = NULL_PTR;

	#if (PORT_DEV_ERROR_DETECT == STD_ON)
		if(NULL_PTR == ConfigPtr){
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
		}
		else
	#endif
		{
			/*Set driver state to initialized*/
			Port_Status = PORT_INITIALIZED;

			/*Below pointers is global variable to be used in other functions*/
			/*point to first element of the array of Port_ConfigPin(&Pin_Config[0]) structs */
			Port_Pin = ConfigPtr->Pin_Config;

			for(i = 0; i < NUMBER_OF_PORT_PINS; i++){
				switch(Port_Pin[i].Port_Num){
						case 0: DDR_Ptr = (uint8*)&DDRA_REG;
								Port_Ptr = (uint8*)&PORTA_REG;
								break;
						case 1: DDR_Ptr = (uint8*)&DDRB_REG;
								Port_Ptr = (uint8*)&PORTB_REG;
								break;
						case 2: DDR_Ptr = (uint8*)&DDRC_REG;
								Port_Ptr = (uint8*)&PORTC_REG;
								break;
						case 3: DDR_Ptr = (uint8*)&DDRD_REG;
								Port_Ptr = (uint8*)&PORTD_REG;
								break;
				}
				/*check on pin direction */
				if(PORT_PIN_IN == Port_Pin[i].Pin_Direction){

					/*Set bit in DDR register i.e for input mode*/

					CLEAR_BIT(*DDR_Ptr, Port_Pin[i].Pin_Num);

					if(RES_DISABLED != Port_Pin[i].Pin_ResistorMode){

						/*Enable pull up resistor*/
						SET_BIT(*Port_Ptr, Port_Pin[i].Pin_Num);
					}
					else
					{
						/*No action required*/
					}

				}
				else if(PORT_PIN_OUT == Port_Pin[i].Pin_Direction )
				{

					/*Set bit in DDR register i.e for output mode*/

					SET_BIT(*DDR_Ptr, Port_Pin[i].Pin_Num);

					/*put initial value on port pin if output*/

					SET_BIT_VAL(*Port_Ptr, Port_Pin[i].Pin_Num, Port_Pin[i].Pin_InitialLevel);

				}
				else
				{
					/*No action required*/
				}
			}
		}
}


/*********************************************************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): 1- Pin - Port Pin ID number
* 				   2- Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction (During Runtime).
*********************************************************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == TRUE)
void Port_SetPinDirection(
 Port_PinType Pin,
 Port_PinDirectionType Direction
){
	uint8 *DDR_Ptr = NULL_PTR;
	boolean error = FALSE;
	#if (PORT_DEV_ERROR_DETECT == STD_ON)

		if(PORT_NOT_INITIALIZED == Port_Status){
			/*driver is not initialized*/
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
			error = TRUE;

		}
		else
		{
			/*No action required*/
		}
		if(NUMBER_OF_PORT_PINS <= Pin){

			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
			error = TRUE;

		}
		else
		{
			/*No action required*/
		}
		/*parameter pin is index of pin config in aray of structs*/
		if(FALSE == Port_Pin[Pin].Pin_Direction_Changeable){

			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
			error = TRUE;

		}
		else
		{
			/*no action required*/
		}

	#endif

		/*If there are no errors*/
		if(FALSE == error){
			switch(Port_Pin[Pin].Port_Num){
					case 0: DDR_Ptr = (uint8*)&DDRA_REG;
							break;
					case 1: DDR_Ptr = (uint8*)&DDRB_REG;
							break;
					case 2: DDR_Ptr = (uint8*)&DDRC_REG;
							break;
					case 3: DDR_Ptr = (uint8*)&DDRD_REG;
							break;
			}
			if(PORT_PIN_IN == Direction){

				/*Set bit in DDR register i.e for input mode*/

				CLEAR_BIT(*DDR_Ptr, Port_Pin[Pin].Pin_Num);

			}
			else
			{

				/*Set bit in DDR register i.e for output mode*/

				SET_BIT(*DDR_Ptr, Port_Pin[Pin].Pin_Num);
			}
		}
		else
		{
			/*No action required*/
		}

}
#endif
/*********************************************************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): Non
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Service to Refresh port direction.
*********************************************************************************************************************************/
void Port_RefreshPortDirection(
 void
){

	Port_PinType i = 0;
	boolean error = FALSE;
	uint8 *DDR_Ptr = NULL_PTR;
	#if (PORT_DEV_ERROR_DETECT == STD_ON)

		if(PORT_NOT_INITIALIZED == Port_Status){
			/*driver is not initialized*/
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
			error = TRUE;

		}else{
			/*No action required*/
		}
	#endif
		if(FALSE == error){
			for(i = 0; i < NUMBER_OF_PORT_PINS; i++){

				/*refresh port pins to configured direction,
				 *  exclude those port pins from refreshing that are configured
				 *  as ‘pin direction changeable during runtime‘*/

				if(FALSE == Port_Pin[i].Pin_Direction_Changeable){

					switch(Port_Pin[i].Port_Num){
							case 0: DDR_Ptr = (uint8*)&DDRA_REG;
									break;
							case 1: DDR_Ptr = (uint8*)&DDRB_REG;
									break;
							case 2: DDR_Ptr = (uint8*)&DDRC_REG;
									break;
							case 3: DDR_Ptr = (uint8*)&DDRD_REG;
									break;
					}

					/*check on pin direction */
					if(PORT_PIN_IN == Port_Pin[i].Pin_Direction){

						/*Reresh Pin in DDR register i.e for input mode*/

						CLEAR_BIT(*DDR_Ptr, Port_Pin[i].Pin_Num);


					}
					else if(PORT_PIN_OUT == Port_Pin[i].Pin_Direction )
					{

						/*Refresh Pin in DDR register i.e for output mode*/

						SET_BIT(*DDR_Ptr, Port_Pin[i].Pin_Num);

					}
					else
					{
						/*No action required*/
					}


				}
				else
				{
					/*No action Required*/
				}
			}
		}
		else{
			/*No action Required*/
		}
}

/*********************************************************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Returns the version information of this module.
*********************************************************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(
 Std_VersionInfoType* versioninfo
){

	#if (PORT_DEV_ERROR_DETECT == STD_ON)

	if(PORT_NOT_INITIALIZED == Port_Status){
		/*driver is not initialized*/
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_UNINIT);

	}else{
		/*No action required*/
	}
		if(NULL_PTR == versioninfo)
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
		}
		else
	#endif
		{
			/*Copy Vendor ID*/
			versioninfo->VendorID = (uint16)PORT_VENDOR_ID;
			/*Copy Module ID*/
			versioninfo->moduleID = (uint16)PORT_MODULE_ID;
			/*Copy SW Major Version*/
			versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
			/*Copy SW Minor Version*/
			versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
			/*Copy Software Patch*/
			versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;

		}

}
#endif
/*********************************************************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): 1- Pin - Port Pin ID number
 	 	 	 	   2- Mode - New Port Pin mode to be set on port pin.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Service to set port pin mode (During Runtime)
*********************************************************************************************************************************/
#if (PORT_SET_PIN_MODE_API == TRUE)
void Port_SetPinMode(
 Port_PinType Pin,
 Port_PinModeType Mode
){
	boolean error = FALSE;
	#if (PORT_DEV_ERROR_DETECT == STD_ON)

		if(PORT_NOT_INITIALIZED == Port_Status){
			/*driver is not initialized*/
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
			error = TRUE;

		}
		else
		{
			/*No action required*/
		}
		if(NUMBER_OF_PORT_PINS <= Pin){

			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
			error = TRUE;

		}
		else
		{
			/*No action required*/
		}
		/*parameter pin is index of pin config in aray of structs*/
		if(FALSE == Port_Pin[Pin].Pin_Mode_Changeable){

			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
			error = TRUE;

		}
		else
		{
			/*no action required*/
		}

		/*parameter pin is index of pin config in aray of structs
		 *
		 * return error if another value is sent since mode is unused on AVR*/
		if(PORT_PIN_MODE_UNUSED != Port_Pin[Pin].Pin_Mode){

			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
			error = TRUE;

		}
		else
		{
			/*no action required*/
		}

	#endif

}
#endif
