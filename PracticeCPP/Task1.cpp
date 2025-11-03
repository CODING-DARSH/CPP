// #include <iostream>
// #include <string>
// #include <vector>
// #include <cctype>
// #include <limits>
// #include <fstream>
// #include <sstream>
// using namespace std;

// class person
// {
// protected:
//     int id;
//     string name;
//     string password; // Changed from private to protected for child access

// public:
//     person(int id, string name, string password)
//     {
//         this->id = id;
//         this->name = name;
//         this->password = password;
//     }
//     bool login(const string &pw)
//     {
//         return pw == password;
//     }
//     int getId() const
//     {
//         return id;
//     }
//     string getName() const
//     {
//         return name;
//     }
//     void setId(int newId)
//     {
//         id = newId;
//     }
//     void setName(const string &newName)
//     {
//         name = newName;
//     }
//     bool changePassword(const string &oldpassword, const string &newpass)
//     {
//         if (oldpassword == password)
//         {
//             password = newpass;
//             return true;
//         }
//         return false;
//     }
//     static bool isValidPassword(const string &password)
//     {
//         if (password.length() < 6)
//         {
//             return false;
//         }
//         bool hasUpper = false, hasLower = false, hasDigit = false;
//         for (char ch : password)
//         {
//             if (isupper(ch))
//             {
//                 hasUpper = true;
//             }
//             else if (islower(ch))
//             {
//                 hasLower = true;
//             }
//             else if (isdigit(ch))
//             {
//                 hasDigit = true;
//             }
//         }
//         return hasUpper && hasLower && hasDigit;
//     }

//     const string &getPassword() const { return password; } // Getter added

//     virtual void showDetails() const = 0;
//     virtual void performRole() const = 0;
// };

// class student : public person
// {
//     vector<string> course;
//     string grades = "";
//     static int nextId;

// public:
//     student(string name, string password) : person(nextId++, name, password)
//     {
//         // grades is default empty
//     }
//     void enrollcourse(const string &c)
//     {
//         course.push_back(c);
//     }
//     void showDetails() const override
//     {
//         cout << "Student ID: " << id << "\n"
//              << "Name: " << name << "\n"
//              << "Courses: ";
//         for (auto &c : course)
//             cout << c << " ";
//         cout << "\nGrades: " << grades << "\n";
//     }
//     void performRole() const override
//     {
//         cout << "Student role\n";
//     }
//     void assignGrade(const string &g)
//     {
//         grades = g;
//     }

//     // Getter and Setter for file handling
//     const vector<string> &getCourses() const { return course; }
//     void setCourses(const vector<string> &courses) { course = courses; }

//     const string &getGrades() const { return grades; }
//     void setGrades(const string &g) { grades = g; }
// };
// int student::nextId = 1;

// class Teacher : public person
// {
//     vector<string> subjects;
//     static int nextId;

// public:
//     Teacher(string name, string password)
//         : person(nextId++, name, password)
//     {
//     }
//     void addSubject(const string &sub)
//     {
//         subjects.push_back(sub);
//     }
//     void showDetails() const override
//     {
//         cout << "Teacher ID: " << id << "\n"
//              << "Name: " << name << "\n"
//              << "Subjects: ";
//         for (auto &s : subjects)
//             cout << s << " ";
//         cout << "\n";
//     }
//     void performRole() const override
//     {
//         cout << "Teacher role\n";
//     }
//     void assignGrade(student &s, const string &g)
//     {
//         s.assignGrade(g);
//     }
//     const vector<string> &getSubjects() const { return subjects; }
//     void setSubjects(const vector<string> &subs) { subjects = subs; }
// };
// int Teacher::nextId = 1;

// template <typename T>
// int findById(const vector<T> &list, int id)
// {
//     for (size_t i = 0; i < list.size(); ++i)
//         if (list[i].getId() == id)
//             return static_cast<int>(i);
//     return -1;
// }

// void studentLogin(vector<student> &students)
// {
//     int id;
//     string password;
//     cout << "Enter student id: ";
//     cin >> id;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');

//     int index = findById(students, id);
//     if (index == -1)
//     {
//         cout << "Student not found\n";
//         return;
//     }

//     cout << "Enter password: ";
//     getline(cin, password);

//     if (students[index].login(password))
//     {
//         cout << "\nWelcome, " << students[index].getName() << "!\n";
//         int choice = 0;
//         while (true)
//         {
//             cout << "\n1. Enroll Course\n2. Show Details\n3. Change Password\n4. Logout\nChoice: ";
//             cin >> choice;
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');

