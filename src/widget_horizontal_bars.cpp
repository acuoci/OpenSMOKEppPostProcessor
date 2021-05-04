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

#include "widget_horizontal_bars.h"
#include <QtWidgets/QMenuBar>
#include <QtGui/QPainter>
#include <QtGui/QClipboard>
#include <QtPrintSupport/QPrintDialog>
#include <QtCore/QTextStream>
#include <QtGui/QImage>
#include <QtGui/QTextDocument>
#include <math.h>
#include <iostream>

// Maximum number of bars
const int		Widget_Horizontal_Bars::max_bars = 20;

// Logical coordinates
const double	Widget_Horizontal_Bars::h_window = 1000;
const double	Widget_Horizontal_Bars::w_window = 1000;


Widget_Horizontal_Bars::Widget_Horizontal_Bars(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);

	setBackgroundRole(QPalette::Light);

	// Colors
	color_PlusBars  = Qt::red;
	color_MinusBars = Qt::blue;

	// Set context menu
	setContextMenu();
}

void Widget_Horizontal_Bars::setContextMenu()
{
	copyImageAction = new QAction(tr("&Copy Image"), this);
	copyImageAction->setStatusTip(tr("Copy bars as image"));
	copyImageAction->setIcon(QIcon(":/Resources/images/icon_copy.png"));
	copyImageAction->setShortcut(QKeySequence::Copy);
	connect(copyImageAction, SIGNAL(triggered()), this, SLOT(copyImage()));

	printImageAction = new QAction(tr("&Print Image"), this);
	printImageAction->setStatusTip(tr("Print bars as image"));
	printImageAction->setIcon(QIcon(":/Resources/images/icon_pen.png"));
	printImageAction->setShortcut(QKeySequence::Print);
	connect(printImageAction, SIGNAL(triggered()), this, SLOT(printImage()));

	copyTextAction = new QAction(tr("Copy Text"), this);
	copyTextAction->setStatusTip(tr("Copy bars as text"));
	copyTextAction->setIcon(QIcon(":/Resources/images/icon_copy.png"));
	connect(copyTextAction, SIGNAL(triggered()), this, SLOT(copyText()));

	printTextAction = new QAction(tr("Print Text"), this);
	printTextAction->setStatusTip(tr("Print bars as text"));
	printTextAction->setIcon(QIcon(":/Resources/images/icon_pen.png"));
	connect(printTextAction, SIGNAL(triggered()), this, SLOT(printText()));

	colorAction = new QAction(tr("Change Color"), this);
	colorAction->setStatusTip(tr("Change bar colors"));
	colorAction->setIcon(QIcon(":/Resources/images/icon_colors.png"));
	connect(colorAction, SIGNAL(triggered()), this, SLOT(setColors()));

	addAction(copyImageAction);
	addAction(printImageAction);
	addAction(copyTextAction);
	addAction(printTextAction);
	addAction(colorAction);
	setContextMenuPolicy(Qt::ActionsContextMenu);
}

void Widget_Horizontal_Bars::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	draw(&painter);
}

