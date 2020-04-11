#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QPointer>
#include "ui_MainScene.h"
#include "PlayerTank.h"
#include <QTimer>
#include "EnemyManager.h"

class MainScene : public QWidget
{
	Q_OBJECT

public:
	MainScene(QWidget *parent = 0);
	~MainScene();

protected:

	virtual void paintEvent(QPaintEvent* event) override;

	virtual void keyPressEvent(QKeyEvent* event) override;

	virtual void keyReleaseEvent(QKeyEvent* event) override;

public slots:

	void OnStartGame(int player_num);

	// ��ʱ�ѵ�
	void OnUpdateUi();

private:

	void InitUi();

	void InitLogic();

private:
	Ui::MainScene ui;

	// ��ͼԪ��ͼƬ
	QImage m_img_wall_l;
	QImage m_img_wall_r;
	QImage m_img_base;
	QImage m_img_iron;
	QImage m_img_grass;

	PlayerTank m_player1;

	QPointer<EnemyManager> m_enemy_manager = nullptr;

	// �¼�ѭ������������ʱ����
	QTimer* m_timer;
};

#endif // MAINSCENE_H
