#ifndef _CRYPTO_AEAESCCM_H_
#define _CRYPTO_AEAESCCM_H_

#include <memory>
#include <cstdint>

#define AE_AES_CCM_BLOCK_SIZE       (16u)
#define AE_AES_CCM_TAG_LENGTH       (16u)
#define AE_AES_CCM_KEY_SIZE_128     (16u)

#define AE_AES_GCM_ERR_TAG_VERIFICATION (0x2000u + 0x0029u)

/// ENCRYPT
class AeAesCcmEncrypt
{
public:
    AeAesCcmEncrypt();
    ~AeAesCcmEncrypt();
    uint16_t Init(uint8_t *key, uint32_t key_length, uint8_t *nonce, uint32_t nonce_length, uint32_t aad_length, uint32_t msg_length, uint8_t auth_field_size, uint8_t auth_field_size_length);
    uint16_t Update(uint8_t *input_data, uint32_t length_data_length, uint8_t *output_data, uint32_t *utput_data_length);
    uint16_t Finish(uint8_t *output_data, uint32_t *output_data_length, uint8_t *tag);

private:
    class impl;
    std::unique_ptr<impl> pimpl;

    uint16_t KeyLen;
};

/// DECRYPT
class AeAesCcmDecrypt
{
public:
    AeAesCcmDecrypt();
    ~AeAesCcmDecrypt();
    uint16_t Init(uint8_t *key, uint32_t key_length, uint8_t *iv, uint8_t iv_length);
    uint16_t Update(uint8_t *input_data, uint32_t length_data_length, uint8_t *output_data, uint32_t *utput_data_length);
    uint16_t Finish(uint8_t *output_data, uint32_t *output_data_length, uint8_t *tag);

private:
    class impl;
    std::unique_ptr<impl> pimpl;

    uint16_t KeyLen;
};

#endif //_CRYPTO_AEAESCCM_H_
