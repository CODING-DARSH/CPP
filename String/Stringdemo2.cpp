#include<iostream>
#include<string>

using namespace std;

int main(){

    // +

    string fname= "samir";
    string lname = "vithlani";

    string fullname = fname+" "+lname;
    cout<<"\n full name = "<<fullname;

    string course = "javaaaaaa";
    string coffee = "javaaa";

    //!=
    //x<=java
    if(course <= coffee){
        cout<<"\n you can drink coffee while learing java";
    }
    else{
        cout<<"\n go to python";
    }

    //substr function...
    string add = "ahmedabad 201, surbhi complex, cg road ahmedabad";
    string x = add.substr(0,6); // last will excl..
    cout<<"\n x = "<<x;

    cout<<"\n find..."<<add.find("ahmedabad");
    cout<<"\n Rfind..."<<add.rfind("ahmedabad");

    //number  == ->0
    //    diff
    //  -diff
    int x1 = coffee.compare(course);
    cout<<"\n x1 = "<<x1;
    
        
    

}