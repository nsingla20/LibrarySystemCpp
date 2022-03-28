#pragma once
#include "User.h"
#include<string>
#include <boost/ptr_container/ptr_vector.hpp>
#include<memory>
#include <map>
class User;
using namespace std;
class UserDatabase{
    private:
        // static boost::ptr_vector<User> users;
        static map<string,shared_ptr<User>> m;
    public:
        static void add(User &u);
        static bool exists(string username);
        static void del(string username);
        static shared_ptr<User> search(string username);
};