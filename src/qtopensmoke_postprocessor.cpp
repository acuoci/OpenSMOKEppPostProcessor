/*----------------------------------------------------------------------*\
|    ___                   ____  __  __  ___  _  _______                  |
|   / _ \ _ __   ___ _ __ / ___||  \/  |/ _ \| |/ / ____| _     _         |
|  | | | | '_ \ / _ \ '_ \\___ \| |\/| | | | | ' /|  _| _| |_ _| |_       |
|  | |_| | |_) |  __/ | | |___) | |  | | |_| | . \| |__|_   _|_   _|      |
|   \___/| .__/ \___|_| |_|____/|_|  |_|\___/|_|\_\_____||_|   |_|        |
|        |_|                                                              |
|                                                                         |
|   Author: Alberto Cuoci <alberto.cuoci@polimi.it>                       |
|   CRECK Modeling Group <http://creckmodeling.chem.polimi.it>            |
|   Department of Chemistry, Materials and Chemical Engineering           |
|   Politecnico di Milano                                                 |
|   P.zza Leonardo da Vinci 32, 20133 Milano                              |
|                                                                         |
|-------------------------------------------------------------------------|
|                                                                         |
|   This file is part of OpenSMOKE++PostProcessor.                        |
|                                                                         |
|	License                                                               |
|                                                                         |
|   Copyright(C) 2014, 2013  Alberto Cuoci                                |
|   OpenSMOKE++PostProcessor is free software: you can redistribute it    |
|   and/or modify it under the terms of the GNU General Public            |
|   License as published by the Free Software Foundation, either          |
|   version 3 of the License, or (at your option) any later version.      |
|                                                                         |
|   OpenSMOKE++PostProcessor is distributed in the hope that it will be   |
|   useful, but WITHOUT ANY WARRANTY; without even the implied warranty   |
|   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the      |
|   GNU General Public License for more details.                          |
|                                                                         |
|   You should have received a copy of the GNU General Public License     |
|   along with OpenSMOKE++. If not, see <http://www.gnu.org/licenses/>.   |
|                                                                         |
\*-----------------------------------------------------------------------*/

#include "qtopensmoke_postprocessor.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>


// Qt Windows
#include "window_profiles.h"
#include "window_ropa.h"
#include "window_sensitivities.h"

// OpenSMOKE++
#include "Profiles_Database.h"


QtOpenSMOKE_PostProcessor::QtOpenSMOKE_PostProcessor(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	data_ = new Profiles_Database();

	QObject::connect(ui.pushButton_Results,     SIGNAL(clicked()), this, SLOT(ClickSelectResultsPushButton()));
	QObject::connect(ui.pushButton_Mechanism,   SIGNAL(clicked()), this, SLOT(ClickSelectMechanismPushButton()));
	QObject::connect(ui.pushButton_Profiles,    SIGNAL(clicked()), this, SLOT(Show_Window_Profiles()));
	QObject::connect(ui.pushButton_ROPA,        SIGNAL(clicked()), this, SLOT(Show_Window_ROPA()));
	QObject::connect(ui.pushButton_Sensitivity, SIGNAL(clicked()), this, SLOT(Show_Window_Sensitivity()));

	default_folder_results_ = "";
	default_folder_mechanism_ = "";
	Read_Settings();
}

QtOpenSMOKE_PostProcessor::~QtOpenSMOKE_PostProcessor()
{
	Write_Settings();
}

void QtOpenSMOKE_PostProcessor::SetExeFolder(const boost::filesystem::path folder)
{
	exe_folder_ = folder; 
}

void QtOpenSMOKE_PostProcessor::ClickSelectResultsPushButton()
{
	QString output_folder_name;
	{
		QFileDialog dialog(this);
		dialog.setFileMode(QFileDialog::Directory);
		output_folder_name = dialog.getExistingDirectory(this, "Select the folder containing the Output.xml file", default_folder_results_);
	}

	if ( data_->ReadFileResults(output_folder_name) == true)
	{
		default_folder_results_ = output_folder_name;
		ui.pushButton_Mechanism->setEnabled(true);
		ui.pushButton_Profiles->setEnabled(true);
		ui.pushButton_Results->setEnabled(false);
	}

	output_folder_ = output_folder_name.toStdString();
}

void QtOpenSMOKE_PostProcessor::ClickSelectMechanismPushButton()
{
	QString folder_name;
	{
		QFileDialog dialog(this);
		dialog.setFileMode(QFileDialog::Directory);
		folder_name = dialog.getExistingDirectory(this, "Select the folder containing the kinetics.xml file", default_folder_mechanism_);
	}

	if ( data_->ReadKineticMechanism(folder_name) == true)
	{
		default_folder_mechanism_ = folder_name;
		ui.pushButton_Mechanism->setEnabled(false);
		if (data_->iROPAEnabled_ == true)
			ui.pushButton_ROPA->setEnabled(true);
		if (data_->iSensitivityEnabled_ == true)
			ui.pushButton_Sensitivity->setEnabled(true);
	}
}

void QtOpenSMOKE_PostProcessor::Show_Window_Profiles()
{
	Window_Profiles *widget = new Window_Profiles();
	widget->SetDatabase(data_);
	widget->Prepare(); 
	widget->show();
}

void QtOpenSMOKE_PostProcessor::Show_Window_ROPA()
{
	Window_ROPA *widget = new Window_ROPA();
	widget->SetDatabase(data_);
	widget->SetExeFolder(exe_folder_);
	widget->SetOutputFolder(output_folder_);
	widget->Prepare(); 
	widget->show();
}

void QtOpenSMOKE_PostProcessor::Show_Window_Sensitivity()
{
	Window_Sensitivities *widget = new Window_Sensitivities();
	widget->SetDatabase(data_);
	widget->Prepare(); 
	widget->show();
}


void QtOpenSMOKE_PostProcessor::Write_Settings()
 {
     QSettings settings("OpenSMOKE", "OpenSMOKE_PostProcessor");

     settings.beginGroup("Folders");
     settings.setValue("Results", default_folder_results_);
     settings.setValue("Mechanism", default_folder_mechanism_);
     settings.endGroup();
 }

 void QtOpenSMOKE_PostProcessor::Read_Settings()
 {
     QSettings settings("OpenSMOKE", "OpenSMOKE_PostProcessor");

     settings.beginGroup("Folders");
     default_folder_results_ = settings.value("Results").toString();
     default_folder_mechanism_ = settings.value("Mechanism").toString();
     settings.endGroup();
 }




