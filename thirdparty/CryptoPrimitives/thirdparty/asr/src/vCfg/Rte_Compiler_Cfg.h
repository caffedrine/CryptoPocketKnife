/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Compiler_Cfg.h
 *           Config:
 *      ECU-Project:
 *
 *        Generator:  MICROSAR RTE Generator Version 4.38.00
 *                    RTE Core Version 4.38.00
 *          License:
 *
 *      Description:  RTE Compiler Abstraction header file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_COMPILER_CFG_H
# define RTE_COMPILER_CFG_H

# include "SomeIpXf_Compiler_Cfg.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * RTE specific defines
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CODE
 *********************************************************************************************************************/

/* used for code */
# define RTE_CODE

/* used for all global or static variables that are not initialized by the startup code of the compiler */
# define RTE_VAR_NOINIT

/* used for global or static variables that are initialized with zero by the startup code of the compiler or in Rte_InitMemory */
# define RTE_VAR_ZERO_INIT

/* used for global or static variables that are initialized by the startup code of the compiler or in Rte_InitMemory */
# define RTE_VAR_INIT

/* used for global or static constants */
# define RTE_CONST

/* used for references on application data (variables or constants) */
# define RTE_APPL_DATA

/* used for references on application variables */
# define RTE_APPL_VAR

/* used for references on application functions */
# define RTE_APPL_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_INSTANCECONSTP2CONST
 *********************************************************************************************************************/

/* In AUTOSAR 4.1.3 [SWS_Rte_06810] was introduced that breaks compatibility with MICROSAR.
   Define the following define to P2CONST to get the old behavior. */
# define RTE_INSTANCECONSTP2CONST CONSTP2CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * SW-C specific defines
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_BSWM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_BSWM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_BSWM_APPL_DATA

/* used for references on application functions */
# define RTE_BSWM_APPL_CODE

/* used for references on application constants */
# define RTE_BSWM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BswM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define BswM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BswM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define BswM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: BswM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define BswM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define BswM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define BswM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_COMM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_COMM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_COMM_APPL_DATA

/* used for references on application functions */
# define RTE_COMM_APPL_CODE

