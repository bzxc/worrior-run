#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QMovie>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    QPixmap pixmap(":/new/prefix1/open-screen"); // 传图片
    QSplashScreen splash(pixmap);//装载图
    QLabel lbl(&splash);
    QMovie mv(":/new/prefix1/open-screen");
    lbl.setMovie (&mv);
    mv.start ();
    splash.show ();
    splash.setCursor(Qt::BlankCursor);
    for(int i=0; i<60000; i+=1)
    {
    QCoreApplication::processEvents();
    }
    splash.show();//显示图
    //for(long index = 0; index < 1000000000; index++);//显示延时
    splash.finish(&w);

    w.show();

    return a.exec();
}
