// Overriding means a parent function in a class is there and we are changing and upgrading its properties in another class means 2 different class are there 1 is parent and other is child we will be accessing function inside parent in child we will be using parent function inside child here we cant overide a constructor
#include <iostream>
using namespace std;
class Govt
{
public:
    void paytax()
    {
        cout << "Govt pay tax is accessed";
    }
};
class state : public Govt
{
public:
    void paytax()
    {
        cout << "State paytax is accessed";
        Govt::paytax();
    }
};
int main()
{
    state s;
    s.paytax();
}