/* used for references on application constants */
# define RTE_COMM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define ComM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define ComM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: ComM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define ComM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define ComM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define ComM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPAIOBOARDDETECTION_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPAIOBOARDDETECTION_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPAIOBOARDDETECTION_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPAIOBOARDDETECTION_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPAIOBOARDDETECTION_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApAioBoardDetection_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApAioBoardDetection_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApAioBoardDetection_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApAioBoardDetection_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApAioBoardDetection_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApAioBoardDetection_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApAioBoardDetection_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApAioBoardDetection_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPAPPLIANCECAPABILITIESINFOPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPAPPLIANCECAPABILITIESINFOPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPAPPLIANCECAPABILITIESINFOPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPAPPLIANCECAPABILITIESINFOPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPAPPLIANCECAPABILITIESINFOPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApApplianceCapabilitiesInfoProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApApplianceCapabilitiesInfoProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApApplianceCapabilitiesInfoProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApApplianceCapabilitiesInfoProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApApplianceCapabilitiesInfoProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApApplianceCapabilitiesInfoProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApApplianceCapabilitiesInfoProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApApplianceCapabilitiesInfoProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPBRINEPUMPTESTPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPBRINEPUMPTESTPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPBRINEPUMPTESTPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPBRINEPUMPTESTPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPBRINEPUMPTESTPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApBrinePumpTestProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApBrinePumpTestProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApBrinePumpTestProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApBrinePumpTestProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApBrinePumpTestProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApBrinePumpTestProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApBrinePumpTestProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApBrinePumpTestProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPCONDENSATETRAYHEATERTESTPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPCONDENSATETRAYHEATERTESTPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPCONDENSATETRAYHEATERTESTPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPCONDENSATETRAYHEATERTESTPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPCONDENSATETRAYHEATERTESTPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApCondensateTrayHeaterTestProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApCondensateTrayHeaterTestProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApCondensateTrayHeaterTestProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApCondensateTrayHeaterTestProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApCondensateTrayHeaterTestProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApCondensateTrayHeaterTestProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApCondensateTrayHeaterTestProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApCondensateTrayHeaterTestProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPCONFIGSOLARTHERMALENERGYGENERATIONPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPCONFIGSOLARTHERMALENERGYGENERATIONPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPCONFIGSOLARTHERMALENERGYGENERATIONPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPCONFIGSOLARTHERMALENERGYGENERATIONPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPCONFIGSOLARTHERMALENERGYGENERATIONPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApConfigSolarThermalEnergyGenerationProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApConfigSolarThermalEnergyGenerationProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApConfigSolarThermalEnergyGenerationProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApConfigSolarThermalEnergyGenerationProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApConfigSolarThermalEnergyGenerationProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApConfigSolarThermalEnergyGenerationProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApConfigSolarThermalEnergyGenerationProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApConfigSolarThermalEnergyGenerationProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPCONSUMERSERVICECONNECTOR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPCONSUMERSERVICECONNECTOR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPCONSUMERSERVICECONNECTOR_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPCONSUMERSERVICECONNECTOR_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPCONSUMERSERVICECONNECTOR_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApConsumerServiceConnector_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApConsumerServiceConnector_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApConsumerServiceConnector_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApConsumerServiceConnector_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApConsumerServiceConnector_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApConsumerServiceConnector_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApConsumerServiceConnector_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApConsumerServiceConnector_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPCRANKCASEHEATERTESTPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPCRANKCASEHEATERTESTPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPCRANKCASEHEATERTESTPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPCRANKCASEHEATERTESTPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPCRANKCASEHEATERTESTPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApCrankCaseHeaterTestProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApCrankCaseHeaterTestProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApCrankCaseHeaterTestProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApCrankCaseHeaterTestProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApCrankCaseHeaterTestProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApCrankCaseHeaterTestProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApCrankCaseHeaterTestProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApCrankCaseHeaterTestProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPDATARECORDINGPROVIDERSIMPLE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPDATARECORDINGPROVIDERSIMPLE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPDATARECORDINGPROVIDERSIMPLE_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPDATARECORDINGPROVIDERSIMPLE_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPDATARECORDINGPROVIDERSIMPLE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDataRecordingProviderSimple_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApDataRecordingProviderSimple_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDataRecordingProviderSimple_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApDataRecordingProviderSimple_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDataRecordingProviderSimple_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApDataRecordingProviderSimple_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApDataRecordingProviderSimple_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApDataRecordingProviderSimple_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPDATARECORDINGTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPDATARECORDINGTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPDATARECORDINGTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPDATARECORDINGTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPDATARECORDINGTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDataRecordingTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApDataRecordingTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDataRecordingTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApDataRecordingTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDataRecordingTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApDataRecordingTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApDataRecordingTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApDataRecordingTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPDATABASEHANDLER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPDATABASEHANDLER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPDATABASEHANDLER_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPDATABASEHANDLER_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPDATABASEHANDLER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDatabaseHandler_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApDatabaseHandler_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDatabaseHandler_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApDatabaseHandler_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDatabaseHandler_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApDatabaseHandler_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApDatabaseHandler_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApDatabaseHandler_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPDEICINGTESTPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPDEICINGTESTPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPDEICINGTESTPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPDEICINGTESTPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPDEICINGTESTPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDeicingTestProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApDeicingTestProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDeicingTestProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApDeicingTestProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDeicingTestProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApDeicingTestProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApDeicingTestProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApDeicingTestProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPDEVICEINFO_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPDEVICEINFO_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPDEVICEINFO_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPDEVICEINFO_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPDEVICEINFO_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDeviceInfo_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApDeviceInfo_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDeviceInfo_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApDeviceInfo_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDeviceInfo_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApDeviceInfo_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApDeviceInfo_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApDeviceInfo_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPDYNAMICINSTANCEIDWRAPPER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPDYNAMICINSTANCEIDWRAPPER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPDYNAMICINSTANCEIDWRAPPER_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPDYNAMICINSTANCEIDWRAPPER_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPDYNAMICINSTANCEIDWRAPPER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDynamicInstanceIdWrapper_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApDynamicInstanceIdWrapper_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDynamicInstanceIdWrapper_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApDynamicInstanceIdWrapper_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDynamicInstanceIdWrapper_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApDynamicInstanceIdWrapper_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApDynamicInstanceIdWrapper_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApDynamicInstanceIdWrapper_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPEBHCENTRALHEATINGPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPEBHCENTRALHEATINGPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPEBHCENTRALHEATINGPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPEBHCENTRALHEATINGPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPEBHCENTRALHEATINGPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhCentralHeatingProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEbhCentralHeatingProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhCentralHeatingProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEbhCentralHeatingProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhCentralHeatingProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEbhCentralHeatingProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEbhCentralHeatingProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEbhCentralHeatingProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPEBHCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPEBHCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPEBHCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPEBHCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPEBHCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhComponentCommissioningProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEbhComponentCommissioningProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhComponentCommissioningProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEbhComponentCommissioningProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhComponentCommissioningProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEbhComponentCommissioningProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEbhComponentCommissioningProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEbhComponentCommissioningProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPEBHCOMPONENTFACTORYRESETPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPEBHCOMPONENTFACTORYRESETPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPEBHCOMPONENTFACTORYRESETPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPEBHCOMPONENTFACTORYRESETPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPEBHCOMPONENTFACTORYRESETPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhComponentFactoryResetProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEbhComponentFactoryResetProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhComponentFactoryResetProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEbhComponentFactoryResetProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhComponentFactoryResetProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEbhComponentFactoryResetProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEbhComponentFactoryResetProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEbhComponentFactoryResetProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPEBHELECTRICALPOWERLIMITATIONPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPEBHELECTRICALPOWERLIMITATIONPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPEBHELECTRICALPOWERLIMITATIONPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPEBHELECTRICALPOWERLIMITATIONPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPEBHELECTRICALPOWERLIMITATIONPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhElectricalPowerLimitationProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEbhElectricalPowerLimitationProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhElectricalPowerLimitationProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEbhElectricalPowerLimitationProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhElectricalPowerLimitationProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEbhElectricalPowerLimitationProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEbhElectricalPowerLimitationProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEbhElectricalPowerLimitationProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPEBHENERGYMETERINGFUNCTIONPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPEBHENERGYMETERINGFUNCTIONPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPEBHENERGYMETERINGFUNCTIONPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPEBHENERGYMETERINGFUNCTIONPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPEBHENERGYMETERINGFUNCTIONPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhEnergyMeteringFunctionProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEbhEnergyMeteringFunctionProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhEnergyMeteringFunctionProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEbhEnergyMeteringFunctionProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhEnergyMeteringFunctionProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEbhEnergyMeteringFunctionProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEbhEnergyMeteringFunctionProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEbhEnergyMeteringFunctionProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPEBHGENERATORCONTROLINFOPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPEBHGENERATORCONTROLINFOPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPEBHGENERATORCONTROLINFOPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPEBHGENERATORCONTROLINFOPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPEBHGENERATORCONTROLINFOPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhGeneratorControlInfoProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEbhGeneratorControlInfoProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhGeneratorControlInfoProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEbhGeneratorControlInfoProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhGeneratorControlInfoProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEbhGeneratorControlInfoProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEbhGeneratorControlInfoProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEbhGeneratorControlInfoProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPEBHSTANDBYPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPEBHSTANDBYPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPEBHSTANDBYPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPEBHSTANDBYPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPEBHSTANDBYPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhStandbyProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEbhStandbyProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhStandbyProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEbhStandbyProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhStandbyProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEbhStandbyProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEbhStandbyProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEbhStandbyProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPEBHTANKLOADINGPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPEBHTANKLOADINGPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPEBHTANKLOADINGPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPEBHTANKLOADINGPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPEBHTANKLOADINGPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhTankLoadingProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEbhTankLoadingProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhTankLoadingProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEbhTankLoadingProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEbhTankLoadingProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEbhTankLoadingProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEbhTankLoadingProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEbhTankLoadingProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPECUDTCSERVICE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPECUDTCSERVICE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPECUDTCSERVICE_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPECUDTCSERVICE_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPECUDTCSERVICE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEcuDtcService_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEcuDtcService_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEcuDtcService_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEcuDtcService_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEcuDtcService_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEcuDtcService_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEcuDtcService_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEcuDtcService_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPECURESTART_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPECURESTART_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPECURESTART_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPECURESTART_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPECURESTART_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEcuRestart_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEcuRestart_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEcuRestart_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEcuRestart_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEcuRestart_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEcuRestart_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEcuRestart_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEcuRestart_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPEEVTESTPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPEEVTESTPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPEEVTESTPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPEEVTESTPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPEEVTESTPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEevTestProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEevTestProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEevTestProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEevTestProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEevTestProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEevTestProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEevTestProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEevTestProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPENVIRONMENTCIRCUITBLEEDINGPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPENVIRONMENTCIRCUITBLEEDINGPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPENVIRONMENTCIRCUITBLEEDINGPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPENVIRONMENTCIRCUITBLEEDINGPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPENVIRONMENTCIRCUITBLEEDINGPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEnvironmentCircuitBleedingProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEnvironmentCircuitBleedingProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEnvironmentCircuitBleedingProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEnvironmentCircuitBleedingProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEnvironmentCircuitBleedingProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEnvironmentCircuitBleedingProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEnvironmentCircuitBleedingProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEnvironmentCircuitBleedingProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPENVIRONMENTCIRCUITPRESSUREPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPENVIRONMENTCIRCUITPRESSUREPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPENVIRONMENTCIRCUITPRESSUREPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPENVIRONMENTCIRCUITPRESSUREPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPENVIRONMENTCIRCUITPRESSUREPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEnvironmentCircuitPressureProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEnvironmentCircuitPressureProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEnvironmentCircuitPressureProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEnvironmentCircuitPressureProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEnvironmentCircuitPressureProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEnvironmentCircuitPressureProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEnvironmentCircuitPressureProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEnvironmentCircuitPressureProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPETHERNETSUPERVISION_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPETHERNETSUPERVISION_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPETHERNETSUPERVISION_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPETHERNETSUPERVISION_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPETHERNETSUPERVISION_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEthernetSupervision_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApEthernetSupervision_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEthernetSupervision_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApEthernetSupervision_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApEthernetSupervision_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEthernetSupervision_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEthernetSupervision_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEthernetSupervision_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPLINPUMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPLINPUMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPLINPUMP_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPLINPUMP_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPLINPUMP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApLinPump_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApLinPump_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApLinPump_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApLinPump_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApLinPump_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApLinPump_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApLinPump_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApLinPump_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPFACTORYRESET_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPFACTORYRESET_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPFACTORYRESET_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPFACTORYRESET_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPFACTORYRESET_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFactoryReset_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApFactoryReset_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFactoryReset_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApFactoryReset_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFactoryReset_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApFactoryReset_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApFactoryReset_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApFactoryReset_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPFANTESTPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPFANTESTPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPFANTESTPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPFANTESTPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPFANTESTPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFanTestProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApFanTestProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFanTestProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApFanTestProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFanTestProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApFanTestProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApFanTestProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApFanTestProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPFBLPROXY_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPFBLPROXY_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPFBLPROXY_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPFBLPROXY_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPFBLPROXY_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFblProxy_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApFblProxy_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFblProxy_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApFblProxy_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFblProxy_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApFblProxy_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApFblProxy_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApFblProxy_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPFLOWRATESENSORPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPFLOWRATESENSORPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPFLOWRATESENSORPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPFLOWRATESENSORPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPFLOWRATESENSORPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFlowRateSensorProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApFlowRateSensorProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFlowRateSensorProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApFlowRateSensorProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFlowRateSensorProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApFlowRateSensorProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApFlowRateSensorProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApFlowRateSensorProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPFROSTPROTECTIONCONSUMERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPFROSTPROTECTIONCONSUMERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPFROSTPROTECTIONCONSUMERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPFROSTPROTECTIONCONSUMERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPFROSTPROTECTIONCONSUMERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFrostProtectionConsumerTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApFrostProtectionConsumerTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFrostProtectionConsumerTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApFrostProtectionConsumerTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApFrostProtectionConsumerTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApFrostProtectionConsumerTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApFrostProtectionConsumerTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApFrostProtectionConsumerTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHC1HEATINGCIRCUITIOPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHC1HEATINGCIRCUITIOPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHC1HEATINGCIRCUITIOPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHC1HEATINGCIRCUITIOPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHC1HEATINGCIRCUITIOPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHc1HeatingCircuitIoProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHc1HeatingCircuitIoProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHc1HeatingCircuitIoProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHc1HeatingCircuitIoProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHc1HeatingCircuitIoProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHc1HeatingCircuitIoProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHc1HeatingCircuitIoProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHc1HeatingCircuitIoProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHC2HEATINGCIRCUITIOPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHC2HEATINGCIRCUITIOPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHC2HEATINGCIRCUITIOPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHC2HEATINGCIRCUITIOPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHC2HEATINGCIRCUITIOPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHc2HeatingCircuitIoProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHc2HeatingCircuitIoProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHc2HeatingCircuitIoProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHc2HeatingCircuitIoProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHc2HeatingCircuitIoProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHc2HeatingCircuitIoProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHc2HeatingCircuitIoProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHc2HeatingCircuitIoProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHC3HEATINGCIRCUITIOPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHC3HEATINGCIRCUITIOPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHC3HEATINGCIRCUITIOPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHC3HEATINGCIRCUITIOPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHC3HEATINGCIRCUITIOPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHc3HeatingCircuitIoProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHc3HeatingCircuitIoProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHc3HeatingCircuitIoProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHc3HeatingCircuitIoProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHc3HeatingCircuitIoProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHc3HeatingCircuitIoProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHc3HeatingCircuitIoProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHc3HeatingCircuitIoProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHGPENERGYMETERINGFUNCTIONPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHGPENERGYMETERINGFUNCTIONPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHGPENERGYMETERINGFUNCTIONPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHGPENERGYMETERINGFUNCTIONPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHGPENERGYMETERINGFUNCTIONPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHgpEnergyMeteringFunctionProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHgpEnergyMeteringFunctionProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHgpEnergyMeteringFunctionProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHgpEnergyMeteringFunctionProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHgpEnergyMeteringFunctionProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHgpEnergyMeteringFunctionProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHgpEnergyMeteringFunctionProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHgpEnergyMeteringFunctionProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHIGHPRESSURESHUTDOWNTESTPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHIGHPRESSURESHUTDOWNTESTPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHIGHPRESSURESHUTDOWNTESTPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHIGHPRESSURESHUTDOWNTESTPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHIGHPRESSURESHUTDOWNTESTPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHighPressureShutdownTestProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHighPressureShutdownTestProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHighPressureShutdownTestProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHighPressureShutdownTestProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHighPressureShutdownTestProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHighPressureShutdownTestProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHighPressureShutdownTestProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHighPressureShutdownTestProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHMUCONFIGURATIONEBHPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHMUCONFIGURATIONEBHPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHMUCONFIGURATIONEBHPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHMUCONFIGURATIONEBHPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHMUCONFIGURATIONEBHPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHmuConfigurationEbhProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHmuConfigurationEbhProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHmuConfigurationEbhProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHmuConfigurationEbhProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHmuConfigurationEbhProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHmuConfigurationEbhProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHmuConfigurationEbhProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHmuConfigurationEbhProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHMUCONFIGURATIONHPPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHMUCONFIGURATIONHPPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHMUCONFIGURATIONHPPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHMUCONFIGURATIONHPPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHMUCONFIGURATIONHPPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHmuConfigurationHpProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHmuConfigurationHpProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHmuConfigurationHpProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHmuConfigurationHpProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHmuConfigurationHpProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHmuConfigurationHpProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHmuConfigurationHpProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHmuConfigurationHpProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHPCENTRALCOOLINGPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHPCENTRALCOOLINGPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHPCENTRALCOOLINGPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHPCENTRALCOOLINGPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHPCENTRALCOOLINGPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpCentralCoolingProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHpCentralCoolingProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpCentralCoolingProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHpCentralCoolingProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpCentralCoolingProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHpCentralCoolingProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHpCentralCoolingProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHpCentralCoolingProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHPCENTRALHEATINGPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHPCENTRALHEATINGPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHPCENTRALHEATINGPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHPCENTRALHEATINGPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHPCENTRALHEATINGPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpCentralHeatingProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHpCentralHeatingProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpCentralHeatingProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHpCentralHeatingProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpCentralHeatingProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHpCentralHeatingProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHpCentralHeatingProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHpCentralHeatingProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHPCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHPCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHPCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHPCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHPCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpComponentCommissioningProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHpComponentCommissioningProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpComponentCommissioningProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHpComponentCommissioningProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpComponentCommissioningProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHpComponentCommissioningProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHpComponentCommissioningProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHpComponentCommissioningProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHPCOMPONENTFACTORYRESETPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHPCOMPONENTFACTORYRESETPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHPCOMPONENTFACTORYRESETPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHPCOMPONENTFACTORYRESETPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHPCOMPONENTFACTORYRESETPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpComponentFactoryResetProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHpComponentFactoryResetProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpComponentFactoryResetProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHpComponentFactoryResetProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpComponentFactoryResetProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHpComponentFactoryResetProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHpComponentFactoryResetProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHpComponentFactoryResetProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHPDEICINGPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHPDEICINGPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHPDEICINGPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHPDEICINGPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHPDEICINGPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpDeicingProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHpDeicingProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpDeicingProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHpDeicingProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpDeicingProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHpDeicingProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHpDeicingProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHpDeicingProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHPELECTRICALPOWERLIMITATIONPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHPELECTRICALPOWERLIMITATIONPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHPELECTRICALPOWERLIMITATIONPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHPELECTRICALPOWERLIMITATIONPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHPELECTRICALPOWERLIMITATIONPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpElectricalPowerLimitationProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHpElectricalPowerLimitationProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpElectricalPowerLimitationProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHpElectricalPowerLimitationProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpElectricalPowerLimitationProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHpElectricalPowerLimitationProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHpElectricalPowerLimitationProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHpElectricalPowerLimitationProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHPGENERATORCONTROLINFOPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHPGENERATORCONTROLINFOPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHPGENERATORCONTROLINFOPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHPGENERATORCONTROLINFOPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHPGENERATORCONTROLINFOPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpGeneratorControlInfoProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHpGeneratorControlInfoProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpGeneratorControlInfoProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHpGeneratorControlInfoProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpGeneratorControlInfoProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHpGeneratorControlInfoProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHpGeneratorControlInfoProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHpGeneratorControlInfoProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHPSTANDBYPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHPSTANDBYPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHPSTANDBYPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHPSTANDBYPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHPSTANDBYPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpStandbyProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHpStandbyProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpStandbyProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHpStandbyProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpStandbyProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHpStandbyProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHpStandbyProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHpStandbyProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPHPTANKLOADINGPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPHPTANKLOADINGPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHPTANKLOADINGPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHPTANKLOADINGPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHPTANKLOADINGPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpTankLoadingProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApHpTankLoadingProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpTankLoadingProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApHpTankLoadingProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApHpTankLoadingProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHpTankLoadingProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHpTankLoadingProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHpTankLoadingProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPIDENTIFICATIONSTORAGE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPIDENTIFICATIONSTORAGE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPIDENTIFICATIONSTORAGE_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPIDENTIFICATIONSTORAGE_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPIDENTIFICATIONSTORAGE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApIdentificationStorage_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApIdentificationStorage_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApIdentificationStorage_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApIdentificationStorage_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApIdentificationStorage_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApIdentificationStorage_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApIdentificationStorage_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApIdentificationStorage_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPIDUODUINFOSPLITCONSUMERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPIDUODUINFOSPLITCONSUMERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPIDUODUINFOSPLITCONSUMERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPIDUODUINFOSPLITCONSUMERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPIDUODUINFOSPLITCONSUMERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApIduOduInfoSplitConsumerTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApIduOduInfoSplitConsumerTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApIduOduInfoSplitConsumerTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApIduOduInfoSplitConsumerTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApIduOduInfoSplitConsumerTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApIduOduInfoSplitConsumerTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApIduOduInfoSplitConsumerTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApIduOduInfoSplitConsumerTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPIDUODUINFOSPLITPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPIDUODUINFOSPLITPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPIDUODUINFOSPLITPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPIDUODUINFOSPLITPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPIDUODUINFOSPLITPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApIduOduInfoSplitProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApIduOduInfoSplitProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApIduOduInfoSplitProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApIduOduInfoSplitProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApIduOduInfoSplitProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApIduOduInfoSplitProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApIduOduInfoSplitProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApIduOduInfoSplitProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPINVERTERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPINVERTERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPINVERTERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPINVERTERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPINVERTERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApInverterTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApInverterTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApInverterTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApInverterTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApInverterTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApInverterTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApInverterTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApInverterTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPLINCOMPONENTSTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPLINCOMPONENTSTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPLINCOMPONENTSTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPLINCOMPONENTSTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPLINCOMPONENTSTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApLinComponentsTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApLinComponentsTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApLinComponentsTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApLinComponentsTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApLinComponentsTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApLinComponentsTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApLinComponentsTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApLinComponentsTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPLINDIAGNOSTICS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPLINDIAGNOSTICS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPLINDIAGNOSTICS_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPLINDIAGNOSTICS_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPLINDIAGNOSTICS_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApLinDiagnostics_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApLinDiagnostics_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApLinDiagnostics_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApLinDiagnostics_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApLinDiagnostics_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApLinDiagnostics_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApLinDiagnostics_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApLinDiagnostics_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPLINFLOWSENSOR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPLINFLOWSENSOR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPLINFLOWSENSOR_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPLINFLOWSENSOR_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPLINFLOWSENSOR_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApLinFlowSensor_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApLinFlowSensor_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApLinFlowSensor_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApLinFlowSensor_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApLinFlowSensor_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApLinFlowSensor_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApLinFlowSensor_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApLinFlowSensor_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPNOISEREDUCTIONCONTROLPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPNOISEREDUCTIONCONTROLPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPNOISEREDUCTIONCONTROLPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPNOISEREDUCTIONCONTROLPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPNOISEREDUCTIONCONTROLPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApNoiseReductionControlProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApNoiseReductionControlProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApNoiseReductionControlProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApNoiseReductionControlProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApNoiseReductionControlProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApNoiseReductionControlProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApNoiseReductionControlProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApNoiseReductionControlProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPOPENDOORMONSTATEPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPOPENDOORMONSTATEPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPOPENDOORMONSTATEPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPOPENDOORMONSTATEPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPOPENDOORMONSTATEPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApOpenDoorMonStateProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApOpenDoorMonStateProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApOpenDoorMonStateProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApOpenDoorMonStateProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApOpenDoorMonStateProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApOpenDoorMonStateProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApOpenDoorMonStateProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApOpenDoorMonStateProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPOPENDOORMONSUPPRESSIONPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPOPENDOORMONSUPPRESSIONPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPOPENDOORMONSUPPRESSIONPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPOPENDOORMONSUPPRESSIONPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPOPENDOORMONSUPPRESSIONPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApOpenDoorMonSuppressionProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApOpenDoorMonSuppressionProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApOpenDoorMonSuppressionProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApOpenDoorMonSuppressionProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApOpenDoorMonSuppressionProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApOpenDoorMonSuppressionProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApOpenDoorMonSuppressionProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApOpenDoorMonSuppressionProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPPASSIVECOOLINGMIXERTESTPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPPASSIVECOOLINGMIXERTESTPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPPASSIVECOOLINGMIXERTESTPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPPASSIVECOOLINGMIXERTESTPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPPASSIVECOOLINGMIXERTESTPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPassiveCoolingMixerTestProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApPassiveCoolingMixerTestProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPassiveCoolingMixerTestProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApPassiveCoolingMixerTestProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPassiveCoolingMixerTestProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApPassiveCoolingMixerTestProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApPassiveCoolingMixerTestProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApPassiveCoolingMixerTestProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPPASSIVECOOLINGTWVCONTROLPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPPASSIVECOOLINGTWVCONTROLPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPPASSIVECOOLINGTWVCONTROLPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPPASSIVECOOLINGTWVCONTROLPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPPASSIVECOOLINGTWVCONTROLPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPassiveCoolingTwvControlProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApPassiveCoolingTwvControlProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPassiveCoolingTwvControlProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApPassiveCoolingTwvControlProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPassiveCoolingTwvControlProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApPassiveCoolingTwvControlProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApPassiveCoolingTwvControlProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApPassiveCoolingTwvControlProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPPIPETRACEHEATERTESTPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPPIPETRACEHEATERTESTPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPPIPETRACEHEATERTESTPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPPIPETRACEHEATERTESTPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPPIPETRACEHEATERTESTPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPipeTraceHeaterTestProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApPipeTraceHeaterTestProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPipeTraceHeaterTestProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApPipeTraceHeaterTestProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPipeTraceHeaterTestProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApPipeTraceHeaterTestProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApPipeTraceHeaterTestProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApPipeTraceHeaterTestProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPPRESSURELOSSCOEFFICIENTPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPPRESSURELOSSCOEFFICIENTPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPPRESSURELOSSCOEFFICIENTPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPPRESSURELOSSCOEFFICIENTPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPPRESSURELOSSCOEFFICIENTPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPressureLossCoefficientProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApPressureLossCoefficientProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPressureLossCoefficientProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApPressureLossCoefficientProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPressureLossCoefficientProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApPressureLossCoefficientProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApPressureLossCoefficientProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApPressureLossCoefficientProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPPROVIDESERVICEHANDLER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPPROVIDESERVICEHANDLER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPPROVIDESERVICEHANDLER_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPPROVIDESERVICEHANDLER_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPPROVIDESERVICEHANDLER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApProvideServiceHandler_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApProvideServiceHandler_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApProvideServiceHandler_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApProvideServiceHandler_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApProvideServiceHandler_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApProvideServiceHandler_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApProvideServiceHandler_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApProvideServiceHandler_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPPUMPCONTROLINFOPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPPUMPCONTROLINFOPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPPUMPCONTROLINFOPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPPUMPCONTROLINFOPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPPUMPCONTROLINFOPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpControlInfoProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApPumpControlInfoProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpControlInfoProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApPumpControlInfoProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpControlInfoProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApPumpControlInfoProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApPumpControlInfoProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApPumpControlInfoProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPPUMPPRESSUREDIFFERENCECONTROLPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPPUMPPRESSUREDIFFERENCECONTROLPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPPUMPPRESSUREDIFFERENCECONTROLPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPPUMPPRESSUREDIFFERENCECONTROLPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPPUMPPRESSUREDIFFERENCECONTROLPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpPressureDifferenceControlProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApPumpPressureDifferenceControlProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpPressureDifferenceControlProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApPumpPressureDifferenceControlProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpPressureDifferenceControlProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApPumpPressureDifferenceControlProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApPumpPressureDifferenceControlProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApPumpPressureDifferenceControlProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPPUMPSPEEDCONTROLPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPPUMPSPEEDCONTROLPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPPUMPSPEEDCONTROLPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPPUMPSPEEDCONTROLPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPPUMPSPEEDCONTROLPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpSpeedControlProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApPumpSpeedControlProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpSpeedControlProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApPumpSpeedControlProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpSpeedControlProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApPumpSpeedControlProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApPumpSpeedControlProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApPumpSpeedControlProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPPUMPSTANDBYPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPPUMPSTANDBYPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPPUMPSTANDBYPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPPUMPSTANDBYPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPPUMPSTANDBYPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpStandbyProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApPumpStandbyProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpStandbyProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApPumpStandbyProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpStandbyProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApPumpStandbyProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApPumpStandbyProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApPumpStandbyProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPPUMPVOLUMEFLOWCONTROLPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPPUMPVOLUMEFLOWCONTROLPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPPUMPVOLUMEFLOWCONTROLPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPPUMPVOLUMEFLOWCONTROLPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPPUMPVOLUMEFLOWCONTROLPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpVolumeFlowControlProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApPumpVolumeFlowControlProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpVolumeFlowControlProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApPumpVolumeFlowControlProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPumpVolumeFlowControlProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApPumpVolumeFlowControlProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApPumpVolumeFlowControlProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApPumpVolumeFlowControlProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPPWMPUMP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPPWMPUMP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPPWMPUMP_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPPWMPUMP_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPPWMPUMP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPwmPump_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApPwmPump_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPwmPump_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApPwmPump_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApPwmPump_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApPwmPump_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApPwmPump_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApPwmPump_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPRCMENERGYMETERINGFUNCTIONPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPRCMENERGYMETERINGFUNCTIONPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPRCMENERGYMETERINGFUNCTIONPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPRCMENERGYMETERINGFUNCTIONPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPRCMENERGYMETERINGFUNCTIONPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApRcmEnergyMeteringFunctionProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApRcmEnergyMeteringFunctionProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApRcmEnergyMeteringFunctionProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApRcmEnergyMeteringFunctionProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApRcmEnergyMeteringFunctionProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApRcmEnergyMeteringFunctionProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApRcmEnergyMeteringFunctionProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApRcmEnergyMeteringFunctionProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPREFRIGERANTCIRCUITINFOPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPREFRIGERANTCIRCUITINFOPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPREFRIGERANTCIRCUITINFOPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPREFRIGERANTCIRCUITINFOPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPREFRIGERANTCIRCUITINFOPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApRefrigerantCircuitInfoProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApRefrigerantCircuitInfoProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApRefrigerantCircuitInfoProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApRefrigerantCircuitInfoProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApRefrigerantCircuitInfoProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApRefrigerantCircuitInfoProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApRefrigerantCircuitInfoProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApRefrigerantCircuitInfoProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPRUNTIMEMONITOR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPRUNTIMEMONITOR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPRUNTIMEMONITOR_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPRUNTIMEMONITOR_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPRUNTIMEMONITOR_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApRuntimeMonitor_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApRuntimeMonitor_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApRuntimeMonitor_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApRuntimeMonitor_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApRuntimeMonitor_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApRuntimeMonitor_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApRuntimeMonitor_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApRuntimeMonitor_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSENSORACTUATORTESTIOMU_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSENSORACTUATORTESTIOMU_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSENSORACTUATORTESTIOMU_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSENSORACTUATORTESTIOMU_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSENSORACTUATORTESTIOMU_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSensorActuatorTestIomu_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSensorActuatorTestIomu_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSensorActuatorTestIomu_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSensorActuatorTestIomu_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSensorActuatorTestIomu_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSensorActuatorTestIomu_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSensorActuatorTestIomu_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSensorActuatorTestIomu_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSERVICEACTIVATIONPSW_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSERVICEACTIVATIONPSW_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSERVICEACTIVATIONPSW_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSERVICEACTIVATIONPSW_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSERVICEACTIVATIONPSW_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApServiceActivationPsw_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApServiceActivationPsw_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApServiceActivationPsw_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApServiceActivationPsw_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApServiceActivationPsw_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApServiceActivationPsw_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApServiceActivationPsw_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApServiceActivationPsw_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSERVICEVARIANTHANDLER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSERVICEVARIANTHANDLER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSERVICEVARIANTHANDLER_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSERVICEVARIANTHANDLER_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSERVICEVARIANTHANDLER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApServiceVariantHandler_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApServiceVariantHandler_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApServiceVariantHandler_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApServiceVariantHandler_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApServiceVariantHandler_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApServiceVariantHandler_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApServiceVariantHandler_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApServiceVariantHandler_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSTACKMONITOR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSTACKMONITOR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSTACKMONITOR_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSTACKMONITOR_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSTACKMONITOR_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApStackMonitor_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApStackMonitor_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApStackMonitor_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApStackMonitor_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApStackMonitor_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApStackMonitor_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApStackMonitor_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApStackMonitor_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSIODHWCYLINDERTEMPERATURE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSIODHWCYLINDERTEMPERATURE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSIODHWCYLINDERTEMPERATURE_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSIODHWCYLINDERTEMPERATURE_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSIODHWCYLINDERTEMPERATURE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoDhwCylinderTemperature_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSysIoDhwCylinderTemperature_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoDhwCylinderTemperature_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSysIoDhwCylinderTemperature_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoDhwCylinderTemperature_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSysIoDhwCylinderTemperature_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSysIoDhwCylinderTemperature_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSysIoDhwCylinderTemperature_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSIODHWTHERMOSTAT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSIODHWTHERMOSTAT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSIODHWTHERMOSTAT_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSIODHWTHERMOSTAT_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSIODHWTHERMOSTAT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoDhwThermostat_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSysIoDhwThermostat_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoDhwThermostat_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSysIoDhwThermostat_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoDhwThermostat_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSysIoDhwThermostat_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSysIoDhwThermostat_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSysIoDhwThermostat_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSIOFLOORHEATINGCONTACT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSIOFLOORHEATINGCONTACT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSIOFLOORHEATINGCONTACT_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSIOFLOORHEATINGCONTACT_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSIOFLOORHEATINGCONTACT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoFloorHeatingContact_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSysIoFloorHeatingContact_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoFloorHeatingContact_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSysIoFloorHeatingContact_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoFloorHeatingContact_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSysIoFloorHeatingContact_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSysIoFloorHeatingContact_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSysIoFloorHeatingContact_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSIOHYBRIDOUTPUT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSIOHYBRIDOUTPUT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSIOHYBRIDOUTPUT_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSIOHYBRIDOUTPUT_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSIOHYBRIDOUTPUT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoHybridOutput_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSysIoHybridOutput_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoHybridOutput_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSysIoHybridOutput_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoHybridOutput_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSysIoHybridOutput_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSysIoHybridOutput_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSysIoHybridOutput_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSIOMULTIFUNCTIONINPUT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSIOMULTIFUNCTIONINPUT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSIOMULTIFUNCTIONINPUT_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSIOMULTIFUNCTIONINPUT_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSIOMULTIFUNCTIONINPUT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoMultiFunctionInput_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSysIoMultiFunctionInput_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoMultiFunctionInput_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSysIoMultiFunctionInput_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoMultiFunctionInput_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSysIoMultiFunctionInput_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSysIoMultiFunctionInput_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSysIoMultiFunctionInput_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSIOMULTIFUNCTIONOUTPUT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSIOMULTIFUNCTIONOUTPUT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSIOMULTIFUNCTIONOUTPUT_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSIOMULTIFUNCTIONOUTPUT_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSIOMULTIFUNCTIONOUTPUT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoMultiFunctionOutput_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSysIoMultiFunctionOutput_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoMultiFunctionOutput_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSysIoMultiFunctionOutput_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoMultiFunctionOutput_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSysIoMultiFunctionOutput_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSysIoMultiFunctionOutput_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSysIoMultiFunctionOutput_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSIOOUTDOORTEMPERATURE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSIOOUTDOORTEMPERATURE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSIOOUTDOORTEMPERATURE_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSIOOUTDOORTEMPERATURE_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSIOOUTDOORTEMPERATURE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoOutdoorTemperature_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSysIoOutdoorTemperature_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoOutdoorTemperature_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSysIoOutdoorTemperature_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoOutdoorTemperature_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSysIoOutdoorTemperature_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSysIoOutdoorTemperature_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSysIoOutdoorTemperature_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSIOPRIMARYCIRCUITPRESSURE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSIOPRIMARYCIRCUITPRESSURE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSIOPRIMARYCIRCUITPRESSURE_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSIOPRIMARYCIRCUITPRESSURE_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSIOPRIMARYCIRCUITPRESSURE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoPrimaryCircuitPressure_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSysIoPrimaryCircuitPressure_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoPrimaryCircuitPressure_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSysIoPrimaryCircuitPressure_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoPrimaryCircuitPressure_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSysIoPrimaryCircuitPressure_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSysIoPrimaryCircuitPressure_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSysIoPrimaryCircuitPressure_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSIOSECONDARYCIRCUITPRESSURE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSIOSECONDARYCIRCUITPRESSURE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSIOSECONDARYCIRCUITPRESSURE_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSIOSECONDARYCIRCUITPRESSURE_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSIOSECONDARYCIRCUITPRESSURE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoSecondaryCircuitPressure_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSysIoSecondaryCircuitPressure_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoSecondaryCircuitPressure_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSysIoSecondaryCircuitPressure_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoSecondaryCircuitPressure_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSysIoSecondaryCircuitPressure_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSysIoSecondaryCircuitPressure_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSysIoSecondaryCircuitPressure_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSIOSYSTEMFLOWRATE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSIOSYSTEMFLOWRATE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSIOSYSTEMFLOWRATE_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSIOSYSTEMFLOWRATE_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSIOSYSTEMFLOWRATE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoSystemFlowRate_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSysIoSystemFlowRate_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoSystemFlowRate_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSysIoSystemFlowRate_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoSystemFlowRate_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSysIoSystemFlowRate_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSysIoSystemFlowRate_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSysIoSystemFlowRate_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSIOSYSTEMFLOWTEMPERATURE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSIOSYSTEMFLOWTEMPERATURE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSIOSYSTEMFLOWTEMPERATURE_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSIOSYSTEMFLOWTEMPERATURE_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSIOSYSTEMFLOWTEMPERATURE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoSystemFlowTemperature_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSysIoSystemFlowTemperature_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoSystemFlowTemperature_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSysIoSystemFlowTemperature_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSysIoSystemFlowTemperature_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSysIoSystemFlowTemperature_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSysIoSystemFlowTemperature_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSysIoSystemFlowTemperature_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSTEMCOMMISSIONINGCONSUMERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSTEMCOMMISSIONINGCONSUMERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSTEMCOMMISSIONINGCONSUMERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSTEMCOMMISSIONINGCONSUMERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSTEMCOMMISSIONINGCONSUMERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSystemCommissioningConsumerTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSystemCommissioningConsumerTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSystemCommissioningConsumerTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSystemCommissioningConsumerTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSystemCommissioningConsumerTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSystemCommissioningConsumerTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSystemCommissioningConsumerTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSystemCommissioningConsumerTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSTEMFILLINGSTATUSCONSUMERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSTEMFILLINGSTATUSCONSUMERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSTEMFILLINGSTATUSCONSUMERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSTEMFILLINGSTATUSCONSUMERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSTEMFILLINGSTATUSCONSUMERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSystemFillingStatusConsumerTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSystemFillingStatusConsumerTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSystemFillingStatusConsumerTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSystemFillingStatusConsumerTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSystemFillingStatusConsumerTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSystemFillingStatusConsumerTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSystemFillingStatusConsumerTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSystemFillingStatusConsumerTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSTEMMODEOFFCONSUMERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSTEMMODEOFFCONSUMERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSTEMMODEOFFCONSUMERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSTEMMODEOFFCONSUMERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSTEMMODEOFFCONSUMERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSystemModeOffConsumerTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSystemModeOffConsumerTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSystemModeOffConsumerTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSystemModeOffConsumerTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSystemModeOffConsumerTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSystemModeOffConsumerTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSystemModeOffConsumerTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSystemModeOffConsumerTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSYSTEMOUTDOORTEMPERATURECONSUMERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSYSTEMOUTDOORTEMPERATURECONSUMERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSTEMOUTDOORTEMPERATURECONSUMERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSTEMOUTDOORTEMPERATURECONSUMERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSTEMOUTDOORTEMPERATURECONSUMERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSystemOutdoorTemperatureConsumerTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSystemOutdoorTemperatureConsumerTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSystemOutdoorTemperatureConsumerTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSystemOutdoorTemperatureConsumerTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSystemOutdoorTemperatureConsumerTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSystemOutdoorTemperatureConsumerTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSystemOutdoorTemperatureConsumerTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSystemOutdoorTemperatureConsumerTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPTEMPERATURESENSORCALIBRATIONPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPTEMPERATURESENSORCALIBRATIONPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPTEMPERATURESENSORCALIBRATIONPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPTEMPERATURESENSORCALIBRATIONPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPTEMPERATURESENSORCALIBRATIONPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTemperatureSensorCalibrationProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApTemperatureSensorCalibrationProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTemperatureSensorCalibrationProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApTemperatureSensorCalibrationProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTemperatureSensorCalibrationProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApTemperatureSensorCalibrationProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApTemperatureSensorCalibrationProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApTemperatureSensorCalibrationProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPTESTMASTER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPTESTMASTER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPTESTMASTER_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPTESTMASTER_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPTESTMASTER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTestMaster_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApTestMaster_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTestMaster_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApTestMaster_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTestMaster_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApTestMaster_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApTestMaster_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApTestMaster_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPTIMESYNC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPTIMESYNC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPTIMESYNC_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPTIMESYNC_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPTIMESYNC_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTimeSync_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApTimeSync_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTimeSync_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApTimeSync_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTimeSync_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApTimeSync_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApTimeSync_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApTimeSync_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPTOPOLOGYSERVICECLIENT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPTOPOLOGYSERVICECLIENT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPTOPOLOGYSERVICECLIENT_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPTOPOLOGYSERVICECLIENT_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPTOPOLOGYSERVICECLIENT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTopologyServiceClient_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApTopologyServiceClient_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTopologyServiceClient_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApTopologyServiceClient_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTopologyServiceClient_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApTopologyServiceClient_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApTopologyServiceClient_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApTopologyServiceClient_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPTWVCONTROLPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPTWVCONTROLPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPTWVCONTROLPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPTWVCONTROLPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPTWVCONTROLPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTwvControlProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApTwvControlProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTwvControlProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApTwvControlProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApTwvControlProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApTwvControlProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApTwvControlProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApTwvControlProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPWELLCIRCUITTEMPERATUREPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPWELLCIRCUITTEMPERATUREPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPWELLCIRCUITTEMPERATUREPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPWELLCIRCUITTEMPERATUREPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPWELLCIRCUITTEMPERATUREPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApWellCircuitTemperatureProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApWellCircuitTemperatureProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApWellCircuitTemperatureProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApWellCircuitTemperatureProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApWellCircuitTemperatureProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApWellCircuitTemperatureProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApWellCircuitTemperatureProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApWellCircuitTemperatureProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPWELLPUMPTESTPROVIDERTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPWELLPUMPTESTPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPWELLPUMPTESTPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPWELLPUMPTESTPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPWELLPUMPTESTPROVIDERTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApWellPumpTestProviderTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApWellPumpTestProviderTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApWellPumpTestProviderTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApWellPumpTestProviderTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApWellPumpTestProviderTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApWellPumpTestProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApWellPumpTestProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApWellPumpTestProviderTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTCDDDEMWRAPPER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTCDDDEMWRAPPER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTCDDDEMWRAPPER_APPL_DATA

