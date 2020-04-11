#ifndef __BULLET_H__
#define __BULLET_H__

#include <QPixmap>
#include "Config.h"
#include "Item.h"


class Bullet : public Item
{
public:
	Bullet();
	~Bullet();

	virtual void UpdatePosition() override;

	// »æÖÆ
	virtual void PaintPixmap(QPainter& painter) override;

public:


};

#endif //__BULLET_H__
