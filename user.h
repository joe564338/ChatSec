#ifndef USER
#define USER
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
//Class for users
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
    /*
    string mMessagePublicKey;
    string mMessagePrivateKey;
    string mSignaturePublicKey;
    string mSignaturePrivateKey;*/
    vector<User> muted;// list of people muted by the user

};
#endif // USER

