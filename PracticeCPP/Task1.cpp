#include <iostream>
#include <string>
#include <vector>
using namespace std;

class person
{
protected:
    int id;
    string name;

private:
    string password;

public:
    person(int id, string name, string password)
    {
        this->id = id;
        this->name = name;
        this->password = password;
    }
    bool login(const string &pw)
    {
        return pw == password;
    }
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    virtual void showDetails() const = 0;
    virtual void performRole() const = 0;
};
class student : public person
{
    vector<string> course;
    string grades;

public:
    student(int id, string name, string password, string grades) : person(id, name, password)
    {
        this->grades = grades;
    }
    void enrollcourse(const string &c)
    {
        course.push_back(c);
    }
    void showDetails() const override
    {
        cout << "student id " << id << "\n"
             << "name : " << name << "\n"
             << "course :";
        for (auto &c : course)
            cout << c << " ";
        cout << "\n"
             << "grades " << grades;
    }
    void performRole() const override
    {
        cout << "\n"
             << "Student role";
    }
};
class Teacher : public person
{
    vector<string> subjects;

public:
    Teacher(int id, string name, string password)
        : person(id, name, password)
    {
    }
    void addSubject(const string &sub)
    {
        subjects.push_back(sub);
    }
    void showDetails() const override
    {
        cout << "\n"
             << "Teacher ID: " << id << "\n"
             << "Name: " << name << "\n"
             << "Subjects: ";
        for (auto &s : subjects)
            cout << s << " ";
        cout << "\n";
    }
    void performRole() const override
    {
        cout << "Teacher role";
    }
};
int main()
{
    student s(1, "Darsh", "pass123", "A");
    s.enrollcourse("Maths");
    s.enrollcourse("English");
    s.showDetails();
    s.getId();
    s.getName();
    s.performRole();
    cout << "\n"
         << "--------Teacher--------";
    Teacher t(1, "Rekha", "pass321");
    t.addSubject("Maths");
    t.addSubject("English");
    t.showDetails();
    t.performRole();
}