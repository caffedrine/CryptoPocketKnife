#include "CmacAes.h"

#include "vImpl/ESLib.h"

class CmacAes::impl
{
public:
    eslt_WorkSpaceCMACAES workspace;
};

CmacAes::CmacAes(): pimpl{std::make_unique<impl>()}
{

}

CmacAes::~CmacAes()
{

}

uint16_t CmacAes::Init(uint8_t *key, uint32_t key_length)
{
    this->KeyLen = key_length;

    eslt_ErrorCode retVal = esl_initWorkSpaceHeader(&pimpl->workspace.header, ESL_MAXSIZEOF_WS_CMACAES, reinterpret_cast<esl_WatchdogFuncPtr>((esl_WatchdogFuncPtr *) NULL_PTR));

    if( retVal == ESL_ERC_NO_ERROR )
    {
        if( this->KeyLen == CMAC_AES128_KEY_SIZE )
            retVal = esl_initCMACAES128(&pimpl->workspace, CMAC_AES128_KEY_SIZE, key);
        else if( this->KeyLen == CMAC_AES256_KEY_SIZE )
            retVal = esl_initCMACAES256(&pimpl->workspace, CMAC_AES256_KEY_SIZE, key);
        else
            retVal = 1;
    }
    return retVal;
}

uint16_t CmacAes::Update(uint8_t *data, int length)
{
    if( this->KeyLen == CMAC_AES128_KEY_SIZE )
        return esl_updateCMACAES128(&pimpl->workspace, length, data);
    else if( this->KeyLen == CMAC_AES256_KEY_SIZE )
        return esl_updateCMACAES256(&pimpl->workspace, length, data);
    else
        return 1;
}

uint16_t CmacAes::Finish(uint8_t *mac)
{
    if( this->KeyLen == CMAC_AES128_KEY_SIZE )
        return esl_finalizeCMACAES128(&pimpl->workspace, mac);
    else if( this->KeyLen == CMAC_AES256_KEY_SIZE )
    {
        uint32_t macLen = CMAC_AES_MAC_SIZE;
        return esl_finalizeCMACAES256(&pimpl->workspace, mac, reinterpret_cast<eslt_Length *>(&macLen));
    }
    else
        return 1;
}

uint16_t CmacAes::VerifyMac(uint8_t *mac)
{
    if( this->KeyLen == CMAC_AES128_KEY_SIZE )
        return esl_verifyCMACAES128(&pimpl->workspace, mac);
    else if( this->KeyLen == CMAC_AES256_KEY_SIZE )
        return esl_verifyCMACAES256(&pimpl->workspace, mac);
    else
        return 1;
}
