#include "Bomb.h"
#include "Config.h"


Bomb::Bomb()
{
	// 初始化爆炸图片
	for (int i = 0; i < BOMB_MAX; i++)
	{
		QString str = QString(BOMB_PATH).arg(i);
		m_pixmaps.push_back(QPixmap(str));
	}

	m_X = 0;
	m_Y = 0;
	m_Free = true;
	m_index = 0;
}


Bomb::~Bomb()
{
}

void Bomb::UpdatePosition()
{
	//空闲状态
	if (m_Free)
		return;

	m_Record++;
	if (m_Record < BOMB_INTERVAL)
	{
		//记录爆炸间隔未到，直接return，不需要切图
		return;
	}
	//重置记录
	m_Record = 0;

	//切换爆炸播放图片
	m_index++;
	//注：数组中的下标从0开始，最大是6
	//如果计算的下标大于6，重置为0
	if (m_index > BOMB_MAX - 1)
	{
		m_index = 0;
		m_Free = true;
	}
}

void Bomb::PaintPixmap(QPainter& painter)
{
	if (m_Free == false)
	{
		painter.drawPixmap(m_X, m_Y, m_pixmaps[m_index]);
	}
}