/* used for references on application functions */
# define RTE_CTCDDDEMWRAPPER_APPL_CODE

/* used for references on application constants */
# define RTE_CTCDDDEMWRAPPER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddDemWrapper_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtCddDemWrapper_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddDemWrapper_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtCddDemWrapper_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddDemWrapper_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtCddDemWrapper_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtCddDemWrapper_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtCddDemWrapper_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTCDDLIFETIMETEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTCDDLIFETIMETEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTCDDLIFETIMETEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTCDDLIFETIMETEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTCDDLIFETIMETEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddLifeTimeTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtCddLifeTimeTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddLifeTimeTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtCddLifeTimeTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddLifeTimeTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtCddLifeTimeTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtCddLifeTimeTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtCddLifeTimeTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTCDDLINTP_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTCDDLINTP_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTCDDLINTP_APPL_DATA

/* used for references on application functions */
# define RTE_CTCDDLINTP_APPL_CODE

/* used for references on application constants */
# define RTE_CTCDDLINTP_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddLinTp_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtCddLinTp_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddLinTp_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtCddLinTp_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddLinTp_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtCddLinTp_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtCddLinTp_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtCddLinTp_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTCDDMODBUS_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTCDDMODBUS_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTCDDMODBUS_APPL_DATA

