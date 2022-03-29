#include "User.h"
#include<string>
int User::count=0;
bool User::is_password(string pass){
    return pass==password;
}
bool User::is_admin(){
    return false;
}
int User::get_id(){
    return id;
}
User::User(std::string name,std::string pass):username(name),password(pass){
    id=count++;
}