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

	// ���ڶ�ʱ����ˢ�»���
	connect(&m_Timer, &QTimer::timeout, [=]() {
		// �л�����
		m_EnemyManager.EnemyToScene();
		// ʵʱ����λ��
		UpdateAllItem();
		// ˢ����Ⱦ
		emit SignalUpdateUi();
		// ��ͻ���
		CollisionDetection();
	});

	// ��������
	if (nullptr != pSound)
	{
		pSound->play();
	}
}

void GameController::UpdateAllItem()
{
	m_Map.UpdatePosition();

	// �����ӵ���λ��
	m_HeroPlane.UpdatePosition();

	//�л��������
	m_EnemyManager.UpdateAllEnemyPosition();

	//���㱬ը���ŵ�ͼƬ
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
						//��ը״̬����Ϊ�ǿ���
						m_Bombs[k].SetFree(false);
						//��������

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

// �ýӿ�û�õ�������
void GameController::HandleMouseEvent(QMouseEvent* event)
{
	int x = event->x() - m_HeroPlane.GetRect().width()*0.5; //���λ�� - �ɻ����ε�һ��
	int y = event->y() - m_HeroPlane.GetRect().height()*0.5;

	//�߽���
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
	// ���Ƶ�ͼͼƬ
	m_Map.PaintPixmap(painter);

	// ����Ӣ�۷ɻ�
	m_HeroPlane.PaintPixmap(painter);

	// �����ӵ�
	m_HeroPlane.PaintBullet(painter);

	//���Ƶл�
	m_EnemyManager.PaintEnemyPlane(painter);

	//���Ʊ�ըͼƬ
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
	// ����ˢ�¼��
	m_Timer.setInterval(GAME_RATE);

	// ��ʼ������
	pSound = new QSound(SOUND_BACKGROUND);
	pSound->setLoops(-1);
}
