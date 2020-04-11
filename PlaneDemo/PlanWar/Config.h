#ifndef __CONFIG_H__
#define __CONFIG_H__

#define GAME_WIDTH 512
#define GAME_HEIGHT 768
#define GAME_TITLE "Plan War v1.0"

#define GAME_ICON ":/image/Resources/app.ico"

#define MAP_PATH ":/image/Resources/img_bg_level_1.jpg"

#define MAP_SCROLL_SPEED 1

#define GAME_RATE 10   // 刷新间隔，帧率

#define HERO_PATH ":/image/Resources/hero2.png"

#define HERO_MOVE_STEP 8

#define BULLET_PATH ":/image/Resources/bullet_11.png"

#define BULLET_SPEED 3

#define BULLET_NUM 30
#define BULLET_INTERVAL 1

#define ENEMY_PLANE_PATH ":/image/Resources/img-plane_5.png"
#define ENEMY_SPEED 5
#define ENEMY_NUM 20
#define ENEMY_INTERVAL 50

#define BOMB_PATH  ":/image/Resources/bomb-%1.png"   //爆炸资源图片
#define BOMB_NUM  20     //爆炸数量
#define BOMB_MAX  7      //爆炸图片最大索引
#define BOMB_INTERVAL 20   //爆炸切图时间间隔

#define SOUND_BACKGROUND  ":/sound/Resources/bg.wav"
#define SOUND_BOMB ":/sound/Resources/bomb.wav"

#define GAME_RES_PATH "./sound.rcc"
#define GAME_RES_PATH1 "./plane.rcc"

#define SOUND_LOOP_VALUE 10

// 如果qrc文件过大（包含声音文件），在编译时加载qrc会导致编译空间不足的问题
// 因此需要使用qt的rcc命令，将qrc转换成二进制的rcc文件，在程序运行时再载入内存中
// rcc -binary Resource.qrc -o plane.rcc
// 然后将rcc文件放在代码级目录，通过QResource::registerResource(GAME_RES_PATH1)
// 加载目录，源资源路径几乎不变的。
















#endif // __CONFIG_H__

