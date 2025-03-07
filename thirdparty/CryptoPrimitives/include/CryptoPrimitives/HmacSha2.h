#ifndef _CRYPTO_HMACSHA2_H_
#define _CRYPTO_HMACSHA2_H_

#include <memory>
#include <cstdint>

#define HMAC_SHA2_256           (0u)
#define HMAC_SHA2_384           (1u)
#define HMAC_SHA2_256_MAC_LEN   (32u)
#define HMAC_SHA2_384_MAC_LEN   (48u)

class HmacSha2
{
public:
    HmacSha2(uint8_t Sha2Bits);
    ~HmacSha2();
    uint16_t Init(uint8_t *key, uint32_t key_length);
    uint16_t Update(uint8_t *data, uint32_t length);
    uint16_t Finish(uint8_t *mac);
    uint16_t VerifyMac(uint8_t *mac);

private:
    class impl;
    std::unique_ptr<impl> pimpl;

    uint8_t ShaSize;
};


#endif //_CRYPTO_HMACSHA2_H_
