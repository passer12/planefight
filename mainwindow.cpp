#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<config.h>
#include<help.h>
#include<QTimer>
#include<QPainter>
#include<play1.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);
    initScense();
    startbg->play();
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
    //启动游戏
    PlayGame();
    //第一个场景
    play1 *fight1 = new play1;


    connect(ui->pushButton,&QPushButton::clicked,[=](){
       fight1->show();
       this->hide();
       fight1->PlayGame();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initScense(){
    //ui中设置菜单栏，和固定大小
    setWindowIcon(QIcon(GAME_WINDOW_ICON));
    //窗口图标设置，未知为何在ui上直接设置不显示（似乎不能二进制）

    //定时器设置
    m_timer.setInterval(GAME_RATE);

    //背景设置
    m_map.map1.load(START_MAP);
    m_map.map2.load(START_MAP);
}

void MainWindow::PlayGame()
{
    //开始游戏，调用定时器
    m_timer.start();

    connect(&m_timer,&QTimer::timeout,[=](){
       //更新坐标
        UpdatePostion();

       //绘制图片
        update();

    });
}

void MainWindow::UpdatePostion()
{
    //更新地图坐标
    m_map.mapPosition();

}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,m_map.map1_posy,m_map.map1);
    painter.drawPixmap(0,m_map.map2_posy,m_map.map2);



}
