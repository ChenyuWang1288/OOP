#include "diary.h"
#include <iostream>
#include <fstream>
using namespace std;
void diary::ReadDate(string d)
{
    date = d;
}
void diary::ReadContentFromConsole()
{
    string tmp;
    getchar();
    getline(cin, tmp);
    const string end1 = ".";
    while(tmp != end1 && tmp[0] != EOF)
    {
        content.push_back(tmp);
        getline(cin, tmp);
    }
    content.push_back(".");
}
void diary::ReadContentFromFile(string tmp)
{
    content.push_back(tmp);
}
void diary::Reset()
{
    content.clear();
}
void diary::RecordNo(int i)
{
    no = i;
}
string diary::GetDate()
{
    return date;
}
vector<string> diary::OutContent()
{
    return content;
}
int diary::ContentSize()
{
    return content.size();
}
void diary::RecordContentD(vector<string> t)
{
    content = t;
}