/* used for references on application functions */
# define RTE_CTCDDMODBUS_APPL_CODE

/* used for references on application constants */
# define RTE_CTCDDMODBUS_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddModbus_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtCddModbus_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddModbus_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtCddModbus_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddModbus_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtCddModbus_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtCddModbus_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtCddModbus_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTCDDUART_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTCDDUART_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTCDDUART_APPL_DATA

/* used for references on application functions */
# define RTE_CTCDDUART_APPL_CODE

/* used for references on application constants */
# define RTE_CTCDDUART_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddUart_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtCddUart_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddUart_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtCddUart_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCddUart_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtCddUart_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtCddUart_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtCddUart_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTIOHWAB_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTIOHWAB_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTIOHWAB_APPL_DATA

/* used for references on application functions */
# define RTE_CTIOHWAB_APPL_CODE

/* used for references on application constants */
# define RTE_CTIOHWAB_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtIoHwAb_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtIoHwAb_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtIoHwAb_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtIoHwAb_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtIoHwAb_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtIoHwAb_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtIoHwAb_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtIoHwAb_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSASENSORANALOGTEMPERATURE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSASENSORANALOGTEMPERATURE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSASENSORANALOGTEMPERATURE_APPL_DATA

/* used for references on application functions */
# define RTE_CTSASENSORANALOGTEMPERATURE_APPL_CODE

