#include<iostream>
#include<string>
using namespace std;

int main(){
    string s=" Darsh  vithlani  ";
    int i;
    cout<<s<<endl;
    for (i = 0; i < s.size(); i++)
    {
    if (s.front()==' ')
    {
        s.erase(i,1);
    }
    else if(s[i]==' ' && s[i+1]==' '){
        s.erase(i,1);
        i--;
    }
    else if(s.back()==' '){
        s.erase(s.size()-1);
    }
    }
    
    cout<<s;
}