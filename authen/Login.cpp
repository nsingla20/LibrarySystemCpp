#include<bits/stdc++.h>
#include "Login.h"
#include "../Users/UserDatabase.h"
#include "../Users/User.h"
#include "../getint.h"
#include<memory>
using namespace std;
shared_ptr<User> Login(){
    int id;
    string password;
    start:
    id=getint("Please input your id: ");
    if(!UserDatabase::exists(id)){
        cout<<"Account not found present! Try different id."<<endl;
        goto start;
    }
    cout<<"Please input password: ";
    cin>>password;
    shared_ptr<User> u=UserDatabase::search(id);
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