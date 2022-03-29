#include "Librarian.h"
#include "User.h"
#include "UserDatabase.h"
bool Librarian::is_admin(){
    return true;
}
Librarian::Librarian(string a,string b):User(a,b){
    UserDatabase::add(*this);
}