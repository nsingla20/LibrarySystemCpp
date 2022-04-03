# LibrarySystemCpp

## _Library Management System in C++ (CS253 course)_

[![Build Status](https://github.com/nsingla20/LibrarySystemCpp/actions/workflows/cmake.yml/badge.svg)](https://travis-ci.org/joemccann/dillinger)

- Implement Library Management System in C++ language using Object-oriented programming concepts.
- Implement the system on command line interface.
- List of functionalities:

   1. Implement Login Logout
   2. Professor, Student and Librarian are child classes of User class.

       - Professor Can see all the books. Can see list of books s/he has. Can check if book is available for issue or not. Can issue infinite number of books. Can issue a book for 60 days. Fine is 5 rupees/day after due date.
       - Student Can see all the books. Can see list of books s/he has. Can check if book is available for issue or not. Can issue at max 5 books. Can issue a book for 30 days. Fine is 2 rupees/day after due date.
       - Librarian Can add/update/delete user or book. Can list down all books/users. Can check which book is issued to which user. Can check list of books issue to user.
- Every functionality must be in appropriate class. (Ex. Professor can see all the books. This should be performed by calling Display() method of “Book database” class. You don’t need to put Display all books() method in professor class.)
- List of classes: Use classes shown in Figure 1 to implement above functionalities. You can add more classes or change the structure of classes (add attributes or methods in particular class).

![List of Classes](https://iitk-my.sharepoint.com/:i:/g/personal/nsingla20_iitk_ac_in/EXWxT3wnYa5JueRvtLrRIHQBJKVT7rDRYju_pCZPPkv-1A?e=4qLaCl)

### Steps for execution

- #### Install Boost

    ```sh
    sudo apt-get install libboost-all-dev
    ```

- #### Install CMake

    ```sh
    sudo apt-get -y install cmake
    ```

- #### Run Program

    ```sh
    cmake -S . -B build -G "Unix Makefiles"
    cmake --build build --target LibrarySystemCpp -j 14 --
    ./build/LibrarySystemCpp
    ```
