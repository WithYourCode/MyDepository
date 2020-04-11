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

	// ��ʼ��Ϸ
	void StartGame();

	// ��������ļ����¼�
	void HandleKeyEvent(QKeyEvent* event);

	// ��������ƶ��¼�
	void HandleMouseEvent(QMouseEvent* event);

	// ������Ⱦ�¼�
	void HandlePaintEvent(QPainter& painter);

	// �������ɿ��¼�
	void HandleKeyRealseEvent(QKeyEvent* event);

private:
	
	 // ��ʼ��
	void InitController();

	// ����ȫ��item
	void UpdateAllItem();

	// ��ͻ���
	void CollisionDetection();

signals:

	// ˢ���ź�
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
