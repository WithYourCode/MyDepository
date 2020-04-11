#include "EnemyNormal.h"
#include "Configure.h"
#include <QTime>
#include "TankMap.h"

EnemyNormal::EnemyNormal(QObject *ptr_parent)
	: Tank(ptr_parent)
{
	m_moveFlag = true;   // �л�һֱ�ǿ����ƶ���

	m_alive = 1;		 // ��ʼ������ֵ

	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));  // �л��ķ���������仯�ģ�������ǰ��������
}

EnemyNormal::~EnemyNormal()
{

}

void EnemyNormal::InitTank(int xx, int yy, Direction dir, char role)
{
	Tank::InitTank(xx, yy, dir, role);

	// ��ͨ�л���ͼ��
	m_image_tank = QImage(":/TankWar/Resources/image/enemy/enemyNormal.png"); 

	SetSpeedX(NOAML_TANK_SPEED_X);
	SetSpeedY(NOAML_TANK_SPEED_X);
}


void EnemyNormal::UpdateAllData()
{
	// ���������߽�ʱ����ʹ���ڰ�ѹ���̣���Ȼ�޸ĵ���־λ��ͣ���ƶ�
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
