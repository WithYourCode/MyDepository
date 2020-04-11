#ifndef __MAP_H__
#define __MAP_H__

#include <QPixmap>
#include "Item.h"


class Map : public Item
{
public:
	Map();
	virtual ~Map();

	// 更新位置
	virtual void UpdatePosition() override;

	// 绘制
	virtual void PaintPixmap(QPainter& p) override;

public:
	QPixmap m_map1;
	QPixmap m_map2;

	int m_map1_posY;
	int m_map2_posY;

	int m_scroll_speed;
};


#endif // __MAP_H__
