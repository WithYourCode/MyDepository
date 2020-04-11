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

	// ��ըʱ���ص�ͼƬ���±�
	int m_index;

	// ��ը��ͼ���
	int m_Record = 0;
};

#endif // __BOMB_H__
