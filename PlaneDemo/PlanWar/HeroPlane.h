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

	// ����
	virtual void PaintPixmap(QPainter& p) override;

	// �����ӵ�
	void PaintBullet(QPainter& p);

	// �����ƶ���־
	void SetMoveFlag(bool move,Direction dir);

private:
	// �ð���������boolֵ��Ȼ������ᰴ�����Ʒɻ��ƶ���������
	void UpdateHeroPosition();

public:

	// ����
	Bullet m_Bullets[BULLET_NUM];

	// ��������¼
	int m_Recorder;

	bool m_Move = false;

	Direction m_Dir = None;
};


#endif //__HERO_PLANE_H__
