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

#include "xyplot.h"
#include <QMessageBox>
#include <QMenu>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "window_zoom_2dplot.h"

double Min(const QVector<double>& v);
double Max(const QVector<double>& v);

XYPlot::XYPlot(QObject *parent)
	: QObject(parent)
{
	customPlot = new QCustomPlot();
	colors_.resize(10);
	colors_[0] = Qt::red;
	colors_[1] = Qt::blue;
	colors_[2] = Qt::green;
	colors_[3] = Qt::cyan;
	colors_[4] = Qt::magenta;
	colors_[5] = Qt::gray;
	colors_[6] = Qt::darkRed;
	colors_[7] = Qt::darkBlue;
	colors_[8] = Qt::darkBlue;
	colors_[9] = Qt::darkCyan;

	colors_bw_.resize(10);
	styles_bw_.resize(10);
	colors_bw_[0] = Qt::black;			styles_bw_[0] = Qt::SolidLine;
	colors_bw_[1] = Qt::black;			styles_bw_[1] = Qt::DashLine;
	colors_bw_[2] = Qt::black;			styles_bw_[2] = Qt::DotLine;
	colors_bw_[3] = Qt::black;			styles_bw_[3] = Qt::DashDotLine;
	colors_bw_[4] = Qt::black;			styles_bw_[4] = Qt::DashDotDotLine;
	colors_bw_[5] = Qt::gray;			styles_bw_[5] = Qt::SolidLine;
	colors_bw_[6] = Qt::gray;			styles_bw_[6] = Qt::DashLine;
	colors_bw_[7] = Qt::gray;			styles_bw_[7] = Qt::DotLine;
	colors_bw_[8] = Qt::gray;			styles_bw_[8] = Qt::DashDotLine;
	colors_bw_[9] = Qt::gray;			styles_bw_[9] = Qt::DashDotDotLine;

	QObject::connect(customPlot, SIGNAL(mouseDoubleClick(QMouseEvent*) ), this, SLOT(Rescale()));

	customPlot->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(customPlot, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(ShowContextMenu(const QPoint&)));

	color_palette_ = true;
	linear_scale_x_ = true;
	linear_scale_y_ = true;
	normalized_profiles_ = false;
}

XYPlot::~XYPlot()
{

}

void XYPlot::Rescale()
{
	if (normalized_profiles_ == false)
	{
		customPlot->xAxis->setRange(min_x_, max_x_);
		customPlot->yAxis->setRange(min_y_, max_y_);
	}
	else
	{
		customPlot->xAxis->setRange(min_x_, max_x_);
		customPlot->yAxis->setRange(-1, 1);
	}
	customPlot->replot();
}

void XYPlot::SetXTitle(const QString title_x)
{
	title_x_ = title_x;
}

void XYPlot::SetYTitle(const QString title_y)
{
	title_y_ = title_y;
}


void XYPlot::SetAbscissas(const QVector<double>& x)
{
	x_ = x;
}

void XYPlot::AddGraph(const std::string name, const QVector<double>& y)
{
	y_.push_back(y);
	names_.push_back(QString::fromStdString(name));
}

void XYPlot::SetMinAndMax()	
{
	min_y_ =  1.e100;
	max_y_ = -1.e100;
	min_x_ =  1.e100;
	max_x_ = -1.e100;
	
	for(unsigned int j=0;j<x_.size();j++)
		if (x_[j] < min_x_)	min_x_ = x_[j];	
	for(unsigned int j=0;j<x_.size();j++)
		if (x_[j] > max_x_)	max_x_ = x_[j];

	for(unsigned int i=0;i<y_.size();i++)
		for(unsigned int j=0;j<y_[i].size();j++)
			if (y_[i][j] < min_y_)	min_y_ = y_[i][j];
	for(unsigned int i=0;i<y_.size();i++)
		for(unsigned int j=0;j<y_[i].size();j++)
			if (y_[i][j] > max_y_)	max_y_ = y_[i][j];

	if (min_y_>0.)	min_y_ *= 0.99;
	else			min_y_ *= 1.01;

	if (max_y_>0.)	max_y_ *= 1.01;
	else			max_y_ *= 0.99;
}	

