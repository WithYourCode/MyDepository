/********************************************************************************
** Form generated from reading UI file 'PlayerNumsSelectWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERNUMSSELECTWIDGET_H
#define UI_PLAYERNUMSSELECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayerNumsSelectWidget
{
public:

    void setupUi(QWidget *PlayerNumsSelectWidget)
    {
        if (PlayerNumsSelectWidget->objectName().isEmpty())
            PlayerNumsSelectWidget->setObjectName(QStringLiteral("PlayerNumsSelectWidget"));
        PlayerNumsSelectWidget->resize(400, 300);

        retranslateUi(PlayerNumsSelectWidget);

        QMetaObject::connectSlotsByName(PlayerNumsSelectWidget);
    } // setupUi

    void retranslateUi(QWidget *PlayerNumsSelectWidget)
    {
        PlayerNumsSelectWidget->setWindowTitle(QApplication::translate("PlayerNumsSelectWidget", "PlayerNumsSelectWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlayerNumsSelectWidget: public Ui_PlayerNumsSelectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERNUMSSELECTWIDGET_H
