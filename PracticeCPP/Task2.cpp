#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <limits>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <ctime>

using namespace std;

// ------------------ UTIL ------------------

string trim(const string &str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

// Forward declarations
class student;
class Teacher;
class Admin;

// ------------------ TEMPLATE FIND ------------------

template <typename T>
int findById(const vector<T> &list, int id) {
    for (size_t i = 0; i < list.size(); ++i)
        if (list[i].getId() == id)
            return static_cast<int>(i);
    return -1;
}

// ------------------ PERSON ------------------

class person {
protected:
    int id;
    string name;
    string password;

public:
    person(int id, string name, string password)
        : id(id), name(std::move(name)), password(std::move(password)) {}

    virtual ~person() = default;  // Added virtual destructor

    bool login(const string &pw) const { return pw == password; }

    int getId() const { return id; }
    string getName() const { return name; }

    void setId(int newId) { id = newId; }
    void setName(const string &newName) { name = newName; }

    bool changePassword(const string &oldpassword, const string &newpass) {
        if (oldpassword == password) {
            password = newpass;
            return true;
        }
        return false;
    }

    static bool isValidPassword(const string &password) {
        if (password.length() < 6) return false;
        bool hasUpper = false, hasLower = false, hasDigit = false;
        for (unsigned char ch : password) {
            if (isupper(ch)) hasUpper = true;
            else if (islower(ch)) hasLower = true;
            else if (isdigit(ch)) hasDigit = true;
        }
        return hasUpper && hasLower && hasDigit;
    }

    const string &getPassword() const { return password; }
    void setPassword(const string &newpass) { password = newpass; } // Added for password reset

    virtual void showDetails() const = 0;
    virtual void performRole() const = 0;
};

// ------------------ STUDENT ------------------

class student : public person {
    vector<string> course;
    string grades = "";
    vector<string> notifications; // Added notifications
    static int nextId;

public:
    student(string name, string password) : person(nextId++, std::move(name), std::move(password)) {}

    void enrollcourse(const string &c) { course.push_back(c); }

    void showDetails() const override {
        cout << "Student ID: " << id << "\n"
             << "Name: " << name << "\nCourses: ";
        for (const auto &c : course) cout << c << " ";
        cout << "\nGrades: " << (grades.empty() ? "No grades assigned" : grades) << "\n";
    }

    void performRole() const override { cout << "Student role\n"; }

    void assignGrade(const string &g) { grades = g; }

    const vector<string> &getCourses() const { return course; }
    void setCourses(const vector<string> &courses) { course = courses; }

    const string &getGrades() const { return grades; }
    void setGrades(const string &g) { grades = g; }

    // Notification functions
    void addNotification(const string &message) {
        notifications.push_back(message);
    }
    
    void showNotifications() const {
        if (notifications.empty()) {
            cout << "No new notifications.\n";
            return;
        }
        cout << "\n----- NOTIFICATIONS -----\n";
        for (size_t i = 0; i < notifications.size(); ++i) {
            cout << i + 1 << ". " << notifications[i] << "\n";
        }
    }

    // Course removal function
    void removeCourse(int courseIndex) {
        if (courseIndex >= 0 && courseIndex < static_cast<int>(course.size())) {
            course.erase(course.begin() + courseIndex);
        }
    }

    static void ensureNextIdAtLeast(int minId) { if (nextId <= minId) nextId = minId + 1; }
};
int student::nextId = 1;

// ------------------ TEACHER ------------------

class Teacher : public person {
    vector<string> subjects;
    static int nextId;

public:
    Teacher(string name, string password) : person(nextId++, std::move(name), std::move(password)) {}

    void addSubject(const string &sub) { subjects.push_back(sub); }

    void showDetails() const override {
        cout << "Teacher ID: " << id << "\n"
             << "Name: " << name << "\nSubjects: ";
        for (const auto &s : subjects) cout << s << " ";
        cout << "\n";
    }

    void performRole() const override { cout << "Teacher role\n"; }

    void assignGrade(student &s, const string &g) { s.assignGrade(g); }

    const vector<string> &getSubjects() const { return subjects; }
    void setSubjects(const vector<string> &subs) { subjects = subs; }

    // Notification broadcast function
    void broadcastToStudents(vector<student> &students, const string &subject, const string &message) {
        int count = 0;
        for (auto &s : students) {
            for (const auto &course : s.getCourses()) {
                if (course == subject) {
                    s.addNotification("[" + subject + "] " + message);
                    count++;
                    break;
                }
            }
        }
        cout << "Notification sent to " << count << " students enrolled in " << subject << "\n";
    }

    static void ensureNextIdAtLeast(int minId) { if (nextId <= minId) nextId = minId + 1; }
};
int Teacher::nextId = 1;

// ------------------ ADMIN ------------------

class Admin {
    string username;
    string password;

public:
    Admin() = default;
    Admin(string u, string p) : username(std::move(u)), password(std::move(p)) {}
    string getUsername() const { return username; }
    string getPassword() const { return password; }

    bool login(const string &pw) const { return pw == password; }

    void showAllStudents(const vector<student> &students) const {
        cout << "\n----- All Students -----\n";
        for (const auto &s : students) {
            s.showDetails();
            cout << "------------------------\n";
        }
    }

    void showAllTeachers(const vector<Teacher> &teachers) const {
        cout << "\n----- All Teachers -----\n";
        for (const auto &t : teachers) {
            t.showDetails();
            cout << "------------------------\n";
        }
    }

    void subjectReport(const vector<student> &students, const string &subject) const {
        cout << "\n----- Subject Report: " << subject << " -----\n";
        int passCount = 0, failCount = 0, noGradeCount = 0;
        int totalEnrolled = 0;

        for (const auto &s : students) {
            bool enrolled = false;
            for (const auto &c : s.getCourses()) {
                if (trim(c) == trim(subject)) {
                    enrolled = true;
                    break;
                }
            }

            if (enrolled) {
                totalEnrolled++;
                string g = trim(s.getGrades());

                // Deep clean the grade string
                g.erase(remove_if(g.begin(), g.end(), [](unsigned char ch) {
                    return ch == '\r' || ch == '\n';
                }), g.end());

                // Remove any extra whitespace
                g = trim(g);

                cout << "Student: " << s.getName() << " | Grade: '" << g << "'";

                if (g.empty()) {
                    cout << " | Status: NO GRADE\n";
                    noGradeCount++;
                    continue;
                }

                // Convert to uppercase for consistent comparison
                string gradeUpper = g;
                transform(gradeUpper.begin(), gradeUpper.end(), gradeUpper.begin(), ::toupper);

                // Enhanced grade checking - handle various grade formats
                if (gradeUpper == "A" || gradeUpper == "A+" || gradeUpper == "A-" || 
                    gradeUpper == "B" || gradeUpper == "B+" || gradeUpper == "B-" ||
                    gradeUpper == "C" || gradeUpper == "C+" || gradeUpper == "C-" ||
                    gradeUpper == "PASS" || gradeUpper == "P") {
                    cout << " | Status: PASS\n";
                    passCount++;
                } 
                else if (gradeUpper == "D" || gradeUpper == "D+" || gradeUpper == "D-" ||
                         gradeUpper == "F" || gradeUpper == "FAIL" || 
                         gradeUpper == "E" || gradeUpper == "0" || gradeUpper == "1" || gradeUpper == "2") {
                    cout << " | Status: FAIL\n";
                    failCount++;
                }
                else {
                    // Try to handle numeric grades
                    try {
                        double numericGrade = stod(gradeUpper);
                        if (numericGrade >= 3.0) {  // Assuming 3.0+ is passing
                            cout << " | Status: PASS\n";
                            passCount++;
                        } else {
                            cout << " | Status: FAIL\n";
                            failCount++;
                        }
                    } catch (const exception&) {
                        // If we can't parse as number, default to FAIL for safety
                        cout << " | Status: FAIL (unrecognized grade format)\n";
                        failCount++;
                    }
                }
            }
        }

        cout << "\n=== REPORT SUMMARY ===\n";
        cout << "Total Enrolled in " << subject << ": " << totalEnrolled << "\n";
        cout << "Passed: " << passCount << "\n";
        cout << "Failed: " << failCount << "\n";
        cout << "No Grade: " << noGradeCount << "\n";
        
        int gradedStudents = passCount + failCount;
        if (gradedStudents > 0) {
            cout << "Pass Rate: " << (passCount * 100.0) / gradedStudents << "%\n";
        } else {
            cout << "Pass Rate: No graded students\n";
        }
        
        if (totalEnrolled == 0) {
            cout << "No students enrolled in this subject!\n";
        }
    }

    // New Admin Functions

    void searchStudent(const vector<student> &students, const string &searchTerm) const {
        cout << "\n----- Search Results for '" << searchTerm << "' -----\n";
        bool found = false;
        for (const auto &s : students) {
            if (s.getName().find(searchTerm) != string::npos || 
                to_string(s.getId()).find(searchTerm) != string::npos) {
                s.showDetails();
                cout << "------------------------\n";
                found = true;
            }
        }
        if (!found) cout << "No students found.\n";
    }

    void searchTeacher(const vector<Teacher> &teachers, const string &searchTerm) const {
        cout << "\n----- Search Results for '" << searchTerm << "' -----\n";
        bool found = false;
        for (const auto &t : teachers) {
            if (t.getName().find(searchTerm) != string::npos || 
                to_string(t.getId()).find(searchTerm) != string::npos) {
                t.showDetails();
                cout << "------------------------\n";
                found = true;
            }
        }
        if (!found) cout << "No teachers found.\n";
    }

    void showStatistics(const vector<student> &students, const vector<Teacher> &teachers) const {
        cout << "\n----- SYSTEM STATISTICS -----\n";
        cout << "Total Students: " << students.size() << "\n";
        cout << "Total Teachers: " << teachers.size() << "\n";
        
        // Course enrollment statistics
        map<string, int> courseEnrollment;
        int studentsWithGrades = 0;
        
        for (const auto &s : students) {
            for (const auto &course : s.getCourses()) {
                courseEnrollment[course]++;
            }
            if (!s.getGrades().empty()) {
                studentsWithGrades++;
            }
        }
        
        cout << "Students with grades assigned: " << studentsWithGrades << "/" << students.size() << "\n";
        cout << "\nCourse Enrollment:\n";
        for (const auto &[course, count] : courseEnrollment) {
            cout << "  " << course << ": " << count << " students\n";
        }
    }

    // Fixed: Remove const from parameters to allow modification
    void resetUserPassword(vector<student> &students, vector<Teacher> &teachers) {
        int id;
        string userType;
        cout << "Enter user type (student/teacher): ";
        cin >> userType;
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        string newPassword = "Temp123"; // Default temporary password
        
        if (userType == "student") {
            int index = findById(students, id);
            if (index != -1) {
                // Directly set password (bypass old password check)
                students[index].setPassword(newPassword);
                cout << "Password reset for student " << students[index].getName() 
                     << ". Temporary password: " << newPassword << "\n";
            } else {
                cout << "Student not found.\n";
            }
        } else if (userType == "teacher") {
            int index = findById(teachers, id);
            if (index != -1) {
                teachers[index].setPassword(newPassword);
                cout << "Password reset for teacher " << teachers[index].getName() 
                     << ". Temporary password: " << newPassword << "\n";
            } else {
                cout << "Teacher not found.\n";
            }
        } else {
            cout << "Invalid user type.\n";
        }
    }

    // Fixed: Remove const from parameters to allow modification
    void manageCourses(vector<student> &students) {
        cout << "\n----- COURSE MANAGEMENT -----\n";
        int studentId;
        cout << "Enter student ID: ";
        cin >> studentId;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        int index = findById(students, studentId);
        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }
        
        cout << "Current courses for " << students[index].getName() << ":\n";
        const auto &courses = students[index].getCourses();
        for (size_t i = 0; i < courses.size(); ++i) {
            cout << i + 1 << ". " << courses[i] << "\n";
        }
        
        cout << "\n1. Add Course\n2. Remove Course\nChoice: ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        if (choice == 1) {
            string newCourse;
            cout << "Enter course name to add: ";
            getline(cin, newCourse);
            students[index].enrollcourse(newCourse);
            cout << "Course added successfully.\n";
        } else if (choice == 2 && !courses.empty()) {
            int courseNum;
            cout << "Enter course number to remove: ";
            cin >> courseNum;
            if (courseNum >= 1 && courseNum <= static_cast<int>(courses.size())) {
                students[index].removeCourse(courseNum - 1);
                cout << "Course removed.\n";
            } else {
                cout << "Invalid course number.\n";
            }
        }
    }
};

