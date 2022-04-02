#include "Users/Users.h"
#include "Books/BookDatabase.h"
#include <bits/stdc++.h>
#include "choose.h"
#include "authen/authen.h"
#include "Menu/Menu.h"
// #include <boost/serialization/shared_ptr.hpp>
#include <cstdlib>
#include <boost/serialization/export.hpp>
BOOST_CLASS_EXPORT_GUID(Student, "Student")
BOOST_CLASS_EXPORT_GUID(Professor, "Professor")
BOOST_CLASS_EXPORT_GUID(Librarian, "Librarian")
using namespace std;

int main(int, char**) {
    UserDatabase::load();
    BookDatabase::load();
    atexit(UserDatabase::save);
    atexit(BookDatabase::save);
    cout<<"Welcome! to Library Management System"<<endl;
    // Professor p("naman","n",1);
    // Student s("n","n",2);
    // Librarian l("admin","n",1);
    vector<string> ch;
    ch.insert(ch.end(),{"Register","Login"});
    shared_ptr<User> u;
    start:
    int x=choose(ch);
    switch (x)
    {
    case 1:
        Register();
        goto start;
        break;
    case 2:
        u=Login();
        break;
    default:
        return 1;
    }
    if((*u).is_admin()){
        admin_main(u);
    }else{
        user_main(u);
    }
}
