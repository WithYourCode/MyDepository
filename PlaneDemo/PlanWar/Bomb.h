#ifndef __BOMB_H__
#define __BOMB_H__


#include "Item.h"

class Bomb :public Item
{
public:
	Bomb();
	~Bomb();

	virtual void UpdatePosition() override;

	virtual void PaintPixmap(QPainter& painter) override;

public:
	QVector<QPixmap> m_pixmaps;

	// 爆炸时加载的图片的下标
	int m_index;

	// 爆炸切图间隔
	int m_Record = 0;
};

#endif // __BOMB_H__
