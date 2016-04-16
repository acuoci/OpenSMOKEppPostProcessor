/********************************************************************************
** Form generated from reading UI file 'window_profiles.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_PROFILES_H
#define UI_WINDOW_PROFILES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_Profiles
{
public:
    QGroupBox *groupBox;
    QRadioButton *radioButton_x;
    QRadioButton *radioButton_omega;
    QRadioButton *radioButton_c;
    QRadioButton *radioButton_p;
    QLabel *label;
    QPushButton *pushButton_Profiles;
    QListWidget *listWidget_Species;
    QListWidget *listWidget_Additional;
    QLabel *label_2;
    QListWidget *listWidget_X;
    QLabel *label_3;
    QSlider *horizontalSlider_Species;
    QPushButton *pushButton_clean_Species;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_Conversion;
    QListWidget *listWidget_Species_Selectivity;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_clean_Species_Selectivity;
    QPushButton *pushButton_Selectivities;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_Selectivity_Mole;
    QRadioButton *radioButton_Selectivity_Mass;
    QRadioButton *radioButton_Selectivity_Element;
    QComboBox *comboBox_Elements;
    QPushButton *pushButton_clean_Additional;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *Window_Profiles)
    {
        if (Window_Profiles->objectName().isEmpty())
            Window_Profiles->setObjectName(QStringLiteral("Window_Profiles"));
        Window_Profiles->resize(1028, 563);
        groupBox = new QGroupBox(Window_Profiles);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(400, 350, 231, 151));
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
        label = new QLabel(Window_Profiles);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 160, 281, 31));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        pushButton_Profiles = new QPushButton(Window_Profiles);
        pushButton_Profiles->setObjectName(QStringLiteral("pushButton_Profiles"));
        pushButton_Profiles->setGeometry(QRect(460, 510, 131, 28));
        listWidget_Species = new QListWidget(Window_Profiles);
        listWidget_Species->setObjectName(QStringLiteral("listWidget_Species"));
        listWidget_Species->setGeometry(QRect(30, 190, 301, 311));
        listWidget_Species->setSelectionMode(QAbstractItemView::MultiSelection);
        listWidget_Additional = new QListWidget(Window_Profiles);
        listWidget_Additional->setObjectName(QStringLiteral("listWidget_Additional"));
        listWidget_Additional->setGeometry(QRect(360, 190, 301, 121));
        listWidget_Additional->setSelectionMode(QAbstractItemView::MultiSelection);
        label_2 = new QLabel(Window_Profiles);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 160, 281, 31));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        listWidget_X = new QListWidget(Window_Profiles);
        listWidget_X->setObjectName(QStringLiteral("listWidget_X"));
        listWidget_X->setGeometry(QRect(200, 50, 291, 91));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget_X->sizePolicy().hasHeightForWidth());
        listWidget_X->setSizePolicy(sizePolicy);
        listWidget_X->setFrameShape(QFrame::StyledPanel);
        listWidget_X->setAutoScroll(false);
        label_3 = new QLabel(Window_Profiles);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(210, 20, 281, 31));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        horizontalSlider_Species = new QSlider(Window_Profiles);
        horizontalSlider_Species->setObjectName(QStringLiteral("horizontalSlider_Species"));
        horizontalSlider_Species->setGeometry(QRect(50, 510, 201, 19));
        horizontalSlider_Species->setMouseTracking(false);
        horizontalSlider_Species->setMaximum(100);
        horizontalSlider_Species->setSingleStep(5);
        horizontalSlider_Species->setTracking(false);
        horizontalSlider_Species->setOrientation(Qt::Horizontal);
        horizontalSlider_Species->setTickPosition(QSlider::NoTicks);
        pushButton_clean_Species = new QPushButton(Window_Profiles);
        pushButton_clean_Species->setObjectName(QStringLiteral("pushButton_clean_Species"));
        pushButton_clean_Species->setGeometry(QRect(270, 510, 51, 21));
        QFont font1;
        font1.setPointSize(8);
        pushButton_clean_Species->setFont(font1);
        groupBox_2 = new QGroupBox(Window_Profiles);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(690, 20, 321, 511));
        comboBox_Conversion = new QComboBox(groupBox_2);
        comboBox_Conversion->setObjectName(QStringLiteral("comboBox_Conversion"));
        comboBox_Conversion->setGeometry(QRect(20, 60, 281, 22));
        listWidget_Species_Selectivity = new QListWidget(groupBox_2);
        listWidget_Species_Selectivity->setObjectName(QStringLiteral("listWidget_Species_Selectivity"));
        listWidget_Species_Selectivity->setGeometry(QRect(10, 130, 301, 171));
        listWidget_Species_Selectivity->setSelectionMode(QAbstractItemView::MultiSelection);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 100, 281, 31));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 30, 281, 31));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);
        pushButton_clean_Species_Selectivity = new QPushButton(groupBox_2);
        pushButton_clean_Species_Selectivity->setObjectName(QStringLiteral("pushButton_clean_Species_Selectivity"));
        pushButton_clean_Species_Selectivity->setGeometry(QRect(260, 310, 51, 21));
        pushButton_clean_Species_Selectivity->setFont(font1);
        pushButton_Selectivities = new QPushButton(groupBox_2);
        pushButton_Selectivities->setObjectName(QStringLiteral("pushButton_Selectivities"));
        pushButton_Selectivities->setGeometry(QRect(100, 310, 121, 28));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(70, 350, 181, 141));
        radioButton_Selectivity_Mole = new QRadioButton(groupBox_3);
        buttonGroup = new QButtonGroup(Window_Profiles);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton_Selectivity_Mole);
        radioButton_Selectivity_Mole->setObjectName(QStringLiteral("radioButton_Selectivity_Mole"));
        radioButton_Selectivity_Mole->setGeometry(QRect(30, 30, 95, 20));
        radioButton_Selectivity_Mole->setChecked(true);
        radioButton_Selectivity_Mass = new QRadioButton(groupBox_3);
        buttonGroup->addButton(radioButton_Selectivity_Mass);
        radioButton_Selectivity_Mass->setObjectName(QStringLiteral("radioButton_Selectivity_Mass"));
        radioButton_Selectivity_Mass->setGeometry(QRect(30, 60, 95, 20));
        radioButton_Selectivity_Element = new QRadioButton(groupBox_3);
        buttonGroup->addButton(radioButton_Selectivity_Element);
        radioButton_Selectivity_Element->setObjectName(QStringLiteral("radioButton_Selectivity_Element"));
        radioButton_Selectivity_Element->setGeometry(QRect(30, 90, 95, 20));
        comboBox_Elements = new QComboBox(groupBox_3);
        comboBox_Elements->setObjectName(QStringLiteral("comboBox_Elements"));
        comboBox_Elements->setEnabled(false);
        comboBox_Elements->setGeometry(QRect(50, 110, 91, 22));
        pushButton_clean_Additional = new QPushButton(Window_Profiles);
        pushButton_clean_Additional->setObjectName(QStringLiteral("pushButton_clean_Additional"));
        pushButton_clean_Additional->setGeometry(QRect(610, 320, 51, 21));
        pushButton_clean_Additional->setFont(font1);

        retranslateUi(Window_Profiles);

        QMetaObject::connectSlotsByName(Window_Profiles);
    } // setupUi

    void retranslateUi(QWidget *Window_Profiles)
    {
        Window_Profiles->setWindowTitle(QApplication::translate("Window_Profiles", "Form", 0));
        groupBox->setTitle(QApplication::translate("Window_Profiles", "Species", 0));
        radioButton_x->setText(QApplication::translate("Window_Profiles", "mole fractions", 0));
        radioButton_omega->setText(QApplication::translate("Window_Profiles", "mass fractions", 0));
        radioButton_c->setText(QApplication::translate("Window_Profiles", "concentrations [kmol/m3]", 0));
        radioButton_p->setText(QApplication::translate("Window_Profiles", "partial pressures [Pa]", 0));
        label->setText(QApplication::translate("Window_Profiles", "Species", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_Profiles->setToolTip(QApplication::translate("Window_Profiles", "<html><head/><body><p>Plots the selected profiles in the Species and Additional Variables Panels</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Profiles->setText(QApplication::translate("Window_Profiles", "Plot profiles", 0));
#ifndef QT_NO_TOOLTIP
        listWidget_Species->setToolTip(QApplication::translate("Window_Profiles", "<html><head/><body><p>The species are reported in alphabetical order</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("Window_Profiles", "Additional variables", 0));
#ifndef QT_NO_TOOLTIP
        listWidget_X->setToolTip(QApplication::translate("Window_Profiles", "<html><head/><body><p>The user can choose the variable to be used as x axis when plotting the profiles of species or additional variables</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        listWidget_X->setWhatsThis(QApplication::translate("Window_Profiles", "<html><head/><body><p>This is the variable used on the x axis</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("Window_Profiles", "X Variable", 0));
#ifndef QT_NO_TOOLTIP
        horizontalSlider_Species->setToolTip(QApplication::translate("Window_Profiles", "<html><head/><body><p>The slide allows to select only the most important species, i.e. species whose peak mass fraction is large.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButton_clean_Species->setToolTip(QApplication::translate("Window_Profiles", "<html><head/><body><p>Removes all the selections</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_clean_Species->setText(QApplication::translate("Window_Profiles", "clean", 0));
        groupBox_2->setTitle(QApplication::translate("Window_Profiles", "Selectivity Analysis", 0));
#ifndef QT_NO_TOOLTIP
        comboBox_Conversion->setToolTip(QApplication::translate("Window_Profiles", "<html><head/><body><p>This is the species with respect to which the selectivities are calculated. Only the species for which the calculation of the conversion is feasible are reported in this list</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        listWidget_Species_Selectivity->setToolTip(QApplication::translate("Window_Profiles", "<html><head/><body><p>The species are reported in alphabetical order</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("Window_Profiles", "Selectivity", 0));
        label_7->setText(QApplication::translate("Window_Profiles", "Conversion", 0));
        pushButton_clean_Species_Selectivity->setText(QApplication::translate("Window_Profiles", "clean", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_Selectivities->setToolTip(QApplication::translate("Window_Profiles", "<html><head/><body><p>Plots the sensitivity profile of the species selected in the Species (Selectivity) Panel with respect to the species selected in the Species (Conversion) Panel.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Selectivities->setText(QApplication::translate("Window_Profiles", "Plot selectivity", 0));
        groupBox_3->setTitle(QApplication::translate("Window_Profiles", "Type", 0));
        radioButton_Selectivity_Mole->setText(QApplication::translate("Window_Profiles", "Mole", 0));
        radioButton_Selectivity_Mass->setText(QApplication::translate("Window_Profiles", "Mass", 0));
        radioButton_Selectivity_Element->setText(QApplication::translate("Window_Profiles", "Element", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_clean_Additional->setToolTip(QApplication::translate("Window_Profiles", "<html><head/><body><p>Removes all the selections</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_clean_Additional->setText(QApplication::translate("Window_Profiles", "clean", 0));
    } // retranslateUi

};

namespace Ui {
    class Window_Profiles: public Ui_Window_Profiles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_PROFILES_H
