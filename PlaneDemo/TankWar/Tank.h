#ifndef TANK_H
#define TANK_H

#include "Base.h"
#include <QPainter>

class Tank : public Base
{
	Q_OBJECT

public:
	Tank(QObject *ptr_parent=nullptr);
	~Tank();

	// 初始化坦克信息
	virtual void InitTank(int xx, int yy, Direction dir, char role);

	// 绘制坦克
	virtual void PaintTank(QPainter& painter);

	// 更新全部的信息
	virtual void UpdateAllData();

	void SetMoveFlag(bool f);
	bool GetMoveFlag() const;

	void SetRole(char r);
	char GetRole() const;

	void SetSpeedX(int s);
	int GetSpeedX() const;

	void SetSpeedY(int s);
	int GetSpeedY() const;

	void SetAlive(int a);
	int GetAlive() const;

	// 获取图片旋转的角度
	int GetAngle() const;

protected:

	// 边界冲突检测
	bool IsTouchBorder();

	// 
	bool IsTouchObjectPart(int x, int y);

	// 
	bool IsTouchObject();

	// 更新坦克在地图上的位置
	void UpdateTankPositionOnMap();

	// 更新横纵坐标信息
	void UpdateXY();





protected:
	QImage m_image_tank;    // 坦克的图片
	bool m_moveFlag;		// 是否可以移动
	char m_role;			// 角色
	int m_speedX;			// 横向移动速度
	int m_speedY;			// 纵向移动速度
	int m_alive;			// 坦克生命值
	
};

#endif // TANK_H
