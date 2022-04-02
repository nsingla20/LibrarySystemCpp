#include "Books.h"
#include "../Users/User.h"
// #include <boost/serialization/shared_ptr.hpp>
#include<ctime>
#include<iostream>
using namespace std;

using namespace std;
bool Book::book_req(User &u){
    if(is_available()){
        if(u.add_book(*this)){
            this->issue_to=make_shared<User>(u);
            this->issue_t=time(0);
            return true;
        }
        return false;
    }
    cout<<"Sorry "<<u.username<<" ,Book is currently issued to "<<issue_to->username<<endl;
    return true;
}

// template<typename U>
time_t Book::show_dueDate(){
    // time_t t=new time_t(this->issue_t);
    struct tm due_tm = *localtime(&(this->issue_t));
    due_tm.tm_mday+=this->issue_to->due_days();
    time_t t=mktime(&due_tm);
    return t;
}

shared_ptr<User> Book::get_issue_to(){return issue_to;}
time_t Book::get_issue_t(){return issue_t;}

bool Book::is_available(){
    return issue_to==nullptr;
}
void Book::unissue(){
    issue_to=nullptr;
    issue_t=time(0);
}
Book::Book(string t,string a,string I,string P):title(t),author(a),ISBN(I),Pub(P){
    BookDatabase::add(*this);
}