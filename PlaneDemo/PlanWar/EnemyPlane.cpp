#include "EnemyPlane.h"
#include "Config.h"


EnemyPlane::EnemyPlane()
{
	m_Item.load(ENEMY_PLANE_PATH);

	m_X = 0;
	m_Y = 0;
	m_Free = true;
	m_Speed = ENEMY_SPEED;

	m_Rect.setRect(m_X, m_Y, m_Item.width(), m_Item.height());
}


EnemyPlane::~EnemyPlane()
{
}

void EnemyPlane::UpdatePosition()
{
	//¿ÕÏÐ×´Ì¬£¬²»¼ÆËã×ø±ê
	if (m_Free)
	{
		return;
	}

	m_Y += m_Speed;
	m_Rect.moveTo(m_X, m_Y);

	// ³¬³öÁËÆÁÄ»£¬ÏûÊ§
	if (m_Y >= GAME_HEIGHT + m_Rect.height())
	{
		m_Free = true;
	}
}

void EnemyPlane::PaintPixmap(QPainter& painter)
{
	painter.drawPixmap(m_X, m_Y, m_Item);

}
