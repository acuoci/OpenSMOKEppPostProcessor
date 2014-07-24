/********************************************************************************
** Form generated from reading UI file 'window_ropa.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_ROPA_H
#define UI_WINDOW_ROPA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window_ROPA
{
public:
    QGroupBox *groupBox_3;
    QPushButton *pushButton_AnalyzeCharacteristicTimes;
    QListWidget *listWidget_Reactions;
    QLabel *label_2;
    QSlider *horizontalSlider_Species_ReactionRates;
    QPushButton *pushButton_PlotReactionRates;
    QListWidget *listWidget_Species;
    QLabel *label;
    QListWidget *listWidget_X;
    QLabel *label_3;
    QGroupBox *groupBox;
    QRadioButton *radioButton_formation_mass;
    QRadioButton *radioButton_formation_mole;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_formation_production;
    QRadioButton *radioButton_formation_net;
    QRadioButton *radioButton_formation_destruction;
    QRadioButton *radioButton_formation_characteristictimes;
    QPushButton *pushButton_PlotFormationRates;
    QRadioButton *radioButton_eigenvalues;
    QRadioButton *radioButton_svd;
    QDoubleSpinBox *doubleSpinBox_CharacteristicTimes;
    QPushButton *pushButton_PlotShortestChemicalTime;
    QPushButton *pushButton_clean_ReactionRates;
    QPushButton *pushButton_clean_FormationRates;
    QComboBox *comboBox_Species_ReactionRates;
    QCheckBox *checkBox_Species_ReactionRates;
    QGroupBox *groupBox_4;
    QListWidget *listWidget_ROPA_Species;
    QLabel *label_4;
    QGroupBox *groupBox_5;
    QRadioButton *radioButton_ROPA_Local;
    QRadioButton *radioButton_ROPA_Global;
    QRadioButton *radioButton_ROPA_Region;
    QFrame *line;
    QFrame *line_2;
    QDoubleSpinBox *doubleSpinBox_ROPA_Local;
    QDoubleSpinBox *doubleSpinBox_ROPA_Region_Min;
    QDoubleSpinBox *doubleSpinBox_ROPA_Region_Max;
    QPushButton *pushButton_ROPA_BarChart;
    QLabel *label_5;
    QComboBox *comboBox_ROPA_X;
    QGroupBox *groupBox_6;
    QPushButton *pushButton_ROPA_FluxAnalysis;
    QGroupBox *groupBox_7;
    QRadioButton *radioButton_Labels_Absolute;
    QRadioButton *radioButton_Labels_Relative;
    QGroupBox *groupBox_8;
    QRadioButton *radioButton_Thickness_Absolute;
    QRadioButton *radioButton_Thickness_Relative;
    QCheckBox *checkBox_Thickness_Logarithmic;
    QGroupBox *groupBox_10;
    QSpinBox *spinBox_MaxDepth;
    QLabel *label_8;
    QSpinBox *spinBox_MaxWidth;
    QLabel *label_6;
    QLabel *label_9;
    QComboBox *comboBox_Elements;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_MinThreshold;
    QGroupBox *groupBox_9;
    QRadioButton *radioButton_FluxAnalysis_Production;
    QRadioButton *radioButton_FluxAnalysis_Destruction;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;
    QButtonGroup *buttonGroup_3;
    QButtonGroup *buttonGroup_4;

    void setupUi(QWidget *Window_ROPA)
    {
        if (Window_ROPA->objectName().isEmpty())
            Window_ROPA->setObjectName(QStringLiteral("Window_ROPA"));
        Window_ROPA->resize(1322, 791);
        groupBox_3 = new QGroupBox(Window_ROPA);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 731, 751));
        pushButton_AnalyzeCharacteristicTimes = new QPushButton(groupBox_3);
        pushButton_AnalyzeCharacteristicTimes->setObjectName(QStringLiteral("pushButton_AnalyzeCharacteristicTimes"));
        pushButton_AnalyzeCharacteristicTimes->setGeometry(QRect(460, 70, 201, 28));
        listWidget_Reactions = new QListWidget(groupBox_3);
        listWidget_Reactions->setObjectName(QStringLiteral("listWidget_Reactions"));
        listWidget_Reactions->setGeometry(QRect(300, 210, 411, 371));
        listWidget_Reactions->setSelectionMode(QAbstractItemView::MultiSelection);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 180, 431, 16));
        QFont font;
        font.setPointSize(10);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        horizontalSlider_Species_ReactionRates = new QSlider(groupBox_3);
        horizontalSlider_Species_ReactionRates->setObjectName(QStringLiteral("horizontalSlider_Species_ReactionRates"));
        horizontalSlider_Species_ReactionRates->setEnabled(false);
        horizontalSlider_Species_ReactionRates->setGeometry(QRect(320, 620, 381, 20));
        horizontalSlider_Species_ReactionRates->setMaximum(100);
        horizontalSlider_Species_ReactionRates->setPageStep(5);
        horizontalSlider_Species_ReactionRates->setTracking(false);
        horizontalSlider_Species_ReactionRates->setOrientation(Qt::Horizontal);
        pushButton_PlotReactionRates = new QPushButton(groupBox_3);
        pushButton_PlotReactionRates->setObjectName(QStringLiteral("pushButton_PlotReactionRates"));
        pushButton_PlotReactionRates->setGeometry(QRect(420, 650, 171, 28));
        listWidget_Species = new QListWidget(groupBox_3);
        listWidget_Species->setObjectName(QStringLiteral("listWidget_Species"));
        listWidget_Species->setGeometry(QRect(20, 210, 241, 261));
        listWidget_Species->setSelectionMode(QAbstractItemView::MultiSelection);
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 180, 221, 20));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        listWidget_X = new QListWidget(groupBox_3);
        listWidget_X->setObjectName(QStringLiteral("listWidget_X"));
        listWidget_X->setGeometry(QRect(20, 60, 401, 101));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 30, 381, 20));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 520, 71, 111));
        radioButton_formation_mass = new QRadioButton(groupBox);
        radioButton_formation_mass->setObjectName(QStringLiteral("radioButton_formation_mass"));
        radioButton_formation_mass->setGeometry(QRect(10, 60, 71, 20));
        radioButton_formation_mole = new QRadioButton(groupBox);
        radioButton_formation_mole->setObjectName(QStringLiteral("radioButton_formation_mole"));
        radioButton_formation_mole->setGeometry(QRect(10, 30, 71, 20));
        radioButton_formation_mole->setChecked(true);
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(100, 520, 161, 111));
        radioButton_formation_production = new QRadioButton(groupBox_2);
        radioButton_formation_production->setObjectName(QStringLiteral("radioButton_formation_production"));
        radioButton_formation_production->setGeometry(QRect(10, 40, 111, 20));
        radioButton_formation_net = new QRadioButton(groupBox_2);
        radioButton_formation_net->setObjectName(QStringLiteral("radioButton_formation_net"));
        radioButton_formation_net->setGeometry(QRect(10, 20, 71, 20));
        radioButton_formation_net->setChecked(true);
        radioButton_formation_destruction = new QRadioButton(groupBox_2);
        radioButton_formation_destruction->setObjectName(QStringLiteral("radioButton_formation_destruction"));
        radioButton_formation_destruction->setGeometry(QRect(10, 60, 111, 20));
        radioButton_formation_characteristictimes = new QRadioButton(groupBox_2);
        radioButton_formation_characteristictimes->setObjectName(QStringLiteral("radioButton_formation_characteristictimes"));
        radioButton_formation_characteristictimes->setGeometry(QRect(10, 80, 141, 20));
        pushButton_PlotFormationRates = new QPushButton(groupBox_3);
        pushButton_PlotFormationRates->setObjectName(QStringLiteral("pushButton_PlotFormationRates"));
        pushButton_PlotFormationRates->setGeometry(QRect(40, 640, 181, 28));
        radioButton_eigenvalues = new QRadioButton(groupBox_3);
        buttonGroup = new QButtonGroup(Window_ROPA);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton_eigenvalues);
        radioButton_eigenvalues->setObjectName(QStringLiteral("radioButton_eigenvalues"));
        radioButton_eigenvalues->setGeometry(QRect(470, 140, 95, 20));
        radioButton_eigenvalues->setChecked(true);
        radioButton_svd = new QRadioButton(groupBox_3);
        buttonGroup->addButton(radioButton_svd);
        radioButton_svd->setObjectName(QStringLiteral("radioButton_svd"));
        radioButton_svd->setGeometry(QRect(580, 140, 95, 20));
        radioButton_svd->setChecked(false);
        doubleSpinBox_CharacteristicTimes = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_CharacteristicTimes->setObjectName(QStringLiteral("doubleSpinBox_CharacteristicTimes"));
        doubleSpinBox_CharacteristicTimes->setEnabled(true);
        doubleSpinBox_CharacteristicTimes->setGeometry(QRect(500, 110, 121, 22));
        doubleSpinBox_CharacteristicTimes->setDecimals(6);
        pushButton_PlotShortestChemicalTime = new QPushButton(groupBox_3);
        pushButton_PlotShortestChemicalTime->setObjectName(QStringLiteral("pushButton_PlotShortestChemicalTime"));
        pushButton_PlotShortestChemicalTime->setGeometry(QRect(460, 40, 201, 28));
        pushButton_clean_ReactionRates = new QPushButton(groupBox_3);
        pushButton_clean_ReactionRates->setObjectName(QStringLiteral("pushButton_clean_ReactionRates"));
        pushButton_clean_ReactionRates->setGeometry(QRect(660, 590, 51, 21));
        QFont font1;
        font1.setPointSize(8);
        pushButton_clean_ReactionRates->setFont(font1);
        pushButton_clean_FormationRates = new QPushButton(groupBox_3);
        pushButton_clean_FormationRates->setObjectName(QStringLiteral("pushButton_clean_FormationRates"));
        pushButton_clean_FormationRates->setGeometry(QRect(210, 480, 51, 21));
        pushButton_clean_FormationRates->setFont(font1);
        comboBox_Species_ReactionRates = new QComboBox(groupBox_3);
        comboBox_Species_ReactionRates->setObjectName(QStringLiteral("comboBox_Species_ReactionRates"));
        comboBox_Species_ReactionRates->setEnabled(false);
        comboBox_Species_ReactionRates->setGeometry(QRect(390, 590, 251, 22));
        checkBox_Species_ReactionRates = new QCheckBox(groupBox_3);
        checkBox_Species_ReactionRates->setObjectName(QStringLiteral("checkBox_Species_ReactionRates"));
        checkBox_Species_ReactionRates->setGeometry(QRect(310, 590, 71, 20));
        groupBox_4 = new QGroupBox(Window_ROPA);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(760, 10, 551, 751));
        listWidget_ROPA_Species = new QListWidget(groupBox_4);
        listWidget_ROPA_Species->setObjectName(QStringLiteral("listWidget_ROPA_Species"));
        listWidget_ROPA_Species->setGeometry(QRect(20, 130, 271, 221));
        listWidget_ROPA_Species->setSelectionMode(QAbstractItemView::SingleSelection);
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 100, 221, 20));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(300, 130, 241, 211));
        radioButton_ROPA_Local = new QRadioButton(groupBox_5);
        radioButton_ROPA_Local->setObjectName(QStringLiteral("radioButton_ROPA_Local"));
        radioButton_ROPA_Local->setGeometry(QRect(10, 80, 71, 20));
        radioButton_ROPA_Global = new QRadioButton(groupBox_5);
        radioButton_ROPA_Global->setObjectName(QStringLiteral("radioButton_ROPA_Global"));
        radioButton_ROPA_Global->setGeometry(QRect(90, 20, 71, 20));
        radioButton_ROPA_Global->setChecked(true);
        radioButton_ROPA_Region = new QRadioButton(groupBox_5);
        radioButton_ROPA_Region->setObjectName(QStringLiteral("radioButton_ROPA_Region"));
        radioButton_ROPA_Region->setGeometry(QRect(10, 150, 71, 20));
        line = new QFrame(groupBox_5);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 50, 221, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(groupBox_5);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 110, 221, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        doubleSpinBox_ROPA_Local = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_ROPA_Local->setObjectName(QStringLiteral("doubleSpinBox_ROPA_Local"));
        doubleSpinBox_ROPA_Local->setEnabled(false);
        doubleSpinBox_ROPA_Local->setGeometry(QRect(100, 80, 121, 22));
        doubleSpinBox_ROPA_Local->setDecimals(6);
        doubleSpinBox_ROPA_Region_Min = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_ROPA_Region_Min->setObjectName(QStringLiteral("doubleSpinBox_ROPA_Region_Min"));
        doubleSpinBox_ROPA_Region_Min->setEnabled(false);
        doubleSpinBox_ROPA_Region_Min->setGeometry(QRect(100, 140, 121, 22));
        doubleSpinBox_ROPA_Region_Min->setDecimals(6);
        doubleSpinBox_ROPA_Region_Max = new QDoubleSpinBox(groupBox_5);
        doubleSpinBox_ROPA_Region_Max->setObjectName(QStringLiteral("doubleSpinBox_ROPA_Region_Max"));
        doubleSpinBox_ROPA_Region_Max->setEnabled(false);
        doubleSpinBox_ROPA_Region_Max->setGeometry(QRect(100, 170, 121, 22));
        doubleSpinBox_ROPA_Region_Max->setDecimals(6);
        pushButton_ROPA_BarChart = new QPushButton(groupBox_4);
        pushButton_ROPA_BarChart->setObjectName(QStringLiteral("pushButton_ROPA_BarChart"));
        pushButton_ROPA_BarChart->setGeometry(QRect(350, 60, 171, 28));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 30, 251, 20));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        comboBox_ROPA_X = new QComboBox(groupBox_4);
        comboBox_ROPA_X->setObjectName(QStringLiteral("comboBox_ROPA_X"));
        comboBox_ROPA_X->setGeometry(QRect(20, 60, 271, 22));
        groupBox_6 = new QGroupBox(groupBox_4);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 380, 531, 281));
        pushButton_ROPA_FluxAnalysis = new QPushButton(groupBox_6);
        pushButton_ROPA_FluxAnalysis->setObjectName(QStringLiteral("pushButton_ROPA_FluxAnalysis"));
        pushButton_ROPA_FluxAnalysis->setEnabled(false);
        pushButton_ROPA_FluxAnalysis->setGeometry(QRect(200, 240, 171, 28));
        groupBox_7 = new QGroupBox(groupBox_6);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(330, 140, 181, 80));
        radioButton_Labels_Absolute = new QRadioButton(groupBox_7);
        buttonGroup_3 = new QButtonGroup(Window_ROPA);
        buttonGroup_3->setObjectName(QStringLiteral("buttonGroup_3"));
        buttonGroup_3->addButton(radioButton_Labels_Absolute);
        radioButton_Labels_Absolute->setObjectName(QStringLiteral("radioButton_Labels_Absolute"));
        radioButton_Labels_Absolute->setGeometry(QRect(20, 20, 81, 20));
        radioButton_Labels_Relative = new QRadioButton(groupBox_7);
        buttonGroup_3->addButton(radioButton_Labels_Relative);
        radioButton_Labels_Relative->setObjectName(QStringLiteral("radioButton_Labels_Relative"));
        radioButton_Labels_Relative->setGeometry(QRect(20, 50, 101, 20));
        radioButton_Labels_Relative->setChecked(true);
        groupBox_8 = new QGroupBox(groupBox_6);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(330, 20, 181, 111));
        radioButton_Thickness_Absolute = new QRadioButton(groupBox_8);
        buttonGroup_2 = new QButtonGroup(Window_ROPA);
        buttonGroup_2->setObjectName(QStringLiteral("buttonGroup_2"));
        buttonGroup_2->addButton(radioButton_Thickness_Absolute);
        radioButton_Thickness_Absolute->setObjectName(QStringLiteral("radioButton_Thickness_Absolute"));
        radioButton_Thickness_Absolute->setGeometry(QRect(20, 20, 81, 20));
        radioButton_Thickness_Absolute->setChecked(true);
        radioButton_Thickness_Relative = new QRadioButton(groupBox_8);
        buttonGroup_2->addButton(radioButton_Thickness_Relative);
        radioButton_Thickness_Relative->setObjectName(QStringLiteral("radioButton_Thickness_Relative"));
        radioButton_Thickness_Relative->setGeometry(QRect(20, 50, 101, 20));
        checkBox_Thickness_Logarithmic = new QCheckBox(groupBox_8);
        checkBox_Thickness_Logarithmic->setObjectName(QStringLiteral("checkBox_Thickness_Logarithmic"));
        checkBox_Thickness_Logarithmic->setGeometry(QRect(20, 80, 141, 20));
        checkBox_Thickness_Logarithmic->setChecked(true);
        groupBox_10 = new QGroupBox(groupBox_6);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(20, 99, 291, 121));
        spinBox_MaxDepth = new QSpinBox(groupBox_10);
        spinBox_MaxDepth->setObjectName(QStringLiteral("spinBox_MaxDepth"));
        spinBox_MaxDepth->setGeometry(QRect(50, 40, 46, 22));
        spinBox_MaxDepth->setMaximum(9);
        spinBox_MaxDepth->setValue(2);
        label_8 = new QLabel(groupBox_10);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 80, 53, 16));
        spinBox_MaxWidth = new QSpinBox(groupBox_10);
        spinBox_MaxWidth->setObjectName(QStringLiteral("spinBox_MaxWidth"));
        spinBox_MaxWidth->setGeometry(QRect(50, 80, 46, 22));
        spinBox_MaxWidth->setMinimum(2);
        spinBox_MaxWidth->setMaximum(9);
        spinBox_MaxWidth->setValue(5);
        label_6 = new QLabel(groupBox_10);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(220, 20, 53, 16));
        label_9 = new QLabel(groupBox_10);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(130, 80, 81, 20));
        QFont font2;
        font2.setPointSize(7);
        label_9->setFont(font2);
        comboBox_Elements = new QComboBox(groupBox_10);
        comboBox_Elements->setObjectName(QStringLiteral("comboBox_Elements"));
        comboBox_Elements->setGeometry(QRect(130, 40, 141, 22));
        label_7 = new QLabel(groupBox_10);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 40, 53, 16));
        doubleSpinBox_MinThreshold = new QDoubleSpinBox(groupBox_10);
        doubleSpinBox_MinThreshold->setObjectName(QStringLiteral("doubleSpinBox_MinThreshold"));
        doubleSpinBox_MinThreshold->setGeometry(QRect(210, 80, 62, 22));
        doubleSpinBox_MinThreshold->setDecimals(3);
        doubleSpinBox_MinThreshold->setMinimum(0.001);
        doubleSpinBox_MinThreshold->setMaximum(1);
        doubleSpinBox_MinThreshold->setSingleStep(0.001);
        doubleSpinBox_MinThreshold->setValue(0.01);
        groupBox_9 = new QGroupBox(groupBox_6);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(20, 20, 291, 71));
        radioButton_FluxAnalysis_Production = new QRadioButton(groupBox_9);
        buttonGroup_4 = new QButtonGroup(Window_ROPA);
        buttonGroup_4->setObjectName(QStringLiteral("buttonGroup_4"));
        buttonGroup_4->addButton(radioButton_FluxAnalysis_Production);
        radioButton_FluxAnalysis_Production->setObjectName(QStringLiteral("radioButton_FluxAnalysis_Production"));
        radioButton_FluxAnalysis_Production->setGeometry(QRect(20, 30, 95, 20));
        radioButton_FluxAnalysis_Destruction = new QRadioButton(groupBox_9);
        buttonGroup_4->addButton(radioButton_FluxAnalysis_Destruction);
        radioButton_FluxAnalysis_Destruction->setObjectName(QStringLiteral("radioButton_FluxAnalysis_Destruction"));
        radioButton_FluxAnalysis_Destruction->setGeometry(QRect(150, 30, 95, 20));
        radioButton_FluxAnalysis_Destruction->setChecked(true);

        retranslateUi(Window_ROPA);

        QMetaObject::connectSlotsByName(Window_ROPA);
    } // setupUi

    void retranslateUi(QWidget *Window_ROPA)
    {
        Window_ROPA->setWindowTitle(QApplication::translate("Window_ROPA", "Window_ROPA", 0));
        groupBox_3->setTitle(QApplication::translate("Window_ROPA", "Profiles", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_AnalyzeCharacteristicTimes->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>The characteristic chemical time spectrum can be analyzed at a specific location, according to the following two criteria:</p><p>1. by looking at the eigenvalues of the Jacobian matrix associated to the formation rates</p><p>2. by looking at the singular values of the Jacobian matrix associated to the formation rates</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_AnalyzeCharacteristicTimes->setText(QApplication::translate("Window_ROPA", "Analyze Characteristic Times", 0));
#ifndef QT_NO_TOOLTIP
        listWidget_Reactions->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>When the reaction list is linked to a specific species, the reactions are reported in order of importance (based on the absolute value of the peak). Otherwise the reactions are reported in the same order in which they appear in the kinetic mechanism.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("Window_ROPA", "Reaction Rates", 0));
        pushButton_PlotReactionRates->setText(QApplication::translate("Window_ROPA", "Plot Reaction Rates", 0));
#ifndef QT_NO_TOOLTIP
        listWidget_Species->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>The species are reported in alphabetical order</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Window_ROPA", "Formation rates", 0));
        label_3->setText(QApplication::translate("Window_ROPA", "X Variable", 0));
        groupBox->setTitle(QApplication::translate("Window_ROPA", "Units", 0));
        radioButton_formation_mass->setText(QApplication::translate("Window_ROPA", "mass", 0));
        radioButton_formation_mole->setText(QApplication::translate("Window_ROPA", "mole", 0));
        groupBox_2->setTitle(QApplication::translate("Window_ROPA", "Type", 0));
#ifndef QT_NO_TOOLTIP
        radioButton_formation_production->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>Only the production rate (strictly positive) is reported</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        radioButton_formation_production->setText(QApplication::translate("Window_ROPA", "production", 0));
#ifndef QT_NO_TOOLTIP
        radioButton_formation_net->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>The net formation rates are reported</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        radioButton_formation_net->setText(QApplication::translate("Window_ROPA", "net", 0));
#ifndef QT_NO_TOOLTIP
        radioButton_formation_destruction->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>Only the destruction rate (strictly positive) is reported</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        radioButton_formation_destruction->setText(QApplication::translate("Window_ROPA", "destruction", 0));
#ifndef QT_NO_TOOLTIP
        radioButton_formation_characteristictimes->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>The characteristic chemical time for the selected species is calculated as the ratio between the concentration and the destruction rate</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        radioButton_formation_characteristictimes->setText(QApplication::translate("Window_ROPA", "characteristic times", 0));
        pushButton_PlotFormationRates->setText(QApplication::translate("Window_ROPA", "Plot", 0));
        radioButton_eigenvalues->setText(QApplication::translate("Window_ROPA", "eigenvalues", 0));
        radioButton_svd->setText(QApplication::translate("Window_ROPA", "svd", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_PlotShortestChemicalTime->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>The shortest chemical time scales are evaluated according to the 2 following criteria:</p><p>1. Reciprocal value of the maximum eigenvalue (absolute value)</p><p>2. The smallest ratio between the concentration and the destruction rate of each species</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_PlotShortestChemicalTime->setText(QApplication::translate("Window_ROPA", "Plot shortest time scale", 0));
        pushButton_clean_ReactionRates->setText(QApplication::translate("Window_ROPA", "clean", 0));
        pushButton_clean_FormationRates->setText(QApplication::translate("Window_ROPA", "clean", 0));
#ifndef QT_NO_TOOLTIP
        checkBox_Species_ReactionRates->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>The user can specify a species in order to select only the reactions involving such a species.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        checkBox_Species_ReactionRates->setText(QApplication::translate("Window_ROPA", "Species", 0));
        groupBox_4->setTitle(QApplication::translate("Window_ROPA", "Rate of Production Analysis", 0));
        label_4->setText(QApplication::translate("Window_ROPA", "Species", 0));
        groupBox_5->setTitle(QApplication::translate("Window_ROPA", "Type", 0));
#ifndef QT_NO_TOOLTIP
        radioButton_ROPA_Local->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>The most important reactions are automaticallyselected by looking only at the absolute value of the peak in the location specified by the user</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        radioButton_ROPA_Local->setText(QApplication::translate("Window_ROPA", "Local", 0));
#ifndef QT_NO_TOOLTIP
        radioButton_ROPA_Global->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>The most important reactions are automaticallyselected on the whole computational domain, by looking at the absolute value of the peak</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        radioButton_ROPA_Global->setText(QApplication::translate("Window_ROPA", "Global", 0));
#ifndef QT_NO_TOOLTIP
        radioButton_ROPA_Region->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>The most important reactions are automaticallyselected by looking only at the absolute value of the peaks in the region specified by the user</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        radioButton_ROPA_Region->setText(QApplication::translate("Window_ROPA", "Region", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_ROPA_BarChart->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>Plots the rate of production analysis of the selected species</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_ROPA_BarChart->setText(QApplication::translate("Window_ROPA", "Plot ROPA Bars", 0));
        label_5->setText(QApplication::translate("Window_ROPA", "X Variable", 0));
        groupBox_6->setTitle(QApplication::translate("Window_ROPA", "Flux Analysis", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_ROPA_FluxAnalysis->setToolTip(QApplication::translate("Window_ROPA", "<html><head/><body><p>The flux analysis can be performed only on a local basis. Please, be sure that the Local option is selected in the Type panel.</p><p>In order to draw the flux anlaysis plots, the presence of the Graphviz software on your machine is required. </p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_ROPA_FluxAnalysis->setText(QApplication::translate("Window_ROPA", "Flux Analysis", 0));
        groupBox_7->setTitle(QApplication::translate("Window_ROPA", "Labels", 0));
        radioButton_Labels_Absolute->setText(QApplication::translate("Window_ROPA", "Absolute", 0));
        radioButton_Labels_Relative->setText(QApplication::translate("Window_ROPA", "Relative (%)", 0));
        groupBox_8->setTitle(QApplication::translate("Window_ROPA", "Thickness", 0));
        radioButton_Thickness_Absolute->setText(QApplication::translate("Window_ROPA", "Absolute", 0));
        radioButton_Thickness_Relative->setText(QApplication::translate("Window_ROPA", "Relative (%)", 0));
        checkBox_Thickness_Logarithmic->setText(QApplication::translate("Window_ROPA", "Logarithmic scale", 0));
        groupBox_10->setTitle(QApplication::translate("Window_ROPA", "Options", 0));
        label_8->setText(QApplication::translate("Window_ROPA", "Width", 0));
        label_6->setText(QApplication::translate("Window_ROPA", "Element", 0));
        label_9->setText(QApplication::translate("Window_ROPA", "Threshold(%)", 0));
        label_7->setText(QApplication::translate("Window_ROPA", "Depth", 0));
        groupBox_9->setTitle(QApplication::translate("Window_ROPA", "Type", 0));
        radioButton_FluxAnalysis_Production->setText(QApplication::translate("Window_ROPA", "Production", 0));
        radioButton_FluxAnalysis_Destruction->setText(QApplication::translate("Window_ROPA", "Destruction", 0));
    } // retranslateUi

};

namespace Ui {
    class Window_ROPA: public Ui_Window_ROPA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_ROPA_H
