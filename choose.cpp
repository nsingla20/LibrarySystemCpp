#include "choose.h"
#include <bits/stdc++.h>
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
    cin>>x;
    if(x>v.size()||x<1){
        goto start;
    }cout<<"\n\n";
    return x;
}