void XYPlot::Plot()
{
	customPlot->xAxis->setLabel(title_x_);
	customPlot->yAxis->setLabel(title_y_);
	
	SetMinAndMax();
	customPlot->xAxis->setRange(min_x_, max_x_);
	customPlot->yAxis->setRange(min_y_, max_y_);

	customPlot->legend->setVisible(true);
	QFont legendFont("Times", 10, QFont::Bold);   
	legendFont.setPointSize(9); 
	customPlot->legend->setFont(legendFont);
	customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight | Qt::AlignTop);
	customPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));
	customPlot->axisRect()->setupFullAxesBox(true);
	customPlot->axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
	customPlot->axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);
	customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

	for(unsigned int i=0;i<y_.size();i++)
	{
		QPen pen;
		pen.setColor(colors_[i]);
		pen.setWidthF(3);

		customPlot->addGraph();
		customPlot->graph(i)->setData(x_, y_[i]);
		customPlot->graph(i)->setPen(pen);
		customPlot->graph(i)->setName(names_[i]);
	}

	customPlot->replot();
	
	QDesktopWidget widget;
	QRect screenSize = widget.availableGeometry(widget.primaryScreen());
	customPlot->resize(screenSize.width() * 0.30, screenSize.height() * 0.35 );
	customPlot->show();
}

void XYPlot::ShowContextMenu(const QPoint& pos) // this is a slot
{
	QPoint globalPos = customPlot->mapToGlobal(pos);

    QMenu myMenu;	 
    
	QAction* rescale = new QAction("Rescale", &myMenu);
	QAction* palette_switching = new QAction("Switch the palette", &myMenu);
	QAction* save_as_bmp = new QAction("Save as bmp...", &myMenu);
	QAction* save_as_pdf = new QAction("Save as pdf...", &myMenu);
	QAction* save_as_png = new QAction("Save as png...", &myMenu);
	QAction* save_as_jpg = new QAction("Save as jpg...", &myMenu);
	QAction* switch_x_scale = new QAction("Switch x scale (lin/log)...", &myMenu);
	QAction* switch_y_scale = new QAction("Switch y scale (lin/log)...", &myMenu);
	QAction* normalize_profiles = new QAction("Normalize profiles...", &myMenu);
	QAction* export_to_file = new QAction("Export to file...", &myMenu);
	QAction* custom_zoom = new QAction("Zoom...", &myMenu);

	myMenu.addAction(rescale);
	myMenu.addAction(palette_switching);
	myMenu.addAction(save_as_bmp);
	myMenu.addAction(save_as_pdf);
	myMenu.addAction(save_as_png);
	myMenu.addAction(save_as_jpg);
	myMenu.addAction(switch_x_scale);
	myMenu.addAction(switch_y_scale);
	myMenu.addAction(normalize_profiles);
	myMenu.addAction(export_to_file);
	myMenu.addAction(custom_zoom);

	connect(rescale, SIGNAL(triggered()), this, SLOT(Rescale()));
	connect(palette_switching, SIGNAL(triggered()), this, SLOT(PaletteSwitching()));
	connect(save_as_bmp, SIGNAL(triggered()), this, SLOT(SaveAsBMP()));
	connect(save_as_pdf, SIGNAL(triggered()), this, SLOT(SaveAsPDF()));
	connect(save_as_png, SIGNAL(triggered()), this, SLOT(SaveAsPNG()));
	connect(save_as_jpg, SIGNAL(triggered()), this, SLOT(SaveAsJPG()));
	connect(switch_x_scale, SIGNAL(triggered()), this, SLOT(SwitchXScale()));
	connect(switch_y_scale, SIGNAL(triggered()), this, SLOT(SwitchYScale()));
	connect(normalize_profiles, SIGNAL(triggered()), this, SLOT(Normalize()));
	connect(export_to_file, SIGNAL(triggered()), this, SLOT(ExportToFile()));
	connect(custom_zoom, SIGNAL(triggered()), this, SLOT(CustomZoom()));

    myMenu.exec(globalPos);
}

void XYPlot::SwitchXScale()
{
	if (linear_scale_x_ == true)
	{
		linear_scale_x_ = false;
        customPlot->xAxis->setScaleType(QCPAxis::stLogarithmic);
	}
	else
	{
		linear_scale_x_ = true;
        customPlot->xAxis->setScaleType(QCPAxis::stLinear);
	}
	customPlot->replot();
}

void XYPlot::SwitchYScale()
{
	if (linear_scale_y_ == true)
	{
		linear_scale_y_ = false;
        customPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);
	}
	else
	{
		linear_scale_y_ = true;
        customPlot->yAxis->setScaleType(QCPAxis::stLinear);
	}
	customPlot->replot();
}

