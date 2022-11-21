#ifndef MYFUNCTION_H
#define MYFUNCTION_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "diary.h"
using namespace std;
void ReadDiary();
void WriteDiary();
void Out();
int FindIfExist(string newdate);
int Remove(string removedate);
void pdadd();
void pdlist();
int pdshow();
int pdremove();
int Compare(string date1, string date2);
#endif