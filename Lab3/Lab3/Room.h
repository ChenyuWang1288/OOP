#ifndef _ROOM_H_
#define _ROOM_H_

class Room
{
private:
    /* data */
    int special = 0; // 0 is cell, 1 is lobby, 2-monster, 3-princess
    bool isVisited = false; // if the room is visited
public:
    void CreatRoom(int type);
    void PrintRoom();
    void Visit();
};

#endif