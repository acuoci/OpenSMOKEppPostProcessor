/********************************************************************************
** Form generated from reading UI file 'Widget_PlotXYProfiles.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_PLOTXYPROFILES_H
#define UI_WIDGET_PLOTXYPROFILES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_PlotXYProfiles
{
public:
    QGroupBox *groupBox;
    QRadioButton *radioButton_x;
    QRadioButton *radioButton_omega;
    QRadioButton *radioButton_c;
    QRadioButton *radioButton_p;
    QLabel *label;
    QPushButton *pushButton;
    QListWidget *listWidget_Species;
    QListWidget *listWidget_Additional;
    QLabel *label_2;
    QListWidget *listWidget_X;
    QLabel *label_3;
    QSlider *horizontalSlider_Species;
    QLabel *label_4;

    void setupUi(QWidget *Widget_PlotXYProfiles)
    {
        if (Widget_PlotXYProfiles->objectName().isEmpty())
            Widget_PlotXYProfiles->setObjectName(QStringLiteral("Widget_PlotXYProfiles"));
        Widget_PlotXYProfiles->resize(782, 573);
        groupBox = new QGroupBox(Widget_PlotXYProfiles);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(400, 340, 231, 151));
        radioButton_x = new QRadioButton(groupBox);
        radioButton_x->setObjectName(QStringLiteral("radioButton_x"));
        radioButton_x->setGeometry(QRect(30, 30, 121, 20));
        radioButton_x->setChecked(false);
        radioButton_omega = new QRadioButton(groupBox);
        radioButton_omega->setObjectName(QStringLiteral("radioButton_omega"));
        radioButton_omega->setEnabled(true);
        radioButton_omega->setGeometry(QRect(30, 60, 121, 20));
        radioButton_omega->setChecked(true);
        radioButton_c = new QRadioButton(groupBox);
        radioButton_c->setObjectName(QStringLiteral("radioButton_c"));
        radioButton_c->setGeometry(QRect(30, 90, 181, 20));
        radioButton_p = new QRadioButton(groupBox);
        radioButton_p->setObjectName(QStringLiteral("radioButton_p"));
        radioButton_p->setGeometry(QRect(30, 120, 181, 20));
        label = new QLabel(Widget_PlotXYProfiles);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 180, 281, 31));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(Widget_PlotXYProfiles);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 520, 93, 28));
        listWidget_Species = new QListWidget(Widget_PlotXYProfiles);
        listWidget_Species->setObjectName(QStringLiteral("listWidget_Species"));
        listWidget_Species->setGeometry(QRect(30, 210, 301, 291));
        listWidget_Species->setSelectionMode(QAbstractItemView::MultiSelection);
        listWidget_Additional = new QListWidget(Widget_PlotXYProfiles);
        listWidget_Additional->setObjectName(QStringLiteral("listWidget_Additional"));
        listWidget_Additional->setGeometry(QRect(360, 210, 301, 111));
        listWidget_Additional->setSelectionMode(QAbstractItemView::MultiSelection);
        label_2 = new QLabel(Widget_PlotXYProfiles);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 180, 281, 31));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        listWidget_X = new QListWidget(Widget_PlotXYProfiles);
        listWidget_X->setObjectName(QStringLiteral("listWidget_X"));
        listWidget_X->setGeometry(QRect(200, 50, 291, 91));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget_X->sizePolicy().hasHeightForWidth());
        listWidget_X->setSizePolicy(sizePolicy);
        listWidget_X->setFrameShape(QFrame::StyledPanel);
        listWidget_X->setAutoScroll(false);
        label_3 = new QLabel(Widget_PlotXYProfiles);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 20, 281, 31));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        horizontalSlider_Species = new QSlider(Widget_PlotXYProfiles);
        horizontalSlider_Species->setObjectName(QStringLiteral("horizontalSlider_Species"));
        horizontalSlider_Species->setGeometry(QRect(80, 520, 160, 19));
        horizontalSlider_Species->setMouseTracking(false);
        horizontalSlider_Species->setMaximum(100);
        horizontalSlider_Species->setSingleStep(5);
        horizontalSlider_Species->setOrientation(Qt::Horizontal);
        horizontalSlider_Species->setTickPosition(QSlider::TicksAbove);
        label_4 = new QLabel(Widget_PlotXYProfiles);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 540, 111, 20));

        retranslateUi(Widget_PlotXYProfiles);

        QMetaObject::connectSlotsByName(Widget_PlotXYProfiles);
    } // setupUi

    void retranslateUi(QWidget *Widget_PlotXYProfiles)
    {
        Widget_PlotXYProfiles->setWindowTitle(QApplication::translate("Widget_PlotXYProfiles", "Form", 0));
        groupBox->setTitle(QApplication::translate("Widget_PlotXYProfiles", "Species", 0));
        radioButton_x->setText(QApplication::translate("Widget_PlotXYProfiles", "mole fractions", 0));
        radioButton_omega->setText(QApplication::translate("Widget_PlotXYProfiles", "mass fractions", 0));
        radioButton_c->setText(QApplication::translate("Widget_PlotXYProfiles", "concentrations [kmol/m3]", 0));
        radioButton_p->setText(QApplication::translate("Widget_PlotXYProfiles", "partial pressures [Pa]", 0));
        label->setText(QApplication::translate("Widget_PlotXYProfiles", "Species", 0));
        pushButton->setText(QApplication::translate("Widget_PlotXYProfiles", "Plot", 0));
        label_2->setText(QApplication::translate("Widget_PlotXYProfiles", "Additional variables", 0));
#ifndef QT_NO_TOOLTIP
        listWidget_X->setToolTip(QApplication::translate("Widget_PlotXYProfiles", "<html><head/><body><p>Select the x variable</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        listWidget_X->setWhatsThis(QApplication::translate("Widget_PlotXYProfiles", "<html><head/><body><p>This is the variable used on the x axis</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("Widget_PlotXYProfiles", "X Variable", 0));
        label_4->setText(QApplication::translate("Widget_PlotXYProfiles", "Species threshold", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget_PlotXYProfiles: public Ui_Widget_PlotXYProfiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_PLOTXYPROFILES_H
