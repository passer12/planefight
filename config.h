#ifndef CONFIG_H
#define CONFIG_H
//游戏配置文件//
#define GAME_HEIGHT 768
#define GAME_WIDTH 512
#define GAME_TITLE "hitplane1.0"  //游戏名称
#define GAME_RCC_PATH "./res.rcc"  //RCC文件位置
#define GAME_WINDOW_ICON ":/res/app.ico"    //窗口图标路径
#define GAME_RATE 10 //刷新时间
#define HERO_PATH ":/res/hero2.png" //飞机路径

//地图配置
#define MAP_PATH ":/res/img_bg_level_1.jpg" //地图路径
#define MAP_SCROLL_SPEED 2

//子弹配置
#define BULLET_SPEED 4//子弹移动速度
#define BULLET_PATH  ":/res/bullet_12.png" //子弹图片路径
#define BULLETS_NUM 15 //弹匣中子弹个数
#define BULLET_INTERVAL 30 //子弹发射间隔
#define BULLET_MIDDLE_PATH ":/res/bullet_11.png" //设置中间的特殊子弹

//敌机设置
#define ENEMY_PATH ":/res/img-plane_4.png" //敌机资源路径
#define ENEMY_SPEED 4 //敌机速度
#define ENEMY_NUM 20  //敌机数量
#define ENEMY_INTERVAL 50 //敌机出场间隔

//爆炸设置
#define BOMB_PATH ":/res/bomb-%1.png" //爆炸图片
#define BOMB_NUM 20 //爆炸数量
#define BOMB_MAX 7 //爆炸图片最大索引
#define BOMB_INTERVAL 20 //爆炸切图时间间隔

//音效配置数据
#define BOMB_SOUND ":/res/bomb.wav" //爆炸音效


#endif // CONFIG_H
