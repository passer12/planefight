#include "map.h"
#include<config.h>
map::map()
{
    //加载地图
    map1.load(MAP_PATH);
    map2.load(MAP_PATH);

    //初始化y轴
    map1_posy = -map1.height();
    map2_posy = 0;

    //地图滚动速率
    scroll_speed = MAP_SCROLL_SPEED;

}

void map::mapPosition()
{   map1_posy+=MAP_SCROLL_SPEED;
    map2_posy+=MAP_SCROLL_SPEED;
    if(map1_posy==0){
        map1_posy = -map1.height();
        map2_posy = 0;
    }

}