//             if (choice == 1)
//             {
//                 string courseName;
//                 cout << "Enter the course name: ";
//                 getline(cin, courseName);
//                 students[index].enrollcourse(courseName);
//                 cout << "Course enrolled successfully!\n";
//             }
//             else if (choice == 2)
//             {
//                 students[index].showDetails();
//             }
//             else if (choice == 3)
//             {
//                 string oldpass, newpass;
//                 cout << "Enter old password: ";
//                 getline(cin, oldpass);
//                 cout << "Enter new password: ";
//                 getline(cin, newpass);
//                 if (students[index].changePassword(oldpass, newpass))
//                 {
//                     cout << "Password changed successfully\n";
//                 }
//                 else
//                 {
//                     cout << "Incorrect old password\n";
//                 }
//             }
//             else if (choice == 4)
//             {
//                 cout << "Logging out...\n";
//                 break;
//             }
//             else
//                 cout << "Invalid option!\n";
//         }
//     }
//     else
//     {
//         cout << "Wrong password!\n";
//     }
// }

// void teacherLogin(vector<Teacher> &teachers, vector<student> &students)
// {
//     int id;
//     string password;
//     cout << "Enter id for teacher: ";
//     cin >> id;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');

//     cout << "Enter password: ";
//     getline(cin, password);

//     int index = findById(teachers, id);
//     if (index == -1)
//     {
//         cout << "Teacher not found\n";
//         return;
//     }

//     if (teachers[index].login(password))
//     {
//         cout << "\nWelcome, " << teachers[index].getName() << "!\n";
//         int choice = 0;
//         while (true)
//         {
//             cout << "\n1. Add subjects\n2. Show Details\n3. Assign Grade\n4. Change Password\n5. Logout\nChoice: ";
//             cin >> choice;
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');

//             if (choice == 1)
//             {
//                 string subjectName;
//                 cout << "Enter subject you teach: ";
//                 getline(cin, subjectName);
//                 teachers[index].addSubject(subjectName);
//                 cout << subjectName << " added successfully\n";
//             }
//             else if (choice == 2)
//             {
//                 teachers[index].showDetails();
//             }
//             else if (choice == 3)
//             {
//                 int studentId;
//                 string grade;
//                 cout << "Enter student ID: ";
//                 cin >> studentId;
//                 cin.ignore(numeric_limits<streamsize>::max(), '\n');

//                 int idx = findById(students, studentId);
//                 if (idx == -1)
//                 {
//                     cout << "Student not found\n";
//                 }
//                 else
//                 {
//                     cout << "Enter grade to assign: ";
//                     getline(cin, grade);
//                     teachers[index].assignGrade(students[idx], grade);
//                     cout << "Grade assigned successfully!\n";
//                 }
//             }
//             else if (choice == 4)
//             {
//                 string oldpass, newpass;
//                 cout << "Enter old password: ";
//                 getline(cin, oldpass);
//                 cout << "Enter new password: ";
//                 getline(cin, newpass);
//                 if (teachers[index].changePassword(oldpass, newpass))
//                 {
//                     cout << "Password changed successfully\n";
//                 }
//                 else
//                 {
//                     cout << "Incorrect old password\n";
//                 }
//             }
//             else if (choice == 5)
//             {
//                 cout << "Logging out...\n";
//                 break;
//             }
//             else
//             {
//                 cout << "Invalid choice\n";
//             }
//         }
//     }
//     else
//     {
//         cout << "Wrong password!\n";
//     }
// }

// void studentRegisteration(vector<student> &students)
// {
//     string name, password;
//     cout << "Enter name: ";
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     getline(cin, name);

//     while (true)
//     {
//         cout << "Enter password (must contain uppercase, lowercase, and a digit): ";
//         getline(cin, password);

//         if (person::isValidPassword(password))
//         {
//             break;
//         }
//         else
//         {
//             cout << "Invalid password. Try again.\n";
//         }
//     }

//     students.push_back(student(name, password));
//     cout << "Registration successful! Your student ID is: " << students.back().getId() << "\n";
// }

// void teacherRegisteration(vector<Teacher> &teachers)
// {
//     string name, password;
//     cout << "Enter teacher name: ";
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     getline(cin, name);

//     while (true)
//     {
//         cout << "Enter password (must contain uppercase, lowercase, and a digit): ";
//         getline(cin, password);

