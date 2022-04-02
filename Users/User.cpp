#include "User.h"
#include "UserDatabase.h"
#include<string>

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
    id=UserDatabase::count();
}
User::operator std::string() {
    return "\nName:"+(*this).username+"\nType:"+typeid(*(this)).name()+"\nid:"+to_string((*this).get_id());
}