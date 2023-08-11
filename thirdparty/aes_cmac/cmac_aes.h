#ifndef _AES_CMAC_H_
#define _AES_CMAC_H_

#include <stdlib.h>
#include <stdint.h>

# ifdef __cplusplus
extern "C"
{
# endif

#define CMAC_AES_BLOCK_SIZE     (16u)
#define CMAC_AES_MAC_SIZE       (16u)
#define CMAC_AES128_KEY_SIZE    (16u)
#define CMAC_AES256_KEY_SIZE    (32u)

uint16_t cmac_aes128_init(uint8_t key[CMAC_AES128_KEY_SIZE]);
uint16_t cmac_aes128_update(uint8_t *data, int length);
uint16_t cmac_aes128_finish(uint8_t mac[CMAC_AES_MAC_SIZE]);
uint16_t cmac_aes128_verifyMac(uint8_t inputMac[CMAC_AES_MAC_SIZE]);

uint16_t cmac_aes256_init(uint8_t key[CMAC_AES256_KEY_SIZE]);
uint16_t cmac_aes256_update(uint8_t *data, int length);
uint16_t cmac_aes256_finish(uint8_t mac[CMAC_AES_MAC_SIZE]);
uint16_t cmac_aes256_verifyMac(uint8_t inputMac[CMAC_AES_MAC_SIZE]);

# ifdef __cplusplus
} /* extern "C" */
# endif

#endif //_AES_CMAC_H_
