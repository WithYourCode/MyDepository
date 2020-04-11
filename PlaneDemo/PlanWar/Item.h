#ifndef __ITEM_H__ 
#define __ITEM_H__

#include <QPixmap>
#include <QPainter>

class Item
{
public:
	Item();
	virtual ~Item();

	// 位置更新
	virtual void UpdatePosition() = 0;

	// 绘制自身
	virtual void PaintPixmap(QPainter& p) = 0 ;

	// 获取X
	int GetX() const;

	// 获取Y
	int GetY() const;

	// 获取势力范围
	QRect GetRect() const;

	// 获取元素是否空闲
	bool GetIsFree() const;

	// 设置X坐标
	void SetX(int x);

	// 设置Y坐标
	void SetY(int y);

	// 设置可用性
	void SetFree(bool free);

protected:
	QPixmap m_Item;  // 元素的图片

	int m_X;		 // 元素的横坐标
	int m_Y;		 // 元素的纵坐标

	int m_Speed;     // 元素的移动速度

	QRect m_Rect;	 // 元素的势力范围

	bool m_Free;	 // 元素当前的使用状态
};

#endif // __ITEM_H__
