#ifndef USER
#define USER
#include <stdio.h>
#include <string.h>
#include <string>
using namespace::std;
class User{
public:
    User(string usrNm, string pswrd);

    void Mute(string usrNm);
    void setName(string name);
private:
    string mUserName;
    string mPassword;
    bool muted = false;

};
#endif // USER

