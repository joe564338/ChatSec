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

    int padding = RSA_PKCS1_PADDING;
    int public_encrypt(unsigned char * data, int data_len, unsigned char *encrypted);
    int private_decrypt(unsigned char * enc_data, int data_len, unsigned char *decrypted);
    char* getKey(char* pk);
private:
    RSA *mPrivateRSA;
    RSA *mPublicRSA;
    




};


#endif // CRYPTER_H
