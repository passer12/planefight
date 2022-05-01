#include "midbullet.h"
#include<QPixmap>
midbullet::midbullet()
{
    //图片的加载
    m_Bullet.load(BULLET_MIDDLE_PATH);

    //坐标初始化（无用）
    m_x = GAME_WIDTH * 0.5 - m_Bullet.width();
    m_y = GAME_HEIGHT - m_Bullet.height();

    //子弹速度设置
    m_Speed = BULLET_SPEED;

    //初始化为闲置的
    m_Free = true;

    //设置碰撞检测，也就是边框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_x,m_y);


}

void midbullet::updatePosition()
{   //判断闲置否
    if(m_Free){
        return;
    }

    //子弹前进
    m_y -= m_Speed;
    m_Rect.moveTo(m_x,m_y);

    //子弹的再次空闲利用
    if(m_y <= -m_Bullet.height()){
        m_Free = true;
    }
}
