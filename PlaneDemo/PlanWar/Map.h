#ifndef __MAP_H__
#define __MAP_H__

#include <QPixmap>
#include "Item.h"


class Map : public Item
{
public:
	Map();
	virtual ~Map();

	// ����λ��
	virtual void UpdatePosition() override;

	// ����
	virtual void PaintPixmap(QPainter& p) override;

public:
	QPixmap m_map1;
	QPixmap m_map2;

	int m_map1_posY;
	int m_map2_posY;

	int m_scroll_speed;
};


#endif // __MAP_H__
