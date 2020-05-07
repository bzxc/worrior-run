#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <vector>
#include <utility>
#include "worrior.h"
#include "enermy.h"

const int kBoardSizeNum = 15;// 棋盘尺寸

typedef std::pair<int, int> Point;

enum Level        //关卡
{
    ExampleLevel = 0,
    Level1,
    Level2,
    Level3,
    Level4,
    Level5,
    Level6
};

enum GameStatus    //游戏状态
{
    PLAYING,
    WIN,
    DEAD
};

class GameController
{
public:
    GameController();
    ~GameController();

    Worrior *worrior; //勇士
    Enermy* enermies[10]; //敌人
    Point* exit; //出口
    Point* walls[10]; //墙

    std::vector<std::vector<int>> gameMapVec;// 存储当前游戏棋盘和棋子的情况,空白为0，Enermy:1，Worrior:-1
    Level S_level;
    GameStatus gameStatus;

    void StartGame(Level level);//开始游戏
    void updateGameMap(); // 每次落子后更新游戏棋盘
    bool isWin(int row, int col); // 判断游戏是否胜利
    bool isDeadGame(); // 判断是否和棋
    void MoveAction(int, int); //棋子移动行动
};

#endif // GAMECONTROLLER_H
