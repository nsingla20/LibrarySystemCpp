#include "getint.h"
#include<iostream>
#include<string>
#include<limits>
using namespace std;
int getint(string s){
    int x;
    start:
    cout<<s;
    cin>>x;
    if(cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        goto start;
    }else{
        return x;
    }
    return -1;
}