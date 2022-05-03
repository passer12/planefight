#include "enemyplane.h"
#include<config.h>
enemyplane::enemyplane()
{
    //速度
    m_speed = ENEMY_SPEED;

    //图片资源
    m_enemy.load(ENEMY_PATH);
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
