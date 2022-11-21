#include <iostream>
#include <string>
using namespace std;
int StrToNum(string str)
{
    if(str.length() == 2)
        return 10;
    return str[0] - 48;
}
int main()
{
    double m= 5;
    double n = 6;
    double x = m/n;
    cout << m<< n << endl;
    cout << x;
    return 0;
}