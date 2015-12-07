#ifndef USER
#define USER
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace::std;
class User{
public:
    User(string usrNm);
    string getName();
    void Mute(string usrNm);
    void SetName(string name);
private:
    string mUserName;
    //all keys stored on user's device only the user's public keys get sent to a key server
    //private keys encrypted and are unlocked by the user's password
    string mMessagePublicKey;
    string mMessagePrivateKey;
    string mSignaturePublicKey;
    string mSignaturePrivateKey;
    vector<User> muted;// list of people muted by the user
    //string mPassword;//password to unlock the encryption on keys
};
#endif // USER

