// Capitalize Middle Character (using at())
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="Darsh";
    int n=s.size(),ascii;
        ascii=s.at((n-1)/2);
        ascii-=32;
        s.at((n-1)/2)=ascii;
    cout<<s;
}