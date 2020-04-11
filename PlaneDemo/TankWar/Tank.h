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

	// ��ʼ��̹����Ϣ
	virtual void InitTank(int xx, int yy, Direction dir, char role);

	// ����̹��
	virtual void PaintTank(QPainter& painter);

	// ����ȫ������Ϣ
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

	// ��ȡͼƬ��ת�ĽǶ�
	int GetAngle() const;

protected:

	// �߽��ͻ���
	bool IsTouchBorder();

	// 
	bool IsTouchObjectPart(int x, int y);

	// 
	bool IsTouchObject();

	// ����̹���ڵ�ͼ�ϵ�λ��
	void UpdateTankPositionOnMap();

	// ���º���������Ϣ
	void UpdateXY();





protected:
	QImage m_image_tank;    // ̹�˵�ͼƬ
	bool m_moveFlag;		// �Ƿ�����ƶ�
	char m_role;			// ��ɫ
	int m_speedX;			// �����ƶ��ٶ�
	int m_speedY;			// �����ƶ��ٶ�
	int m_alive;			// ̹������ֵ
	
};

#endif // TANK_H
