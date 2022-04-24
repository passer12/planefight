#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<config.h>
#include<help.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initScense();
    //通过ui界面实现退出按钮
    //创建了帮助界面
    //将菜单中的帮助和帮助文档联系起来。
    connect(ui->actionhelp,&QAction::triggered,help1,&help::show);
    //创建关于我们界面，但是偷懒。
    aboutus->beabout();
    connect(ui->actionabout_us,&QAction::triggered,aboutus,&help::show);
    //音乐界面
    music->bemusic();
    connect(ui->actionmusic,&QAction::triggered,music,&help::show);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initScense(){
    //ui中设置菜单栏，和固定大小
    setWindowIcon(QIcon(GAME_WINDOW_ICON));
    //窗口图标设置，未知为何在ui上直接设置不显示（似乎不能二进制）

}
