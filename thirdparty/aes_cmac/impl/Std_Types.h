#if (!defined STD_TYPES_H)
/* !LINKSTO STD003,1, STD014,1 */
#define STD_TYPES_H

#define CPU_TYPE_8       8u
#define CPU_TYPE_16      16u
#define CPU_TYPE_32      32u

#define MSB_FIRST        0u  /* big endian bit ordering */
#define LSB_FIRST        1u  /* little endian bit ordering */

#define HIGH_BYTE_FIRST  0u  /* big endian byte ordering */
#define LOW_BYTE_FIRST   1u  /* little endian byte ordering */

#ifndef TRUE
#define TRUE   1u
#endif

#ifndef FALSE
#define FALSE  0u
#endif

#define CPU_TYPE            CPU_TYPE_32
#define CPU_BIT_ORDER       LSB_FIRST
#define CPU_BYTE_ORDER      LOW_BYTE_FIRST

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef unsigned char       boolean;        /* for use with TRUE/FALSE        */

typedef signed char         sint8;          /*        -128 .. +127            */
typedef unsigned char       uint8;          /*           0 .. 255             */
typedef signed short        sint16;         /*      -32768 .. +32767          */
typedef unsigned short      uint16;         /*           0 .. 65535           */
typedef signed long         sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long       uint32;         /*           0 .. 4294967295      */
#define PLATFORM_SUPPORT_SINT64_UINT64
typedef signed long long    sint64;         /* \brief 64-bit unsigned integer */
typedef unsigned long long  uint64;
typedef unsigned long       uint8_least;    /* At least 8 bit                 */
typedef unsigned long       uint16_least;   /* At least 16 bit                */
typedef unsigned long       uint32_least;   /* At least 32 bit                */
typedef signed long         sint8_least;    /* At least 7 bit + 1 bit sign    */
typedef signed long         sint16_least;   /* At least 15 bit + 1 bit sign   */
typedef signed long         sint32_least;   /* At least 31 bit + 1 bit sign   */

typedef float               float32;
typedef double              float64;


/* AUTOMATIC used for the declaration of local pointers */
#define AUTOMATIC

/* TYPEDEF shall be used within type definitions, where no memory qualifier can be specified.*/
#define TYPEDEF


/* NULL_PTR define with a void pointer to zero definition*/
#ifndef NULL_PTR
#define NULL_PTR  ((void *)0)
#endif

/* INLINE  define for abstraction of the keyword inline*/
#ifndef INLINE
#define INLINE       __inline__
#endif

/* LOCAL_INLINE define for abstraction of the keyword inline in functions with "static" scope.
   Different compilers may require a different sequence of the keywords "static" and "inline"
   if this is supported at all. */
#ifndef LOCAL_INLINE
#define LOCAL_INLINE   static __inline__
#endif

/* FUNC macro for the declaration and definition of functions, that ensures correct syntax of function declarations
   rettype     return type of the function
   memclass    classification of the function itself*/
#define FUNC(rettype, memclass) rettype /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* FUNC_P2CONST macro for declaration and definition of functions returning a pointer to a constant, that ensures
     correct syntax of function declarations.
   rettype     return type of the function
   ptrclass    defines the classification of the pointer’s distance
   memclass    classification of the function itself*/
#define FUNC_P2CONST(rettype, ptrclass, memclass) const rettype* /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* FUNC_P2VAR macro for the declaration and definition of functions returning a pointer to a variable, that ensures
     correct syntax of function declarations
   rettype     return type of the function
   ptrclass    defines the classification of the pointer’s distance
   memclass    classification of the function itself*/
#define FUNC_P2VAR(rettype, ptrclass, memclass) rettype* /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* P2VAR macro for the declaration and definition of pointers in RAM, pointing to variables
   ptrtype     type of the referenced variable memory class
   memclass    classification of the pointer variable itself
   ptrclass    defines the classification of the pointer’s distance
 */
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype* /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* P2CONST macro for the declaration and definition of pointers in RAM pointing to constants
   ptrtype     type of the referenced data
   memclass    classification of the pointer variable itself
   ptrclass    defines the classification of the pointer distance
 */
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype* /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* CONSTP2VAR macro for the declaration and definition of constant pointers accessing variables
   ptrtype     type of the referenced data
   memclass    classification of the pointer variable itself
   ptrclass    defines the classification of the pointer distance
 */
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype* const /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* CONSTP2CONST macro for the declaration and definition of constant pointers accessing constants
   ptrtype     type of the referenced data
   memclass    classification of the pointer variable itself
   ptrclass    defines the classification of the pointer distance
 */
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype* const /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* P2FUNC macro for the type definition of pointers to functions
   rettype     return type of the function
   ptrclass    defines the classification of the pointer distance
   fctname     function name respectively name of the defined type
 */
#define P2FUNC(rettype, ptrclass, fctname) rettype (* fctname) /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* CONSTP2FUNC macro for the type definition of pointers to functions
   rettype     return type of the function
   ptrclass    defines the classification of the pointer distance
   fctname     function name respectively name of the defined type
   Example (PowerPC): #define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const fctname)
   Example (IAR, R32C): #define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (ptrclass * const fctname)
 */
#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const fctname) /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* CONST macro for the declaration and definition of constants
   type        type of the constant
   memclass    classification of the constant itself
 */
#define CONST(type, memclass) const type /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/* VAR macro for the declaration and definition of variables
   vartype        type of the variable
   memclass    classification of the variable itself
 */
