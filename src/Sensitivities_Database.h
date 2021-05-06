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

#ifndef QTOPENSMOKE_Sensitivities_Database_H
#define QTOPENSMOKE_Sensitivities_Database_H

#include <QtCore/QObject>

#if QTVERSION == 4
#include <QtGui/QMainWindow>
#elif QTVERSION == 5
#include <QtWidgets/QMainWindow>
#endif

#include <boost/property_tree/ptree.hpp>

class Profiles_Database;

class Sensitivities_Database
{
public:
	Sensitivities_Database(void);
	~Sensitivities_Database(void);

	void SetDatabase(Profiles_Database* data);

	void ReadParentFile();
	void ReadFromChildFile(const std::string name);
	QVector<double> NormalizedProfile(const unsigned int index, bool local_normalization);
	double NormalizedProfile(const unsigned int index, bool local_normalization, unsigned int point);

	boost::property_tree::ptree xml_main_input;

	const std::vector<std::string>& names() const { return names_; }
	unsigned int number_of_variables() const { return number_of_variables_; }
	const QVector<double>& variable() const { return variable_; }

	const QStringList& string_list_reactions() const { return string_list_reactions_; }
	const std::vector<unsigned int>& current_coarse_index() const { return current_coarse_index_; }

	void ReactionsCoarsening(const double threshold);
	void ReactionsReset();

	unsigned int number_of_parameters() const { return number_of_parameters_; }


private:

	Profiles_Database* data_;
	unsigned int number_of_variables_;
	unsigned int number_of_parameters_;
	unsigned int number_of_points_;
	unsigned int number_of_species_;
	std::vector<unsigned int> local_index_;
	std::vector<unsigned int> global_index_;
	std::vector<std::string> names_;
	std::vector<QVector<double> > coefficients_;
	std::vector<double> parameters_;

	QVector<double> variable_;
	unsigned int current_local_index_;

	QStringList string_list_reactions_;
	std::vector<unsigned int> current_coarse_index_;
};

#endif // QTOPENSMOKE_Sensitivities_Database_H



