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

#ifndef QTOPENSMOKE_Profiles_Database_H
#define QTOPENSMOKE_Profiles_Database_H

#include <QObject>
//#include <QtGui/QMainWindow>
#include <QtWidgets/QMainWindow>
#include "rapidxml.hpp"
#include <boost/filesystem.hpp>

namespace OpenSMOKE
{
	template<typename T>
	class ThermodynamicsMap_CHEMKIN;
	template<typename T>
	class KineticsMap_CHEMKIN;
}

class Profiles_Database
{
public:
	Profiles_Database(void);
	~Profiles_Database(void);

	bool ReadKineticMechanism(const QString& folder_name);
	bool ReadFileResults(const QString& folder_name);
	void Prepare();
	void SpeciesCoarsening(const double threshold);

	unsigned int number_of_abscissas_;
	unsigned int number_of_ordinates_;

	QVector<int> column_index_of_massfractions_profiles;
	QStringList string_list_additional;
	QVector<int> list_of_conversion_species_;

	QStringList string_list_massfractions_sorted;
	QVector<int> sorted_index;
	QVector<int> current_sorted_index;
	QVector<double> sorted_max;

	QVector< QVector<double> > omega;
	QVector< QVector<double> > additional;

	unsigned int index_T;
	unsigned int index_P;
	unsigned int index_MW;
	unsigned int index_density;
	unsigned int index_velocity;
	unsigned int index_mass_flow_rate;

	QVector<double> mw_species_;

	rapidxml::xml_document<> xml_main_input;
	std::vector<char> xml_main_input_string;

	OpenSMOKE::ThermodynamicsMap_CHEMKIN<double>* thermodynamicsMapXML; 
	OpenSMOKE::KineticsMap_CHEMKIN<double>* kineticsMapXML; 

	bool iSensitivityEnabled_;
	bool iROPAEnabled_;
	bool is_kinetics_available_;

	boost::filesystem::path path_folder_results_;
	boost::filesystem::path path_folder_mechanism_;

	void ReactionsAssociatedToSpecies(const unsigned int index, std::vector<unsigned int>& indices);

	std::vector<std::string> reaction_strings_;
};

#endif // QTOPENSMOKE_Profiles_Database_H
