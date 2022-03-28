#include "Librarian.h"
#include "User.h"
#include "UserDatabase.h"
bool Librarian::is_admin(){
    return true;
}
Librarian::Librarian(string a,string b,int i):User(a,b,i){
    UserDatabase::add(*this);
}