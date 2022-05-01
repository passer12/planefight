#include "hero.h"
#include<config.h>
hero::hero()
{
    //初始化加载飞机图片
    myPlane.load(HERO_PATH);
    //初始化飞机位置
    m_x = (GAME_WIDTH - myPlane.width())*0.5;
    m_y = GAME_HEIGHT - myPlane.height();
    //初始化矩形边框
    myRect.setWidth(myPlane.width());
    myRect.setHeight(myPlane.height());
    myRect.moveTo(m_x,m_y);
}

void hero::shoot()
{

}

void hero::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
    myRect.moveTo(m_x,m_y);

}
