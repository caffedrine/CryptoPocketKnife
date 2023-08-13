#include "HmacSha1.h"
#include "vImpl/ESLib.h"

class HmacSha1::impl
{
public:
    eslt_WorkSpaceHMACSHA1 workspace;
};

HmacSha1::HmacSha1(): pimpl{std::make_unique<impl>()}
{

}

HmacSha1::~HmacSha1()
{

}

uint16_t HmacSha1::Init(uint8_t *key, uint32_t key_length)
{
    eslt_ErrorCode retVal;

    retVal = esl_initWorkSpaceHeader(&pimpl->workspace.header, ESL_MAXSIZEOF_WS_HMACSHA1, reinterpret_cast<esl_WatchdogFuncPtr>((esl_WatchdogFuncPtr *) NULL_PTR));

    if( retVal ==  ESL_ERC_NO_ERROR)
    {
        retVal = esl_initHashMACSHA1( &pimpl->workspace,  key_length, key);
    }

    return retVal;
}

uint16_t HmacSha1::Update(uint8_t *data, int length)
{
    return esl_updateHashMACSHA1(&pimpl->workspace, length, data);
}

uint16_t HmacSha1::Finish(uint8_t *mac)
{
    return esl_finalizeHashMACSHA1(&pimpl->workspace, mac);
}

uint16_t HmacSha1::VerifyMac(uint8_t *mac)
{
    return esl_verifyHashMACSHA1(&pimpl->workspace, mac);
}
