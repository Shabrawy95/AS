 /********************************************************************************************************************************
 * Module: Platform_Abstraction
 *
 * File Name: Platform_Types.h
 *
 * Description: Platform types for AVR
 *
 * Author: AhmadShabrawy
 ********************************************************************************************************************************/

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/*ID for AUTOSAR partner or associate e.g 1000*/
#define PLATFORM_VENDOR_ID                 (1000U)

/*Module SW Version (1.0.0)*/

#define PLATFORM_SW_MAJOR_VERSION				(1U)
#define PLATFORM_SW_MINOR_VERSION				(0U)
#define PLATFORM_SW_PATCH_VERSION				(0U)

/*Module AUTOSAR Version (4.0.3)*/

#define PLATFORM_AR_RELEASE_MAJOR_VERSION				(4U)
#define PLATFORM_AR_RELEASE_MINOR_VERSION				(0U)
#define PLATFORM_AR_RELEASE_PATCH_VERSION				(3U)

/*CPU register type width*/

#define CPU_TYPE_8								(8U)
#define CPU_TYPE_16								(16U)
#define CPU_TYPE_32								(32U)

/*Bit order definition*/

#define MSB_FIRST								(0U)	/*Big endian bit ordering*/
#define LSB_FIRST								(1U)	/*little endian bit ordering*/

/*Byte order*/
#define HIGH_BYTE_FIRST							(0U)	/*Big endian byte ordering*/
#define LOW_BYTE_FIRST							(1U)	/*little endian byte ordering*/

/*platform types and endianess defintion*/

#define CPU_TYPE								CPU_TYPE_8

#define CPU_BIT_ORDER							LSB_FIRST
#define CPU_BYTE_ORDER							LOW_BYTE_FIRST


/*Boolean Values*/

#ifndef TRUE
#define TRUE									(1U)
#endif

#ifndef FALSE
#define FALSE									(0U)
#endif


typedef unsigned char boolean;

typedef unsigned char uint8;  					/*0 - 255*/
typedef unsigned short uint16;					/* 0 - 65535 */
typedef unsigned long uint32;					/* 0 - 4294967295 */
typedef unsigned long long uint64;				/*0 - 18446744073709551615*/
typedef signed char sint8;						/*-128 - +127*/
typedef signed short sint16;					/* -32768 - 32767*/
typedef signed long sint32;						/* -2147483648 - +2147483647*/
typedef signed long long sint64;
typedef float float32;
typedef double float64;


#endif /* PLATFORM_TYPES_H_ */