void Widget_Horizontal_Bars::draw(QPainter *painter)
{
	painter->setRenderHint(QPainter::Antialiasing, true);

	// Set logical coordinate
	painter->setWindow(-w_window/2.,0, h_window,w_window);

	// Set background color
	painter->setBrush(QBrush(Qt::white, Qt::SolidPattern));
	painter->setPen(QPen(Qt::white, 0.5, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));
	painter->drawRect(-w_window/2., 0, h_window, w_window);

	// Set title
	painter->setPen(QPen(Qt::black, 0.5, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));
	painter->setFont(QFont("Helvetica", h_window/10./4., QFont::Normal));
	painter->drawText(-w_window/2.,0.,w_window,h_window/10., Qt::AlignVCenter| Qt::AlignCenter, mainComment);

	// Set rectangles
	for(int i=0;i<qMin(max_bars, n_rectangles);i++)
	{
		if (x_coordinates[i] >= 0.)	
		{
			painter->setPen(QPen(color_PlusBars, 0.5, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));
			painter->setBrush(QBrush(color_PlusBars, Qt::SolidPattern));

		}
		if (x_coordinates[i] <  0.)	
		{
			painter->setPen(QPen(color_MinusBars, 0.5, Qt::SolidLine, Qt::RoundCap, Qt::MiterJoin));
			painter->setBrush(QBrush(color_MinusBars, Qt::SolidPattern));
		}
		painter->drawRect(0, y_coordinates[i], x_coordinates[i], h_rectangles);

		if (r_peaks.size() == 0)
		{
			painter->setFont(font_index);
			painter->drawText(	-w_window*0.50, y_coordinates[i], 0.10*w_window, h_rectangles, 
							Qt::AlignVCenter | Qt::AlignCenter,	r_indices[i]);
		}
		else
		{
			const std::string tmp = r_indices[i].toStdString() + " (" + r_peaks[i].toStdString() + ")";
			painter->setFont(font_index);
			painter->drawText(	-w_window*0.50, y_coordinates[i], 0.10*w_window, h_rectangles, 
								Qt::AlignVCenter | Qt::AlignCenter,	QString::fromStdString(tmp));
		}

		painter->setFont(font_value);
		painter->drawText(	0.40*w_window, y_coordinates[i], 0.10*w_window, h_rectangles, 
							Qt::AlignVCenter | Qt::AlignRight,	r_values[i]);

		if (x_coordinates[i] >= 0.)
		{
			painter->setFont(font_string);
			painter->drawText(	-w_window*0.42, y_coordinates[i], w_window*0.40, h_rectangles, 
								Qt::AlignVCenter| Qt::AlignRight,	r_strings[i]);

		}

		if (x_coordinates[i]  < 0.)
		{
			painter->setFont(font_string);
			painter->drawText(	w_window*0.02, y_coordinates[i], w_window*0.40, h_rectangles, 
								Qt::AlignVCenter| Qt::AlignLeft,	r_strings[i]);

		}
	}
}

void Widget_Horizontal_Bars::copyImage()
{
	QImage image(width(), height(), QImage::Format_RGB32);
	QPainter painterImage(&image);
	draw(&painterImage);

	QApplication::clipboard()->setImage(image);
}


void Widget_Horizontal_Bars::printImage()
{
//	QPrintDialog printDialog(printer, this);
//	if (printDialog.exec())
//	{
//		QPainter painterPrinter(printer);
//		painterPrinter.setViewport(	painterPrinter.window().width()/2.-width()/2., 
//									painterPrinter.window().height()/10, 
//									width(),height() );
//		draw(&painterPrinter);
//	}
}

void Widget_Horizontal_Bars::prepareText(QString *stringText)
{
	QTextStream textStream(stringText);

	int max_size_string = 0;
	for(int i=0;i<n_rectangles;i++)
		if (r_strings[i].size()>max_size_string)	max_size_string = r_strings[i].size();
	if (max_size_string > 100) max_size_string = 100;

	for(int i=0;i<n_rectangles;i++)
	{
		textStream << left  << qSetFieldWidth(7) << i+1;
		textStream << left  << qSetFieldWidth(max_size_string+2) << r_strings[i];
		textStream << right << qSetFieldWidth(16) << r_values[i];
		textStream << "\n";
	}
}

void Widget_Horizontal_Bars::copyText()
{
	QString stringText;
	prepareText(&stringText);
	QApplication::clipboard()->setText(stringText);
}


void Widget_Horizontal_Bars::printText()
{
//	QString stringText;
//	prepareText(&stringText);

//	QPrintDialog printDialog(printer, this);
//	if (printDialog.exec())
//	{
//		QTextDocument textDocument;
//		textDocument.setPlainText(stringText);
	//	textDocument.print(printer);
	//}
}

