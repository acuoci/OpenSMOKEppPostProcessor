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


#include "Sensitivities_Database.h"

void MessageBox(const QString message)
{
	QMessageBox msgBox;
	msgBox.setText(message);
	msgBox.exec();
}

Sensitivities_Database::Sensitivities_Database(void)
{
}

Sensitivities_Database::~Sensitivities_Database(void)
{
}

void Sensitivities_Database::SetDatabase(Profiles_Database* data)
{
	data_ = data;
}

void Sensitivities_Database::ReadParentFile()
{
	boost::filesystem::path path_results = data_->path_folder_results_ / "Sensitivities.xml";   
    OpenSMOKE::OpenInputFileXML(xml_main_input, xml_main_input_string, path_results);
	
	{
		rapidxml::xml_node<>* variables_node = xml_main_input.first_node("opensmoke")->first_node("variables");
		std::stringstream values(variables_node->value());
		values >> number_of_variables_;

		names_.resize(number_of_variables_);
		local_index_.resize(number_of_variables_);
		global_index_.resize(number_of_variables_);
		for(unsigned int j=0;j<number_of_variables_;j++)
		{	
			values >> names_[j];
			values >> local_index_[j];
			values >> global_index_[j];
		}
	}
	
	{
		rapidxml::xml_node<>* parameters_node = xml_main_input.first_node("opensmoke")->first_node("n-parameters");
		std::stringstream values(parameters_node->value());
		values >> number_of_parameters_;
		parameters_.resize(number_of_parameters_);
	}

	{
		rapidxml::xml_node<>* parameters_node = xml_main_input.first_node("opensmoke")->first_node("constant-parameters");
		std::stringstream values(parameters_node->value());
		for(unsigned int j=0;j<number_of_parameters_;j++)
			values >> parameters_[j];
	}

	{
		rapidxml::xml_node<>* points_node = xml_main_input.first_node("opensmoke")->first_node("points");
		std::stringstream values(points_node->value());
		values >> number_of_points_;
	}

	// Memory allocation
	coefficients_.resize(number_of_parameters_);
	for(unsigned int j=0;j<number_of_parameters_;j++)
		coefficients_[j].resize(number_of_points_);
	variable_.resize(number_of_points_);

	// Names of reactions
	{
		string_list_reactions_.reserve(number_of_parameters_);
		for(unsigned int j=0;j<number_of_parameters_;j++)
		{
			if (j+1 <= data_->kineticsMapXML->NumberOfReactions())
			{
				std::stringstream index;
				index << j+1;
				std::string tmp = "R" + index.str() + ": " + data_->reaction_strings_[j];
				string_list_reactions_.push_back(QString::fromStdString(tmp));
			}
			else
			{
				unsigned int local_index = j+1-data_->kineticsMapXML->NumberOfReactions();
				if (local_index <= data_->kineticsMapXML->NumberOfFallOffReactions())
				{
					unsigned int global_index = data_->kineticsMapXML->IndicesOfFalloffReactions()[local_index-1];
					std::stringstream index;
					index << global_index;
					std::string tmp = "R" + index.str() + "(inf): " + data_->reaction_strings_[global_index-1];
					string_list_reactions_.push_back(QString::fromStdString(tmp));
				}
				else
				{
					unsigned int global_index = data_->kineticsMapXML->IndicesOfCabrReactions()[local_index-data_->kineticsMapXML->NumberOfReactions()-1];
					std::stringstream index;
					index << global_index;
					std::string tmp = "R" + index.str() + "(inf): " + data_->reaction_strings_[global_index-1];
					string_list_reactions_.push_back(QString::fromStdString(tmp));
				}
			}
		}
	}
}

