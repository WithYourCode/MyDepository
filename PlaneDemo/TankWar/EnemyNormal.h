#ifndef ENEMYNORMAL_H
#define ENEMYNORMAL_H

/*
��ͨ����
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

	// ����̹�˵ķ����������
	void UpdateDirRandom();

private:
	
};

#endif // ENEMYNORMAL_H
