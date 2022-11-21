#ifndef DIARY_H
#define DIARY_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class diary
{
private:
    string date;
    vector<string> content;
    int no; // 第几条记录
public:
    diary(){no = 0;};
    ~diary(){};
    void ReadDate(string d);
    void RecordNo(int i);
    void ReadContentFromConsole();
    void ReadContentFromFile(string tmp);
    void Reset();
    string GetDate();
    int GetNo() {return no;};
    vector<string> OutContent();
    void RecordContentD(vector<string> t);
    int ContentSize();
};
#endif