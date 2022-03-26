#include "Book.h"
#include "../Users/User.h"
#include<memory>
#include<ctime>
using namespace std;
void Book::book_req(const User &u){
    this->issue_to=make_shared<User>(u);
    this->issue_t=time(0);
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