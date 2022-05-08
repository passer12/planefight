#include "play1.h"
#include "ui_play1.h"
#include<config.h>
#include<help.h>
#include<QSound>
#include<QTimer>
#include<QPainter>
#include<QMouseEvent>
#include<bullet.h>
#include<ctime>
#include<QMessageBox>
play1::play1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::play1)
{   best2 = 30;
    ui->setupUi(this);
    initScense();
    //启动游戏,在主界面按按钮时实现了
    //bosslife
    bosslife = 20;
    //被boss击中
    index = 0;
    //无敌帧设置
    best = 30;
    //龙头击中否
    head = 0;
    //随机数种子
    srand((unsigned int)time(NULL));
    QMessageBox message(QMessageBox::NoIcon,"检测到大波能量","垃圾换皮飞机也敢挑战龙王？");
    message.setIconPixmap(QPixmap(BOSS_PATH));

}

play1::~play1()
{
    delete ui;
}
void play1::initScense(){
    //ui中设置菜单栏，和固定大小
    setWindowIcon(QIcon(GAME_WINDOW_ICON));
    //窗口图标设置，未知为何在ui上直接设置不显示（似乎不能二进制）

    //定时器设置
    m_timer.setInterval(GAME_RATE);

    //时间记录初始化
    m_recorder = 0;

    //调整爆炸音量 未知如何

    //杀敌数置零
    kill_num = 0;

}
void play1::PlayGame()
{
    //开始游戏，调用定时器
    m_timer.start();
    //背景音乐

    bg->play();
    QSound::play(STARTVOICE);

    connect(&m_timer,&QTimer::timeout,[=](){
        //判断死活
        isdie();
        //判断大招
        istime();
       //更新坐标
        UpdatePostion();
        //敌机出场
         enemycome(flag);
       //绘制图片
        update();
       //启动测试子弹
       // testbullet.m_Free = false;
        //检测碰撞
        l_collisiondetection();
        m_collisiondetection();
        r_collisiondetection();
        //杀敌数目判断
        if(kill_num == KILL_NUM){
            flag = true;
            bg->stop();
            fg->play();
            QMessageBox::warning(this,tr("检测到大波能量波动"),tr("人类？滚吧！！"));
            QSound::play(VOICE);
            QMessageBox message(QMessageBox::NoIcon,"飘渺之音","垃圾换皮飞机也敢挑战龙王？");
            message.setIconPixmap(QPixmap(BOSS_PATH));
            message.exec();
            QSound::play(SHOW);
            QMessageBox message1(QMessageBox::NoIcon,"反驳","我不做人了！");
            message1.setIconPixmap(QPixmap(NEWPLANE));
            message1.exec();
            QMessageBox::about(this,"前生记忆","boss有30滴血，只有中间的黄色子弹能对其造成伤害，boss身体的攻击范围之外，子弹伤害无效，请移动到屏幕的3/5位置处攻击敌人。在boss冲刺之前回到安全区，你只有一条命");

            m_map.map1.load(BOSS_MAP_PATH);
            m_map.map2.load(BOSS_MAP_PATH);
            hero1.myPlane.load(NEWPLANE);
            hero1.myPlane = hero1.myPlane.scaled(220,140);
            for(int i = 0;i<BULLETS_NUM;i++){
            hero1.m_bullets[i].m_Bullet.load(NEWBULLET);
            hero1.m_bullets[i].m_Bullet = hero1.m_bullets[i].m_Bullet.scaled(50,100);
            }kill_num++;

        }
        //boss
        bosscoming();

        //判定击中
        shootboss();

        //判定胜负
        iswin();



    });

}

