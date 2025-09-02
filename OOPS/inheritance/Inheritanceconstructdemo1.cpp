#include<iostream>
using namespace std;
class India {
    public:
    // int x=100;
    India(){
        cout<<"India class default constructor is called";
    }
};
class Gujarat:public India{
    public:
    Gujarat(){
        cout<<"\nDefault constructor of Gujarat is called";
    }
};
int main(){
Gujarat g;

}