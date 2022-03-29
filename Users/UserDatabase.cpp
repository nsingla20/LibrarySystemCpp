#include "UserDatabase.h"
#include "User.h"
#include <bits/stdc++.h>
#include<memory>
#include <boost/ptr_container/ptr_vector.hpp>
#include<iostream>
// boost::ptr_vector<User> UserDatabase::users;
// using namespace std;
map<int,shared_ptr<User>> UserDatabase::m;
void UserDatabase::add(User &u){
    if(exists(u.get_id())){
        cout<<"Account with id:"<<u.get_id()<<" already in database"<<endl;
    }
    // users.push_back(&u);
    // cout<<u.Calc_fine();
    m[u.get_id()]=u.clone();
    cout<<"Account with id:"<<u.get_id()<<" added to database (Account type:"<<typeid(*(m[u.get_id()])).name()<<") admin:"<<u.is_admin()<<endl;
    // cout<<(*m[u.username]).Calc_fine()<<endl;
}
bool UserDatabase::exists(int id){
    auto i=m.find(id);
    return i!=m.end();
}
void UserDatabase::del(int id){
    m.erase(id);
    cout<<"Account with id:"<<id<<" deleted from database"<<endl;
}
shared_ptr<User> UserDatabase::search(int id){
    if(exists(id)){
        return m[id];
    }
    return nullptr;
}
vector<string> UserDatabase::list_all(){
    vector<string> v;
    string s="";
    for(auto i:m){
        s="Name:"+(*i.second).username+" Type:"+typeid(*(i.second)).name()+" id:"+to_string((*i.second).get_id())+" Admin:"+(((*i.second).is_admin())?"True":"False");
        v.push_back(s);
    }
    return v;
}