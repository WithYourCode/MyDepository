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

	// �л�̹�˳���
	void EnemyTanksToScene();

	// ͸������̹��
	void PaintEnemyTanks(QPainter& painter);

	// ����̹����Ϣ
	void UpdateEnemyTanksData();

	// ����̹�˵ķ�����Ϣ
	void UpdateTanksDir();

private:

	QVector<QPointer<EnemyNormal>> m_nomal_tanks;

	QTimer m_timer;
};

#endif //__ENEMY_MANAGER_H__
