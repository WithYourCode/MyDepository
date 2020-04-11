#include "Item.h"



Item::Item()
{

}


Item::~Item()
{

}

int Item::GetX() const 
{
	return m_X;
}

int Item::GetY() const
{
	return m_Y;
}

QRect Item::GetRect() const
{
	return m_Rect;
}

bool Item::GetIsFree() const
{
	return m_Free;
}

void Item::SetX(int x)
{
	m_X = x;
}

void Item::SetY(int y)
{
	m_Y = y;
}

void Item::SetFree(bool free)
{
	m_Free = free;
}
