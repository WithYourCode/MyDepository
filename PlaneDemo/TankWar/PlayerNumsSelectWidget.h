#ifndef PLAYERNUMSSELECTWIDGET_H
#define PLAYERNUMSSELECTWIDGET_H

#include <QWidget>
#include "ui_PlayerNumsSelectWidget.h"

class PlayerNumsSelectWidget : public QWidget
{
	Q_OBJECT

public:
	PlayerNumsSelectWidget(QWidget *ptr_parent = 0);
	~PlayerNumsSelectWidget();

protected:

	virtual void paintEvent(QPaintEvent* event) override;

	virtual void keyPressEvent(QKeyEvent* event) override;

signals:

	void SignalPlayerSelected(int player_num);

private:
	Ui::PlayerNumsSelectWidget ui;

	QImage m_start_image1;
	QImage m_start_image2;
	QImage m_selected_image;

	QPoint m_select_pos;

	int m_selected_num = 1;
};



#endif // PLAYERNUMSSELECTWIDGET_H
