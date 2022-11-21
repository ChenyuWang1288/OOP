/* student.h */
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;
extern vector<string> line1;
class student
{
    public:
        void SaveNumber(int linenumber);
        void SaveName(string name);
        void SaveCourse(string cname, int score);
        void Print();
    private:
        int no;
        string name;
        struct course
        {
            int score;
            string coursename;
        };
        vector<course> C;
};
#endif