#include "Tank.h"
#include "Configure.h"
#include <QPoint>
#include "TankMap.h"

Tank::Tank(QObject *ptr_parent)
	: Base(ptr_parent)
{
	m_moveFlag = false;
}

Tank::~Tank()
{

}

void Tank::SetMoveFlag(bool f)
{
	m_moveFlag = f;
}

bool Tank::GetMoveFlag() const
{
	return m_moveFlag;
}

void Tank::SetRole(char r)
{
	m_role = r;
}

char Tank::GetRole() const
{
	return m_role;
}

void Tank::SetSpeedX(int s)
{
	m_speedX = s;
}

int Tank::GetSpeedX() const
{
	return m_speedX;
}

void Tank::SetSpeedY(int s)
{
	m_speedY = s;
}

int Tank::GetSpeedY() const
{
	return m_speedY;
}

void Tank::SetAlive(int a)
{
	m_alive = a;
}

int Tank::GetAlive() const
{
	return m_alive;
}

int Tank::GetAngle() const
{
	switch (m_direction)
	{
	case Base::Direction_Up:    return 0;   break;
	case Base::Direction_Left:  return 270; break;
	case Base::Direction_Down:  return 180; break;
	case Base::Direction_Right: return 90;  break;
	default: return -1; break;
	}
}

bool Tank::IsTouchBorder()
{
	// 这里的边界冲突检测会有微小的像素细调
	switch (m_direction)
	{
	case Base::Direction_Up:
		if (m_y > BORDER_UP)
			return false;
		else
			return true;
	case Base::Direction_Left:
		if (m_x > BORDER_LEFT)
			return false;
		else
			return true;
	case Base::Direction_Down:
		if (m_y + PLAYER_TANK_HEIGHT < BORDER_UP + CELL_HEIGHT*CELL_NUMBER) // 这里对底边的检测做一个微调
			return false;
		else
			return true;
	case Base::Direction_Right:
		if (m_x + PLAYER_TANK_WIDTH < BORDER_LEFT + CELL_WIDTH*CELL_NUMBER)
			return false;
		else
			return true;
	default:
		return true;
		break;

		return true;
	}
}

bool Tank::IsTouchObjectPart(int x, int y)
{
	int smallX = CELL_WIDTH * 2;     //20
	int smallY = CELL_HEIGHT * 2;    //16

	int bigX = CELL_WIDTH * 4;		 //40
	int bigY = CELL_HEIGHT * 4;		 //32

	int biggerX = CELL_WIDTH * 8;    //40
	int biggerY = CELL_HEIGHT * 8;   //32

	if (TankMap::GetMap(x / smallX*2, y / smallY*2) == 'W'
		|| TankMap::GetMap(x / smallX * 2, y / smallY * 2) == 'V'
		|| TankMap::GetMap(x / bigX*4, y / bigY*4) == 'I'
		|| TankMap::GetMap(x / biggerX*8, y / biggerY*8) == 'B'
		|| TankMap::GetMap(x / biggerX * 8, y / biggerY*8) == 'R'
		|| 
			(
			((TankMap::GetMap(x / CELL_WIDTH, y / CELL_HEIGHT) >= '0' && TankMap::GetMap(x / CELL_WIDTH, y / CELL_HEIGHT) <= '9') ||
			(TankMap::GetMap(x / CELL_WIDTH, y / CELL_HEIGHT) == 'P' || TankMap::GetMap(x / CELL_WIDTH, y / CELL_HEIGHT) == 'Q')) &&
			TankMap::GetMap(x / CELL_WIDTH, y / CELL_HEIGHT) != GetRole()
			)
		)
		
	{
		return true;
	}
	else
		return false;
}

