
#include<iostream>
// #include<string>
using namespace std;

class Car;
class driver{
    int charges;
    public:
    driver(int charges){
        this->charges=charges;
    }

    friend int calculateWages(Car,driver);

};

class Car{

    string CarType;
    int km;
    public:
    Car(int km){
        this->km=km;
    }
    friend int calculateWages(Car,driver);

};

int calculateWages(Car c,driver d){

    return c.km * d.charges;
}
int main(){

    Car c1(15);
    driver d1(100);
    int wages = calculateWages(c1,d1);
    cout<<"\n salary = "<<wages;

}
