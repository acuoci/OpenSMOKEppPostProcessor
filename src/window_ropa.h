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

#ifndef QTOPENSMOKE_Window_ROPA_H
#define QTOPENSMOKE_Window_ROPA_H

#include <boost/filesystem.hpp>
#include <QtCore/QtGlobal>
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#  include <QtWidgets/QWidget>
#else
#  include <QtGui>
#endif
#include "ui_window_ropa.h"


class Profiles_Database;
class XYPlot;

class Window_ROPA : public QWidget
{
	Q_OBJECT

public:
	Window_ROPA(QWidget *parent = 0);
	~Window_ROPA();

private:
	Ui::Window_ROPA ui;

public:

	void SetDatabase(Profiles_Database* data);
	void SetExeFolder(const boost::filesystem::path folder);
	void SetOutputFolder(const boost::filesystem::path folder);

	void Prepare();

private:

	boost::filesystem::path exe_folder_;
	boost::filesystem::path output_folder_;

	Profiles_Database* data_;
	std::vector<unsigned int> indices_coarse_reactions_;
	QStringList string_list_reactions;
	void SetXAxisForXYPlotting(XYPlot* xyplot);

private slots:
	void Plot_FormationRates();
	void Plot_ReactionRates();
	void AnalyzeCharacteristicTimes();
	void PlotShortestChemicalTime();
	void Plot_ROPA_BarChart();
	void Plot_FluxAnalysis();

	void Clicked_ROPA_Local();
	void Clicked_ROPA_Region();
	void Clicked_ROPA_Global();

	void Clean_FormationRates_List();
	void Clean_ReactionRates_List();

	void UpdateCheckBox();
	void UpdateListOfReactions();
};

//#include "window_ropa.cpp"

#endif // QTOPENSMOKE_Window_ROPA_H
