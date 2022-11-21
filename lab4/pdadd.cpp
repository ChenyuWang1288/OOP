#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "diary.h"
#include "myfunction.h"
using namespace std;
int main()
{
    ReadDiary();
    pdadd();
    Out();
    return 0;
}