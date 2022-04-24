#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<help.h>
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
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
