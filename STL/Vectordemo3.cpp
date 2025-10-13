#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    
    vector<int>v;

    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);
    v.pop_back();
    for(int x:v){
        cout<<"  x="<<x;
    }
    cout<<"\n";
        v.erase(v.begin()+2);
    cout<<"\n";
    for(int x:v){
        cout<<"  x="<<x;
    }

    v.clear();
    for(int x:v){
        cout<<"  x="<<x;
    }
}