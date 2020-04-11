#ifndef __TANKWAR_H__
#define __TANKWAR_H__

#include <QtWidgets/QWidget>
#include "ui_TankWar.h"

class TankWar : public QWidget
{
	Q_OBJECT

public:
	TankWar(QWidget *ptr_parent = 0);
	~TankWar();

private:
	Ui::TankWarClass ui;
};

#endif // __TANKWAR_H__
