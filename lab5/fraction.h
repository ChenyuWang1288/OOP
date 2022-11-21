#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>
#include <string>
using namespace std;
class fraction
{
private:
    int denominator; // 分母
    int numerator; // 分子
public:
    fraction() {denominator = 1; numerator = 1;}; // default ctor
    fraction(int a, int b); // ctor
    ~fraction(); // destructor
    int G(int a, int b); // The function to calculate gcd of a and b

    /* operator overloading */
    fraction operator+(fraction pa);
    fraction operator-(fraction pa);
    fraction operator*(fraction pa);
    fraction operator/(fraction pa);
    fraction& operator=(const fraction& pa); 
    bool operator<(fraction pa);
    bool operator>(fraction pa);
    bool operator<=(fraction pa);
    bool operator>=(fraction pa);
    bool operator==(fraction pa);
    bool operator!=(fraction pa);
    friend ostream& operator<<(ostream& os, const fraction& data);
    friend istream& operator>>(istream& is, fraction& data);

    double TransToDouble(); // Transform fraction to floating number
    string TransToString(); // Transform fraction to a string
    void ConvertFromString(string deci); // conversion from a finite decimal string
    void print();
};
#endif