#pragma once
#include "User.h"
#include "clone.h"
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/shared_ptr.hpp>
class Librarian : public User{
    CLONE(Librarian)
    public:
        bool is_admin() override;
        Librarian(string a,string b);
        Librarian(){}
    private:
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive & ar, const unsigned int file_version){
            ar & boost::serialization::base_object<User>(*this);
        }
};