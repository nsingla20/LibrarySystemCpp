#pragma once
#include "User.h"
#include "clone.h"
class Librarian : public User{
    CLONE(Librarian)
    public:
        bool is_admin() override;
        Librarian(string a,string b);
};