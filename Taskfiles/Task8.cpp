// Remove Extra Spaces (using erase())
#include<iostream>
#include<string>
using namespace std;

int main(){
    string s="Darsh    vithlani ";
    int i;
    for ( i = 0; i<s.size(); i++)
    {
        if (s.back()==' ')
        {
            s.erase(s.size()-1);
        }
         if (s[i] == ' ' && s[i+1] == ' ')
        {
            s.erase(i,1);
            i--;
        }
    }
    cout<<s;
}
