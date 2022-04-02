#include "Student.h"
#include <ctime>
#include "../Books/Book.h"
#include<iostream>
#include<memory>
#include "UserDatabase.h"
// #include <boost/ptr_container/ptr_vector.hpp>
using namespace std;

Student::Student(string a,string b):User(a,b){
    UserDatabase::add(*this);
    // cout<<typeid(this).name()<<" account created with username:"<<a<<endl;
}
int Student::Calc_fine(){
    int fine=0;
    time_t t;
    for(auto book:books){
        t=(*book).show_dueDate();
        if(time(0)>t){
            t=difftime(time(0),t);
            fine+=(t/86400)*fine_day();
        }
    }
    return fine;
}
void Student::clear_fine(){
    for(auto book:books){
        (*book).unissue();
    }
    books.clear();
}
bool Student::add_book(Book &b){
    if (books.size()==5){
        cout<<"Max issue limit reached!"<<endl;
        return false;
    }
    books.push_back(make_shared<Book>(b));
    return true;
}