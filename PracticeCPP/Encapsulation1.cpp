#include<iostream>
#include<string>
using namespace std;
class Student{
    public:
    int rno,std;
    string name;
    Student(int rno,int std,string name){
        this->name=name;
        this->rno=rno;
        this->std=std;
    }
};
int main(){
    int rno=0,std=0;
    string name;
    cout<<"Enter name of student rno and std ";
    cin>>name;
    cout<<"Enter rno and std";
    cin>>std>>rno;
    Student s(rno,std,name);

    cout<<s.name<<" "<<s.rno<<" c"<<s.std;

}