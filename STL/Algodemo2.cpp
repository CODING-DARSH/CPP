#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    vector<int> v={90,70,30,100,210};
    reverse(v.begin(),v.end());    //for asc order 
    // reverse(v.begin(),v.end(),greater<int>()); //for sorting in desc order
    for(auto i:v){
        cout<<"\n"<<i;
    }
    vector<string> s={"darsh","harsh","yash"};
    reverse(s.begin(),s.end());
    for (auto i:s){
        cout<<"\n"<<i;
    }
    string name="darsh";
    reverse(name.begin(),name.end());
    for(auto i:name){
        cout<<"\n"<<i;
        }

}

