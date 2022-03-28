#include "Register.h"
#include "../Users/Users.h"
#include "../choose.h"
#include <bits/stdc++.h>
void stu(string username,string password){
    Student s(username,password,0);
}
void prof(string username,string password){
    Professor p(username,password,1);
}
void admin(string username,string password){
    Librarian(username,password,2);
}
void Register(){
    vector<string> ch;
    string username,password;
    ch.insert(ch.end(),{"Register as Student","Register as Professor","Register as admin (Librarian)"});
    int x=choose(ch);
    start:
    cout<<"Please input your username: ";
    cin>>username;
    if(UserDatabase::exists(username)){
        cout<<"Account already present! Try different username."<<endl;
        goto start;
    }
    cout<<"Please input password: ";
    cin>>password;
    
    
    switch (x)
    {
    case 1:
        stu(username,password);
        break;
    case 2:
        prof(username,password);
        break;
    case 3:
        admin(username,password);
        break;
    default:
        break;
    }
}