// ------------------ GLOBAL FUNCTIONS ------------------

void createBackup(const vector<student> &students, const vector<Teacher> &teachers, 
                  const vector<Admin> &admins) {
    string timestamp = to_string(time(nullptr));
    
    // Save students to backup file
    ofstream ofs1("backup_students_" + timestamp + ".txt");
    if (ofs1) {
        for (const auto &s : students) {
            ofs1 << s.getId() << "," << s.getName() << "," << s.getPassword() << ",";
            const auto &courses = s.getCourses();
            for (size_t i = 0; i < courses.size(); ++i) {
                ofs1 << courses[i];
                if (i < courses.size() - 1) ofs1 << "|";
            }
            ofs1 << "," << s.getGrades() << "\n";
        }
    }
    
    // Save teachers to backup file
    ofstream ofs2("backup_teachers_" + timestamp + ".txt");
    if (ofs2) {
        for (const auto &t : teachers) {
            ofs2 << t.getId() << "," << t.getName() << "," << t.getPassword() << ",";
            const auto &subjects = t.getSubjects();
            for (size_t i = 0; i < subjects.size(); ++i) {
                ofs2 << subjects[i];
                if (i < subjects.size() - 1) ofs2 << "|";
            }
            ofs2 << "\n";
        }
    }
    
    // Save admins to backup file
    ofstream ofs3("backup_admins_" + timestamp + ".txt");
    if (ofs3) {
        for (const auto &a : admins)
            ofs3 << a.getUsername() << "," << a.getPassword() << "\n";
    }
    
    cout << "Backup created successfully with timestamp: " << timestamp << "\n";
}

