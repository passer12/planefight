#include "hero.h"
#include<config.h>
hero::hero()
{
    //初始化加载飞机图片
    myPlane.load(HERO_PATH);
    //myPlane = myPlane.scaled(QSize(50,50),Qt::KeepAspectRatio);
    //初始化飞机位置
    m_x = (GAME_WIDTH - myPlane.width())*0.5;
    m_y = GAME_HEIGHT - myPlane.height();
    //初始化矩形边框
    myRect.setWidth(myPlane.width());
    myRect.setHeight(myPlane.height());
    myRect.moveTo(m_x,m_y);
}

void hero::shoot()
{   //发射间隔增加
    m_recorder++;
    //判断是否可发射
    if(m_recorder<BULLET_INTERVAL){
        return;
    }
    m_recorder = 0;
    //发射
    for(int i = 0; i<BULLETS_NUM; i++ ){
    //一个个判断是否为闲置
        if(r_m_bullets[i].m_Free){
            //调整坐标并使其非空闲
            r_m_bullets[i].m_x = m_x + myPlane.width()-r_m_bullets[i].m_Bullet.width();
            r_m_bullets[i].m_y = m_y;
            r_m_bullets[i].m_Free = false;
            break;
        }
    }for(int i = 0; i<BULLETS_NUM; i++ ){
        //一个个判断是否为闲置
            if(l_m_bullets[i].m_Free){
                //调整坐标并使其非空闲
                l_m_bullets[i].m_x = m_x;
                l_m_bullets[i].m_y = m_y;
                l_m_bullets[i].m_Free = false;
                break;
            }
        }
    for(int i = 0; i<BULLETS_NUM; i++ ){
            //一个个判断是否为闲置
                if(m_bullets[i].m_Free){
                    //调整坐标并使其非空闲
                    m_bullets[i].m_x = m_x + myPlane.width()*0.5 - m_bullets[i].m_Bullet.width()*0.5;
                    m_bullets[i].m_y = m_y;
                    m_bullets[i].m_Free = false;
                    break;
                }
            }
}

void hero::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
    myRect.moveTo(m_x,m_y);

}
