#include "GameController.h"
#include "Config.h"
#include <ctime>

GameController::GameController(QObject* ptr_pareent)
	:QObject(ptr_pareent)
{
	srand((unsigned int)time(NULL));
	InitController();
}


GameController::~GameController()
{
	if (nullptr != pSound)
	{
		delete pSound;
		pSound = nullptr;
	}
}

void GameController::StartGame()
{
	m_Timer.start();

	// 基于定时器的刷新机制
	connect(&m_Timer, &QTimer::timeout, [=]() {
		// 敌机出场
		m_EnemyManager.EnemyToScene();
		// 实时更新位置
		UpdateAllItem();
		// 刷新渲染
		emit SignalUpdateUi();
		// 冲突检测
		CollisionDetection();
	});

	// 背景音乐
	if (nullptr != pSound)
	{
		pSound->play();
	}
}

void GameController::UpdateAllItem()
{
	m_Map.UpdatePosition();

	// 计算子弹的位置
	m_HeroPlane.UpdatePosition();

	//敌机坐标计算
	m_EnemyManager.UpdateAllEnemyPosition();

	//计算爆炸播放的图片
	for (int i = 0; i < BOMB_NUM; i++)
	{
		if (m_Bombs[i].GetIsFree() == false)
		{
			m_Bombs[i].UpdatePosition();
		}
	}
}

void GameController::CollisionDetection()
{
	EnemyPlane* m_Enemys = m_EnemyManager.GetAllEnemy();

	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (m_Enemys[i].GetIsFree())
			continue;

		for (int j = 0; j < BULLET_NUM; j++)
		{
			if (m_HeroPlane.m_Bullets[j].GetIsFree())
				continue;

			if (m_Enemys[i].GetRect().intersects(m_HeroPlane.m_Bullets[j].GetRect()))
			{
				m_Enemys[i].SetFree(true);
				m_HeroPlane.m_Bullets[j].SetFree(true);

				QSound::play(SOUND_BOMB);

				for (int k = 0; k < BOMB_NUM; k++)
				{
					if (m_Bombs[k].GetIsFree())
					{
						//爆炸状态设置为非空闲
						m_Bombs[k].SetFree(false);
						//更新坐标

						m_Bombs[k].SetX(m_Enemys[i].GetX());
						m_Bombs[k].SetY(m_Enemys[i].GetY());
						break;
					}
				}
			}
		}
	}
}

void GameController::HandleKeyEvent(QKeyEvent* event)
{
	if (nullptr == event)
		return;

	switch (event->key())
	{
	case Qt::Key_W:
	{
		m_HeroPlane.SetMoveFlag(true,HeroPlane::Up);
	}
	break;
	case Qt::Key_S:
	{
		m_HeroPlane.SetMoveFlag(true, HeroPlane::Down);
	}
	break;
	case Qt::Key_A:
	{
		m_HeroPlane.SetMoveFlag(true, HeroPlane::Left);
	}
	break;
	case Qt::Key_D:
	{
		m_HeroPlane.SetMoveFlag(true, HeroPlane::Right);
	}
	break;
	case Qt::Key_J:
	{
		m_HeroPlane.Shoot();
	}
	break;
	default:
		break;

	}
}

// 该接口没用到，保留
void GameController::HandleMouseEvent(QMouseEvent* event)
{
	int x = event->x() - m_HeroPlane.GetRect().width()*0.5; //鼠标位置 - 飞机矩形的一半
	int y = event->y() - m_HeroPlane.GetRect().height()*0.5;

	//边界检测
	if (x <= 0)
	{
		x = 0;
	}
	if (x >= GAME_WIDTH - m_HeroPlane.GetRect().width())
	{
		x = GAME_WIDTH - m_HeroPlane.GetRect().width();
	}
	if (y <= 0)
	{
		y = 0;
	}
	if (y >= GAME_HEIGHT - m_HeroPlane.GetRect().height())
	{
		y = GAME_HEIGHT - m_HeroPlane.GetRect().height();
	}
	//m_HeroPlane.SetPosition(x, y);
}

void GameController::HandlePaintEvent(QPainter& painter)
{
	// 绘制地图图片
	m_Map.PaintPixmap(painter);

	// 绘制英雄飞机
	m_HeroPlane.PaintPixmap(painter);

	// 绘制子弹
	m_HeroPlane.PaintBullet(painter);

	//绘制敌机
	m_EnemyManager.PaintEnemyPlane(painter);

	//绘制爆炸图片
	for (int i = 0; i < BOMB_NUM; i++)
	{
		m_Bombs[i].PaintPixmap(painter);
	}
}

void GameController::HandleKeyRealseEvent(QKeyEvent* event)
{
	if (nullptr == event)
		return;

	switch (event->key())
	{
	case Qt::Key_W:
	case Qt::Key_S:
	case Qt::Key_A:
	case Qt::Key_D:
	{
		m_HeroPlane.SetMoveFlag(false, HeroPlane::None);
	}
	break;
	default:
		break;
	}
}

void GameController::InitController()
{
	// 设置刷新间隔
	m_Timer.setInterval(GAME_RATE);

	// 初始化声音
	pSound = new QSound(SOUND_BACKGROUND);
	pSound->setLoops(-1);
}