void exportToCSV(const vector<student> &students, const string &filename) {
    ofstream ofs(filename);
    if (!ofs) { cerr << "Error creating CSV file.\n"; return; }
    
    // CSV header
    ofs << "ID,Name,Courses,Grades\n";
    
    for (const auto &s : students) {
        ofs << s.getId() << "," << s.getName() << ",";
        
        // Courses as semicolon separated
        const auto &courses = s.getCourses();
        for (size_t i = 0; i < courses.size(); ++i) {
            ofs << courses[i];
            if (i < courses.size() - 1) ofs << ";";
        }
        
        ofs << "," << s.getGrades() << "\n";
    }
    cout << "Data exported to " << filename << " successfully.\n";
}

// ------------------ STUDENT LOGIN ------------------

void studentLogin(vector<student> &students) {
    int id;
    string password;
    cout << "Enter student id: ";
    if (!(cin >> id)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << "Invalid id\n"; return; }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int index = findById(students, id);
    if (index == -1) {
        cout << "Student not found\n";
        return;
    }

    cout << "Enter password: ";
    getline(cin, password);

    if (students[index].login(password)) {
        cout << "\nWelcome, " << students[index].getName() << "!\n";
        int choice = 0;
        while (true) {
            cout << "\n1. Enroll Course\n2. Show Details\n3. Change Password\n4. View Notifications\n5. Logout\nChoice: ";
            if (!(cin >> choice)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << "Invalid option\n"; continue; }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (choice == 1) {
                string courseName;
                cout << "Enter the course name: ";
                getline(cin, courseName);
                students[index].enrollcourse(courseName);
                cout << "Course enrolled successfully!\n";
            } else if (choice == 2) {
                students[index].showDetails();
            } else if (choice == 3) {
                string oldpass, newpass;
                cout << "Enter old password: ";
                getline(cin, oldpass);
                cout << "Enter new password: ";
                getline(cin, newpass);
                if (person::isValidPassword(newpass)) {
                    if (students[index].changePassword(oldpass, newpass))
                        cout << "Password changed successfully\n";
                    else
                        cout << "Incorrect old password\n";
                } else {
                    cout << "New password doesn't meet requirements!\n";
                }
            } else if (choice == 4) {
                students[index].showNotifications();
            } else if (choice == 5) {
                cout << "Logging out...\n";
                break;
            } else
                cout << "Invalid option!\n";
        }
    } else
        cout << "Wrong password!\n";
}

