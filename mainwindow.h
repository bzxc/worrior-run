#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamecontroller.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void chessOneByPerson(); // 人执行
    //void chessOneByAI(); // AI下棋

    void initExampleLevel();
    void initiallevel1();
    void initiallevel2();
    void initiallevel3();
    void initiallevel4();
    void initiallevel5();
    void initiallevel6();
    void StartGame();

protected:
    // 绘制
    void paintEvent(QPaintEvent *event);
    // 监听鼠标移动情况，方便落子
    void mouseMoveEvent(QMouseEvent *event);
    // 实际落子
    void mouseReleaseEvent(QMouseEvent *event);

private:
    GameController *game; // 游戏指针
    Level M_level; // 存储游戏类型
    int clickPosRow, clickPosCol; // 存储将点击的位置
    void initGame();
    void checkGame(int y, int x);

};


#endif // MAINWINDOW_H
