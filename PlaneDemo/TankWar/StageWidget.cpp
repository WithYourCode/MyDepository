#include "StageWidget.h"
#include <QKeyEvent>
#include <QPainter>

StageWidget::StageWidget(QWidget *ptr_parent)
	: QWidget(ptr_parent)
{
	ui.setupUi(this);

	m_image = QImage(":/TankWar/Resources/image/start2.jpg");
}

StageWidget::~StageWidget()
{

}

void StageWidget::OnPlayerNumSelected(int num)
{
	grabKeyboard();
	m_player_num = num;
}

void StageWidget::keyPressEvent(QKeyEvent *event)
{
	if (nullptr == event)
		return;

	if(event->key() == Qt::Key_Return)
	{
		emit SignalGameStart(m_player_num);
	}

	QWidget::keyPressEvent(event);
}

void StageWidget::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	p.setBrush(Qt::black);
	p.drawRect(rect());

	p.drawImage(rect(), m_image);

	QWidget::paintEvent(event);
}
