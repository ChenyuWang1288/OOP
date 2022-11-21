#include <iostream>
#include "fraction.h"
#include <string>
#include <stdlib.h>
#include <math.h>
using namespace std;
char * getch(double num);
void fraction::print()
{
    cout << numerator << '/' << denominator << endl;
}
fraction::fraction(int a = 1, int b = 1) // ctor with default
{
    denominator = b;
    numerator = a;
}
fraction::~fraction() // destructor
{
}
int fraction::G(int a, int b) // gcd
{
    int tmp = b;
    while(a % b)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return tmp;
}
fraction fraction::operator+(fraction pa) // fraction1 + fraction 2
{
    int n1 = numerator * pa.denominator;
    int n2 = denominator * pa.numerator;
    int n = n1 + n2;
    int d = denominator * pa.denominator;
    int gcd = G(n, d);
    n = n / gcd;
    d = d / gcd;
    return fraction(n, d);
}
fraction fraction::operator-(fraction pa) // fraction1 - fraction 2
{
    int n1 = numerator * pa.denominator;
    int n2 = denominator * pa.numerator;
    int n = n1 - n2;
    int d = denominator * pa.denominator;
    int gcd = G(n, d);
    n = n / gcd;
    d = d / gcd;
    return fraction(n, d);
}
fraction fraction::operator*(fraction pa) // fraction1 * fraction 2
{
    int n = numerator * pa.numerator;
    int d = denominator * pa.denominator;
    int gcd = G(n, d);
    n = n / gcd;
    d = d / gcd;
    return fraction(n, d);
}
fraction fraction::operator/(fraction pa) // fraction1 / fraction 2
{
    int tmp;
    tmp = pa.denominator;
    pa.denominator = pa.numerator;
    pa.numerator = tmp;
    int n = numerator * pa.numerator;
    int d = denominator * pa.denominator;
    int gcd = G(n, d);
    n = n / gcd;
    d = d / gcd;
    return fraction(n, d);
}
fraction& fraction::operator=(const fraction& pa) // copy ctor
{
    numerator = pa.numerator;
    denominator = pa.denominator;
    return *this;
}
bool fraction::operator==(fraction pa)
{
    int n1 = numerator * pa.denominator;
    int n2 = denominator * pa.numerator;
    int n = n1 - n2;
    if(n == 0)
        return true;
    return false;
}
bool fraction::operator!=(fraction pa)
{
    int n1 = numerator * pa.denominator;
    int n2 = denominator * pa.numerator;
    int n = n1 - n2;
    if(n != 0)
        return true;
    return false;
}
bool fraction::operator<(fraction pa)
{
    int n1 = numerator * pa.denominator;
    int n2 = denominator * pa.numerator;
    int n = n1 - n2;
    
    if(n < 0)
        return true;
    return false;
}
bool fraction::operator>(fraction pa)
{
    int n1 = numerator * pa.denominator;
    int n2 = denominator * pa.numerator;
    int n = n1 - n2;
    
    if(n > 0)
        return true;
    return false;
}
bool fraction::operator<=(fraction pa)
{
    int n1 = numerator * pa.denominator;
    int n2 = denominator * pa.numerator;
    int n = n1 - n2;
    
    if(n <= 0)
        return true;
    return false;
}
bool fraction::operator>=(fraction pa)
{
    int n1 = numerator * pa.denominator;
    int n2 = denominator * pa.numerator;
    int n = n1 - n2;
    
    if(n >= 0)
        return true;
    return false;
}
double fraction::TransToDouble()
{
    return (double)(numerator * 1.000 / denominator);
}
string fraction::TransToString()
{
    string tmp1, tmp2;
    tmp1 = to_string(numerator);
    tmp2 = to_string(denominator);
    string tmp = "/";
    tmp1.append(tmp);
    tmp1.append(tmp2);

    return tmp1;
}
void fraction::ConvertFromString(string deci)
{
    int l, n, d, left, right;
    double db = stod(deci);
    char* expo = getch(db);
    char point[] = ".";
    char* tmp0 = strtok(expo, point); // String splitting
    char* tmp1 = strtok(NULL, point);
    left = atoi(tmp0);
    right = atoi(tmp1);
    string tmp = tmp1;
    l = tmp.size();
    n = (int)(left * pow(10, l) + right);
    d = (int)pow(10, l);
    int gcd = G(n, d);
    n = n / gcd; // reduction
    d = d / gcd;
    numerator = n;
    denominator = d;
}
char* getch(double num) 
{
    string tmp;
    int i, j;
    tmp = to_string(num);
    i = tmp.size();
    char *expo = new char[i];
    strcpy(expo, tmp.c_str());
    return expo;
}
ostream& operator<<(ostream& os, const fraction& data) // inserter and extractor for streams
{
    return os << data.numerator << "/" << data.denominator <<endl;
}
istream& operator>>(istream& is, fraction& data) // inserter and extractor for streams
{
    return is >> data.numerator >> data.denominator;
}