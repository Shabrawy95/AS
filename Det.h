 /********************************************************************************************************************************
 * Module: DET
 *
 * File Name: Det.h
 *
 * Description: Development error tracer header file
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#ifndef DET_H_
#define DET_H_



/*ID for AUTOSAR partner or associate e.g 1000*/
#define DET_VENDOR_ID                 (1000U)

/*Module ID for DET*/
#define DET_MODULE_ID				  (15U)

/*Instance ID for DET*/
#define DET_INSTANCE_ID				  (0U)

/*Module SW Version (1.0.0)*/

#define DET_SW_MAJOR_VERSION				(1U)
#define DET_SW_MINOR_VERSION				(0U)
#define DET_SW_PATCH_VERSION				(0U)

/*Module AUTOSAR Version (4.0.3)*/

#define DET_AR_RELEASE_MAJOR_VERSION				(4U)
#define DET_AR_RELEASE_MINOR_VERSION				(0U)
#define DET_AR_RELEASE_PATCH_VERSION				(3U)

/*Standard autosar types*/
#include "Std_Types.h"

#if ((DET_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
		||(DET_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
		||(DET_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
#error "The AUTOSAR version of Std_Types.h doesn't match the expected version"
#endif

/**********************************************************************************************************************************
 *                    								  Function Prototypes      						                              *
 *********************************************************************************************************************************/

void Det_ReportError(
 uint16 ModuleId,
 uint8 InstanceId,
 uint8 ApiId,
 uint8 ErrorId
);

#endif /* DET_H_ */
