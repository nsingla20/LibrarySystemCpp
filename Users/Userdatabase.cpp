#include "UserDatabase.h"
#include "User.h"
#include <bits/stdc++.h>
#include<memory>
#include <boost/ptr_container/ptr_vector.hpp>
#include<iostream>
// boost::ptr_vector<User> UserDatabase::users;
map<string,shared_ptr<User>> UserDatabase::m;
void UserDatabase::add(User &u){
    if(exists(u.username)){
        cout<<"Account with username:"<<u.username<<" already in database"<<endl;
    }
    // users.push_back(&u);
    // cout<<u.Calc_fine();
    m[u.username]=u.clone();
    cout<<"Account with username:"<<u.username<<" added to database (Account type:"<<typeid(*(m[u.username])).name()<<") admin:"<<u.is_admin()<<endl;
    // cout<<(*m[u.username]).Calc_fine()<<endl;
}
bool UserDatabase::exists(string username){
    auto i=m.find(username);
    return i!=m.end();
}
void UserDatabase::del(string username){
    m.erase(username);
    cout<<"Account with username:"<<username<<" deleted from database"<<endl;
}
shared_ptr<User> UserDatabase::search(string username){
    if(exists(username)){
        return m[username];
    }
    return nullptr;
}