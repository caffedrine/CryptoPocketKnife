#include "DsaSecp.h"
#include <memory>

#include "DsaSecpCurveInfo.h"
#include "vSecPrim/ESLib.h"
#include "vStd/vstdlib.h"
#include "Crypto_30_LibCv/Crypto_30_LibCv_Services.h"
#include "Crypto_30_LibCv/Crypto_30_LibCv_SignatureGenerate.h"

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
    struct DsaSecp::impl
    {
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

    std::vector<std::byte> DsaSecp::SignData(uint8_t *in_data, uint32_t data_len, std::vector<std::byte> privKey)
    {
        // reimplementation of Crypto_30_LibCv_EccPrimeGenerateSignature_SignData()

        // Check private key size
        if (privKey.size() != PrivateKeysSizes[this->curve])
            return std::vector<std::byte>();

        eslt_ErrorCode retValCv = ESL_ERC_ERROR;
        eslt_Length sigLength = 0u, doubleSigLength = 0u, sigLengthR = 0u, sigLengthS = 0u;

        eslt_Byte signatureR[CRYPTO_30_LIBCV_SIZEOF_ECC_521_N] = {0u};
        eslt_Byte signatureS[CRYPTO_30_LIBCV_SIZEOF_ECC_521_N] = {0u};

        uint8 *privateKeyElementPtr = reinterpret_cast<uint8 *>(privKey.data());
        CurveInfo curveInfo = GetCurveInfo(this->curve);

        uint8 signatureRS[sizeof(signatureR) + sizeof(signatureS)];
        uint32 outputRSLen = sizeof(signatureRS);

        /* # Initialize ECC workspace header. */
        if (ESL_ERC_NO_ERROR != esl_initWorkSpaceHeader(&this->pimpl->workspace.header, ESL_MAXSIZEOF_WS_ECP, reinterpret_cast<esl_WatchdogFuncPtr>((esl_WatchdogFuncPtr *) NULL_PTR))) /* PRQA S 3395 */ /* MD_CRYPTO_30_LIBCV_3395 */ /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */
        {
            return std::vector<std::byte>();;
        }

        // Init DSAEcP primitive
        if (ESL_ERC_NO_ERROR != esl_initSignDSAEcP_prim(&pimpl->workspace, curveInfo.Domain, curveInfo.DomainExt, curveInfo.SpeedLvl)) /* PRQA S 0310 */ /* MD_CRYPTO_30_LIBCV_0310 */ /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_NULL_PTR */
        {
            return std::vector<std::byte>();
        }

        # if (CRYPTO_30_LIBCV_ECP160GENERATE == STD_ON)
            if (sigKeyLength == (keyElements[0].keyElementLength + 1u))
            {
                privateKeyElementBuffer[0] = 0u; /* SBSW_CRYPTO_30_LIBCV_STACK_ARRAY_ACCESS_WITH_SIZE */
                 Crypto_30_LibCv_CopyData(&privateKeyElementBuffer[1u], Crypto_30_LibCv_GetAddrKeyStorage(keyElements[0].keyElementIndex), (keyElements[0].keyElementLength)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */  /* SBSW_CRYPTO_30_LIBCV_CSL02_KEY_STORAGE_VIA_KEY_ELEMENT */
                  privateKeyElementPtr = privateKeyElementBuffer;
            }
            else
        # endif
        {
            privateKeyElementPtr = reinterpret_cast<uint8 *>(privKey.data());
        }

        /* # get esl size of signature length for r and s (signature = [signature_r|signature_s]) */
        sigLength = esl_getLengthOfEcPsignature_comp(curveInfo.Domain); /* SBSW_CRYPTO_30_LIBCV_ESL_CONST_WORKSPACE */
        doubleSigLength = (eslt_Length)Crypto_30_LibCv_Math_Mul2(sigLength);
        if ((sizeof(signatureR) + sizeof(signatureS)) < doubleSigLength)
        {
            return std::vector<std::byte>();
        }

        sigLengthS = sigLength;
        sigLengthR = sigLength;

        /* # Finalize and store output. */
        retValCv = esl_signDSAEcP_prim(&(pimpl->workspace), /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
                                       (eslt_Length)data_len, (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))in_data,
                                       (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))privateKeyElementPtr,
                                       (P2VAR(eslt_Length, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))&sigLengthR, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))signatureR,
                                       (P2VAR(eslt_Length, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))&sigLengthS, (P2VAR(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))signatureS);

        if (retValCv == ESL_ERC_NO_ERROR)
        {
            //retVal = Crypto_30_LibCv_EccPrimeGenerateSignature_ConvertSignatureForOutputBuffer(&job, sigLength, doubleSigLength, sigLengthR, sigLengthS, expectedKeyLength, signatureR, signatureS); /* SBSW_CRYPTO_30_LIBCV_FORWARDING_PTR_AND_MEMBER_OF_JOB_PTR */
            VStdLib_MemCpy(signatureRS, signatureR, (sigLengthR)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
            VStdLib_MemCpy(&signatureRS[sigLengthR], signatureS, (sigLengthS)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CRYPTO_30_LIBCV_WRITE_ACCESS_TO_JOBPRIMITIVE_INPUTOUTPUT_PTR */
            outputRSLen = doubleSigLength;

            // Sopy data to output vector and return it
            std::vector<std::byte> outputVec;
            outputVec.reserve(outputRSLen);
            for (uint32_t i = 0; i < outputRSLen; i++)
            {
                outputVec.push_back(static_cast<std::byte>(signatureRS[i]));
            }
            return outputVec;
        }

        return std::vector<std::byte>();
    }

    bool DsaSecp::VerifySignature(uint8_t *in_data, uint32_t data_len, std::vector<std::byte> publicKey, std::vector<std::byte> signature)
    {
        // Implementation of Crypto_30_LibCv_DispatchSignatureEccPrimeVerifyFinish_CvOperation
        /* ----- Local Variables ------------------------------------------------ */
        eslt_ErrorCode retValCv = ESL_ERC_ERROR;
        uint32 sigKeyLength = 0u;
        CurveInfo CurveInfo = GetCurveInfo(this->curve);

        /* get esl size of key length for x and y component of the public key (key = [key_x|key_y]) */
        sigKeyLength = (uint32)(Crypto_30_LibCv_Math_Mul2((uint32)esl_getLengthOfEcPpublicKey_comp(CurveInfo.Domain)));  /* SBSW_CRYPTO_30_LIBCV_ESL_CONST_WORKSPACE */

        /* # Initialize ECC workspace header. */
        if (ESL_ERC_NO_ERROR != esl_initWorkSpaceHeader((P2VAR(eslt_WorkSpaceHeader, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))&(pimpl->workspace.header), ESL_MAXSIZEOF_WS_ECP, reinterpret_cast<esl_WatchdogFuncPtr>((esl_WatchdogFuncPtr *) NULL_PTR))) /* PRQA S 3395 */ /* MD_CRYPTO_30_LIBCV_3395 */ /* SBSW_CRYPTO_30_LIBCV_INIT_ESL_WORKSPACE */
        {
            return false;
        }

        /* # Initialize ECC algorithm. */
        if(ESL_ERC_NO_ERROR != esl_initVerifyDSAEcP_prim((P2VAR(eslt_WorkSpaceEcP, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))&(pimpl->workspace), CurveInfo.Domain, CurveInfo.DomainExt))
        {
            return false;
        }

        retValCv = esl_verifyDSAEcP_prim(&(pimpl->workspace),
                                         (eslt_Length)data_len, (P2CONST(eslt_Byte, AUTOMATIC, CRYPTO_30_LIBCV_CRYPTOCV_APPL_VAR))in_data,  /* SBSW_CRYPTO_30_LIBCV_ESL_CALL_WITH_WORKSPACE_AND_BUFFERS */
                                         (const eslt_Byte *)publicKey.data(), (const eslt_Byte *)(&(publicKey.data()[sigKeyLength/2])),
                                         (eslt_Length)sigKeyLength / 2, (const eslt_Byte *)signature.data(),
                                         (eslt_Length)sigKeyLength / 2, (const eslt_Byte *)(&signature.data()[sigKeyLength/2]));
        if (retValCv == ESL_ERC_NO_ERROR)
        {
            return true;
        }

        return false;
    }
}