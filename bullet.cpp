#include "bullet.h"
#include<QPixmap>
bullet::bullet()
{
    //图片的加载
    m_Bullet.load(BULLET_PATH);

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

void bullet::updatePosition()
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

void bullet::bossbulletupdate()
{
    //判断闲置否
        if(m_Free){
            return;
        }
        //子弹前进
        m_x += (1-rand()%(3))*BOSS_SPEED;
        m_y += (1-rand()%(3))*BOSS_SPEED;
        if(m_x < 0){
            m_x += 2*BOSS_SPEED;
        }if(m_y < 0){
            m_y += 2*BOSS_SPEED;
        }if(m_x > GAME_WIDTH - m_Bullet.width()){
            m_x -= 3*BOSS_SPEED;
        }if(m_y > GAME_HEIGHT*0.6){
            m_y -= 3*BOSS_SPEED;
        }m_Rect.moveTo(m_x,m_y);
        //子弹的再次空闲利用
        if(m_y <= -m_Bullet.height()){
            m_Free = true;
        }
}
