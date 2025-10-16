#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Student{
    public:
    string name;
    int age;
    int rollno;
        Student(int age,int rollno,string name){
            this->age=age;
            this->name=name;
            this->rollno=rollno;
        }   
};
int main(){
    vector<Student> s;
    string dname;
    Student s1(18,1,"Darsh");
    Student s2(19,2,"Harsh");
    Student s3(19,3,"Yash");
    s.push_back(s1);
    s.push_back(s2);
    s.push_back(s3);
    for(Student stu:s){
            cout<<"Name of student "<<stu.name<<"\n";
            cout<<"age of student "<<stu.age<<"\n";
            cout<<"Roll no of student"<<stu.rollno<<"\n";
            cout<<"---------------------------------"<<"\n";
    }
    s.push_back(Student(21,4,"Darsh")); ///this is second way of pushing whole object in vector where we are implementing class inside breacket

    //in upper data we creare object of that data and then we push that object inside the vector
    cout<<"Enter name u want to delete"<<"\n";
    cin>>dname;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i].name==dname)
        {
            s.erase(s.begin()+i);
            cout<<dname<<"deleted successfully";
            // break;
        }
        
    }
        for(Student stu:s){
            cout<<"Name of student "<<stu.name<<"\n";
            cout<<"age of student "<<stu.age<<"\n";
            cout<<"Roll no of student"<<stu.rollno<<"\n";
            cout<<"---------------------------------"<<"\n";
    }
    
}