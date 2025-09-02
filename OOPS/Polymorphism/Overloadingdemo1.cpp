#include<iostream>
using namespace std;
class shapes{
    public:
    float pi=3.14;
    void getArea(){
        cout<<"Simple void function is called";
    }
    void getArea(float r){
        float area=pi*(r*r);
        cout<<"\nArea of circle is "<<area;
    }
    void getArea(int h,int w){
        int area=0.5*(h*w);
        cout<<"\nArea of triangle is "<<area;
    }
};
int main(){
    shapes s;
    s.getArea();
    s.getArea(3);
    s.getArea(3,4);
}

// Polymorphism is nothing but reusing a same function multiple times with multiple new datatypes and usage
// In terms of operators--->other than performing tasks for 2 operands they are used as function calling