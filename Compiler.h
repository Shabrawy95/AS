/********************************************************************************************************************************
 * Module: Compiler abstraction
 *
 * File Name: Compiler.h
 *
 * Description: Abstraction of compiler specific keywords
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#ifndef COMPILER_H_
#define COMPILER_H_

/*ID for AUTOSAR partner or associate e.g 1000*/
#define COMPILER_VENDOR_ID                 (1000U)

/*Module SW Version (1.0.0)*/

#define COMPILER_SW_MAJOR_VERSION				(1U)
#define COMPILER_SW_MINOR_VERSION				(0U)
#define COMPILER_SW_PATCH_VERSION				(0U)

/*Module AUTOSAR Version (4.0.3)*/

#define COMPILER_AR_RELEASE_MAJOR_VERSION				(4U)
#define COMPILER_AR_RELEASE_MINOR_VERSION				(0U)
#define COMPILER_AR_RELEASE_PATCH_VERSION				(3U)


/*Memory class for local pointer declaration*/
#define AUTOMATIC

/*Memory class for type defintions where no memory qualifier can be specified*/
#define TYPEDEF

/*null pointer is defined to zero*/
#define NULL_PTR								((void*)0)

/*define abstraction of compiler keyword inline*/
#define INLINE									inline

/*define abstraction of compiler keyword static*/
#define STATIC static

/*defintion for local inline functions declaration*/

#define LOCAL_INLINE 						    static inline
#endif /* COMPILER_H_ */
