#include<iostream>
using namespace std;

class Bank {
protected:
    int Balance;
public:
    Bank(int balance) {   // constructor to initialize Balance
        Balance = balance;
    }

    virtual void displayAccountDetails() = 0; // pure virtual

    void depositAmount(int Amount) {
        Balance += Amount;
        cout << "Deposited: " << Amount << ", New Balance: " << Balance << endl;
    }

    void withdrawAmount(int Amount) {
        if (Balance - Amount >= 0) {
            Balance -= Amount;
            cout << "Withdrawn: " << Amount << ", Remaining Balance: " << Balance << endl;
        } else {
            cout << "Insufficient Balance!" << endl;
        }
    }
};

class SavingsAccount : public Bank {
public:
    SavingsAccount(int balance) : Bank(balance) {} // call base constructor

    void displayAccountDetails() override {
        cout << "Savings Account Balance: " << Balance << endl;
        if (Balance < 500) {
            cout << "Insufficient balance for opening savings account" << endl;
        }
    }
};

int main() {
    Bank *b;
    SavingsAccount s(300); // open with 300
    b = &s;

    b->displayAccountDetails();
    b->depositAmount(400);
    b->withdrawAmount(200);
    b->displayAccountDetails();

    return 0;
}
