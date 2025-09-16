// Input a string and print its reverse by accessing characters with at().

#include<iostream>
#include<string>
using namespace std;

int main(){
    string str="Darsh",newstr="";
    int n=str.size(),i;
  for ( i = n-1; i >=0; i--)
  {
    newstr+=str[i];
  }
  
    cout<<"newstr="<<newstr;
}