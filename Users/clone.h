#pragma once
#define CLONE(MyType) \
protected:  \
    shared_ptr<User> clone_impl() override { return make_shared<MyType>(*this); } \
public: \
    shared_ptr<MyType> clone() \
    { \
        shared_ptr<User> res = clone_impl(); \
        assert(dynamic_cast<MyType*>(res.get()) != 0); \
        return static_pointer_cast<MyType>(res); \
    }

#define CLONE_BASE(MyType) \
protected:  \
    virtual shared_ptr<User> clone_impl() { return make_shared<MyType>(*this); } \
public: \
    shared_ptr<MyType> clone() \
    { \
        shared_ptr<User> res = clone_impl(); \
        assert(dynamic_cast<MyType*>(res.get()) != 0); \
        return static_pointer_cast<MyType>(res); \
    }