/* used for references on application constants */
# define RTE_CTSASENSORANALOGTEMPERATURE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorAnalogTemperature_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaSensorAnalogTemperature_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorAnalogTemperature_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaSensorAnalogTemperature_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorAnalogTemperature_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaSensorAnalogTemperature_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaSensorAnalogTemperature_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaSensorAnalogTemperature_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSADIGIN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSADIGIN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSADIGIN_APPL_DATA

/* used for references on application functions */
# define RTE_CTSADIGIN_APPL_CODE

/* used for references on application constants */
# define RTE_CTSADIGIN_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaDigIn_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaDigIn_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaDigIn_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaDigIn_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaDigIn_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaDigIn_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaDigIn_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaDigIn_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSASENSORPWMIN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSASENSORPWMIN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSASENSORPWMIN_APPL_DATA

/* used for references on application functions */
# define RTE_CTSASENSORPWMIN_APPL_CODE

/* used for references on application constants */
# define RTE_CTSASENSORPWMIN_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorPwmIn_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaSensorPwmIn_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorPwmIn_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaSensorPwmIn_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorPwmIn_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaSensorPwmIn_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaSensorPwmIn_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaSensorPwmIn_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSADIGOUT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSADIGOUT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSADIGOUT_APPL_DATA

/* used for references on application functions */
# define RTE_CTSADIGOUT_APPL_CODE

