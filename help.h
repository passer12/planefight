#ifndef HELP_H
#define HELP_H
#include <QWidget>
#include<map.h>
#include<QTimer>
#include<QPushButton>
namespace Ui {
class help;
}

class help : public QWidget
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = 0);
    ~help();
    void beabout();
    void bemusic();
    map m_map;
    //设置定时器
    QTimer m_timer;
    //更新元素坐标
    void UpdatePostion();

    //绘制到屏幕中
    void paintEvent(QPaintEvent *);
    //声音暂停
    QPushButton* nomusic = new QPushButton;
private:
    Ui::help *ui;
};

#endif // HELP_H
