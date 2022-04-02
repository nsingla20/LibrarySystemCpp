#include "choose.h"
#include "getint.h"
#include <bits/stdc++.h>
#include<limits>
using namespace std;
int choose(vector<string> v){
    // cout << "\033[2J\033[1;1H";
    cout<<"\n\nWhere to go?"<<endl;
    for(int i=1;i<=v.size();i++){
        cout<<"OPTION "<<i<<": "<<v[i-1]<<endl;
    }
    int ;
    do{
        x=getint("Please enter a number from 1 to "+to_string(v.size())+" : ");
    }while(x>v.size()||x<1);
    cout<<"\n\n";
    return x;
}
