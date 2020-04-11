/********************************************************************************
** Form generated from reading UI file 'TankWar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TANKWAR_H
#define UI_TANKWAR_H

#include <MainScene.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "GameOverWidget.h"
#include "PlayerNumsSelectWidget.h"
#include "StageWidget.h"

QT_BEGIN_NAMESPACE

class Ui_TankWarClass
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *m_stack_widget;
    PlayerNumsSelectWidget *m_start1_widget;
    StageWidget *m_start2_widget;
    MainScene *m_main_scene;
    GameOverWidget *m_over_widget;

    void setupUi(QWidget *TankWarClass)
    {
        if (TankWarClass->objectName().isEmpty())
            TankWarClass->setObjectName(QStringLiteral("TankWarClass"));
        TankWarClass->resize(600, 400);
        gridLayout = new QGridLayout(TankWarClass);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        m_stack_widget = new QStackedWidget(TankWarClass);
        m_stack_widget->setObjectName(QStringLiteral("m_stack_widget"));
        m_start1_widget = new PlayerNumsSelectWidget();
        m_start1_widget->setObjectName(QStringLiteral("m_start1_widget"));
        m_stack_widget->addWidget(m_start1_widget);
        m_start2_widget = new StageWidget();
        m_start2_widget->setObjectName(QStringLiteral("m_start2_widget"));
        m_stack_widget->addWidget(m_start2_widget);
        m_main_scene = new MainScene();
        m_main_scene->setObjectName(QStringLiteral("m_main_scene"));
        m_stack_widget->addWidget(m_main_scene);
        m_over_widget = new GameOverWidget();
        m_over_widget->setObjectName(QStringLiteral("m_over_widget"));
        m_stack_widget->addWidget(m_over_widget);

        gridLayout->addWidget(m_stack_widget, 0, 0, 1, 1);


        retranslateUi(TankWarClass);

        QMetaObject::connectSlotsByName(TankWarClass);
    } // setupUi

    void retranslateUi(QWidget *TankWarClass)
    {
        TankWarClass->setWindowTitle(QApplication::translate("TankWarClass", "TankWar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TankWarClass: public Ui_TankWarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TANKWAR_H
