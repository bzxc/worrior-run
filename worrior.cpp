#include "worrior.h"

Worrior::Worrior(int X, int Y):
    x(X), y(Y)
{

}

void Worrior::move(int x0, int y0, std::pair<int, int> **walls)
{
    for(int i = 0; i < 10; ++i)
    {
        if(walls[i])
        {
            if(x0 == walls[i]->first && y0 ==walls[i]->second)
                return;
        }
    }

    if(x0 <= (x + 1) && x0 >= (x - 1) &&
       y0 <= (y + 1) && y0 >= (y - 1) )    //判断位置是否合理
    {
        x = x0;
        y = y0;
    }
}
