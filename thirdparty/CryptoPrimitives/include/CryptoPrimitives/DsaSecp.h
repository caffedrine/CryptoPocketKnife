#ifndef _CRYPTO_DSASECP_H_
#define _CRYPTO_DSASECP_H_

#include <memory>
#include <cstdint>
#include <vector>

namespace Base::CryptoPrimitives
{

typedef enum
{
    secp160r1,
    secp224r1,
    secp256r1,
    secp384r1,
    secp521r1,

    secp192k1,
    secp224k1,
    secp256k1,

    secp_algo_no
} dsa_secp_curve_t;

class DsaSecp
{
public:
    DsaSecp(dsa_secp_curve_t secpCurve);
    ~DsaSecp();
    std::vector<std::byte> CalcPubKey(std::vector<std::byte> privKey);

private:
    class impl;
    std::unique_ptr<impl> pimpl;
    dsa_secp_curve_t curve;
};

}



#endif //_CRYPTO_DSASECP_H_
