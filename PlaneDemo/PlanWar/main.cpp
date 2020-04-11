#include "Mainscene.h"
#include <QtWidgets/QApplication>
#include <QResource>
#include "Config.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QResource::registerResource(GAME_RES_PATH1);
	MainScene w;
	w.show();
	return a.exec();
}
