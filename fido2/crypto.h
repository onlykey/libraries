// Copyright 2019 SoloKeys Developers
//
// Licensed under the Apache License, Version 2.0, <LICENSE-APACHE or
// http://apache.org/licenses/LICENSE-2.0> or the MIT license <LICENSE-MIT or
// http://opensource.org/licenses/MIT>, at your option. This file may not be
// copied, modified, or distributed except according to those terms.
#ifndef _CRYPTO_H
#define _CRYPTO_H

#include <stddef.h>

#define USE_SOFTWARE_IMPLEMENTATION

#ifdef __cplusplus
extern "C"
{
#endif

void crypto_sha256_init();
void crypto_sha256_update(uint8_t * data, size_t len);
void crypto_sha256_update_secret();
void crypto_sha256_final(uint8_t * hash);

void crypto_sha256_hmac_init(uint8_t * key, uint32_t klen, uint8_t * hmac);
void crypto_sha256_hmac_final(uint8_t * key, uint32_t klen, uint8_t * hmac);

void crypto_ecc256_init();
void crypto_ecc256_derive_public_key(uint8_t * data, int len, uint8_t * x, uint8_t * y);

void crypto_ecc256_load_key(uint8_t * data, int len, uint8_t * data2, int len2);
void crypto_ecc256_load_attestation_key();
void crypto_load_external_key(uint8_t * key, int len);
void crypto_ecc256_sign(uint8_t * data, int len, uint8_t * sig);
void crypto_ecdsa_sign(uint8_t * data, int len, uint8_t * sig, int MBEDTLS_ECP_ID);


void generate_private_key(uint8_t * data, int len, uint8_t * data2, int len2, uint8_t * privkey);
void crypto_ecc256_make_key_pair(uint8_t * pubkey, uint8_t * privkey);
void crypto_ecc256_shared_secret(const uint8_t * pubkey, const uint8_t * privkey, uint8_t * shared_secret);

#define CRYPTO_TRANSPORT_KEY2            ((uint8_t*)2)
#define CRYPTO_TRANSPORT_KEY            ((uint8_t*)1)
#define CRYPTO_MASTER_KEY               ((uint8_t*)0)

#define crypto_aes256_decrypt aes_cbc_decrypt
#define crypto_aes256_encrypt aes_cbc_encrypt

void crypto_reset_master_secret();
void crypto_load_master_secret(uint8_t * key);


extern uint8_t attestation_cert_der[768];
extern uint16_t attestation_cert_der_size;

extern uint8_t attestation_key[33];
extern uint16_t attestation_key_size;

#ifdef __cplusplus
}
#endif

#endif