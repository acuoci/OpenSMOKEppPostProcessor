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

#include "window_zoom_2dplot.h"

Window_Zoom_2dPlot::Window_Zoom_2dPlot(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.pushButton_OK, SIGNAL(released()), this, SLOT(accept()));
	QObject::connect(ui.pushButton_Cancel, SIGNAL(released()), this, SLOT(reject()));
}

Window_Zoom_2dPlot::~Window_Zoom_2dPlot()
{

}

void Window_Zoom_2dPlot::SetMinAndMaxValues(const double min_x, const double max_x, const double min_y, const double max_y)
{
	ui.doubleSpinBox_xmin->setMinimum(min_x);
	ui.doubleSpinBox_xmin->setMaximum(max_x);
	ui.doubleSpinBox_xmax->setMinimum(min_x);
	ui.doubleSpinBox_xmax->setMaximum(max_x);

	ui.doubleSpinBox_ymin->setMinimum(min_y);
	ui.doubleSpinBox_ymin->setMaximum(max_y);
	ui.doubleSpinBox_ymax->setMinimum(min_y);
	ui.doubleSpinBox_ymax->setMaximum(max_y);

	ui.doubleSpinBox_xmin->setDecimals(12);
	ui.doubleSpinBox_xmin->setSingleStep((max_x-min_x)/100.);
	ui.doubleSpinBox_xmax->setDecimals(12);
	ui.doubleSpinBox_xmax->setSingleStep((max_x-min_x)/100.);
	ui.doubleSpinBox_ymin->setDecimals(12);
	ui.doubleSpinBox_ymin->setSingleStep((max_y-min_y)/100.);
	ui.doubleSpinBox_ymax->setDecimals(12);
	ui.doubleSpinBox_ymax->setSingleStep((max_y-min_y)/100.);

}

void Window_Zoom_2dPlot::SetCurrentValues(const double min_x, const double max_x, const double min_y, const double max_y)
{
	ui.doubleSpinBox_xmin->setValue(min_x);
	ui.doubleSpinBox_xmax->setValue(max_x);
	ui.doubleSpinBox_ymin->setValue(min_y);
	ui.doubleSpinBox_ymax->setValue(max_y);
}