// ------------------ TEACHER LOGIN ------------------

void teacherLogin(vector<Teacher> &teachers, vector<student> &students) {
    int id;
    string password;
    cout << "Enter teacher id: ";
    if (!(cin >> id)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << "Invalid id\n"; return; }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int index = findById(teachers, id);
    if (index == -1) {
        cout << "Teacher not found\n";
        return;
    }

    cout << "Enter password: ";
    getline(cin, password);

    if (teachers[index].login(password)) {
        cout << "\nWelcome, " << teachers[index].getName() << "!\n";
        int choice = 0;
        while (true) {
            cout << "\n1. Add subjects\n2. Show Details\n3. Assign Grade\n4. Change Password\n5. Broadcast Notification\n6. Logout\nChoice: ";
            if (!(cin >> choice)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << "Invalid option\n"; continue; }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (choice == 1) {
                string subjectName;
                cout << "Enter subject you teach: ";
                getline(cin, subjectName);
                teachers[index].addSubject(subjectName);
                cout << subjectName << " added successfully\n";
            } else if (choice == 2) {
                teachers[index].showDetails();
            } else if (choice == 3) {
                int studentId;
                cout << "Enter student ID: ";
                if (!(cin >> studentId)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << "Invalid id\n"; continue; }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                int idx = findById(students, studentId);
                if (idx == -1)
                    cout << "Student not found\n";
                else {
                    // Show student details first
                    cout << "Student: " << students[idx].getName() << " | Current Grade: " 
                         << (students[idx].getGrades().empty() ? "No grade" : students[idx].getGrades()) << "\n";
                    
                    string grade;
                    cout << "Enter grade to assign (A, B, C, D, F, or numeric): ";
                    getline(cin, grade);
                    
                    if (!grade.empty()) {
                        teachers[index].assignGrade(students[idx], grade);
                        cout << "Grade '" << grade << "' assigned successfully!\n";
                    } else {
                        cout << "Grade cannot be empty!\n";
                    }
                }
            } else if (choice == 4) {
                string oldpass, newpass;
                cout << "Enter old password: ";
                getline(cin, oldpass);
                cout << "Enter new password: ";
                getline(cin, newpass);
                if (person::isValidPassword(newpass)) {
                    if (teachers[index].changePassword(oldpass, newpass))
                        cout << "Password changed successfully\n";
                    else
                        cout << "Incorrect old password\n";
                } else {
                    cout << "New password doesn't meet requirements!\n";
                }
            } else if (choice == 5) {
                string subject, message;
                cout << "Enter subject to broadcast to: ";
                getline(cin, subject);
                cout << "Enter message: ";
                getline(cin, message);
                teachers[index].broadcastToStudents(students, subject, message);
            } else if (choice == 6) {
                cout << "Logging out...\n";
                break;
            } else
                cout << "Invalid choice\n";
        }
    } else
        cout << "Wrong password!\n";
}

