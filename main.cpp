#include "Users/Users.h"
#include <bits/stdc++.h>
#include "choose.h"
#include "authen/authen.h"
#include<memory>
using namespace std;

int main(int, char**) {
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
}