void play1::UpdatePostion()
{
    //更新地图坐标
    m_map.mapPosition();
    //testbullet.updatePosition();
    //子弹射出
    hero1.shoot();
    //子弹移动
    for(int i = 0; i<BULLETS_NUM; i++ ){
    //一个个判断是否为闲置
        hero1.r_m_bullets[i].updatePosition();
        hero1.l_m_bullets[i].updatePosition();
        hero1.m_bullets[i].updatePosition();
    }/*m_boss.bullet1.updatePosition();
    m_boss.bullet2.updatePosition();*/
    //更新敌机坐标
    for(int i = 0 ;i<ENEMY_NUM; i++){
        m_enemys[i].UpdatePosition();
    }
    //计算爆炸图片
    for(int i = 0; i <BOMB_NUM ; i++){
        if(m_bombs[i].m_free == false){
            m_bombs[i].updateInfo();
        }
    }
    //加入boss
    if(m_boss.m_free == false){
        m_boss.UpdatePosition();
    }
    //boss子弹规矩
    if(m_boss.bullet1.m_Free == false){
        m_boss.bullet1.bossbulletupdate();
        m_boss.bullet2.bossbulletupdate();
    }
}

void play1::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(0,m_map.map1_posy,m_map.map1);
    painter.drawPixmap(0,m_map.map2_posy,m_map.map2);
    //paint hero
    painter.drawPixmap(hero1.m_x,hero1.m_y,hero1.myPlane);
    //boss子弹绘制
    if(m_boss.bullet1.m_Free == false){
    painter.drawPixmap(m_boss.bullet1.m_x,m_boss.bullet1.m_y,m_boss.bullet1.m_Bullet);
    painter.drawPixmap(m_boss.bullet2.m_x,m_boss.bullet2.m_y,m_boss.bullet2.m_Bullet);
    }
    //painter.drawPixmap(testbullet.m_x,testbullet.m_y,testbullet.m_Bullet);
    //绘制子弹
    for(int i = 0; i<BULLETS_NUM; i++ ){
    //一个个判断是否为闲置
        if(hero1.r_m_bullets[i].m_Free == false){
            //绘制
            painter.drawPixmap(hero1.r_m_bullets[i].m_x,hero1.r_m_bullets[i].m_y,hero1.r_m_bullets[i].m_Bullet);
        }
    }
    for(int i = 0; i<BULLETS_NUM; i++ ){
    //一个个判断是否为闲置
        if(hero1.l_m_bullets[i].m_Free == false){
            //绘制
            painter.drawPixmap(hero1.l_m_bullets[i].m_x,hero1.l_m_bullets[i].m_y,hero1.l_m_bullets[i].m_Bullet);
        }
    }
    for(int i = 0; i<BULLETS_NUM; i++ ){
        //一个个判断是否为闲置
            if(hero1.m_bullets[i].m_Free == false){
                //绘制
                painter.drawPixmap(hero1.m_bullets[i].m_x,hero1.m_bullets[i].m_y,hero1.m_bullets[i].m_Bullet);
            }
        }
    //绘制敌机
    for(int i = 0 ; i<ENEMY_NUM ; i++){
        //闲置否
        if(m_enemys[i].m_free == false){
            painter.drawPixmap(m_enemys[i].m_x,m_enemys[i].m_y,m_enemys[i].m_enemy);
        }
    }
    //绘制爆炸
    for(int i = 0; i <BOMB_NUM ; i++){
        if(m_bombs[i].m_free == false){
            painter.drawPixmap(m_bombs[i].m_x, m_bombs[i].m_y, m_bombs[i].m_pixarr[m_bombs[i].m_index]);
        }
    }
    //绘制boss
    if(m_boss.m_free==false){
    painter.drawPixmap(m_boss.m_x,m_boss.m_y,m_boss.m_bossp);
    }
}

void play1::mouseMoveEvent(QMouseEvent *event)
{   //鼠标位置读取
    int x = event->x() - hero1.myRect.width()*0.5;
    int y = event->y() - hero1.myRect.height()*0.5 ;
    //鼠标边界检测
    if(x<0){
        x = 0;
    }if(x>GAME_WIDTH - hero1.myRect.width()){
        x = GAME_WIDTH - hero1.myRect.width();
    }if(y<0){
        y = 0;
    }if(y>GAME_HEIGHT - hero1.myRect.height()){
        y = GAME_HEIGHT - hero1.myRect.height();
    }

    hero1.setPosition(x,y);


}

