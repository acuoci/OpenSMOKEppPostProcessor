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

#include "Profiles_Database.h"

Profiles_Database::Profiles_Database(void)
{
	iSensitivityEnabled_ = false;
	iROPAEnabled_ = false;
	is_kinetics_available_ = false;

	index_density  = -1;
	index_velocity = -1;
	index_mass_flow_rate = -1;
}

Profiles_Database::~Profiles_Database(void)
{
}

bool Profiles_Database::ReadKineticMechanism(const QString& folder_name)
{
	path_folder_mechanism_ = folder_name.toStdString();
	boost::filesystem::path path_mechanism= path_folder_mechanism_ / "kinetics.xml"; 

	if ( !boost::filesystem::exists( path_mechanism ) )
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromStdString("The kinetics.xml file does not exist!"));
		msgBox.exec();
		return false;
	}

	// Read from file 
	{
		rapidxml::xml_document<> doc;
		std::vector<char> xml_string; 
        OpenSMOKE::OpenInputFileXML(doc, xml_string, path_mechanism);

		thermodynamicsMapXML = new OpenSMOKE::ThermodynamicsMap_CHEMKIN<double>(doc); 
		kineticsMapXML = new OpenSMOKE::KineticsMap_CHEMKIN<double>(*thermodynamicsMapXML, doc); 
	}

	if (thermodynamicsMapXML->NumberOfSpecies() == omega.size())
		iROPAEnabled_ = true;
	else
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromStdString("The rate of production analysis is not available \
			                                   because the Output.xml file contains only a subset of \
											   the total number of species in the kinetic mechanism"));
		msgBox.exec();
		return false;
	}

	// Read the reaction strings 
	{
		std::string local_name = "reaction_names.xml";
		boost::filesystem::path path_reaction_names = path_folder_mechanism_ / local_name;   

		if ( !boost::filesystem::exists( path_reaction_names ) )
		{
			QMessageBox msgBox;
			msgBox.setText(QString::fromStdString("The reaction_names.xml file does not exist!"));
			msgBox.exec();
			return false;
		}

		rapidxml::xml_document<> local_xml;
		std::vector<char> local_xml_input_string;
        OpenSMOKE::OpenInputFileXML(local_xml, local_xml_input_string, path_reaction_names);

		// Names of reactions
		{
			rapidxml::xml_node<>* reaction_names_node = local_xml.first_node("opensmoke")->first_node("reaction-names");
			std::stringstream values(reaction_names_node->value());

			reaction_strings_.reserve(kineticsMapXML->NumberOfReactions());
			for(unsigned int j=0;j<kineticsMapXML->NumberOfReactions();j++)
			{
				std::string reaction_string; 
				values >> reaction_string;
				reaction_strings_.push_back(reaction_string);
			}
		}
	}

	is_kinetics_available_ = true;

	return true;
}

bool Profiles_Database::ReadFileResults(const QString& folder_name)
{
	path_folder_results_ = folder_name.toStdString();
	boost::filesystem::path path_results = path_folder_results_ / "Output.xml"; 

	if ( !boost::filesystem::exists( path_results ) )
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromStdString("The Output.xml file does not exist!"));
		msgBox.exec();
		return false;
	}

    OpenSMOKE::OpenInputFileXML(xml_main_input, xml_main_input_string, path_results);
	Prepare();

	boost::filesystem::path path_sensitivities = path_folder_results_ / "Sensitivities.xml"; 
	if ( boost::filesystem::exists( path_sensitivities ) )
		iSensitivityEnabled_ = true;

	return true;
}

