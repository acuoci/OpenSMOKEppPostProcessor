/********************************************************************************
** Form generated from reading UI file 'qtopensmoke_postprocessor.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTOPENSMOKE_POSTPROCESSOR_H
#define UI_QTOPENSMOKE_POSTPROCESSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtOpenSMOKE_PostProcessor_Class
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton_ROPA;
    QPushButton *pushButton_Mechanism;
    QPushButton *pushButton_Profiles;
    QPushButton *pushButton_Results;
    QPushButton *pushButton_Sensitivity;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *QtOpenSMOKE_PostProcessor_Class)
    {
        if (QtOpenSMOKE_PostProcessor_Class->objectName().isEmpty())
            QtOpenSMOKE_PostProcessor_Class->setObjectName(QStringLiteral("QtOpenSMOKE_PostProcessor_Class"));
        QtOpenSMOKE_PostProcessor_Class->resize(280, 302);
        centralWidget = new QWidget(QtOpenSMOKE_PostProcessor_Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_ROPA = new QPushButton(centralWidget);
        pushButton_ROPA->setObjectName(QStringLiteral("pushButton_ROPA"));
        pushButton_ROPA->setEnabled(false);
        pushButton_ROPA->setGeometry(QRect(40, 160, 211, 28));
        pushButton_Mechanism = new QPushButton(centralWidget);
        pushButton_Mechanism->setObjectName(QStringLiteral("pushButton_Mechanism"));
        pushButton_Mechanism->setEnabled(false);
        pushButton_Mechanism->setGeometry(QRect(80, 60, 131, 28));
        pushButton_Profiles = new QPushButton(centralWidget);
        pushButton_Profiles->setObjectName(QStringLiteral("pushButton_Profiles"));
        pushButton_Profiles->setEnabled(false);
        pushButton_Profiles->setGeometry(QRect(40, 120, 211, 28));
        pushButton_Results = new QPushButton(centralWidget);
        pushButton_Results->setObjectName(QStringLiteral("pushButton_Results"));
        pushButton_Results->setGeometry(QRect(80, 20, 131, 28));
        pushButton_Sensitivity = new QPushButton(centralWidget);
        pushButton_Sensitivity->setObjectName(QStringLiteral("pushButton_Sensitivity"));
        pushButton_Sensitivity->setEnabled(false);
        pushButton_Sensitivity->setGeometry(QRect(40, 200, 211, 28));
        QtOpenSMOKE_PostProcessor_Class->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(QtOpenSMOKE_PostProcessor_Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtOpenSMOKE_PostProcessor_Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtOpenSMOKE_PostProcessor_Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtOpenSMOKE_PostProcessor_Class->setStatusBar(statusBar);
        menuBar = new QMenuBar(QtOpenSMOKE_PostProcessor_Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 280, 26));
        QtOpenSMOKE_PostProcessor_Class->setMenuBar(menuBar);

        retranslateUi(QtOpenSMOKE_PostProcessor_Class);

        QMetaObject::connectSlotsByName(QtOpenSMOKE_PostProcessor_Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtOpenSMOKE_PostProcessor_Class)
    {
        QtOpenSMOKE_PostProcessor_Class->setWindowTitle(QApplication::translate("QtOpenSMOKE_PostProcessor_Class", "QtOpenSMOKE_PostProcessor", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_ROPA->setToolTip(QApplication::translate("QtOpenSMOKE_PostProcessor_Class", "<html><head/><body><p>The rate of production analysis can be performed only if:</p><p>1. The Output.xml file contains the mass fractions profiles of all the species in the kinetic mechanism</p><p>2. The kinetic mechanism has been imported through the Select Mechanism... button</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_ROPA->setText(QApplication::translate("QtOpenSMOKE_PostProcessor_Class", "2. Rate of Production Analysis", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_Mechanism->setToolTip(QApplication::translate("QtOpenSMOKE_PostProcessor_Class", "<html><head/><body><p>The user has to specify the folder containing the kinetics.xml file in which the kinetic mechanism was written after the pre-processing</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Mechanism->setText(QApplication::translate("QtOpenSMOKE_PostProcessor_Class", "Select Mechanism ...", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_Profiles->setToolTip(QApplication::translate("QtOpenSMOKE_PostProcessor_Class", "<html><head/><body><p>In order to plot the profiles of the species and the additional variables only the Output.xml file is required (i.e. the User does not have to import also the kinetic.xml file). However, without importing the kinetic.xml file, the possibility to plot the selectivity profiles is not enabled.</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Profiles->setText(QApplication::translate("QtOpenSMOKE_PostProcessor_Class", "1. Profiles", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_Results->setToolTip(QApplication::translate("QtOpenSMOKE_PostProcessor_Class", "<html><head/><body><p>The user has to specify the folder containing the Output.xml file in which the simulation results are reported</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Results->setText(QApplication::translate("QtOpenSMOKE_PostProcessor_Class", "Select Results ...", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_Sensitivity->setToolTip(QApplication::translate("QtOpenSMOKE_PostProcessor_Class", "<html><head/><body><p>The sensitivity analysis can be performed only if:</p><p>1. The simulation was performed by exporting the sensitivity coefficients (i.e. the Sensitivities.xml file must be available in the same folder containing the Output.xml file)</p><p>2. the kinetic mechanism has been imported through the Select Mechanism... button</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Sensitivity->setText(QApplication::translate("QtOpenSMOKE_PostProcessor_Class", "3. Sensitivity Analysis", 0));
    } // retranslateUi

};

namespace Ui {
    class QtOpenSMOKE_PostProcessor_Class: public Ui_QtOpenSMOKE_PostProcessor_Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTOPENSMOKE_POSTPROCESSOR_H
