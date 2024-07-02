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

#ifndef WINDOW_SENSITIVITIES_H
#define WINDOW_SENSITIVITIES_H

#include <QtCore/QtGlobal>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QtWidgets/QWidget>
#else
#include <QtGui>
#endif

#include "ui_window_sensitivities.h"

class Profiles_Database;
class Sensitivities_Database;

class Window_Sensitivities : public QWidget
{
	Q_OBJECT

public:
	Window_Sensitivities(QWidget *parent = 0);
	~Window_Sensitivities();

public:

	void SetDatabase(Profiles_Database* data);
	void Prepare();

private:
	Ui::Window_Sensitivities ui;

	Profiles_Database* data_;
	Sensitivities_Database* sensitivities;

private slots:

	void Clean_Reactions_List();

	void Plot_Sensitivities_Profiles();
	void Plot_Sensitivities_BarChart();

	void Clicked_Sensitivities_Local();
	void Clicked_Sensitivities_Region();
	void Clicked_Sensitivities_Global();

	void UpdateListOfReactions();
	void ReadSensitvityCoefficients();
};

//#include "window_sensitivities.cpp"

#endif // WINDOW_SENSITIVITIES_H
