/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: MemMap
 *           Program:
 *          Customer:
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:
 *    License Scope :
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CryIf_MemMap.h
 *   Generation Time: 2024-09-26 17:12:14
 *           Project:
 *          Delivery:
 *      Tool Version: DaVinci Configurator Classic 5.30.22
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0883 EOF */ /* MD_MSR_MemMap */

#ifndef MICROSAR_DISABLE_MEMMAP

/**********************************************************************************************************************
 *  PRE USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

/**********************************************************************************************************************
 *  MEMMAP SECTIONS
 *********************************************************************************************************************/

#define MEMMAP_ERROR

#if defined CRYIF_START_SEC_CODE
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYIF_START_SEC_CODE is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYIF_CODE_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma ghs section text = ".MSR_CODE" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef CRYIF_START_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYIF_STOP_SEC_CODE
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYIF_STOP_SEC_CODE is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYIF_CODE_OPEN
#  error Using CRYIF_STOP_SEC_CODE is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYIF_CODE_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CODE/MSR_CODE */
# pragma ghs section text = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef CRYIF_STOP_SEC_CODE /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYIF_START_SEC_CONST_UNSPECIFIED
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYIF_START_SEC_CONST_UNSPECIFIED is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYIF_CONST_UNSPECIFIED_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma ghs section rodata = ".MSR_CONST" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef CRYIF_START_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYIF_STOP_SEC_CONST_UNSPECIFIED
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYIF_STOP_SEC_CONST_UNSPECIFIED is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYIF_CONST_UNSPECIFIED_OPEN
#  error Using CRYIF_STOP_SEC_CONST_UNSPECIFIED is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYIF_CONST_UNSPECIFIED_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_CONST/MSR_CONST */
# pragma ghs section rodata = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef CRYIF_STOP_SEC_CONST_UNSPECIFIED /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

/* -------------------------------------------------------------------------------- */

#elif defined CRYIF_START_SEC_VAR_ZERO_INIT_8BIT
# ifdef MEMMAP_SECTION_OPEN
#  error Using CRYIF_START_SEC_VAR_ZERO_INIT_8BIT is not possible as a memory section has already been opened. Nesting is not supported.
# endif
# define MEMMAP_SECTION_OPEN
# define CRYIF_VAR_ZERO_INIT_8BIT_OPEN

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma ghs section bss = ".MSR_VAR_CLEARED" /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = ".MSR_VAR_INIT" /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */

#elif defined CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# ifndef MEMMAP_SECTION_OPEN
#  error Using CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as no memory section has been opened.
# endif
# undef MEMMAP_SECTION_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */
# ifndef CRYIF_VAR_ZERO_INIT_8BIT_OPEN
#  error Using CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as the corresponding memory section has not been opened.
# endif
# undef CRYIF_VAR_ZERO_INIT_8BIT_OPEN /* PRQA S 0841 */ /* MD_MSR_Undef */

/* Pragmas generated automatically. Related MemMapAddressingMode: /ActiveEcuC/MemMap/MSR_VAR_CLEARED/MSR_VAR_CLEARED */
# pragma ghs section bss = default /* PRQA S 3116 */ /* MD_MSR_Pragma */
# pragma ghs section data = default /* PRQA S 3116 */ /* MD_MSR_Pragma */

# undef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT /* PRQA S 0841 */ /* MD_MSR_Undef */
# undef MEMMAP_ERROR /* PRQA S 0841 */ /* MD_MSR_Undef */
#endif

/* -------------------------------------------------------------------------------- */


/**********************************************************************************************************************
 *  MEMMAP ERROR CHECKS
 *********************************************************************************************************************/

#ifdef CRYIF_START_SEC_CODE
# error Using CRYIF_START_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYIF_STOP_SEC_CODE
# error Using CRYIF_STOP_SEC_CODE is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYIF_START_SEC_CONST_UNSPECIFIED
# error Using CRYIF_START_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYIF_STOP_SEC_CONST_UNSPECIFIED
# error Using CRYIF_STOP_SEC_CONST_UNSPECIFIED is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYIF_START_SEC_VAR_ZERO_INIT_8BIT
# error Using CRYIF_START_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif
#ifdef CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT
# error Using CRYIF_STOP_SEC_VAR_ZERO_INIT_8BIT is not possible as multiple memory allocation keywords are defined. Include the MemMap separately for each one.
#endif

#ifdef MEMMAP_ERROR
# error No MemMap section found in CryIf_MemMap.h. Check your section define for validity.
#endif


/**********************************************************************************************************************
 *  POST USER CONFIG FILE
 *********************************************************************************************************************/

/* User Config File Start */

/* User Config File End */

#endif
/**********************************************************************************************************************
 *  END OF FILE: CryIf_MemMap.h
 *********************************************************************************************************************/

