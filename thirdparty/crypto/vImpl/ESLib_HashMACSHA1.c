#include "ESLib.h"
#include "ESLib_Helper.h"

/* actCLib includes */
#include "actIHashMAC.h"

/**********************************************************************************************************************
 *  esl_initHashMACSHA1()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initHashMACSHA1(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA1) workSpace, const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) key)
{
  eslt_ErrorCode retVal;

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (key == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA1)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  /* check keyLength */
  else if (keyLength == 0u)
  {
    retVal = ESL_ERC_HMAC_KEY_LENGTH_OUT_OF_RANGE;
  }
  else
  {
    /* init actCLib HMAC-SHA-1 */
    if (actOK == actHashMACInit(&workSpace->wsHMACSHA1, key, (actLengthType)keyLength, workSpace->header.watchdog))
    {
      /* Set workSpace state */
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_HMACSHA1);
    }
    else
    {
      retVal = ESL_ERC_ERROR;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_updateHashMACSHA1()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_updateHashMACSHA1(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA1) workSpace, const eslt_Length inputLength, VSECPRIM_P2CONST_PARA(eslt_Byte) input) /* PRQA S 3673 */ /* MD_VSECPRIM_16.7 */
{
  eslt_ErrorCode retVal;

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (input == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA1, ESL_WST_ALGO_HMACSHA1)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  else
  {
    /* Update HMAC calculation */
    if (actEXCEPTION_LENGTH == actHashMACUpdate(&workSpace->wsHMACSHA1, input, (actLengthType)inputLength, workSpace->header.watchdog))
    {
      retVal = ESL_ERC_SHA1_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  esl_finalizeHashMACSHA1()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashMACSHA1(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA1) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageHashMAC)
{
  eslt_ErrorCode retVal;

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA1, ESL_WST_ALGO_HMACSHA1)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  else
  {
    /* finalize actCLib HMAC-SHA-1 */
    if (actOK != actHashMACFinalize(&workSpace->wsHMACSHA1, messageHashMAC, workSpace->header.watchdog))
    {
      retVal = ESL_ERC_ERROR;
    }

    /* Reset and clear workspace */
    esl_ResetAndClearWorkspace(&workSpace->header, &(workSpace->wsHMACSHA1)); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  esl_verifyHashMACSHA1()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyHashMACSHA1(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA1) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) messageHashMAC)
{
  eslt_Byte tmpMAC[ESL_SIZEOF_SHA1_DIGEST];
  eslt_ErrorCode retVal;

  actMemClear(tmpMAC, ESL_SIZEOF_SHA1_DIGEST); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA1, ESL_WST_ALGO_HMACSHA1)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  else
  {
    /* Verify MAC */
    if (ESL_ERC_NO_ERROR == esl_finalizeHashMACSHA1(workSpace, tmpMAC))
    {
      if (actMemcmp(tmpMAC, messageHashMAC, ESL_SIZEOF_SHA1_DIGEST) != TRUE) /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
      {
        retVal = ESL_ERC_HMAC_INCORRECT_MAC;
      }
    }
    else
    {
      retVal = ESL_ERC_ERROR;
    }
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */