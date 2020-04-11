#include "PlayerTank.h"
#include "Configure.h"
#include "TankMap.h"
#include <QImage>

PlayerTank::PlayerTank(QObject *ptr_parent)
	: Tank(ptr_parent)
{
	m_alive = 1;

	m_initX = 0;
	m_initY = 0;
	m_initDir = Direction_Up;
}

PlayerTank::~PlayerTank()
{

}

void PlayerTank::InitTank(int xx, int yy, Direction dir, char role)
{
	// parent
	Tank::InitTank(xx, yy, dir, role);

	// myself
	SetSpeedX(PLAYER_TANK_SPEED_X);
	SetSpeedY(PLAYER_TANK_SPEED_Y);

	m_initX = m_x;
	m_initY = m_y;
	m_initDir = m_direction;
	m_image_tank = QImage(":/TankWar/Resources/image/player/p1tankNormal_U1.png");
}

void PlayerTank::ReInitPlayer()
{

}


