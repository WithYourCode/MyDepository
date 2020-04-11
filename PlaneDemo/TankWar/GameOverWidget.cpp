#include "GameOverWidget.h"
#include <QPainter>

GameOverWidget::GameOverWidget(QWidget *ptr_parent)
	: QWidget(ptr_parent)
{
	ui.setupUi(this);

	m_image = QImage(":/TankWar/Resources/image/gameOver1.png");
}

GameOverWidget::~GameOverWidget()
{

}

void GameOverWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setBrush(Qt::black);
	painter.drawRect(rect());
	painter.drawImage(rect(), m_image);

	QWidget::paintEvent(event);
}
