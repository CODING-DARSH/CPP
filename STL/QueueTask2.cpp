#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    int signal = 1;

    while (!q.empty())  
    {
        cout<<"Green signal\n";
        int count = 0;
        while (!q.empty())
        {
            if (count < 3) {
                cout << "Car " << q.front() << "passed \n";
                q.pop();
                count++;
            }
            else {
                break; 
            }
        }
        cout << "\nRemaining cars:" << q.size()<<"\n";
        signal++; 
    }
}
