#include "Base.h"

Base::Base(QObject *ptr_parent)
	: QObject(ptr_parent)
{

}

Base::Base(int x, int y, Direction dir /*= Direction_Up*/)
	:m_x(x),
	m_y(y),
	m_direction(dir)
{

}

void Base::SetX(int x)
{
	m_x = x;
}


Base::~Base()
{

}

void Base::SetY(int y)
{
	m_y = y;
}

void Base::SetDirection(Direction dir)
{
	m_direction = dir;
}

int Base::GetX() const
{
	return m_x;
}

int Base::GetY() const
{
	return m_y;
}

Base::Direction Base::GetDirection() const
{
	return m_direction;
}

