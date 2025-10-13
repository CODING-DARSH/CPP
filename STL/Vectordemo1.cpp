#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector <int> v={100,200,300};
    // for(int x:v){
    //     cout<<x;
    // }   
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<"\n";
    }
    
}