#include<iostream>
using namespace std;
template <typename T>
class person{
    public:
    T add(T a, T b){
        return a+b;
    }
};  
int main(){
    person <int>p;
    cout<<p.add(10,20);
    person <string>p1;
    cout<<p1.add("Darsh","vithlai");
}