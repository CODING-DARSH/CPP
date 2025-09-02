// create a class named Product 
// declare data members:
// id, name, price, quantity
// int  char  float  int
// if user is insrting price or quantity in negative then display error message
// get data from user in main function
// and after that display the data in main function
#include<iostream>
using namespace std;
class Product{
    public:
    int id,quantity;
    float price;
    char name[50];
};
int main(){
    Product p;
    cout<<"Enter Id of product:";
    cin>>p.id;
    cout<<"Enter Name of product:";
    cin>>p.name;
    cout<<"Enter Price of product";
    cin>>p.price;
    cout<<"Enter Quantity of product";
    cin>>p.quantity;
    cout<<"Id number of product="<<p.id<<"\n";
    cout<<"Name of product="<<p.name<<"\n";
    if (p.price<0)
    {
        cout<<"Invalid price"<<"\n";
    }
    else{
        cout<<"Price of product ="<<p.price<<"\n";
    }
    if (p.quantity<0)
    {
        cout<<"Invalid quantity"<<"\n";
    }
    else{
        cout<<"Quantity of product="<<p.quantity;
    }
    
    
}