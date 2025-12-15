#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main(){
    priority_queue <pair<int,string>> orders;
    orders.push({100,"pizza"});
    orders.push({75,"Pasta"});
    orders.push({10,"Burger"});
    orders.push({5,"Noodles"});

    while (!orders.empty())
    {
        cout<<"\n Restro is delivering "<<orders.top().second;
        orders.pop();
    }
    

}