void XYPlot::PaletteSwitching()
{
	if (color_palette_ == true)
	{
		color_palette_ = false;
		
		for(unsigned int i=0;i<y_.size();i++)
		{
			QPen pen;
			pen.setColor(colors_bw_[i]);
			pen.setStyle(styles_bw_[i]);
			pen.setWidthF(3);
			customPlot->graph(i)->setPen(pen);
		}
	}
	else
	{
		color_palette_ = true;
		
		for(unsigned int i=0;i<y_.size();i++)
		{
			QPen pen;
			pen.setColor(colors_[i]);
			pen.setWidthF(3);
			customPlot->graph(i)->setPen(pen);
		}
	}

	customPlot->replot();
}

void XYPlot::SaveAsPDF()
{
	QString filename = QFileDialog::getSaveFileName(customPlot, "Save file", "", ".pdf");
	customPlot->savePdf(filename+".pdf");
}

void XYPlot::SaveAsBMP()
{
	QString filename = QFileDialog::getSaveFileName(customPlot, "Save file", "", ".bmp");
	customPlot->saveBmp(filename+".bmp");
}

void XYPlot::SaveAsJPG()
{
	QString filename = QFileDialog::getSaveFileName(customPlot, "Save file", "", ".jpg");
	customPlot->saveJpg(filename+".jpg");
}

void XYPlot::SaveAsPNG()
{
	QString filename = QFileDialog::getSaveFileName(customPlot, "Save file", "", ".png");
	customPlot->savePng(filename+".png");
}

void XYPlot::CustomZoom()
{
	Window_Zoom_2dPlot* zoom_window = new Window_Zoom_2dPlot(0);
	zoom_window->setModal(true);
	zoom_window->SetMinAndMaxValues(min_x_, max_x_, min_y_, max_y_);
	zoom_window->SetCurrentValues(	customPlot->xAxis->range().lower, customPlot->xAxis->range().upper,
									customPlot->yAxis->range().lower, customPlot->yAxis->range().upper);

	zoom_window->exec();

	if (zoom_window->result() == Window_Zoom_2dPlot::Accepted)
	{
		customPlot->xAxis->setRange(zoom_window->xmin(), zoom_window->xmax());
		customPlot->yAxis->setRange(zoom_window->ymin(), zoom_window->ymax());
		customPlot->replot();
	}
}

void XYPlot::Normalize()
{
	if (normalized_profiles_ == false)
	{
		normalized_profiles_ = true;
		for(unsigned int i=0;i<y_.size();i++)
		{
			double min_y = Min(y_[i]);
			double max_y = Max(y_[i]);
			QVector<double> ytmp(y_[i].size());
			if (max_y != 0.)
				for(unsigned int j=0;j<y_[i].size();j++)
					ytmp[j] = y_[i][j]/max_y;

			customPlot->graph(i)->setData(x_, ytmp);
		}
		customPlot->yAxis->setRange(-1, 1);
	}
	else
	{
		normalized_profiles_ = false;
		for(unsigned int i=0;i<y_.size();i++)
		{
			customPlot->graph(i)->setData(x_, y_[i]);
		}
		customPlot->yAxis->setRange(min_y_, max_y_);
	}
	customPlot->replot();
}

void XYPlot::ExportToFile()
{
	QString filename = QFileDialog::getSaveFileName(customPlot, "Save file", "", "");
	
	// Open output file
	std::ofstream fOut;
	fOut.open(filename.toStdString().c_str(), std::ios::out);
	fOut.setf(std::ios::scientific);

	// Write first line 
	fOut << std::left << std::setw(16) << "x(1)";
	for(unsigned int i=0;i<y_.size();i++)
	{
		std::stringstream label;
		label << names_[i].toStdString() << "(" << i+2 << ")";
		fOut << std::left << std::setw(16) << label.str();
	}
	fOut << std::endl;

	// Write values
	for(unsigned int k=0;k<x_.size();k++)
	{
		fOut << std::left << std::setw(16) << x_[k];
		for(unsigned int i=0;i<y_.size();i++)
			fOut << std::left << std::setw(16) << y_[i][k];
		fOut << std::endl;
	}

	fOut.close();
}

double Min(const QVector<double>& v)
{
	double min_v = 1.e100;
	for(unsigned int i=0;i<v.size();i++)
		if (v[i] < min_v) min_v = v[i];
	return min_v;
}

double Max(const QVector<double>& v)
{
	double max_v = -1.e100;
	for(unsigned int i=0;i<v.size();i++)
		if (v[i] > max_v) max_v = v[i];
	return max_v;
}

