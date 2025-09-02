#include<iostream>
using namespace std;
class Bank{
    
    public:
    float balance=0;
    void wihdraw(float amount){
        if (amount>balance)
        {
            cout<<"Inusufficent amount";
        }
        else{
            balance=balance-amount;
            cout<<"\nWithdraw done successfully";
            cout<<"Total balance="<<balance;
        }
    }
    void deposit(float amount);
};
void Bank::deposit(float amount){
    balance=balance+amount;
      cout<<"\n deposit process is successfully done !!";
        cout<<"\n after deposit balance  = "<<balance;
}
int main(){
    Bank bank;
    bank.deposit(1000);
    bank.deposit(150);
}