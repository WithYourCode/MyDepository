#include "Mainscene.h"
#include "Config.h"
#include <QPainter>
#include <QDebug>

MainScene::MainScene(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	InitScene();


}

MainScene::~MainScene()
{

}

void MainScene::InitScene()
{
	setFixedSize(GAME_WIDTH, GAME_HEIGHT);

	setWindowTitle(GAME_TITLE);

	setWindowIcon(QIcon(GAME_ICON));

	pController = new GameController(this);

	connect(pController, &GameController::SignalUpdateUi, this, [=] {
		update();
	});
	// ¿ªÊ¼game
	pController->StartGame();

}



void MainScene::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);

	if (!pController.isNull())
		pController->HandlePaintEvent(painter);

	QWidget::paintEvent(event);
}

void MainScene::keyPressEvent(QKeyEvent* event)
{
	if (!pController.isNull())
		pController->HandleKeyEvent(event);

	QWidget::keyPressEvent(event);
}

void MainScene::mouseMoveEvent(QMouseEvent* event)
{
	if (!pController.isNull())
		//pController->HandleMouseEvent(event);

	QWidget::mouseMoveEvent(event);
}

void MainScene::keyReleaseEvent(QKeyEvent *event)
{
	if (!pController.isNull())
		pController->HandleKeyRealseEvent(event);

	QWidget::keyReleaseEvent(event);
}
