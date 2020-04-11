#ifndef __BASE_H__
#define __BASE_H__

#include <QObject>

class Base : public QObject
{
	Q_OBJECT

public:
	enum Direction
	{
		Direction_None = 0,
		Direction_Up,
		Direction_Left,
		Direction_Down,
		Direction_Right
	};

public:
	Base(QObject *ptr_parent = nullptr);
	virtual ~Base();

	Base(int x, int y, Direction dir = Direction_Up);

	//
	void SetX(int x);

	// 
	void SetY(int y);

	// 
	void SetDirection(Direction dir);

	int GetX() const;

	int GetY() const;

	Direction GetDirection() const;

protected:
	int m_x;    // ��Ϸ��Ļ�е�ȫ�����꣨�ǹ�һ����
	int m_y;
	Direction m_direction;
	
};

#endif // __BASE_H__
