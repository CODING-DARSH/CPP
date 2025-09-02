#include<iostream>
using namespace std;
class User{
    public:
    int age;
    User(int age){
        this->age=age;
    }
    bool operator&&(const User &u){
        return age==u.age;
    }
    void show(){
        
    }
};
int main(){
    User user(20);
    User user1(20);
    if (user && user1)
    {
        cout<<"Age is equal";
    }
    else{
        cout<<"User dosen't have equal age";
    }
    
}