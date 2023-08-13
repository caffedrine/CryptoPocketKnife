#include "ESLib.h"
#include "ESLib_Helper.h"

/* actCLib includes */
#include "actIHashMACSHA384.h"

/****************************************************************************
 * esl_initHashMACSHA384
 ***************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initHashMACSHA384(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA384) workSpace, const eslt_Length keyLength, VSECPRIM_P2CONST_PARA(eslt_Byte) key)
{
  eslt_ErrorCode retVal;

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (key == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA384)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  /* Check keyLength */
  else if (keyLength == 0u)
  {
    retVal = ESL_ERC_HMAC_KEY_LENGTH_OUT_OF_RANGE;
  }
  else
  {
    /* Init actCLib HMAC-SHA-384 */
    if (actOK == actHashMACSHA384Init(&workSpace->wsHMACSHA384, key, keyLength, workSpace->header.watchdog))
    {
      /* Set workSpace state */
      esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_HMACSHA384);
    }
    else
    {
      retVal = ESL_ERC_ERROR;
    }
  }

  return retVal;
}

/****************************************************************************
 * esl_updateHashMACSHA384
 ***************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_updateHashMACSHA384(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA384) workSpace, const eslt_Length inputLength, VSECPRIM_P2CONST_PARA(eslt_Byte) input)
{
  eslt_ErrorCode retVal;

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (input == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA384, ESL_WST_ALGO_HMACSHA384)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  else
  {
    /* update actCLib HMAC-SHA-384 */
    if (actEXCEPTION_LENGTH == actHashMACSHA384Update(&workSpace->wsHMACSHA384, input, inputLength, workSpace->header.watchdog))
    {
      retVal = ESL_ERC_SHA384_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
 * esl_finalizeHashMACSHA384
 ***************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashMACSHA384(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA384) workSpace, VSECPRIM_P2VAR_PARA(eslt_Byte) messageHashMAC)
{
  eslt_ErrorCode retVal;

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA384, ESL_WST_ALGO_HMACSHA384)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  else
  {
    /* finalize actCLib HMAC-SHA-384 */
    if (actOK != actHashMACSHA384Finalize(&workSpace->wsHMACSHA384, messageHashMAC, workSpace->header.watchdog))
    {
      retVal = ESL_ERC_ERROR;
    }

    /* Reset and clear workspace */
    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsHMACSHA384); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
 * esl_verifyHashMACSHA384
 ***************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyHashMACSHA384(VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA384) workSpace, VSECPRIM_P2CONST_PARA(eslt_Byte) messageHashMAC)
{
  eslt_Byte tmpMAC[ESL_SIZEOF_SHA384_DIGEST];
  eslt_ErrorCode retVal;

  actMemClear(tmpMAC, ESL_SIZEOF_SHA384_DIGEST); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA384, ESL_WST_ALGO_HMACSHA384)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */
  {
    /* retVal already set */
  }
  else
  {
    /* Verify MAC */
    if (ESL_ERC_NO_ERROR == esl_finalizeHashMACSHA384(workSpace, tmpMAC))
    {
      if (actMemcmp(tmpMAC, messageHashMAC, ESL_SIZEOF_SHA384_DIGEST) != TRUE) /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */
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
