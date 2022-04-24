#include "help.h"
#include "ui_help.h"
#include<QLabel>
#include<qslider>
help::help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
}

help::~help()
{
    delete ui;
}
//创建beabout函数，我的建议是：不如继承
void help::beabout(){
    ui->label->setText(QString("aboutus"));
    ui->label_2->setText(QString("求三连"));
    ui->label_3->setText(QString("制作人帝王专属，哈哈"));
}
//创建bemusic
void help::bemusic(){
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    //设置水平滑动条
    QSlider* sound = new QSlider(Qt::Horizontal);
    sound->setMinimum(0);
    sound->setMaximum(100);
    sound->setValue(50);
    sound->setParent(this);
    sound->setGeometry(this->width()*0.5-150,this->height()*0.5,300,10);
}


