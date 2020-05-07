#ifndef ENERMY_H
#define ENERMY_H
#include "worrior.h"

class Enermy : public Worrior
{
public:
    Enermy(int X, int Y) : Worrior(X, Y){}
    void move(int, int, std::pair<int, int>** walls = nullptr);
};

#endif // ENERMY_H
