/*----------------------------------------------------------------------*\
|     ____                    ______ __  __  ____  _  ________            |
|    / __ \                  /  ___ |  \/  |/ __ \| |/ /  ____|           |
|   | |  | |_ __   ___ _ __ |  (___ | \  / | |  | | ' /| |__              |
|   | |  | | '_ \ / _ \ '_ \ \___  \| |\/| | |  | |  < |  __|             |
|   | |__| | |_) |  __/ | | |____)  | |  | | |__| | . \| |____            |
|    \____/| .__/ \___|_| |_|______/|_|  |_|\____/|_|\_\______|           |
|          | |                                                            |
|          |_|                                                            |
|                                                                         |
|   CRECK Modeling Group <http://creckmodeling.chem.polimi.it>            |
|   Department of Chemistry, Materials and Chemical Engineering           |
|   Politecnico di Milano                                                 |
|   Author: Alberto Cuoci <alberto.cuoci@polimi.it>                       |
|	Date: 07 Mar 2013                                                     |
|-------------------------------------------------------------------------|
|	License                                                               |
|                                                                         |
|   This file is part of OpenSMOKE.                                       |
|                                                                         |
|   OpenSMOKE is free software: you can redistribute it and/or modify     |
|   it under the terms of the GNU General Public License as published by  |
|   the Free Software Foundation, either version 3 of the License, or     |
|   (at your option) any later version.                                   |
|                                                                         |
|   OpenSMOKE is distributed in the hope that it will be useful,          |
|   but WITHOUT ANY WARRANTY; without even the implied warranty of        |
|   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         |
|   GNU General Public License for more details.                          |
|                                                                         |
|   You should have received a copy of the GNU General Public License     |
|   along with OpenSMOKE. If not, see <http://www.gnu.org/licenses/>.     |
|                                                                         |
\*-----------------------------------------------------------------------*/

#ifndef QTOPENSMOKE_POSTPROCESSOR_H
#define QTOPENSMOKE_POSTPROCESSOR_H

#include <boost/filesystem.hpp>
//#include <QtGui/QApplication>
#include <QtWidgets/QApplication>
#include "ui_qtopensmoke_postprocessor.h"
#include "rapidxml.hpp"

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
