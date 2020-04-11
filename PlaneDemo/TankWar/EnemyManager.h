#ifndef __ENEMY_MANAGER_H__
#define __ENEMY_MANAGER_H__

#include <QObject>
#include <QPointer>
#include <QTimer>
#include "EnemyNormal.h"

class EnemyManager : public QObject
{
	Q_OBJECT

public:
	EnemyManager(QObject *parent);
	~EnemyManager();

	// 敌机坦克出场
	void EnemyTanksToScene();

	// 透传绘制坦克
	void PaintEnemyTanks(QPainter& painter);

	// 更新坦克信息
	void UpdateEnemyTanksData();

	// 更新坦克的方向信息
	void UpdateTanksDir();

private:

	QVector<QPointer<EnemyNormal>> m_nomal_tanks;

	QTimer m_timer;
};

#endif //__ENEMY_MANAGER_H__
