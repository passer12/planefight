#ifndef BOSS_H
#define BOSS_H
#include<config.h>
#include<QPixmap>
#include<QRect>

class Boss
{
public:
    Boss();

    //图片资源文件
    QPixmap m_bossp;

    //坐标更新
    void UpdatePosition();

    //坐标
    int m_x;
    int m_y;

    //移动速度
    int m_speed;

    //boss状态
    bool m_free;

    //边框
    QRect m_rect;

    //设置生命
    int life ;
};

#endif // BOSS_H
