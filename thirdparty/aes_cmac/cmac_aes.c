#include "cmac_aes.h"
#include "cmac_aes128.h"

eslt_WorkSpaceCMACAES workspace_aes128;
eslt_WorkSpaceCMACAES workspace_aes256;

uint16_t cmac_aes128_init(uint8_t key[CMAC_AES128_KEY_SIZE])
{
    eslt_ErrorCode retVal = esl_initWorkSpaceHeader(&workspace_aes128.header, ESL_MAXSIZEOF_WS_CMACAES, NULL_PTR);

    if( retVal == ESL_ERC_NO_ERROR )
    {
        retVal = esl_initCMACAES128(&workspace_aes128, CMAC_AES128_KEY_SIZE, key);
    }
    return retVal;
}

uint16_t cmac_aes128_update(uint8_t *data, int length)
{
    return esl_updateCMACAES128(&workspace_aes128, length, data);
}

uint16_t cmac_aes128_finish(uint8_t mac[CMAC_AES_MAC_SIZE])
{
    return esl_finalizeCMACAES128(&workspace_aes128, mac);
}

uint16_t cmac_aes128_verifyMac(uint8_t inputMac[CMAC_AES_MAC_SIZE])
{
    return esl_verifyCMACAES128(&workspace_aes128, inputMac);
}



uint16_t cmac_aes256_init(uint8_t key[CMAC_AES256_KEY_SIZE])
{
    eslt_ErrorCode retVal = esl_initWorkSpaceHeader(&workspace_aes256.header, ESL_MAXSIZEOF_WS_CMACAES, NULL_PTR);

    if( retVal == ESL_ERC_NO_ERROR )
    {
        retVal = esl_initCMACAES256(&workspace_aes256, CMAC_AES256_KEY_SIZE, key);
    }
    return retVal;
}

uint16_t cmac_aes256_update(uint8_t *data, int length)
{
    return esl_updateCMACAES256(&workspace_aes256, length, data);
}

uint16_t cmac_aes256_finish(uint8_t mac[CMAC_AES_MAC_SIZE])
{
    uint32_t macLen = CMAC_AES_MAC_SIZE;
    return esl_finalizeCMACAES256(&workspace_aes256, mac, (eslt_Length *) &macLen);
}

uint16_t cmac_aes256_verifyMac(uint8_t inputMac[CMAC_AES256_KEY_SIZE])
{
    return esl_verifyCMACAES256(&workspace_aes256, inputMac);
}