/* used for references on application constants */
# define RTE_CTSADIGOUT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaDigOut_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaDigOut_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaDigOut_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaDigOut_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaDigOut_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaDigOut_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaDigOut_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaDigOut_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSASENSORANALOGVOLTAGEMON_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSASENSORANALOGVOLTAGEMON_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSASENSORANALOGVOLTAGEMON_APPL_DATA

/* used for references on application functions */
# define RTE_CTSASENSORANALOGVOLTAGEMON_APPL_CODE

/* used for references on application constants */
# define RTE_CTSASENSORANALOGVOLTAGEMON_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorAnalogVoltageMon_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaSensorAnalogVoltageMon_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorAnalogVoltageMon_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaSensorAnalogVoltageMon_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorAnalogVoltageMon_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaSensorAnalogVoltageMon_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaSensorAnalogVoltageMon_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaSensorAnalogVoltageMon_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSAEBHRELAY_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSAEBHRELAY_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSAEBHRELAY_APPL_DATA

/* used for references on application functions */
# define RTE_CTSAEBHRELAY_APPL_CODE

/* used for references on application constants */
# define RTE_CTSAEBHRELAY_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaEbhRelay_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaEbhRelay_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaEbhRelay_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaEbhRelay_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaEbhRelay_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaEbhRelay_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaEbhRelay_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaEbhRelay_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSASENSORANALOGPRESSURE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSASENSORANALOGPRESSURE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSASENSORANALOGPRESSURE_APPL_DATA

/* used for references on application functions */
# define RTE_CTSASENSORANALOGPRESSURE_APPL_CODE

/* used for references on application constants */
# define RTE_CTSASENSORANALOGPRESSURE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorAnalogPressure_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaSensorAnalogPressure_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorAnalogPressure_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaSensorAnalogPressure_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorAnalogPressure_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaSensorAnalogPressure_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaSensorAnalogPressure_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaSensorAnalogPressure_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSAPWMOUT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSAPWMOUT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSAPWMOUT_APPL_DATA

/* used for references on application functions */
# define RTE_CTSAPWMOUT_APPL_CODE

/* used for references on application constants */
# define RTE_CTSAPWMOUT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaPwmOut_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaPwmOut_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaPwmOut_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaPwmOut_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaPwmOut_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaPwmOut_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaPwmOut_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaPwmOut_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSADIGOUTPWMOUT_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSADIGOUTPWMOUT_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSADIGOUTPWMOUT_APPL_DATA

/* used for references on application functions */
# define RTE_CTSADIGOUTPWMOUT_APPL_CODE

/* used for references on application constants */
# define RTE_CTSADIGOUTPWMOUT_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaDigOutPwmOut_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaDigOutPwmOut_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaDigOutPwmOut_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaDigOutPwmOut_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaDigOutPwmOut_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaDigOutPwmOut_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaDigOutPwmOut_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaDigOutPwmOut_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSASENSORANALOGDYNAMICCURVE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSASENSORANALOGDYNAMICCURVE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSASENSORANALOGDYNAMICCURVE_APPL_DATA

/* used for references on application functions */
# define RTE_CTSASENSORANALOGDYNAMICCURVE_APPL_CODE

/* used for references on application constants */
# define RTE_CTSASENSORANALOGDYNAMICCURVE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorAnalogDynamicCurve_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaSensorAnalogDynamicCurve_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorAnalogDynamicCurve_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaSensorAnalogDynamicCurve_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorAnalogDynamicCurve_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaSensorAnalogDynamicCurve_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaSensorAnalogDynamicCurve_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaSensorAnalogDynamicCurve_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSASENSORCURVES_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSASENSORCURVES_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSASENSORCURVES_APPL_DATA

/* used for references on application functions */
# define RTE_CTSASENSORCURVES_APPL_CODE

/* used for references on application constants */
# define RTE_CTSASENSORCURVES_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorCurves_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaSensorCurves_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorCurves_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaSensorCurves_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorCurves_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaSensorCurves_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaSensorCurves_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaSensorCurves_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSASTEPPERMOTOR_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSASTEPPERMOTOR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSASTEPPERMOTOR_APPL_DATA

/* used for references on application functions */
# define RTE_CTSASTEPPERMOTOR_APPL_CODE

/* used for references on application constants */
# define RTE_CTSASTEPPERMOTOR_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaStepperMotor_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaStepperMotor_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaStepperMotor_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaStepperMotor_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaStepperMotor_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaStepperMotor_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaStepperMotor_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaStepperMotor_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSASTEPPERMOTORMANAGER_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSASTEPPERMOTORMANAGER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSASTEPPERMOTORMANAGER_APPL_DATA

/* used for references on application functions */
# define RTE_CTSASTEPPERMOTORMANAGER_APPL_CODE

/* used for references on application constants */
# define RTE_CTSASTEPPERMOTORMANAGER_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaStepperMotorManager_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaStepperMotorManager_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaStepperMotorManager_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaStepperMotorManager_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaStepperMotorManager_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaStepperMotorManager_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaStepperMotorManager_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaStepperMotorManager_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTSASENSORVORTEX_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTSASENSORVORTEX_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSASENSORVORTEX_APPL_DATA

/* used for references on application functions */
# define RTE_CTSASENSORVORTEX_APPL_CODE

/* used for references on application constants */
# define RTE_CTSASENSORVORTEX_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorVortex_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtSaSensorVortex_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorVortex_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtSaSensorVortex_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtSaSensorVortex_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaSensorVortex_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaSensorVortex_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaSensorVortex_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CSM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CSM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CSM_APPL_DATA

/* used for references on application functions */
# define RTE_CSM_APPL_CODE