// ------------------ REGISTRATION ------------------

void studentRegistration(vector<student> &students) {
    string name, password;
    cout << "Enter name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    while (true) {
        cout << "Enter password (must contain uppercase, lowercase, and a digit): ";
        getline(cin, password);
        if (person::isValidPassword(password)) break;
        else cout << "Invalid password. Try again.\n";
    }

    students.emplace_back(name, password);
    cout << "Registration successful! Your student ID is: " << students.back().getId() << "\n";
}

void teacherRegistration(vector<Teacher> &teachers) {
    string name, password;
    cout << "Enter teacher name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    while (true) {
        cout << "Enter password (must contain uppercase, lowercase, and a digit): ";
        getline(cin, password);
        if (person::isValidPassword(password)) break;
        else cout << "Invalid password. Try again.\n";
    }

    teachers.emplace_back(name, password);
    cout << "Registration successful! Your teacher ID is: " << teachers.back().getId() << "\n";
}

void adminRegistration(vector<Admin> &admins) {
    string username, password;
    cout << "Enter admin username: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, username);
    while (true) {
        cout << "Enter password (must contain uppercase, lowercase, and a digit): ";
        getline(cin, password);
        if (person::isValidPassword(password)) break;
        else cout << "Invalid password. Try again.\n";
    }
    admins.emplace_back(username, password);
    cout << "Admin registered successfully!\n";
}

