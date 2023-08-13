#include "ESLib.h"

/* actCLib includes */
#include "actIHashMAC.h"

/****************************************************************************
 * esl_generateKeyHashMACSHA1
 ***************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyHashMACSHA1(const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key)
{
  return esl_getBytesRNG(keyLength, key);
}
