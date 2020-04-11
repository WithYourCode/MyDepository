#include "Bullet.h"



Bullet::Bullet()
{
	m_Item.load(BULLET_PATH);

	//�ӵ����� ��ʼ������������ã����ڻ�����
	m_X = GAME_WIDTH*0.5 - m_Item.width()*0.5;
	m_Y = GAME_HEIGHT;

	//�ӵ�״̬
	m_Free = true;

	//�ӵ��ٶ�
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
