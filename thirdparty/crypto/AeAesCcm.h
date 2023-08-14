#ifndef _CRYPTO_AEAESCCM_H_
#define _CRYPTO_AEAESCCM_H_

#include <memory>
#include <cstdint>

#define AE_AES_CCM_BLOCK_SIZE       (16u)
#define AE_AES_CCM_KEY_SIZE_128     (16u)
#define AE_AES_CCM_NONCE_MIN_LEN    (7u)
#define AE_AES_CCM_NONCE_MAX_LEN    (13u)
#define AE_AES_CCM_AUTH_MIN_LEN     (4u)
#define AE_AES_CCM_AUTH_MAX_LEN     (16u)

#define AE_AES_CCM_ERR_TAG_VERIFICATION (0x2000u + 0x000Fu)

/// ENCRYPT
class AeAesCcmEncrypt
{
public:
    AeAesCcmEncrypt();
    ~AeAesCcmEncrypt();
    uint16_t Init(uint8_t *key, uint32_t key_length, uint8_t *nonce, uint32_t nonce_length, uint32_t aad_length, uint32_t msg_length, uint8_t auth_field_size);
    uint16_t Update(uint8_t *input_data, uint32_t input_data_length, uint8_t *aad, uint32_t aad_length, uint8_t *output_data, uint32_t *output_data_length);
    uint16_t Finish(uint8_t *output_data, uint32_t *output_data_length, uint8_t *tag, uint32_t *tag_length);

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
    uint16_t Init(uint8_t *key, uint32_t key_length, uint8_t *nonce, uint32_t nonce_length, uint32_t aad_length, uint32_t msg_length, uint8_t auth_field_size);
    uint16_t Update(uint8_t *ciphred_data, uint32_t ciphred_data_length, uint8_t *input_aad, uint32_t aad_length, uint8_t *output_data, uint32_t *output_data_length);
    uint16_t Finish(uint8_t *output_data, uint32_t *output_data_length, uint8_t *tag);

private:
    class impl;
    std::unique_ptr<impl> pimpl;

    uint16_t KeyLen;
};

#endif //_CRYPTO_AEAESCCM_H_
