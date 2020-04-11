#ifndef __ENEMYMANAGER_H__
#define __ENEMYMANAGER_H__

#include "Config.h"
#include "EnemyPlane.h"

// 封装一层敌机管理类

class EnemyManager
{
public:
	EnemyManager();
	virtual ~EnemyManager();

	// 更新全部敌机的位置
	void UpdateAllEnemyPosition();

	// 敌机出场
	void EnemyToScene();

	// 绘制全部的敌机
	void PaintEnemyPlane(QPainter& painter);

	// 返回全部的敌机数据
	EnemyPlane* GetAllEnemy();

private:
	EnemyPlane m_Enemys[ENEMY_NUM];

	int m_EnemyRecord = 0;

};

#endif //__ENEMYMANAGER_H__
