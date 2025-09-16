// Insert Separator (using insert())
#include<iostream>
#include<string>
using namespace std;

int main(){
    string s="Darsh";
    int i;
    for ( i = 1; i<s.size(); i+=2)
    {
        s.insert(i,"-");
    }
    cout<<s;
}