void Sensitivities_Database::ReadFromChildFile(const std::string name)
{
	std::string local_name = "Sensitivities." + name + ".xml";
	boost::filesystem::path path_file = data_->path_folder_results_ / local_name;   

	rapidxml::xml_document<> local_xml;
	std::vector<char> local_xml_input_string;
    OpenSMOKE::OpenInputFileXML(local_xml, local_xml_input_string, path_file);


	rapidxml::xml_node<>* coefficients_node = local_xml.first_node("opensmoke")->first_node("coefficients");
	if (coefficients_node == 0) 
		MessageBox("Corrupted xml file: missing the coefficients leaf");
	else
	{
		std::stringstream values(coefficients_node->value());
		for(unsigned int i=0;i<number_of_points_;i++)
			for(unsigned int j=0;j<number_of_parameters_;j++)
				values >> coefficients_[j][i];
	}

	for(unsigned int j=0;j<number_of_variables_;j++)
		if (names_[j] == name)
		{
			current_local_index_ = j;
			break;
		}

	if (name == "temperature")
		variable_ = data_->additional[data_->index_T];
	else if (name == "density")
		variable_ = data_->additional[data_->index_density];
	else if (name == "velocity")
		variable_ = data_->additional[data_->index_velocity];
	else if (name == "mass-flow-rate")
		variable_ = data_->additional[data_->index_mass_flow_rate]; 
	else
	{
		// recognizing the global index of species
		unsigned int species_index;
		for(unsigned int j=0;j<data_->string_list_massfractions_sorted.size();j++)
			if (name == data_->string_list_massfractions_sorted[j].toStdString())
			{
				species_index = data_->sorted_index[j];
				break;
			}

		// from mass to mole fractions
		for(unsigned int i=0;i<number_of_points_;i++)
			variable_[i] =	data_->omega[species_index][i] * data_->additional[data_->index_MW][i] /
							data_->mw_species_[species_index];
	}
}

// zero-based
QVector<double> Sensitivities_Database::NormalizedProfile(const unsigned int index, bool local_normalization)
{
	QVector<double> profile = coefficients_[index];
	if (local_normalization == true)
	{
		for(unsigned int i=0;i<number_of_points_;i++)
			if (fabs(variable_[i]) > 1e-12)
				profile[i] *= parameters_[index]/variable_[i];
			else
				profile[i] = 0.;
	}
	else
	{
		double normalization_coefficient = -1e100;
		for(unsigned int i=0;i<number_of_points_;i++)
			if (fabs(variable_[i]) > normalization_coefficient) 
				normalization_coefficient = fabs(variable_[i]);

		
		if (normalization_coefficient > 1e-32)
			for(unsigned int i=0;i<number_of_points_;i++)
				profile[i] *= parameters_[index]/normalization_coefficient;
		else
			for(unsigned int i=0;i<number_of_points_;i++)
				profile[i] = 0.;
	}

	return profile;
}

// zero-based
double Sensitivities_Database::NormalizedProfile(const unsigned int index, bool local_normalization, unsigned int point)
{
	if (local_normalization == true)
	{
		if (fabs(variable_[point]) > 1e-16)
			return coefficients_[index][point]*parameters_[index]/variable_[point];
		else
			return 0.;
	}
	else
	{
		double normalization_coefficient = -1e100;
		for(unsigned int i=0;i<number_of_points_;i++)
			if (fabs(variable_[i]) > normalization_coefficient) 
				normalization_coefficient = fabs(variable_[i]);
		
		if (normalization_coefficient > 1e-32)
			return coefficients_[index][point]*parameters_[index]/normalization_coefficient;
		else
			return 0.;
	}
}

void Sensitivities_Database::ReactionsReset()
{
	// Fill the reaction indices
	current_coarse_index_.resize(number_of_parameters_);
	for (unsigned int j=0;j<number_of_parameters_;j++)
		current_coarse_index_[j] = j+1;
}

void Sensitivities_Database::ReactionsCoarsening(const double threshold)
{
	// Fill the reaction indices
	std::vector<unsigned int> total_indices(number_of_parameters_);
	for (unsigned int j=0;j<number_of_parameters_;j++)
		total_indices[j] = j+1;

	// Evaluates the coefficients
	std::vector<double> total_coefficients(number_of_parameters_);
	QVector<double> profile(data_->number_of_abscissas_);
	for (unsigned int j=0;j<number_of_parameters_;j++)
	{
		profile = NormalizedProfile(j, false);

		double max_value = -1.e100;
		unsigned int max_index=0;
		for (unsigned int i=0;i<data_->number_of_abscissas_;i++)
			if ( fabs(profile[i]) > max_value)
			{
				max_value = fabs(profile[i]);
				max_index = i;
			}
		total_coefficients[j] = profile[max_index];	
	}

	// Reorder the coefficients
	std::vector<int> indices;
	std::vector<double> coefficients;
	MergeBars( total_indices, total_coefficients, indices, coefficients);

	current_coarse_index_.resize(0);
	if (fabs(coefficients[0]) > 0.)
	{
		for (unsigned int j=0;j<number_of_parameters_;j++)
		{
			if (fabs(coefficients[j])/fabs(coefficients[0]) > threshold)
				current_coarse_index_.push_back(indices[j]);
			else
				break;
		}
	}
}

