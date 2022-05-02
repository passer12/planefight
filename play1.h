#ifndef PLAY1_H
#define PLAY1_H
#include<config.h>
#include <QWidget>
#include<help.h>
#include<QTimer>
#include<map.h>
#include<hero.h>
#include<bullet.h>
#include<enemyplane.h>
#include<bomb.h>
#include<QSound>
namespace Ui {
class play1;
}
class play1 : public QWidget
{
    Q_OBJECT

public:
    explicit play1(QWidget *parent = 0);
    ~play1();
    void initScense();
    //设置定时器
    QTimer m_timer;

    //启动游戏
    void PlayGame();

    //更新元素坐标
    void UpdatePostion();

    //绘制到屏幕中
    void paintEvent(QPaintEvent *);

    //创建地图
    map m_map;

    //paint hero
    hero hero1;

    //鼠标跟随事件
    void mouseMoveEvent(QMouseEvent* event);

    //测试子弹
    //bullet testbullet;

    //一堆敌机
    enemyplane m_enemys[ENEMY_NUM];

    //设置时间记录
    int m_recorder;

    //敌机登场
    void enemycome();

    //碰撞检测
    void collisiondetection();

    //添加爆炸数组
    bomb m_bombs[BOMB_NUM];

    //爆炸音效
    QSound * bombsound = new QSound(BOMB_SOUND,this);

    //计录战胜数目
    int kill_num;

    //boss界面设置




private:
    Ui::play1 *ui;
};

#endif // PLAY1_H
