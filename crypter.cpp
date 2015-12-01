#include "crypter.h"

//#define RSA_F_RSA_PADDING_ADD_PKCS1_OAEP_MGF1        154

Crypter::Crypter()
{

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
/*
int Crypter::RSA_padding_add_PKCS1_OAEP_mgf1_SHA256(unsigned char *to, int tlen,
    const unsigned char *from, int flen, const unsigned char *param, int plen,
    const EVP_MD *md, const EVP_MD *mgf1md){
    int i, emlen = tlen - 1;
    unsigned char *db, *seed;
    unsigned char *dbmask, seedmask[EVP_MAX_MD_SIZE];
    int mdlen;

    if (md == NULL)
        md = EVP_sha256(); //HERE IS THE ACTUAL USE OF SHAR256 digest!
    if (mgf1md == NULL)
        mgf1md = md;

    mdlen = EVP_MD_size(md);

    if (flen > emlen - 2 * mdlen - 1)
    {
        RSAerr(RSA_F_RSA_PADDING_ADD_PKCS1_OAEP_MGF1,
        RSA_R_DATA_TOO_LARGE_FOR_KEY_SIZE);
        return 0;
    }

    if (emlen < 2 * mdlen + 1)
    {
        RSAerr(RSA_F_RSA_PADDING_ADD_PKCS1_OAEP_MGF1, RSA_R_KEY_SIZE_TOO_SMALL);
        return 0;
    }

    to[0] = 0;
    seed = to + 1;
    db = to + mdlen + 1;

    if (!EVP_Digest((void *)param, plen, db, NULL, md, NULL))
        return 0;
    memset(db + mdlen, 0, emlen - flen - 2 * mdlen - 1);
    db[emlen - flen - mdlen - 1] = 0x01;
    memcpy(db + emlen - flen - mdlen, from, (unsigned int)flen);
    if (RAND_bytes(seed, mdlen) <= 0)
        return 0;
    #ifdef PKCS_TESTVECT
        memcpy(seed,
            "\xaa\xfd\x12\xf6\x59\xca\xe6\x34\x89\xb4\x79\xe5\x07\x6d\xde\xc2\xf0\x6c\xb5\x8f",
            20);
    #endif

    dbmask = (unsigned char*)OPENSSL_malloc(emlen - mdlen);
    if (dbmask == NULL)
    {
        RSAerr(RSA_F_RSA_PADDING_ADD_PKCS1_OAEP_MGF1, ERR_R_MALLOC_FAILURE);
        return 0;
    }

    if (PKCS1_MGF1(dbmask, emlen - mdlen, seed, mdlen, mgf1md) < 0)
        return 0;
    for (i = 0; i < emlen - mdlen; i++)
        db[i] ^= dbmask[i];

    if (PKCS1_MGF1(seedmask, mdlen, db, emlen - mdlen, mgf1md) < 0)
        return 0;
    for (i = 0; i < mdlen; i++)
        seed[i] ^= seedmask[i];

    OPENSSL_free(dbmask);
    return 1;
}

int Crypter::RSA_padding_add_PKCS1_OAEP_SHA256(unsigned char *to, int tlen,
    const unsigned char *from, int flen, const unsigned char *param, int plen){
    return RSA_padding_add_PKCS1_OAEP_mgf1_SHA256(to, tlen, from, flen,
            param, plen, NULL, NULL);
}
int Crypter::RSA_eay_public_encrypt_SHA256(int flen, const unsigned char *from,
    unsigned char *to, RSA *rsa, int padding){
    BIGNUM *f, *ret;
        int i, j, k, num = 0, r = -1;
        unsigned char *buf = NULL;
        BN_CTX *ctx = NULL;

    #ifdef OPENSSL_FIPS
        if (FIPS_selftest_failed())
        {
            FIPSerr(FIPS_F_RSA_EAY_PUBLIC_ENCRYPT, FIPS_R_FIPS_SELFTEST_FAILED);
            if (ctx != NULL)
            {
                BN_CTX_end(ctx);
                BN_CTX_free(ctx);
            }
            if (buf != NULL)
            {
                OPENSSL_cleanse(buf, num);
                OPENSSL_free(buf);
            }
            return(r);
        }

        if (FIPS_module_mode() && !(rsa->flags & RSA_FLAG_NON_FIPS_ALLOW)
            && (BN_num_bits(rsa->n) < OPENSSL_RSA_FIPS_MIN_MODULUS_BITS))
        {
            RSAerr(RSA_F_RSA_EAY_PUBLIC_ENCRYPT, RSA_R_KEY_SIZE_TOO_SMALL);
            return -1;
        }
    #endif

        if (BN_num_bits(rsa->n) > OPENSSL_RSA_MAX_MODULUS_BITS)
        {
            RSAerr(RSA_F_RSA_EAY_PUBLIC_ENCRYPT, RSA_R_MODULUS_TOO_LARGE);
            return -1;
        }

        if (BN_ucmp(rsa->n, rsa->e) <= 0)
        {
            RSAerr(RSA_F_RSA_EAY_PUBLIC_ENCRYPT, RSA_R_BAD_E_VALUE);
            return -1;
        }

        /* for large moduli, enforce exponent limit *//*
        if (BN_num_bits(rsa->n) > OPENSSL_RSA_SMALL_MODULUS_BITS)
        {
            if (BN_num_bits(rsa->e) > OPENSSL_RSA_MAX_PUBEXP_BITS)
            {
                RSAerr(RSA_F_RSA_EAY_PUBLIC_ENCRYPT, RSA_R_BAD_E_VALUE);
                return -1;
            }
        }

        if ((ctx = BN_CTX_new()) == NULL) goto err;
        BN_CTX_start(ctx);
        f = BN_CTX_get(ctx);
        ret = BN_CTX_get(ctx);
        num = BN_num_bytes(rsa->n);
        buf = (unsigned char*)OPENSSL_malloc(num);
        if (!f || !ret || !buf)
        {
            RSAerr(RSA_F_RSA_EAY_PUBLIC_ENCRYPT, ERR_R_MALLOC_FAILURE);
            if (ctx != NULL)
            {
                BN_CTX_end(ctx);
                BN_CTX_free(ctx);
            }
            if (buf != NULL)
            {
                OPENSSL_cleanse(buf, num);
                OPENSSL_free(buf);
            }
            return(r);
        }

        switch (padding)
        {
        case RSA_PKCS1_PADDING:
            i = RSA_padding_add_PKCS1_type_2(buf, num, from, flen);
            break;
    #ifndef OPENSSL_NO_SHA
        case RSA_PKCS1_OAEP_PADDING:
            i = RSA_padding_add_PKCS1_OAEP_SHA256(buf, num, from, flen, NULL, 0);
            break;
    #endif
        case RSA_SSLV23_PADDING:
            i = RSA_padding_add_SSLv23(buf, num, from, flen);
            break;
        case RSA_NO_PADDING:
            i = RSA_padding_add_none(buf, num, from, flen);
            break;
        default:
            RSAerr(RSA_F_RSA_EAY_PUBLIC_ENCRYPT, RSA_R_UNKNOWN_PADDING_TYPE);
            if (ctx != NULL)
            {
                BN_CTX_end(ctx);
                BN_CTX_free(ctx);
            }
            if (buf != NULL)
            {
                OPENSSL_cleanse(buf, num);
                OPENSSL_free(buf);
            }
            return(r);
        }
        if (i <= 0) {
            if (ctx != NULL)
            {
                BN_CTX_end(ctx);
                BN_CTX_free(ctx);
            }
            if (buf != NULL)
            {
                OPENSSL_cleanse(buf, num);
                OPENSSL_free(buf);
            }
            return(r);
        }

        if (BN_bin2bn(buf, num, f) == NULL) {
            if (ctx != NULL)
            {
                BN_CTX_end(ctx);
                BN_CTX_free(ctx);
            }
            if (buf != NULL)
            {
                OPENSSL_cleanse(buf, num);
                OPENSSL_free(buf);
            }
            return(r);
        }

        if (BN_ucmp(f, rsa->n) >= 0)
        {
            /* usually the padding functions would catch this *//*
            RSAerr(RSA_F_RSA_EAY_PUBLIC_ENCRYPT, RSA_R_DATA_TOO_LARGE_FOR_MODULUS);
            if (ctx != NULL)
            {
                BN_CTX_end(ctx);
                BN_CTX_free(ctx);
            }
            if (buf != NULL)
            {
                OPENSSL_cleanse(buf, num);
                OPENSSL_free(buf);
            }
            return(r);
        }

        if (rsa->flags & RSA_FLAG_CACHE_PUBLIC)
            if (!BN_MONT_CTX_set_locked(&rsa->_method_mod_n, CRYPTO_LOCK_RSA, rsa->n, ctx)){
                if (ctx != NULL)
                {
                    BN_CTX_end(ctx);
                    BN_CTX_free(ctx);
                }
                if (buf != NULL)
                {
                    OPENSSL_cleanse(buf, num);
                    OPENSSL_free(buf);
                }
                return(r);
            }

        if (!rsa->meth->bn_mod_exp(ret, f, rsa->e, rsa->n, ctx,
            rsa->_method_mod_n)) {
            if (ctx != NULL)
            {
                BN_CTX_end(ctx);
                BN_CTX_free(ctx);
            }
            if (buf != NULL)
            {
                OPENSSL_cleanse(buf, num);
                OPENSSL_free(buf);
            }
            return(r);
        }

        /* put in leading 0 bytes if the number is less than the
        * length of the modulus *//*
        j = BN_num_bytes(ret);
        i = BN_bn2bin(ret, &(to[num - j]));
        for (k = 0; k<(num - i); k++)
            to[k] = 0;

        r = num;
    err:
        if (ctx != NULL)
        {
            BN_CTX_end(ctx);
            BN_CTX_free(ctx);
        }
        if (buf != NULL)
        {
            OPENSSL_cleanse(buf, num);
            OPENSSL_free(buf);
        }
        return(r);
}
int Crypter::RSA_public_encrypt_sha256(int flen, const unsigned char *from,
    unsigned char *to, RSA *rsa, int padding){
    return(RSA_eay_public_encrypt_SHA256(flen, from, to, rsa, padding));
}*/
int Crypter::public_encrypt(unsigned char *data, int data_len, unsigned char *encrypted){
    int result = RSA_public_encrypt(data_len, data, encrypted, mPublicRSA, padding);
    return result;
}
int Crypter::private_decrypt(unsigned char *enc_data, int data_len, unsigned char *decrypted){
    int result = RSA_private_decrypt(data_len, enc_data, decrypted, mPrivateRSA, padding);
    return result;
}