/* used for references on application constants */
# define RTE_CSM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Csm_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Csm_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Csm_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Csm_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Csm_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Csm_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Csm_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Csm_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPDTCTEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPDTCTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPDTCTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPDTCTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPDTCTEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDtcTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApDtcTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDtcTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApDtcTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApDtcTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApDtcTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApDtcTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApDtcTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPNVDATABASETEST_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPNVDATABASETEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPNVDATABASETEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPNVDATABASETEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPNVDATABASETEST_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApNvDatabaseTest_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApNvDatabaseTest_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApNvDatabaseTest_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApNvDatabaseTest_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApNvDatabaseTest_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApNvDatabaseTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApNvDatabaseTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApNvDatabaseTest_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPSENSORACTUATORTESTHMU_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPSENSORACTUATORTESTHMU_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSENSORACTUATORTESTHMU_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSENSORACTUATORTESTHMU_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSENSORACTUATORTESTHMU_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSensorActuatorTestHmu_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApSensorActuatorTestHmu_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSensorActuatorTestHmu_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApSensorActuatorTestHmu_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApSensorActuatorTestHmu_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSensorActuatorTestHmu_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSensorActuatorTestHmu_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSensorActuatorTestHmu_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DCM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DCM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DCM_APPL_DATA

/* used for references on application functions */
# define RTE_DCM_APPL_CODE

/* used for references on application constants */
# define RTE_DCM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Dcm_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Dcm_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Dcm_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Dcm_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Dcm_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Dcm_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DEMMASTER_SYSTEMAPPLICATION_OSCORE0_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DEMMASTER_SYSTEMAPPLICATION_OSCORE0_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DEMMASTER_SYSTEMAPPLICATION_OSCORE0_APPL_DATA

/* used for references on application functions */
# define RTE_DEMMASTER_SYSTEMAPPLICATION_OSCORE0_APPL_CODE

/* used for references on application constants */
# define RTE_DEMMASTER_SYSTEMAPPLICATION_OSCORE0_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemMaster_SystemApplication_OsCore0_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DemMaster_SystemApplication_OsCore0_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemMaster_SystemApplication_OsCore0_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DemMaster_SystemApplication_OsCore0_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemMaster_SystemApplication_OsCore0_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DemMaster_SystemApplication_OsCore0_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DemMaster_SystemApplication_OsCore0_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DemMaster_SystemApplication_OsCore0_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DEMSATELLITE_SYSTEMAPPLICATION_OSCORE0_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DEMSATELLITE_SYSTEMAPPLICATION_OSCORE0_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DEMSATELLITE_SYSTEMAPPLICATION_OSCORE0_APPL_DATA

/* used for references on application functions */
# define RTE_DEMSATELLITE_SYSTEMAPPLICATION_OSCORE0_APPL_CODE

/* used for references on application constants */
# define RTE_DEMSATELLITE_SYSTEMAPPLICATION_OSCORE0_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemSatellite_SystemApplication_OsCore0_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define DemSatellite_SystemApplication_OsCore0_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemSatellite_SystemApplication_OsCore0_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define DemSatellite_SystemApplication_OsCore0_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: DemSatellite_SystemApplication_OsCore0_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define DemSatellite_SystemApplication_OsCore0_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define DemSatellite_SystemApplication_OsCore0_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define DemSatellite_SystemApplication_OsCore0_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_DET_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_DET_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_DET_APPL_DATA

/* used for references on application functions */
# define RTE_DET_APPL_CODE

/* used for references on application constants */
# define RTE_DET_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Det_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Det_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Det_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Det_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Det_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Det_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Det_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Det_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_ECUM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_ECUM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_ECUM_APPL_DATA

/* used for references on application functions */
# define RTE_ECUM_APPL_CODE

/* used for references on application constants */
# define RTE_ECUM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define EcuM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define EcuM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: EcuM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define EcuM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define EcuM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define EcuM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_FIMMASTER_SYSTEMAPPLICATION_OSCORE0_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_FIMMASTER_SYSTEMAPPLICATION_OSCORE0_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_FIMMASTER_SYSTEMAPPLICATION_OSCORE0_APPL_DATA

/* used for references on application functions */
# define RTE_FIMMASTER_SYSTEMAPPLICATION_OSCORE0_APPL_CODE

/* used for references on application constants */
# define RTE_FIMMASTER_SYSTEMAPPLICATION_OSCORE0_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FiMMaster_SystemApplication_OsCore0_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define FiMMaster_SystemApplication_OsCore0_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FiMMaster_SystemApplication_OsCore0_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define FiMMaster_SystemApplication_OsCore0_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FiMMaster_SystemApplication_OsCore0_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define FiMMaster_SystemApplication_OsCore0_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define FiMMaster_SystemApplication_OsCore0_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define FiMMaster_SystemApplication_OsCore0_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_FIMSATELLITE_SYSTEMAPPLICATION_OSCORE0_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_FIMSATELLITE_SYSTEMAPPLICATION_OSCORE0_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_FIMSATELLITE_SYSTEMAPPLICATION_OSCORE0_APPL_DATA

/* used for references on application functions */
# define RTE_FIMSATELLITE_SYSTEMAPPLICATION_OSCORE0_APPL_CODE

/* used for references on application constants */
# define RTE_FIMSATELLITE_SYSTEMAPPLICATION_OSCORE0_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FiMSatellite_SystemApplication_OsCore0_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define FiMSatellite_SystemApplication_OsCore0_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FiMSatellite_SystemApplication_OsCore0_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define FiMSatellite_SystemApplication_OsCore0_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: FiMSatellite_SystemApplication_OsCore0_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define FiMSatellite_SystemApplication_OsCore0_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define FiMSatellite_SystemApplication_OsCore0_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define FiMSatellite_SystemApplication_OsCore0_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_KEYM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_KEYM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_KEYM_APPL_DATA

/* used for references on application functions */
# define RTE_KEYM_APPL_CODE

/* used for references on application constants */
# define RTE_KEYM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define KeyM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define KeyM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: KeyM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define KeyM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define KeyM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define KeyM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTAPMAIN_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTAPMAIN_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPMAIN_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPMAIN_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPMAIN_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApMain_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtApMain_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApMain_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtApMain_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtApMain_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApMain_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApMain_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApMain_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_NVM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_NVM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_NVM_APPL_DATA

/* used for references on application functions */
# define RTE_NVM_APPL_CODE

/* used for references on application constants */
# define RTE_NVM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define NvM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define NvM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: NvM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define NvM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define NvM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define NvM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_OS_OSCORE0_SWC_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_OS_OSCORE0_SWC_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_OS_OSCORE0_SWC_APPL_DATA

/* used for references on application functions */
# define RTE_OS_OSCORE0_SWC_APPL_CODE

/* used for references on application constants */
# define RTE_OS_OSCORE0_SWC_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Os_OsCore0_swc_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define Os_OsCore0_swc_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Os_OsCore0_swc_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define Os_OsCore0_swc_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: Os_OsCore0_swc_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define Os_OsCore0_swc_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define Os_OsCore0_swc_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define Os_OsCore0_swc_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_WDGM_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_WDGM_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_WDGM_APPL_DATA

/* used for references on application functions */
# define RTE_WDGM_APPL_CODE

/* used for references on application constants */
# define RTE_WDGM_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define WdgM_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define WdgM_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: WdgM_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define WdgM_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define WdgM_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define WdgM_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CTNVDATABASE_APPL
 *********************************************************************************************************************/

/* used for references on application variables */
# define RTE_CTNVDATABASE_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTNVDATABASE_APPL_DATA

/* used for references on application functions */
# define RTE_CTNVDATABASE_APPL_CODE

/* used for references on application constants */
# define RTE_CTNVDATABASE_APPL_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtNvDatabase_CODE
 *********************************************************************************************************************/

/* used for SWC specific code */
# define CtNvDatabase_CODE

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtNvDatabase_CONST
 *********************************************************************************************************************/

/* used for global or static SWC specific constants */
# define CtNvDatabase_CONST

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: CtNvDatabase_VAR
 *********************************************************************************************************************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtNvDatabase_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtNvDatabase_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtNvDatabase_VAR_ZERO_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Calibration Parameter specific defines
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_CONST_PLATFORMCALPRM_ADDR_METHOD
 *********************************************************************************************************************/

# define RTE_CONST_PLATFORMCALPRM_ADDR_METHOD

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VAR_PLATFORMCALPRM_ADDR_METHOD
 *********************************************************************************************************************/

# define RTE_VAR_PLATFORMCALPRM_ADDR_METHOD

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Per-Instance Memory specific defines
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VAR_DEFAULT_RTE_PIM_GROUP
 *********************************************************************************************************************/

# define RTE_VAR_DEFAULT_RTE_PIM_GROUP

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!     << Start of compiler abstraction implementation >>       DO NOT CHANGE THIS COMMENT!
 * Symbol: RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT
 *********************************************************************************************************************/

# define RTE_VAR_DEFAULT_RTE_PIM_GROUP_INIT

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!      << End of compiler abstraction implementation >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApPersistentDataHandler_VAR)  ******/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApPersistentDataHandler_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApPersistentDataHandler_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApPersistentDataHandler_VAR_ZERO_INIT

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApPersistentDataHandler_CONST)  ****/

/* used for global or static SWC specific constants */
# define CtApPersistentDataHandler_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApBmuPswNvDataTest_CONST)  *********/

/* used for global or static SWC specific constants */
# define CtApBmuPswNvDataTest_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CTAPPERSISTENTDATAHANDLER_APPL)  */

/* used for references on application variables */
# define RTE_CTAPPERSISTENTDATAHANDLER_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPPERSISTENTDATAHANDLER_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPPERSISTENTDATAHANDLER_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPPERSISTENTDATAHANDLER_APPL_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApBmuPswNvDataTest_CODE)  **********/

