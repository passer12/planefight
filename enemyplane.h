#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include<config.h>
#include<QPixmap>
#include<QRect>
class enemyplane
{
public:
    enemyplane();
    //图片资源文件
    QPixmap m_enemy;

    //坐标更新
    void UpdatePosition();

    //坐标
    int m_x;
    int m_y;

    //移动速度
    int m_speed;

    //敌机状态
    bool m_free;

    //边框
    QRect m_rect;

    //设置生命
    int life ;
};

#endif // ENEMYPLANE_H
