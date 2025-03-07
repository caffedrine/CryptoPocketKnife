#ifndef _CRYPTO_CMACAES_H_
#define _CRYPTO_CMACAES_H_

#include <memory>
#include <cstdint>

#define CMAC_AES_BLOCK_SIZE     (16u)
#define CMAC_AES_MAC_SIZE       (16u)
#define CMAC_AES128_KEY_SIZE    (16u)
#define CMAC_AES256_KEY_SIZE    (32u)
#define CMAC_INCORRECT_MAC       (0x2000u + 0x000Fu)

class CmacAes
{
public:
    CmacAes();
    ~CmacAes();
    uint16_t Init(uint8_t *key, uint32_t key_length);
    uint16_t Update(uint8_t *data, int length);
    uint16_t Finish(uint8_t mac[CMAC_AES_MAC_SIZE]);
    uint16_t VerifyMac(uint8_t mac[CMAC_AES_MAC_SIZE]);

private:
    class impl;
    std::unique_ptr<impl> pimpl;

    uint16_t KeyLen;
};



#endif //_CRYPTO_CMACAES_H_
