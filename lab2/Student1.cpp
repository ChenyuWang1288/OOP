#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
class student
{
    public:
        string name;
        double score1;
        double score2;
        double score3;
        double average;
        int no;

        void aver();                        // Calculate average score
};
void PrintAver(double m)                    // if integers, print; if floating numbers, keep 5 decimals
{
    if(floor(m) == ceil(m))
    {
        cout << int(m) << endl;
    }
    else
        cout << fixed << setprecision(5) << m <<endl;
}
void student::aver()
{
    average = (score1 + score2 + score3) / 3;
}
int StrToNum(string str)                    // exchange a string to integers(1-10)
{
    if(str.length() == 2)
        return 10;
    return str[0] - 48;
}
int main()
{
    student s[15];                          // 10 students in total
    /* record the average scores and maximum and minimum scores of 3 subjects */
    double average[5];
    double max[5];
    double min[5];

    ifstream scorefile;
    scorefile.open("Information.txt");      // open the file
    int line_no = 0;                        // the current line
    string tmp;                             // current string
    int i = 0;
    
    if(scorefile.is_open())                 // open the file successfully
    {
        cout << "no      name    score1  score2  score3  average" << endl;
        while(scorefile >> tmp)
        {
            if(i == 0)                      // name
            {
                line_no++;
                cout << line_no ;
                if(line_no == 10)
                    cout << "      ";
                else cout << "       ";
                cout << tmp;
                for(int j = 0; j < 8 - tmp.length(); j++)
                    cout << " ";
                i++;
            }
            else if(i == 1)                 // score1 
            {
                cout << tmp << "       ";
                s[line_no].score1 = StrToNum(tmp);
                i++;
            }
            else if(i == 2)                 // score1 
            {
                cout << tmp << "       ";
                s[line_no].score2 = StrToNum(tmp);
                i++;
            }
            else if(i == 3)                 // score3
            {
                cout << tmp << "       ";
                s[line_no].score3 = StrToNum(tmp);
                i++;
            }
            if(i == 4)                      // print the average score
            {   
                s[line_no].aver();
                PrintAver(s[line_no].average);
                i = 0;
            }
        }
        double sum1 = 0;
        double sum2 = 0;
        double sum3 = 0;

        /* calculate the scores of 3 subjects */
        for(int j = 1; j <= 10; j++)
        {
            sum1 += s[j].score1;
            sum2 += s[j].score2;
            sum3 += s[j].score3;
        }
        average[1] = sum1 / (line_no);
        average[2] = sum2 / (line_no);
        average[3] = sum3 / (line_no);

        /* calculate the max number and minimun number */
        for(int j = 0; j < 5; j++)
        {
            max[j] = 0;
            min[j] = 5;
        }
        for(int j = 1; j <= 10; j++)
        {
            if(max[1] <= s[j].score1)
                max[1] = s[j].score1;
            if(max[2] <= s[j].score2)
                max[2] = s[j].score2;
            if(max[3] <= s[j].score3)
                max[3] = s[j].score3;
            if(min[1] >= s[j].score1)
                min[1] = s[j].score1;
            if(min[2] >= s[j].score2)
                min[2] = s[j].score2;
            if(min[3] >= s[j].score3)
                min[3] = s[j].score3;
        }
        /* print bottom line */
        cout << "        average ";
        cout << fixed << setprecision(1) << average[1] << "     ";
        cout << fixed << setprecision(1) << average[2] << "     ";
        cout << fixed << setprecision(1) << average[3] << endl;
        cout << "        min     "<< int(min[1]) << "       " << int(min[2]) << "       "<< int(min[3]) << "       "<< endl;
        cout << "        max     "<< int(max[1]) << "       " << int(max[2]) << "       "<< int(max[3]) << "       "<< endl;

        scorefile.close();              // close the file
    }
    else                                // fail to open the file
    {
        cout << "Error!" << endl;
    }
    
    return 0;
}
