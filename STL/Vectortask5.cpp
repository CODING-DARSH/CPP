#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> ognames;
    vector<string> modifiednames;
    string choice;
    while (true) {
        cout << "Enter exit if you dont want to enter name else enter name: ";
        cin >> choice;
        if (choice == "exit") {
            break;
        } else {
            ognames.push_back(choice);
        }
    }
    for (string n : ognames) {
        bool alreadyExists = false;
        for (string d : modifiednames) {
            if (n == d) {
                alreadyExists = true;
                break;
            }
        }
        if (!alreadyExists) {
            modifiednames.push_back(n);
        }
    }
    cout << "\nUnique names are: ";
    for (string dup : modifiednames) {
        cout << dup << " ";
    }

    return 0;
}
