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

#ifndef QTOPENSMOKE_Sensitivities_Database_H
#define QTOPENSMOKE_Sensitivities_Database_H

#include <QObject>
//#include <QtGui/QMainWindow>
#include <QtWidgets/QMainWindow>
#include "rapidxml.hpp"

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


	rapidxml::xml_document<> xml_main_input;
	std::vector<char> xml_main_input_string;

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



