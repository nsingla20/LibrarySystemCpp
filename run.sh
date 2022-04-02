#!/bin/bash
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install libboost-all-dev
sudo apt-get install cmake
cmake -S . -B build -G "Unix Makefiles"
cmake --build build --target LibrarySystemCpp -j 14 --
./build/LibrarySystemCpp