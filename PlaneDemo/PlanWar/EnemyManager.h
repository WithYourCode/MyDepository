#ifndef __ENEMYMANAGER_H__
#define __ENEMYMANAGER_H__

#include "Config.h"
#include "EnemyPlane.h"

// ��װһ��л�������

class EnemyManager
{
public:
	EnemyManager();
	virtual ~EnemyManager();

	// ����ȫ���л���λ��
	void UpdateAllEnemyPosition();

	// �л�����
	void EnemyToScene();

	// ����ȫ���ĵл�
	void PaintEnemyPlane(QPainter& painter);

	// ����ȫ���ĵл�����
	EnemyPlane* GetAllEnemy();

private:
	EnemyPlane m_Enemys[ENEMY_NUM];

	int m_EnemyRecord = 0;

};

#endif //__ENEMYMANAGER_H__
