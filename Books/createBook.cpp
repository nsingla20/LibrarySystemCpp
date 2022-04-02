#include "createBook.h"
#include "../choose.h"
#include "Book.h"
#include "BookDatabase.h"
#include "../Users/UserDatabase.h"
#include "../getint.h"
#include<iostream>
#include<limits>
#include<vector>
#include<string>
#include<memory>
Book& createBook(){
    string title,author,ISBN,Pub;
    cout<<"Please fill Book details :"<<endl;
    cout<<"Title : ";
    std::cin.ignore();
    getline(cin,title);
    // std::cin.ignore();
    cout<<"Author : ";
    
    getline(cin,author);
    do{
        cout<<"ISBN : ";
        // std::cin.ignore();
        cin>>ISBN;
    }while(BookDatabase::exists(ISBN));
    std::cin.ignore();
    cout<<"Publication : ";
    
    getline(cin,Pub);
    return *(new Book(title,author,ISBN,Pub));
}
void updateBook(){
    string ISBN;
    cout<<"ISBN : ";
    cin>>ISBN;
    std::cin.ignore();
    if(!BookDatabase::exists(ISBN)){
        cout<<"Book with ISBN: "<<ISBN<<" doesn't exist!"<<endl;
        return;
    }
    string title,author,Pub;
    cout<<"Please fill Book details :"<<endl;
    cout<<"Title : ";
    getline(cin,title);
    // std::cin.ignore();
    cout<<"Author : ";
    
    getline(cin,author);
    
    cout<<"Publication : ";
    
    getline(cin,Pub);
    shared_ptr<Book> b=BookDatabase::search(ISBN);
    (*b).title=title;
    (*b).author=author;
    (*b).Pub=Pub;
    cout<<"Updated Book : "<<string(*b)<<endl;
}
vector<string> issueList(){
    int x;
    x=getint("id(-1 to list all issues): ");
    if(x>-1){
        if(UserDatabase::exists(x)){
            return BookDatabase::list_issue(*UserDatabase::search(x));
        }
        cout<<"User with id: "<<x<<" doesn't exist!"<<endl;
        return *(new vector<string>());
    }else{
        return BookDatabase::list_issue();
    }
}