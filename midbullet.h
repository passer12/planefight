#ifndef MIDBULLET_H
#define MIDBULLET_H
#include<QPixmap>
#include<config.h>
#include<QRect>
class midbullet
{
public:
    midbullet();
    //更新子弹坐标
    void updatePosition();

    //子弹图片资源
    QPixmap m_Bullet;

    //子弹坐标
    int m_x;
    int m_y;

    //子弹移动速度
    int m_Speed;

    //子弹是否闲置
    bool m_Free;

    //子弹的矩形边框
    QRect m_Rect;
};
#endif // MIDBULLET_H