void play1::enemycome(bool f)
{   if(f){
       return;
    }
    m_recorder++;
    //判读是否可登场
    if(m_recorder < ENEMY_INTERVAL){
        return;
    }
    m_recorder = 0;
    for(int i = 0; i < ENEMY_NUM;i++){
        if(m_enemys[i].m_free){
            m_enemys[i].m_free = false;
            m_enemys[i].m_x = rand()%(GAME_WIDTH-m_enemys[i].m_enemy.width());
            m_enemys[i].m_y = -m_enemys[i].m_enemy.height();
            m_enemys[i].m_rect.moveTo(m_enemys[i].m_x,m_enemys[i].m_y);
            break;
        }
    }

}
//碰撞检测
void play1::l_collisiondetection()
{   //遍历敌机和子弹
    for(int i = 0; i <ENEMY_NUM; i++){
        if(m_enemys[i].m_free){
            continue;
        }
        for(int j = 0; j<BULLETS_NUM; j++){
            if(hero1.m_bullets[j].m_Free){
                continue;
            }//如果重叠
            if(m_enemys[i].m_rect.intersects(hero1.l_m_bullets[j].m_Rect)){
                hero1.l_m_bullets[j].m_Free = true;
                m_enemys[i].life--;
                if(m_enemys[i].life > 0){
                    continue;
                }
                m_enemys[i].m_free = true;
                m_enemys[i].life =30;
                //杀敌数加一
                kill_num++;
                for(int k = 0 ; k<BOMB_NUM ; k++){
                    if(m_bombs[k].m_free){
                        bombsound->play();
                        m_bombs[k].m_free = false;
                        m_bombs[k].m_x = m_enemys[i].m_x;
                        m_bombs[k].m_y = m_enemys[i].m_y;
                        break;
                    }
                }
                break;

            }
        }
    }
}

void play1::m_collisiondetection()
{//遍历敌机和子弹
    for(int i = 0; i <ENEMY_NUM; i++){
        if(m_enemys[i].m_free){
            continue;
        }
        for(int j = 0; j<BULLETS_NUM; j++){
            if(hero1.m_bullets[j].m_Free){
                continue;
            }//如果重叠
            if(m_enemys[i].m_rect.intersects(hero1.m_bullets[j].m_Rect)){

                hero1.m_bullets[j].m_Free = true;
                m_enemys[i].life--;
                if(m_enemys[i].life > 0){
                   continue;
                }
                m_enemys[i].m_free = true;
                m_enemys[i].life = 30;
                //杀敌数加一
                kill_num++;
                //激活爆炸
                for(int k = 0 ; k<BOMB_NUM ; k++){
                    if(m_bombs[k].m_free){
                        bombsound->play();
                        m_bombs[k].m_free = false;
                        m_bombs[k].m_x = m_enemys[i].m_x;
                        m_bombs[k].m_y = m_enemys[i].m_y;
                        break;
                    }
                }
                break;
            }
        }
    }

}

void play1::r_collisiondetection()
{//遍历敌机和子弹
    for(int i = 0; i <ENEMY_NUM; i++){
        if(m_enemys[i].m_free){
            continue;
        }
        for(int j = 0; j<BULLETS_NUM; j++){
            if(hero1.m_bullets[j].m_Free){
                continue;
            }//如果重叠
            if(m_enemys[i].m_rect.intersects(hero1.r_m_bullets[j].m_Rect)){

                hero1.r_m_bullets[j].m_Free = true;
                m_enemys[i].life--;
                if(m_enemys[i].life > 0){
                     continue;
                }m_enemys[i].m_free = true;
                m_enemys[i].life = 30;
                //杀敌数加一
                kill_num++;
                for(int k = 0 ; k<BOMB_NUM ; k++){
                    if(m_bombs[k].m_free){
                        bombsound->play();
                        m_bombs[k].m_free = false;
                        m_bombs[k].m_x = m_enemys[i].m_x;
                        m_bombs[k].m_y = m_enemys[i].m_y;
                        break;
                    }
                }
                break;
            }
        }
    }

}

void play1::bosscoming()
{    //判断杀敌数
    if(flag == false){
        return;
    }m_recorder++;
    if(m_recorder < BOSS_COME_TIME){
        return;
    }m_boss.m_free = false;

}

