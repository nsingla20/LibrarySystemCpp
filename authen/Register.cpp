#include "Register.h"
#include "../Users/Users.h"
#include "../choose.h"
#include <bits/stdc++.h>
User* stu(string username,string password){
    return new Student(username,password);
}
User* prof(string username,string password){
    return new Professor(username,password);
}
User* admin(string username,string password){
    return new Librarian(username,password);
}
void Register(){
    vector<string> ch;
    string username,password;
    ch.insert(ch.end(),{"Register as Student","Register as Professor","Register as admin (Librarian)"});
    int x=choose(ch);
    start:
    cout<<"Please input your Name: ";
    cin>>username;
    // if(UserDatabase::exists(username)){
    //     cout<<"Account already present! Try different username."<<endl;
    //     goto start;
    // }
    cout<<"Please input password: ";
    cin>>password;
    
    User* u;
    switch (x)
    {
    case 1:
        u=stu(username,password);
        break;
    case 2:
        u=prof(username,password);
        break;
    case 3:
        u=admin(username,password);
        break;
    default:
        break;
    }
    cout<<"Your unique id is: "<<(*u).get_id()<<" (Please note it for future ref)"<<endl;
}