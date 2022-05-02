#ifndef BOMB_H
#define BOMB_H
#include<config.h>
#include<QPixmap>
#include<QVector>

class bomb
{
public:
    bomb();
    //更新信息
     void updateInfo();

     //爆炸资源数组
     QVector<QPixmap> m_pixarr;

     //爆炸位置
     int m_x;
     int m_y;

     //爆炸状态
     int m_free;

     //爆炸切图时间间隔
     int m_recorder;

     //爆炸时加载的图片下标
     int m_index;
};

#endif // BOMB_H
