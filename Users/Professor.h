#pragma once
#include "User.h"
#include "../Books/Book.h"
#include <boost/ptr_container/ptr_vector.hpp>
#include<iostream>
#include "clone.h"
class User;
class Book;
class Professor : public User{
    CLONE(Professor)
    private:
        boost::ptr_vector<Book> books;
    public:
        // static const int fine_day=5;
        // static const int due_days=60;
        Professor(string a,string b);
        int due_days() override{
            return 60;
        }
        int fine_day() override{
            return 5;
        }
        int Calc_fine() override;
        void clear_fine() override;
        bool add_book(Book &b) override;
};