#include<iostream>
using namespace std;

class parent{
    public:
    int amount=10;
    void display(){
        cout<<"Display function is callled"<<endl;
    }
};
class child: public parent{
    public:
     void show(){
        cout<<"Child function is called"<<endl;
        cout<<"Amount variable accessed from parent:"<<amount<<endl;
    }
    void displayparent(){
        display();
    }
};
int main(){
    child c;
    c.show();
    // c.display(); we can call parent function using child object but we cant call child function using parent object
    // parent p;
    // p.show();will display error as there is no function like this inside it
    c.displayparent();
}