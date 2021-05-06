/*-----------------------------------------------------------------------*\
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
|   License                                                               |
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

#ifndef QTOPENSMOKE_POSTPROCESSOR_H
#define QTOPENSMOKE_POSTPROCESSOR_H

#include <boost/filesystem.hpp>

#if QTVERSION == 4
#include <QtGui/QApplication>
#elif QTVERSION == 5
#include <QtWidgets/QApplication>
#endif

#include "ui_qtopensmoke_postprocessor.h"

class Profiles_Database;

class QtOpenSMOKE_PostProcessor : public QMainWindow
{
	Q_OBJECT

public:

	QtOpenSMOKE_PostProcessor(QWidget *parent = 0);
	~QtOpenSMOKE_PostProcessor();

	void SetExeFolder(const boost::filesystem::path folder);

private:

	Ui::QtOpenSMOKE_PostProcessor_Class ui;

private:

	Profiles_Database* data_;

	QString default_folder_results_;
	
	QString default_folder_mechanism_;
	boost::filesystem::path exe_folder_;
	boost::filesystem::path output_folder_;

private slots:
	void ClickSelectMechanismPushButton();
	void ClickSelectResultsPushButton();
	void Show_Window_Profiles();
	void Show_Window_ROPA();
	void Show_Window_Sensitivity();
	void Read_Settings();
	void Write_Settings();

};

#endif // QTOPENSMOKE_POSTPROCESSOR_H
