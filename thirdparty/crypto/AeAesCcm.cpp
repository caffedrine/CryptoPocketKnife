#include "AeAesCcm.h"

#include "vImpl/ESLib.h"

//   _____                             _
//  | ____|_ __   ___ _ __ _   _ _ __ | |_
//  |  _| | '_ \ / __| '__| | | | '_ \| __|
//  | |___| | | | (__| |  | |_| | |_) | |_
//  |_____|_| |_|\___|_|   \__, | .__/ \__|
//                         |___/|_|

class AeAesCcmEncrypt::impl
{
public:
    eslt_WorkSpaceAESCCM workspace;
};

AeAesCcmEncrypt::AeAesCcmEncrypt(): pimpl{std::make_unique<impl>()}
{

}

AeAesCcmEncrypt::~AeAesCcmEncrypt() = default;

uint16_t AeAesCcmEncrypt::Init(uint8_t *key, uint32_t key_length, uint8_t *nonce, uint32_t nonce_length, uint32_t aad_length, uint32_t msg_length, uint8_t auth_field_size, uint8_t auth_field_size_length)
{
    this->KeyLen = key_length;

    eslt_ErrorCode retVal = esl_initWorkSpaceHeader(&pimpl->workspace.header, ESL_SIZEOF_WS_AESCCM, reinterpret_cast<esl_WatchdogFuncPtr>((esl_WatchdogFuncPtr *) NULL_PTR));

    if( retVal == ESL_ERC_NO_ERROR )
    {
        retVal = esl_initAESCCM(&pimpl->workspace, key, this->KeyLen, nonce, nonce_length, aad_length, msg_length, auth_field_size, auth_field_size_length);
    }
    return retVal;
}

uint16_t AeAesCcmEncrypt::Update(uint8_t *input_data, uint32_t length_data_length, uint8_t *output_data, uint32_t *utput_data_length)
{
    return esl_updatePlaintextEncryptGCM(&pimpl->workspace, input_data, length_data_length, output_data, reinterpret_cast<eslt_Size32 *>(utput_data_length));
}

uint16_t AeAesCcmEncrypt::Finish(uint8_t *output_data, uint32_t *output_data_length, uint8_t *tag)
{
    return esl_finalizeEncryptGCM(&pimpl->workspace, (eslt_Byte *)output_data, (eslt_Size32 *)output_data_length, tag);
}

//   ____                             _
//  |  _ \  ___  ___ _ __ _   _ _ __ | |_
//  | | | |/ _ \/ __| '__| | | | '_ \| __|
//  | |_| |  __/ (__| |  | |_| | |_) | |_
//  |____/ \___|\___|_|   \__, | .__/ \__|
//                        |___/|_|

class AeAesCcmDecrypt::impl
{
public:
    eslt_WorkSpaceGCM workspace;
};

AeAesCcmDecrypt::AeAesCcmDecrypt(): pimpl{std::make_unique<impl>()}
{

}

AeAesCcmDecrypt::~AeAesCcmDecrypt() = default;

uint16_t AeAesCcmDecrypt::Init(uint8_t *key, uint32_t key_length, uint8_t *iv, uint8_t iv_length)
{
    this->KeyLen = key_length;

    eslt_ErrorCode retVal = esl_initWorkSpaceHeader(&pimpl->workspace.header, ESL_MAXSIZEOF_WS_GCM, reinterpret_cast<esl_WatchdogFuncPtr>((esl_WatchdogFuncPtr *) NULL_PTR));

    if( retVal == ESL_ERC_NO_ERROR )
    {
        retVal = esl_initDecryptGCM(&pimpl->workspace, key, this->KeyLen, iv, iv_length);
    }
    return retVal;
}

uint16_t AeAesCcmDecrypt::Update(uint8_t *input_data, uint32_t length_data_length, uint8_t *output_data, uint32_t *utput_data_length)
{
    return esl_updateCiphertextDecryptGCM(&pimpl->workspace, input_data, length_data_length, output_data, reinterpret_cast<eslt_Size32 *>(utput_data_length));
}

uint16_t AeAesCcmDecrypt::Finish(uint8_t *output_data, uint32_t *output_data_length, uint8_t *tag)
{
    return esl_finalizeDecryptGCM(&pimpl->workspace, (eslt_Byte *)output_data, (eslt_Size32 *)output_data_length, tag);
}
