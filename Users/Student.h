#pragma once
#include "User.h"
#include "../Books/Book.h"
#include <boost/ptr_container/ptr_vector.hpp>
#include "clone.h"
class Book;
class User;
class Student : public User{
    CLONE(Student)
    private:
        boost::ptr_vector<Book> books;
    public:
        int due_days() override{
            return 30;
        }
        int fine_day() override{
            return 2;
        }
        int Calc_fine() override;
        void clear_fine() override;
        bool add_book(Book &b) override;
        Student(std::string s, std::string t);
};