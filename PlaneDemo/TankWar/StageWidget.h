#ifndef STAGEWIDGET_H
#define STAGEWIDGET_H

#include <QWidget>
#include "ui_StageWidget.h"

class StageWidget : public QWidget
{
	Q_OBJECT

public:
	StageWidget(QWidget *ptr_parent = 0);
	~StageWidget();

public slots:
	void OnPlayerNumSelected(int num);

protected:

	virtual void keyPressEvent(QKeyEvent *event) override;

	virtual void paintEvent(QPaintEvent *event) override;

signals:

	void SignalGameStart(int num);

private:
	Ui::StageWidget ui;

	int m_player_num = 1;

	QImage m_image;
};

#endif // STAGEWIDGET_H
