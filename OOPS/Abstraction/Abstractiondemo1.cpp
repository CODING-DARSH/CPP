// Abstraction in programming means showing only the important details and hiding unnecessary implementation details from the user.
#include<iostream>
using namespace std;
class TRAI{
    public:
    // void call(){
        // 
    // }    //here Trai function dosent need body as it head it wont perform any task it is just used for reference
    //therefore here we will use pure virtual function
    virtual void call()=0;
};
class jio:public TRAI{
    public:
    void call(){
        cout<<"Jio is calling";
    }
};
class airtel:public TRAI{
    public:
    void call(){
        cout<<"\nAirtel is calling";
    }
};
int main(){
    TRAI *t;    //pointer or reference of parent object 
    jio j;
    airtel a;
    t=&j;   //object value is assigned with address of childs object
    t->call();  //the child function is called using object of parent as prior we have assigned value of parent object with child object address
    t=&a;
    t->call();
}
//Errors we will have 
//1] we must override parent class function in child class means we must write call function in child class
// 2] we must declare pointer towards parent function as parent function is abstract function as it has virtual function in it

//Note:
//1]We can create as many virtual function we want in parent class but it is must to override them in child class