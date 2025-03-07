#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : CommonAsr_Rh850 CQComponent : Impl_PlatformTypes */
#define COMMONASR_RH850_IMPL_PLATFORMTYPES_VERSION 0x0104
#define COMMONASR_RH850_IMPL_PLATFORMTYPES_RELEASE_VERSION 0x02

#define PLATFORM_VENDOR_ID    30u              /* Vendor ID of Vector */
#define PLATFORM_MODULE_ID    199u             /* 199 is the ID of Platform types */

/* AUTOSAR Software Specification Document Version Information */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION      (4u)
#define PLATFORM_AR_RELEASE_MINOR_VERSION      (8u)
#define PLATFORM_AR_RELEASE_REVISION_VERSION   (0u)

/* Component Version Information */
# define PLATFORM_SW_MAJOR_VERSION       (1u)
# define PLATFORM_SW_MINOR_VERSION       (4u)
# define PLATFORM_SW_PATCH_VERSION       (2u)

#define CPU_TYPE_8       8u
#define CPU_TYPE_16      16u
#define CPU_TYPE_32      32u
#define CPU_TYPE_64      64u

#define MSB_FIRST        0u  /* big endian bit ordering */
#define LSB_FIRST        1u  /* little endian bit ordering */

#define HIGH_BYTE_FIRST  0u  /* big endian byte ordering */
#define LOW_BYTE_FIRST   1u  /* little endian byte ordering */

#ifndef TRUE
# define TRUE            1u
#endif

#ifndef FALSE
# define FALSE           0u
#endif

#define CPU_TYPE          CPU_TYPE_32

#define CPU_BIT_ORDER     LSB_FIRST       /* little endian bit ordering */

#define CPU_BYTE_ORDER    LOW_BYTE_FIRST  /* little endian byte ordering */

#ifdef DISABLED_DUE_TO_USE_OF_STDINT
/* data type limitation defines */
#define UINT8_MIN        0u
#define UINT8_MAX        255u
#define UINT16_MIN       0u
#define UINT16_MAX       65535u
#define UINT32_MIN       0ul
#define UINT32_MAX       4294967295ul
#define UINT64_MIN       0ull
#define UINT64_MAX       18446744073709551615ull

#define SINT8_MIN        -128
#define SINT8_MAX        127
#define SINT16_MIN       -32768
#define SINT16_MAX       32767
#define SINT32_MIN       -2147483648
#define SINT32_MAX       2147483647
#define SINT64_MIN       -9223372036854775808
#define SINT64_MAX       9223372036854775807

#define FLOAT32_MIN      1.17549435e-38f
#define FLOAT32_MAX      3.40282347e+38f
#define FLOAT32_EPSILON  1.19209290e-07f

#define FLOAT64_MIN       2.2250738585072014e-308l
#define FLOAT64_MAX       1.7976931348623157e+308l
#define FLOAT64_EPSILON   2.2204460492503131e-16l
#endif	/* DISABLED_DUE_TO_USE_OF_STDINT */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef unsigned char       boolean;        /* for use with TRUE/FALSE        */

typedef signed char           sint8;         /*        -128 .. +127            */
typedef unsigned char         uint8;         /*           0 .. 255             */
typedef signed short          sint16;        /*      -32768 .. +32767          */
typedef unsigned short        uint16;        /*           0 .. 65535           */
typedef signed long           sint32;        /* -2147483648 .. +2147483647     */
typedef unsigned long         uint32;        /*           0 .. 4294967295      */

typedef signed int            sint8_least;   /* At least 7 bit + 1 bit sign    */
typedef unsigned int          uint8_least;   /* At least 8 bit                 */
typedef signed int            sint16_least;  /* At least 15 bit + 1 bit sign   */
typedef unsigned int          uint16_least;  /* At least 16 bit                */
typedef signed int            sint32_least;  /* At least 31 bit + 1 bit sign   */
typedef unsigned int          uint32_least;  /* At least 32 bit                */

#if defined(__ghs__) && !defined(__LLONG_BIT)
 /*
   The option --no_long_long for GHS compiler disables the support for the long long data type and generates compile
   errors if this type is used. So as an AUTOSAR extension the following typedefs are omitted if --no_long_long is
   given (__LLONG_BIT is not defined in this case).
 */
#else
#define PLATFORM_SUPPORT_SINT64_UINT64
typedef signed long long      sint64;        /* -9223372036854775808 .. 9223372036854775807      */
typedef unsigned long long    uint64;        /*                    0 .. 18446744073709551615     */
#endif

#if defined(__ghs__) && defined(__NoFloat__) 
 /*
   The option -fnone for GHS compiler disallows all floating-point operations and generates compile errors if such
   operations are used by the software. This also applies to any corresponding type definition. So as an AUTOSAR
   extension the following typedefs are omitted if -fnone is given (__NoFloat__ is defined in this case).
 */
#else
 typedef float                 float32;
 typedef double                float64;
#endif

typedef void* VoidPtr;
typedef const void* ConstVoidPtr;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* PLATFORM_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Platform_Types.h
 *********************************************************************************************************************/
