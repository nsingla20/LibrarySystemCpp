#include "../Users/Users.h"
#include "../Books/Books.h"
#include "../choose.h"
#include "../getint.h"
#include "../authen/Register.h"
#include<memory>
#include<bits/stdc++.h>
#include "manage.h"
void change_users(shared_ptr<User> u){
    vector<string> ch;
    start:
    ch.clear();
    ch.insert(ch.end(),{"List all Users","Add a User","Remove a User","Update a User","Return to Main menu"});
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
        id=getint("Input the id to del :");
        UserDatabase::del(id);
        break;
    case 4:
        updateUser();
        break;
    default :
        return;
        break;
    }
    goto start;

}
void change_books(shared_ptr<User> u){
    vector<string> ch;
    start:
    ch.clear();
    ch.insert(ch.end(),{"List all Books","Add a Book","Remove a Book","Update a Book","Return to Main menu"});
    int x=choose(ch);
    string isbn;
    switch (x)
    {
    case 1:
        printv(BookDatabase::list_all());
        break;
    case 2:
        createBook();
        break;
    case 3:
        cout<<"ISBN to remove:";
        cin>>isbn;
        BookDatabase::del(isbn);
        break;
    case 4:
        updateBook();
        break;
    default:
        return;
        break;
    }
    goto start;

}
void admin_main(shared_ptr<User> u){
    if(!(*u).is_admin()){
        return;
    }
    vector<string> ch;
    ch.insert(ch.end(),{"Users Panel","Books Panel","Issue List","Exit"});
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
    case 3:
        printv(issueList());
        break;
    default:
        return;
        break;
    }
    goto start;
}
