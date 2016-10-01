/********************************************************************************
** Form generated from reading UI file 'window_sensitivities.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_SENSITIVITIES_H
#define UI_WINDOW_SENSITIVITIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_Sensitivities
{
public:
    QListWidget *listWidget_Sensitivities_Y;
    QLabel *label_4;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_Sensitivities_BarChart;
    QGroupBox *groupBox_4;
    QRadioButton *radioButton_Sensitivities_Global;
    QDoubleSpinBox *doubleSpinBox_Sensitivities_Region_Min;
    QDoubleSpinBox *doubleSpinBox_Sensitivities_Region_Max;
    QRadioButton *radioButton_Sensitivities_Region;
    QFrame *line_2;
    QFrame *line_3;
    QRadioButton *radioButton_Sensitivities_Local;
    QDoubleSpinBox *doubleSpinBox_Sensitivities_Local;
    QGroupBox *groupBox_6;
    QComboBox *comboBox_Sensitivities_Integral;
    QGroupBox *groupBox;
    QRadioButton *radioButton_Sensitivities_NormalizeLocal;
    QRadioButton *radioButton__Sensitivities_NormalizeMax;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_Sensitivities_PlotProfiles;
    QSlider *horizontalSlider_Sensitivities_Reactions;
    QListWidget *listWidget_Sensitivities_Reactions;
    QLabel *label_6;
    QComboBox *comboBox_Sensitivities_X;
    QLabel *label_5;
    QPushButton *pushButton_clean_Reactions;
    QGroupBox *groupBox_3;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *Window_Sensitivities)
    {
        if (Window_Sensitivities->objectName().isEmpty())
            Window_Sensitivities->setObjectName(QStringLiteral("Window_Sensitivities"));
        Window_Sensitivities->resize(850, 685);
        listWidget_Sensitivities_Y = new QListWidget(Window_Sensitivities);
        listWidget_Sensitivities_Y->setObjectName(QStringLiteral("listWidget_Sensitivities_Y"));
        listWidget_Sensitivities_Y->setGeometry(QRect(60, 50, 391, 111));
        listWidget_Sensitivities_Y->setSelectionMode(QAbstractItemView::SingleSelection);
        label_4 = new QLabel(Window_Sensitivities);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 20, 391, 20));
        QFont font;
        font.setPointSize(10);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        groupBox_5 = new QGroupBox(Window_Sensitivities);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(540, 190, 291, 371));
        pushButton_Sensitivities_BarChart = new QPushButton(groupBox_5);
        pushButton_Sensitivities_BarChart->setObjectName(QStringLiteral("pushButton_Sensitivities_BarChart"));
        pushButton_Sensitivities_BarChart->setGeometry(QRect(60, 330, 171, 28));
        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 30, 261, 211));
        groupBox_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        radioButton_Sensitivities_Global = new QRadioButton(groupBox_4);
        buttonGroup = new QButtonGroup(Window_Sensitivities);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton_Sensitivities_Global);
        radioButton_Sensitivities_Global->setObjectName(QStringLiteral("radioButton_Sensitivities_Global"));
        radioButton_Sensitivities_Global->setGeometry(QRect(100, 30, 71, 20));
        radioButton_Sensitivities_Global->setChecked(true);
        doubleSpinBox_Sensitivities_Region_Min = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_Sensitivities_Region_Min->setObjectName(QStringLiteral("doubleSpinBox_Sensitivities_Region_Min"));
        doubleSpinBox_Sensitivities_Region_Min->setEnabled(false);
        doubleSpinBox_Sensitivities_Region_Min->setGeometry(QRect(20, 100, 111, 22));
        doubleSpinBox_Sensitivities_Region_Min->setDecimals(8);
        doubleSpinBox_Sensitivities_Region_Max = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_Sensitivities_Region_Max->setObjectName(QStringLiteral("doubleSpinBox_Sensitivities_Region_Max"));
        doubleSpinBox_Sensitivities_Region_Max->setEnabled(false);
        doubleSpinBox_Sensitivities_Region_Max->setGeometry(QRect(150, 100, 101, 22));
        doubleSpinBox_Sensitivities_Region_Max->setDecimals(8);
        radioButton_Sensitivities_Region = new QRadioButton(groupBox_4);
        buttonGroup->addButton(radioButton_Sensitivities_Region);
        radioButton_Sensitivities_Region->setObjectName(QStringLiteral("radioButton_Sensitivities_Region"));
        radioButton_Sensitivities_Region->setGeometry(QRect(100, 70, 71, 20));
        line_2 = new QFrame(groupBox_4);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(20, 50, 231, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(groupBox_4);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(20, 130, 231, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        radioButton_Sensitivities_Local = new QRadioButton(groupBox_4);
        buttonGroup->addButton(radioButton_Sensitivities_Local);
        radioButton_Sensitivities_Local->setObjectName(QStringLiteral("radioButton_Sensitivities_Local"));
        radioButton_Sensitivities_Local->setGeometry(QRect(100, 150, 71, 20));
        doubleSpinBox_Sensitivities_Local = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_Sensitivities_Local->setObjectName(QStringLiteral("doubleSpinBox_Sensitivities_Local"));
        doubleSpinBox_Sensitivities_Local->setEnabled(false);
        doubleSpinBox_Sensitivities_Local->setGeometry(QRect(70, 180, 121, 22));
        doubleSpinBox_Sensitivities_Local->setDecimals(8);
        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 260, 261, 51));
        groupBox_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_Sensitivities_Integral = new QComboBox(groupBox_6);
        comboBox_Sensitivities_Integral->setObjectName(QStringLiteral("comboBox_Sensitivities_Integral"));
        comboBox_Sensitivities_Integral->setGeometry(QRect(60, 20, 141, 22));
        groupBox = new QGroupBox(Window_Sensitivities);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(480, 60, 351, 91));
        radioButton_Sensitivities_NormalizeLocal = new QRadioButton(groupBox);
        radioButton_Sensitivities_NormalizeLocal->setObjectName(QStringLiteral("radioButton_Sensitivities_NormalizeLocal"));
        radioButton_Sensitivities_NormalizeLocal->setGeometry(QRect(20, 30, 95, 20));
        radioButton_Sensitivities_NormalizeLocal->setChecked(true);
        radioButton__Sensitivities_NormalizeMax = new QRadioButton(groupBox);
        radioButton__Sensitivities_NormalizeMax->setObjectName(QStringLiteral("radioButton__Sensitivities_NormalizeMax"));
        radioButton__Sensitivities_NormalizeMax->setGeometry(QRect(20, 60, 95, 20));
        groupBox_2 = new QGroupBox(Window_Sensitivities);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 190, 501, 481));
        pushButton_Sensitivities_PlotProfiles = new QPushButton(groupBox_2);
        pushButton_Sensitivities_PlotProfiles->setObjectName(QStringLiteral("pushButton_Sensitivities_PlotProfiles"));
        pushButton_Sensitivities_PlotProfiles->setGeometry(QRect(190, 440, 111, 28));
        horizontalSlider_Sensitivities_Reactions = new QSlider(groupBox_2);
        horizontalSlider_Sensitivities_Reactions->setObjectName(QStringLiteral("horizontalSlider_Sensitivities_Reactions"));
        horizontalSlider_Sensitivities_Reactions->setGeometry(QRect(30, 410, 381, 20));
        horizontalSlider_Sensitivities_Reactions->setMaximum(100);
        horizontalSlider_Sensitivities_Reactions->setTracking(false);
        horizontalSlider_Sensitivities_Reactions->setOrientation(Qt::Horizontal);
        listWidget_Sensitivities_Reactions = new QListWidget(groupBox_2);
        listWidget_Sensitivities_Reactions->setObjectName(QStringLiteral("listWidget_Sensitivities_Reactions"));
        listWidget_Sensitivities_Reactions->setGeometry(QRect(10, 130, 481, 271));
        listWidget_Sensitivities_Reactions->setSelectionMode(QAbstractItemView::MultiSelection);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 100, 471, 20));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        comboBox_Sensitivities_X = new QComboBox(groupBox_2);
        comboBox_Sensitivities_X->setObjectName(QStringLiteral("comboBox_Sensitivities_X"));
        comboBox_Sensitivities_X->setGeometry(QRect(30, 60, 441, 22));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 30, 431, 20));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        pushButton_clean_Reactions = new QPushButton(groupBox_2);
        pushButton_clean_Reactions->setObjectName(QStringLiteral("pushButton_clean_Reactions"));
        pushButton_clean_Reactions->setGeometry(QRect(430, 410, 51, 21));
        QFont font1;
        font1.setPointSize(8);
        pushButton_clean_Reactions->setFont(font1);
        groupBox_3 = new QGroupBox(Window_Sensitivities);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(540, 570, 291, 101));

        retranslateUi(Window_Sensitivities);

        QMetaObject::connectSlotsByName(Window_Sensitivities);
    } // setupUi

    void retranslateUi(QWidget *Window_Sensitivities)
    {
        Window_Sensitivities->setWindowTitle(QApplication::translate("Window_Sensitivities", "Window_Sensitivities", 0));
        label_4->setText(QApplication::translate("Window_Sensitivities", "Y Variables", 0));
        groupBox_5->setTitle(QApplication::translate("Window_Sensitivities", "Sensitivity Bars", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_Sensitivities_BarChart->setToolTip(QApplication::translate("Window_Sensitivities", "<html><head/><body><p>Plots the sensitivity coefficients of the most important reactions for the selected species</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Sensitivities_BarChart->setText(QApplication::translate("Window_Sensitivities", "Plot Sensitivities Bars", 0));
        groupBox_4->setTitle(QApplication::translate("Window_Sensitivities", "Domain", 0));
#ifndef QT_NO_TOOLTIP
        radioButton_Sensitivities_Global->setToolTip(QApplication::translate("Window_Sensitivities", "<html><head/><body><p>The sensitivity coefficients are analyzed in the whole domain</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        radioButton_Sensitivities_Global->setText(QApplication::translate("Window_Sensitivities", "Global", 0));
#ifndef QT_NO_TOOLTIP
        radioButton_Sensitivities_Region->setToolTip(QApplication::translate("Window_Sensitivities", "<html><head/><body><p>The sensitivity coefficients are analyzed only in the specified region</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        radioButton_Sensitivities_Region->setText(QApplication::translate("Window_Sensitivities", "Region", 0));
#ifndef QT_NO_TOOLTIP
        radioButton_Sensitivities_Local->setToolTip(QApplication::translate("Window_Sensitivities", "<html><head/><body><p>The sensitivity coefficients are analyzed only in the specified location</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        radioButton_Sensitivities_Local->setText(QApplication::translate("Window_Sensitivities", "Local", 0));
        groupBox_6->setTitle(QApplication::translate("Window_Sensitivities", "Ordering", 0));
#ifndef QT_NO_TOOLTIP
        comboBox_Sensitivities_Integral->setToolTip(QApplication::translate("Window_Sensitivities", "<html><head/><body><p>Specifies the strategy to select the most important reactions:</p><p><br/></p><p>1. Peak values: the reactions are ordered by looking only at the absolute peak value of the sensitivity coefficient</p><p><br/></p><p>2.  Area: the reactions are ordered on the basis of the mean integral value (i.e. the area between the sensitivty coefficient profile and the x axis). If the sign of the sensitivity coefficient changes in the considered domain, this area can be very small. </p><p><br/></p><p>3. Absolute Area: the reactions are ordered on the basis of the absolute mean integral value (i.e. the area between the absolute sensitivty coefficient profile and the x axis)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        comboBox_Sensitivities_Integral->setProperty("currentText", QVariant(QString()));
        groupBox->setTitle(QApplication::translate("Window_Sensitivities", "Normalization", 0));
#ifndef QT_NO_TOOLTIP
        radioButton_Sensitivities_NormalizeLocal->setToolTip(QApplication::translate("Window_Sensitivities", "<html><head/><body><p>The sensitivity coefficients are normalized using the local value of the Y variable. This approach can lead to unexpected results when the Y variable approaches zero (for example when the mass fractions are very small)</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        radioButton_Sensitivities_NormalizeLocal->setText(QApplication::translate("Window_Sensitivities", "Local", 0));
#ifndef QT_NO_TOOLTIP
        radioButton__Sensitivities_NormalizeMax->setToolTip(QApplication::translate("Window_Sensitivities", "<html><head/><body><p>The sensitivity coefficients are normalized using the maximum value of the Y variable, evaluated on the whole computational domain.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        radioButton__Sensitivities_NormalizeMax->setText(QApplication::translate("Window_Sensitivities", "Max value", 0));
        groupBox_2->setTitle(QApplication::translate("Window_Sensitivities", "Sensitivity Profiles", 0));
        pushButton_Sensitivities_PlotProfiles->setText(QApplication::translate("Window_Sensitivities", "Plot Profiles", 0));
        label_6->setText(QApplication::translate("Window_Sensitivities", "Reactions", 0));
        label_5->setText(QApplication::translate("Window_Sensitivities", "X Variable", 0));
        pushButton_clean_Reactions->setText(QApplication::translate("Window_Sensitivities", "clean", 0));
        groupBox_3->setTitle(QApplication::translate("Window_Sensitivities", "Report on File", 0));
    } // retranslateUi

};

namespace Ui {
    class Window_Sensitivities: public Ui_Window_Sensitivities {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_SENSITIVITIES_H
