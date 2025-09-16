#include<iostream>
#include<string>
using namespace std;
int main(){
    string  s="",choice="",appendstr="";
    bool echoice=true;
    
    while (echoice)
    {   
        cout<<"Enter string u want to append ";
        cin>>appendstr;
        s.append(appendstr);
        cout<<s.size()<<endl;
        cout<<s.capacity()<<endl;
        cout<<s<<endl;
    cout<<"Enter yes if u wanna append else no ";
    cin>>choice;
    if (choice=="Yes" || choice=="yes")
    {
        echoice=true;
    }
    else{
        s.clear();
        cout<<s.empty();
        echoice=false;
    }
    }
    
}