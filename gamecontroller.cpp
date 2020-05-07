#include "gamecontroller.h"
#include <iostream>
GameController::GameController()
{
    for(auto &w : walls)
    {
        w = nullptr;
    }
}

GameController::~GameController()
{
    if(worrior)
        delete worrior;
    for (int i = 0; i < 10; ++i)
    {
        if(enermies[i])
            delete enermies[i];
    }
    for (int i = 0; i < 10; ++i)
    {
        if(walls[i])
            delete walls[i];
    }
    if(exit)
        delete exit;
}

void GameController::StartGame(Level level)
{
    S_level = level;
    // 初始棋盘
    gameMapVec.clear();
    for (int i = 0; i < kBoardSizeNum; i++)
    {
        std::vector<int> lineBoard;
        for (int j = 0; j < kBoardSizeNum; j++)
            lineBoard.push_back(0);
        gameMapVec.push_back(lineBoard);
    }

    if(S_level == ExampleLevel)
    {
        worrior = new Worrior(4, 2); //勇士位置
        gameMapVec[worrior->getX()][worrior->getY()] = -1;

        exit = new Point(13,10); //出口
        gameMapVec[exit->first][exit->second] = 2;

        enermies[0] = new Enermy(2, 2); //敌人
        for(int i=1;i<10;++i)
        {
            enermies[i] = nullptr;
        }
        for(int i=0;i<10;++i)
        {
            if(enermies[i])
            {
                gameMapVec[enermies[i]->getX()][enermies[i]->getY()] = 1;
            }
        }
    }
    else if(S_level == Level1)
    {
        for (int j=0;j<10;++j)
        {
            walls[j] = nullptr;
        }

        worrior = new Worrior(3, 9);
        gameMapVec[worrior->getX()][worrior->getY()] = -1;

        exit = new Point(13,3); //出口
        gameMapVec[exit->first][exit->second] = 2;

        int i = 0;
        enermies[i++] = new Enermy(2, 2); //敌人
        enermies[i++] = new Enermy(4, 12);
        enermies[i++] = new Enermy(9, 4);
        enermies[i++] = new Enermy(9, 10);
        for (;i<10;++i)
        {
            enermies[i] = nullptr;
        }
        for(int i=0;i<10;++i)
        {
            if(enermies[i])
            {
                gameMapVec[enermies[i]->getX()][enermies[i]->getY()] = 1;
            }
        }
    }
    else if(S_level == Level2)
    {
        worrior = new Worrior(4, 3);
        gameMapVec[worrior->getX()][worrior->getY()] = -1;

        exit = new Point(13,12); //出口
        gameMapVec[exit->first][exit->second] = 2;

        int i = 0;
        enermies[i++] = new Enermy(2, 2); //敌人
        enermies[i++] = new Enermy(2, 12);
        enermies[i++] = new Enermy(9, 3);
        enermies[i++] = new Enermy(8, 9);
        enermies[i++] = new Enermy(10, 6);
        enermies[i++] = new Enermy(11, 5);
        enermies[i++] = new Enermy(6, 11);
        enermies[i++] = new Enermy(6, 1);
        enermies[i++] = new Enermy(3, 5);
        enermies[i++] = new Enermy(7, 9);
        for (;i<10;++i)
        {
            enermies[i] = nullptr;
        }
        for(int i=0;i<10;++i)
        {
            if(enermies[i])
            {
                gameMapVec[enermies[i]->getX()][enermies[i]->getY()] = 1;
            }
        }
        int j = 0;
        walls[j++] = new Point(9, 5);
        walls[j++] = new Point(9, 6);
        walls[j++] = new Point(9, 7);
        walls[j++] = new Point(5, 10);
        walls[j++] = new Point(6, 10);
        for (;j<10;++j)
        {
            walls[j] = nullptr;
        }
        for(int i=0;i<10;++i)
        {
            if(walls[i])
            {
                gameMapVec[walls[i]->first][walls[i]->second] = 3;
            }
        }
    }
    else if(S_level == Level3)
    {
        worrior = new Worrior(4, 3);
        gameMapVec[worrior->getX()][worrior->getY()] = -1;

        exit = new Point(13,12); //出口
        gameMapVec[exit->first][exit->second] = 2;

        int i = 0;
        enermies[i++] = new Enermy(2, 2); //敌人
        enermies[i++] = new Enermy(2, 12);
        enermies[i++] = new Enermy(9, 3);
        enermies[i++] = new Enermy(8, 9);
        enermies[i++] = new Enermy(10, 6);
        enermies[i++] = new Enermy(11, 5);
        enermies[i++] = new Enermy(6, 11);
        enermies[i++] = new Enermy(6, 1);
        enermies[i++] = new Enermy(3, 5);
        enermies[i++] = new Enermy(7, 9);
        for (;i<10;++i)
        {
            enermies[i] = nullptr;
        }
        for(int i=0;i<10;++i)
        {
            if(enermies[i])
            {
                gameMapVec[enermies[i]->getX()][enermies[i]->getY()] = 1;
            }
        }
        int j = 0;
        walls[j++] = new Point(9, 5);
        walls[j++] = new Point(9, 6);
        walls[j++] = new Point(9, 7);
        walls[j++] = new Point(5, 10);
        walls[j++] = new Point(6, 10);
        walls[j++] = new Point(5, 2);
        walls[j++] = new Point(4, 2);
        for (;i<10;++i)
        {
            enermies[i] = nullptr;
        }
        for(int i=0;i<10;++i)
        {
            if(walls[i])
            {
                gameMapVec[walls[i]->first][walls[i]->second] = 3;
            }
        }
    }
}

void GameController::updateGameMap()
{
    for(auto Map_1 = gameMapVec.begin(); Map_1 != gameMapVec.end(); ++Map_1){
        for (auto Map_2 = (*Map_1).begin(); Map_2 != (*Map_1).end(); ++Map_2)
        {
            *Map_2 = 0;
        }
    } // 重置棋盘

    gameMapVec[exit->first][exit->second] = 2;

    for(auto &i:enermies)
    {
        if(i)
            gameMapVec[i->getX()][i->getY()] = 1;
    }

    for(auto &i:walls)
    {
        if(i)
            gameMapVec[i->first][i->second] = 3;
    }

    gameMapVec[worrior->getX()][worrior->getY()] = -1;

}

void GameController::MoveAction(int y1, int x1) //移动动作
{
    worrior->move(x1, y1, walls);//勇士移动

    for (auto &e : enermies)
    {
        if(e)
            e->move(worrior->getX(), worrior->getY(), walls);
    }   //敌人跟随

    //重置棋盘
    updateGameMap();
}

bool GameController::isWin(int y0, int x0) //判赢
{
    //std::cout << x0 << " " << y0 << std::endl;
    //std::cout << exit->first << " " << exit->second << std::endl;
    if(x0 <= (worrior->getX() + 1) && x0 >= (worrior->getX() - 1) &&
       y0 <= (worrior->getY() + 1) && y0 >= (worrior->getY() - 1) &&
       x0 == exit->first && y0 == exit->second)    //判断位置是否合理并断定成功条件
        return true;
    else
        return false;
}

bool GameController::isDeadGame() //判负
{
    for (auto &e : enermies)
    {
        if(e)
        {
            auto x0 = e->getX();
            auto y0 = e->getY();
            if(x0 == worrior->getX() && y0 == worrior->getY())
                return true;
        }
    }
    return false;
}
