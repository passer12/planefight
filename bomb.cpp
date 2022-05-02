#include "bomb.h"
#include<QString>
bomb::bomb()
{   //将所有的爆炸图片放入到数组中
    for(int i = 1 ; i <= BOMB_MAX; i++){
        QString str = QString(BOMB_PATH).arg(i);
        m_pixarr.push_back(QPixmap(str));
    }
    //坐标
    m_x = 0;
    m_y = 0;

    //空闲状态
    m_free = true;

    //当前播放
    m_index = 0;

    //时间记录
    m_recorder = 0;
}

void bomb::updateInfo()
{   //闲否
    if(m_free){
        return;
    }
    //判断是否达到切图时间间隔
    m_recorder++;
    if(m_recorder<BOMB_INTERVAL){
        return;
    }
    m_recorder = 0;
    //索引播放哪张图
    m_index++;
    if(m_index > BOMB_MAX-1){
        m_index = 0;
        m_free = true;
    }

}
