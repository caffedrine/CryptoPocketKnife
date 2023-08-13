#include "HmacSha2.h"

#include "vImpl/ESLib.h"

class HmacSha2::impl
{
public:
    eslt_WorkSpaceHMACSHA256 *workspace_256;
    eslt_WorkSpaceHMACSHA384 *workspace_384;
};

HmacSha2::HmacSha2(uint8_t ShaSize): pimpl{std::make_unique<impl>()}
{
    this->ShaSize = ShaSize;

    // Initialize only the right workspace
    if( this->ShaSize == HMAC_SHA2_256)
        pimpl->workspace_256 = new eslt_WorkSpaceHMACSHA256;
    else if( this->ShaSize == HMAC_SHA2_384)
        pimpl->workspace_384 = new eslt_WorkSpaceHMACSHA384;

}

HmacSha2::~HmacSha2()
{
    if( this->ShaSize == HMAC_SHA2_256)
        delete pimpl->workspace_256;
    else if( this->ShaSize == HMAC_SHA2_384)
        delete pimpl->workspace_384;
}

uint16_t HmacSha2::Init(uint8_t *key, uint32_t key_length)
{
    eslt_ErrorCode retVal;

    if( this->ShaSize == HMAC_SHA2_256 )
        retVal = esl_initWorkSpaceHeader(&pimpl->workspace_256->header, ESL_MAXSIZEOF_WS_HMACSHA256, reinterpret_cast<esl_WatchdogFuncPtr>((esl_WatchdogFuncPtr *) NULL_PTR));
    else if (this->ShaSize == HMAC_SHA2_384)
        retVal = esl_initWorkSpaceHeader(&pimpl->workspace_384->header, ESL_MAXSIZEOF_WS_HMACSHA384, reinterpret_cast<esl_WatchdogFuncPtr>((esl_WatchdogFuncPtr *) NULL_PTR));
    else
        retVal = 1;

    if( retVal ==  ESL_ERC_NO_ERROR)
    {
        if( this->ShaSize == HMAC_SHA2_256 )
            retVal = esl_initHashMACSHA256( pimpl->workspace_256,  key_length, key);
        else if (this->ShaSize == HMAC_SHA2_384)
            retVal = esl_initHashMACSHA384( pimpl->workspace_384,  key_length, key);
        else
            retVal = 1;
    }

    return retVal;
}

uint16_t HmacSha2::Update(uint8_t *data, uint32_t length)
{
    if( this->ShaSize == HMAC_SHA2_256 )
        return esl_updateHashMACSHA256( pimpl->workspace_256,  length, data);
    else if (this->ShaSize == HMAC_SHA2_384)
        return esl_updateHashMACSHA384( pimpl->workspace_384,  length, data);
    else
        return 1;
}

uint16_t HmacSha2::Finish(uint8_t *mac)
{
    if( this->ShaSize == HMAC_SHA2_256 )
        return esl_finalizeHashMACSHA256( pimpl->workspace_256,  mac);
    else if (this->ShaSize == HMAC_SHA2_384)
        return esl_finalizeHashMACSHA384( pimpl->workspace_384,  mac);
    else
        return 1;
}

uint16_t HmacSha2::VerifyMac(uint8_t *mac)
{
    if( this->ShaSize == HMAC_SHA2_256 )
        return esl_verifyHashMACSHA256( pimpl->workspace_256,  mac);
    else if (this->ShaSize == HMAC_SHA2_384)
        return esl_verifyHashMACSHA384( pimpl->workspace_384,  mac);
    else
        return 1;
}
