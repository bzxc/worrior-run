#include <QPainter>
#include <QTimer>
#include <QSound>
#include <QMouseEvent>
#include <QMessageBox>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <math.h>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include "mainwindow.h"
#include <iostream>

/*-------------------全局遍历--------------------------*/
#define CHESS_ONE_SOUND ":/new/prefix1/chess-step"
#define WIN_SOUND ":/new/prefix1/chess-win"
#define LOSE_SOUND ":/new/prefix1/chess-lose"
const int kBoardMargin = 30; // 棋盘边缘空隙
const int KButtonMargin = 150; //button空隙
const int kRadius = 40; // 棋子半径
const int kMarkSize = 6; // 落子标记边长
const int kBlockSize = 40; // 格子的大小
const int kPosDelta = 20; // 鼠标点击的模糊距离上限
/*----------------------------------------------------*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 设置棋盘大小
    setFixedSize(kBoardMargin * 2 + kBlockSize * kBoardSizeNum + KButtonMargin, kBoardMargin * 2 + kBlockSize * kBoardSizeNum);
//    setStyleSheet("background-color:yellow;");

    // 开启鼠标hover功能，这两句一般要设置window的
    setMouseTracking(true);
//    centralWidget()->setMouseTracking(true); //加了会异常退出我也不知道为什么

    QPixmap pixmap = QPixmap(":/new/prefix1/back-ground").scaled(this->size());
    QPalette  palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );

    // 添加菜单
    QMenu *gameMenu = menuBar()->addMenu(tr("Game")); // menuBar默认是存在的，直接加菜单就可以了
    QAction *actionEl = new QAction(QIcon(":/new/prefix1/Star"),"ExampleLevel", this);
    connect(actionEl, &QAction::triggered, this, &MainWindow::initExampleLevel);
    gameMenu->addAction(actionEl);

    QAction *actionl1 = new QAction(QIcon(":/new/prefix1/Star"),"Level1", this);
    connect(actionl1, &QAction::triggered, this, &MainWindow::initiallevel1);
    gameMenu->addAction(actionl1);

    QAction *actionl2 = new QAction(QIcon(":/new/prefix1/Star"),"Level2", this);
    connect(actionl2, &QAction::triggered, this, &MainWindow::initiallevel2);
    gameMenu->addAction(actionl2);

    QAction *actionl3 = new QAction(QIcon(":/new/prefix1/Star"),"Level3", this);
    connect(actionl3, &QAction::triggered, this, &MainWindow::initiallevel3);
    gameMenu->addAction(actionl3);

    QAction *actionl4 = new QAction(QIcon(":/new/prefix1/Star"),"Level4", this);
    connect(actionl4, &QAction::triggered, this, &MainWindow::initiallevel4);
    gameMenu->addAction(actionl4);

    QAction *actionl5 = new QAction(QIcon(":/new/prefix1/Star"),"Level5", this);
    connect(actionl5, &QAction::triggered, this, &MainWindow::initiallevel5);
    gameMenu->addAction(actionl5);

    QAction *actionl6 = new QAction(QIcon(":/new/prefix1/Star"),"Level6", this);
    connect(actionl6, &QAction::triggered, this, &MainWindow::initiallevel6);
    gameMenu->addAction(actionl6);

    //添加按钮
    QPushButton* Start_button = new QPushButton(this); //开始按钮
    Start_button->setStyleSheet(
                       //正常状态样式
                       "QPushButton{"
                       "background-color:rgba(100,225,100,30);"//背景色（也可以设置图片）
                       "border-style:outset;"                  //边框样式（inset/outset）
                       "border-width:4px;"                     //边框宽度像素
                       "border-radius:10px;"                   //边框圆角半径像素
                       "border-color:rgba(255,255,255,30);"    //边框颜色
                       "font:bold 15px;"                       //字体，字体大小
                       "color:rgba(0,0,0,100);"                //字体颜色
                       "padding:6px;"                          //填衬
                       "}"
                       //鼠标按下样式
                       "QPushButton:pressed{"
                       "background-color:rgba(100,255,100,200);"
                       "border-color:rgba(255,255,255,30);"
                       "border-style:inset;"
                       "color:rgba(0,0,0,100);"
                       "}"
                       //鼠标悬停样式
                       "QPushButton:hover{"
                       "background-color:rgba(100,255,100,100);"
                       "border-color:rgba(255,255,255,200);"
                       "color:rgba(0,0,0,200);"
                       "}");
    Start_button->setText(tr("START")); //设置文本
    Start_button->setDefault(true); //默认选中
    Start_button->move(663,100); //设置坐标
    Start_button->resize(100,50); //设置大小
    //Start_button->setIcon(QPixmap(":/new/prefix1/Start-button"));
    connect(Start_button, &QPushButton::clicked, this, &MainWindow::StartGame);

    QPushButton* Quit_button = new QPushButton(this); //退出按钮
    Quit_button->setStyleSheet(
                       //正常状态样式
                       "QPushButton{"
                       "background-color:rgba(100,225,100,30);"//背景色（也可以设置图片）
                       "border-style:outset;"                  //边框样式（inset/outset）
                       "border-width:4px;"                     //边框宽度像素
                       "border-radius:10px;"                   //边框圆角半径像素
                       "border-color:rgba(255,255,255,30);"    //边框颜色
                       "font:bold 15px;"                       //字体，字体大小
                       "color:rgba(0,0,0,100);"                //字体颜色
                       "padding:6px;"                          //填衬
                       "}"
                       //鼠标按下样式
                       "QPushButton:pressed{"
                       "background-color:rgba(100,255,100,200);"
                       "border-color:rgba(255,255,255,30);"
                       "border-style:inset;"
                       "color:rgba(0,0,0,100);"
                       "}"
                       //鼠标悬停样式
                       "QPushButton:hover{"
                       "background-color:rgba(100,255,100,100);"
                       "border-color:rgba(255,255,255,200);"
                       "color:rgba(0,0,0,200);"
                       "}");
    Quit_button->setText(tr("QUIT")); //设置文本
    Quit_button->setDefault(false); //默认不选中
    Quit_button->move(663,180); //设置坐标
    Quit_button->resize(100,50); //设置大小
    //Quit_button->setStyleSheet("QPushButton{border-radius:10px;}");
    //注释掉设置大小可保持原生界面便于跨平台操作
    connect(Quit_button, &QPushButton::clicked, this, &MainWindow::close);

    QLabel* pLabel = new QLabel(this);
    QString strHTML = QString("<html> \
                               <head> \
                               <style> \
                               font{color:white;} #f{font-size:px; color: green;} \
                               </style> \
                               </head> \
                               <body>\
                               <font>%1</font><font id=\"f\">%2</font> \
                               <br/><br/> \
                               <img src=\":/Images/logo\" width=\"100\" height=\"100\"> \
                               </body> \
                               </html>").arg("worrior ").arg("Run!");
    pLabel->setText(strHTML);
    pLabel->setAlignment(Qt::AlignJustify);


    //QVBoxLayout* rightLayout = new QVBoxLayout;
    //rightLayout->addWidget(Start_button);
    //setLayout(rightLayout);

    initGame();
}

MainWindow::~MainWindow()
{
    if(game) //防止内存泄漏
    {
        delete game;
        game = nullptr;
    }
}

void MainWindow::StartGame(){
    initGame();
}

void MainWindow::initGame()
{
    // 初始化游戏模型
    game = new GameController;
    initExampleLevel();
}

void MainWindow::initExampleLevel()
{
    M_level = ExampleLevel;
    game->gameStatus = PLAYING;
    game->StartGame(M_level);
    update();
}

void MainWindow::initiallevel1()
{
    M_level = Level1;
    game->gameStatus = PLAYING;
    game->StartGame(M_level);
    update();
}

void MainWindow::initiallevel2()
{
    M_level = Level2;
    game->gameStatus = PLAYING;
    game->StartGame(M_level);
    update();
}

void MainWindow::initiallevel3()
{
    M_level = Level3;
    game->gameStatus = PLAYING;
    game->StartGame(M_level);
    update();
}

void MainWindow::initiallevel4()
{
    M_level = Level4;
    game->gameStatus = PLAYING;
    game->StartGame(M_level);
    update();
}

void MainWindow::initiallevel5()
{
    M_level = Level5;
    game->gameStatus = PLAYING;
    game->StartGame(M_level);
    update();
}

void MainWindow::initiallevel6()
{
    M_level = Level6;
    game->gameStatus = PLAYING;
    game->StartGame(M_level);
    update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // 绘制棋盘
    painter.setRenderHint(QPainter::Antialiasing, true); // 抗锯齿
    for(int i=0;i!=kBoardSizeNum+1;++i)
    {
        painter.setPen(Qt::white);
        painter.drawLine(kBoardMargin + kBlockSize*i, kBoardMargin, kBoardMargin + kBlockSize*i, size().height()-kBoardMargin);
        painter.drawLine(kBoardMargin, kBoardMargin + kBlockSize*i, size().height()-kBoardMargin, kBoardMargin + kBlockSize*i);
    }

    //绘制鼠标标记
    if (clickPosRow >= 0 && clickPosRow < kBoardSizeNum &&
        clickPosCol >= 0 && clickPosCol < kBoardSizeNum //&&
        /*game->gameMapVec[clickPosRow][clickPosCol] == 0*/)
    {
        // 判断点击位置是否合理
        if(clickPosCol <= (game->worrior->getX() + 1) && clickPosCol >= (game->worrior->getX() - 1) &&
           clickPosRow <= (game->worrior->getY() + 1) && clickPosRow >= (game->worrior->getY() - 1) )
            painter.setPen(Qt::green);
        else
            painter.setPen(Qt::red);

            painter.drawEllipse(kBoardMargin + kBlockSize * clickPosCol, kBoardMargin + kBlockSize * clickPosRow, kBlockSize, kBlockSize);
    }

    //绘制棋子
    for(int i = 0; i < kBoardSizeNum; i++) //由于逻辑问题，此处不能使用迭代器
    {
        for(int j = 0; j < kBoardSizeNum; j++)
        {
            if(game->gameMapVec[i][j] == 1) //绘制白棋(敌人)
            {
               //painter.setPen(Qt::black);
               //painter.setBrush(Qt::white);
               QPixmap pMap1;
               pMap1.load(":/new/prefix1/white-chess");

               painter.drawPixmap(kBoardMargin + kBlockSize * i, kBoardMargin + kBlockSize * j, kRadius, kRadius, pMap1);
               //painter.drawEllipse(kBoardMargin + kBlockSize * i, kBoardMargin + kBlockSize * j, kRadius, kRadius);
            }
            else if(game->gameMapVec[i][j] == -1) //绘制黑棋(勇士）
            {
               // painter.setPen(Qt::white);painter.setBrush(Qt::black);
                QPixmap pMap2;
                pMap2.load(":/new/prefix1/black-chess");

                painter.drawPixmap(kBoardMargin + kBlockSize * i, kBoardMargin + kBlockSize * j, kRadius, kRadius, pMap2);
            }
            else if(game->gameMapVec[i][j] == 2) //绘制出口
            {
                /*painter.setPen(Qt::white);
                painter.setBrush(Qt::blue);
                painter.drawEllipse(kBoardMargin + kBlockSize * i, kBoardMargin + kBlockSize * j, kRadius, kRadius);*/
                QPixmap pMap3;
                pMap3.load(":/new/prefix1/exit-");

                painter.drawPixmap(kBoardMargin + kBlockSize * i, kBoardMargin + kBlockSize * j, kRadius, kRadius, pMap3);
            }
            else if(game->gameMapVec[i][j] == 3) //绘制墙
            {
                //QBrush brush;
                /*brush.setColor(Qt::darkYellow);
                brush.setStyle(Qt::CrossPattern);*/
                painter.setPen(Qt::white);
                /*painter.setBrush(brush);
                painter.drawRect(kBoardMargin + kBlockSize * i, kBoardMargin + kBlockSize * j, kRadius, kRadius);*/
                QPixmap pMap4;
                pMap4.load(":/new/prefix1/walls");

                painter.drawPixmap(kBoardMargin + kBlockSize * i, kBoardMargin + kBlockSize * j, kRadius, kRadius, pMap4);
            }
        }
    }

    // 判断输赢
    if (clickPosRow > 0 && clickPosRow < kBoardSizeNum &&
        clickPosCol > 0 && clickPosCol < kBoardSizeNum )
    {
        //std::cout << "yes2" <<std::endl;
        if (game->isWin(clickPosRow, clickPosCol) && game->gameStatus == PLAYING)
        {
            qDebug("win");
            game->gameStatus = WIN;
            QSound::play(WIN_SOUND);
            QMessageBox::StandardButton reply;
            reply = QMessageBox::information(this, tr("通知："), tr("真菜，这么久才通关👎"));

            if (reply == QMessageBox::Ok)
            {
                if(M_level != Level6)
                {
                    M_level = static_cast<Level>(M_level + 1);
                    game->StartGame(M_level);
                    game->gameStatus = PLAYING;
                }
                else
                {
                    M_level = ExampleLevel;
                    game->StartGame(M_level);
                    game->gameStatus = PLAYING;
                }
                clickPosCol = -1;
                clickPosRow = -1;
            }

        }
    }

    //判断死局
    if (game->isDeadGame())
    {
        QSound::play(LOSE_SOUND);
        //QSound::play(LOSE_SOUND);
        QMessageBox::StandardButton btnValue = QMessageBox::information(this, tr("hhhhhhh"), tr("Geez,u dead!"));
        if (btnValue == QMessageBox::Ok)
        {
            game->StartGame(M_level);
            game->gameStatus = PLAYING;
        }

    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    //std::cout << x << " " << y << std::endl;
    // 棋盘边缘不能落子
    if (x >= kBoardMargin + kBlockSize / 2 &&
            x < size().width() - kBoardMargin &&
            y >= kBoardMargin + kBlockSize / 2 &&
            y < size().height()- kBoardMargin)
    {
        //std::cout<<"yes1"<<std::endl;
        clickPosRow = (y + 10) / kBlockSize - 1;
        clickPosCol = (x + 10) / kBlockSize - 1;
        //std::cout << clickPosCol << " " << clickPosRow << std::endl;
    }

    // 存了坐标后也要重绘
    update();//like the meaning of "repaint"
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (clickPosRow != -1 && clickPosCol != -1 /*&& game->gameMapVec[clickPosRow][clickPosCol] != 3*/)
    {
        //std::cout << "yes";
        game->MoveAction(clickPosRow, clickPosCol);
        QSound::play(CHESS_ONE_SOUND);

        update(); //重绘
    }
}
