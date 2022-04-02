#include "user_main.h"
#include "../choose.h"
#include "../Books/BookDatabase.h"
#include<vector>
#include<string>
#include "manage.h"
#include "../Books/createBook.h"
void user_main(shared_ptr<User> u){
    vector<string> ch;
    ch.insert(ch.end(),{"List all Books","List My Books","Issue a Book","Return a Book","Exit"});
    start:
    int x=choose(ch);
    string isbn;
    switch (x)
    {
    case 1:
        printv(BookDatabase::list_all());
        break;
    case 2:
        printv(issueList((*u).get_id()));
        break;
    case 3:
        cout<<"ISBN: ";
        cin>>isbn;
        (*(BookDatabase::search(isbn))).book_req(*u);
        break;
    case 4:
        cout<<"ISBN: ";
        cin>>isbn;
        (*(BookDatabase::search(isbn))).unissue();
        break;
    default:
        return;
        break;
    }
    goto start;
}