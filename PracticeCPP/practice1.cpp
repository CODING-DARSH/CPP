#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    // string name="darsh";
    // reverse(name.begin(),name.end());
    // cout<<name;  
    int count=0;
    vector<int> v={0,1,2,3,0,5};
    for (int i = 0; i < v.size(); i++)
    {
        int temp=0;
        if (v[i]==0)
        {
            count+=1;
            v.erase(v.begin()+i);
        }
    }
    for (int i = 0; i < count; i++)
    {
        v.push_back(0);
    }
    for(auto i:v){
        cout<<i;
    }
    
    
}