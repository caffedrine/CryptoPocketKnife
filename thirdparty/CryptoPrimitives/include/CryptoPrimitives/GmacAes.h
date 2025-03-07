#ifndef _AES_GMAC_H_
#define _AES_GMAC_H_

#include <memory>
#include <cstdint>

#define GMAC_AES_BLOCK_SIZE         (16u)
#define GMAC_AES_MAC_TAG_LENGTH     (16u)
#define GMAC_AES_GCM_KEY_SIZE_128   (16u)
#define GMAC_AES_GCM_KEY_SIZE_192   (24u)
#define GMAC_AES_GCM_KEY_SIZE_256   (32u)

#define GMAC_AES_TAG_INCORRECT      (0x2000u + 0x0029u)

class GmacAes
{
public:
    GmacAes();
    ~GmacAes();
    uint16_t Init(uint8_t *key, uint32_t key_length, uint8_t *iv, uint32_t iv_length);
    uint16_t Update(uint8_t *data, int length);
    uint16_t Finish(uint8_t tag[GMAC_AES_MAC_TAG_LENGTH]);
    uint16_t VerifyMac(uint8_t tag[GMAC_AES_MAC_TAG_LENGTH]);

private:
    class impl;
    std::unique_ptr<impl> pimpl;
};

#endif //_AES_GMAC_H_
