#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    vector <int>v;
    int choice;
    int number;
    while (true)
    {
        cout<<"Enter 1 for entering number 0 for exit: ";
        cin>>choice;
        if (choice==1)
        {
            cout<<"Enter number: ";
            cin>>number;
            v.push_back(number);
        }
        else{
            cout<<"exiting...\n";
            break;
        }
    }
    for(int x:v){
        cout<<x<<"\n";
    }
}