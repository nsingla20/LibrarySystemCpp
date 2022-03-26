#pragma once
#include "User.h"
#include "../Books/Book.h"
#include <boost/ptr_container/ptr_vector.hpp>
class Professor : public User{
    private:
        boost::ptr_vector<Book> books;
    public:
        // static const int fine_day=5;
        // static const int due_days=60;
        int due_days() override{
            return 60;
        }
        int fine_day() override{
            return 5;
        }
        int Calc_fine();
        void clear_fine();
};