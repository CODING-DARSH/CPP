// Count Vowels (using size() and at())

#include<iostream>
#include<string>
using namespace std;

int main(){
    string name="Darsh";
    int i,n=name.size(),vowels=0;
    for ( i = 0; i < n; i++)
    {
        if (name.at(i)=='A'|| name.at(i)=='E'|| name.at(i)=='I' ||  name.at(i)=='O' ||  name.at(i)=='U' || name.at(i)=='a'|| name.at(i)=='e'|| name.at(i)=='i' ||  name.at(i)=='o' ||  name.at(i)=='u')
        {
            vowels++;
        }
        
    }
    
    cout<<"Total vowels in string "<<vowels;
}