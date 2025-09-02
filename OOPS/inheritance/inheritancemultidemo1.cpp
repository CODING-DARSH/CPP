#include<iostream>
using namespace std;
class college{
    public:
    int universityfees=100;
    void collegefx(){
        cout<<"College class and function is called";
    }
    
};
class engineering:public college{
    public:
    int engineeringfees=2000;
    void engineeringfx(){
        cout<<"Engineering class and function is called";
        cout<<"University fees from college class in enginerring is :"<<universityfees;
    }
};
class aiml:public engineering{
    public:
    int aimlfees=3000;
    void aimlfx(){
        cout<<"Aiml class and function is called";
        cout<<"University fees from college class in enginerring is :"<<universityfees;
        cout<<"University fees from college class in enginerring is :"<<engineeringfees;
    }
};
int main(){
    aiml ai;
    ai.aimlfx();
    ai.engineeringfx();
    ai.collegefx();
}