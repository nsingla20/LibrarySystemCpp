#include "Professor.h"
#include <ctime>
#include "../Books/Books.h"
// #include <boost/ptr_container/ptr_vector.hpp>
#include "UserDatabase.h"
#include<memory>

Professor::Professor(string a,string b):User(a,b){
    UserDatabase::add(*this);
    // cout<<typeid(this).name()<<" account created with username:"<<a<<endl;
}

int Professor::Calc_fine(){
    int f=0;
    vector<shared_ptr<Book>> books=BookDatabase::userBooks(id);
    time_t t;
    for(auto book:books){
        f+=fine(*book);
    }
    return f;
}
void Professor::clear_fine(){
    vector<shared_ptr<Book>> books=BookDatabase::userBooks(id);
    for(auto book:books){
        (*book).unissue();
    }
}

bool Professor::add_book(Book &b){
    // books.push_back(make_shared<Book>(b));
    return true;
}