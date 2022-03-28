#include "User.h"
#include<string>
bool User::is_password(string pass){
    return pass==password;
}
bool User::is_admin(){
    return false;
}