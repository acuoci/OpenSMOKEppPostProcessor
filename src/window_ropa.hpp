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

#include "window_ropa.h"

Window_ROPA::Window_ROPA(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.pushButton_PlotFormationRates, SIGNAL(released()), this, SLOT(Plot_FormationRates()));
	QObject::connect(ui.pushButton_PlotReactionRates, SIGNAL(released()), this, SLOT(Plot_ReactionRates()));
	QObject::connect(ui.pushButton_ROPA_BarChart, SIGNAL(released()), this, SLOT(Plot_ROPA_BarChart()));
	QObject::connect(ui.pushButton_ROPA_FluxAnalysis, SIGNAL(released()), this, SLOT(Plot_FluxAnalysis()));
	QObject::connect(ui.pushButton_AnalyzeCharacteristicTimes, SIGNAL(released()), this, SLOT(AnalyzeCharacteristicTimes()));
	QObject::connect(ui.pushButton_PlotShortestChemicalTime, SIGNAL(released()), this, SLOT(PlotShortestChemicalTime()));
	
	QObject::connect(ui.radioButton_ROPA_Local, SIGNAL(toggled(bool)), this, SLOT(Clicked_ROPA_Local()));	
	QObject::connect(ui.radioButton_ROPA_Region, SIGNAL(toggled(bool)), this, SLOT(Clicked_ROPA_Region()));
	QObject::connect(ui.radioButton_ROPA_Global, SIGNAL(toggled(bool)), this, SLOT(Clicked_ROPA_Global()));

	QObject::connect(ui.pushButton_clean_ReactionRates, SIGNAL(clicked()), this, SLOT(Clean_ReactionRates_List()));
	QObject::connect(ui.pushButton_clean_FormationRates, SIGNAL(clicked()), this, SLOT(Clean_FormationRates_List()));	

	QObject::connect(ui.checkBox_Species_ReactionRates, SIGNAL(stateChanged(int)), this, SLOT(UpdateCheckBox()));	
	QObject::connect(ui.comboBox_Species_ReactionRates, SIGNAL(currentIndexChanged(int)), this, SLOT(UpdateListOfReactions()));	
	QObject::connect(ui.horizontalSlider_Species_ReactionRates, SIGNAL(valueChanged(int)), this, SLOT(UpdateListOfReactions()));	
	
}

Window_ROPA::~Window_ROPA()
{

}

void Window_ROPA::SetDatabase(Profiles_Database* data)
{
	data_ = data;
}

void Window_ROPA::SetExeFolder(const boost::filesystem::path folder)
{
	exe_folder_ = folder; 
}

void Window_ROPA::SetOutputFolder(const boost::filesystem::path folder)
{
	output_folder_ = folder; 
}

void Window_ROPA::Prepare()
{
	//
	{
		string_list_reactions.reserve(data_->kineticsMapXML->NumberOfReactions());
		for(unsigned int j=0;j<data_->kineticsMapXML->NumberOfReactions();j++)
		{
			std::stringstream index;
			index << j+1;
			std::string tmp = "R" + index.str() + ": " + data_->reaction_strings_[j];
			string_list_reactions.push_back(QString::fromStdString(tmp));
		}

		UpdateListOfReactions();
	}

	ui.listWidget_Species->addItems(data_->string_list_massfractions_sorted);

	QStringList string_list_total = data_->string_list_additional + data_->string_list_massfractions_sorted;
	ui.listWidget_X->addItems(string_list_total);
	ui.listWidget_X->item(0)->setSelected(true);

	QStringList string_list_additional_tmp;
	string_list_additional_tmp.push_back(data_->string_list_additional[0]);
	ui.comboBox_ROPA_X->addItems(string_list_additional_tmp);
	ui.listWidget_ROPA_Species->addItems(data_->string_list_massfractions_sorted);
	ui.comboBox_Species_ReactionRates->addItems(data_->string_list_massfractions_sorted);

	ui.doubleSpinBox_ROPA_Local->setMaximum(data_->additional[0][data_->number_of_abscissas_-1]);
	ui.doubleSpinBox_ROPA_Local->setMinimum(data_->additional[0][0]);
	ui.doubleSpinBox_ROPA_Local->setValue(0.50*(data_->additional[0][0]+data_->additional[0][data_->number_of_abscissas_-1]));

	ui.doubleSpinBox_ROPA_Region_Min->setMaximum(data_->additional[0][data_->number_of_abscissas_-1]);
	ui.doubleSpinBox_ROPA_Region_Min->setMinimum(data_->additional[0][0]);
	ui.doubleSpinBox_ROPA_Region_Min->setValue(data_->additional[0][0]);

	ui.doubleSpinBox_ROPA_Region_Max->setMaximum(data_->additional[0][data_->number_of_abscissas_-1]);
	ui.doubleSpinBox_ROPA_Region_Max->setMinimum(data_->additional[0][0]);
	ui.doubleSpinBox_ROPA_Region_Max->setValue(data_->additional[0][data_->number_of_abscissas_-1]);

	ui.doubleSpinBox_CharacteristicTimes->setMaximum(data_->additional[0][data_->number_of_abscissas_-1]);
	ui.doubleSpinBox_CharacteristicTimes->setMinimum(data_->additional[0][0]);
	ui.doubleSpinBox_CharacteristicTimes->setValue(0.50*(data_->additional[0][0]+data_->additional[0][data_->number_of_abscissas_-1]));

	for(unsigned int k=0;k<data_->thermodynamicsMapXML->elements().size();k++)
		ui.comboBox_Elements->addItem(QString::fromStdString(data_->thermodynamicsMapXML->elements()[k]));
}

void Window_ROPA::SetXAxisForXYPlotting(XYPlot* xyplot)
{
	QList<QListWidgetItem*> selected_x = ui.listWidget_X->selectedItems();
		if (selected_x.size() == 0)
			return;
	
	QVector<double> axis_x;
	QString axis_x_title;
	for(unsigned int k=0;k<data_->string_list_additional.size();k++)
		if (selected_x[0]->text() == data_->string_list_additional[k])
		{
			axis_x = data_->additional[k];
			axis_x_title = data_->string_list_additional[k];
			break;
		}
	
	if (axis_x.size() == 0)
	{
		for(unsigned int k=0;k<data_->string_list_massfractions_sorted.size();k++)
			if (selected_x[0]->text() == data_->string_list_massfractions_sorted[k])
			{
				axis_x = data_->omega[data_->sorted_index[k]];
				const double mwj = data_->mw_species_[data_->sorted_index[k]];
				axis_x_title = data_->string_list_massfractions_sorted[k];
				break;
			}
	}
	xyplot->SetAbscissas(axis_x);
	xyplot->SetXTitle(axis_x_title);
}

