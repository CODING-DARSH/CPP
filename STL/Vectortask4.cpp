#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> name;
    vector<string> newlist;
    string choice;

    while (true) {
        cout << "Enter exit if you dont want to enter name else enter name: ";
        cin >> choice;
        if (choice == "exit") {
            break;
        } else {
            name.push_back(choice);
        }
    }
    for (string n : name) {
        bool ispalindrome = true; 

        for (int i = 0; i < n.size() / 2; i++) {
            if (n[i] != n[n.size() - i - 1]) {
                ispalindrome = false;
                break; 
            }
        }

        if (ispalindrome) {
            newlist.push_back(n);
        }
    }
    cout << "\nPalindrome names are:";
    for (string p : newlist) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
