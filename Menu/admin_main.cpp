#include "../Users/Users.h"
#include "../Books/Books.h"
#include "../choose.h"
#include "../getint.h"
#include "../authen/Register.h"
#include<memory>
#include<bits/stdc++.h>
void printv(vector<string> v){
    for(int i=1;i<=v.size();i++){
        cout<<i<<". "<<v[i-1]<<endl;
    }
}
void change_users(shared_ptr<User> u){
    vector<string> ch;
    ch.insert(ch.end(),{"List all Users","Add a User","Remove a User"});
    int x=choose(ch);
    int id;
    switch (x)
    {
    case 1:
        printv(UserDatabase::list_all());
        break;
    case 2:
        Register();
        break;
    case 3:
        getint("Input the id to del :");
        UserDatabase::del(id);
        break;
    default:
        break;
    }

}
void change_books(shared_ptr<User> u){
    vector<string> ch;
    ch.insert(ch.end(),{"List all Books","Add a Book","Remove a Book"});
    int x=choose(ch);
    string name;
    switch (x)
    {
    case 1:
        printv(UserDatabase::list_all());
        break;
    case 2:
        Register();
        break;
    case 3:
        cout<<"Input username:";
        cin>>name;
        // UserDatabase::del(name);
        break;
    default:
        break;
    }
}
void admin_main(shared_ptr<User> u){
    if(!(*u).is_admin()){
        return;
    }
    vector<string> ch;
    ch.insert(ch.end(),{"Users Panel","Books Panel","Exit"});
    start:
    int x=choose(ch);
    switch (x)
    {
    case 1:
        change_users(u);
        break;
    case 2:
        change_books(u);
        break;
    default:
        return;
        break;
    }
    goto start;
}
