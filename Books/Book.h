#pragma once
#include <ctime>
#include<string>
#include<memory>
#include "../Users/User.h"
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
using namespace std;
class Book{
    private:
        shared_ptr<User> issue_to;
        time_t issue_t;
    public:
        string title;
        string author;
        string ISBN;
        string Pub;

        void book_req(const User &u);
        time_t show_dueDate();

        shared_ptr<User> get_issue_to();
        time_t get_issue_t();
    
        bool is_available();
        void unissue();

    Book(string t,string a,string I,string P):title(t),author(a),ISBN(I),Pub(P){}
};