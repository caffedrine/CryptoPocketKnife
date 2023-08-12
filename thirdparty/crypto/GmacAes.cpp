#include "GmacAes.h"
#include "vImpl/ESLib.h"

class GmacAes::impl
{
public:
    eslt_WorkSpaceGMAC workspace;
};

GmacAes::GmacAes(): pimpl{std::make_unique<impl>()}
{

}

GmacAes::~GmacAes()
{

}

uint16_t GmacAes::Init(uint8_t *key, uint32_t key_length, uint8_t *iv, uint32_t iv_length)
{
    eslt_ErrorCode retVal;

    retVal = esl_initWorkSpaceHeader(&pimpl->workspace.header, ESL_MAXSIZEOF_WS_GMAC, reinterpret_cast<esl_WatchdogFuncPtr>((esl_WatchdogFuncPtr *) NULL_PTR));

    if( retVal ==  ESL_ERC_NO_ERROR)
    {
        retVal = esl_initGMAC( &pimpl->workspace,  key_length, key, iv_length, iv);
    }

    return retVal;
}

uint16_t GmacAes::Update(uint8_t *data, int length)
{
    return esl_updateGMAC(&pimpl->workspace, length, data);
}

uint16_t GmacAes::Finish(uint8_t *tag)
{
    return esl_finalizeGMAC(&pimpl->workspace, tag);
}

uint16_t GmacAes::VerifyMac(uint8_t *tag)
{
    return esl_verifyGMAC(&pimpl->workspace, tag);

}



