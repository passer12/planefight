#include "play1.h"
#include "ui_play1.h"
#include<config.h>
#include<help.h>
#include<QSound>
#include<QTimer>
#include<QPainter>
#include<QMouseEvent>
#include<bullet.h>
play1::play1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::play1)
{
    ui->setupUi(this);
    initScense();
    //启动游戏,在主界面按按钮时实现了

}

play1::~play1()
{
    delete ui;
}
void play1::initScense(){
    //ui中设置菜单栏，和固定大小
    setWindowIcon(QIcon(GAME_WINDOW_ICON));
    //窗口图标设置，未知为何在ui上直接设置不显示（似乎不能二进制）

    //定时器设置
    m_timer.setInterval(GAME_RATE);
}
void play1::PlayGame()
{
    //开始游戏，调用定时器
    m_timer.start();
    connect(&m_timer,&QTimer::timeout,[=](){
       //更新坐标
        UpdatePostion();

       //绘制图片
        update();

       //启动测试子弹
       // testbullet.m_Free = false;



    });
}

void play1::UpdatePostion()
{
    //更新地图坐标
    m_map.mapPosition();
    //testbullet.updatePosition();
    //子弹射出
    hero1.shoot();
    //子弹移动
    for(int i = 0; i<BULLETS_NUM; i++ ){
    //一个个判断是否为闲置
        hero1.r_m_bullets[i].updatePosition();
        hero1.l_m_bullets[i].updatePosition();
        hero1.m_bullets[i].updatePosition();
    }

}

void play1::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,m_map.map1_posy,m_map.map1);
    painter.drawPixmap(0,m_map.map2_posy,m_map.map2);
    //paint hero
    painter.drawPixmap(hero1.m_x,hero1.m_y,hero1.myPlane);
    //painter.drawPixmap(testbullet.m_x,testbullet.m_y,testbullet.m_Bullet);
    //绘制子弹
    for(int i = 0; i<BULLETS_NUM; i++ ){
    //一个个判断是否为闲置
        if(hero1.r_m_bullets[i].m_Free == false){
            //绘制
            painter.drawPixmap(hero1.r_m_bullets[i].m_x,hero1.r_m_bullets[i].m_y,hero1.r_m_bullets[i].m_Bullet);
        }
    }
    for(int i = 0; i<BULLETS_NUM; i++ ){
    //一个个判断是否为闲置
        if(hero1.l_m_bullets[i].m_Free == false){
            //绘制
            painter.drawPixmap(hero1.l_m_bullets[i].m_x,hero1.l_m_bullets[i].m_y,hero1.l_m_bullets[i].m_Bullet);
        }
    }
    for(int i = 0; i<BULLETS_NUM; i++ ){
        //一个个判断是否为闲置
            if(hero1.m_bullets[i].m_Free == false){
                //绘制
                painter.drawPixmap(hero1.m_bullets[i].m_x,hero1.m_bullets[i].m_y,hero1.m_bullets[i].m_Bullet);
            }
        }
}

void play1::mouseMoveEvent(QMouseEvent *event)
{   //鼠标位置读取
    int x = event->x() - hero1.myRect.width()*0.5;
    int y = event->y() - hero1.myRect.height()*0.5 ;
    //鼠标边界检测
    if(x<0){
        x = 0;
    }if(x>GAME_WIDTH - hero1.myRect.width()){
        x = GAME_WIDTH - hero1.myRect.width();
    }if(y<0){
        y = 0;
    }if(y>GAME_HEIGHT - hero1.myRect.height()){
        y = GAME_HEIGHT - hero1.myRect.height();
    }

    hero1.setPosition(x,y);


}
