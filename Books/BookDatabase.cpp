#include "BookDatabase.h"
#include "Book.h"
#include<string>
#include <fstream>
// #include <boost/ptr_container/ptr_vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include<map>
#include<vector>
#include<memory>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include<iostream>
#include "createBook.h"
using namespace std;
map<string,shared_ptr<Book>> BookDatabase::m;
void BookDatabase::save(){
    ofstream ofs;
    ofs.open("Books.dat", ofstream::out);
    boost::archive::text_oarchive oa(ofs);
    for(auto i:m){
        if(i.second)
            // auto i=boost::make_shared<User>
            oa<<i.second;
    }
    ofs.close();
}
void BookDatabase::load(){
    ifstream ifs;
    try{
        ifs.open("Books.dat", ifstream::in);
        boost::archive::text_iarchive ia(ifs);
        
        while(true){
            shared_ptr<Book> b;
            ia>>(b);
            m[(*b).ISBN]=b;
        }
    }catch(exception e){}
    cout<<"Book Database loaded with "<<m.size()<<" books"<<endl;
    ifs.close();
}
vector<string> BookDatabase::list_all(){
    vector<string> v;
    // string s="";
    for(auto i:m){
        // s="Title: "+(*i.second).title+"; Author: "+(*(i.second)).author+"; ISBN: "+(*(i.second)).ISBN+"; Publication: "+(*(i.second)).Pub;
        v.push_back(string(*(i.second)));
    }
    return v;
}
vector<string> BookDatabase::list_issue(){
    vector<string> v;
    for(auto i:m){
        if((*(i.second)).get_issue_to()!=nullptr){
            v.push_back(string(*(i.second))+"\nFine: Rs"+to_string(fine(*(i.second))));
        }
    }
    return v;
}
vector<string> BookDatabase::list_issue(int id){
    vector<string> v;
    for(auto i:m){
        if((*(i.second)).get_issue_to()!=nullptr && (*((*(i.second)).get_issue_to())).get_id()==id){
            v.push_back(string(*(i.second))+"\nFine: Rs"+to_string(fine(*(i.second))));
        }
    }
    return v;
}
bool BookDatabase::exists(string ISBN){
    auto i=m.find(ISBN);
    return i!=m.end();
}
void BookDatabase::add(Book &b){
    if(exists(b.ISBN)){
        cout<<"Book with ISBN:"<<b.ISBN<<" already in database"<<endl;
        return;
    }
    // users.push_back(&u);
    // cout<<u.Calc_fine();
    m[b.ISBN]=make_shared<Book>(b);
    cout<<"Book with ISBN:"<<b.ISBN<<" added to database"<<endl;
    // cout<<(*m[u.username]).Calc_fine()<<endl;
    save();
}
void BookDatabase::del(string ISBN){
    m.erase(ISBN);
    cout<<"Book with ISBN:"<<ISBN<<" deleted from database"<<endl;
}
shared_ptr<Book> BookDatabase::search(string ISBN){
    if(exists(ISBN)){
        return m[ISBN];
    }
    return nullptr;
}
int BookDatabase::count(){
    return m.size();
}
vector<shared_ptr<Book>> BookDatabase::userBooks(int id){
    vector<shared_ptr<Book>> v;
    for(auto i:m){
        if((*(i.second)).get_issue_to()!=nullptr && (*((*(i.second)).get_issue_to())).get_id()==id){
            v.push_back(i.second);
        }
    }
    return v;
}