#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    vector <string>v;
    string name;
    while (true)
    {
        cout<<"Enter name or exit";
        cin>>name;
        if (name=="exit")
        {
            cout<<"Exiting \n";
            break;
        }
        else{
            v.push_back(name);
        }
    }
    for(string x:v){
        cout<<x<<"\n";
    }
    
}