// ------------------ FILE SAVE/LOAD ------------------

void saveStudentsToFile(const vector<student> &students, const string &filename) {
    ofstream ofs(filename);
    if (!ofs) { cerr << "Error saving students.\n"; return; }
    for (const auto &s : students) {
        ofs << s.getId() << "," << s.getName() << "," << s.getPassword() << ",";
        const auto &courses = s.getCourses();
        for (size_t i = 0; i < courses.size(); ++i) {
            ofs << courses[i];
            if (i < courses.size() - 1) ofs << "|";
        }
        ofs << "," << s.getGrades() << "\n";
    }
}

void loadStudentsFromFile(vector<student> &students, const string &filename) {
    ifstream ifs(filename);
    if (!ifs) return;
    string line;
    int maxId = 0;
    while (getline(ifs, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string token;
        int id;
        string name, password, coursesStr, gradesStr;
        getline(ss, token, ',');
        id = stoi(token);
        getline(ss, name, ',');
        getline(ss, password, ',');
        getline(ss, coursesStr, ',');
        getline(ss, gradesStr);
        vector<string> courses;
        stringstream cs(coursesStr);
        while (getline(cs, token, '|'))
            if (!token.empty())
                courses.push_back(token);

        student s(name, password);
        s.setId(id);
        s.setCourses(courses);
        s.setGrades(gradesStr);
        students.push_back(s);
        if (id > maxId) maxId = id;
    }
    student::ensureNextIdAtLeast(maxId);
}

void saveTeachersToFile(const vector<Teacher> &teachers, const string &filename) {
    ofstream ofs(filename);
    if (!ofs) { cerr << "Error saving teachers.\n"; return; }
    for (const auto &t : teachers) {
        ofs << t.getId() << "," << t.getName() << "," << t.getPassword() << ",";
        const auto &subjects = t.getSubjects();
        for (size_t i = 0; i < subjects.size(); ++i) {
            ofs << subjects[i];
            if (i < subjects.size() - 1) ofs << "|";
        }
        ofs << "\n";
    }
}

void loadTeachersFromFile(vector<Teacher> &teachers, const string &filename) {
    ifstream ifs(filename);
    if (!ifs) return;
    string line;
    int maxId = 0;
    while (getline(ifs, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string token;
        int id;
        string name, password, subjectsStr;
        getline(ss, token, ',');
        id = stoi(token);
        getline(ss, name, ',');
        getline(ss, password, ',');
        getline(ss, subjectsStr);
        vector<string> subjects;
        stringstream subStream(subjectsStr);
        while (getline(subStream, token, '|'))
            if (!token.empty())
                subjects.push_back(token);

        Teacher t(name, password);
        t.setId(id);
        t.setSubjects(subjects);
        teachers.push_back(t);
        if (id > maxId) maxId = id;
    }
    Teacher::ensureNextIdAtLeast(maxId);
}

void saveAdminsToFile(const vector<Admin> &admins, const string &filename) {
    ofstream ofs(filename);
    if (!ofs) { cerr << "Error saving admins.\n"; return; }
    for (const auto &a : admins)
        ofs << a.getUsername() << "," << a.getPassword() << "\n";
}

void loadAdminsFromFile(vector<Admin> &admins, const string &filename) {
    ifstream ifs(filename);
    if (!ifs) return;
    string line;
    while (getline(ifs, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string username, password;
        getline(ss, username, ',');
        getline(ss, password);
        admins.emplace_back(username, password);
    }
}

// ------------------ ADMIN LOGIN ------------------

void adminLogin(vector<Admin> &admins, vector<student> &students, vector<Teacher> &teachers) {
    string username, password;
    cout << "Enter admin username: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    auto it = find_if(admins.begin(), admins.end(), [&](const Admin &a){ return a.getUsername() == username; });
    if (it == admins.end()) {
        cout << "Admin not found\n";
        return;
    }
    if (!it->login(password)) {
        cout << "Incorrect password\n";
        return;
    }

    cout << "\nWelcome, Admin " << username << "!\n";
    int choice = 0;
    while (true) {
        cout << "\n1. View All Students\n2. View All Teachers\n3. Subject Report\n4. Search Student\n5. Search Teacher\n6. System Statistics\n7. Reset Password\n8. Manage Courses\n9. Create Backup\n10. Export to CSV\n11. Logout\nChoice: ";
        if (!(cin >> choice)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << "Invalid option\n"; continue; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1)
            it->showAllStudents(students);
        else if (choice == 2)
            it->showAllTeachers(teachers);
        else if (choice == 3) {
            string subject;
            cout << "Enter subject to generate report: ";
            getline(cin, subject);
            it->subjectReport(students, subject);
        } else if (choice == 4) {
            string searchTerm;
            cout << "Enter student name or ID to search: ";
            getline(cin, searchTerm);
            it->searchStudent(students, searchTerm);
        } else if (choice == 5) {
            string searchTerm;
            cout << "Enter teacher name or ID to search: ";
            getline(cin, searchTerm);
            it->searchTeacher(teachers, searchTerm);
        } else if (choice == 6)
            it->showStatistics(students, teachers);
        else if (choice == 7)
            it->resetUserPassword(students, teachers);
        else if (choice == 8)
            it->manageCourses(students);
        else if (choice == 9)
            createBackup(students, teachers, admins);
        else if (choice == 10)
            exportToCSV(students, "students_export.csv");
        else if (choice == 11) {
            cout << "Logging out...\n";
            break;
        } else
            cout << "Invalid option!\n";
    }
}

// ------------------ MAIN ------------------

int main() {
    vector<student> students;
    vector<Teacher> teachers;
    vector<Admin> admins;

    loadStudentsFromFile(students, "students.txt");
    loadTeachersFromFile(teachers, "teachers.txt");
    loadAdminsFromFile(admins, "admins.txt");

    int choice;
    while (true) {
        cout << "\n1. Student Login\n2. Teacher Login\n3. Student Registration\n4. Teacher Registration\n5. Admin Registration\n6. Admin Login\n7. Exit\nChoice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input\n";
            continue;
        }

        switch (choice) {
        case 1: studentLogin(students); break;
        case 2: teacherLogin(teachers, students); break;
        case 3: studentRegistration(students); break;
        case 4: teacherRegistration(teachers); break;
        case 5: adminRegistration(admins); break;
        case 6: adminLogin(admins, students, teachers); break;
        case 7:
            cout << "Saving data...\n";
            saveStudentsToFile(students, "students.txt");
            saveTeachersToFile(teachers, "teachers.txt");
            saveAdminsToFile(admins, "admins.txt");
            cout << "Saved. Exiting.\n";
            return 0;
        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}   