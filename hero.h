#ifndef HERO_H
#define HERO_H
#include<QPixmap>
#include<QRect>
#include<bullet.h>
#include<config.h>
#include<midbullet.h>
class hero
{
public:
    hero();
    //发射子弹
    void shoot();
    //设置飞机位置
    void setPosition(int x,int y);

    //飞机资源 对象
    QPixmap myPlane;

    //飞机坐标
    int m_x;
    int m_y;

    //飞机的矩形边框
    QRect myRect;

    //弹匣
    bullet r_m_bullets[BULLETS_NUM];
    bullet l_m_bullets[BULLETS_NUM];
    midbullet m_bullets[BULLETS_NUM];

    //记录发射时间
    int m_recorder;


};

#endif // HERO_H
