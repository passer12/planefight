#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<help.h>
#include<QTimer>
#include<map.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initScense();
    help *help1 = new help;
    help* aboutus = new help;
    help* music = new help;
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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
