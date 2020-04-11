#include "TankWar.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TankWar w;
	w.show();
	return a.exec();
}
