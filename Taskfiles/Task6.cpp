// If the string length is odd, convert the middle character to uppercase.
#include<iostream>
#include<string>
using namespace std;

int main(){
    string s="Darsh";
    int n=s.length(),ascii;
    if (n%2==1)
    {
        ascii=s.at((n-1)/2);
        ascii-=32;
        s.at((n-1)/2)=ascii;
    }
    cout<<s;
    
}