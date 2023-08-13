#include "ESLib.h"

/* actCLib includes */
#include "actIHashMACSHA256.h"

/****************************************************************************
 * esl_generateKeyHashMACSHA256
 ***************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyHashMACSHA256(const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key)
{
  return esl_getBytesRNG(keyLength, key); /* SBSW_VSECPRIM_FCT_CALL_PASSED_BUFFER_FIXED_SIZE */
}