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
|	License                                                           |
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

#ifndef WINDOW_ZOOM_2DPLOT_H
#define WINDOW_ZOOM_2DPLOT_H

#include <QDialog>
#include "ui_window_zoom_2dplot.h"

class Window_Zoom_2dPlot : public QDialog
{
	Q_OBJECT

public:
	Window_Zoom_2dPlot(QWidget *parent = 0);
	~Window_Zoom_2dPlot();

	void SetMinAndMaxValues(const double min_x, const double max_x, const double min_y, const double max_y);
	void SetCurrentValues(const double min_x, const double max_x, const double min_y, const double max_y);

	const double xmin() const { return ui.doubleSpinBox_xmin->value(); }
	const double xmax() const { return ui.doubleSpinBox_xmax->value(); }
	const double ymin() const { return ui.doubleSpinBox_ymin->value(); }
	const double ymax() const { return ui.doubleSpinBox_ymax->value(); }

private:
	Ui::Window_Zoom_2dPlot ui;
};

#endif // WINDOW_ZOOM_2DPLOT_H
