#include "Room.h"
#include <iostream>
using namespace std;

void Room::PrintRoom()
{
    // if(special == 1)
    //     cout << "[..Lobby..]";
    // else if(special)
    if(isVisited)
    {
        if(special == 1)
            cout << "[..Lobby..]";
        else if(special == 0)
            cout << "[..cell...]";
        else if(special == 2)
            cout << "[.monster.]";
        else if(special == 3)
            cout << "[princess.]";
    }
    else
        cout << "[.........]";
}

void Room::CreatRoom(int type) // Create a type of room
{
    special = type;
}

void Room::Visit()
{
    isVisited = true;
}
