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

#ifndef QTOPENSMOKE_XYPlot_H
#define QTOPENSMOKE_XYPlot_H

#include <QObject>
#include "qcustomplot.h"

class XYPlot : public QObject
{
	Q_OBJECT

public:
	XYPlot(QObject *parent);
	~XYPlot();

public:

	void SetXTitle(const QString title_x);
	void SetYTitle(const QString title_y);
	void SetAbscissas(const QVector<double>& abscissas);
	void AddGraph(const std::string name, const QVector<double>& y);
	void Plot();

public slots:

	void ShowContextMenu(const QPoint& pos);
	void Rescale();
	void PaletteSwitching();
	void SaveAsPDF();
	void SaveAsBMP();
	void SaveAsJPG();
	void SaveAsPNG();
	void SwitchXScale();
	void SwitchYScale();
	void Normalize();
	void ExportToFile();
	void CustomZoom();

private:

	QCustomPlot* customPlot;

	QString title_x_;
	QString title_y_;

	double min_x_;
	double min_y_;
	double max_x_;
	double max_y_;
	QVector<double> x_;
	std::vector< QVector<double> > y_;
	std::vector<Qt::GlobalColor> colors_;
	std::vector<Qt::GlobalColor> colors_bw_;
	std::vector<Qt::PenStyle> styles_bw_;
	std::vector<QString> names_;

	bool color_palette_;
	bool linear_scale_x_;
	bool linear_scale_y_;
	bool normalized_profiles_;

	void SetMinAndMax();

};

#endif // QTOPENSMOKE_XYPlot_H
