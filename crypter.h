#ifndef CRYPTER_H
#define CRYPTER_H
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <stdio.h>
#include <string>
#include <openssl/rand.h>

class Crypter
{
public:
    Crypter();
    void CreateRSA(char * fileName, int publicNum);
    /*static int RSA_padding_add_PKCS1_OAEP_mgf1_SHA256(unsigned char *to, int tlen,
        const unsigned char *from, int flen,
        const unsigned char *param, int plen,
        const EVP_MD *md, const EVP_MD *mgf1md);
    static int RSA_padding_add_PKCS1_OAEP_SHA256(unsigned char *to, int tlen,
        const unsigned char *from, int flen,
        const unsigned char *param, int plen);
    static int RSA_eay_public_encrypt_SHA256(int flen, const unsigned char *from,
        unsigned char *to, RSA *rsa, int padding);
    int RSA_public_encrypt_sha256(int flen, const unsigned char *from, unsigned char *to,
        RSA *rsa, int padding);*/
    int padding = RSA_PKCS1_PADDING;
    int public_encrypt(unsigned char * data, int data_len, unsigned char *encrypted);
    int private_decrypt(unsigned char * enc_data, int data_len, unsigned char *decrypted);
private:
    RSA *mPrivateRSA;
    RSA *mPublicRSA;
    




};


#endif // CRYPTER_H
