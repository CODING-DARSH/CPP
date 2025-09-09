#include<iostream>
#include<string>
using namespace std;

class Account {
public:
    virtual int deposit(int amount) = 0;   // pure virtual
    virtual int withdraw(int amount) = 0;  // pure virtual
};

class Person {
public:
    string name;
    int id;
    Person(string name, int id) {
        this->name = name;
        this->id = id;
    }
    void displayNames() {
        cout << "Name of person is " << name << ", Id of person is " << id << endl;
    }
    virtual void showRole() {
        cout << "I am person" << endl;
    }
};

class Customer : public Person, public Account {
private:
    int balance;
public:
    Customer(string name, int i, int initial_balance) : Person(name, i) {
        balance = initial_balance;
    }
    int deposit(int amount) {
        cout << "Enter amount you want to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "You have deposited " << amount << ". Balance = " << balance << endl;
        return balance;
    }
    int withdraw(int amount) {
        cout << "Enter the amount you want to withdraw: ";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient balance" << endl;
        } else {
            balance -= amount;
            cout << "Balance after withdrawal is " << balance << endl;
        }
        return balance;
    }
    friend int checkBalance(Customer c);
    int operator+(Customer c) {
        return this->balance + c.balance;
    }
    void showRole() {
        cout << "Can deposit and withdraw money" << endl;
    }
};

int checkBalance(Customer c) {
    return c.balance;
}

class Employee : public Person {
public:
    string role;
    Employee(string name, int id) : Person(name, id) {
    }
    void showRole() {
        cout << "Manages customer accounts" << endl;
    }
};

int main() {
    string cname, ename, cname1;
    int cid, eid, cid1;
    int intialbalance = 0, intialbalance1 = 0;
    Person* p;

    cout << "Enter employee name ";
    cin >> ename;
    cout << "Enter employee id ";
    cin >> eid;
    Employee e1(ename, eid);

    p = &e1;
    p->displayNames();
    p->showRole();


    cout << "Enter customer name ";
    cin >> cname;
    cout << "Enter customer id ";
    cin >> cid;
    cout << "Enter customer initial balance ";
    cin >> intialbalance;
    Customer c1(cname, cid, intialbalance);

    // Employee
    

    p = &c1;
    p->displayNames();
    p->showRole();

    c1.deposit(0); 
    c1.withdraw(0);  

    cout << "-----------------" << endl;
    
    cout << "Enter second customer name ";
    cin >> cname1;
    cout << "Enter customer id ";
    cin >> cid1;
    cout << "Enter customer initial balance ";
    cin >> intialbalance1;
    Customer c2(cname1, cid1, intialbalance1);

    int total = c1 + c2; // operator overloading
    cout<<"Adding balance of "<<c1.name<<" and "<<c2.name<<endl;
    cout << "Total Balance = " << total << endl;

    return 0;
}
