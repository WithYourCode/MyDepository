#include "EnemyManager.h"
#include <QPainter>


EnemyManager::EnemyManager()
{

}


EnemyManager::~EnemyManager()
{
}

void EnemyManager::UpdateAllEnemyPosition()
{
	//敌机坐标计算
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//非空闲敌机 更新坐标
		if (m_Enemys[i].GetIsFree() == false)
		{
			m_Enemys[i].UpdatePosition();
		}
	}
}

void EnemyManager::EnemyToScene()
{
	m_EnemyRecord++;

	if (m_EnemyRecord < ENEMY_INTERVAL)
		return;

	m_EnemyRecord = 0;

	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (m_Enemys[i].GetIsFree())
		{
			m_Enemys[i].SetFree(false);

			// 初始化坐标
			m_Enemys[i].SetX(rand() % (GAME_WIDTH - m_Enemys[i].GetRect().width()));
			m_Enemys[i].SetY(-m_Enemys[i].GetRect().height());
			break;
		}
	}
}

void EnemyManager::PaintEnemyPlane(QPainter& painter)
{
	//绘制敌机
	painter.save();
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (m_Enemys[i].GetIsFree() == false)
		{
			m_Enemys[i].PaintPixmap(painter);
		}
	}
	painter.restore();
}

EnemyPlane* EnemyManager::GetAllEnemy()
{
	return m_Enemys;
}
