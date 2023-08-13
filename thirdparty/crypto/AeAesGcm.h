#ifndef _CRYPTO_AEAESGCM_H_
#define _CRYPTO_AEAESGCM_H_

#include <memory>
#include <cstdint>

#define AE_AES_GCM_BLOCK_SIZE       (16u)
#define AE_AES_GCM_TAG_LENGTH       (16u)
#define AE_AES_GCM_KEY_SIZE_128     (16u)
#define AE_AES_GCM_KEY_SIZE_192     (24u)
#define AE_AES_GCM_KEY_SIZE_256     (32u)

/// ENCRYPT
class AeAesGcmEncrypt
{
public:
    AeAesGcmEncrypt();
    ~AeAesGcmEncrypt();
    uint16_t Init(uint8_t *key, uint32_t key_length, uint8_t *iv, uint8_t iv_length);
    uint16_t AddEncData(uint8_t *input_data, uint32_t length_data_length, uint8_t *output_data, uint32_t *utput_data_length);
    uint16_t AddAuthData(uint8_t *input_data, uint32_t length_data_length);
    uint16_t Finish(uint8_t *output_data, uint32_t *output_data_length, uint8_t *tag);

private:
    class impl;
    std::unique_ptr<impl> pimpl;

    uint16_t KeyLen;
};

/// DECRYPT
class AeAesGcmDecrypt
{
public:
    AeAesGcmDecrypt();
    ~AeAesGcmDecrypt();
    uint16_t Init(uint8_t *key, uint32_t key_length, uint8_t *iv, uint8_t iv_length);
    uint16_t AddDecData(uint8_t *input_data, uint32_t length_data_length, uint8_t *output_data, uint32_t *utput_data_length);
    uint16_t AddAuthData(uint8_t *input_data, uint32_t length_data_length);
    uint16_t Finish(uint8_t *output_data, uint32_t *output_data_length, uint8_t *tag);

private:
    class impl;
    std::unique_ptr<impl> pimpl;

    uint16_t KeyLen;
};

#endif //_CRYPTO_AEAESGCM_H_
