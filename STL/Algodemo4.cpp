#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
    vector<string> s={"Darsh","harsh","yash"};
    auto i= find(s.begin(),s.end(),"Darsh");
    if(i!=s.end()){
        cout<<"found at index"<<(i-s.begin());
    }
}
