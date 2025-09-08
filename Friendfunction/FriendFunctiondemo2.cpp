
#include<iostream>
using namespace std;

class Student;
class User{

    int userAge;
    public:
    User(int age){
        this->userAge = age;
    }

    friend int calulateSalary(User,Student);

};

class Student{

    int marks;
    public:
    Student(int marks){
        this->marks = marks;
    }
    friend int calulateSalary(User,Student);

};

int calulateSalary(User u,Student s){

    return u.userAge * s.marks;
}



int main(){

    User u1(25);
    Student s1(80);
    int salary = calulateSalary(u1,s1);
    cout<<"\n salary = "<<salary;

}
