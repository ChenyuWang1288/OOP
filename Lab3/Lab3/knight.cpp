#include "knight.h"
#include <iostream>
#include <string>
using namespace std;
extern int x, y;
bool knight::Move(string direction) // move the knight according to command
{
    string south = "south";
    string north = "north";
    string east = "east";
    string west = "west";
    while(1)
    {
        if(direction == south)
        {
            nowx--;
            break;
        }
        else if(direction == north)
        {
            nowx++;
            break;
        }
        else if(direction == west)
        {
            nowy--;
            break;
        }
        else if(direction == east)
        {
            nowy++;
            break;
        }
        else // Reenter command
        {
            cout << "Invalid Input!" << endl;
            cout << "Please input go east/west/north/south again: "<<endl;
            cin >> direction;
            cin >> direction;
        }
    }
    /* Input a wrong command */
    if(nowx > y - 1 || nowy > x - 1 || nowx < 0 || nowy < 0)
    {    
        cout << "Error!" <<endl;
        return false;
    }
    return true;
}
/* get the position of the knight */
int knight::Accessx()
{
    return nowx;
}
int knight::Accessy()
{
    return nowy;
}
/* Initialize the position of the knight */
void knight::Initial(int x, int y)
{
    nowx = x;
    nowy = y;
}