#include<bits/stdc++.h>
#include "Login.h"
#include "../Users/UserDatabase.h"
#include "../Users/User.h"
#include<memory>
using namespace std;
shared_ptr<User> Login(){
    string username,password;
    start:
    cout<<"Please input your username: ";
    cin>>username;
    if(!UserDatabase::exists(username)){
        cout<<"Account not found present! Try different username."<<endl;
        goto start;
    }
    cout<<"Please input password: ";
    cin>>password;
    shared_ptr<User> u=UserDatabase::search(username);
    if(u){
        if(!(*u).is_password(password)){
            cout<<"Wrong Password! Try again."<<endl;
            u=nullptr;
            goto start;
        }
        cout<<"Login Successfull as "<<typeid(*u).name()<<endl;
        // cout<<(*u).Calc_fine()<<endl;
        return u;
    }else{
        cout<<"ERROR Account doesn't exist!"<<endl;
    }
    return nullptr;
}