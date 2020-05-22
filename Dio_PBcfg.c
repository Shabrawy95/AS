 /********************************************************************************************************************************
 * Module:
 *
 * File Name:
 *
 * Description:
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/


/*Module SW Version (1.0.0)*/

#define DIO_PBCFG_SW_MAJOR_VERSION				(1U)
#define DIO_PBCFG_SW_MINOR_VERSION				(0U)
#define DIO_PBCFG_SW_PATCH_VERSION				(0U)

/*Module AUTOSAR Version (4.0.3)*/

#define DIO_PBCFG_AR_RELEASE_MAJOR_VERSION				(4U)
#define DIO_PBCFG_AR_RELEASE_MINOR_VERSION				(0U)
#define DIO_PBCFG_AR_RELEASE_PATCH_VERSION				(3U)


#include"Dio.h"

/*AUTOSAR Checking between DIO_PBcfg.h and DIO.h*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION != DIO_PBCFG_AR_RELEASE_MAJOR_VERSION)\
		||(DIO_AR_RELEASE_MINOR_VERSION != DIO_PBCFG_AR_RELEASE_MINOR_VERSION)\
		||(DIO_AR_RELEASE_PATCH_VERSION != DIO_PBCFG_AR_RELEASE_PATCH_VERSION))
#error "The AUTOSAR version of DIO_PBcfg.h doesn't match the expected version"
#endif

/*SW Checking between DIO_PBcfg.h and DIO.h*/
#if ((DIO_SW_MAJOR_VERSION != DIO_PBCFG_SW_MAJOR_VERSION)\
		||(DIO_SW_MINOR_VERSION != DIO_PBCFG_SW_MINOR_VERSION)\
		||(DIO_SW_PATCH_VERSION != DIO_PBCFG_SW_PATCH_VERSION))
#error "The Software version of DIO_PBcfg.h doesn't match the expected version"
#endif

/*Post_Build Struct used with Dio_Init API*/

const Dio_ConfigType Dio_Configuration = {
										   /*array of 4 Dio_ConfigChannel structs*/
										  {
											  {DIOConf_LED_PORT_NUM, DIOConf_LED_CHANNEL_NUM},
											  {DIOConf_BUTTON_PORT_NUM, DIOConf_BUTTON_CHANNEL_NUM},
											},

										  };