void Widget_Horizontal_Bars::setRectangles(const std::vector<double>	_r_coordinates,
								const std::vector<int>					_indices,
								const std::vector<std::string>			_names)
{
	std::vector<QString> _namesQ;
	for(int j=0;j<_names.size();j++)
		_namesQ.push_back(QString::fromStdString(_names[j]));
	
	setRectangles(_r_coordinates, _indices, _namesQ); 
}

void Widget_Horizontal_Bars::setRectangles(const std::vector<double>	_r_coordinates,
								const std::vector<int>					_indices,
								const std::vector<double>				_peaks,
								const std::vector<std::string>			_names)
{
	std::vector<QString> _namesQ;
	for(int j=0;j<_names.size();j++)
		_namesQ.push_back(QString::fromStdString(_names[j]));
	
	setRectangles(_r_coordinates, _indices, _peaks, _namesQ); 
}

void Widget_Horizontal_Bars::setRectangles(const std::vector<double>   _r_coordinates,
								const std::vector<int>      _indices,
								const std::vector<QString>  _names) 
{
	const std::vector<double> _peaks(0);
	setRectangles(_r_coordinates,_indices, _peaks, _names);
}

void Widget_Horizontal_Bars::setRectangles(const std::vector<double>   _r_coordinates,
								const std::vector<int>      _indices, 
								const std::vector<double>   _peaks,
								const std::vector<QString>  _names)
{
	r_coordinates		= _r_coordinates;
	r_strings			= _names;
	n_total_rectangles	= r_coordinates.size();
	n_rectangles		= n_total_rectangles;

	if (n_rectangles < max_bars)
		resize(width(), height()*double(n_rectangles)/double(max_bars));

	h_rectangles = double(0.90*h_window)/double(qMin(max_bars, n_rectangles)) * 0.90;

	x_coordinates.resize(n_rectangles);
	y_coordinates.resize(n_rectangles);
	r_indices.resize(n_rectangles);
	r_values.resize(n_rectangles);
	
	for(int i=0;i<n_rectangles;i++)
	{
		x_coordinates[i] = r_coordinates[i]/fabs(r_coordinates[0]) * (0.40*w_window);
		y_coordinates[i] = h_window*0.10+(1.1*h_rectangles)*i;

		r_indices[i].setNum(_indices[i]); 

		if (fabs(r_coordinates[i]) > 1e-2)	r_values[i].setNum(r_coordinates[i], 'f', 3); 
		else r_values[i].setNum(r_coordinates[i], 'e', 2); 
	}

	if (_peaks.size() == _indices.size())
	{
		r_peaks.resize(n_rectangles);
		for(int i=0;i<n_rectangles;i++)
			r_peaks[i].setNum(_peaks[i],'e',3);
	}
	else
		r_peaks.resize(0);

	setFonts();
}

void Widget_Horizontal_Bars::setFonts()
{
	QString max_string = NULL;
	int max_string_lenght = 0;
	for(int i=0;i<n_rectangles;i++)
		if (r_strings[i].size() > max_string_lenght)
		{
			max_string = r_strings[i];
			max_string_lenght = r_strings[i].size();
		}

	int count = 0;
	int w;
	do
	{
		font_string = QFont("Helvetica", h_rectangles/(3.+double(count++)*0.1), QFont::Normal);
		QFontMetrics fm(font_string);
		w = fm.width(max_string)/double(width())*double(w_window);
	} 
	while (w>=0.40*w_window && count < 10);

	font_value = QFont("Helvetica", h_rectangles/4.5, QFont::Normal);
	font_index = QFont("Helvetica", h_rectangles/4.5, QFont::Normal);
}

void Widget_Horizontal_Bars::setColors()
{
	color_PlusBars = Qt::black;
	color_MinusBars = Qt::gray;
	update();
}

void Widget_Horizontal_Bars::setTitle(const QString _title)
{
	setWindowTitle(_title);
}

void Widget_Horizontal_Bars::setMainComment(const QString _comment)
{
	mainComment = _comment;
}


Widget_Horizontal_Bars::~Widget_Horizontal_Bars()
{

}
