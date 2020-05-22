 /********************************************************************************************************************************
 * Module: DIO
 *
 * File Name: DIO_Cfg.h
 *
 *
 * Description: Pre-Compile configuration header for DIO module
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#ifndef DIO_CFG_H_
#define DIO_CFG_H_



/*Module SW Version (1.0.0)*/

#define DIO_CFG_SW_MAJOR_VERSION				(1U)
#define DIO_CFG_SW_MINOR_VERSION				(0U)
#define DIO_CFG_SW_PATCH_VERSION				(0U)

/*Module AUTOSAR Version (4.0.3)*/

#define DIO_CFG_AR_RELEASE_MAJOR_VERSION				(4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION				(0U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION				(3U)

/*Pre-compile option for development error detection*/
#define DIO_DEV_ERROR_DETECT					(STD_ON)

/*Pre-compile option for DIO_Flip_Channel API*/
#define DIO_FLIP_CHANNEL_API					(STD_ON)

/*Pre-compile option for DIO Version Info API*/
#define DIO_VERSION_INFO_API					(STD_OFF)

/*Number of configured DIO_channels*/
#define DIO_CONFIGURED_CHANNELS					(2U)

/*Number of Configured Channel Groups*/
#define DIO_CONFIGURED_GROUPS					(0U)

/*Number of Configured Ports*/
#define DIO_CONFIGURED_PORTS					(0U)


/*channel index in array of structs in DIO_PBcfg.c*/
#define DIOConf_LED_CHANNEL_ID_INDEX			((uint8)0x00)
#define DIOConf_BUTTON_CHANNEL_ID_INDEX			((uint8)0x01)

/*DIO configured port ids*/
#define DIOConf_LED_PORT_NUM					(Dio_PortType)2 /*PORTC*/
#define DIOConf_BUTTON_PORT_NUM					(Dio_PortType)3 /*PORTD*/

/*DIO configured Channel IDS*/
#define DIOConf_LED_CHANNEL_NUM					(Dio_ChannelType)5 /*PIN5 in PORTC*/
#define DIOConf_BUTTON_CHANNEL_NUM				(Dio_ChannelType)2 /*PIN2 in PORTd*/


#endif /* DIO_CFG_H_ */
