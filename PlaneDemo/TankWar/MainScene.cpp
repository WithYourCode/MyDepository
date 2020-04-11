#include "MainScene.h"
#include "Configure.h"
#include <QPainter>
#include "TankMap.h"
#include <QDebug>
#include <QKeyEvent>

MainScene::MainScene(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	InitUi();
	InitLogic();
}

MainScene::~MainScene()
{
	if (m_timer != nullptr)
	{
		delete m_timer;
		m_timer = nullptr;
	}
}

void MainScene::OnStartGame(int player_num)
{
	show();
	grabKeyboard();

	m_timer->start();

	// 敌机出场
	m_enemy_manager->EnemyTanksToScene();
}

void MainScene::OnUpdateUi()
{
	// 玩家1更新
	//m_player1.UpdateAllData();

	// 敌机坦克更新
	m_enemy_manager->UpdateEnemyTanksData();

	update();
}

void MainScene::InitUi()
{
	m_img_wall_l = QImage(":/TankWar/Resources/image/object/objectWallL.png");
	m_img_wall_r = QImage(":/TankWar/Resources/image/object/objectWallR.png");
	m_img_base = QImage(":/TankWar/Resources/image/player/base.png");
	m_img_iron = QImage(":/TankWar/Resources/image/object/objectIronSmall.png");
	m_img_grass = QImage(":/TankWar/Resources/image/object/objectGrassSmall.png");

}

void MainScene::InitLogic()
{
	//地图初始化
	TankMap::InitMap();
	TankMap::SetStage(1);

	// 玩家坦克初始化
	m_player1.InitTank(32, 96, Base::Direction_Up, 'P');

	// 敌机管理类初始化
	m_enemy_manager = new EnemyManager(this);

	// 时间驱动器初始化
	m_timer = new QTimer;
	m_timer->setInterval(TIME_INTERVAL);
	connect(m_timer, &QTimer::timeout, this, &MainScene::OnUpdateUi);
}

void MainScene::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);

	painter.setBrush(QColor(99, 97, 99));
	painter.setPen(QPen(QColor(99, 97, 99)));

	// 整体界面大小
	painter.drawRect(0, 0, SIZE_WIDTH, SIZE_HEIGHT);

	// 游戏区域
	painter.setBrush(Qt::black);
	painter.drawRect(BORDER_LEFT - 1, BORDER_UP - 1, CELL_WIDTH*CELL_NUMBER + 1, CELL_HEIGHT*CELL_NUMBER);

	//画地图
	for (int y = 0; y < CELL_NUMBER; y += 1)
	{
		for (int x = 0; x < CELL_NUMBER; x += 1)
		{
			// cell的大小为 width = 10 height = 8
			switch (TankMap::GetMap(x, y))
			{
			case 'B': painter.drawImage(BORDER_LEFT + x * 10, BORDER_UP + y * 8, m_img_base); break;
			case 'W': painter.drawImage(BORDER_LEFT + x * 10, BORDER_UP + y * 8, m_img_wall_l); break;
			case 'V': painter.drawImage(BORDER_LEFT + x * 10, BORDER_UP + y * 8, m_img_wall_r); break;
			case 'I': painter.drawImage(BORDER_LEFT + x * 10, BORDER_UP + y * 8, m_img_iron); break;
			case 'G': painter.drawImage(BORDER_LEFT + x * 10, BORDER_UP + y * 8, m_img_grass); break;

// 				case 'R': break;
// 				case 'P': painter.drawRect(75+x*10, 45+y*8, 10, 8); break;
// 				case 'Q': painter.drawRect(75+x*10, 45+y*8, 10, 8); break;
// 				case '1': painter.drawRect(75+x*10, 45+y*8, 10, 8); break;
// 				case '2': painter.drawRect(75+x*10, 45+y*8, 10, 8); break;
// 				case '3': painter.drawRect(75+x*10, 45+y*8, 10, 8); break;
// 				case '4': painter.drawRect(75+x*10, 45+y*8, 10, 8); break;
			default: break;
			}
		}
	}

	// 画玩家1
	//m_player1.PaintTank(painter);

	// 绘制敌机坦克
	m_enemy_manager->PaintEnemyTanks(painter);















	QWidget::paintEvent(event);
}

void MainScene::keyPressEvent(QKeyEvent* event)
{
	if (nullptr == event)
		return;

	switch (event->key())
	{
	case Qt::Key_W:
		m_player1.SetMoveFlag(true);
		m_player1.SetDirection(Base::Direction_Up);
		break;
	case Qt::Key_S:
		m_player1.SetMoveFlag(true);
		m_player1.SetDirection(Base::Direction_Down);
		break;
	case Qt::Key_A:
		m_player1.SetMoveFlag(true);
		m_player1.SetDirection(Base::Direction_Left);
		break;
	case Qt::Key_D:
		m_player1.SetMoveFlag(true);
		m_player1.SetDirection(Base::Direction_Right);
		break;
	default:
		break;
	}

	QWidget::keyPressEvent(event);
}

void MainScene::keyReleaseEvent(QKeyEvent* event)
{
	if (nullptr == event)
		return;

	switch (event->key())
	{
	case Qt::Key_W:
	case Qt::Key_S:
	case Qt::Key_A:
	case Qt::Key_D:
		m_player1.SetMoveFlag(false);
		break;
	}

	QWidget::keyReleaseEvent(event);
}
