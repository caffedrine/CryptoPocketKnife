#ifndef _CRYPTO_HMACSHA1_H_
#define _CRYPTO_HMACSHA1_H_

#include <memory>
#include <cstdint>

#define HMAC_SHA1_MAC_LENGTH    (20u)

class HmacSha1
{
public:
    HmacSha1();
    ~HmacSha1();
    uint16_t Init(uint8_t *key, uint32_t key_length);
    uint16_t Update(uint8_t *data, int length);
    uint16_t Finish(uint8_t mac[HMAC_SHA1_MAC_LENGTH]);
    uint16_t VerifyMac(uint8_t mac[HMAC_SHA1_MAC_LENGTH]);

private:
    class impl;
    std::unique_ptr<impl> pimpl;
};


#endif //_CRYPTO_HMACSHA1_H_
