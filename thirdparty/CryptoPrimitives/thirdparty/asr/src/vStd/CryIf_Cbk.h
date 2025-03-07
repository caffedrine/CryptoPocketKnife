#if !defined (CRYIF_CBK_H)
# define CRYIF_CBK_H

# include "Std_Types.h"
# include "Crypto_GeneralTypes.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define CRYIF_START_SEC_CODE
# include "CryIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CryIf_CallbackNotification()
 *********************************************************************************************************************/
/*! \brief         CryIf Callback Notification
 *  \details       Notifies the CRYIF about the completion of the request with the result of the cryptographic operation.
 *  \param[in,out] job                       Points to the completed job's information structure. It contains a
 *                                           callbackID to identify which job is finished.
 *  \param[in]     result                    Contains the result of the cryptographic operation.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \trace         CREQ-127574
 *********************************************************************************************************************/
FUNC(void, CRYIF_CODE) CryIf_CallbackNotification(P2VAR(Crypto_JobType, AUTOMATIC, CRYIF_APPL_VAR) job,
  Std_ReturnType result);

# define CRYIF_STOP_SEC_CODE
# include "CryIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* !defined (CRYIF_CBK_H) */

/**********************************************************************************************************************
 *  END OF FILE: CryIf_Cbk.h
 *********************************************************************************************************************/
