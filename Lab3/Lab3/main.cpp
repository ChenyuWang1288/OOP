#include <iostream>
#include <cstdlib>
#include "Room.h"
#include "knight.h"
#define MAXSIZE 15
using namespace std;
void Game(int x, int y);
void PrintMap();
bool GetCommand();
void PrintPrompt(int nowx, int nowy);
bool CheckInput();
Room Graph[MAXSIZE][MAXSIZE];
knight k;
int x, y; // x is the length, y is the width
int main()
{
    cout << "Make sure that the total number of rooms is more than 3 (x * y >= 3)," << endl;
    cout << "Please enter the length and width of the map: " << endl;
    cin >> x >> y;
    while(1)
    {
        if(CheckInput())
        {
            Game(x, y);
            return 0;
        }
        else // The input size if invalid
        {
            cout << "Please enter the length and width of the map: ";
            cin >> x >> y; // reenter the value
        }
    }
}
/* Check if the input of size is valid */
bool CheckInput()
{
    if(x * y < 3)
    {
        cout << "Invalid Input!" << endl;
        return false;
    }
    return true;
}
void Game(int x, int y)
{
    /* Initialization */
    int i, j;
    /* set the position of monster randomly */
    int mx, my;
    while(1)
    {
        mx = rand()%y;
        my = rand()%x;
        if(!(mx == 0 && my == x / 2)) // monster can not exists at lobby
            break;
    }
    /* set the position of princess randomly */
    int px, py;
    while(1)
    {
        px = rand()%y;
        py = rand()%x;
        // princess can not exists at lobby and princess and monster will not exists at the same room
        if(!((px == mx && py == my) || (px == 0 && py == x / 2)))
            break;
    }
    /* Initialize the map */
    for(i = 0; i < y; i++)
    {    
        for(j = 0; j < x; j++)
        {
            // create the lobby
            if(j == x / 2 && i == 0)
            {    
                Graph[i][j].CreatRoom(1);
                Graph[i][j].Visit(); // The initial position is lobby, marked as visited
            }
            /*create the monster's room */
            if(i == mx && j == my)
                Graph[i][j].CreatRoom(2);
            /*create the princess's room */
            if(i == px && j == py)
                Graph[i][j].CreatRoom(3);
        }
    }
    // The initial position of the knight is lobby
    k.Initial(0, x / 2);
    PrintMap();
    cout << "Welcome to the lobby." << endl;
    PrintPrompt(0, x / 2);
    bool IsFindP = false; // if the knight found the princess or not
    while(1)
    {
        if(GetCommand() == false) // Wrong input
        {
            cout << "The game stopped due to some error!" <<endl;
            break;
        }
        PrintMap();
        if(k.Accessx() == px && k.Accessy() == py) // You find the princess
        {
            IsFindP = true;
            cout << "Wow! You find the princess!" << endl;
            cout << "Princess :My brave knight, please bring me out." << endl;
            cout << "Now your task is to bring princess out!" << endl;
        }
        if(k.Accessx() == mx && k.Accessy() == my) // You meet the monster
        {
            cout << "The monster!" << endl;
            if(IsFindP == true) // You have found the princess
            {
                cout << "The monster found you and princess, You lose the game!" << endl;
                return;
            }
            else
            {
                cout << "You lose the game!" << endl;
                return;
            }
        }
        if(k.Accessx() == 0 && k.Accessy() == x / 2) // You are at the lobby
        {
            if(IsFindP = true) // You have found the princess
            {
                cout << "Well done!" << endl;
                cout << "You take princess out successfully!" << endl;
                cout << "You win the game~ The knight lively happyly with the princess finally!" << endl;
                cout << "The game is closed." << endl;
                return;
            }
        }
        PrintPrompt(k.Accessx(), k.Accessy());
    }
}
/* Get the command of the direction from console */
bool GetCommand()
{
    string tmpstring;
    cin >> tmpstring;
    cin >> tmpstring;
    if(k.Move(tmpstring) == false) // Invalid input
        return false;
    Graph[k.Accessx()][k.Accessy()].Visit(); // mark the new room visited
    return true;
}
/* print the current map */
void PrintMap()
{
    int i, j;
    for(i = y - 1; i >= 0; i--)
    {
        for(j = 0; j < x; j++)
        {
            Graph[i][j].PrintRoom();
            if(i == k.Accessx() && j == k.Accessy())
            {
                cout << "<-- ";
            }
            else
            {
                cout << "    ";
            }
        }
        cout << endl;
    }
}
/* Print the exits of each room */
void PrintPrompt(int nowx, int nowy)
{
    // cout << nowx << " " << nowy << endl;
    if(x > 1 && y > 1)
    {
        if(nowx == y - 1 && nowy == x - 1)
            cout << "There are 2 exits: west and south.Enter your command: ";
        else if(nowx == y - 1 && nowy == 0)
            cout << "There are 2 exits: east and south.Enter your command: ";
        else if(nowx == x - 1)
           cout << "There are 3 exits: east, west and south.Enter your command: ";
        else if(nowx == 0 && nowy == x - 1)
           cout << "There are 2 exits: west and north.Enter your command: ";
        else if(nowx == 0 && nowy == 0)
           cout << "There are 2 exits: east and north.Enter your command: ";
        else if(nowx == 0)
           cout << "There are 3 exits: west, east and north.Enter your command: ";
        else if(nowy == 0 )
           cout << "There are 3 exits: east, south and north.Enter your command: ";
        else if(nowy == x - 1)
           cout << "There are 3 exits: west, south and north.Enter your command: ";
        else
           cout << "There are 4 exits: east, west, south and north.Enter your command: ";
    }
    else if(x == 1)
    {
        if(nowx == 0)
            cout << "There are 1 exits: north. Enter your command: ";
        else if(nowx == y - 1)
            cout << "There are 1 exits: south. Enter your command: ";
        else
            cout << "There are 2 exits: south and north. Enter your command: ";
    }
    else
    {
        if(nowy == 0)
            cout << "There are 1 exits: east. Enter your command: ";
        else if(nowy == x - 1)
            cout << "There are 1 exits: west. Enter your command: ";
        else
            cout << "There are 2 exits: east and west. Enter your command: ";
    }
}