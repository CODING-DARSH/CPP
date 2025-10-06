#include <iostream>
#include <string>
using namespace std;
class person
{
public:
    int age;
    string name;
    person(int age, string name)
    {
        this->age = age;
        this->name = name;
    }
    virtual void showDetails()
    {
        cout << "\n"
             << "age is " << age << "\n"
             << "name is " << name << "\n";
    }
};
class student : public person
{
public:
    int rollno;
    string course;
    student(int age, string name, int rno, string course) : person(age, name)
    { // here u hve to write all parent varibales to inside the child class
        this->rollno = rno;
        this->course = course;
    }
    void showDetails() override
    {
        person::showDetails();
        cout << "rollno " << rollno << "\n"
             << "course is " << course << "\n";
    }
};
class GraduateStudent : public student
{
public:
    string researchtopic, advisorName;
    GraduateStudent(int age, string name, int rno, string course, string researchtopic, string advisorName) : student(age, name, rno, course)
    {
        this->advisorName = advisorName;
        this->researchtopic = researchtopic;
    }
    void showDetails() override
    {
        student::showDetails();
        cout << "advisorName :" << advisorName << "\n"
             << "research topic: " << researchtopic;
    }
};
int main()
{
    int rollno, age;
    string course, researchtopic, advisorName, name;
    cout << "Enter rollnu:";
    cin >> rollno;
    cout << "Enter age";
    cin >> age;
    cout << "Enter course:";
    cin >> course;
    cout << "Enter researchtopic:";
    cin >> researchtopic;
    cout << "Enter advisorName:";
    cin >> advisorName;
    cout << "Enter name of student:";
    cin >> name;
    GraduateStudent grad(age, name, rollno, course, researchtopic, advisorName);
    // grad.showDetails();
    cout << "-------------Details-------------";
    person *p = &grad;
    p->showDetails();
}