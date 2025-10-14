#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<string> v;
    string name,dname;
    int choice;
    while (true)
    {
        cout<<"\nEnter 1 for entering name\nEnter2 for deleting name\nEnter 3 for displaying names\nEnter 4 for exiting \n";
        cin>>choice;
        if (choice==1)
        {
            cout<<"Enter name";
            cin>>name;
            v.push_back(name);
        }
        else if (choice==2)
        {
            cout<<"Enter name u want to delete";
            cin>>dname;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i]==dname)
                {
                    cout<<dname<<"found at position"<<i+1<<"\n";
                    v.erase(v.begin()+i);
                    cout<<dname<<"\nDeleted successfully\n";
                }
                else{
                    cout<<dname<<"not found \n";
                    break;
                }
            }
        }
        else if (choice==3){
            for(string x:v){
                cout<<x<<"\n";
            }
        }
        else{
            cout<<"Exiting the loop...";
            break;
        }
        
    }
    
}