# LibrarySystemCpp

## _Library Management System in C++ (CS253 course)_

[![Build Status](https://github.com/nsingla20/LibrarySystemCpp/actions/workflows/cmake.yml/badge.svg)](https://travis-ci.org/joemccann/dillinger)

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
