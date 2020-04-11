#include "TankWar.h"
#include "Configure.h"
#include <QEvent>
#include <QDebug>

TankWar::TankWar(QWidget *ptr_parent)
	: QWidget(ptr_parent)
{
	ui.setupUi(this);
	setFixedSize(SIZE_WIDTH, SIZE_HEIGHT);
	move(300, 50);
	setWindowIcon(QIcon(":/TankWar/Resources/image/BattleCity.ico"));
	setWindowTitle(QString("Tank War V1.0"));

	// Ĭ��Ϊ��һҳ
	ui.m_stack_widget->setCurrentWidget(ui.m_start1_widget);

	// ��Ҫ�ֶ�����stack�������л�����Ȼ����չʾ�ߴ粻��ȷ
	connect(ui.m_start1_widget, &PlayerNumsSelectWidget::SignalPlayerSelected, this, [=](int num) {
		ui.m_stack_widget->setCurrentWidget(ui.m_start2_widget);
		ui.m_start2_widget->OnPlayerNumSelected(num);
	});

	connect(ui.m_start2_widget, &StageWidget::SignalGameStart, this, [=](int num) {
		ui.m_stack_widget->setCurrentWidget(ui.m_main_scene);
		ui.m_start2_widget->releaseKeyboard();
		ui.m_main_scene->OnStartGame(num);
	});
}

TankWar::~TankWar()
{

}
