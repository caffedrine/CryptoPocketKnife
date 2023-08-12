#define ESLIB_INIT_SOURCE

#include "ESLib_t.h"
#include "ESLib_ERC.h"
#include "ESLib_types.h"

/****************************************************************************
 ** Global Functions
 ***************************************************************************/

/**********************************************************************************************************************
 *  esl_initESCryptoLib()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initESCryptoLib(void)
{
  return ESL_ERC_NO_ERROR;
}

/**********************************************************************************************************************
 *  esl_initWorkSpaceHeader()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_initWorkSpaceHeader(
  VSECPRIM_P2VAR_PARA(eslt_WorkSpaceHeader) workSpaceHeader,
  const eslt_Length workSpaceSize,
  esl_WatchdogFuncPtr watchdog)
{
  eslt_ErrorCode retVal;

  /* Any NULLs ? */
  if (workSpaceHeader == NULL_PTR)
  {
    retVal = ESL_ERC_PARAMETER_INVALID;
  }
  else
  {
    /* init workSpaceHeader */
    workSpaceHeader->size = workSpaceSize; /* SBSW_VSECPRIM_WRITE_POINTER */
    workSpaceHeader->status = ESL_WST_ALLOCATED; /* SBSW_VSECPRIM_WRITE_POINTER */
    workSpaceHeader->watchdog = watchdog; /* SBSW_VSECPRIM_WRITE_POINTER */

    workSpaceHeader->checkSum = 0u;  /* not implemented at this point */ /* SBSW_VSECPRIM_WRITE_POINTER */

    retVal = ESL_ERC_NO_ERROR;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  END OF FILE: ESLib_Init.c
 *********************************************************************************************************************/
