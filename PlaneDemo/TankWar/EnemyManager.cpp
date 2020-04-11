#include "EnemyManager.h"
#include "Configure.h"

EnemyManager::EnemyManager(QObject *parent)
	: QObject(parent)
{
	m_timer.setInterval(EENEMY_INTERVAL);
	connect(&m_timer, &QTimer::timeout, this, [=]() {
		UpdateTanksDir();
	});

	
	
}

EnemyManager::~EnemyManager()
{

}

void EnemyManager::EnemyTanksToScene()
{
	//m_timer.start();
	for (int i = 0; i < NOMAL_TANK_NUM; ++i)
	{
		QPointer<EnemyNormal> nomal_tank = new EnemyNormal(this);
		nomal_tank->InitTank(i, i, Base::Direction_Down, '1');  // 1为普通敌人
		m_nomal_tanks.push_back(nomal_tank);
	}
}

void EnemyManager::UpdateEnemyTanksData()
{
	for (auto& item : m_nomal_tanks)
	{
		if (!item.isNull())
			item->UpdateAllData();
	}
}

void EnemyManager::UpdateTanksDir()
{
	for (auto& item : m_nomal_tanks)
	{
		if (!item.isNull())
			item->UpdateDirRandom();
	}
}

void EnemyManager::PaintEnemyTanks(QPainter& painter)
{
	// 绘制普通坦克
	for(auto& item : m_nomal_tanks)
	{
		if (!item.isNull())
			item->PaintTank(painter);
	}
}
