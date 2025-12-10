// 2. Game Player Turn System (Round-Based)
// 🧠 Players take turns in order. After a turn, they go to the back again.
// ✅ Features
// Circular queue behavior
// Turns keep rotating
// Simulates a multiplayer game

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<string> q;

    string choice;
    while (true)
    {
        cout << "Enter player name or stop : ";
        cin >> choice;      //enter name here or stop to stop adding name 
        if (choice == "stop")
        {
            break;
        }
        else
        {
            q.push(choice);
        }
    }
    int totalPlayers=q.size();
    int turncount=0;
    int count=0;
    cout<<totalPlayers;
    while (!q.empty())
    {
        string gameChoice;  
        
        cout << "Enter play if player wanna play the game : ";
        cin >> gameChoice;      //u hve 2 option here either u can type play and each players turn will be there turn by turn else u can exit turn 
        if (gameChoice == "play" || gameChoice=="Play")
        {
            string turn = q.front();
            cout << turn << " it's your turn \n";
            q.pop();
            q.push(turn);
            count++;        //each time singler player  plays count of player  increase in each round
                if (count==totalPlayers)    //if count is = to total players 1 round comlete
                {
                    turncount++;
                    count=0;
                    cout<<"Round "<<turncount<<" completed \n"; //display completed round number
                }
        }

        else break;
    }
}
