#include "AeAesGcm.h"

#include "vImpl/ESLib.h"

//   _____                             _
//  | ____|_ __   ___ _ __ _   _ _ __ | |_
//  |  _| | '_ \ / __| '__| | | | '_ \| __|
//  | |___| | | | (__| |  | |_| | |_) | |_
//  |_____|_| |_|\___|_|   \__, | .__/ \__|
//                         |___/|_|

class AeAesGcmEncrypt::impl
{
public:
    eslt_WorkSpaceGCM workspace;
};

AeAesGcmEncrypt::AeAesGcmEncrypt(): pimpl{std::make_unique<impl>()}
{

}

AeAesGcmEncrypt::~AeAesGcmEncrypt() = default;

uint16_t AeAesGcmEncrypt::Init(uint8_t *key, uint32_t key_length, uint8_t *iv, uint8_t iv_length)
{
    this->KeyLen = key_length;

    eslt_ErrorCode retVal = esl_initWorkSpaceHeader(&pimpl->workspace.header, ESL_MAXSIZEOF_WS_GCM, reinterpret_cast<esl_WatchdogFuncPtr>((esl_WatchdogFuncPtr *) NULL_PTR));

    if( retVal == ESL_ERC_NO_ERROR )
    {
        retVal = esl_initEncryptGCM(&pimpl->workspace, key, this->KeyLen, iv, iv_length);
    }
    return retVal;
}

uint16_t AeAesGcmEncrypt::AddEncData(uint8_t *input_data, uint32_t length_data_length, uint8_t *output_data, uint32_t *utput_data_length)
{
    return esl_updatePlaintextEncryptGCM(&pimpl->workspace, input_data, length_data_length, output_data, reinterpret_cast<eslt_Size32 *>(utput_data_length));
}

uint16_t AeAesGcmEncrypt::AddAuthData(uint8_t *input_data, uint32_t length_data_length)
{
    return esl_updateAuthDataEncryptGCM(&pimpl->workspace, input_data, length_data_length);
}

uint16_t AeAesGcmEncrypt::Finish(uint8_t *output_data, uint32_t *output_data_length, uint8_t *tag)
{
    return esl_finalizeEncryptGCM(&pimpl->workspace, (eslt_Byte *)output_data, (eslt_Size32 *)output_data_length, tag);
}

//   ____                             _
//  |  _ \  ___  ___ _ __ _   _ _ __ | |_
//  | | | |/ _ \/ __| '__| | | | '_ \| __|
//  | |_| |  __/ (__| |  | |_| | |_) | |_
//  |____/ \___|\___|_|   \__, | .__/ \__|
//                        |___/|_|

class AeAesGcmDecrypt::impl
{
public:
    eslt_WorkSpaceGCM workspace;
};

AeAesGcmDecrypt::AeAesGcmDecrypt(): pimpl{std::make_unique<impl>()}
{

}

AeAesGcmDecrypt::~AeAesGcmDecrypt() = default;

uint16_t AeAesGcmDecrypt::Init(uint8_t *key, uint32_t key_length, uint8_t *iv, uint8_t iv_length)
{
    this->KeyLen = key_length;

    eslt_ErrorCode retVal = esl_initWorkSpaceHeader(&pimpl->workspace.header, ESL_MAXSIZEOF_WS_GCM, reinterpret_cast<esl_WatchdogFuncPtr>((esl_WatchdogFuncPtr *) NULL_PTR));

    if( retVal == ESL_ERC_NO_ERROR )
    {
        retVal = esl_initDecryptGCM(&pimpl->workspace, key, this->KeyLen, iv, iv_length);
    }
    return retVal;
}

uint16_t AeAesGcmDecrypt::AddDecData(uint8_t *input_data, uint32_t length_data_length, uint8_t *output_data, uint32_t *utput_data_length)
{
    return esl_updateCiphertextDecryptGCM(&pimpl->workspace, input_data, length_data_length, output_data, reinterpret_cast<eslt_Size32 *>(utput_data_length));
}

uint16_t AeAesGcmDecrypt::AddAuthData(uint8_t *input_data, uint32_t length_data_length)
{
    return esl_updateAuthDataDecryptGCM(&pimpl->workspace, input_data, length_data_length);
}

uint16_t AeAesGcmDecrypt::Finish(uint8_t *output_data, uint32_t *output_data_length, uint8_t *tag)
{
    return esl_finalizeDecryptGCM(&pimpl->workspace, (eslt_Byte *)output_data, (eslt_Size32 *)output_data_length, tag);
}
