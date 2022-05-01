#ifndef HERO_H
#define HERO_H
#include<QPixmap>
#include<QRect>
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


};

#endif // HERO_H
