#include<iostream>
using namespace std;
class product{
    public:
    string name;
    int quantity;
    int price;
    product(string n="",int q=0,int p=0){
        this->name=n;   //this all will assign value to its respective variable as we have passed data below
        this->quantity=q;
        this->price=p;
    }
    product operator+(const product &p){
        product pro;
        pro.name=name;
        pro.quantity=quantity+p.quantity;
        pro.price=price;
        return pro;
    }
    void display(){
        cout<<"Product name "<<name;
        cout<<"\nProduct price "<<price;
        cout<<"\nproduct quantity "<<quantity;
    }
};
int main(){
    product Product("Rice",10,3000);
    product Product1("Rice",20,4000);
    product total=Product+Product1;
    total.display();
}