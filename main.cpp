#include "mainwindow.h"
#include <QApplication>
#include<QResource>
#include<config.h>
int main(int argc, char *argv[])
{   QResource::registerResource(GAME_RCC_PATH);//注册rcc资源文件

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
