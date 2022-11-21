#include <iostream>
#include <string>
#include <iomanip>
#include "fraction.h"
#include <cmath>
using namespace std;
/* Test program */
int main()
{
    fraction f1, f2;
    cout << "Please input the numerator and the denominator of fraction1: " << endl;
    cin >> f1; // input fraction
    cout << "Please input the numerator and the denominator of fraction2: " << endl;
    cin >> f2;
    /* test the operator overloading */
    fraction f3 = f1 + f2;
    cout << "f1 + f2 = " << f3;
    fraction f4 = f1 - f2;
    cout << "f1 - f2 = " << f4;
    fraction f5 = f1 * f2;
    cout << "f1 * f2 = " << f5;
    fraction f6 = f1 / f2;
    cout << "f1 / f2 = " << f6;
    fraction f7 = f1;
    cout << "f7 = f1 = " << f7;
    cout << "Please input the numerator and the denominator of fraction to be compared with fraction1: " << endl;
    /* test the operator overloading */
    fraction f8;
    cin >> f8;
    cout << "This fraction == f1: " << (f8 == f1) << endl;
    cout << "This fraction >= f1: " << (f8 >= f1) << endl;
    cout << "This fraction <= f1: " << (f8 <= f1) << endl;
    cout << "This fraction > f1: " << (f8 > f1) << endl;
    cout << "This fraction < f1: " << (f8 < f1) << endl;
    cout << "This fraction != f1: " << (f8 != f1) << endl; 
    /* test the functions */
    cout << "Transform fraction1 to floating number: ";
    cout << fixed << setprecision(3) << f1.TransToDouble() << endl;
    cout << "Transform fraction1 to string: ";
    cout << f1.TransToString() << endl;
    cout << "Input a finite decimal string, we convert it to a fraction: ";
    string tmp;
    cin >> tmp;
    fraction f9;
    f9.ConvertFromString(tmp);
    cout << f9;
    system("pause");
    return 0;

}