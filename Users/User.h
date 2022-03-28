#pragma once
#include<string>
#include<iostream>
// #include<memory>
#include "../Books/Book.h"
#include "UserDatabase.h"
class UserDatabase;
class Book;
class User{
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
        User(std::string name,std::string pass,int i):username(name),password(pass),id(i){}
    public:
        std::string username;
        
        User()=delete;
        bool is_password(std::string pass);
        virtual bool is_admin();
        int get_id();
};