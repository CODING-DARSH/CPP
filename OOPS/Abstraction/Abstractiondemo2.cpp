#include<iostream>
using namespace std;
class facebook{
    public:
    virtual void smile_function()=0;
};
class ABC:public facebook{
    public:
    void smile_function(){
        cout<<"-^- smiley is calles";
    }
};
class EFG:public facebook{
    public:
    void smile_function(){
        cout<<"\n-~- smiley function is called";
    }
};
int main(){
    facebook *f;
    ABC a;
    EFG b;
    f=&a;
    f->smile_function();
    f=&b;
    f->smile_function();
}