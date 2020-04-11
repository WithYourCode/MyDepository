#ifndef PLAYERTANK_H
#define PLAYERTANK_H

#include "Tank.h"

class PlayerTank : public Tank
{
	Q_OBJECT

public:
	PlayerTank(QObject *ptr_parent = nullptr);
	~PlayerTank();

	// 初始化
	virtual void InitTank(int xx, int yy, Direction dir, char role);

	// 重新初始化
	void ReInitPlayer();

private:
	int m_initX;
	int m_initY;
	Direction m_initDir;
	
};

#endif // PLAYERTANK_H
