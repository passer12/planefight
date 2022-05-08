#include "help.h"
#include "ui_help.h"
#include<QLabel>
#include<qslider>
#include<QPainter>
#include<config.h>
#include<QPushButton>

help::help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
    //ui中设置菜单栏，和固定大小
    //定时器设置
    m_timer.setInterval(GAME_RATE);

    //背景设置
    m_map.map1.load(START_MAP);
    m_map.map2.load(START_MAP);
    m_map.map1_posy = -m_map.map1.height();
    //开始游戏，调用定时器
    m_timer.start();

    connect(&m_timer,&QTimer::timeout,[=](){
       //更新坐标
        UpdatePostion();

       //绘制图片
        update();
    });
}

help::~help()
{
    delete ui;
}
//创建beabout函数，我的建议是：不如继承
void help::beabout(){
    ui->label->setText(QString("aboutus"));
    ui->label_2->setText(QString("没什么好介绍的"));
    ui->label_3->setText(QString(""));
}
//创建bemusic
void help::bemusic(){
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    //设置水平滑动条
//    QSlider* sound = new QSlider(Qt::Horizontal);
//    sound->setMinimum(0);
//    sound->setMaximum(100);
//    sound->setValue(50);
//    sound->setParent(this);
//    sound->setGeometry(this->width()*0.5-150,this->height()*0.5,300,10);
    //关闭声音
    nomusic->setParent(this);
    nomusic->setText("声音开关");
    nomusic->setGeometry(QRect(this->width()*0.5-50,this->width()*0.5-50,100,100));
    nomusic->setFlat(true);

}

void help::UpdatePostion()
{//更新地图坐标
    m_map.mapPosition();

}

void help::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,m_map.map1_posy,m_map.map1);
    painter.drawPixmap(0,m_map.map2_posy,m_map.map2);

}


