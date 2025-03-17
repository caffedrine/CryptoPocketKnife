#include "DsaSecp.h"
#include <memory>

#include "DsaSecpCurveInfo.h"
#include "vSecPrim/ESLib.h"

// Test: https://asecuritysite.com/cryptojs/crytojs_ecc

# define CRYPTO_30_LIBCV_SIZEOF_ECC_160_P                             (20u)
# define CRYPTO_30_LIBCV_SIZEOF_ECC_160_N                             (21u)
# define CRYPTO_30_LIBCV_SIZEOF_ECC_224_P                             (28u)
# define CRYPTO_30_LIBCV_SIZEOF_ECC_224_N                             (28u)
# define CRYPTO_30_LIBCV_SIZEOF_ECC_256_P                             (32u)
# define CRYPTO_30_LIBCV_SIZEOF_ECC_256_N                             (32u)
# define CRYPTO_30_LIBCV_SIZEOF_ECC_384_P                             (48u)
# define CRYPTO_30_LIBCV_SIZEOF_ECC_384_N                             (48u)
# define CRYPTO_30_LIBCV_SIZEOF_ECC_521_P                             (66u)
# define CRYPTO_30_LIBCV_SIZEOF_ECC_521_N                             (66u)

uint16_t PrivateKeysSizes[secp_algo_no] = {
        (CRYPTO_30_LIBCV_SIZEOF_ECC_160_N),
        (CRYPTO_30_LIBCV_SIZEOF_ECC_224_N),
        (CRYPTO_30_LIBCV_SIZEOF_ECC_256_N),
        (CRYPTO_30_LIBCV_SIZEOF_ECC_384_N),
        (CRYPTO_30_LIBCV_SIZEOF_ECC_521_N)
};

uint16_t PublicKeysSizes[secp_algo_no] = {
        (CRYPTO_30_LIBCV_SIZEOF_ECC_160_P),
        (CRYPTO_30_LIBCV_SIZEOF_ECC_224_P),
        (CRYPTO_30_LIBCV_SIZEOF_ECC_256_P),
        (CRYPTO_30_LIBCV_SIZEOF_ECC_384_P),
        (CRYPTO_30_LIBCV_SIZEOF_ECC_521_P)
};

uint16_t SignaturesSizes[secp_algo_no] = {
        (CRYPTO_30_LIBCV_SIZEOF_ECC_160_N),
        (CRYPTO_30_LIBCV_SIZEOF_ECC_224_N),
        (CRYPTO_30_LIBCV_SIZEOF_ECC_256_N),
        (CRYPTO_30_LIBCV_SIZEOF_ECC_384_N),
        (CRYPTO_30_LIBCV_SIZEOF_ECC_521_N)
};

namespace Base::CryptoPrimitives
{
    class DsaSecp::impl
    {
    public:
        eslt_WorkSpaceEcP workspace;
    };

    DsaSecp::DsaSecp(dsa_secp_curve_t secpCurve): pimpl{std::make_unique<Base::CryptoPrimitives::DsaSecp::impl>()}
    {
        this->curve = secpCurve;
    }

    // You MUST define the destructor in the cpp file where impl is complete
    DsaSecp::~DsaSecp() = default;

    std::vector<std::byte> DsaSecp::CalcPubKey(std::vector<std::byte> privKey)
    {
        auto curveInfo = GetCurveInfo(this->curve);
        int publicKeySize = PublicKeysSizes[this->curve];
        int privKeySize = PrivateKeysSizes[this->curve];

        // Place to store the public key
        uint8_t publicValuePtr[2*publicKeySize];
        uint8_t *privateValuePtr = reinterpret_cast<uint8_t*>(privKey.data());

        Std_ReturnType retVal = E_NOT_OK;
        eslt_ErrorCode eslRet;

        eslRet = esl_initWorkSpaceHeader(&pimpl->workspace.header, ESL_MAXSIZEOF_WS_ECP, reinterpret_cast<esl_WatchdogFuncPtr>((esl_WatchdogFuncPtr *) NULL_PTR)); /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_STACK_WORKSPACE */

        if (eslRet == ESL_ERC_NO_ERROR)
        {
            eslRet = esl_initGenerateKeyEcP_prim( &pimpl->workspace, curveInfo.Domain, curveInfo.DomainExt, curveInfo.SpeedLvl);
        }

        if (eslRet == ESL_ERC_NO_ERROR)
        {
            if (esl_getLengthOfEcPprivateKey(curveInfo.Domain) == privKeySize)
            {
                if (esl_getLengthOfEcPpublicKey_comp(curveInfo.Domain) == publicKeySize)
                {
                    /* #20 Calculate Keys */
                    if (esl_generateKeyEcP_prim(&pimpl->workspace,
                                                (eslt_Byte *)privateValuePtr,
                                                (eslt_Byte *)publicValuePtr,
                                                (eslt_Byte *)&(publicValuePtr[privKeySize])) == ESL_ERC_NO_ERROR) /* PRQA S 0310 */ /* MD_CRYPTO_30_LIBCV_0310 */ /* SBSW_CRYPTO_30_LIBCV_WORKSPACE_STACK_WITH_STACK_BUFFERS */
                    {
                        retVal = E_OK;
                    }
                }
            }
        }

        if( retVal != ESL_ERC_NO_ERROR )
            return std::vector<std::byte>();

        std::vector<std::byte> output;
        for (int i = 0; i < sizeof(publicValuePtr); i++) {
            output.push_back(static_cast<std::byte>(publicValuePtr[i]));
        }
        return output;
    }
}