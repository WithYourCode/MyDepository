#ifndef __CONFIG_H__
#define __CONFIG_H__

#define GAME_WIDTH 512
#define GAME_HEIGHT 768
#define GAME_TITLE "Plan War v1.0"

#define GAME_ICON ":/image/Resources/app.ico"

#define MAP_PATH ":/image/Resources/img_bg_level_1.jpg"

#define MAP_SCROLL_SPEED 1

#define GAME_RATE 10   // ˢ�¼����֡��

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

#define BOMB_PATH  ":/image/Resources/bomb-%1.png"   //��ը��ԴͼƬ
#define BOMB_NUM  20     //��ը����
#define BOMB_MAX  7      //��ըͼƬ�������
#define BOMB_INTERVAL 20   //��ը��ͼʱ����

#define SOUND_BACKGROUND  ":/sound/Resources/bg.wav"
#define SOUND_BOMB ":/sound/Resources/bomb.wav"

#define GAME_RES_PATH "./sound.rcc"
#define GAME_RES_PATH1 "./plane.rcc"

#define SOUND_LOOP_VALUE 10

// ���qrc�ļ����󣨰��������ļ������ڱ���ʱ����qrc�ᵼ�±���ռ䲻�������
// �����Ҫʹ��qt��rcc�����qrcת���ɶ����Ƶ�rcc�ļ����ڳ�������ʱ�������ڴ���
// rcc -binary Resource.qrc -o plane.rcc
// Ȼ��rcc�ļ����ڴ��뼶Ŀ¼��ͨ��QResource::registerResource(GAME_RES_PATH1)
// ����Ŀ¼��Դ��Դ·����������ġ�
















#endif // __CONFIG_H__

