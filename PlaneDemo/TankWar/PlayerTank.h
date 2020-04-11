#ifndef PLAYERTANK_H
#define PLAYERTANK_H

#include "Tank.h"

class PlayerTank : public Tank
{
	Q_OBJECT

public:
	PlayerTank(QObject *ptr_parent = nullptr);
	~PlayerTank();

	// ��ʼ��
	virtual void InitTank(int xx, int yy, Direction dir, char role);

	// ���³�ʼ��
	void ReInitPlayer();

private:
	int m_initX;
	int m_initY;
	Direction m_initDir;
	
};

#endif // PLAYERTANK_H
