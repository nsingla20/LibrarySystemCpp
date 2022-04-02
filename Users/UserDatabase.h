#pragma once
#include "User.h"
#include<string>
// #include <boost/ptr_container/ptr_vector.hpp>
// #include <boost/serialization/map.hpp>
// #include <boost/serialization/shared_ptr.hpp>
// #include <boost/serialization/serialization.hpp>

class User;
using namespace std;
class UserDatabase{
    private:
        // static boost::ptr_vector<User> users;
        static map<int,shared_ptr<User>> m;
        
    public:
        static void save();
        static void load();
        static void add(User &u);
        static bool exists(int id);
        static void del(int id);
        static shared_ptr<User> search(int id);
        static vector<string> list_all();
        static int count();
        // static map<int,shared_ptr<User>> get_map();
    // private:
    //     friend class boost::serialization::access;
    //     template<class Archive>
    //     void serialize(Archive & ar, const unsigned int version){
    //         ar & m;
    //     }
};