#include "choose.h"
#include <bits/stdc++.h>
#include<limits>
using namespace std;
int choose(vector<string> v){
    // cout << "\033[2J\033[1;1H";
    cout<<"\n\nWhere to go?"<<endl;
    for(int i=1;i<=v.size();i++){
        cout<<"OPTION "<<i<<": "<<v[i-1]<<endl;
    }
    int x;
    start:
    cout<<"Please enter a number from 1 to "<<v.size()<<" : ";
    x=0;
    cin>>x;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(x>v.size()||x<1){
        goto start;
    }cout<<"\n\n";
    return x;
}