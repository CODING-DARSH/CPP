#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    vector<string> v={"darsh","harsh"};
    sort(v.begin(),v.end(),greater<int>());
    // for(auto i:v){
        cout<<"max element is "<<v[0]; 
    // }
}