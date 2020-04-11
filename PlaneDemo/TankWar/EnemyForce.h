#ifndef ENEMYFORCE_H
#define ENEMYFORCE_H

#include "Tank.h"

class EnemyForce : public Tank
{
	Q_OBJECT

public:
	EnemyForce(QObject *ptr_parent);
	~EnemyForce();

private:
	
};

#endif // ENEMYFORCE_H
