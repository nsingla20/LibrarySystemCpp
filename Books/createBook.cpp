#include "createBook.h"
#include "../choose.h"
#include "Book.h"
#include "BookDatabase.h"
#include<iostream>
#include<limits>
#include<string>
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