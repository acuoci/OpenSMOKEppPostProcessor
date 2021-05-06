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

#ifndef QBARSWIDGET_H
#define QBARSWIDGET_H

#include <QtCore/QMap>
#include <QtGui/QPixmap>
#include <QtCore/QVector>
#include <QtWidgets/QWidget>
#include <vector>

#include "ui_widget_horizontal_bars.h"

class Widget_Horizontal_Bars : public QWidget
{
	Q_OBJECT

public:
	Widget_Horizontal_Bars(QWidget *parent = 0);
	
	void paintEvent(QPaintEvent *event);

	void setTitle(const QString _title);
	void setMainComment(const QString _comment);
	
	void setRectangles(	const std::vector<double>	_r_coordinates,
						const std::vector<int>      _indices,
						const std::vector<QString>	_names);

	void setRectangles(	const std::vector<double>	_r_coordinates,
						const std::vector<int>      _indices,
						const std::vector<double>   _peaks,
						const std::vector<QString>	_names);

	void setRectangles(	const std::vector<double>		_r_coordinates,
						const std::vector<int>			_indices,
						const std::vector<std::string>	_names);

	void setRectangles(	const std::vector<double>		_r_coordinates,
						const std::vector<int>			_indices,
						const std::vector<double>		_peaks,
						const std::vector<std::string>	_names);

	~Widget_Horizontal_Bars();

private:
	
	Ui::Widget_Horizontal_Bars ui;

	int n_rectangles;
	int n_total_rectangles;
	double h_rectangles;
	QString mainComment;

	std::vector<double> r_coordinates;
	std::vector<double> x_coordinates;
	std::vector<double> y_coordinates;

	std::vector<QString> r_strings;
	std::vector<QString> r_indices;
	std::vector<QString> r_peaks;
	std::vector<QString> r_values;

	void setContextMenu();
	void draw(QPainter *painter);
	void setFonts();
	void prepareText(QString *stringText);

	QAction *copyImageAction;
	QAction *printImageAction;

	QAction *copyTextAction;
	QAction *printTextAction;

	QAction *colorAction;

	QFont font_string;
	QFont font_value;
	QFont font_index;

	QColor color_PlusBars;
	QColor color_MinusBars;

	
	

private slots:

	void copyImage();
	void printImage();

	void copyText();
	void printText();

	void setColors();

private:

	static const int	max_bars;
	static const double h_window;
	static const double w_window;
};

#endif // QBARSWIDGET_H
