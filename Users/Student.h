#pragma once
#include "User.h"
#include "../Books/Book.h"
#include <boost/ptr_container/ptr_vector.hpp>
class Student : public User{
    private:
        boost::ptr_vector<Book> books;
    public:
        int due_days() override{
            return 30;
        }
        int fine_day() override{
            return 2;
        }
        int Calc_fine();
        void clear_fine();
};