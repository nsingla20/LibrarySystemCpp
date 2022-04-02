#include "manage.h"
#include "UserDatabase.h"
#include<iostream>
#include<string>
#include<memory>
#include "../getint.h"
void updateUser(){
    int id;
    id=getint("id :");
    if(!UserDatabase::exists(id)){
        cout<<"User with id:"<<id<<" doesn't exist!"<<endl;
    }
    shared_ptr<User> u=UserDatabase::search(id);
    cin.ignore();
    cout<<"Username: "<<endl;
    string username;
    getline(cin,username);
    (*u).username=username;
    cout<<"Updated User: "<<string(*u)<<endl;
}