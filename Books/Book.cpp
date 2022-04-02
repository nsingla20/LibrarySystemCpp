#include "Books.h"
#include "../Users/User.h"
// #include <boost/serialization/shared_ptr.hpp>
#include<ctime>
#include<iostream>
#include<memory>
using namespace std;

using namespace std;
bool Book::book_req(User &u){
    if(is_available()){
        if(u.add_book(*this)){
            this->issue_to=u.clone();
            this->issue_t=time(0);
            BookDatabase::save();
            cout<<"Book "<<title<<" issued to "<<u.username<<endl;
            return true;
        }
        return false;
    }
    cout<<"Sorry "<<u.username<<" ,Book is currently issued to "<<issue_to->username<<endl;
    return false;
}

// template<typename U>
time_t Book::show_dueDate(){
    // time_t t=new time_t(this->issue_t);
    // struct tm due_tm = *localtime(&(this->issue_t));
    time_t t=issue_t;
    t=t+(this->issue_to->due_days())*24*3600;
    // due_tm.tm_mday+=this->issue_to->due_days();
    // time_t t=mktime(&due_tm);
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
    BookDatabase::save();
    cout<<"Book "<<title<<" returned"<<endl;
}
Book::Book(string t,string a,string I,string P):title(t),author(a),ISBN(I),Pub(P){
    BookDatabase::add(*this);
}
Book::operator std::string(){
    char s[100];
    strftime(s,sizeof(s),"%a %b %d, %Y",localtime(new time_t(this->show_dueDate())));
    return "\nTitle: "+(*this).title
            +"\nAuthor: "+(*(this)).author
            +"\nISBN: "+(*(this)).ISBN
            +"\nPublication: "+(*(this)).Pub
            +"\nIssued to: "+(issue_to==nullptr?"None":((*issue_to).username
                        +"\nDue Date: "+s));
}
