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
	//�л��������
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		//�ǿ��ел� ��������
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

			// ��ʼ������
			m_Enemys[i].SetX(rand() % (GAME_WIDTH - m_Enemys[i].GetRect().width()));
			m_Enemys[i].SetY(-m_Enemys[i].GetRect().height());
			break;
		}
	}
}

void EnemyManager::PaintEnemyPlane(QPainter& painter)
{
	//���Ƶл�
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
