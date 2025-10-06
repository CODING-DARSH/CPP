#include<iostream>
using namespace std;
class Balance{

    public:
    int bal;    //bal is global variable
    Balance(int bal){       // parameterized constructor
        this->bal=bal;  //first bal= the upper declared global variable and right one is local declared variable
    }
    bool operator ==(const Balance &b){     // const Balance variable and &b is address of b which is used for calling 2nd value of object here it is used for calling b2 
        cout<<"\n operator is called";
        return bal==b.bal;     //1000==1000--->1(returns)
    }
};
int main(){
    Balance b1(1000);
    Balance b2(2000);
    if (b1==b2){    //b1==b2 is used for calling fucntion
        cout<<"\nBoth have same balance";
    }
    else{
        cout<<"\nBalance aren't equal";
    }
}