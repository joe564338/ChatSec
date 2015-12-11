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
//Class for handling encryption/decryption
class Crypter
{
public:
    Crypter();
    void CreateRSA(char * fileName, int publicNum);//for obtaining rsa keys from file.

    int padding = RSA_PKCS1_PADDING;
    int public_encrypt(unsigned char * data, int data_len, unsigned char *encrypted);//encrypts msgs
    int private_decrypt(unsigned char * enc_data, int data_len, unsigned char *decrypted);//decrypts msgs
    char* getKey(char* pk); //for retrieving public key to upload to server
private:
    RSA *mPrivateRSA;//Holds private key
    RSA *mPublicRSA;//holds public key
    




};


#endif // CRYPTER_H
