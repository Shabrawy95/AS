 /********************************************************************************************************************************
 * Module:
 *
 * File Name:
 *
 * Description:
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include "Platform_Types.h"
#include "Compiler.h"

/*ID for AUTOSAR partner or associate e.g 1000*/
#define STD_TYPES_VENDOR_ID                 (1000U)

/*Module SW Version (1.0.0)*/

#define STD_TYPES_SW_MAJOR_VERSION				(1U)
#define STD_TYPES_SW_MINOR_VERSION				(0U)
#define STD_TYPES_SW_PATCH_VERSION				(0U)

/*Module AUTOSAR Version (4.0.3)*/

#define STD_TYPES_AR_RELEASE_MAJOR_VERSION				(4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION				(0U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION				(3U)

/*standard return type used in project*/
typedef uint8 Std_ReturnType;

/*structure for version of the module, requested by calling
 * <Module name>_GetVersionInfo() */
typedef struct {
	uint16 VendorID;
	uint16 moduleID;
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;
}Std_VersionInfoType;

#define STD_HIGH					0x01U 	/*Standard High*/
#define STD_LOW						0x00U 	/*Standard Low*/

#define STD_ACTIVE					0x01U 	/*Standard Active*/
#define STD_IDLE					0x00U 	/*Standard Idle*/

#define STD_ON						0x01U 	/*Standard On*/
#define STD_OFF						0x00U 	/*Standard Off*/

#define E_OK						((Std_ReturnType)0x01U)		/*Function Returns ok*/
#define E_NOT_OK 					((Std_ReturnType)0x00U)		/*Function Returns not ok*/

#endif /* STD_TYPES_H_ */
