#include "boss.h"
#include<ctime>
Boss::Boss()
{   //图片资源
    m_bossp.load(BOSS_PATH);
    //子弹图标
    bullet2.m_Bullet.load(BOSS_RIGHT_BULLET);
    bullet1.m_Bullet.load(BOSS_LEFT_BULLET);
    bullet1.m_Bullet = bullet1.m_Bullet.scaled(150,150);
//    bullet1.m_y = -2*bullet1.m_Bullet.height();
    bullet2.m_y = -bullet2.m_Bullet.height();
    bullet1.m_Rect.setWidth(bullet1.m_Bullet.width());
    bullet2.m_Rect.setWidth(bullet2.m_Bullet.width());
    bullet2.m_Rect.setHeight(bullet2.m_Bullet.height());
    bullet1.m_Rect.setHeight(bullet1.m_Bullet.height());
    //移动速度
    m_speed = BOSS_SPEED;
    //坐标
    m_x = GAME_WIDTH*0.5;
    m_y = 0;

    //状态
    m_free = true;

    //边框
    m_rect.setWidth(m_bossp.width());
    m_rect.setHeight(m_bossp.height());
    m_rect.moveTo(m_x,m_y);
}

void Boss::UpdatePosition()
{   //闲否
    srand((unsigned int)time(NULL));
    if(m_free){
        return;
    }
    m_x += (1-rand()%(3))*BOSS_SPEED;
    m_y += (1-rand()%(3))*BOSS_SPEED;
    if(m_x < 0){
        m_x += 2*BOSS_SPEED;
    }if(m_y < 0){
        m_y += 2*BOSS_SPEED;
    }if(m_y > GAME_HEIGHT*0.5){
        m_y -= 3*BOSS_SPEED;
    }if(m_x > GAME_WIDTH - m_bossp.width()){
        m_x -= 3*BOSS_SPEED;
    }m_rect.moveTo(m_x,m_y);
}
