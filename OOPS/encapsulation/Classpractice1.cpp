// get data from user in main function
// and after that display the data in main function
// create 4 functions in class named :
// add,sub,mul,div 
// eg int add (no1,no2){

//         return no1 + no2;
// }
// main(){
//     //menu using switvvch case
//     enter 1 for add... 2...3...4..
//     switch(choice){
//         case 1:
//             calc.add(100,20);
//         break;
//     }
// }
#include<iostream>
using namespace std;
class calculator{

    public:
    int add(int no1,int no2){
        return no1+no2;
    }
    int sub(int no1,int no2){
        return no1-no2;
    }
    int mul(int no1,int no2){
        return no1*no2;
    }
    int div(int no1,int no2);
};
int calculator::div(int no1,int no2){
    return no1%no2;
}
int main(){
    int no1,no2,choice,ans;
    cout<<"Enter the value of no1 and no2:";
    cin>>no1>>no2;
    cout<<"Enter the choice:";
    cin>>choice;
    calculator calc;
    switch (choice)
    {
    case 1:
        ans=calc.add(no1,no2);
        cout<<ans;
        break;
    case 2:
        ans=calc.sub(no1,no2);
        cout<<ans;
    case 3:
        ans=calc.mul(no1,no2);
        cout<<ans;
    case 4:
        ans=calc.div(no1,no2);
        cout<<ans;
    default:
        cout<<"Enter the valid input between 1 and 4";
        break;
    }
}
