#include "ESLib.h"
#include "ESLib_Helper.h"

/* actCLib includes */
#include "actIGCM.h"


/**********************************************************************************************************************
 *  esl_initGMAC()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initGMAC(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGMAC) workSpace,
                                           const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) key, const eslt_Length ivLength, VSECPRIM_P2CONST_PARA(eslt_Byte) iv)
{
  eslt_ErrorCode retVal;

  /* any NULLs ? */
  if ((workSpace == NULL_PTR) || (key == NULL_PTR) || (iv == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_GMAC)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  /* check keyLength */
  else if ((keyLength != ESL_SIZEOF_AES128_KEY) && (keyLength != ESL_SIZEOF_AES192_KEY) && (keyLength != ESL_SIZEOF_AES256_KEY))
  {
    retVal = ESL_ERC_GCM_INVALID_KEY_LENGTH;
  }
  /* check ivLength */
  else if (ivLength < 1u)
  {
    retVal = ESL_ERC_INVALID_IV_LENGTH;
  }
  else
  {
    /* init actCLib GCM; actGCMInit always returns actOK */
    (void)actGCMInit(&workSpace->wsGMAC, key, keyLength, iv, ivLength, workSpace->header.watchdog);
    /* set workSpace state */
    workSpace->header.status = (ESL_WST_ALGO_GMAC | ESL_WST_M_RUNNING | ESL_WST_M_CRITICAL);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_updateGMAC()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_updateGMAC(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGMAC) workSpace, const eslt_Length inputLength, VSECPRIM_P2CONST_PARA(eslt_Byte) input)
{
  eslt_ErrorCode retVal;

  /* any NULLs ? */
  if ((workSpace == NULL_PTR) || (input == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_GMAC, ESL_WST_ALGO_GMAC)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  /* update actCLib GCM */
  else
  {
    actRETURNCODE result = actGCMTransform(&workSpace->wsGMAC, input, inputLength, NULL_PTR, NULL_PTR, 0u, workSpace->header.watchdog);
    if (result == actEXCEPTION_LENGTH)
    {
      retVal = ESL_ERC_GCM_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_finalizeGMAC()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeGMAC(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGMAC) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) tag)
{
  eslt_ErrorCode retVal;

  /* any NULLs ? */
  if ((workSpace == NULL_PTR) || (tag == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_GMAC, ESL_WST_ALGO_GMAC)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  else
  {
    /* finalize actCLib GMAC; actGMACFinalize always returns actOK */
    (void)actGMACFinalize(&workSpace->wsGMAC, tag, workSpace->header.watchdog);
    /* Reset and clear workspace */
    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsGMAC); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_verifyGMAC()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyGMAC(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceGMAC) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) tag)
{
  eslt_ErrorCode retVal;
  eslt_Byte tmpTag[ESL_SIZEOF_GCM_TAG];
  actMemClear(tmpTag, ESL_SIZEOF_GCM_TAG); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */

  /* any NULLs ? */
  if ((workSpace == NULL_PTR) || (tag == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_GMAC, ESL_WST_ALGO_GMAC)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  /* finalize actCLib GCM and compare provided tag with computed one */
  else
  {
    /* finalize actCLib GMAC; actGMACFinalize always returns actOK */
    (void)actGMACFinalize(&workSpace->wsGMAC, tmpTag, workSpace->header.watchdog);
    if (actMemcmp(tmpTag, tag, ESL_SIZEOF_GCM_TAG) != TRUE) /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
    {
      retVal = ESL_ERC_GCM_TAG_VERIFICATION_FAILED;
    }

    /* Reset and clear workspace */
    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsGMAC); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  }

  return retVal;
}