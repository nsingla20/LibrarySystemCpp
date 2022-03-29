#include "UserDatabase.h"
#include "User.h"
#include<string>
#include <fstream>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/serialization/map.hpp> 
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/make_shared.hpp>
#include<iostream>
// boost::ptr_vector<User> UserDatabase::users;
using namespace std;
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
int UserDatabase::count(){
    return m.size();
}
// map<int,shared_ptr<User>> UserDatabase::get_map(){
//     return m;
// }
void UserDatabase::save(){
    ofstream ofs;
    ofs.open("Users.bin", ofstream::out);
    boost::archive::text_oarchive oa(ofs);
    for(auto i:m){
        if(i.second)
            // auto i=boost::make_shared<User>
            oa<<i.second;
    }
    ofs.close();
}
void UserDatabase::load(){
    ifstream ifs;
    try{
        ifs.open("Users.bin", ifstream::in);
        boost::archive::text_iarchive ia(ifs);
        
        while(true){
            shared_ptr<User> u;
            ia>>(u);
            m[(*u).get_id()]=u;
        }
    }catch(exception e){}
    cout<<"User Database loaded"<<endl;
    ifs.close();
}