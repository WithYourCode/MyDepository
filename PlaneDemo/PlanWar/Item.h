#ifndef __ITEM_H__ 
#define __ITEM_H__

#include <QPixmap>
#include <QPainter>

class Item
{
public:
	Item();
	virtual ~Item();

	// λ�ø���
	virtual void UpdatePosition() = 0;

	// ��������
	virtual void PaintPixmap(QPainter& p) = 0 ;

	// ��ȡX
	int GetX() const;

	// ��ȡY
	int GetY() const;

	// ��ȡ������Χ
	QRect GetRect() const;

	// ��ȡԪ���Ƿ����
	bool GetIsFree() const;

	// ����X����
	void SetX(int x);

	// ����Y����
	void SetY(int y);

	// ���ÿ�����
	void SetFree(bool free);

protected:
	QPixmap m_Item;  // Ԫ�ص�ͼƬ

	int m_X;		 // Ԫ�صĺ�����
	int m_Y;		 // Ԫ�ص�������

	int m_Speed;     // Ԫ�ص��ƶ��ٶ�

	QRect m_Rect;	 // Ԫ�ص�������Χ

	bool m_Free;	 // Ԫ�ص�ǰ��ʹ��״̬
};

#endif // __ITEM_H__
