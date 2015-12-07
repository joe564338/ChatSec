#include "crypter.h"

//#define RSA_F_RSA_PADDING_ADD_PKCS1_OAEP_MGF1        154

Crypter::Crypter()
{

}

char* Crypter::getKey(char* pk){
    FILE *f = fopen(pk, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    char* key;
    key = (char*) malloc(fsize + 1);
    fread(key, fsize, 1, f);
    fclose(f);

    key[fsize] = 0;
    return key;
}

void Crypter::CreateRSA(char * fileName, int publicNum){

    FILE * fp = fopen(fileName,"rb");

    if(fp == NULL)
    {
        printf("Unable to open file %s \n",fileName);
        return;
    }
    RSA *rsaKey = RSA_new() ;

    if(publicNum)
    {
        rsaKey = PEM_read_RSA_PUBKEY(fp, &rsaKey,NULL, NULL);
        mPublicRSA = rsaKey;
    }
    else
    {
        rsaKey = PEM_read_RSAPrivateKey(fp, &rsaKey, NULL, NULL);
        mPrivateRSA = rsaKey;
    }


}

int Crypter::public_encrypt(unsigned char *data, int data_len, unsigned char *encrypted){
    int result = RSA_public_encrypt(data_len, data, encrypted, mPublicRSA, padding);
    return result;
}
int Crypter::private_decrypt(unsigned char *enc_data, int data_len, unsigned char *decrypted){
    int result = RSA_private_decrypt(data_len, enc_data, decrypted, mPrivateRSA, padding);
    return result;
}
