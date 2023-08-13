#include "ESLib_RNG.h"
#include "actUtilities.h"

VSECPRIM_FUNC(eslt_ErrorCode) esl_getBytesRNG(
        const eslt_Length targetLength,
        VSECPRIM_P2VAR_PARA(eslt_Byte) target)
{
    uint8 rng[32] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
    if(targetLength <= 32)
        actMemcpy((void *)target, rng, targetLength);
    else
        actMemcpy((void *)target, rng, sizeof(rng));
    return 0;
}