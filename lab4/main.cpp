#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "diary.h"
using namespace std;
int main()
{
    string input;
    while(1)
    {
        cout << "Please input your command: pdadd, pdlist, pdshow or pdremove: " << endl;
        cin >> input;
        if(input == "pdadd")
        {
            system("pdadd.exe");
        }
        else if(input == "pdlist")
        {
            system("pdlist.exe");
        }
        else if(input == "pdshow")
        {
            system("pdshow.exe");
        }
        else
        {
            system("pdremove.exe");
        }
    }
    system("pause");
    return 0;
}