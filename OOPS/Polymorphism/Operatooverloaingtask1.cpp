#include <iostream>
using namespace std;
class Bankaccount
{
public:
    int initialbalance;
    int balance;
    Bankaccount(int initialbalance)
    {
        this->initialbalance = initialbalance; // there is mandatory initialbalance in account therefore that that initialbalance will be further equal to current balance of account
        this->balance = initialbalance;
    }
    Bankaccount operator+(int amount)
    {
        cout << "\nDepositing " << amount << " into account";
        Bankaccount bank = balance; // We are creating new object here and assigning old balance value each and everytime becoz balance is changing after every task

        bank.balance += amount; // bank.balance is used for accessing balance variable which is inside bank object

        return bank; // we can also use return *this which will avoid creating new object everytime currently new object is created everytime we call it
    }
    Bankaccount operator-(int amount)
    {
        cout << "\n Withdrawing " << amount << " from account";
        Bankaccount bank1 = balance;
        bank1.balance -= amount;
        return bank1;
    }
    void show()
    {
        cout << "\nCurrent Balance: " << balance;
    }
};
int main()
{
    int choice, withdrawam, deposistam;
    Bankaccount ba(100);

    while (true)
    {
        cout << "\n1. Deposit\n2. Withdraw\n3. Exit\nEnter choice: ";
        cin >> choice;
        cout << "Your current balance in account =" << ba.balance << "\n";
        if (choice == 1)
        {
            cout << "Enter the amount u want to deposit->";
            cin >> deposistam; // it works like ba is object so inside object +operator is called and that +operator requires an argument amount so here that argument is deposistam

            ba = ba + deposistam; // once deposit amount is given the above thing hapens then we go upwards and it works like a bank object is created with old balance then it will add this deposit amount in it and it return object or balance it will return inshort and that balance will be new balance
            ba.show();
        }
        else if (choice == 2)
        {
            cout << "Enter the amount u want to withdraw->";
            cin >> withdrawam;
            if (withdrawam < ba.balance) // if withdraw amount is less then balance amount then and only then it will run this task
            {
                ba = ba - withdrawam;
                ba.show();
            }
            else
            {
                cout << "Insufficient balance";
            }
        }
        else if (choice == 3)
        {
            cout << "\nExiting...";
            break;
        }
    }
}