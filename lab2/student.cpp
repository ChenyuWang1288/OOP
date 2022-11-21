/* student.cpp */
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include "student.h"
using namespace std;
vector<string> line1; // 输出的第一行的string，下标从2开始为所有课程名
vector<int> cmax; // 记录每门课的最高分，下标与line1对应
vector<int> cmin; // 记录每门课的最低分，下标与line1对应
vector<int> cs; // 记录每门课的成绩之和，下标与line1对应
vector<int> ccount; // 记录每门课的选课人数，下标与line1对应

void student::SaveCourse(string cname, int score)
{
    struct course cr;
    cr.coursename = cname;
    cr.score = score;
    C.push_back(cr);
}
void student::SaveName(string sname)
{
    name = sname;
}
void student::SaveNumber(int n)
{
    no = n;
}
/* Print the result */ 
void student::Print()
{
    cout << left << setw(12) << no;
    cout << left << setw(12) << name;
    int i, j;
    for(j = 2; j < line1.size() - 1; j++)
    {
        i = 0;
        int flag = 0; /* 该学生是否修过这门课 */
        for(; i < C.size(); i++) /* 在该学生修的课中查找 */
        {
            if(C[i].coursename == line1[j]) /* 该学生修过这门课 */
            {
                cout << left << setw(12) << C[i].score;
                if(cmax[j] < C[i].score)
                    cmax[j] = C[i].score;
                if(cmin[j] > C[i].score)
                    cmin[j] = C[i].score;
                cs[j] += C[i].score;
                ccount[j]++;
                flag = 1;
                i++;
                break;
            }
        }
        if(!flag) /* 该学生没有修过这门课 */
        {
            cout << "            ";
        }
    }
    double total = 0;
    for(i = 0; i < C.size(); i++)
    {
        total += C[i].score;
    }
    /* 输出该学生所有科目的平均分 */
    total /= C.size();
    if(floor(total) == ceil(total))
        cout << left << setw(12) << total;
    else
        cout << left << setw(12) << fixed << setprecision(5) << total;
    cout << endl;
}