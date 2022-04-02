#include "Student.h"
#include <ctime>
#include "../Books/Books.h"
#include<iostream>
#include<memory>
#include "UserDatabase.h"
// #include "../Books/createBook.h"
// #include <boost/ptr_container/ptr_vector.hpp>
using namespace std;

Student::Student(string a,string b):User(a,b){
    UserDatabase::add(*this);
    // cout<<typeid(this).name()<<" account created with username:"<<a<<endl;
}
int Student::Calc_fine(){
    int f=0;
    vector<shared_ptr<Book>> books=BookDatabase::userBooks(id);
    for(auto book:books){
        f+=fine(*book);
    }
    return f;
}
void Student::clear_fine(){
    vector<shared_ptr<Book>> books=BookDatabase::userBooks(id);
    for(auto book:books){
        (*book).unissue();
    }
}
bool Student::add_book(Book &b){
    if (BookDatabase::userBooks(id).size()==5){
        cout<<"Max issue limit for issue reached!"<<endl;
        return false;
    }
    // books.push_back(make_shared<Book>(b));
    return true;
}