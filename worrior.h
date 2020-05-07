#ifndef WORRIOR_H
#define WORRIOR_H
#include <utility>

class Worrior
{
public:
    Worrior(int, int);
    void move(int x0, int y0, std::pair<int, int> **walls = nullptr);//移动
    int getX(){return x;}
    int getY(){return y;}
protected:
    int x;
    int y;//坐标

};

#endif // WORRIOR_H
