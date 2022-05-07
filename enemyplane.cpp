#include "enemyplane.h"
#include<config.h>
#include<ctime>
enemyplane::enemyplane()
{
    //速度
    m_speed = ENEMY_SPEED;
    //srand((unsigned int)time(NULL));
    //图片资源
    int i =rand()%2+1;
    //QString str = QString(ENEMY_PATH).arg(i);

    m_enemy.load(QString(ENEMY_PATH).arg(i));

    m_enemy = m_enemy.scaled(100,150);
    //位置初始化
    m_x = 0;
    m_y = -m_enemy.width();

    //边框
    m_rect.setWidth(m_enemy.width());
    m_rect.setHeight(m_enemy.height());
    m_rect.moveTo(m_x,m_y);

    life = 30;
}

void enemyplane::UpdatePosition()
{
    //判断是否空闲
    if(m_free){
        return;
    }
    //竖直向下移动
    m_y += ENEMY_SPEED;
    m_rect.moveTo(m_x,m_y);
    //超出屏幕
    if(m_y>=GAME_HEIGHT){

        m_free = true;
    }
}
