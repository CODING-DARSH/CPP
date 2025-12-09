//real time use case of swiggy/zomato
#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main(){
    queue <string> q;
    string item;
    while (true) {
        cout << "Enter item or type stop to end: ";
        cin>>item;

        if (item == "stop") break;

        q.push(item);
    }
    while (!q.empty())
    {
        cout<<q.front()<<" is being prepared...."<<"\n";
        q.pop();
    }
    

}