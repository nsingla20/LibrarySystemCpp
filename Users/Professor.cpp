#include "Professor.h"
#include <ctime>
#include "../Books/Book.h"
#include <boost/ptr_container/ptr_vector.hpp>
#include "UserDatabase.h"

Professor::Professor(string a,string b,int i):User(a,b,i){
    UserDatabase::add(*this);
    // cout<<typeid(this).name()<<" account created with username:"<<a<<endl;
}

int Professor::Calc_fine(){
    int fine=0;
    time_t t;
    for(auto book:books){
        t=book.show_dueDate();
        if(time(0)>t){
            t=difftime(time(0),t);
            fine+=(t/86400)*fine_day();
        }
    }
    return fine;
}
void Professor::clear_fine(){
    for(auto book:books){
        book.unissue();
    }
    books.clear();
}

bool Professor::add_book(Book &b){
    books.push_back(&b);
    return true;
}