/* used for SWC specific code */
# define CtApBmuPswNvDataTest_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtNvDataBlock_VAR)  ******************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtNvDataBlock_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtNvDataBlock_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtNvDataBlock_VAR_ZERO_INIT

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApPlatformNvData_VAR)  *************/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApPlatformNvData_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApPlatformNvData_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApPlatformNvData_VAR_ZERO_INIT

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CTAPHMUPSWNVDATATEST_APPL)  ******/

/* used for references on application variables */
# define RTE_CTAPHMUPSWNVDATATEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPHMUPSWNVDATATEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPHMUPSWNVDATATEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPHMUPSWNVDATATEST_APPL_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApBmuPswNvDataTest_VAR)  ***********/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApBmuPswNvDataTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApBmuPswNvDataTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApBmuPswNvDataTest_VAR_ZERO_INIT

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApPlatformNvData_CODE)  ************/

/* used for SWC specific code */
# define CtApPlatformNvData_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtNvDataBlock_CODE)  *****************/

/* used for SWC specific code */
# define CtNvDataBlock_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CTAPPLATFORMNVDATA_APPL)  ********/

/* used for references on application variables */
# define RTE_CTAPPLATFORMNVDATA_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPPLATFORMNVDATA_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPPLATFORMNVDATA_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPPLATFORMNVDATA_APPL_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApHmuPswNvDataTest_CONST)  *********/

/* used for global or static SWC specific constants */
# define CtApHmuPswNvDataTest_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApHmuPswNvDataTest_VAR)  ***********/

/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApHmuPswNvDataTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApHmuPswNvDataTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApHmuPswNvDataTest_VAR_ZERO_INIT

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CTAPBMUPSWNVDATATEST_APPL)  ******/

/* used for references on application variables */
# define RTE_CTAPBMUPSWNVDATATEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPBMUPSWNVDATATEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPBMUPSWNVDATATEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPBMUPSWNVDATATEST_APPL_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApPersistentDataHandler_CODE)  *****/

/* used for SWC specific code */
# define CtApPersistentDataHandler_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtNvDataBlock_CONST)  ****************/

/* used for global or static SWC specific constants */
# define CtNvDataBlock_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApHmuPswNvDataTest_CODE)  **********/

/* used for SWC specific code */
# define CtApHmuPswNvDataTest_CODE

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApPlatformNvData_CONST)  ***********/

/* used for global or static SWC specific constants */
# define CtApPlatformNvData_CONST

/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CTNVDATABLOCK_APPL)  *************/

/* used for references on application variables */
# define RTE_CTNVDATABLOCK_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTNVDATABLOCK_APPL_DATA

/* used for references on application functions */
# define RTE_CTNVDATABLOCK_APPL_CODE

/* used for references on application constants */
# define RTE_CTNVDATABLOCK_APPL_CONST

/***  End of saved code  ************************************************************************************/
#endif
#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtSaBipolarStepperMotor_CODE)  *******/
/* used for SWC specific code */
# define CtSaBipolarStepperMotor_CODE
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtSaBipolarStepperMotor_CONST)  ******/
/* used for global or static SWC specific constants */
# define CtSaBipolarStepperMotor_CONST
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtSaBipolarStepperMotor_VAR)  ********/
/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaBipolarStepperMotor_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaBipolarStepperMotor_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaBipolarStepperMotor_VAR_ZERO_INIT
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtSaUnipolarStepperMotor_CODE)  ******/
/* used for SWC specific code */
# define CtSaUnipolarStepperMotor_CODE
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtSaUnipolarStepperMotor_CONST)  *****/
/* used for global or static SWC specific constants */
# define CtSaUnipolarStepperMotor_CONST
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtSaUnipolarStepperMotor_VAR)  *******/
/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtSaUnipolarStepperMotor_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtSaUnipolarStepperMotor_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtSaUnipolarStepperMotor_VAR_ZERO_INIT
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CTSABIPOLARSTEPPERMOTOR_APPL)  ***/
/* used for references on application variables */
# define RTE_CTSABIPOLARSTEPPERMOTOR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSABIPOLARSTEPPERMOTOR_APPL_DATA

/* used for references on application functions */
# define RTE_CTSABIPOLARSTEPPERMOTOR_APPL_CODE

/* used for references on application constants */
# define RTE_CTSABIPOLARSTEPPERMOTOR_APPL_CONST
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CTSAUNIPOLARSTEPPERMOTOR_APPL)  **/
/* used for references on application variables */
# define RTE_CTSAUNIPOLARSTEPPERMOTOR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTSAUNIPOLARSTEPPERMOTOR_APPL_DATA

/* used for references on application functions */
# define RTE_CTSAUNIPOLARSTEPPERMOTOR_APPL_CODE

/* used for references on application constants */
# define RTE_CTSAUNIPOLARSTEPPERMOTOR_APPL_CONST
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApEth_CODE)  *************/
/* used for SWC specific code */
# define CtApEth_CODE
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApEth_CONST)  ************/
/* used for global or static SWC specific constants */
# define CtApEth_CONST
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApEth_VAR)  **************/
/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEth_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEth_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEth_VAR_ZERO_INIT
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CTAPETH_APPL)  *********/
/* used for references on application variables */
# define RTE_CTAPETH_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPETH_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPETH_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPETH_APPL_CONST
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApComponentCommissioningProviderTest_CODE)  */
/* used for SWC specific code */
# define CtApComponentCommissioningProviderTest_CODE
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApComponentCommissioningProviderTest_CONST)  */
/* used for global or static SWC specific constants */
# define CtApComponentCommissioningProviderTest_CONST
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApComponentCommissioningProviderTest_VAR)  */
/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApComponentCommissioningProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApComponentCommissioningProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApComponentCommissioningProviderTest_VAR_ZERO_INIT
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApComponentFactoryResetProviderTest_CODE)  */
/* used for SWC specific code */
# define CtApComponentFactoryResetProviderTest_CODE
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApComponentFactoryResetProviderTest_CONST)  */
/* used for global or static SWC specific constants */
# define CtApComponentFactoryResetProviderTest_CONST
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApComponentFactoryResetProviderTest_VAR)  */
/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApComponentFactoryResetProviderTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApComponentFactoryResetProviderTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApComponentFactoryResetProviderTest_VAR_ZERO_INIT
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApSystemCommissioningConfigurationConsumerTest_CODE)  */
/* used for SWC specific code */
# define CtApSystemCommissioningConfigurationConsumerTest_CODE
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApSystemCommissioningConfigurationConsumerTest_CONST)  */
/* used for global or static SWC specific constants */
# define CtApSystemCommissioningConfigurationConsumerTest_CONST
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApSystemCommissioningConfigurationConsumerTest_VAR)  */
/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApSystemCommissioningConfigurationConsumerTest_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApSystemCommissioningConfigurationConsumerTest_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApSystemCommissioningConfigurationConsumerTest_VAR_ZERO_INIT
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CTAPCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL)  */
/* used for references on application variables */
# define RTE_CTAPCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPCOMPONENTCOMMISSIONINGPROVIDERTEST_APPL_CONST
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CTAPCOMPONENTFACTORYRESETPROVIDERTEST_APPL)  */
/* used for references on application variables */
# define RTE_CTAPCOMPONENTFACTORYRESETPROVIDERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPCOMPONENTFACTORYRESETPROVIDERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPCOMPONENTFACTORYRESETPROVIDERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPCOMPONENTFACTORYRESETPROVIDERTEST_APPL_CONST
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CTAPSYSTEMCOMMISSIONINGCONFIGURATIONCONSUMERTEST_APPL)  */
/* used for references on application variables */
# define RTE_CTAPSYSTEMCOMMISSIONINGCONFIGURATIONCONSUMERTEST_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPSYSTEMCOMMISSIONINGCONFIGURATIONCONSUMERTEST_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPSYSTEMCOMMISSIONINGCONFIGURATIONCONSUMERTEST_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPSYSTEMCOMMISSIONINGCONFIGURATIONCONSUMERTEST_APPL_CONST
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApEventEnvironmentDataCollector_CODE)  */
/* used for SWC specific code */
# define CtApEventEnvironmentDataCollector_CODE
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApEventEnvironmentDataCollector_CONST)  */
/* used for global or static SWC specific constants */
# define CtApEventEnvironmentDataCollector_CONST
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:CtApEventEnvironmentDataCollector_VAR)  */
/* used for all global or static SWC specific variables that are not initialized by the startup code of the compiler */
# define CtApEventEnvironmentDataCollector_VAR_NOINIT

/* used for global or static SWC specific variables that are initialized by the startup code of the compiler */
# define CtApEventEnvironmentDataCollector_VAR_INIT

/* used for global or static SWC specific variables that are initialized with zero by the startup code of the compiler */
# define CtApEventEnvironmentDataCollector_VAR_ZERO_INIT
/***  End of saved code  ************************************************************************************/
#endif

#if 0
/***  Start of saved code (symbol: compiler abstraction implementation:RTE_CTAPEVENTENVIRONMENTDATACOLLECTOR_APPL)  */
/* used for references on application variables */
# define RTE_CTAPEVENTENVIRONMENTDATACOLLECTOR_APPL_VAR

/* used for references on application data (constants or variables) */
# define RTE_CTAPEVENTENVIRONMENTDATACOLLECTOR_APPL_DATA

/* used for references on application functions */
# define RTE_CTAPEVENTENVIRONMENTDATACOLLECTOR_APPL_CODE

/* used for references on application constants */
# define RTE_CTAPEVENTENVIRONMENTDATACOLLECTOR_APPL_CONST
/***  End of saved code  ************************************************************************************/
#endif


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#endif /* RTE_COMPILER_CFG_H */
