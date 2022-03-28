#pragma once
#include "User.h"
class Librarian : public User{
    public:
        bool is_admin() override;
        Librarian(string a,string b,int i);
};