bool Tank::IsTouchObject()
{
	// 这里的计算我也不懂
	int x1 = m_x - BORDER_LEFT;
	int y1 = m_y - BORDER_UP;
	int x2 = m_x - BORDER_LEFT + PLAYER_TANK_WIDTH - 2;
	int y2 = m_y - BORDER_UP + PLAYER_TANK_HEIGHT - 2;

	//
	switch (m_direction)
	{
	case Base::Direction_Up:
	{
		if (IsTouchObjectPart(x1, (y1 - m_speedY))
			|| IsTouchObjectPart(x2, (y1 - m_speedY))
			|| IsTouchObjectPart((x1 + 40), (y1 - m_speedY))
			|| IsTouchObjectPart((x1 + 20), (y1 - m_speedY))
			|| IsTouchObjectPart((x1 + 60), (y1 - m_speedY)))
			return true;
		else
			return false;
	}
	case Base::Direction_Left:
	{
		if (IsTouchObjectPart((x1 - m_speedX), y1)
			|| IsTouchObjectPart((x1 - m_speedX), y2)
			|| IsTouchObjectPart((x1 - m_speedX), (y1 + 32))
			|| IsTouchObjectPart((x1 - m_speedX), (y1 + 16))
			|| IsTouchObjectPart((x1 - m_speedX), (y1 + 48)))
			return true;
		else
			return false;
	}
	case Base::Direction_Down:
	{
		if (IsTouchObjectPart(x1, (y2 + m_speedY)) 
			|| IsTouchObjectPart(x2, (y2 + m_speedY))
			|| IsTouchObjectPart((x1 + 20), (y2 + m_speedY))
			|| IsTouchObjectPart((x1 + 40), (y2 + m_speedY))
			|| IsTouchObjectPart((x1 + 60), (y2 + m_speedY)))
			return true;
		else
			return false;
	}
	case Base::Direction_Right:
	{
		if (IsTouchObjectPart((x2 + m_speedX), y1) 
			|| IsTouchObjectPart((x2 + m_speedX), y2)
			|| IsTouchObjectPart((x2 + m_speedX), (y1 + 32))
			|| IsTouchObjectPart((x2 + m_speedX), (y1 + 16))
			|| IsTouchObjectPart((x2 + m_speedX), (y1 + 48)))
			return true;
	}
	default:
		return false;
	}
	
}

void Tank::UpdateTankPositionOnMap()
{
	// 当碰触到边界时，即使还在按压键盘，仍然修改掉标志位，停下移动
	if (IsTouchBorder() || IsTouchObject())
	{
		m_moveFlag = false;
		return;
	}

	UpdateXY();

	QPoint p = QPoint((m_x - BORDER_LEFT) / CELL_WIDTH , (m_y - BORDER_UP) / CELL_HEIGHT);

	TankMap::SetBigCell(p.x(), p.y(), m_role);
}

void Tank::UpdateXY()
{
	if (!m_moveFlag)
		return;

	switch (m_direction)
	{
	case Base::Direction_Up:
		m_y -= m_speedY;
		break;
	case Base::Direction_Down:
		m_y += m_speedY;
		break;
	case Base::Direction_Left:
		m_x -= m_speedX;
		break;
	case Base::Direction_Right:
		m_x += m_speedX;
		break;
	default:
		break;
	}
}

void Tank::PaintTank(QPainter& painter)
{
	if (m_alive > 0)
	{
		// 根据方向获取旋转的角度来旋转图片
		QMatrix matrix;
		matrix.rotate(GetAngle());
		QImage i = m_image_tank.transformed(matrix).scaled(PLAYER_TANK_WIDTH, PLAYER_TANK_HEIGHT);
		painter.drawImage(m_x, m_y, i);
	}
}

void Tank::UpdateAllData()
{
	UpdateTankPositionOnMap();
}

void Tank::InitTank(int xx, int yy, Direction dir, char role)
{
	//位置
	m_x = BORDER_LEFT + xx * CELL_WIDTH;
	m_y = BORDER_UP + yy * CELL_HEIGHT;
	m_direction = dir;

	//确定角色
	TankMap::SetBigCell(xx, yy, role);
	SetRole(role);
}
