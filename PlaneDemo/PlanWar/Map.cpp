#include "Map.h"
#include "Config.h"


Map::Map()
{
	m_map1.load(MAP_PATH);
	m_map2.load(MAP_PATH);

	m_map1_posY = -GAME_HEIGHT;
	m_map2_posY = 0;
	m_scroll_speed = MAP_SCROLL_SPEED;

}


Map::~Map()
{

}

// 通过两张图片同时移动纵坐标达到循环的滚动效果
void Map::UpdatePosition()
{
	//处理第一张图片滚动
	m_map1_posY += MAP_SCROLL_SPEED;
	if (m_map1_posY >= 0)
	{
		m_map1_posY = -GAME_HEIGHT;
	}

	//处理第二张图片滚动
	m_map2_posY += MAP_SCROLL_SPEED;
	if (m_map2_posY >= GAME_HEIGHT)
	{
		m_map2_posY = 0;
	}
}

void Map::PaintPixmap(QPainter& painter)
{
	painter.save();
	painter.drawPixmap(0, m_map1_posY, m_map1);
	painter.drawPixmap(0, m_map2_posY, m_map2);
	painter.restore();
}