void Profiles_Database::Prepare()
{
	// Indices of T, P and MW
	{
		rapidxml::xml_node<>* indices_node = xml_main_input.first_node("opensmoke")->first_node("t-p-mw");
		if (indices_node != 0)
		{
			std::stringstream values(indices_node->value());
			values >> index_T;
			values >> index_P;
			values >> index_MW;
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText(QString::fromStdString("Corrupted xml file: missing the t-p-mw leaf"));
			msgBox.exec();
		}
	}

	// Additional
	{
		rapidxml::xml_node<>* additional_node = xml_main_input.first_node("opensmoke")->first_node("additional");
		if (additional_node != 0)
		{
			std::stringstream values(additional_node->value());
			
			unsigned int number_of_additional_profiles;
			values >> number_of_additional_profiles;

			string_list_additional.reserve(number_of_additional_profiles);
			for(unsigned int j=0;j<number_of_additional_profiles;j++)
			{
				std::string unit;
				std::string dummy;
				values >> dummy;
				values >> unit;
				string_list_additional.push_back(QString::fromStdString(dummy +" " + unit));

				if (dummy == "density")			index_density  = j+1;
				if (dummy == "velocity")		index_velocity = j+1;
				if (dummy == "mass-flow-rate")	index_mass_flow_rate = j+1;

				values >> dummy;
			}
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText(QString::fromStdString("Corrupted xml file: missing the additional leaf"));
			msgBox.exec();
		}
	}

	index_mass_flow_rate = 7;
	
	// Species (mass fractions)
	QStringList  string_list_massfractions_unsorted;
	{
		rapidxml::xml_node<>* massfractions_node = xml_main_input.first_node("opensmoke")->first_node("mass-fractions");
		if (massfractions_node != 0)
		{
			std::stringstream values(massfractions_node->value());
			
			unsigned int number_of_massfractions_profiles;
			values >> number_of_massfractions_profiles;
			
			column_index_of_massfractions_profiles.resize(number_of_massfractions_profiles);
			string_list_massfractions_unsorted.reserve(number_of_massfractions_profiles);

			mw_species_.resize(number_of_massfractions_profiles);
			for(unsigned int j=0;j<number_of_massfractions_profiles;j++)
			{
				std::string dummy;
				values >> dummy;
				string_list_massfractions_unsorted.push_back(QString::fromStdString(dummy));
				
				values >> mw_species_[j];
				values >> column_index_of_massfractions_profiles[j];
			}

			string_list_massfractions_sorted = string_list_massfractions_unsorted;
			string_list_massfractions_sorted.sort();

			sorted_index.resize(number_of_massfractions_profiles);
			for(unsigned int j=0;j<number_of_massfractions_profiles;j++)
				for(unsigned int k=0;k<number_of_massfractions_profiles;k++)
					if (string_list_massfractions_sorted[j] == string_list_massfractions_unsorted[k])
					{
						sorted_index[j] = k;
						break;
					}
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText(QString::fromStdString("Corrupted xml file: missing the mass-fractions leaf"));
			msgBox.exec();
		}
	}

	// Read profiles
	omega.resize(column_index_of_massfractions_profiles.size());
	additional.resize(string_list_additional.size());
	{
		{
			rapidxml::xml_node<>* profiles_size_node = xml_main_input.first_node("opensmoke")->first_node("profiles-size");
			
			if (profiles_size_node != 0)
			{
				std::stringstream values(profiles_size_node->value());
				values >> number_of_abscissas_; 
				values >> number_of_ordinates_;
			}
			else
			{
				QMessageBox msgBox;
				msgBox.setText(QString::fromStdString("Corrupted xml file: missing the profiles-size leaf"));
				msgBox.exec();
			}
		}

		omega.resize(column_index_of_massfractions_profiles.size());
		for(unsigned int j=0;j<column_index_of_massfractions_profiles.size();j++)
			omega[j].resize(number_of_abscissas_);
		
		additional.resize(string_list_additional.size());
		for(unsigned int j=0;j<string_list_additional.size();j++)
			additional[j].resize(number_of_abscissas_);
		
		rapidxml::xml_node<>* profiles_node = xml_main_input.first_node("opensmoke")->first_node("profiles");
		if (profiles_node != 0)
		{
			std::stringstream values(profiles_node->value());
			for(unsigned int i=0;i<number_of_abscissas_;i++)
			{
				for(unsigned int j=0;j<string_list_additional.size();j++)
					values >> additional[j][i];
				for(unsigned int j=0;j<column_index_of_massfractions_profiles.size();j++)
					values >> omega[j][i];
			}
		}
		else
		{
			QMessageBox msgBox;
			msgBox.setText(QString::fromStdString("Corrupted xml file: missing the profiles leaf"));
			msgBox.exec();
		}

		sorted_max.resize(string_list_massfractions_sorted.size());
		for(unsigned int j=0;j<column_index_of_massfractions_profiles.size();j++)
		{
			sorted_max[j] = -1.e100;
			for(unsigned int i=0;i<number_of_abscissas_;i++)
				if (omega[sorted_index[j]][i] > sorted_max[j]) sorted_max[j] = omega[sorted_index[j]][i];
		}
				
	}

	// Conversions
	{
		for(unsigned int j=0;j<column_index_of_massfractions_profiles.size();j++)
		{
			if (omega[j][0] > 1e-8)
			{
				list_of_conversion_species_.push_back(j);
				string_list_additional.push_back("conversion-" + string_list_massfractions_unsorted[j]);
				QVector<double> tmp(number_of_abscissas_);
				for(unsigned int i=0;i<number_of_abscissas_;i++)
					tmp[i] = (omega[j][0] - omega[j][i])/omega[j][0];
				additional.push_back(tmp);
			}
		}
	}
}

void Profiles_Database::SpeciesCoarsening(const double threshold)
{
	current_sorted_index.resize(0);
	for(unsigned int k=0;k<string_list_massfractions_sorted.size();k++)
		if (sorted_max[k] > threshold)
			current_sorted_index.push_back(k);
}

// 0-based
void Profiles_Database::ReactionsAssociatedToSpecies(const unsigned int index, std::vector<unsigned int>& indices)
{
	kineticsMapXML->stoichiometry().BuildStoichiometricMatrix();
	
	for (int k=0; k<kineticsMapXML->stoichiometry().stoichiometric_matrix_reactants().outerSize(); ++k)
	{
		for (Eigen::SparseMatrix<double>::InnerIterator it(kineticsMapXML->stoichiometry().stoichiometric_matrix_reactants(),k); it; ++it)
			if (it.col() == index) 
				indices.push_back(it.row());
	}
	for (int k=0; k<kineticsMapXML->stoichiometry().stoichiometric_matrix_products().outerSize(); ++k)
	{
		for (Eigen::SparseMatrix<double>::InnerIterator it(kineticsMapXML->stoichiometry().stoichiometric_matrix_products(),k); it; ++it)
			if (it.col() == index) 
				indices.push_back(it.row());
	}	

	std::sort(indices.begin(), indices.end());
}