void Window_ROPA::Plot_FormationRates()
{
	XYPlot* xyplot;
	xyplot = new XYPlot(this);
	
	// Find the right x variable, together with the x axis lable
	SetXAxisForXYPlotting(xyplot);

	// Select y variables among the species
	OpenSMOKE::OpenSMOKEVector<unsigned int> formation_rates_to_plot;
	QList<QListWidgetItem*> selected_species = ui.listWidget_Species->selectedItems();
	if (selected_species.size() == 0)
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromStdString("You have to select one of the available species"));
		msgBox.exec();
		return;
	}
	{
		unsigned int n_selected_species = selected_species.size();
		ChangeDimensions(n_selected_species, &formation_rates_to_plot, true);
		for(unsigned int j=0;j<n_selected_species;j++)
		{
			for(unsigned int k=0;k<data_->string_list_massfractions_sorted.size();k++)
			if (selected_species[j]->text() == data_->string_list_massfractions_sorted[k])
			{
				formation_rates_to_plot[j+1] = k;
				break;
			}
		}
	}

	// Calculates the formation rates
	{
		QVector< QVector<double> > tmp(formation_rates_to_plot.Size());
		for (unsigned int j=0;j<formation_rates_to_plot.Size();j++)
			tmp[j].resize(data_->number_of_abscissas_);

		OpenSMOKE::OpenSMOKEVectorDouble P(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble D(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble x(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble omega(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble c(data_->thermodynamicsMapXML->NumberOfSpecies());
		
		for (unsigned int i=0;i<data_->number_of_abscissas_;i++)
		{
			// Recovers mass fractions
			for (unsigned int k=0;k<data_->thermodynamicsMapXML->NumberOfSpecies();k++)
				omega[k+1] = data_->omega[k][i];
			
			// Calculates mole fractions
			double MWmix;
			data_->thermodynamicsMapXML->MoleFractions_From_MassFractions(x, MWmix, omega);

			// Calculates concentrations
			const double P_Pa = data_->additional[data_->index_P][i];
			const double T = data_->additional[data_->index_T][i];
			const double cTot = P_Pa/PhysicalConstants::R_J_kmol/T;
			Product(cTot, x, &c);

			// Calculates formations rates
			data_->kineticsMapXML->SetTemperature(T);
			data_->kineticsMapXML->SetPressure(P_Pa);
			data_->thermodynamicsMapXML->SetTemperature(T);
			data_->thermodynamicsMapXML->SetPressure(P_Pa);

			data_->kineticsMapXML->KineticConstants();
			data_->kineticsMapXML->ReactionRates(c);
			data_->kineticsMapXML->ProductionAndDestructionRates(&P, &D);			// kmol/m3/s

			if (ui.radioButton_formation_characteristictimes->isChecked() == true)
			{
				for (unsigned int j=0;j<formation_rates_to_plot.Size();j++)
				{
					const unsigned k = data_->sorted_index[formation_rates_to_plot[j+1]]+1;
					tmp[j][i] = c[k] / (D[k]+1.e-32);	
				}
			}
			else
			{
				if (ui.radioButton_formation_mass->isChecked() == true)
				{
					ElementByElementProduct(P,data_->thermodynamicsMapXML->MW(), &P);
					ElementByElementProduct(D,data_->thermodynamicsMapXML->MW(), &D);
				}
		
				for (unsigned int j=0;j<formation_rates_to_plot.Size();j++)
				{
					const unsigned k = data_->sorted_index[formation_rates_to_plot[j+1]]+1;

					if (ui.radioButton_formation_net->isChecked() == true)
						tmp[j][i] = P[k] - D[k];
					else if (ui.radioButton_formation_production->isChecked() == true)
						tmp[j][i] = P[k];
					else if (ui.radioButton_formation_destruction->isChecked() == true)
						tmp[j][i] = D[k];
				}
			}
		}	

		for (unsigned int j=0;j<formation_rates_to_plot.Size();j++)
			xyplot->AddGraph(selected_species[j]->text().toStdString(), tmp[j]);	
	}

	// Plot
	if (ui.radioButton_formation_characteristictimes->isChecked() == true)
	{
		xyplot->SetYTitle("CharacteristicTimes [s]");
		xyplot->SwitchYScale();
	}
	else
	{
		if (ui.radioButton_formation_mass->isChecked() == true)
		{
			if (ui.radioButton_formation_net->isChecked() == true)
				xyplot->SetYTitle("Formation Rates (net) [kg/m3/s]");
			else if (ui.radioButton_formation_production->isChecked() == true)
				xyplot->SetYTitle("Production Rates [kg/m3/s]");
			else if (ui.radioButton_formation_destruction->isChecked() == true)
				xyplot->SetYTitle("Destruction Rates [kg/m3/s]");
		}
		else
		{
			if (ui.radioButton_formation_net->isChecked() == true)
				xyplot->SetYTitle("Formation Rates (net) [kmol/m3/s]");
			else if (ui.radioButton_formation_production->isChecked() == true)
				xyplot->SetYTitle("Production Rates [kmol/m3/s]");
			else if (ui.radioButton_formation_destruction->isChecked() == true)
				xyplot->SetYTitle("Destruction Rates [kmol/m3/s]");
		}
	}
	xyplot->Plot();
}
void Window_ROPA::Plot_ROPA_BarChart()
{
	// Select y variables among the species
	QList<QListWidgetItem*> selected_species = ui.listWidget_ROPA_Species->selectedItems();
	if (selected_species.size() == 0)
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromStdString("You have to select one of the available species"));
		msgBox.exec();
		return;
	}

	unsigned int index_of_species;
	for(unsigned int j=0;j<ui.listWidget_ROPA_Species->count();j++)
		if (ui.listWidget_ROPA_Species->item(j)->isSelected() == true)
		{
			index_of_species = data_->sorted_index[j];
			break;
		}

	{
		OpenSMOKE::OpenSMOKEVectorDouble x(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble omega(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble c(data_->thermodynamicsMapXML->NumberOfSpecies());

		// Local Analysis
		if (ui.radioButton_ROPA_Local->isChecked() == true)
		{
			unsigned int index = 0;
			for(unsigned int j=0;j<data_->number_of_abscissas_;j++)
				if (data_->additional[0][j] >= ui.doubleSpinBox_ROPA_Local->value() )
				{
					index = j;
					break;
				}
		
			// Recovers mass fractions
			for (unsigned int k=0;k<data_->thermodynamicsMapXML->NumberOfSpecies();k++)
				omega[k+1] = data_->omega[k][index];
			
			// Calculates mole fractions
			double MWmix;
			data_->thermodynamicsMapXML->MoleFractions_From_MassFractions(x, MWmix, omega);

			// Calculates concentrations
			const double P_Pa = data_->additional[data_->index_P][index];
			const double T = data_->additional[data_->index_T][index];
			const double cTot = P_Pa/PhysicalConstants::R_J_kmol/T;
			Product(cTot, x, &c);

			// Calculates formations rates
			data_->kineticsMapXML->SetTemperature(T);
			data_->kineticsMapXML->SetPressure(P_Pa);
			data_->thermodynamicsMapXML->SetTemperature(T);
			data_->thermodynamicsMapXML->SetPressure(P_Pa);

			data_->kineticsMapXML->KineticConstants();
			data_->kineticsMapXML->ReactionRates(c);

			// Ropa
			OpenSMOKE::ROPA_Data ropa;
			data_->kineticsMapXML->RateOfProductionAnalysis(ropa);	

			std::vector<int> reaction_indices;
			std::vector<double> reaction_coefficients;
			MergePositiveAndNegativeBars(	ropa.production_reaction_indices[index_of_species], 
											ropa.destruction_reaction_indices[index_of_species],
											ropa.production_coefficients[index_of_species], ropa.destruction_coefficients[index_of_species], 
											reaction_indices, reaction_coefficients);
			
			// The OpenSMOKE ROPA Analysis returns 0-based indices that needs to be
			// transformed into 1-based indices before calling the Widget_Horizontal_Bars
			for(unsigned int i=0;i<reaction_indices.size();i++)
				reaction_indices[i]++;
			
			std::vector<std::string> production_reaction_names(reaction_indices.size());
			for(unsigned int i=0;i<reaction_indices.size();i++)
				production_reaction_names[i] = data_->reaction_strings_[reaction_indices[i]-1];

			Widget_Horizontal_Bars* horizontal_bars = new Widget_Horizontal_Bars();
			horizontal_bars->setTitle("Rate of Production Analysis");
			horizontal_bars->setMainComment("Rate of Production Analysis - " + selected_species[0]->text());
			horizontal_bars->setRectangles(	reaction_coefficients, reaction_indices, production_reaction_names);
			horizontal_bars->show();
		} // Local
		else
		{
			unsigned int index_min = 0;
			unsigned int index_max = data_->number_of_abscissas_-1;
			if (ui.radioButton_ROPA_Region->isChecked() == true)
			{
				for(unsigned int j=0;j<data_->number_of_abscissas_;j++)
					if (data_->additional[0][j] >= ui.doubleSpinBox_ROPA_Region_Min->value() )
					{
						index_min = j;
						break;
					}

				for(unsigned int j=index_min;j<data_->number_of_abscissas_;j++)
					if (data_->additional[0][j] >= ui.doubleSpinBox_ROPA_Region_Max->value() )
					{
						index_max = j;
						break;
					}

				if (index_min == index_max)
				{
					if (index_max == data_->number_of_abscissas_-1)
						index_min = index_max-1;
					else
						index_max = index_min+1;
				}
			}

			const double delta = data_->additional[0][index_max] - data_->additional[0][index_min];

			std::vector<double> global_production_coefficients;
			std::vector<double> global_destruction_coefficients;
			std::vector<unsigned int> global_production_reaction_indices;
			std::vector<unsigned int> global_destruction_reaction_indices;

			for(unsigned int j=index_min;j<index_max-1;j++)
			{
				// Recovers mass fractions
				for (unsigned int k=0;k<data_->thermodynamicsMapXML->NumberOfSpecies();k++)
					omega[k+1] = data_->omega[k][j];
			
				// Calculates mole fractions
				double MWmix;
				data_->thermodynamicsMapXML->MoleFractions_From_MassFractions(x, MWmix, omega);

				// Calculates concentrations
				const double P_Pa = data_->additional[data_->index_P][j];
				const double T = data_->additional[data_->index_T][j];
				const double cTot = P_Pa/PhysicalConstants::R_J_kmol/T;
				Product(cTot, x, &c);

				// Calculates formations rates
				data_->kineticsMapXML->SetTemperature(T);
				data_->kineticsMapXML->SetPressure(P_Pa);
				data_->thermodynamicsMapXML->SetTemperature(T);
				data_->thermodynamicsMapXML->SetPressure(P_Pa);

				data_->kineticsMapXML->KineticConstants();
				data_->kineticsMapXML->ReactionRates(c);

				// Ropa
				OpenSMOKE::ROPA_Data ropa;
				data_->kineticsMapXML->RateOfProductionAnalysis(ropa);	

				if ( ropa.production_coefficients[index_of_species].size() !=  ropa.production_reaction_indices[index_of_species].size() ||
					 ropa.destruction_coefficients[index_of_species].size() !=  ropa.destruction_reaction_indices[index_of_species].size() )
					 { QMessageBox msgBox;msgBox.setText(QString::fromStdString("SSS"));msgBox.exec();}

				if (j==index_min)
				{
					global_production_coefficients.resize(ropa.production_coefficients[index_of_species].size());
					global_destruction_coefficients.resize(ropa.destruction_coefficients[index_of_species].size());
					global_production_reaction_indices = ropa.production_reaction_indices[index_of_species];
					global_destruction_reaction_indices = ropa.destruction_reaction_indices[index_of_species];

				}

				const double dt = (data_->additional[0][j+1] - data_->additional[0][j])/delta;
				for(unsigned int k=0;k<ropa.production_coefficients[index_of_species].size();k++)
					global_production_coefficients[k] += dt*ropa.production_coefficients[index_of_species][k];

				for(unsigned int k=0;k<ropa.destruction_coefficients[index_of_species].size();k++)
					global_destruction_coefficients[k] += dt*ropa.destruction_coefficients[index_of_species][k];
			}

			std::vector<int> reaction_indices;
			std::vector<double> reaction_coefficients;
			MergePositiveAndNegativeBars(	global_production_reaction_indices, 
											global_destruction_reaction_indices,
											global_production_coefficients, global_destruction_coefficients, 
											reaction_indices, reaction_coefficients);

			// The OpenSMOKE ROPA Analysis returns 0-based indices that needs to be
			// transformed into 1-based indices before calling the Widget_Horizontal_Bars
			for(unsigned int i=0;i<reaction_indices.size();i++)
				reaction_indices[i]++;

			std::vector<std::string> production_reaction_names(reaction_indices.size());
			for(unsigned int i=0;i<reaction_indices.size();i++)
				production_reaction_names[i] = data_->reaction_strings_[reaction_indices[i]-1];

			Widget_Horizontal_Bars* horizontal_bars = new Widget_Horizontal_Bars();
			horizontal_bars->setTitle("Rate of Production Analysis");
			horizontal_bars->setMainComment("Rate of Production Analysis - " + selected_species[0]->text());
			horizontal_bars->setRectangles(	reaction_coefficients, reaction_indices, production_reaction_names);
			horizontal_bars->show();
		}

	}

}

void Window_ROPA::PlotShortestChemicalTime()
{
	OpenSMOKE::OpenSMOKEVectorDouble x(data_->thermodynamicsMapXML->NumberOfSpecies());
	OpenSMOKE::OpenSMOKEVectorDouble omega(data_->thermodynamicsMapXML->NumberOfSpecies());
	OpenSMOKE::OpenSMOKEVectorDouble c(data_->thermodynamicsMapXML->NumberOfSpecies());
	OpenSMOKE::OpenSMOKEMatrixDouble dR_over_dc(data_->thermodynamicsMapXML->NumberOfSpecies(),data_->thermodynamicsMapXML->NumberOfSpecies());
	OpenSMOKE::OpenSMOKEVectorDouble P(dR_over_dc.Rows());
	OpenSMOKE::OpenSMOKEVectorDouble D(dR_over_dc.Rows());
	OpenSMOKE::OpenSMOKEVectorDouble tau(dR_over_dc.Rows());
	Eigen::MatrixXd A(dR_over_dc.Rows(),dR_over_dc.Rows());

	QVector<double> tau_min_jacobian(data_->number_of_abscissas_);
	QVector<double> tau_min_destruction_rate(data_->number_of_abscissas_);
	for(unsigned int j=0;j<data_->number_of_abscissas_;j++)
	{
		// Recovers mass fractions
		for (unsigned int k=0;k<data_->thermodynamicsMapXML->NumberOfSpecies();k++)
			omega[k+1] = data_->omega[k][j];
			
		// Calculates mole fractions
		double MWmix;
		data_->thermodynamicsMapXML->MoleFractions_From_MassFractions(x, MWmix, omega);

		// Calculates concentrations
		const double P_Pa = data_->additional[data_->index_P][j];
		const double T = data_->additional[data_->index_T][j];
		const double cTot = P_Pa/PhysicalConstants::R_J_kmol/T;
		Product(cTot, x, &c);

		// Calculates formations rates
		data_->kineticsMapXML->SetTemperature(T);
		data_->kineticsMapXML->SetPressure(P_Pa);
		data_->thermodynamicsMapXML->SetTemperature(T);
		data_->thermodynamicsMapXML->SetPressure(P_Pa);

		data_->kineticsMapXML->KineticConstants();
		data_->kineticsMapXML->ReactionRates(c);
		data_->kineticsMapXML->ProductionAndDestructionRates(&P, &D);			// kmol/m3/s

		tau_min_destruction_rate[j] = 1e16;
		for(unsigned int i=1;i<=dR_over_dc.Rows();i++)
		{
			if (c[i] > 1.e-48)
			{
				const double tc = c[i]/(D[i]+1e-48);
				if (tau_min_destruction_rate[j]> tc) tau_min_destruction_rate[j] = tc;	
			}
		}

		data_->kineticsMapXML->DerivativesOfFormationRates(c, omega, &dR_over_dc);
	
		// Calculates the eigenvectors
		for(unsigned int i=0;i<dR_over_dc.Rows();i++)
			for(unsigned int j=0;j<dR_over_dc.Rows();j++)
				A(i,j) = dR_over_dc[i+1][j+1];

		if (ui.radioButton_eigenvalues->isChecked() == true)
		{
			Eigen::EigenSolver<Eigen::MatrixXd> eigensolver(A);
			if (eigensolver.info() != Eigen::Success) 
			{
				abort();
			}
		
			for(unsigned int i=0;i<dR_over_dc.Rows();i++)
				tau[i+1] = 1./std::max(1e-12, fabs(eigensolver.eigenvalues().real()[i]));
			tau_min_jacobian[j] = tau.Min();
		}
		else
		{
			Eigen::JacobiSVD<Eigen::MatrixXd> jacobi(A);
			for(unsigned int i=0;i<dR_over_dc.Rows();i++)
				tau[i+1] = 1./std::max(1e-12, fabs(jacobi.singularValues().real()[i]));
			tau_min_jacobian[j] = tau.Min();
		}
	}

	XYPlot* plot = new XYPlot(this);
	plot->SetAbscissas(data_->additional[0]);
	plot->AddGraph("Jacobian Analysis", tau_min_jacobian);
	plot->AddGraph("Destruction rates", tau_min_destruction_rate);
	plot->Plot();
}

void Window_ROPA::AnalyzeCharacteristicTimes()
{
	OpenSMOKE::OpenSMOKEVectorDouble x(data_->thermodynamicsMapXML->NumberOfSpecies());
	OpenSMOKE::OpenSMOKEVectorDouble omega(data_->thermodynamicsMapXML->NumberOfSpecies());
	OpenSMOKE::OpenSMOKEVectorDouble c(data_->thermodynamicsMapXML->NumberOfSpecies());
	OpenSMOKE::OpenSMOKEMatrixDouble dR_over_dc(data_->thermodynamicsMapXML->NumberOfSpecies(),data_->thermodynamicsMapXML->NumberOfSpecies());
	OpenSMOKE::OpenSMOKEVectorDouble tau(dR_over_dc.Rows());
	Eigen::MatrixXd A(dR_over_dc.Rows(),dR_over_dc.Rows());

	unsigned int index = 0;
	for(unsigned int j=0;j<data_->number_of_abscissas_;j++)
		if (data_->additional[0][j] >= ui.doubleSpinBox_CharacteristicTimes->value() )
		{
			index = j;
			break;
		}
	
	// Recovers mass fractions
	for (unsigned int k=0;k<data_->thermodynamicsMapXML->NumberOfSpecies();k++)
		omega[k+1] = data_->omega[k][index];
			
	// Calculates mole fractions
	double MWmix;
	data_->thermodynamicsMapXML->MoleFractions_From_MassFractions(x, MWmix, omega);

	// Calculates concentrations
	const double P_Pa = data_->additional[data_->index_P][index];
	const double T = data_->additional[data_->index_T][index];
	const double cTot = P_Pa/PhysicalConstants::R_J_kmol/T;
	Product(cTot, x, &c);

	// Calculates formations rates
	data_->kineticsMapXML->SetTemperature(T);
	data_->kineticsMapXML->SetPressure(P_Pa);
	data_->thermodynamicsMapXML->SetTemperature(T);
	data_->thermodynamicsMapXML->SetPressure(P_Pa);

	data_->kineticsMapXML->KineticConstants();
	data_->kineticsMapXML->ReactionRates(c);

	data_->kineticsMapXML->DerivativesOfFormationRates(c, omega, &dR_over_dc);

	// Calculates the eigenvectors
	for(unsigned int i=0;i<dR_over_dc.Rows();i++)
		for(unsigned int j=0;j<dR_over_dc.Rows();j++)
			A(i,j) = dR_over_dc[i+1][j+1];

	if (ui.radioButton_eigenvalues->isChecked() == true)
	{
		Eigen::EigenSolver<Eigen::MatrixXd> eigensolver(A);
		if (eigensolver.info() != Eigen::Success) 
		{
			abort();
		}
		
		for(unsigned int i=0;i<dR_over_dc.Rows();i++)
			tau[i+1] = 1./std::max(1e-12, fabs(eigensolver.eigenvalues().real()[i]));

	//	std::ofstream fOut("eigen", std::ios::out);
	//	fOut << eigensolver.eigenvalues() << std::endl;
	//	fOut << eigensolver.eigenvectors() << std::endl;
	//	fOut.close();
	}
	else
	{
		Eigen::JacobiSVD<Eigen::MatrixXd> jacobi(A);
		for(unsigned int i=0;i<dR_over_dc.Rows();i++)
			tau[i+1] = 1./std::max(1e-12, fabs(jacobi.singularValues().real()[i]));
	}

	
	Eigen::VectorXi bins(16);
	bins.setConstant(0);

	for(unsigned int i=1;i<=dR_over_dc.Rows();i++)
	{
		if (tau[i] >=5e2)			bins(15)++;
		else if (tau[i] >=5e1)		bins(14)++;
		else if (tau[i] >= 5e0)		bins(13)++;
		else if (tau[i] >= 5e-1)		bins(12)++;
		else if (tau[i] >= 5e-2)		bins(11)++;
		else if (tau[i] >= 5e-3)		bins(10)++;
		else if (tau[i] >= 5e-4)		bins(9)++;
		else if (tau[i] >= 5e-5)		bins(8)++;
		else if (tau[i] >= 5e-6)		bins(7)++;
		else if (tau[i] >= 5e-7)		bins(6)++;
		else if (tau[i] >= 5e-8)		bins(5)++;
		else if (tau[i] >= 5e-9)		bins(4)++;
		else if (tau[i] >= 5e-10)	bins(3)++;
		else if (tau[i] >= 5e-11)	bins(2)++;
		else if (tau[i] >= 5e-12)	bins(1)++;
		else 						bins(0)++;
	}

	int sum = 0;
	for(unsigned int i=0;i<16;i++)
		sum += bins(i);

	QVector<double> bin(16);
	for(unsigned int i=0;i<16;i++)
		bin[i]= double(bins(i))/double(sum)*100.;

	QCustomPlot* customPlot = new QCustomPlot();
	QCPBars *myBars = new QCPBars(customPlot->xAxis, customPlot->yAxis);
	customPlot->addPlottable(myBars);
	myBars->setName("Characteristic chemical times");
	QVector<double> keyData;
	keyData << -12 <<-11 << -10 << -9 << -8 << -7 << -6 << -5 << -4 << -3 << -2 << -1 << 0 << 1 << 2 << 3;	
	myBars->setData(keyData, bin);
	customPlot->rescaleAxes();

	customPlot->xAxis->setRangeLower(-12.);
	customPlot->xAxis->setRangeUpper(4.);
	customPlot->xAxis->setTickStep(2.);
	customPlot->yAxis->setLabel("percentage");
	customPlot->xAxis->setLabel("log10 of characteristic chemical times [s]");
	customPlot->setMinimumWidth(450);
	customPlot->setMinimumHeight(300);

	customPlot->replot();
	customPlot->show();	
}

void CalculateTau(	OpenSMOKE::OpenSMOKEVectorDouble& tau, 
					const OpenSMOKE::OpenSMOKEMatrixDouble& dR_over_dc, bool flag,
					const int nspecies, const OpenSMOKE::OpenSMOKEVectorInt& indices);
/*
void Window_ROPA::AnalyzeCharacteristicTimes()
{
	OpenSMOKE::OpenSMOKEVectorDouble omega_max(data_->thermodynamicsMapXML->NumberOfSpecies());
	for (unsigned int k=0;k<data_->thermodynamicsMapXML->NumberOfSpecies();k++)
	{
		OpenSMOKE::OpenSMOKEVectorDouble omega_tmp(data_->number_of_abscissas_);
		for(unsigned int index=0;index<data_->number_of_abscissas_;index++)
			omega_tmp[index+1] = data_->omega[k][index];
		omega_max[k+1] = omega_tmp.Max();
	}
	
	std::ofstream fJacobian("Jacobian.out", std::ios::out);
	fJacobian.setf(std::ios::scientific);
//	fJacobian << "Max " << std::endl;
	//for(unsigned int j=0;j<omega_max.Size();j++)
		//fJacobian << j+1 << " " << omega_max[j+1] << std::endl;

	OpenSMOKE::OpenSMOKEVectorInt indices_omega_max(data_->thermodynamicsMapXML->NumberOfSpecies());

	for(unsigned int j=0;j<omega_max.Size();j++)
	{
		int index_current_max = 0;
		double current_max = -1e16;
		for(unsigned int k=0;k<omega_max.Size();k++)
			if (omega_max[k+1] > current_max)
			{
				current_max = omega_max[k+1]; 
				index_current_max = k+1; 
			}
		omega_max[index_current_max] = -1e16;
		indices_omega_max[j+1] = index_current_max;
	}
	
	indices_omega_max[1] = data_->thermodynamicsMapXML->IndexOfSpecies("O2");
	indices_omega_max[2] = data_->thermodynamicsMapXML->IndexOfSpecies("CO2");
	indices_omega_max[3] = data_->thermodynamicsMapXML->IndexOfSpecies("H");
	indices_omega_max[4] = data_->thermodynamicsMapXML->IndexOfSpecies("O");
	indices_omega_max[5] = data_->thermodynamicsMapXML->IndexOfSpecies("HO2");
	indices_omega_max[6] = data_->thermodynamicsMapXML->IndexOfSpecies("CH3");
	indices_omega_max[7] = data_->thermodynamicsMapXML->IndexOfSpecies("HCO");
	indices_omega_max[8] = data_->thermodynamicsMapXML->IndexOfSpecies("CH2O");
	indices_omega_max[9] = data_->thermodynamicsMapXML->IndexOfSpecies("H2O2");
	indices_omega_max[10] = data_->thermodynamicsMapXML->IndexOfSpecies("OH");
	

//	fJacobian << "Reordered " << std::endl;
//	for(unsigned int j=0;j<omega_max.Size();j++)
//		fJacobian << j+1 << " " << indices_omega_max[j+1] << " " << data_->thermodynamicsMapXML->NamesOfSpecies()[indices_omega_max[j+1]-1] << std::endl;

	for(unsigned int index=0;index<data_->number_of_abscissas_;index++)
	{
		OpenSMOKE::OpenSMOKEVectorDouble x(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble omega(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble c(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEMatrixDouble dR_over_dc(data_->thermodynamicsMapXML->NumberOfSpecies(),data_->thermodynamicsMapXML->NumberOfSpecies());

		// Recovers mass fractions
		for (unsigned int k=0;k<data_->thermodynamicsMapXML->NumberOfSpecies();k++)
			omega[k+1] = data_->omega[k][index];
			
		// Calculates mole fractions
		double MWmix;
		data_->thermodynamicsMapXML->MoleFractions_From_MassFractions(x, MWmix, omega);

		// Calculates concentrations
		const double P_Pa = data_->additional[data_->index_P][index];
		const double T = data_->additional[data_->index_T][index];
		const double cTot = P_Pa/PhysicalConstants::R_J_kmol/T;
		Product(cTot, x, &c);

		// Calculates formations rates
		data_->kineticsMapXML->SetTemperature(T);
		data_->kineticsMapXML->SetPressure(P_Pa);
		data_->thermodynamicsMapXML->SetTemperature(T);
		data_->thermodynamicsMapXML->SetPressure(P_Pa);

		data_->kineticsMapXML->KineticConstants();
		data_->kineticsMapXML->ReactionRates(c);

		data_->kineticsMapXML->DerivativesOfFormationRates(c, omega, &dR_over_dc);

		/*
		// Calculates the eigenvectors
		Eigen::MatrixXd Atotal(dR_over_dc.Rows(),dR_over_dc.Rows());
		for(unsigned int i=0;i<dR_over_dc.Rows();i++)
			for(unsigned int j=0;j<dR_over_dc.Rows();j++)
				Atotal(i,j) = dR_over_dc[i+1][j+1];

		// Calculates
		OpenSMOKE::OpenSMOKEVectorDouble tau;
		if (ui.radioButton_eigenvalues->isChecked() == true)
		{
			Eigen::EigenSolver<Eigen::MatrixXd> eigensolver(Atotal);
			if (eigensolver.info() != Eigen::Success) 
			{
				abort();
			}
		
			for(unsigned int i=0;i<dR_over_dc.Rows();i++)
				if ( fabs(eigensolver.eigenvalues().real()[i]) > 1e-14 )
					tau.Append(1./fabs(eigensolver.eigenvalues().real()[i]));
		}
		else
		{
			Eigen::JacobiSVD<Eigen::MatrixXd> jacobi(Atotal);
			for(unsigned int i=0;i<dR_over_dc.Rows();i++)
				if ( fabs(jacobi.singularValues().real()[i]) > 1e-14 )
					tau.Append(1./fabs(jacobi.singularValues().real()[i]));
		}
		*/
/*
		OpenSMOKE::OpenSMOKEVectorDouble tau10;
		OpenSMOKE::OpenSMOKEVectorDouble tau9;
		OpenSMOKE::OpenSMOKEVectorDouble tau8;
		OpenSMOKE::OpenSMOKEVectorDouble tau7;
		OpenSMOKE::OpenSMOKEVectorDouble tau6;
		OpenSMOKE::OpenSMOKEVectorDouble tau5;
		CalculateTau(	tau5, dR_over_dc, ui.radioButton_eigenvalues->isChecked(), 5, indices_omega_max);
		CalculateTau(	tau6, dR_over_dc, ui.radioButton_eigenvalues->isChecked(), 6, indices_omega_max);
		CalculateTau(	tau7, dR_over_dc, ui.radioButton_eigenvalues->isChecked(), 7, indices_omega_max);
		CalculateTau(	tau8, dR_over_dc, ui.radioButton_eigenvalues->isChecked(), 8, indices_omega_max);
		CalculateTau(	tau9, dR_over_dc, ui.radioButton_eigenvalues->isChecked(), 9, indices_omega_max);
		CalculateTau(	tau10, dR_over_dc, ui.radioButton_eigenvalues->isChecked(), 10, indices_omega_max);

		fJacobian	<< data_->additional[0][index] << " " 
					<< tau5.Max()  << " " 
					<< tau6.Max()  << " " 
					<< tau7.Max()  << " " 
					<< tau8.Max()  << " " 
					<< tau9.Max()  << " " 
					<< tau10.Max() << " " 
					<< tau5.Min()  << " " 
					<< tau6.Min()  << " " 
					<< tau7.Min()  << " " 
					<< tau8.Min()  << " " 
					<< tau9.Min()  << " " 
					<< tau10.Min() << " " 
					<< std::endl;
	}

	fJacobian.close();
}
*/
		// Calculates
void CalculateTau(	OpenSMOKE::OpenSMOKEVectorDouble& tau, 
					const OpenSMOKE::OpenSMOKEMatrixDouble& dR_over_dc, bool flag,
					const int nspecies, const OpenSMOKE::OpenSMOKEVectorInt& indices)
{
	Eigen::MatrixXd A(nspecies, nspecies);

	for(unsigned int i=0;i<nspecies;i++)
			for(unsigned int j=0;j<nspecies;j++)
				A(i,j) = dR_over_dc[indices[i+1]][indices[j+1]];

	if (flag == true)
	{
		Eigen::EigenSolver<Eigen::MatrixXd> eigensolver(A);
		if (eigensolver.info() != Eigen::Success) 
		{
			abort();
		}
		
		for(unsigned int i=0;i<nspecies;i++)
			if ( fabs(eigensolver.eigenvalues().real()[i]) > 1e-14 )
				tau.Append(1./fabs(eigensolver.eigenvalues().real()[i]));
	}
	else
	{
		Eigen::JacobiSVD<Eigen::MatrixXd> jacobi(A);
		for(unsigned int i=0;i<nspecies;i++)
			if ( fabs(jacobi.singularValues().real()[i]) > 1e-14 )
				tau.Append(1./fabs(jacobi.singularValues().real()[i]));
	}
}

void Window_ROPA::Plot_ReactionRates()
{
	XYPlot* xyplot;
	xyplot = new XYPlot(this);
	
	// Find the right x variable, together with the x axis lable
	SetXAxisForXYPlotting(xyplot);

	// Select y variables among the reactions
	QList<QListWidgetItem*> selected_reactions = ui.listWidget_Reactions->selectedItems();
	if (selected_reactions.size() == 0)
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromStdString("You have to select at least one of the available reactions"));
		msgBox.exec();
		return;
	}
	std::vector<int> selected_reaction_indices;
	for(int index = 0; index < ui.listWidget_Reactions->count(); index++)
	{
		if (ui.listWidget_Reactions->item(index)->isSelected() == true)
			selected_reaction_indices.push_back(indices_coarse_reactions_[index]);
	}

	// Calculates the formation rates
	{
		QVector< QVector<double> > tmp(selected_reaction_indices.size());
		for (unsigned int j=0;j<selected_reaction_indices.size();j++)
			tmp[j].resize(data_->number_of_abscissas_);

		OpenSMOKE::OpenSMOKEVectorDouble x(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble omega(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble c(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble r(data_->kineticsMapXML->NumberOfReactions());
		
		for (unsigned int i=0;i<data_->number_of_abscissas_;i++)
		{
			// Recovers mass fractions
			for (unsigned int k=0;k<data_->thermodynamicsMapXML->NumberOfSpecies();k++)
				omega[k+1] = data_->omega[k][i];
			
			// Calculates mole fractions
			double MWmix;
			data_->thermodynamicsMapXML->MoleFractions_From_MassFractions(x, MWmix, omega);

			// Calculates concentrations
			const double P_Pa = data_->additional[data_->index_P][i];
			const double T = data_->additional[data_->index_T][i];
			const double cTot = P_Pa/PhysicalConstants::R_J_kmol/T;
			Product(cTot, x, &c);

			// Calculates formations rates
			data_->kineticsMapXML->SetTemperature(T);
			data_->kineticsMapXML->SetPressure(P_Pa);
			data_->thermodynamicsMapXML->SetTemperature(T);
			data_->thermodynamicsMapXML->SetPressure(P_Pa);

			data_->kineticsMapXML->KineticConstants();
			data_->kineticsMapXML->ReactionRates(c);
			data_->kineticsMapXML->GetReactionRates(&r);

			for (unsigned int j=0;j<selected_reaction_indices.size();j++)
			{
				const unsigned k = selected_reaction_indices[j]+1;
				tmp[j][i] = r[k];	
			}
		}	

		for (unsigned int j=0;j<selected_reaction_indices.size();j++)
			xyplot->AddGraph(string_list_reactions[selected_reaction_indices[j]].toStdString(), tmp[j]);	
	}

	// Plot
	xyplot->SetYTitle("Reaction rates [kmol/m3/s]");
	xyplot->Plot();
}

void Window_ROPA::Clicked_ROPA_Local()
{
	ui.doubleSpinBox_ROPA_Local->setEnabled(true);
	ui.pushButton_ROPA_FluxAnalysis->setEnabled(true);
	ui.doubleSpinBox_ROPA_Region_Min->setEnabled(false);
	ui.doubleSpinBox_ROPA_Region_Max->setEnabled(false);
}

void Window_ROPA::Clicked_ROPA_Region()
{
	ui.doubleSpinBox_ROPA_Local->setEnabled(false);
	ui.pushButton_ROPA_FluxAnalysis->setEnabled(false);
	ui.doubleSpinBox_ROPA_Region_Min->setEnabled(true);
	ui.doubleSpinBox_ROPA_Region_Max->setEnabled(true);
}

void Window_ROPA::Clicked_ROPA_Global()
{
	ui.doubleSpinBox_ROPA_Local->setEnabled(false);
	ui.pushButton_ROPA_FluxAnalysis->setEnabled(false);
	ui.doubleSpinBox_ROPA_Region_Min->setEnabled(false);
	ui.doubleSpinBox_ROPA_Region_Max->setEnabled(false);
}

void Window_ROPA::Clean_FormationRates_List()
{
	for(int index = 0; index < ui.listWidget_Species->count(); index++)
	{
		if (ui.listWidget_Species->item(index)->isSelected() == true)
			ui.listWidget_Species->item(index)->setSelected(false);
	}
}


void Window_ROPA::Clean_ReactionRates_List()
{
	for(int index = 0; index < ui.listWidget_Reactions->count(); index++)
	{
		if (ui.listWidget_Reactions->item(index)->isSelected() == true)
			ui.listWidget_Reactions->item(index)->setSelected(false);
	}
}

void Window_ROPA::UpdateCheckBox()
{
	ui.comboBox_Species_ReactionRates->setEnabled(ui.checkBox_Species_ReactionRates->isChecked());
	ui.horizontalSlider_Species_ReactionRates->setEnabled(ui.checkBox_Species_ReactionRates->isChecked());
	UpdateListOfReactions();
}

void Window_ROPA::UpdateListOfReactions()
{
	indices_coarse_reactions_.resize(0);
	ui.listWidget_Reactions->clear();

	if (ui.checkBox_Species_ReactionRates->isChecked() == false)
	{
		indices_coarse_reactions_.resize(string_list_reactions.size());
		for (unsigned int j=0;j<indices_coarse_reactions_.size();j++)
			indices_coarse_reactions_[j] = j;
		ui.listWidget_Reactions->addItems(string_list_reactions);
	}
	else
	{
		// Check the reactions associated to the selected species
		unsigned int index = data_->sorted_index[ui.comboBox_Species_ReactionRates->currentIndex()];
		data_->ReactionsAssociatedToSpecies(index, indices_coarse_reactions_);

		// Only if the slider is not equal to zero
		if (ui.horizontalSlider_Species_ReactionRates->value() > 0)
		{
			const double slider_position = double(ui.horizontalSlider_Species_ReactionRates->value()) / double(ui.horizontalSlider_Species_ReactionRates->maximum()) * 100;
			//const double threshold = 2.1100*(exp(0.03879369254481392*slider_position)-1.) / 100.;
			const double threshold = 0.1006*(exp(0.06903072535586566*slider_position)-1.) / 100.;

			std::vector<double> tmp_max(indices_coarse_reactions_.size());
			for(unsigned int j=0;j<indices_coarse_reactions_.size();j++)
				tmp_max[j] = -1e100;

			OpenSMOKE::OpenSMOKEVectorDouble x(data_->thermodynamicsMapXML->NumberOfSpecies());
			OpenSMOKE::OpenSMOKEVectorDouble omega(data_->thermodynamicsMapXML->NumberOfSpecies());
			OpenSMOKE::OpenSMOKEVectorDouble c(data_->thermodynamicsMapXML->NumberOfSpecies());
			OpenSMOKE::OpenSMOKEVectorDouble r(data_->kineticsMapXML->NumberOfReactions());
		
			for (unsigned int i=0;i<data_->number_of_abscissas_;i++)
			{
				// Recovers mass fractions
				for (unsigned int k=0;k<data_->thermodynamicsMapXML->NumberOfSpecies();k++)
					omega[k+1] = data_->omega[k][i];
			
				// Calculates mole fractions
				double MWmix;
				data_->thermodynamicsMapXML->MoleFractions_From_MassFractions(x, MWmix, omega);

				// Calculates concentrations
				const double P_Pa = data_->additional[data_->index_P][i];
				const double T = data_->additional[data_->index_T][i];
				const double cTot = P_Pa/PhysicalConstants::R_J_kmol/T;
				Product(cTot, x, &c);

				// Calculates formations rates
				data_->kineticsMapXML->SetTemperature(T);
				data_->kineticsMapXML->SetPressure(P_Pa);
				data_->thermodynamicsMapXML->SetTemperature(T);
				data_->thermodynamicsMapXML->SetPressure(P_Pa);

				data_->kineticsMapXML->KineticConstants();
				data_->kineticsMapXML->ReactionRates(c);
				data_->kineticsMapXML->GetReactionRates(&r);

				for(unsigned int j=0;j<indices_coarse_reactions_.size();j++)
					if (fabs(r[indices_coarse_reactions_[j]+1]) > tmp_max[j]) tmp_max[j] = fabs(r[indices_coarse_reactions_[j]+1]);
			}	

			OpenSMOKE_Utilities::ReorderPairsOfVectors(tmp_max, indices_coarse_reactions_);
			std::reverse(tmp_max.begin(), tmp_max.end());
			std::reverse(indices_coarse_reactions_.begin(), indices_coarse_reactions_.end());

			std::vector<unsigned int> tmp_indices_coarse_reactions_;
			if (tmp_max[0] > 0.)
			{
				for(unsigned int j=0;j<indices_coarse_reactions_.size();j++)
					if (tmp_max[j]/tmp_max[0] > threshold) 
						tmp_indices_coarse_reactions_.push_back(indices_coarse_reactions_[j]);
					else
						break;
				indices_coarse_reactions_ = tmp_indices_coarse_reactions_;
			}
		}
		
		QStringList current_string_list;
		current_string_list.reserve(indices_coarse_reactions_.size());
		for (unsigned int k=0;k<indices_coarse_reactions_.size();k++)
			current_string_list.push_back(string_list_reactions[indices_coarse_reactions_[k]]);
		ui.listWidget_Reactions->addItems(current_string_list);
	}
}

void Window_ROPA::Plot_FluxAnalysis()
{
	// Select y variables among the species
	QList<QListWidgetItem*> selected_species = ui.listWidget_ROPA_Species->selectedItems();
	if (selected_species.size() == 0)
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromStdString("You have to select one of the available species"));
		msgBox.exec();
		return;
	}

	unsigned int index_of_species;
	for(unsigned int j=0;j<ui.listWidget_ROPA_Species->count();j++)
		if (ui.listWidget_ROPA_Species->item(j)->isSelected() == true)
		{
			index_of_species = data_->sorted_index[j];
			break;
		}

	const unsigned index_element = ui.comboBox_Elements->currentIndex();
	const double n_elements = data_->thermodynamicsMapXML->atomic_composition()(index_of_species, index_element);
	
	if (n_elements == 0.)
	{
		QMessageBox msgBox;
		msgBox.setText(QString::fromStdString("The selected species does not contain the selected element"));
		msgBox.exec();
		return;
	}

	const int max_depth = ui.spinBox_MaxDepth->value();
	const int max_width = ui.spinBox_MaxWidth->value();
	const double min_threshold_percentage = ui.doubleSpinBox_MinThreshold->value();

	// Local Analysis
	if (ui.radioButton_ROPA_Local->isChecked() == true)
	{
		unsigned int index = 0;
		for(unsigned int j=0;j<data_->number_of_abscissas_;j++)
			if (data_->additional[0][j] >= ui.doubleSpinBox_ROPA_Local->value() )
			{
				index = j;
				break;
			}

		OpenSMOKE::OpenSMOKEVectorDouble x(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble omega(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble c(data_->thermodynamicsMapXML->NumberOfSpecies());
		OpenSMOKE::OpenSMOKEVectorDouble r(data_->kineticsMapXML->NumberOfReactions());
		
		// Recovers mass fractions
		for (unsigned int k=0;k<data_->thermodynamicsMapXML->NumberOfSpecies();k++)
			omega[k+1] = data_->omega[k][index];
			
		// Calculates mole fractions
		double MWmix;
		data_->thermodynamicsMapXML->MoleFractions_From_MassFractions(x, MWmix, omega);

		// Calculates concentrations
		const double P_Pa = data_->additional[data_->index_P][index];
		const double T = data_->additional[data_->index_T][index];
		const double cTot = P_Pa/PhysicalConstants::R_J_kmol/T;
		Product(cTot, x, &c);

		// Calculates formations rates
		data_->kineticsMapXML->SetTemperature(T);
		data_->kineticsMapXML->SetPressure(P_Pa);
		data_->thermodynamicsMapXML->SetTemperature(T);
		data_->thermodynamicsMapXML->SetPressure(P_Pa);

		data_->kineticsMapXML->KineticConstants();
		data_->kineticsMapXML->ReactionRates(c);
		data_->kineticsMapXML->GetReactionRates(&r);

		OpenSMOKE::FluxAnalysisMap<double> flux_analysis(*data_->thermodynamicsMapXML, *data_->kineticsMapXML);
		flux_analysis.SetDestructionAnalysis(ui.radioButton_FluxAnalysis_Destruction->isChecked());
		flux_analysis.SetNormalThickness(ui.radioButton_Thickness_Relative->isChecked());
		flux_analysis.SetNormalTags(ui.radioButton_Labels_Relative->isChecked());
		flux_analysis.SetLogarithmicThickness(ui.checkBox_Thickness_Logarithmic->isChecked());
		flux_analysis.SetMaxDepth(max_depth);
		flux_analysis.SetMaxWidth(max_width);
		flux_analysis.SetMinPercentageThreshold(min_threshold_percentage);
		flux_analysis.SetAtom(index_element);
		flux_analysis.SetReactionRates(r);
		
		std::vector<unsigned int> important_indices;
		important_indices.push_back(index_of_species);
		flux_analysis.GloballyAnalyze( important_indices, 0 );
		flux_analysis.CalculateThickness();

		boost::filesystem::path graph_txt = output_folder_ / "graph.txt";
		boost::filesystem::path graph_png = output_folder_ / "graph.png";

		flux_analysis.Plot(graph_txt.string());

        #ifdef __linux__

            std::string graphviz_command    = "dot -Tpng " + graph_txt.string() + " -o " + graph_png.string();
            std::string visualizer_command  = "eog " + graph_png.string() + " &";

            system(graphviz_command.c_str());
            system(visualizer_command.c_str());

		#elif defined __APPLE__

			std::string graphviz_command = "dot -Tpng " + graph_txt.string() + " -o " + graph_png.string();
			std::string visualizer_command = "open " + graph_png.string() + " &";

			system(graphviz_command.c_str());
			system(visualizer_command.c_str());

        #elif defined _WIN32 || defined _WIN64

			std::string graph_png_quoted = "\"" + graph_png.string() + "\"";
			std::string graph_txt_quoted = "\"" + graph_txt.string() + "\"";
    
			std::string graphviz_command = "dot  -Tpng " + graph_txt_quoted + " -o " + graph_png_quoted;
			std::string irfanview_command = "START /MIN i_view32.exe " + graph_png_quoted;

            system(graphviz_command.c_str());
    		system(irfanview_command.c_str());

        #endif
	}

}
