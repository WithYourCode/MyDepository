/********************************************************************************
** Form generated from reading UI file 'StageWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAGEWIDGET_H
#define UI_STAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StageWidget
{
public:

    void setupUi(QWidget *StageWidget)
    {
        if (StageWidget->objectName().isEmpty())
            StageWidget->setObjectName(QStringLiteral("StageWidget"));
        StageWidget->resize(400, 300);

        retranslateUi(StageWidget);

        QMetaObject::connectSlotsByName(StageWidget);
    } // setupUi

    void retranslateUi(QWidget *StageWidget)
    {
        StageWidget->setWindowTitle(QApplication::translate("StageWidget", "StageWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StageWidget: public Ui_StageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAGEWIDGET_H
