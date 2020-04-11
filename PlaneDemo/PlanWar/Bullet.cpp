#include "Bullet.h"



Bullet::Bullet()
{
	m_Item.load(BULLET_PATH);

	//子弹坐标 初始坐标可随意设置，后期会重置
	m_X = GAME_WIDTH*0.5 - m_Item.width()*0.5;
	m_Y = GAME_HEIGHT;

	//子弹状态
	m_Free = true;

	//子弹速度
	m_Speed = BULLET_SPEED;

	m_Rect.setRect(m_X, m_Y, m_Item.width(), m_Item.height());
}


Bullet::~Bullet()
{
}

void Bullet::UpdatePosition()
{
	if (m_Free)
		return;

	m_Y -= m_Speed;
	m_Rect.moveTo(m_X, m_Y);

	if (m_Y <= -m_Rect.height())
		m_Free = true;
}

void Bullet::PaintPixmap(QPainter& painter)
{
	if (!m_Free)
		painter.drawPixmap(m_X, m_Y, m_Item);
}
