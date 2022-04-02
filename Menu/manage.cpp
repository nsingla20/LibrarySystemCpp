#include<vector>
#include<string>
#include<iostream>
using namespace std;
void printv(vector<string> v){
    if(v.size()==0){
        cout<<"Empty"<<endl;
        return;
    }
    for(int i=1;i<=v.size();i++){
        cout<<i<<". "<<v[i-1]<<endl;
    }
}