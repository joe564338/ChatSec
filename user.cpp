#include "user.h"

User::User(string usrNm){
    mUserName = usrNm;
}
string User::getName(){
    return mUserName;
}
