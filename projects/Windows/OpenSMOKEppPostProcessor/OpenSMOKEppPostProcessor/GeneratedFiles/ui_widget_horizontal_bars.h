/********************************************************************************
** Form generated from reading UI file 'widget_horizontal_bars.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_HORIZONTAL_BARS_H
#define UI_WIDGET_HORIZONTAL_BARS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Horizontal_Bars
{
public:

    void setupUi(QWidget *Widget_Horizontal_Bars)
    {
        if (Widget_Horizontal_Bars->objectName().isEmpty())
            Widget_Horizontal_Bars->setObjectName(QStringLiteral("Widget_Horizontal_Bars"));
        Widget_Horizontal_Bars->resize(800, 500);
        Widget_Horizontal_Bars->setMinimumSize(QSize(600, 500));
        Widget_Horizontal_Bars->setMaximumSize(QSize(1200, 1000));

        retranslateUi(Widget_Horizontal_Bars);

        QMetaObject::connectSlotsByName(Widget_Horizontal_Bars);
    } // setupUi

    void retranslateUi(QWidget *Widget_Horizontal_Bars)
    {
        Widget_Horizontal_Bars->setWindowTitle(QApplication::translate("Widget_Horizontal_Bars", "Sensitivity bars", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget_Horizontal_Bars: public Ui_Widget_Horizontal_Bars {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_HORIZONTAL_BARS_H
