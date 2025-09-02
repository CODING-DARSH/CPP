#include<iostream>
using namespace std;
class User{
    public:
    int age;    //it is instance variable
    User(){
        cout<<"Default constructor is called";
        this->age=25;
        cout<<"Users age is"<<age;
        }
    User(int salary){
        this->age=26;
        cout<<"\nSalary of user is "<<salary;
        cout<<"\nuser age is "<<age;
    }
    User(char name[20],int newage){
        this->age=newage;
        cout<<"\nuser name is "<<name<<"\n User age is "<<age;
    }
      void getAge(){
            cout<<"\n age = "<<this->age;
        }
};
int main(){
    User u;
    User u1(2000);
    User u2("Darsh",30);
    u1.getAge();
}

// Here mulitple constructors are made with different task and different datatypes