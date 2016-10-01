/********************************************************************************
** Form generated from reading UI file 'window_zoom_2dplot.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_ZOOM_2DPLOT_H
#define UI_WINDOW_ZOOM_2DPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_Zoom_2dPlot
{
public:
    QDoubleSpinBox *doubleSpinBox_xmin;
    QDoubleSpinBox *doubleSpinBox_xmax;
    QDoubleSpinBox *doubleSpinBox_ymin;
    QDoubleSpinBox *doubleSpinBox_ymax;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_Cancel;

    void setupUi(QWidget *Window_Zoom_2dPlot)
    {
        if (Window_Zoom_2dPlot->objectName().isEmpty())
            Window_Zoom_2dPlot->setObjectName(QStringLiteral("Window_Zoom_2dPlot"));
        Window_Zoom_2dPlot->resize(385, 166);
        doubleSpinBox_xmin = new QDoubleSpinBox(Window_Zoom_2dPlot);
        doubleSpinBox_xmin->setObjectName(QStringLiteral("doubleSpinBox_xmin"));
        doubleSpinBox_xmin->setGeometry(QRect(80, 50, 121, 21));
        doubleSpinBox_xmin->setDecimals(6);
        doubleSpinBox_xmin->setMaximum(1);
        doubleSpinBox_xmax = new QDoubleSpinBox(Window_Zoom_2dPlot);
        doubleSpinBox_xmax->setObjectName(QStringLiteral("doubleSpinBox_xmax"));
        doubleSpinBox_xmax->setGeometry(QRect(80, 80, 121, 21));
        doubleSpinBox_xmax->setDecimals(6);
        doubleSpinBox_ymin = new QDoubleSpinBox(Window_Zoom_2dPlot);
        doubleSpinBox_ymin->setObjectName(QStringLiteral("doubleSpinBox_ymin"));
        doubleSpinBox_ymin->setGeometry(QRect(230, 50, 121, 21));
        doubleSpinBox_ymin->setDecimals(6);
        doubleSpinBox_ymax = new QDoubleSpinBox(Window_Zoom_2dPlot);
        doubleSpinBox_ymax->setObjectName(QStringLiteral("doubleSpinBox_ymax"));
        doubleSpinBox_ymax->setGeometry(QRect(230, 80, 121, 21));
        doubleSpinBox_ymax->setDecimals(6);
        label = new QLabel(Window_Zoom_2dPlot);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 20, 53, 16));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Window_Zoom_2dPlot);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 20, 53, 16));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Window_Zoom_2dPlot);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 50, 53, 16));
        QFont font1;
        font1.setPointSize(9);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Window_Zoom_2dPlot);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 80, 53, 16));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        pushButton_OK = new QPushButton(Window_Zoom_2dPlot);
        pushButton_OK->setObjectName(QStringLiteral("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(90, 120, 93, 28));
        pushButton_Cancel = new QPushButton(Window_Zoom_2dPlot);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(240, 120, 93, 28));

        retranslateUi(Window_Zoom_2dPlot);

        QMetaObject::connectSlotsByName(Window_Zoom_2dPlot);
    } // setupUi

    void retranslateUi(QWidget *Window_Zoom_2dPlot)
    {
        Window_Zoom_2dPlot->setWindowTitle(QApplication::translate("Window_Zoom_2dPlot", "Set Min and Max Coordinates", 0));
        label->setText(QApplication::translate("Window_Zoom_2dPlot", "X Axis", 0));
        label_2->setText(QApplication::translate("Window_Zoom_2dPlot", "Y Axis", 0));
        label_3->setText(QApplication::translate("Window_Zoom_2dPlot", "Min", 0));
        label_4->setText(QApplication::translate("Window_Zoom_2dPlot", "Max", 0));
        pushButton_OK->setText(QApplication::translate("Window_Zoom_2dPlot", "OK", 0));
        pushButton_Cancel->setText(QApplication::translate("Window_Zoom_2dPlot", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Window_Zoom_2dPlot: public Ui_Window_Zoom_2dPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_ZOOM_2DPLOT_H
