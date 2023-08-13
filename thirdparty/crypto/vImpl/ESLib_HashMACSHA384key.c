#include "ESLib.h"

/* actCLib includes */
#include "actIHashMACSHA384.h"

/****************************************************************************
 * esl_generateKeyHashMACSHA384
 ***************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
VSECPRIM_FUNC(eslt_ErrorCode) esl_generateKeyHashMACSHA384(const eslt_Length keyLength, VSECPRIM_P2VAR_PARA(eslt_Byte) key)
{
  return esl_getBytesRNG(keyLength, key);
}
