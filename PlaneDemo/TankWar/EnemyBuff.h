#ifndef ENEMYBUFF_H
#define ENEMYBUFF_H

#include "Tank.h"

class EnemyBuff : public Tank
{
	Q_OBJECT

public:
	EnemyBuff(QObject *ptr_parent);
	~EnemyBuff();

private:
	
};

#endif // ENEMYBUFF_H
