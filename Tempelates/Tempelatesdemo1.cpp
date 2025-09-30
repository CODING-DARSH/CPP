#include<iostream>
#include<string>
using namespace std;

// void test(int a){

//     cout<<"\n value of a = "<<a;
// }

template <typename T>
void test(T a){
    cout<<"\n value of a ="<<a;
}

template <typename T>
T add(T a,T b){

    return a + b; //"char array" "char array"
}
int main(){

    test(100);
    test("java");
    test(true);

    /////
    string s="cpp";
    string s1 = " prog";
    cout<<"\n value of add "<<add(10,20);
    //cout<<"\n value of add "<<add("cpp ","programming");
    cout<<"\n value of add "<<add(s,s1);

    //int x = add(100,200);
    auto x = add(100,200);
    cout<<"\n value of x "<<x;

    string fname ="Darsh";
    string lname = " Vithlani";
    
    auto fullName = add(fname,lname);
    cout<<"\n full name = "<<fullName;

    //Note
    //T data int
    // cout<<"\n error"<<add(10,fname);

}