//         if (person::isValidPassword(password))
//         {
//             break;
//         }
//         else
//         {
//             cout << "Invalid password. Try again.\n";
//         }
//     }

//     teachers.push_back(Teacher(name, password));
//     cout << "Registration successful! Your teacher ID is: " << teachers.back().getId() << "\n";
// }

// void saveStudentsToFile(const vector<student> &students, const string &filename)
// {
//     ofstream ofs(filename);
//     if (!ofs)
//     {
//         cerr << "Error opening file for saving students.\n";
//         return;
//     }
//     for (const auto &s : students)
//     {
//         ofs << s.getId() << "," << s.getName() << "," << s.getPassword() << ",";

//         const auto &courses = s.getCourses();
//         for (size_t i = 0; i < courses.size(); ++i)
//         {
//             ofs << courses[i];
//             if (i < courses.size() - 1)
//                 ofs << "|";
//         }
//         ofs << ",";

//         const auto &grades = s.getGrades();
//         ofs << grades << "\n";
//     }
// }

// void loadStudentsFromFile(vector<student> &students, const string &filename)
// {
//     ifstream ifs(filename);
//     if (!ifs)
//     {
//         // No file found, or error reading; silently continue with empty list
//         return;
//     }
//     string line;

//     while (getline(ifs, line))
//     {
//         stringstream ss(line);
//         string token;

//         int id;
//         string name, password, coursesStr, gradesStr;

//         getline(ss, token, ',');
//         id = stoi(token);
//         getline(ss, name, ',');
//         getline(ss, password, ',');
//         getline(ss, coursesStr, ',');
//         getline(ss, gradesStr);

//         vector<string> courses;
//         stringstream cs(coursesStr);
//         while (getline(cs, token, '|'))
//             courses.push_back(token);

//         student s(name, password);
//         s.setId(id);
//         s.setCourses(courses);
//         s.setGrades(gradesStr);

//         students.push_back(s);
//     }
// }
// void saveTeachersToFile(const vector<Teacher> &teachers, const string &filename)
// {
//     ofstream ofs(filename);
//     if (!ofs)
//     {
//         cerr << "Error opening file for saving teachers.\n";
//         return;
//     }
//     for (const auto &t : teachers)
//     {
//         ofs << t.getId() << "," << t.getName() << "," << t.getPassword() << ",";
//         // Save subjects separated by '|'
//         const auto &subjects = t.getSubjects();
//         for (size_t i = 0; i < subjects.size(); ++i)
//         {
//             ofs << subjects[i];
//             if (i < subjects.size() - 1)
//                 ofs << "|";
//         }
//         ofs << "\n";
//     }
// }

// void loadTeachersFromFile(vector<Teacher> &teachers, const string &filename)
// {
//     ifstream ifs(filename);
//     if (!ifs)
//         return; // no file, silently continue

//     string line;

//     while (getline(ifs, line))
//     {
//         stringstream ss(line);
//         string token;

//         int id;
//         string name, password, subjectsStr;

//         getline(ss, token, ',');
//         id = stoi(token);
//         getline(ss, name, ',');
//         getline(ss, password, ',');
//         getline(ss, subjectsStr);

//         vector<string> subjects;
//         stringstream subStream(subjectsStr);
//         while (getline(subStream, token, '|'))
//             subjects.push_back(token);

//         Teacher t(name, password);
//         t.setId(id);
//         t.setSubjects(subjects);

//         teachers.push_back(t);
//     }
// }

// int main()
// {
//     vector<student> students;
//     vector<Teacher> teachers;

//     loadStudentsFromFile(students, "students.txt");
//     loadTeachersFromFile(teachers, "teachers.txt");
//     int choice;
//     while (true)
//     {
//         cout << "\n1. Student Login\n2. Teacher Login\n3. Student Registration\n4. Teacher Registration\n5. Exit\nChoice: ";
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//             studentLogin(students);
//             break;
//         case 2:
//             teacherLogin(teachers, students);
//             break;
//         case 3:
//             studentRegisteration(students);
//             break;
//         case 4:
//             teacherRegisteration(teachers);
//             break;
//         case 5:
//             cout << "Exiting program...\n";
//             saveStudentsToFile(students, "students.txt");
//             saveTeachersToFile(teachers, "teachers.txt");
//             return 0;
//         default:
//             cout << "Invalid choice!\n";
//         }
//     }
// }
