#include "enermy.h"
#include <stdlib.h>

void Enermy::move(int x0, int y0, std::pair<int, int> **walls) //敌人移动
{
    int flat = 0;

    if(y - y0 != x -x0 && y - y0 != x0 - x)
    {
        if(abs(y-y0) < x-x0)
        {
            for(int i = 0; i < 10; ++i)
            {
                if(walls[i])
                    if(walls[i]->first == (x-1) && walls[i]->second == y)
                        flat = 1;
            }
        if(!flat)
            x -= 1;
        if(flat)
            y += 1;
        }
        else if(abs(y-y0) < x0-x)
        {
            for(int i = 0; i < 10; ++i)
            {
                if(walls[i])
                    if(walls[i]->first == (x+1) && walls[i]->second == y)
                        flat = 1;
            }
        if(!flat)
            x += 1;
        if(flat)
            y += 1;
        }
        else if(abs(x-x0) < y-y0)
        {
            for(int i = 0; i < 10; ++i)
            {
                if(walls[i])
                    if(walls[i]->first == x && walls[i]->second == (y-1))
                        flat = 1;
            }
        if(!flat)
            y -= 1;
        if(flat)
            x += 1;
        }
        else if(abs(x-x0) < y0-y)
        {
            for(int i = 0; i < 10; ++i)
            {
                if(walls[i])
                    if(walls[i]->first == x && walls[i]->second == (y+1))
                        flat = 1;
            }
        if(!flat)
            y += 1;
        if(flat)
            x += 1;
        }
    }
}
