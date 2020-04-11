#ifndef GAMEOVERWIDGET_H
#define GAMEOVERWIDGET_H

#include <QWidget>
#include "ui_GameOverWidget.h"

class GameOverWidget : public QWidget
{
	Q_OBJECT

public:
	GameOverWidget(QWidget *ptr_parent = 0);
	~GameOverWidget();

protected:

	virtual void paintEvent(QPaintEvent *event) override;

private:
	Ui::GameOverWidget ui;

	QImage m_image;
};

#endif // GAMEOVERWIDGET_H
