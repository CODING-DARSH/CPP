#include<iostream>
using namespace std;
class India{
    public:
    float Tax=10.0f;
    int population=1400000000;
    void pride(){
        cout<<"I am proud to be indian\n";
    }
};
class Gujarat{
    public:
    int population=60000000;
    int grant=10000;
    void pride(){
        cout<<"I am proud to be gujarati\n";
    }
};
class Ahemdabad:public India,public Gujarat{
    public:
    int population = 8000000;
    void display(){
    cout<<"\nTax which is imposed by india "<<Tax;  //unambiguous means only india has Tax so
    cout<<"\nGrant given by gujarat "<<grant;
    cout<<"populatoin  "<<population << endl;
    cout<<"population of India : "<<India::population << endl;
    cout<<"population of Gujarat : "<<Gujarat::population << endl;
    }
};
int main(){
    Ahemdabad a;
    a.display();
    // a.pride(); // Calls the pride function from India class
    // scope resolution operator to call pride from Gujarat class
    a.India::pride(); // Calls the pride function from India class
    a.Gujarat::pride(); // Calls the pride function from Gujarat class

    cout<<"ahmedabad population : "<<a.population<<endl;
    cout<<"population of India : "<<a.India::population<<endl;
    cout<<"population of Gujarat : "<<a.Gujarat::population<<endl;
}

//Unambigious means it exist only once in this code means like tax 
//Ambgious means it exist more then once in this code which means like pride and population it need scope resolution to point out the exact variable






