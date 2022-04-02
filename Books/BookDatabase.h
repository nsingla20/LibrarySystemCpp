#pragma once
#include "Book.h"
#include<string>
#include<memory>
#include<vector>
#include<map>
using namespace std;
class Book;

class BookDatabase{
    private:
        static map<string,shared_ptr<Book>> m;

    public:
        static void save();
        static void load();
        static void add(Book &u);
        static bool exists(string isbn);
        static void del(string isbn);
        static shared_ptr<Book> search(string isbn);
        static vector<string> list_all();
        static vector<string> list_issue();
        static vector<string> list_issue(int id);
        static vector<shared_ptr<Book>> userBooks(int id);
        static int count();
};