#ifndef USER
#define USER
#include <stdio.h>
#include <string.h>
#include <string>

class User{
public:
    User(string usrNm, string pswrd);
    void Mute(string usrNm);
private:
    string mUserName;
    string mPassword;
    bool muted = false;

}
#endif // USER