#define VAR(vartype, memclass) vartype /* PRQA S 3410 */ /* MD_Compiler_19.10 */

/*==================[macros]=================================================*/

/* !LINKSTO STD007,1 */
#if (defined STD_HIGH)
#error STD_HIGH already defined
#endif

/** \brief physical state 5V or 3.3V  */
#define STD_HIGH 1U

#if (defined STD_LOW)
#error STD_LOW already defined
#endif

/** \brief physical state 0V */
#define STD_LOW 0U

/* !LINKSTO STD013,1 */
#if (defined STD_ACTIVE)
#error STD_ACTIVE already defined
#endif

/** \brief Autosar logical state 'active' */
#define STD_ACTIVE 1U

#if (defined STD_IDLE)
#error STD_IDLE already defined
#endif

/** \brief Autosar logical state 'idle' */
#define STD_IDLE 0U

/* !LINKSTO STD010,1 */
#if (defined STD_ON)
#error STD_ON already defined
#endif

/** \brief Autosar definition for 'on' */
#define STD_ON 1U

#if (defined STD_OFF)
#error STD_OFF already defined
#endif

/** \brief Autosar definition for 'off' */
#define STD_OFF 0U

#if (!defined STATUSTYPEDEFINED)
/** \brief Guard macro for type definition of StatusType */
#define STATUSTYPEDEFINED
/** \brief Definition StatusType (OSEK compliance) */
/* Deviation MISRA-1 */
typedef unsigned char StatusType;
#endif

/* !LINKSTO STD006,1 */
#if (!defined E_OK)
/** \brief Constant for value OK of StatusType */
/* !LINKSTO STD011,1 */
#define E_OK 0U
#endif

#if (!defined E_NOT_OK)
/** \brief Constant for value NOT_OK of StatusType */
/* !LINKSTO STD011,1 */
#define E_NOT_OK 1U
#endif

/*------------------[AUTOSAR vendor identification]-------------------------*/

#if (defined STD_VENDOR_ID)
#error STD_VENDOR_ID is already defined
#endif
/** \brief AUTOSAR vendor identification: Elektrobit Automotive GmbH */
#define STD_VENDOR_ID         1U

/*------------------[AUTOSAR module identification]-------------------------*/

#if (defined STD_MODULE_ID)
#error STD_MODULE_ID already defined
#endif
/** \brief AUTOSAR module identification
 *
 * Left empty as this header does not belong to any module
 */
#define STD_MODULE_ID         197U

/*------------------[AUTOSAR release version identification]----------------*/

#if (defined STD_AR_RELEASE_MAJOR_VERSION)
#error STD_AR_RELEASE_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR release major version */
#define STD_AR_RELEASE_MAJOR_VERSION     4U

#if (defined STD_AR_RELEASE_MINOR_VERSION)
#error STD_AR_RELEASE_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR release minor version */
#define STD_AR_RELEASE_MINOR_VERSION     0U

#if (defined STD_AR_RELEASE_REVISION_VERSION)
#error STD_AR_RELEASE_REVISION_VERSION already defined
#endif
/** \brief AUTOSAR release revision version */
#define STD_AR_RELEASE_REVISION_VERSION  3U

/*------------------[AUTOSAR module version identification]------------------*/

#if (defined STD_SW_MAJOR_VERSION)
#error STD_SW_MAJOR_VERSION already defined
#endif
/** \brief AUTOSAR module major version */
#define STD_SW_MAJOR_VERSION     1U

#if (defined STD_SW_MINOR_VERSION)
#error STD_SW_MINOR_VERSION already defined
#endif
/** \brief AUTOSAR module minor version */
#define STD_SW_MINOR_VERSION     3U

#if (defined STD_SW_PATCH_VERSION)
#error STD_SW_PATCH_VERSION already defined
#endif
/** \brief AUTOSAR module patch version */
#define STD_SW_PATCH_VERSION     0U

/*------------------[AUTOSAR module vendor API infix]------------------------*/

#if (defined STD_VENDOR_API_INFIX)
#error STD_VENDOR_API_INFIX already defined
#endif
/** \brief Vendor API infix
 *
 * Left empty as this header does not belong to any module
 */
#define STD_VENDOR_API_INFIX

/*==================[type definitions]=======================================*/

/** \brief Autosar standard API return type */
/* !LINKSTO STD005,1 */
typedef uint8 Std_ReturnType;

#if (!defined STD_VERSION_INFO_TYPE_DEFINED)
/** \brief Guard for definition of Std_VersionInfoType */
#define STD_VERSION_INFO_TYPE_DEFINED STD_OFF
#endif

/* !LINKSTO Base.CustomStdVersionInfoType.ConfigMacro,1 */
#if (STD_VERSION_INFO_TYPE_DEFINED != STD_ON)

/** \brief return type for xxx_GetVersionInfo() functions of each BSW module
 *
 * This type is used to request the version of BSW module using the
 * xxx_GetVersionInfo() function.
 */
/* !LINKSTO STD015,1 */
typedef struct
{
    uint16 vendorID;
    uint16 moduleID;
    uint8  sw_major_version;
    uint8  sw_minor_version;
    uint8  sw_patch_version;
} Std_VersionInfoType;

#endif /* #if (STD_VERSION_INFO_TYPE_DEFINED != STD_ON) */

/*==================[end of file]============================================*/
#endif /* if !defined( STD_TYPES_H ) */
