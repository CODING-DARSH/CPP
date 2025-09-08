
#include<iostream>
using namespace std;

class Box{

     
    int length;

    public:
    Box(int l){
        this->length = l;
    }

    friend void printBox(Box b); //dont create body

};

//no scope resolution
void printBox(Box b){

    cout<<"\n lenght of box = "<<b.length;
}


int main(){

    Box b1(15);
    //b1.printBox(b1)
    printBox(b1);
}
