#ifndef ENEMYNORMAL_H
#define ENEMYNORMAL_H

/*
普通敌人
*/

#include "Tank.h"

class EnemyNormal : public Tank
{
	Q_OBJECT

public:
	EnemyNormal(QObject *ptr_parent);
	~EnemyNormal();

	virtual void InitTank(int xx, int yy, Direction dir, char role) override;

	virtual void UpdateAllData() override;

	// 敌人坦克的方向随机更新
	void UpdateDirRandom();

private:
	
};

#endif // ENEMYNORMAL_H
