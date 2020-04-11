#ifndef __HERO_PLANE_H__
#define __HERO_PLANE_H__

#include "Bullet.h"
#include "Config.h"
#include "Item.h"


class HeroPlane : public Item
{

public:
	enum Direction
	{
		None = 0,
		Up ,
		Down ,
		Left ,
		Right ,
	};

public:
	HeroPlane();
	~HeroPlane();

	void Shoot();

	virtual void UpdatePosition() override;

	// 绘制
	virtual void PaintPixmap(QPainter& p) override;

	// 绘制子弹
	void PaintBullet(QPainter& p);

	// 设置移动标志
	void SetMoveFlag(bool move,Direction dir);

private:
	// 用按键来设置bool值，然后可以提按键控制飞机移动的灵敏度
	void UpdateHeroPosition();

public:

	// 弹夹
	Bullet m_Bullets[BULLET_NUM];

	// 发射间隔记录
	int m_Recorder;

	bool m_Move = false;

	Direction m_Dir = None;
};


#endif //__HERO_PLANE_H__
