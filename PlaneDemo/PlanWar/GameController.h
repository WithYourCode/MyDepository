#ifndef __GAME_CONTREOLLER__
#define __GAME_CONTREOLLER__

#include <QTimer>
#include <QSound>
#include <QKeyEvent>
#include <QObject>
#include <QMouseEvent>
#include "Map.h"
#include "HeroPlane.h"
#include "Bullet.h"
#include "EnemyPlane.h"
#include "Bomb.h"
#include "EnemyManager.h"


class GameController : public QObject
{
	Q_OBJECT

public:
	GameController(QObject* ptr_parent = nullptr);
	virtual ~GameController();

	// 开始游戏
	void StartGame();

	// 处理界面层的键盘事件
	void HandleKeyEvent(QKeyEvent* event);

	// 处理鼠标移动事件
	void HandleMouseEvent(QMouseEvent* event);

	// 处理渲染事件
	void HandlePaintEvent(QPainter& painter);

	// 处理按键松开事件
	void HandleKeyRealseEvent(QKeyEvent* event);

private:
	
	 // 初始化
	void InitController();

	// 更新全部item
	void UpdateAllItem();

	// 冲突检测
	void CollisionDetection();

signals:

	// 刷新信号
	void SignalUpdateUi();

private:
	QTimer m_Timer;

	Map m_Map;

	HeroPlane m_HeroPlane;

	EnemyManager m_EnemyManager;

	Bomb m_Bombs[BOMB_NUM];

	QSound* pSound = nullptr;
};

#endif //__GAME_CONTREOLLER__
