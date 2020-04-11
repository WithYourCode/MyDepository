#include "EnemyNormal.h"
#include "Configure.h"
#include <QTime>
#include "TankMap.h"

EnemyNormal::EnemyNormal(QObject *ptr_parent)
	: Tank(ptr_parent)
{
	m_moveFlag = true;   // 敌机一直是可以移动的

	m_alive = 1;		 // 初始化生命值

	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));  // 敌机的方向是随机变化的，这里提前撒下种子
}

EnemyNormal::~EnemyNormal()
{

}

void EnemyNormal::InitTank(int xx, int yy, Direction dir, char role)
{
	Tank::InitTank(xx, yy, dir, role);

	// 普通敌机的图标
	m_image_tank = QImage(":/TankWar/Resources/image/enemy/enemyNormal.png"); 

	SetSpeedX(NOAML_TANK_SPEED_X);
	SetSpeedY(NOAML_TANK_SPEED_X);
}


void EnemyNormal::UpdateAllData()
{
	// 当碰触到边界时，即使还在按压键盘，仍然修改掉标志位，停下移动
	if (IsTouchBorder() || IsTouchObject())
	{
		UpdateDirRandom();
		return;
	}

	UpdateXY();

	QPoint p = QPoint((m_x - BORDER_LEFT) / CELL_WIDTH, (m_y - BORDER_UP) / CELL_HEIGHT);
	TankMap::SetBigCell(p.x(), p.y(), m_role);
}

void EnemyNormal::UpdateDirRandom()
{
	int rand = qrand() % 4;
	m_direction = static_cast<Base::Direction>(rand+1);
}