void play1::isdie()
{   //遍历敌人
    for(int i = 0;i<ENEMY_NUM;i++){
    if(m_enemys[i].m_free==false){
      if(m_enemys[i].m_rect.intersects(hero1.myRect)){
              QMessageBox::about(NULL,"bye","下次一定…………会赢");
              this->close();
              m_enemys[i].m_free = true;
    }
    }best--;
    if(best > 0){
        return;
    }
    }if(m_boss.m_free==false){
        if(m_boss.m_rect.intersects(hero1.myRect)||head == 1){
            if(index == 0){
            QSound::play(VOICE);
            QMessageBox message(QMessageBox::NoIcon,"嘲讽之音","给你机会你不中用啊");
            message.setIconPixmap(QPixmap(BOSS_PATH));
            message.exec();
            QMessageBox message1(QMessageBox::NoIcon,"机会之音","再给你个机会");
            message1.setIconPixmap(QPixmap(BOSS_PATH));
            message1.exec();
            best = 100;
            index++;
            }else if(index == 1){
                QSound::play(VOICE);
                QMessageBox message2(QMessageBox::NoIcon,"劝告之音","机会就这么多，你得抓住啊");
                message2.setIconPixmap(QPixmap(BOSS_PATH));
                message2.exec();
                index++;
                best = 100;
            }else if(index == 2){
                QSound::play(VOICE);
                QMessageBox message3(QMessageBox::NoIcon,"宽容之音","成，再给你最后一次机会");
                message3.setIconPixmap(QPixmap(BOSS_PATH));
                message3.exec();
                index++;
                best = 100;
            }else if(index == 3){
                QSound::play(VOICE);
                QMessageBox message4(QMessageBox::NoIcon,"无奈之音","你没机会了");
                message4.setIconPixmap(QPixmap(BOSS_PATH));
                message4.exec();
                index++;
                best = 100;
            }else if(index == 4){
                QMessageBox message5(QMessageBox::NoIcon,"结局之音","再见");
                message5.setIconPixmap(QPixmap(BOSS_PATH));
                message5.exec();
                index++;
                best = 100;
                QMessageBox message6(QMessageBox::NoIcon,"终局","你死了，游戏结束");
                message6.setIconPixmap(QPixmap(NEWPLANE));
                message6.exec();
                this->close();
            }head = 0;
        }
    }best2--;
    if(best2>0){
        return;
    }
    if(m_boss.bullet1.m_Free == false){
        if(m_boss.bullet1.m_Rect.intersects(hero1.myRect)){
            index++;
            head = 1;
        }else if(m_boss.bullet2.m_Rect.intersects(hero1.myRect)){
            index++;
            head = 1;
        }best2 = 30;
    }

}

void play1::shootboss()
{
    if(hero1.m_y < 0.7*GAME_HEIGHT-hero1.myPlane.height()){
    for(int j = 0; j<BULLETS_NUM; j++){
        if(hero1.m_bullets[j].m_Free){
            continue;
        }//如果重叠
        if(hero1.m_bullets[j].m_Rect.intersects(m_boss.m_rect)){
            hero1.m_bullets[j].m_Free = true;
            bosslife -- ;
        }break;
    }
    }
}void play1::iswin(){
        if(bosslife == 0){
        QMessageBox::about(this,"凯旋","好吧，你赢了.我不感到悲伤，我只是很遗憾");
        this->close();
        bosslife--;
        }
}

void play1::istime()
{       if(bosslife == 10){
        QMessageBox message8(QMessageBox::NoIcon,"隐藏之音","boss启动了后备隐藏龙头，小心");
        message8.setIconPixmap(QPixmap(BOSS_PATH));
        message8.exec();
        QMessageBox message7(QMessageBox::NoIcon,"乱耳之音","boss残血了，扛过这一击，他就是待宰羔羊！");
        QPixmap pix(WIFE);
        pix = pix.scaled(300,300);
        message7.setIconPixmap(pix);
        message7.exec();
        bosslife--;
        m_boss.bullet1.m_Free = false;
        m_boss.bullet1.m_x = 0;
        m_boss.bullet1.m_y = 0;
        m_boss.bullet2.m_Free = false;
        m_boss.bullet2.m_x = GAME_WIDTH - m_boss.bullet2.m_Bullet.width();
        m_boss.bullet2.m_x = 0; }
}
