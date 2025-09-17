// Capitalize Middle Character (using at())
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="Darsh";
    int n=s.size(),ascii;
    if(n%2==1){
        cout<<"String has even numbers no middle letter";
    }
    else{
        ascii=s.at((n-1)/2);
        ascii-=32;
        s.at((n-1)/2)=ascii;
    }
    cout<<s;
}