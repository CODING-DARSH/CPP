#include<iostream>
using namespace std;
class Shape{
    public:
    int x;
    // void area(){    //here area function is called with no return type no parameters
    //     cout<<"\n are function called....";
    // }

    // int area1(){    //here area function is called with return type and no parameters
    //     cout<<"\n are function called...."  ;
    //     return 100; // return type here is integer
    // }
    Shape area(){       //Shape is class and area is here function name 
        cout<<"Area function is called";
        Shape s1;   // class ,,object
        s1.x=1000;     //class.variable==some value
        return s1;  // as we return integer in int here we return object in class
    }

};
int main(){ 
    Shape s;    //class,object
    s.x=100;    //object.variable value assigned for that object for that global/instance variable
    cout<<"\n x="<<s.x; // it will print 100
    // int x=s.area();  //here  the  return type mismatch here we are assigning value to an int while we are returning object
    Shape s2=s.area();  // here we are assigning object to call the function with object
    cout<<"\n s2.x = "<<s2.x; // here it will return 1000 becoz we are returning s1 in the function and value of x in this function is 1000
}