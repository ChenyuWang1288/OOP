#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "diary.h"
using namespace std;
vector<diary> diarylist;
diary d;
const string end1 = ".";
int diarynum = 0;
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
void WriteDiary()
{
    string newdate;
    cin >> newdate;
    int replaceno = FindIfExist(newdate);
    if(replaceno == -1) // new date
    {
        diarynum++;
        d.ReadDate(newdate); // Read date
        d.RecordNo(diarynum);
        d.ReadContentFromConsole(); // Read content
        diarylist.push_back(d);
        d.Reset();
    }
    else
    {
        diarylist[replaceno - 1].Reset();
        diarylist[replaceno - 1].ReadDate(newdate);
        diarylist[replaceno - 1].ReadContentFromConsole(); // Read content
    }
    
}
void pdadd()
{
    WriteDiary();
}
void ReadDiary()
{
    ifstream readin;
    readin.open("diary.txt"); // open the file
    string linestr;
    diary p;
    int lineno = 0;
    int lastend = 0;
    if(readin.is_open()) // success opening the file
    {
        while(getline(readin, linestr)) // get a line from the diary
        {
            lineno++;
            if(lineno == 1 || lineno == lastend + 1) // Start recording a new diary
            {
                diarynum++;
                p.ReadDate(linestr);
                p.RecordNo(diarynum);
                continue;
            }
            if(linestr == end1 || linestr[0] == EOF) // End a diary
            {
                lastend = lineno;
                p.ReadContentFromFile(linestr);
                diarylist.push_back(p);
                p.Reset();
                continue;
            }
            p.ReadContentFromFile(linestr);
        }
        readin.close();
    }
    else // fail to open the file
    {
        cout << "Error!" << endl;
    }
}
int FindIfExist(string newdate) // find if the file have a diary with date "newdate"
{
    vector<diary>::iterator it;
    for(it = diarylist.begin(); it != diarylist.end(); it++)
    {
        if((*it).GetDate() == newdate)
        {
            return (*it).GetNo(); // return the index of the diary
        }
    }
    return -1;
}
void Out() // output the diary to file
{
    ofstream out;
    out.open("diary.txt");
    int i;
    if(out.is_open()) // success opening the file
    {
        vector<diary>::iterator it;
        vector<string> tmp;
        for(it = diarylist.begin(); it != diarylist.end(); it++)
        {
            out << (*it).GetDate() << endl;
            tmp = (*it).OutContent();
            for(i = 0; i < (*it).ContentSize(); i++)
            {
                out << tmp[i] << endl;
            }
        }
    }
    else // fail to open the file
    {
        cout << "Error!" << endl;
    }
}
int pdremove() // remove a diary
{
    string removedate;
    cout << "Please input the date of the diary you want to remove: " << endl;
    cin >> removedate;
    if(Remove(removedate) == 0) return 0; // success to remove
    return -1; // fail to remove
}
int Remove(string removedate)
{
    vector<diary>::iterator it;
    for(it = diarylist.begin(); it != diarylist.end(); it++) // find the date
    {
        if((*it).GetDate() == removedate) // success finding
        {
            diarylist.erase(it);
            return 0;
        }
    }
    return -1; // fail to find the date to remove
}
void pdlist()
{
    cout << "Enter PART if you want to list them at a date range, enter ALL if you want to list them all " << endl;
    string input;
    cin >> input;
    if(input == "ALL") // list them all
    {
        int i, j;
        // bubble sort
        for(i = 1; i <= diarylist.size() - 1; i++)
        {
            for(j = 0; j <= diarylist.size() - 1 - i; j++)
            {
                if(diarylist[j].GetDate() > diarylist[j+1].GetDate())
                {
                    diary tmp;
                    // tmp = diarylist[i];
                    // diarylist[i] = diarylist[i+1];
                    // diarylist[i+1] = tmp;
                    tmp.ReadDate(diarylist[j].GetDate());
                    tmp.RecordNo(diarylist[j].GetNo());
                    tmp.RecordContentD(diarylist[j].OutContent());

                    diarylist[j].ReadDate(diarylist[j+1].GetDate());
                    diarylist[j].RecordNo(diarylist[j+1].GetNo());
                    diarylist[j].RecordContentD(diarylist[j+1].OutContent());

                    diarylist[j+1].ReadDate(tmp.GetDate());
                    diarylist[j+1].RecordNo(tmp.GetNo());
                    diarylist[j+1].RecordContentD(tmp.OutContent());
                    
                }
            }
        }
    }
    else // list them partly
    {
        cout << "Enter the date range: " << endl;
        string begin, end;
        cin >> begin >> end;
        vector<diary> in;
        vector<diary> out;
        diary tmp;
        int i, j;
        // divide the diaries into to lists, between the date and out the date
        for(i = 0; i < diarylist.size(); i++)
        {
            if(diarylist[i].GetDate() <= end && diarylist[i].GetDate() >= begin)
            {
                tmp.ReadDate(diarylist[i].GetDate());
                tmp.RecordNo(diarylist[i].GetNo());
                tmp.RecordContentD(diarylist[i].OutContent());
                in.push_back(tmp);
                // cout << tmp.GetDate() << endl;
            }
            else
            {
                tmp.ReadDate(diarylist[i].GetDate());
                tmp.RecordNo(diarylist[i].GetNo());
                tmp.RecordContentD(diarylist[i].OutContent());
                out.push_back(tmp);
                // cout << tmp.GetDate() << endl;
            }
        }
        // bubble sort
        for(i = 1; i <= in.size() - 1; i++)
        {
            for(j = 0; j <= in.size() - 1 - i; j++)
            {
                if(in[j].GetDate() > in[j + 1].GetDate())
                {
                    // tmp = in[j];
                    // in[j] = in[j + 1];
                    // in[j + 1] = tmp;
                    tmp.ReadDate(in[j].GetDate());
                    tmp.RecordNo(in[j].GetNo());
                    tmp.RecordContentD(in[j].OutContent());
                    in[j].ReadDate(in[j+1].GetDate());
                    in[j].RecordNo(in[j+1].GetNo());
                    in[j].RecordContentD(in[j+1].OutContent());
                    in[j+1].ReadDate(tmp.GetDate());
                    in[j+1].RecordNo(tmp.GetNo());
                    in[j+1].RecordContentD(tmp.OutContent());
                }
            }
        }
        for(i = 0; i < in.size(); i++) // put the sorted diary into original list
        {
            diarylist[i].ReadDate(in[i].GetDate());
            diarylist[i].RecordNo(in[i].GetNo());
            diarylist[i].RecordContentD(in[i].OutContent());
        }
        for(j = 0; j < out.size(); j++) // put the sorted diary into original list 
        {
            diarylist[i].ReadDate(out[j].GetDate());
            diarylist[i].RecordNo(out[j].GetNo());
            diarylist[i].RecordContentD(out[j].OutContent());
            i++;
        }
    }
}
int pdshow()
{
    string showdate;
    cout << "Please input the date of the diary you want to show: " << endl;
    cin >> showdate;
    int showno = FindIfExist(showdate); // find the date
    if(showno == -1) return -1; // fail to find
    vector<string> tmp = diarylist[showno - 1].OutContent();
    vector<string>::iterator it;
    for(it = tmp.begin(); it != tmp.end(); it++) // cout the content
    {
        cout << *it << endl;
    }
    return 0;
}