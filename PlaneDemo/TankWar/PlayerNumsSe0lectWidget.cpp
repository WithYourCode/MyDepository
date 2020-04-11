#include "PlayerNumsSelectWidget.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>


PlayerNumsSelectWidget::PlayerNumsSelectWidget(QWidget *ptr_parent)
	: QWidget(ptr_parent)
{
	ui.setupUi(this);

	// �õ�ǰ�Ľ����ȡ�������뽹�㣬���ȼ�����setFocus
	grabKeyboard();

	m_start_image1 = QImage(":/TankWar/Resources/image/start0.jpg");
	m_selected_image = QImage(":/TankWar/Resources/image/player/p1tankNormal_U1.png");

	QMatrix matrixBulletIS;
	matrixBulletIS.rotate(90);
	m_selected_image = m_selected_image.transformed(matrixBulletIS).scaled(80, 64);

	m_select_pos = QPoint(322, 510);  //�̶�λ��
}

PlayerNumsSelectWidget::~PlayerNumsSelectWidget()
{

}

void PlayerNumsSelectWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	
	// ���������ɫ
	painter.setBrush(Qt::black);
	painter.drawRect(this->rect());

	painter.drawImage(this->rect(), m_start_image1);

	painter.drawImage(m_select_pos, m_selected_image);

	QWidget::paintEvent(event);
}

void PlayerNumsSelectWidget::keyPressEvent(QKeyEvent* event)
{
	if (nullptr == event)
		return;

	switch (event->key())
	{
	case Qt::Key_W:
	{
		m_select_pos.ry() = 510;
		m_selected_num = 1;
		update();
	}
	break;
	case Qt::Key_S:
	{
		m_selected_num = 2;
		m_select_pos.ry() = 64 + 510;
		update();
	}
	break;
	case Qt::Key_Return:
	{
		emit SignalPlayerSelected(m_selected_num);
		releaseKeyboard();
	}
	break;
	}

	QWidget::keyPressEvent(event);
}
