#pragma once
#include "User.h"
#include "../Books/Book.h"
// #include <boost/ptr_container/ptr_vector.hpp>
#include<vector>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include<iostream>
#include "clone.h"
class User;
class Book;
class Professor : public User{
    CLONE(Professor)
    // private:
    //     vector<shared_ptr<Book>> books;
    public:
        // static const int fine_day=5;
        // static const int due_days=60;
        Professor(){}
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
    private:
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive & ar, const unsigned int file_version){
            ar & boost::serialization::base_object<User>(*this);
            // for(auto i:books){
            //     ar & i;
            // }
        }
};