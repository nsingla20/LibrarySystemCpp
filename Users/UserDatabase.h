#pragma once
#include "User.h"
#include<string>
// #include <boost/ptr_container/ptr_vector.hpp>
#include<memory>
#include <map>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
class User;
using namespace std;
class UserDatabase{
    private:
        // static boost::ptr_vector<User> users;
        static map<int,shared_ptr<User>> m;
    public:
        static void add(User &u);
        static bool exists(int id);
        static void del(int id);
        static shared_ptr<User> search(int id);
        static vector<string> list_all();

    private:
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive & ar, const unsigned int version){
            ar & m;
        }
};