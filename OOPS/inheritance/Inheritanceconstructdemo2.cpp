//Parameterized constructor

#include<iostream>
using namespace std;

class User{
    public:
    User(int age){
        cout<<"User class parameterized constructor is called\n";
        cout<<"Age is "<<age;
    }
};
class Employee:public User{
    public:
    Employee(char name[10]):User(20){
        cout<<"\nEmployee class parameterized constructor is called\n";
        cout<<"Name "<<name;
    }
};
int main(){
    Employee e("Darsh");
}