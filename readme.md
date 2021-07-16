# Crypto pocket knife

Small tool for all kind of cryptographic operation used often. It currently supports the following:

1. Signatures handling
	* Public/Private keys pair generation for ED25519
	* ED25519 Signature calculation and verification

2. Key exchange
	* X25519 Public/Private keys generator
	* X25519 secret exchange
	* Symmetric keys generator after key exchange

3. Ciphers
	* AES-CTR Encryption/Decryption

4. Hashing
	* SHA512 hashing

5. Cettificates handling
	* Parse X509 certificates from any format: PEM/DER/BIN/File
	* Export X509 certificates to PEM/DER/BIN formats
	* Parse X509 CSR (certificate singing request) from any format: PEM/DER/BIN/File
	* Export X509 CSR to PEM/DER/BIN formats

6. Data encoding
	* Automatic conversion between BIN/ASCII/HEX/Base64


# Previews:
![alt Crypto pocket knife](docs/img/screen.png "Crypto pocket knife")