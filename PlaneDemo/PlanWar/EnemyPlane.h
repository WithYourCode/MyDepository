#ifndef __ENEMYPLANE_H__
#define __ENEMYPLANE_H__

#include "Item.h"

class EnemyPlane : public Item
{
public:
	EnemyPlane();
	~EnemyPlane();

	virtual void UpdatePosition() override;

	virtual void PaintPixmap(QPainter& p) override;


};

#endif // __ENEMYPLANE_H__
