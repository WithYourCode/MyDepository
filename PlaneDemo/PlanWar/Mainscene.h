#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QPointer>
#include "ui_MainScene.h"
#include "GameController.h"

class MainScene : public QWidget
{
	Q_OBJECT

public:
	MainScene(QWidget *parent = 0);
	~MainScene();

private:
	// ≥ı ºªØ
	void InitScene();

protected:
	virtual void paintEvent(QPaintEvent* event)override;

	virtual void keyPressEvent(QKeyEvent* event)override;

	virtual void mouseMoveEvent(QMouseEvent* event) override;

	virtual void keyReleaseEvent(QKeyEvent *event) override;

private:
	Ui::MainSceneClass ui;

	QPointer<GameController> pController = nullptr;

};

#endif // MAINSCENE_H
