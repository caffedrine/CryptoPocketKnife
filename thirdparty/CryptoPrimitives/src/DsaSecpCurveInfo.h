#ifndef _CRYPTO_DSASECPCURVEINFO_H_
#define _CRYPTO_DSASECPCURVEINFO_H_

#include "DsaSecp.h"

using namespace Base::CryptoPrimitives;

struct CurveInfo
{
    const uint8_t *Domain;
    uint16_t DomainLen;
    const uint8_t *DomainExt;
    uint16_t DomainExtLen;
    const uint8_t *SpeedLvl;
    uint16_t SpeedLvlLen;
};

CurveInfo GetCurveInfo(dsa_secp_curve_t curveType);


#endif //_CRYPTO_DSASECPCURVEINFO_H_
