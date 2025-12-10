// 3. Hospital Emergency Queue System
// Normal patients go in queue. Emergency patients go to the front (using two queues).
// Features
// Normal queue
// Emergency queue
// Emergency patients served first

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    queue<string> normalPatient;
    queue<string> emergencyPatient;
    string category;
    string namePatient;
    while (true)
    {
        cout << "Enter name for normal patient: ";  //enter normal patient's name
        cin >> namePatient;
        if (namePatient == "stop")
        {
            break;
        }
        else
        {
            normalPatient.push(namePatient);
        }
    }
    int choice;
    while (!normalPatient.empty() || !emergencyPatient.empty())
    {
        cout << "Enter 1 for register patient or enter 2 for patient turn: ";   //enter choice for patient turn or register a patient
        cin >> choice;
        switch (choice) //switch is used becoz a whole block needs to be executed
        {
        case 1:
            cout << "Enter name of patient: ";
            cin >> namePatient;
            cout << "Enter category or patient either emergency e or normal n: ";   
            cin >> category; // based on category patient queue with be updated
            if (category == "emergency" || category == "e")
            {
                emergencyPatient.push(namePatient); 
            }
            else
            {
                normalPatient.push(namePatient);    
            }
            break;
        case 2:
            if (!emergencyPatient.empty()) //first use if as our first priority is emergency patients if its empty we directly move to normal patients 
            {
                cout << emergencyPatient.front() << " emergency case \n";
                emergencyPatient.pop();
            }
            else            //else automatically assign patient in normal category
            {
                cout << normalPatient.front() << " normal patient turn \n";
                normalPatient.pop();
            }
        default:
            cout << "Enter valid choice";
            break;
        }
        if (choice == 3)
        {
            break;
        }
    }
}