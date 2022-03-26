#pragma once
#include<string>
class User{
    public:
        virtual int due_days(){return -1;};
        virtual int fine_day(){return -1;};
    private:
        std::string username;
        std::string password;
        int id;
    public:
        User(std::string name,std::string pass,int i):username(name),password(pass),id(i){}
        User()=delete;
};