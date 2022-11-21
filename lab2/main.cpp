/* main.cpp */
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "student.h"
using namespace std;
extern vector<string> line1;
extern vector<int> cmax;
extern vector<int> cmin;
extern vector<int> cs;
extern vector<int> ccount;
void initial()
{
    int i;
    for(i = 0; i < line1.size(); i++)
    {
        cmax.push_back(0);
        cmin.push_back(5);
        cs.push_back(0);
        ccount.push_back(0);
    }
}
int main()
{
    vector<student*> s;
    
    line1.push_back("no");
    line1.push_back("name");
    ifstream scorefile;
    scorefile.open("Information.txt");      // open the file
    int line_no = 0;                        // the current line
    string tmp;                             // current string
    string linestr;
    string sname;
    string cname;
    if(scorefile.is_open()) // 判断是否成功打开文件
    {
        int linenum = 1;
        while(getline(scorefile, linestr)) 
        {
            int i = 1; // 这是该行第几个字符串
            student *pstudent = new student;
            char *lineCharArray;
            lineCharArray = new char[linestr.length() + 1];
            strcpy(lineCharArray, linestr.c_str());

            char *p = strtok(lineCharArray, " ");
            while(p)
            {
                if(i == 1) // 学生姓名
                {
                    sname = p;
                    pstudent->SaveName(sname);
                    pstudent->SaveNumber(linenum);
                }
                else if(i % 2 == 0) // Course
                {
                    int k;
                    cname = p;
                    for(k = 2; k < line1.size(); k++)
                    {
                        if(line1[k] == cname)
                            break;
                    }
                    if(k >= line1.size())
                    {
                        line1.push_back(cname);
                    }
                    i++;
                    if(p)
                        p = strtok(NULL, " ");
                    int score = p[0] - 48;
                    pstudent->SaveCourse(cname, score);

                }
                if(p)
                    p = strtok(NULL, " ");
                i++;
            }
            linenum++;
            s.push_back(pstudent);
        }
        initial();
        // OUTPUT the result
        int m;
        line1.push_back("average");
        int j;
        for(j = 0; j < line1.size(); j++) // 输出表头
        {
            cout << left << setw(12) << line1[j];
        }
        cout << endl;
        for(j = 0; j < s.size(); j++)
        {
            s[j]->Print();
        }
        // 输出最大值和平均数
        cout << "            ";
        cout << left <<  setw(12) << "average";
        
        for(j = 2; j < line1.size() - 1; j++)
        {
            if(!ccount[j]) cout << "             ";
            else
                cout << left << setw(12) << fixed << setprecision(1) << (double)1.0 * cs[j] / ccount[j];
        }
        cout << endl;
        cout << "            ";
        cout << left << setw(12) << "max";
        for(j = 2; j < line1.size() - 1; j++)
        {
            if(!ccount[j]) cout << "             ";
            else   
                cout << left << setw(12) << cmax[j];
        }
        cout << endl;
        cout << "            ";
        cout << left << setw(12) << "min";
        for(j = 2; j < line1.size() - 1; j++)
        {
            if(!ccount[j]) cout << "             ";
            else 
                cout << left << setw(12) << cmin[j];
        }
        cout << endl;
        scorefile.close();
    }
    else cout << "Error!" << endl; // 如果未能成功打开文件 输出Error！
    return 0;
}