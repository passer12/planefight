#ifndef PLAY1_H
#define PLAY1_H
#include <QWidget>
#include<help.h>
#include<QTimer>
#include<map.h>
#include<hero.h>
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


private:
    Ui::play1 *ui;
};

#endif // PLAY1_H
