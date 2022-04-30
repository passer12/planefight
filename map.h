#ifndef MAP_H
#define MAP_H
#include<QPixmap>

class map
{
public:
    //构造函数
    map();
    //地图滚动坐标计算
    void mapPosition();
    //地图图片对象
    QPixmap map1;
    QPixmap map2;
    //地图y轴坐标
    int map1_posy;
    int map2_posy;
    //地图滚动幅度
    int scroll_speed;

};

#endif // MAP_H
