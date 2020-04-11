#include "HeroPlane.h"


HeroPlane::HeroPlane()
{
	m_Item.load(HERO_PATH);

	// 飞机的初始位置在地图的正下方
	m_X = GAME_WIDTH*0.5 - m_Item.width()*0.5;
	m_Y = GAME_HEIGHT - m_Item.height();

	m_Rect.setRect(m_X, m_Y, m_Item.width(), m_Item.height());

	m_Recorder = 0;
}


HeroPlane::~HeroPlane()
{
}

void HeroPlane::Shoot()
{
	m_Recorder++;

	if (m_Recorder < BULLET_INTERVAL)
	{
		return;
	}

	m_Recorder = 0;

	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (m_Bullets[i].GetIsFree())
		{
			m_Bullets[i].SetFree(false);

			// 设置发射子弹的初始坐标
			m_Bullets[i].SetX(m_X + m_Rect.width()*0.5 - 10);
			m_Bullets[i].SetY(m_Y - 25);
			break;
		}
	}

}

void HeroPlane::UpdateHeroPosition()
{
	if (!m_Move)
		return;

	int x = m_X;
	int y = m_Y;

	switch (m_Dir)
	{
	case HeroPlane::Up:
		y -= HERO_MOVE_STEP;;
		break;
	case HeroPlane::Down:
		y += HERO_MOVE_STEP;
		break;
	case HeroPlane::Left:
		x -= HERO_MOVE_STEP;
		break;
	case HeroPlane::Right:
		x += HERO_MOVE_STEP;
		break;
	default:
		break;
	}

	//边界检测
	if (x <= 0)
	{
		x = 0;
	}
	if (x >= GAME_WIDTH - m_Rect.width())
	{
		x = GAME_WIDTH - m_Rect.width();
	}
	if (y <= 0)
	{
		y = 0;
	}
	if (y >= GAME_HEIGHT - m_Rect.height())
	{
		y = GAME_HEIGHT - m_Rect.height();
	}
	m_X = x;
	m_Y = y;
	m_Rect.moveTo(m_X, m_Y);
}

void HeroPlane::UpdatePosition()
{
	//计算子弹坐标
	for (int i = 0; i < BULLET_NUM; i++)
	{
		//如果子弹状态为非空闲，计算发射位置
		if (!m_Bullets[i].GetIsFree())
		{
			m_Bullets[i].UpdatePosition();
		}
	}

	// 更新飞机的位置
	UpdateHeroPosition();
}

void HeroPlane::PaintPixmap(QPainter& painter)
{
	painter.save();
	painter.drawPixmap(m_X, m_Y,m_Item);
	painter.restore();
}

void HeroPlane::PaintBullet(QPainter& painter)
{
	painter.save();
	for (int i = 0; i < BULLET_NUM; i++)
	{
		//如果子弹状态为非空闲，计算发射位置
		m_Bullets[i].PaintPixmap(painter);
	}
	painter.restore();
}

void HeroPlane::SetMoveFlag(bool move, Direction dir)
{
	m_Move = move;
	m_Dir = dir;
}


