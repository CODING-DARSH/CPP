#include<iostream>
using namespace std;
class calc{
    public:
    int no1,no2,ans;
};
int main(){
    // object is declared as className objecName
    calc calc;  //u can define same object name and same as class
    cout<<"Enter value of no1";
    cin>>calc.no1;
    cout<<"No1 value ="<<calc.no1;

}