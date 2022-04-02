#pragma once
#include "Book.h"
Book& createBook();
void updateBook();
vector<string> issueList();
vector<string> issueList(int x);
int fine(Book& b);