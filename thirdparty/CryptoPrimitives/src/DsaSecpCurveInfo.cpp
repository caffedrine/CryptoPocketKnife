#include "DsaSecpCurveInfo.h"

#include "Crypto_30_LibCv/Crypto_30_LibCv_Curve_Int.h"

using namespace Base::CryptoPrimitives;

const uint8_t *c[secp_algo_no][3u] =
{
        // SECP160R1
        {
                Crypto_30_LibCv_EccCurveSecP160R1Domain,
                Crypto_30_LibCv_EccCurveSecP160R1DomainExt,
                Crypto_30_LibCv_EccCurveSecP160R1SpeedUpExt
        },

        // SECP224R1
        {
                Crypto_30_LibCv_EccCurveNistSecP224R1Domain,
                Crypto_30_LibCv_EccCurveNistSecP224R1DomainExt,
                Crypto_30_LibCv_EccCurveNistSecP224R1SpeedUpExt
        },

        // SECP256R1
        {
                Crypto_30_LibCv_EccCurveNistAnsiSecP256R1Domain,
                Crypto_30_LibCv_EccCurveNistAnsiSecP256R1DomainExt,
                Crypto_30_LibCv_EccCurveNistAnsiSecP256R1SpeedUpExt
        },

        // SECP384R1
        {
                Crypto_30_LibCv_EccCurveNistSecP384R1Domain,
                Crypto_30_LibCv_EccCurveNistSecP384R1DomainExt,
                Crypto_30_LibCv_EccCurveNistSecP384R1SpeedUpExt
        },

        // SECP512R1
        {
                Crypto_30_LibCv_EccCurveNistSecP521R1Domain,
                Crypto_30_LibCv_EccCurveNistSecP521R1DomainExt,
                Crypto_30_LibCv_EccCurveNistSecP521R1SpeedUpExt
        }
};

CurveInfo GetCurveInfo(dsa_secp_curve_t curveType)
{
    CurveInfo info;
    info.Domain = c[(int)curveType][0];
    info.DomainLen = sizeof(c[(int)curveType][0]);

    info.DomainExt = c[(int)curveType][1];
    info.DomainExtLen = sizeof(c[(int)curveType][1]);

    info.SpeedLvl = c[(int)curveType][2];
    info.SpeedLvlLen = sizeof(c[(int)curveType][2]);

    return info;
}
