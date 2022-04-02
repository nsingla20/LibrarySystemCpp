#pragma once
#include<string>
#include<iostream>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include "../Books/Book.h"
#include "UserDatabase.h"
#include "clone.h"
#include <boost/serialization/serialization.hpp>
class UserDatabase;
class Book;
class User{
    CLONE_BASE(User)
    public:
        virtual int due_days(){return -1;};
        virtual int fine_day(){return -1;};
        virtual int Calc_fine(){return -10;};
        virtual void clear_fine(){};
        virtual bool add_book(Book &b) {return false;}
    private:
        std::string password;
        int id;
    protected:
        User(std::string name,std::string pass);
    public:
        std::string username;
        
        User(){};
        bool is_password(std::string pass);
        virtual bool is_admin();
        int get_id();
        operator std::string() {return "Name:"+(*this).username+" Type:"+typeid(*(this)).name()+" id:"+to_string((*this).get_id()) + " Admin:"+(((*this).is_admin())?"True":"False");}
    private:
        friend class boost::serialization::access;

        template<class Archive>
        void serialize(Archive & ar, const unsigned int file_version){
            ar & id;
            ar & username;
            ar & password;
        }

};