#include<iostream>
#include<string>
using namespace std;
int main(){
    string word="";
    string newstring="";
    cout<<"Enter a word u want to remove duplicates of";
    cin>>word;
    int n=word.size();
    for ( int i = 0; i < word.size(); i++)
    {
        size_t pos=word.find(word[i]);
        if (newstring.find(word[i])==string::npos)
        {
            newstring+=word[i];            
        }  
    }
    cout<<newstring;
}