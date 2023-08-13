
#include "ESLib.h"
#include "ESLib_Helper.h"

/* actCLib includes */
#include "actIHashMACSHA256.h"

/**********************************************************************************************************************
 *  esl_initHashMACSHA256()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initHashMACSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA256) workSpace,
const eslt_Length keyLength,
VSECPRIM_P2CONST_PARA(eslt_Byte) key)
{
  eslt_ErrorCode retVal;

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (key == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  /* Check workSpace */
  else if ((retVal = esl_CheckWorkSpaceHeader(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA256)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
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
    /* init actCLib HMAC-SHA-256; it is safe to void actHashMACSHA256Init, since actHashMACSHA256Init only returns
     * actEXCEPTION_LENGTH, if keyLength < 1, and this was checked before */
    (void)actHashMACSHA256Init(&workSpace->wsHMACSHA256, key, keyLength, workSpace->header.watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */

    /* Set workSpace state */
    esl_SetWorkspaceStatus(&workSpace->header, ESL_WST_ALGO_HMACSHA256); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */

  }

  return retVal;
}

/**********************************************************************************************************************
 *  esl_updateHashMACSHA256()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_updateHashMACSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA256) workSpace,
const eslt_Length inputLength,
VSECPRIM_P2CONST_PARA(eslt_Byte) input)
{
  eslt_ErrorCode retVal;

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (input == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA256, ESL_WST_ALGO_HMACSHA256)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* retVal already set */
  }
  else
  {
    /* update actCLib HMAC-SHA-256 */
    if (actEXCEPTION_LENGTH == actHashMACSHA256Update(&workSpace->wsHMACSHA256, input, (actLengthType)inputLength, workSpace->header.watchdog)) /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
    {
      retVal = ESL_ERC_SHA256_TOTAL_LENGTH_OVERFLOW;
    }
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  esl_finalizeHashMACSHA256()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_finalizeHashMACSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA256) workSpace,
VSECPRIM_P2VAR_PARA(eslt_Byte) messageHashMAC)
{
  eslt_ErrorCode retVal;

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA256, ESL_WST_ALGO_HMACSHA256)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* retVal already set */
  }
  else
  {
    /* finalize actCLib HMAC-SHA-256; actHashMACSHA256Finalize always returns actOK */
    (void)actHashMACSHA256Finalize(&workSpace->wsHMACSHA256, messageHashMAC, workSpace->header.watchdog); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_HMACSHA256_FINALIZE */

    /* Reset and clear workspace */
    esl_ResetAndClearWorkspace(&workSpace->header, &workSpace->wsHMACSHA256); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER */
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  esl_verifyHashMACSHA256()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_verifyHashMACSHA256(
VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHMACSHA256) workSpace,
VSECPRIM_P2CONST_PARA(eslt_Byte) messageHashMAC)
{
  eslt_Byte tmpMAC[ESL_SIZEOF_SHA256_DIGEST];
  eslt_ErrorCode retVal;

  actMemClear(tmpMAC, ESL_SIZEOF_SHA256_DIGEST); /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_FCT_CALL_LOCAL_BUFFER_FIXED_SIZE */

  /* Any NULLs ? */
  if ((workSpace == NULL_PTR) || (messageHashMAC == NULL_PTR))
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else if ((retVal = esl_CheckWorkSpaceHeaderAndState(&workSpace->header, ESL_MAXSIZEOF_WS_HMACSHA256, ESL_WST_ALGO_HMACSHA256)) != ESL_ERC_NO_ERROR) /* PRQA S 3326 */ /* MD_VSECPRIM_13.1 */ /* SBSW_VSECPRIM_CALL_FUNCTION */
  {
    /* retVal already set */
  }
  else
  {
    /* Verify MAC; it is safe to void esl_finalizeHashMACSHA256, since all relevant error conditions for
     * esl_finalizeHashMACSHA256 were checked before */
    (void)esl_finalizeHashMACSHA256(workSpace, tmpMAC); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_AND_LOCAL_BUFFER */

    if (actMemcmp(tmpMAC, messageHashMAC, ESL_SIZEOF_SHA256_DIGEST) != TRUE) /* PRQA S 0315 */ /* MD_VSECPRIM_P2VOID_CAST */ /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_FIXED_SIZE */
    {
      retVal = ESL_ERC_HMAC_INCORRECT_MAC;
    }
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
