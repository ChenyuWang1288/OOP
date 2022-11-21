#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include <string>
using namespace std;
class knight
{
private:
    int nowx;
    int nowy;
public:
    bool Move(string direction);
    /* Get the position of the knight */
    int Accessx();
    int Accessy();
    void Initial(int x, int y);
};
#endif