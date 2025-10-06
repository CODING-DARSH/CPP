#include <iostream>
using namespace std;
class Counter
{
public:
    int value; // this is instance of variable instance means if there is another object and in that object if a value  is declared then value of that object will only be changed for other variables it wont affect

    Counter(int v)
    { // parameterized constructor is created which means constructor with value inside
        // both type of constructor parameterized and default both constructor can be used in overloading
        this->value = v;
    }
    // this is prefix operator
    // prefix means ++a
    void operator++()
    {
        cout << "Prefix Operator overloading function is called ";
        this->value = ++value;
    }
    // this is postfix operator in this int parameter should be passed compulsary
    // a++
    void operator++(int)
    {
        cout << "\n Postfix operator overloading  is called";
        this->value = value++;
    }

    void operator--()
    {
        cout << "\n prefix decrement overloading is called";
    }
    void display()
    {
        cout << "\n value of value = " << this->value; // 101
    }
};

int main()
{
    Counter c1(100); // as we have given value in constructor we have to pass value here in object
    ++c1;            // prefix overloading operator is called
    c1++;            // suffix overloading operator is called
    --c1;
    c1.display();
}