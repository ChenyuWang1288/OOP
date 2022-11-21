#include <iostream>
#include "Vector.h"
using namespace std;
#define TYPE int
int main()
{
    // 测试有size的构造
    cout << "Now let's test the ctor with size: " << endl;
    Vector<TYPE> Vint(5);
    TYPE e1, e2, e3, e4, e5;
    cout << "Please input five elements: " << endl;
    cin >> e1 >> e2 >> e3 >> e4 >> e5;
    Vint.push_back(e1);
    Vint.push_back(e2);
    Vint.push_back(e3);
    Vint.push_back(e4);
    Vint.push_back(e5);
    cout << "After pushing back the Vector: " << endl;
    cout << "Vint.empty() = " << Vint.empty() << endl;
    cout << "The current elements in Vector are: " << endl;
    int i;
    for(i = 0; i < Vint.size(); i++)
    {
        cout << Vint[i] << " ";
    }
    cout << endl;
    cout << "Access the element with index -1(actually it is illegal): " << endl;
    try{
        cout << Vint.at(-1) << endl;
    }catch (const char* msg){
        cerr << msg << endl;
    }
    cout << "Please input the index of the element you want to access: " << endl;
    int index;
    cin >> index;
    try{
        cout << Vint.at(index) << endl;
    }catch (const char* msg){
        cerr << msg << endl;
    }
    cout << "Vint.size() = " << Vint.size() << endl;
    Vint.clear();
    cout << "After Finishing Vint.clear()" << endl;
    cout << "Vint.size() = " << Vint.size() << endl;
    cout << "Vint.empty() = " << Vint.empty() << endl;

    // 无size的构造
    cout << "Now let's test the ctor without size: " << endl;
    Vector<TYPE> Vintw;
    cout << "Please input the size of the element you want to push back: " << endl;
    int n;
    cin >> n;
    TYPE tmp;
    for(i = 0; i < n; i++)
    {
        cin >> tmp;
        Vintw.push_back(tmp);
    }
    cout << "After pushing back the Vector, The current elements in Vector are: " << endl;
    for(i = 0; i < Vintw.size(); i++)
    {
        cout << Vintw[i] << " ";
    }
    cout << endl;
    cout << "Now we finish the test, BYE!" << endl;
    return 0;
    
}