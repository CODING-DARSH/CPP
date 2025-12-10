// 3. Hospital Emergency Queue System
// Normal patients go in queue. Emergency patients go to the front (using two queues).
// Features
// Normal queue
// Emergency queue
// Emergency patients served first

#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main(){
    queue <string> normalPatient;
    queue <string> emergencyPatient;
    string category;
    string namePatient;
    while (true)
    {
        cout<<"Enter name for normal patient: ";
        cin>>namePatient;
        if (namePatient=="stop")
        {
            break;
        }
        else{
            normalPatient.push(namePatient);
        }
    }
    int choice;
    while (!normalPatient.empty() || !emergencyPatient.empty())
    {   
        cout<<"Enter 1 for register patient or enter 2 for patient turn: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter name of patient";
            cin>>namePatient;
            cout<<"Enter category or patient either emergency e or normal n: ";
            cin>>category;
                if (category=="emergency" ||category=="e")
                {
                    emergencyPatient.push(namePatient);
                }
                else
                {
                    normalPatient.push(namePatient);
                }
            break;
        case 2:
                if (!emergencyPatient.empty())
                {
                    cout<<emergencyPatient.front()<<" emergency case \n";
                    emergencyPatient.pop();
                }
                else{
                    cout<<normalPatient.front()<<" normal patient turn \n";
                    normalPatient.pop();
                }
        case 3:
                break;
        default:cout<<"Enter valid choice";
            break;
        }   
        if (choice==3)
        {
            break;
        }
        
    }
}